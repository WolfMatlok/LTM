/* 
 * File:   cRenderer.h
 * Author: juia
 *
 * Created on 22. Oktober 2015, 20:57
 */

#ifndef CRENDERER_H
#define	CRENDERER_H

class iRenderable;
class cPlayer;
class cRotationStrategy;
class cEncounter;
class cPair;
class cPlayer;
class cTournamentParameter;


class iRenderer
{
public:
  virtual void Render(iRenderable* p_oToRender) = 0;
  virtual void Render(cRotationStrategy* p_oRotStrat) = 0;
  virtual void Render(cEncounter* p_oGame) = 0;
  virtual void Render(cPair* p_oPair) = 0;
  virtual void Render(cPlayer* p_oPlayer) = 0;
  virtual void Render(cTournamentParameter* p_oApp) = 0;
private:

};

#endif	/* CRENDERER_H */

