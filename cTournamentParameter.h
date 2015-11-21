/* 
 * File:   cApplication.h
 * Author: juia
 *
 * Created on 19. September 2015, 14:30
 */

#ifndef CAPPLICATION_H
#define	CAPPLICATION_H

#include "cHelper.h"

#define HELP "help"
#define COURTS "courts" //amount of courts to play on
#define TTP "ttp" //time to play
#define TFG "tfg" //Time for one single game
#define TEAM1 "team1" //amount of gamers in team 1
#define TEAM2 "team2" //amout of gamers in team 2

class cTournamentParameter
{
public:
  cTournamentParameter(double p_dTimeToPlayH = 2, double p_dTimeForOneGameMin = 10, int p_iCountOfCourts = 4, int p_iPlayerTeam1 = 8, int p_iPlayerTeam2 = 8);
  cTournamentParameter(int argc, char** argv);
  cTournamentParameter(const cTournamentParameter& orig);
  virtual ~cTournamentParameter();

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
  friend class boost::serialization::access;

  template<class Archive>
  void serialize(Archive & p_oArchive, const unsigned int p_uiVersion)
  {
    p_oArchive & m_iPlayerTeam1;
    p_oArchive & m_iPlayerTeam2;
    p_oArchive & m_dTimeToPlayH;
    p_oArchive & m_dTimeForOneGameMin;
    p_oArchive & m_iCountOfGamesToPlay;
    p_oArchive & m_iCountOfCourts;
    p_oArchive & m_iGamesPerPlayer;
  }

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

