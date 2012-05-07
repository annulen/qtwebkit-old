/*
 * This file is part of the WebKit open source project.
 * This file has been generated by generate-bindings.pl. DO NOT MODIFY!
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "config.h"

#if ENABLE(Condition1) || ENABLE(Condition2)

#include "WebDOMTestSerializedScriptValueInterface.h"

#include "Array.h"
#include "MessagePortArray.h"
#include "SerializedScriptValue.h"
#include "TestSerializedScriptValueInterface.h"
#include "WebDOMArray.h"
#include "WebDOMMessagePortArray.h"
#include "WebExceptionHandler.h"
#include <wtf/GetPtr.h>
#include <wtf/RefPtr.h>

struct WebDOMTestSerializedScriptValueInterface::WebDOMTestSerializedScriptValueInterfacePrivate {
    WebDOMTestSerializedScriptValueInterfacePrivate(WebCore::TestSerializedScriptValueInterface* object = 0)
        : impl(object)
    {
    }

    RefPtr<WebCore::TestSerializedScriptValueInterface> impl;
};

WebDOMTestSerializedScriptValueInterface::WebDOMTestSerializedScriptValueInterface()
    : WebDOMObject()
    , m_impl(0)
{
}

WebDOMTestSerializedScriptValueInterface::WebDOMTestSerializedScriptValueInterface(WebCore::TestSerializedScriptValueInterface* impl)
    : WebDOMObject()
    , m_impl(new WebDOMTestSerializedScriptValueInterfacePrivate(impl))
{
}

WebDOMTestSerializedScriptValueInterface::WebDOMTestSerializedScriptValueInterface(const WebDOMTestSerializedScriptValueInterface& copy)
    : WebDOMObject()
{
    m_impl = copy.impl() ? new WebDOMTestSerializedScriptValueInterfacePrivate(copy.impl()) : 0;
}

WebDOMTestSerializedScriptValueInterface& WebDOMTestSerializedScriptValueInterface::operator=(const WebDOMTestSerializedScriptValueInterface& copy)
{
    delete m_impl;
    m_impl = copy.impl() ? new WebDOMTestSerializedScriptValueInterfacePrivate(copy.impl()) : 0;
    return *this;
}

WebCore::TestSerializedScriptValueInterface* WebDOMTestSerializedScriptValueInterface::impl() const
{
    return m_impl ? WTF::getPtr(m_impl->impl) : 0;
}

WebDOMTestSerializedScriptValueInterface::~WebDOMTestSerializedScriptValueInterface()
{
    delete m_impl;
    m_impl = 0;
}

WebDOMString WebDOMTestSerializedScriptValueInterface::value() const
{
    if (!impl())
        return WebDOMString();

    return impl()->value()->toString();
}

void WebDOMTestSerializedScriptValueInterface::setValue(const WebDOMString& newValue)
{
    if (!impl())
        return;

    impl()->setValue(WebCore::SerializedScriptValue::create(WTF::String(newValue)));
}

WebDOMString WebDOMTestSerializedScriptValueInterface::readonlyValue() const
{
    if (!impl())
        return WebDOMString();

    return impl()->readonlyValue()->toString();
}

WebDOMString WebDOMTestSerializedScriptValueInterface::cachedValue() const
{
    if (!impl())
        return WebDOMString();

    return impl()->cachedValue()->toString();
}

void WebDOMTestSerializedScriptValueInterface::setCachedValue(const WebDOMString& newCachedValue)
{
    if (!impl())
        return;

    impl()->setCachedValue(WebCore::SerializedScriptValue::create(WTF::String(newCachedValue)));
}

WebDOMMessagePortArray WebDOMTestSerializedScriptValueInterface::ports() const
{
    if (!impl())
        return WebDOMMessagePortArray();

    return toWebKit(WTF::getPtr(impl()->ports()));
}

WebDOMString WebDOMTestSerializedScriptValueInterface::cachedReadonlyValue() const
{
    if (!impl())
        return WebDOMString();

    return impl()->cachedReadonlyValue()->toString();
}

void WebDOMTestSerializedScriptValueInterface::acceptTransferList(const WebDOMString& data, const WebDOMArray& transferList)
{
    if (!impl())
        return;

    impl()->acceptTransferList(WebCore::SerializedScriptValue::create(WTF::String(data)), toWebCore(transferList));
}

void WebDOMTestSerializedScriptValueInterface::multiTransferList(const WebDOMString& first, const WebDOMArray& tx, const WebDOMString& second, const WebDOMArray& txx)
{
    if (!impl())
        return;

    impl()->multiTransferList(WebCore::SerializedScriptValue::create(WTF::String(first)), toWebCore(tx), WebCore::SerializedScriptValue::create(WTF::String(second)), toWebCore(txx));
}

WebCore::TestSerializedScriptValueInterface* toWebCore(const WebDOMTestSerializedScriptValueInterface& wrapper)
{
    return wrapper.impl();
}

WebDOMTestSerializedScriptValueInterface toWebKit(WebCore::TestSerializedScriptValueInterface* value)
{
    return WebDOMTestSerializedScriptValueInterface(value);
}

#endif // ENABLE(Condition1) || ENABLE(Condition2)
