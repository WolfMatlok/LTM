/* 
 * File:   cRendererHtml.h
 * Author: juia
 *
 * Created on 22. Oktober 2015, 21:44
 */

#ifndef CRENDERERHTML_H
#define	CRENDERERHTML_H

#include "iRenderer.h"
#include "cCGIHelper.h"

#define APPCMD "appcmd"
#define APPCMD_NOTHING "appcmd_nothing"
#define APPCMD_START "appcmd_start"
#define APPCMD_CREATE_TOURNAMENT "appcmd_create_tournament"
#define APPCMD_SAVE_TOURNAMENT "appcmd_save_tournament"
#define APPCMD_LOAD_TOURNAMENT_FROM_ARCHIVE "appcmd_load_tournament_from_archive"

#define APP_PARAM_UUID "appuuid"
#define APPFRAMESUSED "appframesused"
#define APP_PARAM_TOURNAMENTTOLOAD "apptournamenttoload"
#define APP_PARAM_TOURNAMENTTOSAVE "apptournamenttosave"


class cRendererCGI : public iRenderer, public cCGIHelper
{
public:
  cRendererCGI(cgicc::Cgicc* p_poCGI);
  virtual ~cRendererCGI();
  
  void RenderStartScreen();

  virtual void Render(cTournament* p_poTournament);

private:
  void PrintCGIParams();
  
  void TableStart(int p_iCols);
  void TableEnd();
  
  void HTMLStart();
  void HTMLEnd();
  
  
  std::string SetParamHidden(std::string p_strParamName, std::string p_strParamValue);
  std::string SetParamNumber(std::string p_strName, std::string p_strMin, std::string p_strMax, std::string p_strValue);
  
  std::string SetButton(std::string p_strText);
  
  enum FormType
  {
    FRM_START, FRM_END
  };
  std::string Form(FormType p_eFrmTyp);

};

#endif	/* CRENDERERHTML_H */

