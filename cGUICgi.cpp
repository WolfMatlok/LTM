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

void cGUICgi::Dispatch()
{
  try
  {
    cGUICgi oCgiGui;
    std::string strState = oCgiGui.GetParamSTR(APPSTATE); //pre analysing the cgi parameter passed from client

    //*** return start display ***
    if (strState == "")
    {
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      oRenderer.RenderStartScreen();
    }

    //*** return gettingparam ***
    if (APPSTATE_PRINTCONTENT == strState)
    {
      //*** parse parameter ***
      LOGSTRSTR("*** parsing parameter ***");
      cTournamentParameter oTournamentParameter( 
        oCgiGui.GetParam<double>(TTP)
      , oCgiGui.GetParam<double>(TFG)
      , oCgiGui.GetParam<int>(COURTS)
      , oCgiGui.GetParam<int>(TEAM1)
      , oCgiGui.GetParam<int>(TEAM2) );
      
      //*** calc tournament ***
      LOGSTRSTR("*** calculate tournament ***");
      cTournament oTournament(&oTournamentParameter);
      oTournament.Create();
      
      //*** render results to cgi ***
      LOGSTRSTR("*** render results ***");
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      oRenderer.Render(&oTournament);
      
    }

  }
  catch (exception& oEx)
  {
    LOGSTRSTR_ERROR("cGUICgi::Dispatch() cgicc is not working:" << oEx.what());
  }

}


