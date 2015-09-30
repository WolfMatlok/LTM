/* 
 * File:   cPlayer.h
 * Author: juia
 *
 * Created on 27. September 2015, 14:16
 */

#ifndef CPLAYER_H
#define	CPLAYER_H

#include <map>
#include <iostream>
#include <iomanip>
#include <boost/shared_ptr.hpp>

#include "cHelper.h"

typedef int PlayerId;
  

class cPlayer
{
public:
  typedef boost::shared_ptr<cPlayer> cPlayerPtr;
  typedef std::map<PlayerId, cPlayerPtr> CPLAYERMAP;

  cPlayer(int p_iId = -1, int p_iIdGroup = -1, int p_iGamesToPlay = 0);
  cPlayer(const cPlayer& orig);
  virtual ~cPlayer();
  
  static CPLAYERMAP& GetPlayers(){return cPlayer::s_mapPlayerPool;};
  static cPlayerPtr CreatePlayer(int p_iId, int p_iIdGroup);
  static PlayerId MakePlayerId(int p_iId, int p_iIdGroup){return p_iId+p_iIdGroup;};
  static void SetGamesPerPlayer(int p_iGamesPerPlayer){cPlayer::s_iGamesPerPlayer = p_iGamesPerPlayer;}
  
  PlayerId GetId() const {return cPlayer::MakePlayerId(m_iId, m_iIdGroup);};
  bool CanPlayMoreGames(){return m_iGamesToPlay < s_iGamesPerPlayer;}  
  int GameRegister(){m_iGamesToPlay+=1; return m_iGamesToPlay;}
  int GameUnregister(){m_iGamesToPlay-=1; if(m_iGamesToPlay<0){m_iGamesToPlay=0;} return m_iGamesToPlay;}
  
  bool operator==(const cPlayer& p_oLeftHand)
  {
    return this->GetId()==p_oLeftHand.GetId();
  }
  
  bool operator ==(const cPlayerPtr& p_poLeftHand)
  {
    return this->GetId()==p_poLeftHand->GetId();
  }
  
  friend std::ostream& operator<<(std::ostream& os, const cPlayer& p_oPlayer)
  {
    //os << "ID:" << std::setw(5) << p_oPlayer.m_iId << " GamesToPlay:" << std::setw(2) << p_oPlayer.m_iGamesToPlay; 
    os << std::setw(3) << p_oPlayer.GetId();
    return os;
  }
  
  friend std::ostream& operator<<(std::ostream& os, const cPlayerPtr& p_poPlayer)
  {
    //os << "ID:" << std::setw(5) << p_oPlayer.m_iId << " GamesToPlay:" << std::setw(2) << p_oPlayer.m_iGamesToPlay; 
    os << std::setw(3) << p_poPlayer->GetId();
    return os;
  }
  
  std::string toString()
  {
    return STREAMSTRING(std::setw(3) << GetId() << std::setw(2) << "("<<m_iGamesToPlay<<")");
  }
  
private:
  int m_iIdGroup;
  int m_iId;
  int m_iGamesToPlay;
  static int s_iGamesPerPlayer;
  static CPLAYERMAP s_mapPlayerPool; //every player is unique
};

#define NEWPLAYERPTR(CPLAYERREFERENCE) [&](const cPlayer& p_oPlayer)->cPlayerPtr{return cPlayerPtr(new cPlayer(p_oPair));}(CPLAYERREFERENCE)


#endif	/* CPLAYER_H */

