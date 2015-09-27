/* 
 * File:   cRotationStrategy.cpp
 * Author: juia
 * 
 * Created on 20. September 2015, 15:13
 */

#include "cRotationStrategy.h"
#include "cGame.h"
#include "cPlayer.h"
#include <iomanip>
#include <map>
#include <random>
#include <ctime>

cRotationStrategy::cRotationStrategy(cApplication* p_poApplication)
: m_poApplication(p_poApplication)
{

  int iNumOfPairs = 0;
  int iNumOfGames = 0;
  int iNumOfGamesToPlay = m_poApplication->GetCountOfGamesToPlay();
  int iGroupIdA = 100, iGroupIdB = 200;
  
  //*** search for all possible pais ***
  for (int iT1 = 0; iT1 < p_poApplication->GetPlayerTeam1(); iT1++)
  {    
    for (int iT2 = 0; iT2 < p_poApplication->GetPlayerTeam2(); iT2++)
    {
      cPair oPair(cPlayer::CreatePlayer(iT1, iGroupIdA), cPlayer::CreatePlayer(iT2, iGroupIdB));
      m_mapPairs.insert(std::make_pair(iNumOfPairs, oPair));
      COUTSTRSTR(" " << m_mapPairs[iNumOfPairs] << std::flush);
      iNumOfPairs++;
    }

    COUTSTRSTR(endl);
  }

  COUTSTRSTR(iNumOfPairs << " pairs found!" << endl);

  //*** search for all possible games ***
  //COUTSTRSTR("Pairs to fight against:" << endl);
  for (int iPairIdA = 0, iPairIdMaxB = 0; iPairIdA < iNumOfPairs; iPairIdA++, iPairIdMaxB++)
  {
    //COUTSTRSTR("***" << endl);
    for (int iPairIdB = 0; iPairIdB < iPairIdMaxB; iPairIdB++)
    {

      //gleiche Paarungen entfernen...
      if (iPairIdA == iPairIdB)
        continue;

      //crosscheck: der selbe spieler kann nicht gegen sich selbst spielen!
      if (m_mapPairs[iPairIdA] == m_mapPairs[iPairIdB]) //sollte theoretsich nicht vorkommen...
        continue;

      //COUTSTRSTR(" " << oMapPairs[iPairIdA] << " vs " << oMapPairs[iPairIdBCurr]);
      cGame oNewGame(iNumOfGames, NEWPAIRPTR(m_mapPairs[iPairIdA]), NEWPAIRPTR(m_mapPairs[iPairIdB]));
      m_mapGamesAll.insert(std::make_pair(oNewGame.GetGameId(), oNewGame));
      iNumOfGames++;
    }

    //COUTSTRSTR(endl);
  }

  COUTSTRSTR("Maximal number of possible games: " << iNumOfGames << endl);

  //*** select randomly games that are possible within the given time ***
  COUTSTRSTR("Going to choose " << iNumOfGamesToPlay << " games randomly" << endl);
  std::default_random_engine oGenerator(time(0));
  std::uniform_int_distribution<int> oDistribution(0, iNumOfGames);
  int iNumOfGameCurr = 0;
  int iCourtId = 0;
  int iNumOfRound = 0;
  cPlayer::SetGamesPerPlayer(m_poApplication->GetGamesPerPlayer());
  while (m_mapGamesChoosen.size() < iNumOfGamesToPlay)
  {
    int iCurrgameID = oDistribution(oGenerator); // generates number in the range 0 .. iNumOfGames
    
    cGame oGameCurr = m_mapGamesAll[iCurrgameID];
    if(!oGameCurr.RegisterPlayerPossible()) //try to register all involved player if possible
      continue;//on of the involved player exceeds the maximum possible amount of games he can play

    //was choosen gameid already choosen
    if (m_mapGamesChoosen.end() == m_mapGamesChoosen.find(iCurrgameID))
    {
      oGameCurr.RegisterPlayer();
      m_mapGamesChoosen.insert(std::make_pair(iNumOfGameCurr, oGameCurr));
      COUTSTRSTR("#" << std::setw(2) << iNumOfGameCurr
        << " " << oGameCurr
        << " Round:" << ((iCourtId % m_poApplication->GetCountOfCourts()) == 0 ? ++iNumOfRound : iNumOfRound)
        << " CourtId:" << std::setw(0) << (iCourtId++ % m_poApplication->GetCountOfCourts()) << endl);
      iNumOfGameCurr++;
    }
  }

}

cRotationStrategy::cRotationStrategy(const cRotationStrategy& orig)
{
}

cRotationStrategy::~cRotationStrategy()
{
}

