/* 
 * File:   cPlayer.h
 * Author: juia
 *
 * Created on 27. September 2015, 14:16
 */

#ifndef CPLAYER_H
#define	CPLAYER_H

#include <iostream>

class cPlayer
{
public:
  cPlayer(int p_iId, int p_iGamesToPlay = 0);
  cPlayer(const cPlayer& orig);
  virtual ~cPlayer();
  
  bool CanPlayMoreGames(){return m_iGamesToPlay < s_iGamesToPlayMax;}  
  int GameRegister(){m_iGamesToPlay+=1; return m_iGamesToPlay;}
  int GameUnregister(){m_iGamesToPlay-=1; if(m_iGamesToPlay<0){m_iGamesToPlay=0;} return m_iGamesToPlay;}
  static void SetGamesToPlay(int p_iGamesToPlay){cPlayer::s_iGamesToPlayMax = p_iGamesToPlay;}
  
  friend std::ostream& operator<<(std::ostream& os, const cPlayer& p_oPlayer)
  {
    //os << "ID:" << std::setw(5) << p_oPlayer.m_iId << " GamesToPlay:" << std::setw(2) << p_oPlayer.m_iGamesToPlay; 
    os << std::setw(5) << p_oPlayer.m_iId;
    return os;
  }
  
private:
  int m_iId;
  int m_iGamesToPlay;
  static int s_iGamesToPlayMax;
};

#endif	/* CPLAYER_H */

