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
  cTournamentParameter* m_poApplication;

  MAPGAME m_mapGamesAll;
  MAPGAME m_mapGamesChoosen;

  /** pool of all possible pairs
   */
  CPAIRMAP m_mapPairs;

  void CreatePairs();
  void CreateGames();
  void SelectGames();
  void PrintPlayerStats();
};

#endif	/* CROTATIONSTRATEGY_H */

