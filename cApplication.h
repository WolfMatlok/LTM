/* 
 * File:   cApplication.h
 * Author: juia
 *
 * Created on 19. September 2015, 14:30
 */

#ifndef CAPPLICATION_H
#define	CAPPLICATION_H

#include "cHelper.h"
#include "boost/program_options/variables_map.hpp"
#include "boost/program_options/options_description.hpp"
#include "boost/program_options/parsers.hpp"
#include "boost/program_options/cmdline.hpp"

namespace po = boost::program_options;

#define HELP "help"
#define COURTS "courts" //amount of courts to play on
#define TTP "ttp" //timt to play
#define TFG "tfg" //Time for one single game
#define TEAM1 "team1" //amount of gamers in team 1
#define TEAM2 "team2" //amout of gamers in team 2

class cApplication
{
public:
  cApplication(double p_dTimeToPlayH, int p_iCountOfCourts, double p_dTimeForOneGameMin, int p_iPlayerTeam1, int p_iPlayerTeam2);
  cApplication(int argc, char** argv);
  cApplication(const cApplication& orig);
  virtual ~cApplication();

  int GetPlayerTeam1()
  {
    return m_iPlayerTeam1;
  }

  int GetPlayerTeam2()
  {
    return m_iPlayerTeam2;
  }

  int GetTimeToPlay()
  {
    return m_dTimeToPlayH;
  }

  int GetTimeForOneGame()
  {
    return m_dTimeForOneGameMin;
  }

  int GetCountOfGamesToPlay()
  {
    return m_iCountOfGamesToPlay;
  }

  int GetCountOfCourts()
  {
    return m_iCountOfCourts;
  }

  int GetGamesPerPlayer() const
  {
    return m_iGamesPerPlayer;
  }

private:
  po::variables_map m_oVarMap;

  /** Zahl der Spieler*/
  int m_iPlayerTeam1;
  int m_iPlayerTeam2;

  /** Zeit fur das Turnier in Stunden
   */
  double m_dTimeToPlayH;

  /** Zeit fuer ein einziges Spiel
   */
  double m_dTimeForOneGameMin;

  /** Zahl der möglichen Spiele
   */
  int m_iCountOfGamesToPlay;

  /** Zahl bespielbaren Plätze
   */
  int m_iCountOfCourts;
  
  /** Zahld er Spiele die pro Spieler gemacht werden können
   */
  int m_iGamesPerPlayer;

  void Init();
};

#endif	/* CAPPLICATION_H */

