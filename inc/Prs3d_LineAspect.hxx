// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Prs3d_LineAspect_HeaderFile
#define _Prs3d_LineAspect_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Prs3d_LineAspect_HeaderFile
#include <Handle_Prs3d_LineAspect.hxx>
#endif

#ifndef _Handle_Graphic3d_AspectLine3d_HeaderFile
#include <Handle_Graphic3d_AspectLine3d.hxx>
#endif
#ifndef _Prs3d_BasicAspect_HeaderFile
#include <Prs3d_BasicAspect.hxx>
#endif
#ifndef _Quantity_NameOfColor_HeaderFile
#include <Quantity_NameOfColor.hxx>
#endif
#ifndef _Aspect_TypeOfLine_HeaderFile
#include <Aspect_TypeOfLine.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class Graphic3d_AspectLine3d;
class Quantity_Color;


//! A framework for defining how a line will be displayed <br>
//! in a presentation. Aspects of line display include <br>
//! width, color and type of line. <br>
//! The definition set by this class is then passed to the <br>
//! attribute manager Prs3d_Drawer. <br>
//! Any object which requires a value for line aspect as <br>
//! an argument may then be given the attribute manager <br>
//! as a substitute argument in the form of a field such as myDrawer for example. <br>
class Prs3d_LineAspect : public Prs3d_BasicAspect {

public:

  //! Constructs a framework for line aspect defined by <br>
//! -   the color aColor <br>
//! -   the type of line aType and <br>
//! -   the line thickness aWidth. <br>
//!   Type of line refers to whether the line is solid or dotted, for example. <br>
  Standard_EXPORT   Prs3d_LineAspect(const Quantity_NameOfColor aColor,const Aspect_TypeOfLine aType,const Standard_Real aWidth);
  
  Standard_EXPORT   Prs3d_LineAspect(const Quantity_Color& aColor,const Aspect_TypeOfLine aType,const Standard_Real aWidth);
  
  Standard_EXPORT     void SetColor(const Quantity_Color& aColor) ;
  //! Sets the line color defined at the time of construction. <br>
//!          Default value: Quantity_NOC_YELLOW <br>
  Standard_EXPORT     void SetColor(const Quantity_NameOfColor aColor) ;
  //! Sets the type of line defined at the time of construction. <br>
//! This could, for example, be solid, dotted or made up of dashes. <br>
//!          Default value: Aspect_TOL_SOLID <br>
  Standard_EXPORT     void SetTypeOfLine(const Aspect_TypeOfLine aType) ;
  //! Sets the line width defined at the time of construction. <br>
//!          Default value: 1. <br>
  Standard_EXPORT     void SetWidth(const Standard_Real aWidth) ;
  //! Returns the line aspect. This is defined as the set of <br>
//! color, type and thickness attributes. <br>
  Standard_EXPORT     Handle_Graphic3d_AspectLine3d Aspect() const;




  DEFINE_STANDARD_RTTI(Prs3d_LineAspect)

protected:




private: 


Handle_Graphic3d_AspectLine3d myAspect;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
