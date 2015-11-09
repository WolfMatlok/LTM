/* 
 * File:   cCSS.cpp
 * Author: wmk
 * 
 * Created on 9. November 2015, 14:39
 */

#include "cCSS.h"

cCSS::cCSS()
: m_strCssSimple("<button type=\"submit\" name=\"action\" value=\"0\">Start</button>")
{
}

cCSS::cCSS(const cCSS& orig)
{
  m_strCssSimple = orig.m_strCssSimple;
}

cCSS::~cCSS()
{
}

cCSS::cCssPtr cCSS::CreateCssDefinition()
{
  return cCssPtr();
}

std::string cCSS::GetSimpleCssStyles()
{
  return m_strCssSimple;
}

