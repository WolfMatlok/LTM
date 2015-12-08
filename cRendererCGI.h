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

#define APPSTATE "appstate"
#define APPSTATE_NOTHING "appstate_nothing"
#define APPSTATE_START "appstate_start"
#define APPSTATE_CREATE_TOURNAMENT "appstate_create_tournament"
#define APPSTATE_SAVE_TOURNAMENT "appstate_save_tournament"
#define APPSTATE_LOAD_TOURNAMENT_FROM_ARCHIVE "appstate_load_tournament_from_archive"

#define APPUUID "appuuid"
#define APPFRAMESUSED "appframesused"
#define APPTOURNAMENTTOLOAD "apptournamenttoload"


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
  
  enum FormType
  {
    FRM_START, FRM_END
  };
  std::string Form(FormType p_eFrmTyp);

};

#endif	/* CRENDERERHTML_H */

