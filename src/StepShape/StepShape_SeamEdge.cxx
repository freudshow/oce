// Created on: 2002-01-04
// Created by: data exchange team
// Copyright (c) 2002-2012 OPEN CASCADE SAS
//
// The content of this file is subject to the Open CASCADE Technology Public
// License Version 6.5 (the "License"). You may not use the content of this file
// except in compliance with the License. Please obtain a copy of the License
// at http://www.opencascade.org and read it completely before using this file.
//
// The Initial Developer of the Original Code is Open CASCADE S.A.S., having its
// main offices at: 1, place des Freres Montgolfier, 78280 Guyancourt, France.
//
// The Original Code and all software distributed under the License is
// distributed on an "AS IS" basis, without warranty of any kind, and the
// Initial Developer hereby disclaims all such warranties, including without
// limitation, any warranties of merchantability, fitness for a particular
// purpose or non-infringement. Please see the License for the specific terms
// and conditions governing the rights and limitations under the License.

// Generator:	ExpToCas (EXPRESS -> CASCADE/XSTEP Translator) V1.1

#include <StepShape_SeamEdge.ixx>

//=======================================================================
//function : StepShape_SeamEdge
//purpose  : 
//=======================================================================

StepShape_SeamEdge::StepShape_SeamEdge ()
{
}

//=======================================================================
//function : Init
//purpose  : 
//=======================================================================

void StepShape_SeamEdge::Init (const Handle(TCollection_HAsciiString) &aRepresentationItem_Name,
                               const Handle(StepShape_Edge) &aOrientedEdge_EdgeElement,
                               const Standard_Boolean aOrientedEdge_Orientation,
                               const Handle(StepGeom_Pcurve) &aPcurveReference)
{
  StepShape_OrientedEdge::Init(aRepresentationItem_Name,
                               aOrientedEdge_EdgeElement,
                               aOrientedEdge_Orientation);

  thePcurveReference = aPcurveReference;
}

//=======================================================================
//function : PcurveReference
//purpose  : 
//=======================================================================

Handle(StepGeom_Pcurve) StepShape_SeamEdge::PcurveReference () const
{
  return thePcurveReference;
}

//=======================================================================
//function : SetPcurveReference
//purpose  : 
//=======================================================================

void StepShape_SeamEdge::SetPcurveReference (const Handle(StepGeom_Pcurve) &aPcurveReference)
{
  thePcurveReference = aPcurveReference;
}
