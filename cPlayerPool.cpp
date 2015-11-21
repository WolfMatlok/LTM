/* 
 * File:   cPlayerPool.cpp
 * Author: juia
 * 
 * Created on 17. November 2015, 17:54
 */

#include "cPlayerPool.h"

cPlayerPool::cPlayerPool()
{
}

cPlayerPool::cPlayerPool(const cPlayerPool& orig)
{
}

cPlayerPool::~cPlayerPool()
{
}

CPLAYERMAP& cPlayerPool::GetPlayers()
{
  return cPlayerPool::m_mapPlayerPool;
}

cPlayerPtr cPlayerPool::CreatePlayer(int p_iId, int p_iIdGroup)
{
  int iCurrPlayerId = cPlayerPool::MakePlayerId(p_iId, p_iIdGroup);
  if (m_mapPlayerPool.end() == m_mapPlayerPool.find(iCurrPlayerId))
  {
    cPlayerPtr poPlayer = cPlayerPtr(new cPlayer(p_iId, p_iIdGroup, 0));
    m_mapPlayerPool.insert(std::make_pair(poPlayer->GetId(), poPlayer));
    return poPlayer;
  }

  return m_mapPlayerPool[iCurrPlayerId];
}

int cPlayerPool::MakePlayerId(int p_iId, int p_iIdGroup)
{
  return p_iId + p_iIdGroup;
}

void cPlayerPool::PrintPlayerStats()
{
  //*** print player stats ***  
  LOGSTRSTR("*** Player stats ***" << endl);
  
  for (CPLAYERMAP::iterator oItPlayerCurr = m_mapPlayerPool.begin(); oItPlayerCurr != m_mapPlayerPool.end(); oItPlayerCurr++)
  {
    cPlayerPtr poPlayer = oItPlayerCurr->second;
    LOGSTRSTR(poPlayer << endl);
  }
}
