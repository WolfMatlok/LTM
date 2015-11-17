/* 
 * File:   cRotationStrategy.h
 * Author: juia
 *
 * Created on 20. September 2015, 15:13
 */

#ifndef CROTATIONSTRATEGY_H
#define	CROTATIONSTRATEGY_H

#include "cTournamentParameter.h"
#include "cEncounter.h"
#include "iRenderable.h"
#include "cPlayerPool.h"

/** Rotionstrategy based on matrices 
 */
class cTournament : public iRenderable
{
public:
  cTournament(cTournamentParameter* p_poApplication);
  cTournament(const cTournament& orig);
  virtual ~cTournament();

  void Create();
  
  MAPENCOUNTER& GetEncountersChoosen();

  virtual void accept(iRenderer* p_poRendrer);

  
  
private:
  int m_iNumOfGamesToPlay;
  cTournamentParameter* m_poParam;

  MAPENCOUNTER m_mapEncountersAll;
  MAPENCOUNTER m_mapEncountersChoosen;

  cPlayerPool m_oPlayerPool;
  
  /** pool of all possible pairs
   */
  CPAIRMAP m_mapPairs;

  void CreatePairs();
  void CreateEncounters();
  void SelectEncounters();
};

#endif	/* CROTATIONSTRATEGY_H */

