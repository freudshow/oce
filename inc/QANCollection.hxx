// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _QANCollection_HeaderFile
#define _QANCollection_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

class Draw_Interpretor;
class QANCollection_ListOfPnt;
class QANCollection_QueueOfPnt;
class QANCollection_StackOfPnt;
class QANCollection_SListOfPnt;
class QANCollection_DataMapOfRealPnt;
class QANCollection_IndexedDataMapOfRealPnt;
class QANCollection_DoubleMapOfRealInteger;
class QANCollection_ListNodeOfListOfPnt;
class QANCollection_ListIteratorOfListOfPnt;
class QANCollection_QueueNodeOfQueueOfPnt;
class QANCollection_StackNodeOfStackOfPnt;
class QANCollection_StackIteratorOfStackOfPnt;
class QANCollection_SListNodeOfSListOfPnt;
class QANCollection_DataMapNodeOfDataMapOfRealPnt;
class QANCollection_DataMapIteratorOfDataMapOfRealPnt;
class QANCollection_IndexedDataMapNodeOfIndexedDataMapOfRealPnt;
class QANCollection_DoubleMapNodeOfDoubleMapOfRealInteger;
class QANCollection_DoubleMapIteratorOfDoubleMapOfRealInteger;



class QANCollection  {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  
  Standard_EXPORT   static  void Commands(Draw_Interpretor& DI) ;
  
  Standard_EXPORT   static  void Commands1(Draw_Interpretor& DI) ;
  
  Standard_EXPORT   static  void Commands2(Draw_Interpretor& DI) ;
  
  Standard_EXPORT   static  void Commands3(Draw_Interpretor& DI) ;





protected:





private:




friend class QANCollection_ListOfPnt;
friend class QANCollection_QueueOfPnt;
friend class QANCollection_StackOfPnt;
friend class QANCollection_SListOfPnt;
friend class QANCollection_DataMapOfRealPnt;
friend class QANCollection_IndexedDataMapOfRealPnt;
friend class QANCollection_DoubleMapOfRealInteger;
friend class QANCollection_ListNodeOfListOfPnt;
friend class QANCollection_ListIteratorOfListOfPnt;
friend class QANCollection_QueueNodeOfQueueOfPnt;
friend class QANCollection_StackNodeOfStackOfPnt;
friend class QANCollection_StackIteratorOfStackOfPnt;
friend class QANCollection_SListNodeOfSListOfPnt;
friend class QANCollection_DataMapNodeOfDataMapOfRealPnt;
friend class QANCollection_DataMapIteratorOfDataMapOfRealPnt;
friend class QANCollection_IndexedDataMapNodeOfIndexedDataMapOfRealPnt;
friend class QANCollection_DoubleMapNodeOfDoubleMapOfRealInteger;
friend class QANCollection_DoubleMapIteratorOfDoubleMapOfRealInteger;

};





// other Inline functions and methods (like "C++: function call" methods)


#endif
