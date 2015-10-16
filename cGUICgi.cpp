/* 
 * File:   cGUICgi.cpp
 * Author: juia
 * 
 * Created on 13. Oktober 2015, 20:03
 */

#include "cGUICgi.h"
#include "cHelper.h"
#include "cApplication.h"

using namespace std;
using namespace cgicc;

cGUICgi::cGUICgi()
{
  m_strHomeIP = "harrysteiner.ddns.net";
}

cGUICgi::~cGUICgi()
{
}

void cGUICgi::Dispatch()
{
  
  try
  {
    cGUICgi oCgiGui;
    std::string strState = oCgiGui.GetParam(APPSTATE);
    
    oCgiGui.HTMLStart();

    //*** return start display ***
    if (strState == "")
    {
      oCgiGui.StartScreen();
    }

    //*** return gettingparam ***
    if (APPSTATE_PRINTCONTENT == strState)
    {
      oCgiGui.PrintContent();
    }
    
    oCgiGui.HTMLEnd();

  } catch (exception& oEx)
  {
    cout << STREAMSTRING("cGUICgi::Dispatch() cgicc is not working:" << oEx.what()) << endl;
  }

}

void cGUICgi::StartScreen()
{
  //cout << "<form method=\"post\" action=\"http://" << m_strHomeIP << "/cgi-bin/ltm.cgi\">
  cout << Form(FRM_START);
  cout << SetParamHidden(APPSTATE, APPSTATE_PRINTCONTENT);
  cout << SetParamHidden(APPUUID, STREAMSTRING(boost::uuids::random_generator()()));
  cout << SetParamHidden(APPFRAMESUSED, STREAMSTRING(m_bWithoutFrames));
  cout << SetParamNumber(TEAM1, "3", "10", "5") << br();
  cout << SetParamNumber(TEAM2, "3", "10", "5")<< br();
  cout << SetParamNumber(COURTS, "1", "4", "4")<< br();
  cout << SetParamNumber(TTP, "1", "4", "2")<< br();
  cout << SetParamNumber(TFG, "7", "60", "10")<< br();
  cout << "<button type=\"submit\" name=\"action\" value=\"0\">Start</button>";
  cout << Form(FRM_END);
}

void cGUICgi::PrintContent()
{  
  cout << table();
  
  cout << tr() << td() <<  APPSTATE        << ":" << td() << td() << GetParam(APPSTATE)         << td() << tr();
  cout << tr() << td() <<  APPUUID         << ":" << td() << td() << GetParam(APPUUID)          << td() << tr();
  cout << tr() << td() <<  APPFRAMESUSED   << ":" << td() << td() << GetParam(APPFRAMESUSED)    << td() << tr();
  cout << tr() << td() <<  TTP             << ":" << td() << td() << GetParam(TTP)              << td() << tr();
  cout << tr() << td() <<  TFG             << ":" << td() << td() << GetParam(TFG)              << td() << tr();
  cout << tr() << td() <<  COURTS          << ":" << td() << td() << GetParam(COURTS)           << td() << tr();
  cout << tr() << td() <<  TEAM1           << ":" << td() << td() << GetParam(TEAM1)            << td() << tr();
  cout << tr() << td() <<  TEAM2           << ":" << td() << td() << GetParam(TEAM2)            << td() << tr();
  
  cout << table();
  
}

std::string cGUICgi::GetParam(std::string p_strParamName)
{
  // Print out the submitted element
  form_iterator name = m_oCGI.getElement(p_strParamName);
  if (name != m_oCGI.getElements().end())
  {
    return STREAMSTRING(**name);
  }

  return "";
}

std::string cGUICgi::SetParamHidden(std::string p_strParamName, std::string p_strParamValue)
{
  return STREAMSTRING(input().set("name", p_strParamName).set("type", "hidden").set("value", p_strParamValue));
}

std::string cGUICgi::SetParamNumber(std::string p_strName, std::string p_strMin, std::string p_strMax, std::string p_strValue)
{
//"Your Group Size 1: <input name=\"team1\" type=\"number\" min=\"1\" max=\"10\" step=\"1\" value=\"5\"/>
  return STREAMSTRING( p_strName << input().set("name", p_strName).set("type", "number").set("min", p_strMin).set("max", p_strMax).set("value", p_strValue));
}


std::string cGUICgi::Form(FormType p_eFrmTyp)
{
  if(FRM_START==p_eFrmTyp)
    return STREAMSTRING(form().set("method", "post").set("action", STREAMSTRING("http://" << m_strHomeIP << "/cgi-bin/ltm.cgi")));
  
  if(FRM_END==p_eFrmTyp)
    return STREAMSTRING(form());
}

std::string cGUICgi::HTMLStart()
{
  cout << HTTPHTMLHeader() << endl;
  cout << html() << head(title("TGS Light Turnier Manager")) << endl;
  cout << body() << endl;
}

std::string cGUICgi::HTMLEnd()
{
    cout << body() << html() << endl;    
}


