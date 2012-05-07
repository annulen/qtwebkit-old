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
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef V8TestObj_h
#define V8TestObj_h

#include "TestObj.h"
#include "V8DOMWrapper.h"
#include "WrapperTypeInfo.h"
#include <v8.h>
#include <wtf/HashMap.h>
#include <wtf/text/StringHash.h>

namespace WebCore {

class V8TestObj {
public:
    static const bool hasDependentLifetime = false;
    static bool HasInstance(v8::Handle<v8::Value>);
    static v8::Persistent<v8::FunctionTemplate> GetRawTemplate();
    static v8::Persistent<v8::FunctionTemplate> GetTemplate();
    static TestObj* toNative(v8::Handle<v8::Object> object)
    {
        return reinterpret_cast<TestObj*>(object->GetPointerFromInternalField(v8DOMWrapperObjectIndex));
    }
    inline static v8::Handle<v8::Object> wrap(TestObj*, v8::Isolate* = 0);
    static void derefObject(void*);
    static WrapperTypeInfo info;
    static v8::Handle<v8::Value> customMethodCallback(const v8::Arguments&);
    static v8::Handle<v8::Value> customMethodWithArgsCallback(const v8::Arguments&);
    static v8::Handle<v8::Value> classMethod2Callback(const v8::Arguments&);
    static v8::Handle<v8::Value> constructorCallback(const v8::Arguments&);
    static v8::Handle<v8::Value> customAttrAccessorGetter(v8::Local<v8::String> name, const v8::AccessorInfo&);
    static void customAttrAccessorSetter(v8::Local<v8::String> name, v8::Local<v8::Value>, const v8::AccessorInfo&);
    static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0;
private:
    static v8::Handle<v8::Object> wrapSlow(PassRefPtr<TestObj>, v8::Isolate*);
};

v8::Handle<v8::Object> V8TestObj::wrap(TestObj* impl, v8::Isolate* isolate)
{
        v8::Handle<v8::Object> wrapper = getDOMObjectMap(isolate).get(impl);
        if (!wrapper.IsEmpty())
            return wrapper;
    return V8TestObj::wrapSlow(impl, isolate);
}

inline v8::Handle<v8::Value> toV8(TestObj* impl, v8::Isolate* isolate = 0)
{
    if (!impl)
        return v8::Null();
    return V8TestObj::wrap(impl, isolate);
}
inline v8::Handle<v8::Value> toV8(PassRefPtr< TestObj > impl, v8::Isolate* isolate = 0)
{
    return toV8(impl.get(), isolate);
}

}

#endif // V8TestObj_h
