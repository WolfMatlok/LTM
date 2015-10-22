/* 
 * File:   cGame.cpp
 * Author: wmk
 * 
 * Created on 25. September 2015, 09:48
 */

#include "cEncounter.h"

cEncounter::cEncounter(int p_iGameId, cPairPtr p_poPairA, cPairPtr p_poPairB)
{
  m_iGameId = p_iGameId;
  m_poPairA = p_poPairA;
  m_poPairB = p_poPairB;
}

cEncounter::cEncounter(const cEncounter& orig)
{
  m_iGameId = orig.m_iGameId;
  m_poPairA = orig.m_poPairA;
  m_poPairB = orig.m_poPairB;
}

cEncounter::~cEncounter()
{
}

bool cEncounter::RegisterPlayerPossible(int p_iRoundId)
{
  if (!m_poPairA->RegisterOnGamePossible(p_iRoundId))
    return false;

  if (!m_poPairB->RegisterOnGamePossible(p_iRoundId))
    return false;

  return true;
}

void cEncounter::RegisterPlayer(int p_iRoundId)
{
  m_poPairA->RegisterOnGame(p_iRoundId);
  m_poPairB->RegisterOnGame(p_iRoundId);
}