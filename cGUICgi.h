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

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#define APPSTATE "appstate"
#define APPSTATE_NOTHING "appstate_nothing"
#define APPSTATE_PRINTCONTENT "appstate_printcontent"

class cGUICgi
{
public:
  cGUICgi();
  cGUICgi(const cGUICgi& orig);
  virtual ~cGUICgi();  
  
  static void Dispatch();  
  
  void PrintContent();
  void StartScreen();
  
private:
  cgicc::Cgicc m_oCGI;
  
  std::string GettingParam(std::string p_strParamName);

};

#endif	/* CGUICGI_H */

