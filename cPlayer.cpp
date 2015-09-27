/* 
 * File:   cPlayer.cpp
 * Author: juia
 * 
 * Created on 27. September 2015, 14:16
 */

#include "cPlayer.h"

int cPlayer::s_iGamesToPlayMax = 0;

cPlayer::cPlayer(int p_iId, int p_iGamesToPlay)
: m_iId(p_iId)
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

