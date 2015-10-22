/* 
 * File:   cPair.cpp
 * Author: wmk
 * 
 * Created on 24. September 2015, 15:45
 */

#include "cPair.h"

cPair::cPair()
{
}

cPair::cPair(cPlayer::cPlayerPtr p_poPlayerA, cPlayer::cPlayerPtr p_poPlayerB)
{
  m_poPlayerA = p_poPlayerA;
  m_poPlayerB = p_poPlayerB;
}

cPair::cPair(const cPair& orig)
{
  m_poPlayerA = orig.m_poPlayerA;
  m_poPlayerB = orig.m_poPlayerB;
}

cPair::~cPair()
{
}

bool cPair::RegisterOnGamePossible(int p_iRoundId)
{
  if (!m_poPlayerA->CanPlayRound(p_iRoundId))
  {
    return false;
  }

  if (!m_poPlayerB->CanPlayRound(p_iRoundId))
  {
    return false;
  }

  return true;
}

void cPair::RegisterOnGame(int p_iRoundId)
{
  m_poPlayerA->GameRegister(p_iRoundId);
  m_poPlayerB->GameRegister(p_iRoundId);
}