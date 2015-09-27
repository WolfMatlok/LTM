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

class cPair
{
public:
  cPair(int p_iPlayerA = 0, int p_iPlayerB = 0);
  cPair(const cPair& orig);
  virtual ~cPair();

  std::string toString()
  {
    COUTSTRSTR(m_iPlayerA << ":" << m_iPlayerB);
  };

  bool operator==(const cPair& p_oLefthand)
  {
    if (m_iPlayerA == p_oLefthand.m_iPlayerA || m_iPlayerA == p_oLefthand.m_iPlayerB)
      return true;

    if (m_iPlayerB == p_oLefthand.m_iPlayerA || m_iPlayerB == p_oLefthand.m_iPlayerB)
      return true;

    return false;
  };

  friend std::ostream& operator<<(std::ostream& os, const cPair& p_oPair)
  {
    os << p_oPair.m_iPlayerA << ":" << p_oPair.m_iPlayerB;
    return os;
  }

private:

  int m_iPlayerA;
  int m_iPlayerB;

  int m_iInGamesInvolved;

};

typedef boost::shared_ptr<cPair> cPairPtr;
#define NEWPAIRPTR(CPAIRREFERENCE) [&](const cPair& p_oPair)->cPairPtr{return cPairPtr(new cPair(p_oPair));}(CPAIRREFERENCE)
typedef std::map<int, cPair> CPAIRMAP;

#endif	/* CPAIR_H */

