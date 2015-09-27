/* 
 * File:   cGame.cpp
 * Author: wmk
 * 
 * Created on 25. September 2015, 09:48
 */

#include "cGame.h"

cGame::cGame(int p_iGameId, cPairPtr p_poPairA, cPairPtr p_poPairB)
{
  m_iGameId = p_iGameId;
  m_poPairA = p_poPairA;
  m_poPairB = p_poPairB;
}

cGame::cGame(const cGame& orig)
{
  m_iGameId = orig.m_iGameId;
  m_poPairA = orig.m_poPairA;
  m_poPairB = orig.m_poPairB;
}

cGame::~cGame()
{
}
