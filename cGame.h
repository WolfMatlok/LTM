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

class cGame
{
public:
  cGame(int p_iGameId = -1, cPairPtr p_poPairA = cPairPtr(), cPairPtr p_poPairB = cPairPtr());
  cGame(const cGame& orig);
  virtual ~cGame();
  
  bool RegisterPlayerPossible(int p_iRoundId);
  void RegisterPlayer(int p_iRoundId);

  int GetGameId()
  {
    return m_iGameId;
  }
  
  friend std::ostream& operator<<(std::ostream& os, const cGame& p_oPair)
  {
    os << "GAMEID:" << std::setw(5) << p_oPair.m_iGameId << " " << *(p_oPair.m_poPairA) << "vs" << *(p_oPair.m_poPairB);
    return os;
  }

private:
  int m_iGameId;
  cPairPtr m_poPairA;
  cPairPtr m_poPairB;
};

typedef std::map<int, cGame> MAPGAME;

#endif	/* CGAME_H */

