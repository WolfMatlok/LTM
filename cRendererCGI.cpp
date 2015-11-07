/* 
 * File:   cRendererHtml.cpp
 * Author: juia
 * 
 * Created on 22. Oktober 2015, 21:44
 */

#include "cRendererCGI.h"
#include "cTournamentParameter.h"
#include "cTournament.h"
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
  this->HTMLStart();

  MAPENCOUNTER& oEncounters = p_poTournament->GetEncountersChoosen();

  cout << table();
  
  for (auto oItEncounter = oEncounters.begin(); oItEncounter != oEncounters.end(); ++oItEncounter)
  {
    //COUTSTRSTR("<div>GID:" << oItEncounter->second.GetGameId() << "</div>");
    cout << tr() ;
    cout << td() << oItEncounter->second.GetId() << td();
    cout << td() << oItEncounter->second.GetIdRound() << td();    
    cout << td() << *(oItEncounter->second.GetPairA()) << td();
    cout << td() << "vs" << td();
    cout << td() << *(oItEncounter->second.GetPairB()) << td();
    cout << td() << "on" << td();
    cout << td() << oItEncounter->second.GetIdCourt() << td();
    cout  << tr();
  }
  
  cout << table();
  
  this->HTMLEnd();
}

void cRendererCGI::RenderStartScreen()
{
  this->HTMLStart();

  cout << "<form method=\"post\" action=\"http://" << m_strHomeIP << "/cgi-bin/ltm.cgi\">";
  //cout << this->Form(FRM_START);
  SetParamHidden(APPSTATE, APPSTATE_PRINTCONTENT);
  SetParamHidden(APPUUID, STREAMSTRING(boost::uuids::random_generator()()));
  SetParamNumber(TEAM1, "3", "10", "5");
  SetParamNumber(TEAM2, "3", "10", "5");
  SetParamNumber(COURTS, "1", "4", "4");
  SetParamNumber(TTP, "1", "4", "2");
  SetParamNumber(TFG, "7", "60", "10");
  cout << "<button type=\"submit\" name=\"action\" value=\"0\">Start</button>";
  //cout << this->Form(FRM_END);
  cout << "</form>";

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

void cRendererCGI::TableStart(int p_iCols)
{
  cout << table();
  
  if(p_iCols)
    cout << tr();
  
  for(int iCol = 0; iCol<p_iCols;++iCol)
  {
    cout  << td() << "" << td() ;// todo add possible headline here
  }
  
  if(p_iCols)
    cout << tr();
}

void cRendererCGI::TableEnd()
{
  cout << table();
}



void cRendererCGI::HTMLStart()
{
  cout << HTTPHTMLHeader() << endl;
  cout << html() << head(title(STREAMSTRING("TGS Light Turnier Manager (" << __DATE__ << " " << __TIME__ << ")"))) << endl;
  cout << body() << endl;
}

void cRendererCGI::HTMLEnd()
{
  cout << body() << html() << endl;
}

std::string cRendererCGI::SetParamHidden(std::string p_strParamName, std::string p_strParamValue)
{
  COUTSTRSTR(input().set("name", p_strParamName).set("type", "hidden").set("value", p_strParamValue));
  COUTSTRSTR(br());
  return "";
}

std::string cRendererCGI::SetParamNumber(std::string p_strName, std::string p_strMin, std::string p_strMax, std::string p_strValue)
{
  //"Your Group Size 1: <input name=\"team1\" type=\"number\" min=\"1\" max=\"10\" step=\"1\" value=\"5\"/>
  COUTSTRSTR(p_strName << input().set("name", p_strName).set("type", "number").set("min", p_strMin).set("max", p_strMax).set("value", p_strValue));
  COUTSTRSTR(br());
  return "";
}

std::string cRendererCGI::Form(FormType p_eFrmTyp)
{
  if (FRM_START == p_eFrmTyp)
  {
    COUTSTRSTR(form().set("method", "post").set("action", STREAMSTRING("http://" << m_strHomeIP << "/cgi-bin/ltm.cgi")));
    COUTSTRSTR(br());
  }

  if (FRM_END == p_eFrmTyp)
  {
    COUTSTRSTR(form());
    COUTSTRSTR(br());
  }

  return "";
}


