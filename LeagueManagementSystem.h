/* Name:Berk Sara
 * Section = 02
 * StudentNumber = 22102354
 * */

#ifndef _LeagueManagementSystem_H
#define _LeagueManagementSystem_H

#include "Team.h"
#include <string>
#include <iostream>

class LeagueManagementSystem {
public:

    LeagueManagementSystem();
    ~LeagueManagementSystem();

    //should check if the name is unique creates the team
    void addTeam( const std::string name, const int year );
    //remove team if exist if not then display warning deletes team
    void removeTeam( const std::string name );
    //first checks if team exists if not then display warning
    void addPlayer( const std::string teamName, const std::string playerName,
                   const int jersey, const int salary );
    //check team exists
    void removePlayer( const std::string teamName, const std::string playerName );
    /*check teams exists first adds trys
    to add the player then removes it from the array
    */
    void transferPlayer( const std::string playerName,
    const std::string departTeamName, const std::string arriveTeamName );

    //teams name year numb of players and their total salary
    void showAllTeams() const;

    //name year all player info and total salary
    void showTeam( const std::string name ) const;

    //name jersey salary team also checks if player exists
    void showPlayer( const std::string name ) const;

private:
    int teamCount;
    Team* teams;

    bool checkIfTeamExists(std::string teamName) const;
};

#endif // _LeagueManagementSystem_H
