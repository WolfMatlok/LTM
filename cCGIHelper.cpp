/* 
 * File:   cCGIHelper.cpp
 * Author: juia
 * 
 * Created on 22. Oktober 2015, 22:30
 */

#include <boost/lexical_cast.hpp>

#include <exception>
#include "cCGIHelper.h"

cCGIHelper::cCGIHelper()
: m_poCGI(new cgicc::Cgicc())
, m_bExternalCopyOfCGI(false)
, m_strDebugCgiBinFile("/home/pi/sandbox/ltm.cgi.lastcall")
, m_bDebugCgiBinFile(false)
{
  m_strHomeIP = "harrysteiner.ddns.net";
}

cCGIHelper::cCGIHelper(cgicc::Cgicc* p_poCgiCC)
: m_poCGI(0)
, m_bExternalCopyOfCGI(true)
, m_strDebugCgiBinFile("/home/pi/sandbox/ltm.cgi.lastcall")
, m_bDebugCgiBinFile(false)
{
  m_poCGI = p_poCgiCC;
  m_strHomeIP = "harrysteiner.ddns.net";
}

cCGIHelper::~cCGIHelper()
{
  if (!m_bExternalCopyOfCGI)
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

void cCGIHelper::StoreEnv(std::string p_strCurrentState)
{
  //  std::string strFileName = STREAMSTRING(m_strRootDirectory << "ltm_input_"<<p_strCurrentState<<".cgicc.input");
  //  m_poCGI->save(strFileName);
  if (m_poCGI)
  {
    const cgicc::CgiEnvironment& oEnv = m_poCGI->getEnvironment();
    LOGSTRSTR("State:" << p_strCurrentState << " with QueryString {" << oEnv.getPostData() << "}" << endl);
    m_poCGI->save(m_strDebugCgiBinFile);
    LOGSTRSTR("Saved to " << m_strDebugCgiBinFile << endl);

  } else
  {
    LOGSTRSTR("Can't get env on appstate:\"" << p_strCurrentState << "\"" << endl);
  }
}

bool cCGIHelper::RestoreEnvFromQueryString(int p_iArgc, char** p_p2Argv)
{
  
  if (m_poCGI && true==DoLoadCgiFromDbgFile(p_iArgc, p_p2Argv))
  {
    m_poCGI->restore(m_strDebugCgiBinFile);
    return true;
  }
  
  return false;
}

bool cCGIHelper::DoLoadCgiFromDbgFile(int p_iArgc, char** p_p2Argv)
{
  // Declare the supported options.
  po::options_description oOptDesc("Debugging Parameter");

  oOptDesc.add_options()
          ("DBG", po::value<bool>(&m_bDebugCgiBinFile)->default_value(false), "debugging last call");

  po::variables_map oVarMap;
  po::store(po::parse_command_line(p_iArgc, p_p2Argv, oOptDesc), oVarMap);
  po::notify(oVarMap);
  
  return m_bDebugCgiBinFile;
}
