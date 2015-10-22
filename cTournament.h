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
class cTournament
{
public:
  cTournament(cTournamentParameter* p_poApplication);
  cTournament(const cTournament& orig);
  virtual ~cTournament();

  void Create();

private:
  int iNumOfGamesToPlay;
  cTournamentParameter* m_poParam;

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

