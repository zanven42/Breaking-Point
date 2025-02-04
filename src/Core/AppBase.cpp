//////////////////////////////////////////////////////////////////////////
//	< Author >	< Anthony Poschen >
//	< Date >	< 20/1/2013 >
// < File >	< AppBase >
// < Brief >	< AppBase implementation >
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	< Includes >
#include "AppBase.h"
#include "../Graphics/Window.h"
#include "../Input/Mouse.h"
//////////////////////////////////////////////////////////////////////////
// < Forward Declares >
AppBase* AppBase::sm_pSingleton = 0;

//////////////////////////////////////////////////////////////////////////
AppBase::AppBase()
	: m_uiFlags(0)
{
	sm_pSingleton = this;
}
	
//////////////////////////////////////////////////////////////////////////
AppBase::~AppBase()
{
	sm_pSingleton = 0;
}
  
//////////////////////////////////////////////////////////////////////////
void AppBase::Execute()
{		
	//bool bMouseScreenLock , bMouseWindowLock;
	//bMouseScreenLock = Mouse::Get()->IsLockedToScreenSpace();
	//bMouseWindowLock = Mouse::Get()->IsLockedToWindow();	
	
	while ((m_uiFlags & FLAGS_DESTROYED) == false)
	{

		if(Window::Get()->IsActive() == false)
		{
			//if(bMouseScreenLock){  Mouse::Get()->LockToScreenSpace(false);}
			//if(bMouseWindowLock){  Mouse::Get()->LockToWindow(false);}
			OnIdle();
			continue;
		}
			
		if (OnUpdate() == false)
		{
			break;
		}
		OnRender();
	}
	OnDestroy();
}

//////////////////////////////////////////////////////////////////////////
bool AppBase::Create(const char* a_sCmdLine)
{
	if(OnCreate(a_sCmdLine) == true)
	{
		m_uiFlags |= FLAGS_CREATED;
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
void AppBase::Destroy()
{
	m_uiFlags |= FLAGS_DESTROYED;
}

//////////////////////////////////////////////////////////////////////////
bool AppBase::IsCreated()
{
	return m_uiFlags & FLAGS_CREATED;
}

//////////////////////////////////////////////////////////////////////////
