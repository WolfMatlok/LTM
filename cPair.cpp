/* 
 * File:   cPair.cpp
 * Author: wmk
 * 
 * Created on 24. September 2015, 15:45
 */

#include "cPair.h"

cPair::cPair(int p_iPlayerA, int p_iPlayerB) : m_iInGamesInvolved(0)
{
  m_iPlayerA = p_iPlayerA;
  m_iPlayerB = p_iPlayerB;
}

cPair::cPair(const cPair& orig)
{
  m_iPlayerA = orig.m_iPlayerA;
  m_iPlayerB = orig.m_iPlayerB;
  m_iInGamesInvolved = orig.m_iInGamesInvolved;
}

cPair::~cPair()
{
}
