/* 
 * File:   cRotationStrategy.cpp
 * Author: juia
 * 
 * Created on 20. September 2015, 15:13
 */

#include "cTournament.h"
#include "cEncounter.h"
#include "cPlayer.h"
#include <iomanip>
#include <map>
#include <random>
#include <ctime>

cTournament::cTournament(cTournamentParameter* p_poApplication)
: m_poParam(p_poApplication)
{
  iNumOfGamesToPlay = m_poParam->GetCountOfGamesToPlay();
  cPlayer::SetGamesPerPlayer(m_poParam->GetGamesPerPlayer());
}

cTournament::cTournament(const cTournament & orig)
{
}

cTournament::~cTournament()
{
}

void cTournament::Create()
{
  CreatePairs();
  CreateEncounters();
  SelectEncounters();
}

MAPENCOUNTER& cTournament::GetEncountersChoosen()
{
  return m_mapEncountersChoosen;
}


void cTournament::accept(iRenderer* p_poRendrer)
{
  if (p_poRendrer)
    p_poRendrer->Render(this);
}



void cTournament::CreatePairs()
{
  int iGroupIdA = 100;
  int iGroupIdB = 200;
  int iNumOfPairs = 0;

  //*** search for all possible pais ***
  for (int iT1 = 0; iT1 < m_poParam->GetPlayerTeam1(); iT1++)
  {
    for (int iT2 = 0; iT2 < m_poParam->GetPlayerTeam2(); iT2++)
    {
      cPair oPair(cPlayer::CreatePlayer(iT1, iGroupIdA), cPlayer::CreatePlayer(iT2, iGroupIdB));
      m_mapPairs.insert(std::make_pair(iNumOfPairs, oPair));
      LOGSTRSTR(" " << m_mapPairs[iNumOfPairs] << std::flush);
      iNumOfPairs++;
    }

    LOGSTRSTR(endl);
  }

  LOGSTRSTR(iNumOfPairs << " pairs found!" << endl);
}

void cTournament::CreateEncounters()
{
  int iNumOfPairs = m_mapPairs.size();
  int iNumOfGames = 0;

  //*** search for all possible games ***
  for (int iPairIdA = 0, iPairIdMaxB = 0; iPairIdA < iNumOfPairs; iPairIdA++, iPairIdMaxB++)
  {
    for (int iPairIdB = 0; iPairIdB < iPairIdMaxB; iPairIdB++)
    {
      //gleiche Paarungen entfernen...
      if (iPairIdA == iPairIdB)
        continue;

      //crosscheck: der selbe spieler kann nicht gegen sich selbst spielen!
      if (m_mapPairs[iPairIdA] == m_mapPairs[iPairIdB]) //sollte theoretsich nicht vorkommen...
        continue;

      cEncounter oNewGame(iNumOfGames, NEWPAIRPTR(m_mapPairs[iPairIdA]), NEWPAIRPTR(m_mapPairs[iPairIdB]));
      m_mapEncountersAll.insert(std::make_pair(oNewGame.GetGameId(), oNewGame));
      iNumOfGames++;
    }
  }
}

void cTournament::SelectEncounters()
{
  int iNumOfGames = m_mapEncountersAll.size();

  //*** select randomly games that are possible within the given time ***
  LOGSTRSTR("Going to choose " << iNumOfGamesToPlay << " games randomly" << endl);
  std::default_random_engine oGenerator(time(0));
  std::uniform_int_distribution<int> oDistribution(0, iNumOfGames - 1);
  int iNumOfGameCurr = 0;
  int iCurrgameID = 0;
  int iCourtId = 0;
  int iRoundId = 0;
  int iGenerationTimeout = 10000;
  while (m_mapEncountersChoosen.size() < iNumOfGamesToPlay)
  {
    if (0 == iGenerationTimeout--)
    {
      iGenerationTimeout = 10000;
      iRoundId++;
      iCourtId = 0;
    }

    iCurrgameID = oDistribution(oGenerator); // generates number in the range 0 .. iNumOfGames
    if (m_mapEncountersChoosen.end() != m_mapEncountersChoosen.find(iCurrgameID))
    {
      continue;
    }

    cEncounter oGameCurr = m_mapEncountersAll[iCurrgameID];
    if (!oGameCurr.RegisterPlayerPossible(iRoundId)) //try to register all involved player if possible
      continue; //on of the involved player exceeds the maximum possible amount of games he can play

    //was choosen gameid already choosen
    oGameCurr.RegisterPlayerPossible(iRoundId);
    oGameCurr.RegisterPlayer(iRoundId);
    m_mapEncountersChoosen.insert(std::make_pair(iCurrgameID, oGameCurr));
    LOGSTRSTR("#" << std::setw(2) << iNumOfGameCurr
            << " " << oGameCurr
            << " Round:" << std::setw(2) << iRoundId
            << " CourtId:" << std::setw(0) << iCourtId++ << endl);
    iNumOfGameCurr++;
  }
}

void cTournament::PrintPlayerStats()
{
  //*** print player stats ***  
  LOGSTRSTR("*** Player stats ***" << endl);
  cPlayer::CPLAYERMAP& oPlayerMap = cPlayer::GetPlayers();
  for (cPlayer::CPLAYERMAP::iterator oItPlayerCurr = oPlayerMap.begin(); oItPlayerCurr != oPlayerMap.end(); oItPlayerCurr++)
  {
    cPlayer::cPlayerPtr poPlayer = oItPlayerCurr->second;
    LOGSTRSTR(poPlayer->toString() << endl);
  }
}
