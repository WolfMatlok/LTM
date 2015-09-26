/* 
 * File:   cGame.h
 * Author: wmk
 *
 * Created on 25. September 2015, 09:48
 */

#ifndef CGAME_H
#define	CGAME_H

class cPair;

class cGame {
public:
    cGame(int p_iGameId = -1);
    cGame(const cGame& orig);
    virtual ~cGame();
    
    int GetGameId(){return m_iGameId;}
    
private:
    int m_iGameId;
    cPair* m_poPair;
};

typedef std::map<int, cGame*> MAPGAMES;

#endif	/* CGAME_H */

