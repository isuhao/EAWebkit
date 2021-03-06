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

/*
* This file was modified by Electronic Arts Inc Copyright � 2009-2010
*/

#include "config.h"

#include "JSNodeFilter.h"

#include <wtf/GetPtr.h>

#include "NodeFilter.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSNodeFilterTableValues[2] =
{
    { "constructor", (intptr_t)JSNodeFilter::ConstructorAttrNum, DontEnum, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSNodeFilterTable = { 0, JSNodeFilterTableValues, 0 };

/* Hash table for constructor */

static const HashTableValue JSNodeFilterConstructorTableValues[17] =
{
    { "FILTER_ACCEPT", (intptr_t)1, DontDelete|ReadOnly, 0 },
    { "FILTER_REJECT", (intptr_t)2, DontDelete|ReadOnly, 0 },
    { "FILTER_SKIP", (intptr_t)3, DontDelete|ReadOnly, 0 },
    { "SHOW_ALL", (intptr_t)0xFFFFFFFF, DontDelete|ReadOnly, 0 },
    { "SHOW_ELEMENT", (intptr_t)0x00000001, DontDelete|ReadOnly, 0 },
    { "SHOW_ATTRIBUTE", (intptr_t)0x00000002, DontDelete|ReadOnly, 0 },
    { "SHOW_TEXT", (intptr_t)0x00000004, DontDelete|ReadOnly, 0 },
    { "SHOW_CDATA_SECTION", (intptr_t)0x00000008, DontDelete|ReadOnly, 0 },
    { "SHOW_ENTITY_REFERENCE", (intptr_t)0x00000010, DontDelete|ReadOnly, 0 },
    { "SHOW_ENTITY", (intptr_t)0x00000020, DontDelete|ReadOnly, 0 },
    { "SHOW_PROCESSING_INSTRUCTION", (intptr_t)0x00000040, DontDelete|ReadOnly, 0 },
    { "SHOW_COMMENT", (intptr_t)0x00000080, DontDelete|ReadOnly, 0 },
    { "SHOW_DOCUMENT", (intptr_t)0x00000100, DontDelete|ReadOnly, 0 },
    { "SHOW_DOCUMENT_TYPE", (intptr_t)0x00000200, DontDelete|ReadOnly, 0 },
    { "SHOW_DOCUMENT_FRAGMENT", (intptr_t)0x00000400, DontDelete|ReadOnly, 0 },
    { "SHOW_NOTATION", (intptr_t)0x00000800, DontDelete|ReadOnly, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSNodeFilterConstructorTable = { 127, JSNodeFilterConstructorTableValues, 0 };

class JSNodeFilterConstructor : public DOMObject {
public:
    JSNodeFilterConstructor(ExecState* exec)
        : DOMObject(exec->lexicalGlobalObject()->objectPrototype())
    {
        putDirect(exec->propertyNames().prototype, JSNodeFilterPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSNodeFilterConstructor::s_info = { "NodeFilterConstructor", 0, &JSNodeFilterConstructorTable, 0 };

bool JSNodeFilterConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSNodeFilterConstructor, DOMObject>(exec, &JSNodeFilterConstructorTable, this, propertyName, slot);
}

JSValue* JSNodeFilterConstructor::getValueProperty(ExecState* exec, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(exec, token);
}

/* Hash table for prototype */

static const HashTableValue JSNodeFilterPrototypeTableValues[18] =
{
    { "FILTER_ACCEPT", (intptr_t)1, DontDelete|ReadOnly, 0 },
    { "FILTER_REJECT", (intptr_t)2, DontDelete|ReadOnly, 0 },
    { "FILTER_SKIP", (intptr_t)3, DontDelete|ReadOnly, 0 },
    { "SHOW_ALL", (intptr_t)0xFFFFFFFF, DontDelete|ReadOnly, 0 },
    { "SHOW_ELEMENT", (intptr_t)0x00000001, DontDelete|ReadOnly, 0 },
    { "SHOW_ATTRIBUTE", (intptr_t)0x00000002, DontDelete|ReadOnly, 0 },
    { "SHOW_TEXT", (intptr_t)0x00000004, DontDelete|ReadOnly, 0 },
    { "SHOW_CDATA_SECTION", (intptr_t)0x00000008, DontDelete|ReadOnly, 0 },
    { "SHOW_ENTITY_REFERENCE", (intptr_t)0x00000010, DontDelete|ReadOnly, 0 },
    { "SHOW_ENTITY", (intptr_t)0x00000020, DontDelete|ReadOnly, 0 },
    { "SHOW_PROCESSING_INSTRUCTION", (intptr_t)0x00000040, DontDelete|ReadOnly, 0 },
    { "SHOW_COMMENT", (intptr_t)0x00000080, DontDelete|ReadOnly, 0 },
    { "SHOW_DOCUMENT", (intptr_t)0x00000100, DontDelete|ReadOnly, 0 },
    { "SHOW_DOCUMENT_TYPE", (intptr_t)0x00000200, DontDelete|ReadOnly, 0 },
    { "SHOW_DOCUMENT_FRAGMENT", (intptr_t)0x00000400, DontDelete|ReadOnly, 0 },
    { "SHOW_NOTATION", (intptr_t)0x00000800, DontDelete|ReadOnly, 0 },
    { "acceptNode", (intptr_t)jsNodeFilterPrototypeFunctionAcceptNode, DontDelete|Function, 1 },
    { 0, 0, 0, 0 }
};

static const HashTable JSNodeFilterPrototypeTable = { 255, JSNodeFilterPrototypeTableValues, 0 };

const ClassInfo JSNodeFilterPrototype::s_info = { "NodeFilterPrototype", 0, &JSNodeFilterPrototypeTable, 0 };

JSObject* JSNodeFilterPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSNodeFilter.prototype]]");
    return KJS::cacheGlobalObject<JSNodeFilterPrototype>(exec, prototypeIdentifier);
}

bool JSNodeFilterPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticPropertySlot<JSNodeFilterPrototype, JSObject>(exec, &JSNodeFilterPrototypeTable, this, propertyName, slot);
}

JSValue* JSNodeFilterPrototype::getValueProperty(ExecState* exec, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(exec, token);
}

const ClassInfo JSNodeFilter::s_info = { "NodeFilter", 0, &JSNodeFilterTable , 0 };

JSNodeFilter::JSNodeFilter(JSObject* prototype, NodeFilter* impl)
    : DOMObject(prototype)
    , m_impl(impl)
{
}

JSNodeFilter::~JSNodeFilter()
{
    ScriptInterpreter::forgetDOMObject(m_impl.get());

}

bool JSNodeFilter::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSNodeFilter, Base>(exec, &JSNodeFilterTable, this, propertyName, slot);
}

JSValue* JSNodeFilter::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

JSValue* JSNodeFilter::getConstructor(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier constructorIdentifier(exec, "[[NodeFilter.constructor]]");
    return KJS::cacheGlobalObject<JSNodeFilterConstructor>(exec, constructorIdentifier);
}

JSValue* jsNodeFilterPrototypeFunctionAcceptNode(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSNodeFilter::s_info))
        return throwError(exec, TypeError);
    JSNodeFilter* castedThisObj = static_cast<JSNodeFilter*>(thisValue);
    return castedThisObj->acceptNode(exec, args);
}

KJS::JSValue* toJS(KJS::ExecState* exec, NodeFilter* obj)
{
    return cacheDOMObject<NodeFilter, JSNodeFilter, JSNodeFilterPrototype>(exec, obj);
}

}
