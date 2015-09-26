/* 
 * File:   cRotationStrategy.h
 * Author: juia
 *
 * Created on 20. September 2015, 15:13
 */

#ifndef CROTATIONSTRATEGY_H
#define	CROTATIONSTRATEGY_H

#include "cApplication.h"
#include "cPair.h"
#include <map>


/** Rotionstrategy based on matrices 
 */
class cRotationStrategy
{
public:
  cRotationStrategy(cApplication* p_poApplication);
  cRotationStrategy(const cRotationStrategy& orig);
  virtual ~cRotationStrategy();
  
  
private:
  cApplication* m_poApplication;
  
  std::map<int, std::string> m_mapGamesAll;
  std::map<int, std::string> m_mapGamesChoosen;
  CPAIRMAP m_mapPairs;

};

#endif	/* CROTATIONSTRATEGY_H */

