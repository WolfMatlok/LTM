/* 
 * File:   cPlayer.cpp
 * Author: juia
 * 
 * Created on 27. September 2015, 14:16
 */

#include "cPlayer.h"

cPlayer::cPlayer(int p_iId)
: m_iId(p_iId)
, m_iGamesToPlayMax(p_iGamesToPlayMax)
, m_iGamesToPlay(0)
{
}

cPlayer::cPlayer(const cPlayer& orig)
{
  m_iGamesToPlayMax = orig.m_iGamesToPlayMax;
  m_iId = orig.m_iId;
  m_iGamesToPlay = orig.m_iGamesToPlay;
}

cPlayer::~cPlayer()
{
}

