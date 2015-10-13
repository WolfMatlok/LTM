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
}

cGUICgi::cGUICgi(const cGUICgi& orig)
{
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
  cout << html() << head(title("TGS Light Turnier Manager")) << endl;
  cout << body() << endl;

  cout << "<form method=\"post\" action=\"http://harrysteiner.ddns.net/cgi-bin/ltm.cgi\"> \
      <input id=\"appstate\" name=\"appstate\" type=\"hidden\" value=\"" << APPSTATE_PRINTCONTENT << "\"/> \
      Your Group Size 1: <input id=\"team1\" name=\"team1\" type=\"number\" min=\"1\" max=\"10\" step=\"1\" value=\"5\"/><br /> \
      Your Group Size 2: <input id=\"team2\" name=\"team2\" type=\"number\" min=\"1\" max=\"10\" step=\"1\" value=\"5\"/><br /> \
      <button type=\"submit\" name=\"action\" value=\"0\">Start</button> \
    </form>";

  // Close the HTML document
  cout << body() << html();
}

void cGUICgi::PrintContent()
{
  cout << APPSTATE << ":" << GettingParam(APPSTATE) << endl;
  cout << TTP << ":" << GettingParam(TTP) << endl;
  cout << TFG << ":" << GettingParam(TFG) << endl;
  cout << COURTS << ":" << GettingParam(COURTS) << endl;
  cout << TEAM1 << ":" << GettingParam(TEAM1) << endl;
  cout << TEAM2 << ":" << GettingParam(TEAM2) << endl;
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