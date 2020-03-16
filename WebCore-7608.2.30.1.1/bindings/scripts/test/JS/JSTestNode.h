/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#pragma once

#include "JSDOMWrapper.h"
#include "JSNode.h"
#include "TestNode.h"

namespace WebCore {

class WEBCORE_TESTSUPPORT_EXPORT JSTestNode : public JSNode {
public:
    using Base = JSNode;
    using DOMWrapped = TestNode;
    static JSTestNode* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<TestNode>&& impl)
    {
        JSTestNode* ptr = new (NotNull, JSC::allocateCell<JSTestNode>(globalObject->vm().heap)) JSTestNode(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::JSType(JSNodeType), StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    static JSC::JSObject* serialize(JSC::ExecState&, JSTestNode& thisObject, JSDOMGlobalObject&, JSC::ThrowScope&);
    static void heapSnapshot(JSCell*, JSC::HeapSnapshotBuilder&);
    TestNode& wrapped() const
    {
        return static_cast<TestNode&>(Base::wrapped());
    }
protected:
    JSTestNode(JSC::Structure*, JSDOMGlobalObject&, Ref<TestNode>&&);

    void finishCreation(JSC::VM&);
};

WEBCORE_TESTSUPPORT_EXPORT JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, TestNode&);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestNode* impl) { return impl ? toJS(state, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Ref<TestNode>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::ExecState* state, JSDOMGlobalObject* globalObject, RefPtr<TestNode>&& impl) { return impl ? toJSNewlyCreated(state, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<TestNode> {
    using WrapperClass = JSTestNode;
    using ToWrappedReturnType = TestNode*;
};

} // namespace WebCore
