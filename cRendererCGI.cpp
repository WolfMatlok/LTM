/* 
 * File:   cRendererHtml.cpp
 * Author: juia
 * 
 * Created on 22. Oktober 2015, 21:44
 */

#include "cRendererCGI.h"
#include "cTournamentParameter.h"
using namespace std;
using namespace cgicc;

cRendererCGI::cRendererCGI(cgicc::Cgicc* p_poCGI)
: cCGIHelper(p_poCGI)
{
}

cRendererCGI::~cRendererCGI()
{

}


void cRendererCGI::Render(cTournament* p_poTournament)
{

}


void cRendererCGI::RenderStartScreen()
{
  this->HTMLStart();
  
  //cout << "<form method=\"post\" action=\"http://" << m_strHomeIP << "/cgi-bin/ltm.cgi\">
  cout << this->Form(FRM_START);
  cout << SetParamHidden(APPSTATE, APPSTATE_PRINTCONTENT);
  cout << SetParamHidden(APPUUID, STREAMSTRING(boost::uuids::random_generator()()));
  //cout << SetParamHidden(APPFRAMESUSED, STREAMSTRING(m_bWithoutFrames));
  cout << SetParamNumber(TEAM1, "3", "10", "5") << br();
  cout << SetParamNumber(TEAM2, "3", "10", "5") << br();
  cout << SetParamNumber(COURTS, "1", "4", "4") << br();
  cout << SetParamNumber(TTP, "1", "4", "2") << br();
  cout << SetParamNumber(TFG, "7", "60", "10") << br();
  cout << "<button type=\"submit\" name=\"action\" value=\"0\">Start</button>";
  cout << this->Form(FRM_END);
  
  this->HTMLEnd();
}


void cRendererCGI::PrintCGIParams()
{
  cout << table();

  cout << tr() << td() << APPSTATE << ":" << td() << td() << GetParamSTR(APPSTATE) << td() << tr();
  cout << tr() << td() << APPUUID << ":" << td() << td() << GetParamSTR(APPUUID) << td() << tr();
  cout << tr() << td() << APPFRAMESUSED << ":" << td() << td() << GetParamSTR(APPFRAMESUSED) << td() << tr();
  cout << tr() << td() << TTP << ":" << td() << td() << GetParamSTR(TTP) << td() << tr();
  cout << tr() << td() << TFG << ":" << td() << td() << GetParamSTR(TFG) << td() << tr();
  cout << tr() << td() << COURTS << ":" << td() << td() << GetParamSTR(COURTS) << td() << tr();
  cout << tr() << td() << TEAM1 << ":" << td() << td() << GetParamSTR(TEAM1) << td() << tr();
  cout << tr() << td() << TEAM2 << ":" << td() << td() << GetParamSTR(TEAM2) << td() << tr();

  cout << table();

}

std::string cRendererCGI::HTMLStart()
{
  cout << HTTPHTMLHeader() << endl;
  cout << html() << head(title("TGS Light Turnier Manager")) << endl;
  cout << body() << endl;
}

std::string cRendererCGI::HTMLEnd()
{
  cout << body() << html() << endl;
}

std::string cRendererCGI::SetParamHidden(std::string p_strParamName, std::string p_strParamValue)
{
  return STREAMSTRING(input().set("name", p_strParamName).set("type", "hidden").set("value", p_strParamValue));
}

std::string cRendererCGI::SetParamNumber(std::string p_strName, std::string p_strMin, std::string p_strMax, std::string p_strValue)
{
  //"Your Group Size 1: <input name=\"team1\" type=\"number\" min=\"1\" max=\"10\" step=\"1\" value=\"5\"/>
  return STREAMSTRING(p_strName << input().set("name", p_strName).set("type", "number").set("min", p_strMin).set("max", p_strMax).set("value", p_strValue));
}

std::string cRendererCGI::Form(FormType p_eFrmTyp)
{
  if (FRM_START == p_eFrmTyp)
    return STREAMSTRING(form().set("method", "post").set("action", STREAMSTRING("http://" << m_strHomeIP << "/cgi-bin/ltm.cgi")));

  if (FRM_END == p_eFrmTyp)
    return STREAMSTRING(form());
}


