/*
 * Copyright (C) 2004, 2005, 2007 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005 Rob Buis <buis@kde.org>
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

#ifndef SVGFEOffsetElement_h
#define SVGFEOffsetElement_h

#include "FEOffset.h"
#include "SVGAnimatedNumber.h"
#include "SVGFilterPrimitiveStandardAttributes.h"

namespace WebCore {

class SVGFEOffsetElement final : public SVGFilterPrimitiveStandardAttributes {
public:
    static Ref<SVGFEOffsetElement> create(const QualifiedName&, Document&);

private:
    SVGFEOffsetElement(const QualifiedName&, Document&);

    virtual void parseAttribute(const QualifiedName&, const AtomicString&) override;
    virtual void svgAttributeChanged(const QualifiedName&) override;
    virtual RefPtr<FilterEffect> build(SVGFilterBuilder*, Filter&) override;

    BEGIN_DECLARE_ANIMATED_PROPERTIES(SVGFEOffsetElement)
        DECLARE_ANIMATED_STRING(In1, in1)
        DECLARE_ANIMATED_NUMBER(Dx, dx)
        DECLARE_ANIMATED_NUMBER(Dy, dy)
    END_DECLARE_ANIMATED_PROPERTIES
};

} // namespace WebCore

#endif
