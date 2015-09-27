/* 
 * File:   cPlayer.cpp
 * Author: juia
 * 
 * Created on 27. September 2015, 14:16
 */

#include "cPlayer.h"

int cPlayer::s_iGamesPerPlayer = 0;
cPlayer::CPLAYERMAP cPlayer::s_mapPlayerPool;

cPlayer::cPlayer(int p_iId, int p_iIdGroup, int p_iGamesToPlay)
: m_iId(p_iId)
, m_iIdGroup(p_iIdGroup)
, m_iGamesToPlay(p_iGamesToPlay)
{
}

cPlayer::cPlayer(const cPlayer& orig)
{
  m_iId = orig.m_iId;
  m_iGamesToPlay = orig.m_iGamesToPlay;
}

cPlayer::~cPlayer()
{
}

cPlayer::cPlayerPtr cPlayer::CreatePlayer(int p_iId, int p_iIdGroup)
{
  int iCurrPlayerId = MakePlayerId(p_iId, p_iIdGroup);
  if(s_mapPlayerPool.end() == s_mapPlayerPool.find(iCurrPlayerId))
  {
    cPlayerPtr poPlayer = cPlayerPtr(new cPlayer(p_iId, p_iIdGroup, 0));
    s_mapPlayerPool.insert(std::make_pair(poPlayer->GetId(), poPlayer));
    return poPlayer;
  }
  
  return s_mapPlayerPool[iCurrPlayerId];
}