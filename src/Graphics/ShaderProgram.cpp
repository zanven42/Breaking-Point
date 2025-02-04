//////////////////////////////////////////////////////////////////////////
//	< Author >	< Anthony Poschen >
//	< Date >	< 15/3/2013 >
//  < File >	< ShaderProgram >
//  < Brief >	< ShaderProgram Implementation >
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	< Includes >
#include "ShaderProgram.h"
#include "ShaderFactory.h"
#include <boost/algorithm/string.hpp>
//////////////////////////////////////////////////////////////////////////
// < Forward Declares >


//////////////////////////////////////////////////////////////////////////
ShaderProgram::ShaderProgram()
	:m_sProgramName(boost::container::string(""))
{
	m_uiPropertyType = SHADER_PROGRAM;
}

//////////////////////////////////////////////////////////////////////////
ShaderProgram::~ShaderProgram()
{

}

//////////////////////////////////////////////////////////////////////////
bool ShaderProgram::LoadShaderProgram(const char * a_pcProgramName)
{
	boost::container::string oProgramName(a_pcProgramName);
	boost::algorithm::to_upper(oProgramName);
	m_sProgramName = oProgramName;
	ShaderFactory::Get()->BuildShader((*this));
	return true;
}