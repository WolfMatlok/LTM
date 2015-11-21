/* 
 * File:   cPlayer.cpp
 * Author: juia
 * 
 * Created on 27. September 2015, 14:16
 */

#include "cPlayer.h"
#include "cPlayerPool.h"

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

bool cPlayer::IsRegisteredOnRound(int p_iRoundId)
{
  return m_oRegisteredRoundId.find(p_iRoundId)!=m_oRegisteredRoundId.end();
}

int cPlayer::RegisterRound(int p_iRoundId)
{
  m_oRegisteredRoundId.insert(std::make_pair(p_iRoundId, -1));
  m_iGamesToPlay = m_oRegisteredRoundId.size();
  return m_iGamesToPlay;
}

void cPlayer::AddPoints(int p_iRoundId, int p_iPoints)
{
  if(IsRegisteredOnRound(p_iRoundId))
    m_oRegisteredRoundId[p_iRoundId]+=p_iPoints;
}


PlayerId cPlayer::GetId() const
{
  return cPlayerPool::MakePlayerId(m_iId, m_iIdGroup);
}

bool cPlayer::operator==(const cPlayer& p_oLeftHand)
{
  return this->GetId() == p_oLeftHand.GetId();
}

bool cPlayer::operator==(const cPlayerPtr& p_poLeftHand)
{
  return this->GetId() == p_poLeftHand->GetId();
}
