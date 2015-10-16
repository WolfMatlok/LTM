/* 
 * File:   cGUICgi.h
 * Author: juia
 *
 * Created on 13. Oktober 2015, 20:03
 */

#ifndef CGUICGI_H
#define	CGUICGI_H

#include <iostream>
#include <vector>
#include <string>

#include "boost/uuid/uuid.hpp"            // uuid class
#include "boost/uuid/uuid_generators.hpp" // generators
#include "boost/uuid/uuid_io.hpp"         // streaming operators etc.

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#define APPSTATE "appstate"
#define APPSTATE_NOTHING "appstate_nothing"
#define APPSTATE_PRINTCONTENT "appstate_printcontent"

#define APPUUID "appuuid"
#define APPFRAMESUSED "appframesused"

class cGUICgi
{
public:
  cGUICgi();
  virtual ~cGUICgi();  
  
  static void Dispatch();  
  
  void PrintContent();
  void StartScreen();
  
private:
  cgicc::Cgicc m_oCGI;
  
  std::string m_strHomeIP;
  std::string m_strUUID;
  bool m_bWithoutFrames;
  
  std::string HTMLStart();
  std::string HTMLEnd();
  
  std::string GetParam(std::string p_strParamName);
  
  std::string SetParamHidden(std::string p_strParamName, std::string p_strParamValue);
  
  std::string SetParamNumber(std::string p_strName, std::string p_strMin, std::string p_strMax, std::string p_strValue);
  
  enum FormType {FRM_START, FRM_END};
  std::string Form(FormType p_eFrmTyp);

};

#endif	/* CGUICGI_H */

