/* 
 * File:   cPlayerPool.h
 * Author: juia
 *
 * Created on 17. November 2015, 17:54
 */

#ifndef CPLAYERPOOL_H
#define	CPLAYERPOOL_H

#include "cPlayer.h"

typedef std::map<PlayerId, cPlayerPtr> CPLAYERMAP;

class cPlayerPool
{
public:
  cPlayerPool();
  cPlayerPool(const cPlayerPool& orig);
  virtual ~cPlayerPool();
  
  CPLAYERMAP& GetPlayers();
  cPlayerPtr CreatePlayer(int p_iId, int p_iIdGroup);
  static PlayerId MakePlayerId(int p_iId, int p_iIdGroup);
  
  void PrintPlayerStats();

  
private:
  friend class boost::serialization::access;

  template<class Archive>
  void serialize(Archive & p_oArchive, const unsigned int p_uiVersion)
  {
    p_oArchive & m_mapPlayerPool;
  }
  
  CPLAYERMAP m_mapPlayerPool; //every player is unique
};

#endif	/* CPLAYERPOOL_H */

