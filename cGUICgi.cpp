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
  cout << STREAMSTRING("cGUICgi::Dispatch() starting:") << endl;
  try
  {
    cGUICgi oCgiGui;
    std::string strState = oCgiGui.GettingParam(APPSTATE);

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

  } catch (exception& oEx)
  {
    cout << STREAMSTRING("cGUICgi::Dispatch() cgicc is not working:" << oEx.what()) << endl;
  }

}

void cGUICgi::StartScreen()
{
  // Send HTTP header
  cout << HTTPHTMLHeader() << endl;

  // Set up the HTML document
  cout << html() << head(title("TGS Light Turnier Manager 0.0.2")) << endl;
  cout << body() << endl;

  //cout << "<form method=\"post\" action=\"http://" << m_strHomeIP << "/cgi-bin/ltm.cgi\">
  cout << Form(FRM_START);
  cout << NextState(APPSTATE_PRINTCONTENT);
  cout << ParamNumber(TEAM1) << br();
  cout << ParamNumber(TEAM2)<< br();
  cout << ParamNumber(COURTS)<< br();
  cout << "<button type=\"submit\" name=\"action\" value=\"0\">Start</button>";
  cout << Form(FRM_END);

  // Close the HTML document
  cout << body() << html();
}

void cGUICgi::PrintContent()
{
  // Send HTTP header
  cout << HTTPHTMLHeader() << endl;

  // Set up the HTML document
  cout << html() << head(title("TGS Light Turnier Manager")) << endl;
  cout << body() << cgicc::div() << endl;
  
  cout << APPSTATE << ":" << GettingParam(APPSTATE) << cgicc::br() << endl;
  cout << TTP << ":" << GettingParam(TTP) << cgicc::br() << endl;
  cout << TFG << ":" << GettingParam(TFG) << cgicc::br() << endl;
  cout << COURTS << ":" << GettingParam(COURTS) << cgicc::br() << endl;
  cout << TEAM1 << ":" << GettingParam(TEAM1) << cgicc::br() << endl;
  cout << TEAM2 << ":" << GettingParam(TEAM2) << cgicc::br() << endl;
  
  cout << cgicc::div() << body() << html() << endl;
}

std::string cGUICgi::GettingParam(std::string p_strParamName)
{
  // Print out the submitted element
  form_iterator name = m_oCGI.getElement(p_strParamName);
  if (name != m_oCGI.getElements().end())
  {
    return STREAMSTRING(**name);
  }

  return "";
}

std::string cGUICgi::NextState(std::string p_strNextState)
{
  return STREAMSTRING(input().set("name", APPSTATE).set("type", "hidden").set("value", p_strNextState));
}

std::string cGUICgi::ParamNumber(std::string p_strName)
{
//"Your Group Size 1: <input name=\"team1\" type=\"number\" min=\"1\" max=\"10\" step=\"1\" value=\"5\"/>
  return STREAMSTRING( p_strName << input().set("name", p_strName).set("type", "number").set("min", "3").set("max", "10").set("value", "5"));
}


std::string cGUICgi::Form(FormType p_eFrmTyp)
{
  if(FRM_START==p_eFrmTyp)
    return STREAMSTRING(form().set("method", "post").set("action", STREAMSTRING("http://" << m_strHomeIP << "/cgi-bin/ltm.cgi")));
  
  if(FRM_END==p_eFrmTyp)
    return STREAMSTRING(form());
}
