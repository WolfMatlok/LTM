/* 
 * File:   cCGIHelper.h
 * Author: juia
 *
 * Created on 22. Oktober 2015, 22:30
 */

#ifndef CCGIHELPER_H
#define	CCGIHELPER_H

#include "cHelper.h"

#include "boost/lexical_cast.hpp"

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

class cCGIHelper
{
public:
  cCGIHelper();
  cCGIHelper(cgicc::Cgicc* p_poCgiCC);

  virtual ~cCGIHelper();

  template<class T>
  T GetParam(std::string p_strParamName)
  {
    return boost::lexical_cast<T>(GetParam<std::string>(p_strParamName));
  }
  
  std::string GetParamSTR(std::string p_strParamName);


protected:
  cgicc::Cgicc* m_poCGI;
  std::string m_strHomeIP;
};

template<>
std::string cCGIHelper::GetParam(std::string p_strParamName)
{
  using namespace cgicc;
  // Print out the submitted element
  form_iterator name = m_poCGI->getElement(p_strParamName);
  if (name != m_poCGI->getElements().end())
  {
    return STREAMSTRING(**name);
  }

  return "";
}

#endif	/* CCGIHELPER_H */

