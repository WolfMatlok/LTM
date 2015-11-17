/* 
 * File:   cPair.h
 * Author: wmk
 *
 * Created on 24. September 2015, 15:45
 */

#ifndef CPAIR_H
#define	CPAIR_H

#include <iomanip>
#include <iostream>
#include <map>
#include <functional>
#include <boost/shared_ptr.hpp>
#include "cHelper.h"
#include "cPlayer.h"

enum PAIR_TYP{A,B};

class cPair
{
public:
  cPair();
  cPair(cPlayer::cPlayerPtr p_poPlayerA, cPlayer::cPlayerPtr p_poPlayerB);
  cPair(const cPair& orig);
  virtual ~cPair();

  bool RegisterOnGamePossible(int p_iRoundId);
  
  void RegisterRound(int p_iRoundId);

  bool operator==(const cPair& p_oLefthand)
  {
    if (m_poPlayerA == p_oLefthand.m_poPlayerA || m_poPlayerA == p_oLefthand.m_poPlayerB)
      return true;

    if (m_poPlayerB == p_oLefthand.m_poPlayerA || m_poPlayerB == p_oLefthand.m_poPlayerB)
      return true;

    return false;
  };

  friend std::ostream& operator<<(std::ostream& os, const cPair& p_oPair)
  {
    os << p_oPair.m_poPlayerA << ":" << p_oPair.m_poPlayerB;
    return os;
  }

private:
  friend class boost::serialization::access;

  template<class Archive>
  void serialize(Archive & p_oArchive, const unsigned int p_uiVersion)
  {
    p_oArchive & m_poPlayerA;
    p_oArchive & m_poPlayerB;
  }

  cPlayer::cPlayerPtr m_poPlayerA;
  cPlayer::cPlayerPtr m_poPlayerB;
};

typedef boost::shared_ptr<cPair> cPairPtr;
#define NEWPAIRPTR(CPAIRREFERENCE) [&](const cPair& p_oPair)->cPairPtr{return cPairPtr(new cPair(p_oPair));}(CPAIRREFERENCE)
typedef std::map<int, cPair> CPAIRMAP;

#endif	/* CPAIR_H */

