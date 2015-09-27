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
  cGame(int p_iGameId = -1, cPairPtr p_poPairA = 0, cPairPtr p_poPairB = 0);
  cGame(const cGame& orig);
  virtual ~cGame();

  int GetGameId()
  {
    return m_iGameId;
  }

  cPairPtr GetPairB() const;
  cPairPtr GetPairA() const;

private:
  int m_iGameId;
  cPairPtr m_poPairA;
  cPairPtr m_poPairB;
};

typedef std::map<int, cGame> MAPGAME;

#endif	/* CGAME_H */

