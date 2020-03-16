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

#include "config.h"
#include "JSTestSerializationInheritFinal.h"

#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "ScriptExecutionContext.h"
#include <JavaScriptCore/HeapSnapshotBuilder.h>
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/ObjectConstructor.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>


namespace WebCore {
using namespace JSC;

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsTestSerializationInheritFinalPrototypeFunctionToJSON(JSC::ExecState*);

// Attributes

JSC::EncodedJSValue jsTestSerializationInheritFinalConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestSerializationInheritFinalConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);
JSC::EncodedJSValue jsTestSerializationInheritFinalFinalLongAttributeFoo(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestSerializationInheritFinalFinalLongAttributeFoo(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);
JSC::EncodedJSValue jsTestSerializationInheritFinalFinalLongAttributeBar(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestSerializationInheritFinalFinalLongAttributeBar(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);

class JSTestSerializationInheritFinalPrototype : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestSerializationInheritFinalPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestSerializationInheritFinalPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestSerializationInheritFinalPrototype>(vm.heap)) JSTestSerializationInheritFinalPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestSerializationInheritFinalPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};

using JSTestSerializationInheritFinalConstructor = JSDOMConstructorNotConstructable<JSTestSerializationInheritFinal>;

template<> JSValue JSTestSerializationInheritFinalConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSTestSerializationInherit::getConstructor(vm, &globalObject);
}

template<> void JSTestSerializationInheritFinalConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestSerializationInheritFinal::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(&vm, String("TestSerializationInheritFinal"_s)), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

template<> const ClassInfo JSTestSerializationInheritFinalConstructor::s_info = { "TestSerializationInheritFinal", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestSerializationInheritFinalConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestSerializationInheritFinalPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializationInheritFinalConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestSerializationInheritFinalConstructor) } },
    { "finalLongAttributeFoo", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializationInheritFinalFinalLongAttributeFoo), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestSerializationInheritFinalFinalLongAttributeFoo) } },
    { "finalLongAttributeBar", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializationInheritFinalFinalLongAttributeBar), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestSerializationInheritFinalFinalLongAttributeBar) } },
    { "toJSON", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestSerializationInheritFinalPrototypeFunctionToJSON), (intptr_t) (0) } },
};

const ClassInfo JSTestSerializationInheritFinalPrototype::s_info = { "TestSerializationInheritFinalPrototype", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestSerializationInheritFinalPrototype) };

void JSTestSerializationInheritFinalPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestSerializationInheritFinal::info(), JSTestSerializationInheritFinalPrototypeTableValues, *this);
}

const ClassInfo JSTestSerializationInheritFinal::s_info = { "TestSerializationInheritFinal", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestSerializationInheritFinal) };

JSTestSerializationInheritFinal::JSTestSerializationInheritFinal(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestSerializationInheritFinal>&& impl)
    : JSTestSerializationInherit(structure, globalObject, WTFMove(impl))
{
}

void JSTestSerializationInheritFinal::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

}

JSObject* JSTestSerializationInheritFinal::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestSerializationInheritFinalPrototype::create(vm, &globalObject, JSTestSerializationInheritFinalPrototype::createStructure(vm, &globalObject, JSTestSerializationInherit::prototype(vm, globalObject)));
}

JSObject* JSTestSerializationInheritFinal::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestSerializationInheritFinal>(vm, globalObject);
}

JSValue JSTestSerializationInheritFinal::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestSerializationInheritFinalConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

template<> inline JSTestSerializationInheritFinal* IDLAttribute<JSTestSerializationInheritFinal>::cast(ExecState& state, EncodedJSValue thisValue)
{
    return jsDynamicCast<JSTestSerializationInheritFinal*>(state.vm(), JSValue::decode(thisValue));
}

template<> inline JSTestSerializationInheritFinal* IDLOperation<JSTestSerializationInheritFinal>::cast(ExecState& state)
{
    return jsDynamicCast<JSTestSerializationInheritFinal*>(state.vm(), state.thisValue());
}

EncodedJSValue jsTestSerializationInheritFinalConstructor(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestSerializationInheritFinalPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(state, throwScope);
    return JSValue::encode(JSTestSerializationInheritFinal::getConstructor(state->vm(), prototype->globalObject()));
}

bool setJSTestSerializationInheritFinalConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestSerializationInheritFinalPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype)) {
        throwVMTypeError(state, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return prototype->putDirect(vm, vm.propertyNames->constructor, JSValue::decode(encodedValue));
}

static inline JSValue jsTestSerializationInheritFinalFinalLongAttributeFooGetter(ExecState& state, JSTestSerializationInheritFinal& thisObject, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(state);
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLLong>(state, throwScope, impl.finalLongAttributeFoo());
    return result;
}

EncodedJSValue jsTestSerializationInheritFinalFinalLongAttributeFoo(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestSerializationInheritFinal>::get<jsTestSerializationInheritFinalFinalLongAttributeFooGetter, CastedThisErrorBehavior::Assert>(*state, thisValue, "finalLongAttributeFoo");
}

static inline bool setJSTestSerializationInheritFinalFinalLongAttributeFooSetter(ExecState& state, JSTestSerializationInheritFinal& thisObject, JSValue value, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLLong>(state, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    AttributeSetter::call(state, throwScope, [&] {
        return impl.setFinalLongAttributeFoo(WTFMove(nativeValue));
    });
    return true;
}

bool setJSTestSerializationInheritFinalFinalLongAttributeFoo(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    return IDLAttribute<JSTestSerializationInheritFinal>::set<setJSTestSerializationInheritFinalFinalLongAttributeFooSetter>(*state, thisValue, encodedValue, "finalLongAttributeFoo");
}

static inline JSValue jsTestSerializationInheritFinalFinalLongAttributeBarGetter(ExecState& state, JSTestSerializationInheritFinal& thisObject, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(state);
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLLong>(state, throwScope, impl.finalLongAttributeBar());
    return result;
}

EncodedJSValue jsTestSerializationInheritFinalFinalLongAttributeBar(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestSerializationInheritFinal>::get<jsTestSerializationInheritFinalFinalLongAttributeBarGetter, CastedThisErrorBehavior::Assert>(*state, thisValue, "finalLongAttributeBar");
}

static inline bool setJSTestSerializationInheritFinalFinalLongAttributeBarSetter(ExecState& state, JSTestSerializationInheritFinal& thisObject, JSValue value, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLLong>(state, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    AttributeSetter::call(state, throwScope, [&] {
        return impl.setFinalLongAttributeBar(WTFMove(nativeValue));
    });
    return true;
}

bool setJSTestSerializationInheritFinalFinalLongAttributeBar(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    return IDLAttribute<JSTestSerializationInheritFinal>::set<setJSTestSerializationInheritFinalFinalLongAttributeBarSetter>(*state, thisValue, encodedValue, "finalLongAttributeBar");
}

JSC::JSObject* JSTestSerializationInheritFinal::serialize(ExecState& state, JSTestSerializationInheritFinal& thisObject, JSDOMGlobalObject& globalObject, ThrowScope& throwScope)
{
    auto& vm = state.vm();
    auto* result = JSTestSerializationInherit::serialize(state, thisObject, globalObject, throwScope);

    auto finalLongAttributeBarValue = jsTestSerializationInheritFinalFinalLongAttributeBarGetter(state, thisObject, throwScope);
    throwScope.assertNoException();
    result->putDirect(vm, Identifier::fromString(&vm, "finalLongAttributeBar"), finalLongAttributeBarValue);

    return result;
}

static inline EncodedJSValue jsTestSerializationInheritFinalPrototypeFunctionToJSONBody(ExecState* state, JSTestSerializationInheritFinal* thisObject, JSC::ThrowScope& throwScope)
{
    return JSValue::encode(JSTestSerializationInheritFinal::serialize(*state, *thisObject, *thisObject->globalObject(), throwScope));
}

EncodedJSValue JSC_HOST_CALL jsTestSerializationInheritFinalPrototypeFunctionToJSON(ExecState* state)
{
    return IDLOperation<JSTestSerializationInheritFinal>::call<jsTestSerializationInheritFinalPrototypeFunctionToJSONBody>(*state, "toJSON");
}

void JSTestSerializationInheritFinal::heapSnapshot(JSCell* cell, HeapSnapshotBuilder& builder)
{
    auto* thisObject = jsCast<JSTestSerializationInheritFinal*>(cell);
    builder.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        builder.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::heapSnapshot(cell, builder);
}


}