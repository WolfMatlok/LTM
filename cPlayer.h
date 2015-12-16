/* 
 * File:   cPlayer.h
 * Author: juia
 *
 * Created on 27. September 2015, 14:16
 */

#ifndef CPLAYER_H
#define	CPLAYER_H

#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <boost/shared_ptr.hpp>

#include "cHelper.h"
#include "cTournamentParameter.h"

typedef int PlayerId;

class cPlayer;
typedef boost::shared_ptr<cPlayer> cPlayerPtr;

class cPlayer
{
public:
  cPlayer(int p_iId = -1, int p_iIdGroup = -1, int p_iGamesToPlay = 0);
  cPlayer(const cPlayer& orig);
  virtual ~cPlayer();

  PlayerId GetId() const;
  
  bool IsRegisteredOnRound(int p_iRoundId);
  
  int RegisterRound(int p_iRoundId);
  
  void AddPoints(int p_iRoundId, int p_iPoints);
  
  /**
   * @param p_iRoundId pass -1 to get the sum of all registered rounds of the player...
   */
  int GetPoints(int p_iRoundId);
  

  bool operator==(const cPlayer& p_oLeftHand);

  bool operator==(const cPlayerPtr& p_poLeftHand);

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

private:
  friend class boost::serialization::access;

  template<class Archive>
  void serialize(Archive & p_oArchive, const unsigned int p_uiVersion)
  {
    p_oArchive & m_iIdGroup;
    p_oArchive & m_iId;
    p_oArchive & m_iGamesToPlay;
    p_oArchive & m_oRegisteredRoundId;
  }
  
  int m_iIdGroup;
  int m_iId;
  int m_iGamesToPlay;
  
  /** key --> roundid
   * values --> points played in this round
   */
  std::map<int, int> m_oRegisteredRoundId;
  
};

#define NEWPLAYERPTR(CPLAYERREFERENCE) [&](const cPlayer& p_oPlayer)->cPlayerPtr{return cPlayerPtr(new cPlayer(p_oPair));}(CPLAYERREFERENCE)

BOOST_SERIALIZATION_SHARED_PTR(cPlayer)


#endif	/* CPLAYER_H */

