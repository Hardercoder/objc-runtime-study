/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
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

#import "config.h"
#import "RemoteObjectRegistry.h"

#import "MessageSender.h"
#import "ProcessThrottler.h"
#import "RemoteObjectInvocation.h"
#import "RemoteObjectRegistryMessages.h"
#import "UserData.h"
#import "WebPage.h"
#import "WebPageProxy.h"
#import "WebProcess.h"
#import "WebProcessProxy.h"
#import "_WKRemoteObjectRegistryInternal.h"

namespace WebKit {

RemoteObjectRegistry::RemoteObjectRegistry(_WKRemoteObjectRegistry *remoteObjectRegistry, WebPage& page)
    : m_remoteObjectRegistry(remoteObjectRegistry)
    , m_messageSender(page)
    , m_takeBackgroundActivityToken([] { return ProcessThrottler::BackgroundActivityToken(); })
    , m_isRegisteredAsMessageReceiver(true)
    , m_messageReceiverID(page.pageID())
{
    WebProcess::singleton().addMessageReceiver(Messages::RemoteObjectRegistry::messageReceiverName(), m_messageReceiverID, *this);
    page.setRemoteObjectRegistry(*this);
}

RemoteObjectRegistry::RemoteObjectRegistry(_WKRemoteObjectRegistry *remoteObjectRegistry, WebPageProxy& page)
    : m_remoteObjectRegistry(remoteObjectRegistry)
    , m_messageSender(page)
    , m_takeBackgroundActivityToken([&page] { return page.process().throttler().backgroundActivityToken(); })
    , m_launchInitialProcessIfNecessary([&page] { page.launchInitialProcessIfNecessary(); })
{
}

RemoteObjectRegistry::~RemoteObjectRegistry()
{
    close();
}

void RemoteObjectRegistry::close()
{
    if (m_isRegisteredAsMessageReceiver) {
        WebProcess::singleton().removeMessageReceiver(Messages::RemoteObjectRegistry::messageReceiverName(), m_messageReceiverID);
        m_isRegisteredAsMessageReceiver = false;
    }
}

void RemoteObjectRegistry::sendInvocation(const RemoteObjectInvocation& invocation)
{
    // For backward-compatibility, support invoking injected bundle methods before having done any load in the WebView.
    if (m_launchInitialProcessIfNecessary)
        m_launchInitialProcessIfNecessary();

    if (auto* replyInfo = invocation.replyInfo()) {
        ASSERT(!m_pendingReplies.contains(replyInfo->replyID));
        m_pendingReplies.add(replyInfo->replyID, m_takeBackgroundActivityToken());
    }

    m_messageSender.send(Messages::RemoteObjectRegistry::InvokeMethod(invocation));
}

void RemoteObjectRegistry::sendReplyBlock(uint64_t replyID, const UserData& blockInvocation)
{
    m_messageSender.send(Messages::RemoteObjectRegistry::CallReplyBlock(replyID, blockInvocation));
}

void RemoteObjectRegistry::sendUnusedReply(uint64_t replyID)
{
    m_messageSender.send(Messages::RemoteObjectRegistry::ReleaseUnusedReplyBlock(replyID));
}

void RemoteObjectRegistry::invokeMethod(const RemoteObjectInvocation& invocation)
{
    [m_remoteObjectRegistry _invokeMethod:invocation];
}

void RemoteObjectRegistry::callReplyBlock(uint64_t replyID, const UserData& blockInvocation)
{
    bool wasRemoved = m_pendingReplies.remove(replyID);
    ASSERT_UNUSED(wasRemoved, wasRemoved);

    [m_remoteObjectRegistry _callReplyWithID:replyID blockInvocation:blockInvocation];
}

void RemoteObjectRegistry::releaseUnusedReplyBlock(uint64_t replyID)
{
    bool wasRemoved = m_pendingReplies.remove(replyID);
    ASSERT_UNUSED(wasRemoved, wasRemoved);

    [m_remoteObjectRegistry _releaseReplyWithID:replyID];
}
} // namespace WebKit
