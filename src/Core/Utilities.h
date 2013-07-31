//////////////////////////////////////////////////////////////////////////
/*! \class		Utilities
 *  \brief		Utility code to help program.
 *	\details	Holds tools and functions to help debug and store repetitive
 *  \details	helper code in a commonly found location
 *  \author		Anthony Poschen
 *  \version	1.0
 *  \date		5/05/2013
 *  \copyright N/A
 */
//////////////////////////////////////////////////////////////////////////
#ifndef _UTILITIES_H_
# define _UTILITIES_H_
//////////////////////////////////////////////////////////////////////////
//	Includes 
#include <stdio.h>
#include <assert.h>

//////////////////////////////////////////////////////////////////////////
//  Forward Declares 
namespace Utilities
{
	void ConsoleShow(bool a_bShow = true);
	void ConsoleClear();

	void Debug_ConsoleWrite(const char* pFormat, ...);
	void Debug_OutputWrite(const char* pFormat, ...);
}


//////////////////////////////////////////////////////////////////////////
#endif // _UTILITIES_H_
//////////////////////////////////////////////////////////////////////////