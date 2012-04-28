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


#include <RWStepBasic_RWProductDefinitionWithAssociatedDocuments.ixx>
#include <StepBasic_ProductDefinitionWithAssociatedDocuments.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepBasic_HArray1OfDocument.hxx>
#include <StepBasic_Document.hxx>


#include <Interface_EntityIterator.hxx>


#include <StepBasic_ProductDefinitionWithAssociatedDocuments.hxx>


RWStepBasic_RWProductDefinitionWithAssociatedDocuments::RWStepBasic_RWProductDefinitionWithAssociatedDocuments () {}

void RWStepBasic_RWProductDefinitionWithAssociatedDocuments::ReadStep
	(const Handle(StepData_StepReaderData)& data,
	 const Standard_Integer num,
	 Handle(Interface_Check)& ach,
	 const Handle(StepBasic_ProductDefinitionWithAssociatedDocuments)& ent) const
{


	// --- Number of Parameter Control ---

	if (!data->CheckNbParams(num,5,ach,"product_definition")) return;

	// --- inherited field : id ---

	Handle(TCollection_HAsciiString) aId;
	//szv#4:S4163:12Mar `99Standard_Boolean stat1 =` not needed
	data->ReadString (num,1,"id",ach,aId);

	// --- inherited field : description ---

	Handle(TCollection_HAsciiString) aDescription;
	//szv#4:S4163:12Mar `99Standard_Boolean stat2 =` not needed
	data->ReadString (num,2,"description",ach,aDescription);

	// --- inherited field : formation ---

	Handle(StepBasic_ProductDefinitionFormation) aFormation;
	//szv#4:S4163:12Mar `99Standard_Boolean stat3 =` not needed
	data->ReadEntity(num, 3,"formation", ach, STANDARD_TYPE(StepBasic_ProductDefinitionFormation), aFormation);

	// --- inherited field : frameOfReference ---

	Handle(StepBasic_ProductDefinitionContext) aFrameOfReference;
	//szv#4:S4163:12Mar `99Standard_Boolean stat4 =` not needed
	data->ReadEntity(num, 4,"frame_of_reference", ach, STANDARD_TYPE(StepBasic_ProductDefinitionContext), aFrameOfReference);

        // --- own field : doc_ids ---
 
        Handle(StepBasic_HArray1OfDocument) aDocIds;
        Handle(StepBasic_Document) anent5;
        Standard_Integer nsub5;
        if (data->ReadSubList (num,5,"frame_of_reference",ach,nsub5)) {
          Standard_Integer nb5 = data->NbParams(nsub5);
          if (nb5 > 0) aDocIds = new StepBasic_HArray1OfDocument (1, nb5);
          for (Standard_Integer i5 = 1; i5 <= nb5; i5 ++) {
	    //szv#4:S4163:12Mar `99Standard_Boolean stat5 =` not needed
            if (data->ReadEntity (nsub5, i5,"product_context", ach, STANDARD_TYPE(StepBasic_Document), anent5))
              aDocIds->SetValue(i5, anent5);
          }
        }

	//--- Initialisation of the read entity ---

	ent->Init(aId, aDescription, aFormation, aFrameOfReference, aDocIds);
}


void RWStepBasic_RWProductDefinitionWithAssociatedDocuments::WriteStep
	(StepData_StepWriter& SW,
	 const Handle(StepBasic_ProductDefinitionWithAssociatedDocuments)& ent) const
{

	// --- inherited field : id ---

	SW.Send(ent->Id());

	// --- inherited field : description ---

	SW.Send(ent->Description());

	// --- inherited field : formation ---

	SW.Send(ent->Formation());

	// --- inherited field : DocIds ---

	SW.Send(ent->FrameOfReference());

	// -- own : list

	SW.OpenSub();
	Standard_Integer i,nb = ent->NbDocIds();
	for (i = 1; i <= nb; i ++) SW.Send (ent->DocIdsValue(i));
	SW.CloseSub();

}


void RWStepBasic_RWProductDefinitionWithAssociatedDocuments::Share(const Handle(StepBasic_ProductDefinitionWithAssociatedDocuments)& ent, Interface_EntityIterator& iter) const
{

	iter.GetOneItem(ent->Formation());


	iter.GetOneItem(ent->FrameOfReference());

	Standard_Integer i,nb = ent->NbDocIds();
	for (i = 1; i <= nb; i ++) iter.AddItem (ent->DocIdsValue(i));
}
