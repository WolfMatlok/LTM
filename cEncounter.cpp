/* 
 * File:   cGame.cpp
 * Author: wmk
 * 
 * Created on 25. September 2015, 09:48
 */

#include "cEncounter.h"

cEncounter::cEncounter(int p_iId, cPairPtr p_poPairA, cPairPtr p_poPairB)
{
  m_iId = p_iId;
  m_poPairA = p_poPairA;
  m_poPairB = p_poPairB;
}

void cEncounter::SetIdRound(int p_iIdRound)
{
  m_iIdRound = p_iIdRound;
}

int cEncounter::GetIdRound() const
{
  return m_iIdRound;
}

void cEncounter::SetIdCourt(int p_iIdCourt)
{
  m_iIdCourt = p_iIdCourt;
}

int cEncounter::GetIdCourt() const
{
  return m_iIdCourt;
}

cEncounter::cEncounter(const cEncounter& orig)
{
  m_iId = orig.m_iId;
  m_poPairA = orig.m_poPairA;
  m_poPairB = orig.m_poPairB;
  m_iIdCourt = orig.m_iIdCourt;
  m_iIdRound = orig.m_iIdRound;
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

void cEncounter::RegisterRoundForPairs(int p_iRoundId)
{
  m_poPairA->RegisterRound(p_iRoundId);
  m_poPairB->RegisterRound(p_iRoundId);
}