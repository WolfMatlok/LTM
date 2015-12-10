/* 
 * File:   cRendererHtml.cpp
 * Author: juia
 * 
 * Created on 22. Oktober 2015, 21:44
 */

#include "cRendererCGI.h"
#include "cTournamentParameter.h"
#include "cTournament.h"
#include "cCSS.h"
#include "cHelperSerializer.h"
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
  cout << tr() ;
	cout << "<td colspan=\"6\">"
          << p_poTournament->GetParameter()->GetTimeOfCreation();
  if(!p_poTournament->GetParameter()->GetSaved())
  {
    cout << Form(FRM_START)
       << SetParamHidden(APPCMD, APPCMD_SAVE_TOURNAMENT)
       << SetParamHidden(APP_PARAM_UUID, STREAMSTRING(p_poTournament->GetParameter()->GetUUID() << ".tmp") )
       << SetParamHidden(APP_PARAM_TOURNAMENTTOSAVE, STREAMSTRING(p_poTournament->GetParameter()->GetTimeOfCreation() << ".ltm"))
       << SetButton("Save")
       << Form(FRM_END);
  }
  else
  {
    cout << " (saved)";
  }
  cout <<"</td>";
	cout  << tr();
  
	cout << tr() ;
	cout << th() << "<h2>Round</h2>"   << th();    
	cout << th() << "<h2>Pair A</h2>"  << th();
	cout << th() << ""        << th();
	cout << th() << "<h2>Pair B</h2>"  << th();
	cout << th() << ""        << th();
	cout << th() << "<h2>Court</h2>"   << th();
	cout  << tr();
  
  int iLastRoundId = 0;
  for (auto oItEncounter = oEncounters.begin(); oItEncounter != oEncounters.end(); ++oItEncounter)
  {
    if(iLastRoundId!=oItEncounter->second.GetIdRound())//print line if new round starts
      cout << tr() << "<td colspan=\"6\"><hr></td>" << tr();
      
      
    cout << tr();
    cout << td() <<   oItEncounter->second.GetIdRound() << td();
    cout << td() << *(oItEncounter->second.GetPairA()) << td();
    cout << td() <<   "vs" << td();
    cout << td() << *(oItEncounter->second.GetPairB()) << td();
    cout << td() <<   "on" << td();
    cout << td() <<   oItEncounter->second.GetIdCourt() << td();
    cout << tr();
    
    iLastRoundId = oItEncounter->second.GetIdRound();
  }
  
  cout << table();
  
  this->HTMLEnd();
}

void cRendererCGI::RenderStartScreen()
{
  this->HTMLStart();
  
  //*** show params for new tournament ***
  cout << "<form method=\"post\" action=\"http://" << m_strHomeIP << "/cgi-bin/ltm.cgi\">";  
  SetParamHidden(APPCMD, APPCMD_CREATE_TOURNAMENT);
  SetParamHidden(APP_PARAM_UUID, STREAMSTRING(boost::uuids::random_generator()()));
  cout << table();
  cout << tr() << "<th colspan=\"2\">New Tournament</th>" << tr();
  cout << tr() << td() << TEAM1   << td() << td() << SetParamNumber(TEAM1, "3", "10", "5")  << td() << tr();
  cout << tr() << td() << TEAM2   << td() << td() << SetParamNumber(TEAM2, "3", "10", "5")  << td() << tr();
  cout << tr() << td() << COURTS  << td() << td() << SetParamNumber(COURTS, "1", "4", "4")  << td() << tr();
  cout << tr() << td() << TTP     << td() << td() << SetParamNumber(TTP, "1", "4", "2")     << td() << tr();
  cout << tr() << td() << TFG     << td() << td() << SetParamNumber(TFG, "7", "60", "10")   << td() << tr();
  cout << tr() << "<td colspan=\"2\">" << "<button type=\"submit\" name=\"action\" value=\"0\">Start</button>" << "</td>" << tr();  
  cout << table();
  cout << "</form>";
  
  //*** show existing tournament ***
  cHelperSandboxSerialize oSandBox;
  std::vector<std::string> oLastSerialisations;
  oLastSerialisations = oSandBox.GetFilesOfSandbox(".ltm");
  
  if(!oLastSerialisations.empty())
  {
    cout << "<form method=\"post\" action=\"http://" << m_strHomeIP << "/cgi-bin/ltm.cgi\">";
    SetParamHidden(APPCMD, APPCMD_LOAD_TOURNAMENT_FROM_ARCHIVE);
    cout << table();
    cout << tr() << "<th colspan=\"2\">Load Tournament</th>" << tr();

    cout << tr() << td() << "Last Tournament:" << td();
    cout << td() << "<select name=\"" << APP_PARAM_TOURNAMENTTOLOAD << "\">";
    for(auto oItCurrFile = oLastSerialisations.begin(); oItCurrFile!=oLastSerialisations.end(); ++oItCurrFile)
    {
      std::string strCurrFile = *oItCurrFile;
      cout << "<option>"<< strCurrFile <<"</option>";
    }
    cout << "<select>" << td();
    cout << tr();
    
    cout << tr() << "<td colspan=\"2\">" << this->SetButton("Load") << "</td>" << tr();
    cout << table();
    
    cout << "</form>";
    
  }

  this->HTMLEnd();
}

void cRendererCGI::PrintCGIParams()
{
  cout << table();

  cout << tr() << td() << APPCMD << ":" << td() << td() << GetParamSTR(APPCMD) << td() << tr();
  cout << tr() << td() << APP_PARAM_UUID << ":" << td() << td() << GetParamSTR(APP_PARAM_UUID) << td() << tr();
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
  cCSS oCSSHelper;
  cout << HTTPHTMLHeader() << endl;
  cout << html() << head() << title(STREAMSTRING("TGS Light Turnier Manager (" << __DATE__ << " " << __TIME__ << ")")) << endl;
  cout << oCSSHelper.GetSimpleCssStyles();
  cout << head() << endl;
  cout << body() << endl;
}

void cRendererCGI::HTMLEnd()
{
  cout << body() << html() << endl;
}

std::string cRendererCGI::SetParamHidden(std::string p_strParamName, std::string p_strParamValue)
{
  COUTSTRSTR(input().set("name", p_strParamName).set("type", "hidden").set("value", p_strParamValue));
  return "";
}

std::string cRendererCGI::SetParamNumber(std::string p_strName, std::string p_strMin, std::string p_strMax, std::string p_strValue)
{
  //"Your Group Size 1: <input name=\"team1\" type=\"number\" min=\"1\" max=\"10\" step=\"1\" value=\"5\"/>
  COUTSTRSTR(input().set("name", p_strName).set("type", "number").set("min", p_strMin).set("max", p_strMax).set("value", p_strValue));
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

std::string cRendererCGI::SetButton(std::string p_strText)
{
  return STREAMSTRING("<button type=\"submit\" name=\"action\" value=\"0\">" << p_strText << "</button>");
}

