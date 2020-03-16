/*
 * Copyright (C) 2018 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#if PLATFORM(MAC)

#include "FloatRect.h"
#include "PlatformScreen.h"
#include <wtf/RetainPtr.h>
#include <wtf/text/WTFString.h>

typedef struct CGColorSpace *CGColorSpaceRef;

namespace WebCore {

struct ScreenData {
    FloatRect screenAvailableRect;
    FloatRect screenRect;
    RetainPtr<CGColorSpaceRef> colorSpace;
    int screenDepth { 0 };
    int screenDepthPerComponent { 0 };
    bool screenSupportsExtendedColor { false };
    bool screenHasInvertedColors { false };
    bool screenIsMonochrome { false };
    uint32_t displayMask { 0 };
    IORegistryGPUID gpuID { 0 };

    enum EncodedColorSpaceDataType {
        Null,
        ColorSpaceName,
        ColorSpaceData,
    };

    template<class Encoder> void encode(Encoder&) const;
    template<class Decoder> static Optional<ScreenData> decode(Decoder&);
};

typedef HashMap<PlatformDisplayID, ScreenData> ScreenDataMap;
    
struct ScreenProperties {
    PlatformDisplayID primaryDisplayID { 0 };
    ScreenDataMap screenDataMap;

    template<class Encoder> void encode(Encoder&) const;
    template<class Decoder> static Optional<ScreenProperties> decode(Decoder&);
};

template<class Encoder>
void ScreenProperties::encode(Encoder& encoder) const
{
    encoder << primaryDisplayID;
    encoder << screenDataMap;
}

template<class Decoder>
Optional<ScreenProperties> ScreenProperties::decode(Decoder& decoder)
{
    Optional<PlatformDisplayID> primaryDisplayID;
    decoder >> primaryDisplayID;
    if (!primaryDisplayID)
        return WTF::nullopt;

    Optional<ScreenDataMap> screenDataMap;
    decoder >> screenDataMap;
    if (!screenDataMap)
        return WTF::nullopt;

    return { { *primaryDisplayID, WTFMove(*screenDataMap) } };
}

template<class Encoder>
void ScreenData::encode(Encoder& encoder) const
{
    encoder << screenAvailableRect << screenRect << screenDepth << screenDepthPerComponent << screenSupportsExtendedColor << screenHasInvertedColors << screenIsMonochrome << displayMask << gpuID;

    if (colorSpace) {
        // Try to encode the name.
        if (auto name = adoptCF(CGColorSpaceCopyName(colorSpace.get()))) {
            encoder.encodeEnum(ColorSpaceName);
            encoder << String(name.get());
            return;
        }

        // Failing that, just encode the ICC data.
        if (auto profileData = adoptCF(CGColorSpaceCopyICCData(colorSpace.get()))) {
            encoder.encodeEnum(ColorSpaceData);

            Vector<uint8_t> iccData;
            iccData.append(CFDataGetBytePtr(profileData.get()), CFDataGetLength(profileData.get()));

            encoder << iccData;
            return;
        }
    }

    // The color space was null or failed to be encoded.
    encoder << Null;
}

template<class Decoder>
Optional<ScreenData> ScreenData::decode(Decoder& decoder)
{
    Optional<FloatRect> screenAvailableRect;
    decoder >> screenAvailableRect;
    if (!screenAvailableRect)
        return WTF::nullopt;

    Optional<FloatRect> screenRect;
    decoder >> screenRect;
    if (!screenRect)
        return WTF::nullopt;

    Optional<int> screenDepth;
    decoder >> screenDepth;
    if (!screenDepth)
        return WTF::nullopt;

    Optional<int> screenDepthPerComponent;
    decoder >> screenDepthPerComponent;
    if (!screenDepthPerComponent)
        return WTF::nullopt;

    Optional<bool> screenSupportsExtendedColor;
    decoder >> screenSupportsExtendedColor;
    if (!screenSupportsExtendedColor)
        return WTF::nullopt;

    Optional<bool> screenHasInvertedColors;
    decoder >> screenHasInvertedColors;
    if (!screenHasInvertedColors)
        return WTF::nullopt;

    Optional<bool> screenIsMonochrome;
    decoder >> screenIsMonochrome;
    if (!screenIsMonochrome)
        return WTF::nullopt;

    Optional<uint32_t> displayMask;
    decoder >> displayMask;
    if (!displayMask)
        return WTF::nullopt;

    Optional<IORegistryGPUID> gpuID;
    decoder >> gpuID;
    if (!gpuID)
        return WTF::nullopt;
    
    EncodedColorSpaceDataType dataType;
    if (!decoder.decodeEnum(dataType))
        return WTF::nullopt;

    RetainPtr<CGColorSpaceRef> cgColorSpace;
    switch (dataType) {
    case Null:
        break;
    case ColorSpaceName: {
        Optional<String> colorSpaceName;
        decoder >> colorSpaceName;
        ASSERT(colorSpaceName);
        if (!colorSpaceName)
            return WTF::nullopt;

        cgColorSpace = adoptCF(CGColorSpaceCreateWithName(colorSpaceName->createCFString().get()));
        break;
    }
    case ColorSpaceData: {
        Optional<Vector<uint8_t>> iccData;
        decoder >> iccData;
        ASSERT(iccData);
        if (!iccData)
            return WTF::nullopt;

        auto colorSpaceData = adoptCF(CFDataCreate(kCFAllocatorDefault, iccData->data(), iccData->size()));
        // FIXME: <http://webkit.org/b/184358> We should switch to CGColorSpaceCreateICCBased.
        ALLOW_DEPRECATED_DECLARATIONS_BEGIN
        cgColorSpace = adoptCF(CGColorSpaceCreateWithICCProfile(colorSpaceData.get()));
        ALLOW_DEPRECATED_DECLARATIONS_END
        break;
    }
    }

    return { { WTFMove(*screenAvailableRect), WTFMove(*screenRect), WTFMove(cgColorSpace), WTFMove(*screenDepth), WTFMove(*screenDepthPerComponent), WTFMove(*screenSupportsExtendedColor), WTFMove(*screenHasInvertedColors), WTFMove(*screenIsMonochrome), WTFMove(*displayMask), WTFMove(*gpuID) } };
}

} // namespace WebCore

#endif // PLATFORM(MAC)
