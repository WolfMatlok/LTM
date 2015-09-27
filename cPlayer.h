/* 
 * File:   cPlayer.h
 * Author: juia
 *
 * Created on 27. September 2015, 14:16
 */

#ifndef CPLAYER_H
#define	CPLAYER_H

class cPlayer
{
public:
  cPlayer(int p_iId);
  cPlayer(const cPlayer& orig);
  virtual ~cPlayer();
  
  bool CantPlayMoreGames(){return m_iGamesToPlay >= m_iGamesToPlayMax;}
  
  int GameRegister(){m_iGamesToPlay+=1; return m_iGamesToPlay;}
  int GameUnregister(){m_iGamesToPlay-=1; if(m_iGamesToPlay<0){m_iGamesToPlay=0;} return m_iGamesToPlay;}

private:
  int m_iId;
  int m_iGamesToPlay;
  static int m_iGamesToPlayMax;

};

#endif	/* CPLAYER_H */

