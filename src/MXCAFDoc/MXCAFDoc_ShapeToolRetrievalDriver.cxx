// Created on: 2000-08-15
// Created by: data exchange team
// Copyright (c) 2000-2012 OPEN CASCADE SAS
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



#include <MDF_RRelocationTable.hxx>
#include <MXCAFDoc_ShapeToolRetrievalDriver.ixx>
#include <MgtTopLoc.hxx>
#include <PTColStd_PersistentTransientMap.hxx>
#include <PXCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_ShapeTool.hxx>


//=======================================================================
//function : Constructor
//purpose  : 
//=======================================================================

MXCAFDoc_ShapeToolRetrievalDriver::MXCAFDoc_ShapeToolRetrievalDriver(const Handle(CDM_MessageDriver)& theMsgDriver) : MDF_ARDriver (theMsgDriver)
{
}

//=======================================================================
//function : VersionNumber
//purpose  : 
//=======================================================================

 Standard_Integer MXCAFDoc_ShapeToolRetrievalDriver::VersionNumber() const
{
  return 0;
}

//=======================================================================
//function : SourceType
//purpose  : 
//=======================================================================

 Handle(Standard_Type) MXCAFDoc_ShapeToolRetrievalDriver::SourceType() const
{
  static Handle(Standard_Type) sourceType = STANDARD_TYPE(PXCAFDoc_ShapeTool);
  return sourceType;
}

//=======================================================================
//function : NewEmpty
//purpose  : 
//=======================================================================

 Handle(TDF_Attribute) MXCAFDoc_ShapeToolRetrievalDriver::NewEmpty() const
{
  return new XCAFDoc_ShapeTool();
}

//=======================================================================
//function : Paste
//purpose  : 
//=======================================================================

void MXCAFDoc_ShapeToolRetrievalDriver::Paste (const Handle(PDF_Attribute)& /* Source */,
					       const Handle(TDF_Attribute)& /* Target*/,
					       const Handle(MDF_RRelocationTable)& /*RelocTable*/) const
{
}

