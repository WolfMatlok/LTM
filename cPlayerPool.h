/* 
 * File:   cPlayerPool.h
 * Author: juia
 *
 * Created on 17. November 2015, 17:54
 */

#ifndef CPLAYERPOOL_H
#define	CPLAYERPOOL_H

#include "cPlayer.h"

typedef std::map<PlayerId, CPLAYERPTR> CPLAYERMAP;

class cPlayerPool
{
public:
  cPlayerPool();
  cPlayerPool(const cPlayerPool& orig);
  virtual ~cPlayerPool();
  
  CPLAYERMAP& GetPlayers();
  CPLAYERPTR CreatePlayer(int p_iId, int p_iIdGroup);
  static PlayerId MakePlayerId(int p_iId, int p_iIdGroup);
  
  void PrintPlayerStats();

  
private:
  
  CPLAYERMAP m_mapPlayerPool; //every player is unique
};

#endif	/* CPLAYERPOOL_H */

