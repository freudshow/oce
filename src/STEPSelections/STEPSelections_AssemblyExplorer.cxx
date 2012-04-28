// Created on: 1999-03-24
// Created by: data exchange team
// Copyright (c) 1999-1999 Matra Datavision
// Copyright (c) 1999-2012 OPEN CASCADE SAS
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



#include <STEPSelections_AssemblyExplorer.ixx>
#include <Interface_Macros.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <Interface_EntityIterator.hxx>
#include <StepShape_ContextDependentShapeRepresentation.hxx>
#include <StepShape_ShapeRepresentation.hxx>
#include <StepRepr_MappedItem.hxx>
#include <STEPSelections_AssemblyLink.hxx>
#include <STEPSelections_HSequenceOfAssemblyLink.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_HAsciiString.hxx>


STEPSelections_AssemblyExplorer::STEPSelections_AssemblyExplorer(const Interface_Graph &G):myGraph(G)
{
  Init(G);
}

Handle(Standard_Transient) STEPSelections_AssemblyExplorer::
       FindItemWithNAUO(const Handle(StepRepr_NextAssemblyUsageOccurrence)& nauo) const
{
  Handle(Standard_Transient) item;
  Handle(StepRepr_ProductDefinitionShape) pds;
  Interface_EntityIterator subs = myGraph.Sharings(nauo);
  for(subs.Start(); subs.More()&&pds.IsNull(); subs.Next())
    if(subs.Value()->IsKind(STANDARD_TYPE(StepRepr_ProductDefinitionShape)))
      pds = Handle(StepRepr_ProductDefinitionShape)::DownCast(subs.Value());
  if(pds.IsNull()) return item;
  
  subs = myGraph.Sharings(pds);
  Handle(StepShape_ContextDependentShapeRepresentation) cdsr;
  Handle(StepShape_ShapeDefinitionRepresentation) shdefrep;
  Handle(Standard_Transient) itmp;
  for(subs.Start(); subs.More()&&shdefrep.IsNull(); subs.Next()) {
    itmp = subs.Value();
    if(itmp->IsKind(STANDARD_TYPE(StepShape_ContextDependentShapeRepresentation)))
      return itmp;
    if(itmp->IsKind(STANDARD_TYPE(StepShape_ShapeDefinitionRepresentation)))
      shdefrep = Handle(StepShape_ShapeDefinitionRepresentation)::DownCast(itmp);
  }
  if(shdefrep.IsNull()) return shdefrep ;
  Handle(StepShape_ShapeRepresentation) srep = Handle(StepShape_ShapeRepresentation)::DownCast(shdefrep->UsedRepresentation());
  if(srep.IsNull()) return srep;
  for(Standard_Integer i = 1; i <= srep->NbItems(); i++) {
    Handle(StepRepr_RepresentationItem) repitem = srep->ItemsValue(i);
    if(repitem->IsKind(STANDARD_TYPE(StepRepr_MappedItem)))
      return repitem;
  }   
  return item;
}

Handle(StepShape_ShapeDefinitionRepresentation) STEPSelections_AssemblyExplorer::
       FindSDRWithProduct(const Handle(StepBasic_ProductDefinition)& product) const
{
  Interface_EntityIterator subs = myGraph.Sharings(product);
  for(subs.Start(); subs.More(); subs.Next())
    if(subs.Value()->IsKind(STANDARD_TYPE(StepRepr_PropertyDefinition))) {
      Interface_EntityIterator subs1 = myGraph.Sharings(subs.Value());
      for(subs1.Start(); subs1.More(); subs1.Next())
	if(subs1.Value()->IsKind(STANDARD_TYPE(StepShape_ShapeDefinitionRepresentation))) {
	  DeclareAndCast(StepShape_ShapeDefinitionRepresentation,SDR,subs1.Value());
	  return SDR;
	}
    }
  Handle(StepShape_ShapeDefinitionRepresentation) sdr;
  return sdr;
}

void STEPSelections_AssemblyExplorer::FillListWithGraph(const Handle(STEPSelections_AssemblyComponent)& cmp)
{
  Handle(StepShape_ShapeDefinitionRepresentation) SDR = cmp->GetSDR();
  Handle(STEPSelections_HSequenceOfAssemblyLink) list = cmp->GetList();
  Handle(StepRepr_ProductDefinitionShape) pdsh = 
    Handle(StepRepr_ProductDefinitionShape)::DownCast ( SDR->Definition().PropertyDefinition() );
  if(pdsh.IsNull()) return;
  Handle(StepBasic_ProductDefinition) pdf = pdsh->Definition().ProductDefinition();
  if(pdf.IsNull()) return;
  Interface_EntityIterator subs = myGraph.Sharings(pdf);
  for(subs.Start(); subs.More(); subs.Next()) 
    if(subs.Value()->IsKind(STANDARD_TYPE(StepRepr_NextAssemblyUsageOccurrence))) {
      DeclareAndCast(StepRepr_NextAssemblyUsageOccurrence,nauo,subs.Value());
      if(pdf==nauo->RelatingProductDefinition()) {
	Handle(STEPSelections_AssemblyLink) link = new STEPSelections_AssemblyLink;
	link->SetNAUO(nauo);
	link->SetItem(FindItemWithNAUO(nauo));
	Handle(StepBasic_ProductDefinition) pdrComponent = nauo->RelatedProductDefinition();
	if(pdrComponent.IsNull()) continue;
	Handle(StepShape_ShapeDefinitionRepresentation) subSDR = FindSDRWithProduct(pdrComponent);
	if(subSDR.IsNull()) continue;
	Standard_Integer index = myMap.FindIndex(subSDR);
	if(index)
	  link->SetComponent(Handle(STEPSelections_AssemblyComponent)::DownCast(myMap.FindFromIndex(index)));
	else {
	  Handle(STEPSelections_HSequenceOfAssemblyLink) sublist = new STEPSelections_HSequenceOfAssemblyLink;
	  Handle(STEPSelections_AssemblyComponent) subCmp = new STEPSelections_AssemblyComponent(subSDR,sublist);
	  FillListWithGraph(subCmp);
	  link->SetComponent(subCmp);
	  myMap.Add(subSDR,subCmp);
	}
	list->Append(link);
      }
    } 
}
		       

void STEPSelections_AssemblyExplorer::Init(const Interface_Graph &G)
{
  myGraph = G;
  myRoots.Clear();
  myMap.Clear();
  Interface_EntityIterator roots = myGraph.RootEntities();
  for(roots.Start(); roots.More(); roots.Next()) 
    if(roots.Value()->IsKind(STANDARD_TYPE(StepShape_ShapeDefinitionRepresentation))) {
      Handle(STEPSelections_AssemblyComponent) cmp = new STEPSelections_AssemblyComponent;
      cmp->SetSDR(Handle(StepShape_ShapeDefinitionRepresentation)::DownCast(roots.Value()));
      cmp->SetList(new STEPSelections_HSequenceOfAssemblyLink);
      FillListWithGraph(cmp);
      myRoots.Append(cmp);
    }
}


static Standard_CString GetProductName(const Handle(StepShape_ShapeDefinitionRepresentation) &SDR)
{
  Standard_CString str = "";
  Handle(StepBasic_Product) empty;
  Handle(StepRepr_PropertyDefinition) PropDf = SDR->Definition().PropertyDefinition();
  if ( PropDf.IsNull() ) return str;
  Handle(StepBasic_ProductDefinition) PD = PropDf->Definition().ProductDefinition();
  if ( PD.IsNull() ) return str;
  Handle(StepBasic_ProductDefinitionFormation) PDF = PD->Formation();
  if ( PDF.IsNull() ) return str;
  return PDF->OfProduct()->Name()->ToCString();
}

static void PrintSubAssembly(Standard_OStream &os,
			     const Handle(STEPSelections_AssemblyComponent)& cmp,
			     const Handle(Interface_InterfaceModel) &Model,
			     Standard_Integer level)
{
  //for ( Standard_Integer j=0; j < level; j++ ) os << "\t";
  os << "SDR: " <<Model->StringLabel(cmp->GetSDR())->ToCString()<<"\t";
  
  os << "Product: "<<GetProductName(cmp->GetSDR())<<endl;
  for ( Standard_Integer i = 1; i <= cmp->GetList()->Length(); i++) {
    for ( Standard_Integer j=0; j < level+1; j++ ) os << "\t";
    os << "NAUO :"<<Model->StringLabel(cmp->GetList()->Value(i)->GetNAUO())->ToCString()<<";\t";
    if(cmp->GetList()->Value(i)->GetItem()->IsKind(STANDARD_TYPE(StepRepr_MappedItem))) 
      os <<"MI ";
    else
      if(cmp->GetList()->Value(i)->GetItem()->IsKind(STANDARD_TYPE(StepShape_ContextDependentShapeRepresentation)))
	os <<"CDSR ";
      else
	os <<"UNKNOWN LINK!!!";
    PrintSubAssembly(os,cmp->GetList()->Value(i)->GetComponent(),Model,level+1);
  }
}
  

void STEPSelections_AssemblyExplorer::Dump(Standard_OStream &os) const
{
  Handle(Interface_InterfaceModel) model = myGraph.Model();
  for(Standard_Integer i = 1 ; i <=myRoots.Length(); i++) {
    os<<"Assembly N: "<<i<<endl<<endl;
    PrintSubAssembly(os,myRoots.Value(i),model,0);
  }
}
