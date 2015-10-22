/* 
 * File:   cRotationStrategy.h
 * Author: juia
 *
 * Created on 20. September 2015, 15:13
 */

#ifndef CROTATIONSTRATEGY_H
#define	CROTATIONSTRATEGY_H

#include "cApplication.h"
#include "cGame.h"

/** Rotionstrategy based on matrices 
 */
class cRotationStrategy
{
public:
  cRotationStrategy(cApplication* p_poApplication);
  cRotationStrategy(const cRotationStrategy& orig);
  virtual ~cRotationStrategy();

  void CreateGame();

private:
  int iNumOfGamesToPlay;
  cApplication* m_poApplication;

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

