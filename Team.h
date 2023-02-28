/* Name:Berk Sara
 * Section = 02
 * StudentNumber = 22102354
 * */

#ifndef _TEAM_H
#define _TEAM_H

#include <string>
#include "Player.h"

class Team{
public:
    Player* players;
    Team(std::string name, int year);
    Team();
    ~Team();

    Player getPlayer(std::string name);
    std::string getName();
    int getYear();
    int getPlayerCount();

    /*checks if jersey number already exists creates and adds
    a new player  to the players
    */
    bool setPlayer(const std::string playerName,
                   const int jersey, const int salary);
    //should also checks if exists
    bool removePlayer(const std::string playerName);
    bool checkIfJerseyExists(int jersey);
    bool checkIfNameExists(std::string);

    Team& operator=(const Team&);


private:
    int playerCount;
    std::string name;
    int year;

    void setName(std::string teamName);
    void setYear(int year);
};

#endif // _TEAM_H
