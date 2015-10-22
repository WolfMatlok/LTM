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
{
  m_strHomeIP = "harrysteiner.ddns.net";
}

cCGIHelper::cCGIHelper(cgicc::Cgicc* p_poCgiCC)
: m_poCGI(p_poCgiCC)
{
  m_strHomeIP = "harrysteiner.ddns.net";
}


cCGIHelper::~cCGIHelper()
{
  delete m_poCGI;
}

std::string cCGIHelper::GetParamSTR(std::string p_strParamName)
{
  return GetParam<std::string>(p_strParamName);
}
