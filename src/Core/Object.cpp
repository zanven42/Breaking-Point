//////////////////////////////////////////////////////////////////////////
//	< Author >	< Anthony Poschen >
//	< Date >	< 18/2/2013 >
//	< File >	< Object >
//	< Brief >	< Object Implementation for full RTTI Support >
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	< Includes >
#include "Object.h"

//////////////////////////////////////////////////////////////////////////
// < Forward Declares >
const Rtti Object::TYPE("Object",0);

//////////////////////////////////////////////////////////////////////////
const Rtti& Object::GetType() const
{
	return TYPE;
}

//////////////////////////////////////////////////////////////////////////
bool Object::IsExsactly(const Rtti& a_kType) const
{
	return GetType().IsExsactly(a_kType);
}

//////////////////////////////////////////////////////////////////////////
bool Object::IsDerived(const Rtti& a_kType) const
{
	return GetType().IsDerived(a_kType);
}

//////////////////////////////////////////////////////////////////////////
bool Object::IsExsactlyTypeOf(const Object* a_pkObj) const
{
	return a_pkObj && GetType().IsExsactly(a_pkObj->GetType());
}

//////////////////////////////////////////////////////////////////////////
bool Object::IsDerivedTypeOf(const Object* a_pkObj) const
{
	return a_pkObj && GetType().IsDerived(a_pkObj->GetType());
}