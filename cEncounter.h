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
  cEncounter(int p_iGameId = -1, cPairPtr p_poPairA = cPairPtr(), cPairPtr p_poPairB = cPairPtr());
  cEncounter(const cEncounter& orig);
  virtual ~cEncounter();

  bool RegisterPlayerPossible(int p_iRoundId);
  void RegisterPlayer(int p_iRoundId);

  std::string toString()
  {
    return STREAMSTRING("GAMEID:" << std::setw(5) << m_iGameId << " " << m_poPairA->toString() << "vs" << m_poPairB->toString());
  }

  int GetGameId()
  {
    return m_iGameId;
  }

  friend std::ostream& operator<<(std::ostream& os, const cEncounter& p_oPair)
  {
    os << "GAMEID:" << std::setw(5) << p_oPair.m_iGameId << " " << *(p_oPair.m_poPairA) << "vs" << *(p_oPair.m_poPairB);
    return os;
  }

private:
  int m_iGameId;
  cPairPtr m_poPairA;
  cPairPtr m_poPairB;
};

typedef std::map<int, cEncounter> MAPGAME;

#endif	/* CGAME_H */

