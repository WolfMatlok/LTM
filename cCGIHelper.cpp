/* 
 * File:   cCGIHelper.cpp
 * Author: juia
 * 
 * Created on 22. Oktober 2015, 22:30
 */

#include <boost/lexical_cast.hpp>

#include "cCGIHelper.h"

cCGIHelper::cCGIHelper()
: m_poCGI(new cgicc::Cgicc())
, m_bExternalCopyOfCGI(false)
{
  m_strHomeIP = "harrysteiner.ddns.net";
}

cCGIHelper::cCGIHelper(cgicc::Cgicc* p_poCgiCC)
: m_poCGI(p_poCgiCC)
, m_bExternalCopyOfCGI(true)
{
  m_strHomeIP = "harrysteiner.ddns.net";
  m_strRootDirectory = "/var/log/apache2/";
}

cCGIHelper::~cCGIHelper()
{
  if(!m_bExternalCopyOfCGI)
    delete m_poCGI;
}

std::string cCGIHelper::GetParamSTR(std::string p_strParamName, std::string p_strDefault /*= ""*/)
{
  using namespace cgicc;
  // Print out the submitted element
  form_iterator name = m_poCGI->getElement(p_strParamName);
  if (name != m_poCGI->getElements().end())
  {
    return STREAMSTRING(**name);
  }

  return p_strDefault;
}

void cCGIHelper::SaveInput(std::string p_strCurrentState)
{
//  std::string strFileName = STREAMSTRING(m_strRootDirectory << "ltm_input_"<<p_strCurrentState<<".cgicc.input");
//  m_poCGI->save(strFileName);
  if(m_poCGI)
  {
    LOGSTRSTR("Try to get env: ");
    const cgicc::CgiEnvironment& oEnv = m_poCGI->getEnvironment();
    LOGSTRSTR("State:"<<p_strCurrentState<<" with QueryString {" << oEnv.getQueryString() << "}" << endl);
  }
  else
  {
    LOGSTRSTR("Can't get env on appstate:\""<<p_strCurrentState <<"\""<< endl);
  }
}
