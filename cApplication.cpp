/* 
 * File:   cApplication.cpp
 * Author: juia
 * 
 * Created on 19. September 2015, 14:30
 */
#include "cApplication.h"
#include "cPlayer.h"

cApplication::cApplication(int argc, char** argv)
{
  // Declare the supported options.
  po::options_description oOptDesc("Allgemeiner Parameter");

  oOptDesc.add_options()
    (HELP, "produce help message")
    (TTP, po::value<double>(&m_dTimeToPlayH)->default_value(2), "time to play in hours")
    (COURTS, po::value<int>(&m_iCountOfCourts)->default_value(4), "amount of courts to play on")
    (TFG, po::value<double>(&m_dTimeForOneGameMin)->default_value(7), "time for one single game in min")
    (TEAM1, po::value<int>(&m_iPlayerTeam1)->default_value(8), "amount of gamers in team 1")
    (TEAM2, po::value<int>(&m_iPlayerTeam2)->default_value(8), "amount of gamers in team 2");

  po::store(po::parse_command_line(argc, argv, oOptDesc), m_oVarMap);
  po::notify(m_oVarMap);

  if (m_oVarMap.count(HELP))
  {
    std::cout << oOptDesc << "\n";
  }

  //*** calc amount of possible games ***
  m_iCountOfGamesToPlay = int(m_dTimeToPlayH * 60. * m_iCountOfCourts / m_dTimeForOneGameMin);

  //*** calc how often every player wants to play.. ***
  m_iGamesPerPlayer = double(double(m_iCountOfGamesToPlay)/double(m_iCountOfCourts));
  
  COUTSTRSTR("Group1 has " << this->GetPlayerTeam1() << " player." << endl);
  COUTSTRSTR("Group2 has " << this->GetPlayerTeam2() << " player." << endl);
  COUTSTRSTR("Time to play:" << this->GetTimeToPlay() << " hours." << endl);
  COUTSTRSTR("Time for one single game:" << this->GetTimeForOneGame() << " min." << endl);
  COUTSTRSTR("Sum of possible games to play:" << this->GetCountOfGamesToPlay() << endl);
  COUTSTRSTR("Amount of courts to play on:" << this->GetCountOfCourts() << endl);
  COUTSTRSTR("Games per player:" << this->GetGamesPerPlayer() << endl);

}

cApplication::cApplication(const cApplication& orig)
{
}

cApplication::~cApplication()
{
}

