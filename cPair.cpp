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

cPair::cPair(cPlayerPtr p_poPlayerA, cPlayerPtr p_poPlayerB)
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
  if (m_poPlayerA->IsRegisteredOnRound(p_iRoundId))
  {
    return false;
  }

  if (m_poPlayerB->IsRegisteredOnRound(p_iRoundId))
  {
    return false;
  }

  return true;
}

void cPair::RegisterRound(int p_iRoundId)
{
  m_poPlayerA->RegisterRound(p_iRoundId);
  m_poPlayerB->RegisterRound(p_iRoundId);
}

void cPair::SetPoints(int p_iRoundId, int p_iPoints)
{
  if (m_poPlayerA->IsRegisteredOnRound(p_iRoundId))
  {
    m_poPlayerA->AddPoints(p_iRoundId, p_iPoints);
  }
  
  if (m_poPlayerB->IsRegisteredOnRound(p_iRoundId))
  {
    m_poPlayerB->AddPoints(p_iRoundId, p_iPoints);
  }
}

std::string cPair::GetResultsAsString(int p_iRoundId)
{
  return STREAMSTRING( m_poPlayerA->GetId() << "(" << m_poPlayerA->GetPoints(p_iRoundId) << "):" <<  m_poPlayerB->GetId() << "(" << m_poPlayerB->GetPoints(p_iRoundId) << ")" );
}


std::ostream& operator<<(std::ostream& os, const cPair& p_oPair)
{
  os << p_oPair.m_poPlayerA << ":" << p_oPair.m_poPlayerB;
  //os << p_oPair.GetResultsAsString(-1);
  return os;
}
