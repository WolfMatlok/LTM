/* 
 * File:   cGUICgi.cpp
 * Author: juia
 * 
 * Created on 13. Oktober 2015, 20:03
 */

#include "cGUICgi.h"
#include "cHelper.h"
#include "cTournamentParameter.h"
#include "cTournament.h"

using namespace std;
using namespace cgicc;

cGUICgi::cGUICgi()
: cCGIHelper()
{
}

cGUICgi::~cGUICgi()
{
}

void cGUICgi::Dispatch(int p_iAgrc, char** p_p2Argv)
{
  try
  {
    cGUICgi oCgiGui;
    oCgiGui.RestoreEnvFromQueryString(p_iAgrc, p_p2Argv);
    std::string strState = oCgiGui.GetParamSTR(APPSTATE, APPSTATE_START); //pre analysing the cgi parameter passed from client

    //*** return start display ***
    if (APPSTATE_START == strState)
    {
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      oRenderer.RenderStartScreen();
    }

    //*** return gettingparam ***
    if (APPSTATE_PRINTCONTENT == strState)
    {
      //*** parse parameter ***
      LOGSTRSTR("*** parsing parameter ***" << endl);
      cTournamentParameter oTournamentParameter( 
        oCgiGui.GetParam<double>(TTP)
      , oCgiGui.GetParam<double>(TFG)
      , oCgiGui.GetParam<int>(COURTS)
      , oCgiGui.GetParam<int>(TEAM1)
      , oCgiGui.GetParam<int>(TEAM2) );
      
      //*** calc tournament ***
      LOGSTRSTR("*** calculate tournament ***"<< endl);
      cTournament oTournament(&oTournamentParameter);
      oTournament.Create();
      
      //*** render results to cgi ***
      LOGSTRSTR("*** render results ***"<< endl);
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      oRenderer.Render(&oTournament);
      
    }

  }
  catch (exception& oEx)
  {
    LOGSTRSTR_ERROR("cGUICgi::Dispatch() cgicc is not working:" << oEx.what() << endl);
  }

}