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
    std::string strState = oCgiGui.GetParamSTR(APPSTATE);

    //*** return start display ***
    if (strState == "")
    {
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      oRenderer.RenderStartScreen();
    }

    //*** return gettingparam ***
    if (APPSTATE_PRINTCONTENT == strState)
    {
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      cTournamentParameter oTournamentParameter( 
        oCgiGui.GetParam<double>(TTP)
      , oCgiGui.GetParam<double>(TFG)
      , oCgiGui.GetParam<int>(COURTS)
      , oCgiGui.GetParam<int>(TEAM1)
      , oCgiGui.GetParam<int>(TEAM2)
      );
      oRenderer.Render(0);
    }

  }  catch (exception& oEx)
  {
    LOGSTRSTR_ERROR("cGUICgi::Dispatch() cgicc is not working:" << oEx.what()) << endl;
  }

}


