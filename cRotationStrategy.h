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

/** Rotionstrategy based on matrices 
 */
class cRotationStrategy
{
public:
  cRotationStrategy(cTournamentParameter* p_poApplication);
  cRotationStrategy(const cRotationStrategy& orig);
  virtual ~cRotationStrategy();

  void CreateGame();

private:
  int iNumOfGamesToPlay;
  cTournamentParameter* m_poTournParam;

  MAPENCOUNTER m_mapEncountersAll;
  MAPENCOUNTER m_mapEncountersChoosen;

  /** pool of all possible pairs
   */
  CPAIRMAP m_mapPairs;

  void CreatePairs();
  void CreateEncounters();
  void SelectEncounters();
  void PrintPlayerStats();
};

#endif	/* CROTATIONSTRATEGY_H */

