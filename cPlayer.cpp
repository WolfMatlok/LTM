/* 
 * File:   cPlayer.cpp
 * Author: juia
 * 
 * Created on 27. September 2015, 14:16
 */

#include "cPlayer.h"

int cPlayer::s_iGamesPerPlayer = 0;
cPlayer::CPLAYERMAP cPlayer::s_mapPlayerPool;

cPlayer::CPLAYERMAP& cPlayer::GetPlayers()
{
  return cPlayer::s_mapPlayerPool;
}

cPlayer::cPlayerPtr cPlayer::CreatePlayer(int p_iId, int p_iIdGroup)
{
  int iCurrPlayerId = MakePlayerId(p_iId, p_iIdGroup);
  if (s_mapPlayerPool.end() == s_mapPlayerPool.find(iCurrPlayerId))
  {
    cPlayerPtr poPlayer = cPlayerPtr(new cPlayer(p_iId, p_iIdGroup, 0));
    s_mapPlayerPool.insert(std::make_pair(poPlayer->GetId(), poPlayer));
    return poPlayer;
  }

  return s_mapPlayerPool[iCurrPlayerId];
}

int cPlayer::MakePlayerId(int p_iId, int p_iIdGroup)
{
  return p_iId + p_iIdGroup;
}

void cPlayer::SetGamesPerPlayer(int p_iGamesPerPlayer)
{
  cPlayer::s_iGamesPerPlayer = p_iGamesPerPlayer;
}

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

bool cPlayer::CanPlayRound(int p_iRoundId)
{
  bool bCanPlay = std::find(m_oRegisteredRoundId.begin(), m_oRegisteredRoundId.end(), p_iRoundId) == m_oRegisteredRoundId.end(); /*&& (m_oRegisteredRoundId.size() < s_iGamesPerPlayer);*/
  return bCanPlay;
}

int cPlayer::GameRegister(int p_iRoundId)
{
  m_oRegisteredRoundId.push_back(p_iRoundId);
  m_iGamesToPlay = m_oRegisteredRoundId.size();
  return m_iGamesToPlay;
}

PlayerId cPlayer::GetId() const
{
  return cPlayer::MakePlayerId(m_iId, m_iIdGroup);
}