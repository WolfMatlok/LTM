/* 
 * File:   cGame.h
 * Author: wmk
 *
 * Created on 25. September 2015, 09:48
 */

#ifndef CGAME_H
#define	CGAME_H

#include "cPair.h"
#include <map>

/** cEncounter save two pairs which fight against.
 */
class cEncounter
{
public:
  cEncounter(int p_iId = -1, cPairPtr p_poPairA = cPairPtr(), cPairPtr p_poPairB = cPairPtr());
  cEncounter(const cEncounter& orig);
  virtual ~cEncounter();

  bool RegisterPlayerPossible(int p_iRoundId);
  void RegisterRoundForPairs(int p_iRoundId);
  
  int GetId(){return m_iId;}  
  cPairPtr GetPairA(){return m_poPairA;}
  cPairPtr GetPairB(){return m_poPairB;}

  void SetIdRound(int p_iIdRound);
  int GetIdRound() const;
  void SetIdCourt(int p_iIdCourt);
  int GetIdCourt() const;  

  friend std::ostream& operator<<(std::ostream& os, const cEncounter& p_oPair)
  {
    os << "GAMEID:" << std::setw(5) << p_oPair.m_iId << " " << *(p_oPair.m_poPairA) << "vs" << *(p_oPair.m_poPairB);
    return os;
  }

private:
  friend class boost::serialization::access;

  template<class Archive>
  void serialize(Archive & p_oArchive, const unsigned int p_uiVersion)
  {
    p_oArchive & m_iId;
    p_oArchive & m_iIdCourt;
    p_oArchive & m_iIdRound;
    p_oArchive & m_poPairA;
    p_oArchive & m_poPairB;
  }
  
  int m_iId;
  int m_iIdCourt;
  int m_iIdRound;
  cPairPtr m_poPairA;
  cPairPtr m_poPairB;
};

typedef std::map<int, cEncounter> MAPENCOUNTER;

#endif	/* CGAME_H */

