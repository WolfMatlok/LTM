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
  cTournament(cTournamentParameter* p_poTournamentParams = 0);
  cTournament(const cTournament& orig);
  virtual ~cTournament();

  void Create();
  
  MAPENCOUNTER& GetEncountersChoosen();

  virtual void accept(iRenderer* p_poRendrer);

  
  
private:
  void CreatePairs();
  void CreateEncounters();
  void SelectEncounters();
  
  friend class boost::serialization::access;

  template<class Archive>
  void serialize(Archive & p_oArchive, const unsigned int p_uiVersion)
  {
    p_oArchive & m_iNumOfGamesToPlay;
    p_oArchive & m_poParam;
    p_oArchive & m_mapEncountersAll;
    p_oArchive & m_mapEncountersChoosen;
    p_oArchive & m_oPlayerPool;
    p_oArchive & m_mapPairs;
    
  }
  
  int m_iNumOfGamesToPlay;
  cTournamentParameter* m_poParam;
  MAPENCOUNTER m_mapEncountersAll;
  MAPENCOUNTER m_mapEncountersChoosen;

  cPlayerPool m_oPlayerPool;
  
  /** pool of all possible pairs
   */
  CPAIRMAP m_mapPairs;
};

#endif	/* CROTATIONSTRATEGY_H */

