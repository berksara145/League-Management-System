//
// Created by PC on 8.12.2022.
//

#include "main.h"
#include "LeagueManagementSystem.h"

int main(){
    LeagueManagementSystem LMS;

    LMS.addTeam( "t1", 11 );
    LMS.addTeam( "t2", 12 );
    LMS.showAllTeams();
    cout << endl;
    LMS.removeTeam( "t2" );
    LMS.addPlayer( "t1", "p1", 1, 1 );
    LMS.addPlayer( "t1", "p2", 2, 2 );
    LMS.showTeam("t1");
    cout << endl;
    LMS.removePlayer("t1", "p2");
    LMS.showTeam("t1");
    return 0;
}