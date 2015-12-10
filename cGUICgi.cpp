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
#include "cHelperSerializer.h"

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
    bool bRestoredEnv = oCgiGui.RestoreEnvFromQueryString(p_iAgrc, p_p2Argv);
    std::string strState = oCgiGui.GetParamSTR(APPCMD, APPCMD_START); //pre analysing the cgi parameter passed from client

    if (!bRestoredEnv)
      oCgiGui.StoreEnv(strState);

    //*** return start display ***
    if (APPCMD_START == strState)
    {
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      oRenderer.RenderStartScreen();
    }

    //*** create tournament ***
    if (APPCMD_CREATE_TOURNAMENT == strState)
    {
      //*** parse parameter ***
      LOGSTRSTR("*** parsing parameter ***" << endl);
      cTournamentParameter oTournamentParameter(
              oCgiGui.GetParam<double>(TTP)
              , oCgiGui.GetParam<double>(TFG)
              , oCgiGui.GetParam<int>(COURTS)
              , oCgiGui.GetParam<int>(TEAM1)
              , oCgiGui.GetParam<int>(TEAM2)
              , oCgiGui.GetParamSTR(APP_PARAM_UUID) );

      //*** calc tournament ***
      LOGSTRSTR("*** calculate tournament ***" << endl);
      cTournament oTournament(&oTournamentParameter);
      oTournament.Create();
      
      //*** write it temporarily for later use if wanted ***
      cSerializer oSerializer(STREAMSTRING(oTournamentParameter.GetUUID() << ".tmp"));
      oSerializer.Write<cTournament>(oTournament);

      //*** render results to cgi ***
      LOGSTRSTR("*** render results ***" << endl);
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      oRenderer.Render(&oTournament);
    }
    
    if(APPCMD_SAVE_TOURNAMENT == strState)
    {
      std::string strFilenameTmp = oCgiGui.GetParamSTR(APP_PARAM_UUID);
      std::string strFilename = oCgiGui.GetParamSTR(APP_PARAM_TOURNAMENTTOSAVE);
      
      //*** read temporary tournament ***
      cDeserializer oDeserializer(strFilenameTmp);
      cTournament oTournament;
      oDeserializer.Read<cTournament>(oTournament);
      
      oTournament.GetParameter()->SetSaved(true);
      
      //*** copy it to make it available the next time ***
      cSerializer oSerializer(strFilename);
      oSerializer.Write<cTournament>(oTournament);
      
      //*** render results to cgi ***
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      oRenderer.Render(&oTournament);
      
    }
    
    if(APPCMD_LOAD_TOURNAMENT_FROM_ARCHIVE == strState)
    {
      std::string strFilename = oCgiGui.GetParamSTR(APP_PARAM_TOURNAMENTTOLOAD);
      
      cDeserializer oDeserializer(strFilename);
      cTournament oTournament;
      oDeserializer.Read<cTournament>(oTournament);
      
      //*** render results to cgi ***
      cRendererCGI oRenderer(oCgiGui.m_poCGI);
      oRenderer.Render(&oTournament);
    }

  }  catch (exception& oEx)
  {
    LOGSTRSTR_ERROR("cGUICgi::Dispatch() cgicc is not working:" << oEx.what() << endl);
  }

}