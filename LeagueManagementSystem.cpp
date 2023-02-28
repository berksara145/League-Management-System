/* Name:Berk Sara
 * Section = 02
 * StudentNumber = 22102354
 * */

#include <iostream>
#include <string>
#include "Team.h"
#include "LeagueManagementSystem.h"

using namespace std;

LeagueManagementSystem::LeagueManagementSystem(){
    teamCount = 0;
    teams = nullptr;
}
LeagueManagementSystem::~LeagueManagementSystem(){
    if(teams) {
        if (teamCount == 1) {
            delete teams;
        }
        else {
            delete[] teams;
        }
    }
}

    //should check if the name is unique creates the team
void LeagueManagementSystem::addTeam( const string name, const int year ){
    if( checkIfTeamExists(name) ){
        cout << "Cannot add team. Team " << name << " already exists." << endl;
        return;
    }
    if(teamCount <= 0){

        teams = new Team(name, year);
    }
    else{
        Team* newTeams = new Team[teamCount + 1];
        Team* newTeam = new Team(name, year);
        newTeams[teamCount] = *newTeam;
        delete newTeam;
        for(int i =0; i < teamCount; i++){
            newTeams[i] = teams[i];
        }
        if(teamCount == 1){
            delete teams;
        }
        else{
            delete [] teams;
        }
        teams = newTeams;
    }
    teamCount++;
    cout << "Added team " << name << endl;
}
    //remove team if exist if not then display warning deletes team
void LeagueManagementSystem::removeTeam( const string name ){
    if( !checkIfTeamExists(name) ){
        cout << "Cannot remove team. Team "<< name  <<" does not exist" << endl;
        return;
    }
    if( teamCount == 1){
        delete teams;
    }
    else{
        Team* newTeams = new Team[teamCount - 1];;

        int count =0;
        for(int i=0; i < teamCount; i++){
            if( !(teams[i].getName() == name) ){
                if(teamCount == 2){
                    delete [] newTeams;
                    newTeams = new Team(teams[i].getName(), teams[i].getYear());
                }
                else{
                    newTeams[count] = teams[i];
                    count++;
                }
            }
        }
        delete [] teams;
        cout << "Removed team: " << name << endl;
        teams = newTeams;
    }
    teamCount--;
}
    //first checks if team exists if not then display warning
void LeagueManagementSystem::addPlayer( const string teamName, const string playerName,
                   const int jersey, const int salary ){
    if( !checkIfTeamExists(teamName) ){
        cout << "Cannot add player. Team " << teamName << " does not exist. " << endl;
        return;
    }
    for(int i=0; i < teamCount; i++){
        if(teams[i].getName() == teamName){
            if( teams[i].setPlayer(playerName, jersey,salary)) {
                cout << "Added player " << playerName <<" to team " <<  teamName << ". " << endl;
            }
            else{
                cout << "Cannot add player. Jersey number "<< jersey <<" already exists in team "<< teamName<<". "<< endl;
            }
        }
    }
}
    //check team exists
void LeagueManagementSystem::removePlayer( const string teamName, const string playerName ){
     if( !checkIfTeamExists(teamName) ){
        cout << "Cannot remove player. Team " <<teamName << " does not exist. " << endl;
        return;
    }
    for(int i=0; i < teamCount; i++){
        if(teams[i].getName() == teamName){
            if( !(teams[i].removePlayer(playerName)) ){
                cout << "Cannot remove player. Player "<<playerName<<" does not exist." << endl;
                return;
            }
        }
    }
    cout << "Removed player "<<playerName<<" from team "<<teamName<<"." << endl;
}
    /*check teams exists first adds trys
    to add the player then removes it from the array
    */
void LeagueManagementSystem::transferPlayer( const string playerName,
    const string departTeamName, const string arriveTeamName ){

    if( !(checkIfTeamExists(departTeamName)) ){
        cout << "Cannot transfer player. Team " << departTeamName << " does not exist." << endl;
        return;
    }

    if( !(checkIfTeamExists(arriveTeamName)) ){
        cout <<"Cannot transfer player. Team " << arriveTeamName << " does not exist." <<endl;
        return;
    }

    //first get player
    Player* Tplayer;
    for(int i=0; i<teamCount; i++){
        if(departTeamName == teams[i].getName()){
            if( teams[i].checkIfNameExists(playerName)){
                for(int j = 0; j < teams[i].getPlayerCount(); j++){
                    if(teams[i].players[j].getName() == playerName){
                        Tplayer = &(teams[i].players[j]);
                    }
                }
                //Tplayer = &(teams[i].getPlayer(playerName));
            }
            else{
                cout << "Cannot transfer player. Player "<< playerName <<" does not exist." << endl;
                return;
            }
        }
    }
    for(int i=0; i<teamCount; i++){
        if(arriveTeamName == teams[i].getName()){
            if( teams[i].checkIfJerseyExists( (*Tplayer).getJersey() )){
                cout << "Cannot transfer player. Jersey number "<< (*Tplayer).getJersey()
                << " already exists in team Fenerbahce" << endl;
                return;
            }
        }
    }
    cout <<"Transferred player "<< playerName<<" from team "<<departTeamName<<" to team "<<arriveTeamName<<"." << endl;
    //then add
    addPlayer(arriveTeamName, playerName, (*Tplayer).getJersey(), (*Tplayer).getSalary());


    //then remove
    removePlayer(departTeamName, playerName) ;
}

    //teams name year numb of players and their total salary
void LeagueManagementSystem::showAllTeams() const{
    cout << "Teams in the league management system:" << endl;
    for(int i=0; i<teamCount; i++){
        int salarySum = 0;

        for(int j=0; j< teams[i].getPlayerCount(); j++){
            salarySum += teams[i].players[j].getSalary();
        }
        cout << teams[i].getName() <<", "<< teams[i].getYear() << ", "<< teams[i].getPlayerCount()
        <<", "<< salarySum << " TL total salary" << endl;
    }
}

/*Team:
Fenerbahce, 1907, 3 players, 4000000 TL total salary
Players:
Melih Mahmutoglu, jersey 10, 2000000 TL salary
Sehmus Hazer, jersey 2, 1000000 TL salary
Metecan Birsen, jersey 1, 1000000 TL salary

*/
    //name year all player info and total salary
void LeagueManagementSystem::showTeam( const string name ) const{
    if( !(checkIfTeamExists(name))) {
        cout << "team " << name <<" doesnt exists" << endl;
        return;
    }

    Team* Tteam;
    int salarySum = 0;

    for(int i=0; i<teamCount; i++){
        if(teams[i].getName() == name){
              Tteam = &(teams[i]);
        }
    }

    for(int i=0; i<(*Tteam).getPlayerCount(); i++){
        salarySum += (*Tteam).players[i].getSalary();
    }
    cout << "Team: " << endl;
    cout << (*Tteam).getName() << ", " << (*Tteam).getYear() << ", "
    << (*Tteam).getPlayerCount() << ", " << salarySum << " TL total salary" << endl;
    cout << "Players:" << endl;
    for(int i=0; i<(*Tteam).getPlayerCount(); i++){
        cout << (*Tteam).players[i].getName() << ", " << "jersey " <<  (*Tteam).players[i].getJersey()
        << ", " << (*Tteam).players[i].getSalary() << "TL salary" << endl;
    }
}
/*Player:
Melih Mahmutoglu, jersey 10, 2000000 TL salary
Plays in team Fenerbahce.

*/

    //name jersey salary team also checks if player exists
void LeagueManagementSystem::showPlayer( const string name ) const{
    Team* Tteam = nullptr;
    Player* Tplayer = nullptr;

    for(int i=0; i<teamCount; i++){
        for(int j=0; j < teams[i].getPlayerCount(); j++){
            if(teams[i].players[j].getName() == name){
                Tteam = &(teams[i]);
                Tplayer = &(teams[i].players[j]);
            }
        }
    }
    if(!Tteam){
        cout << "Player " << name<< " does not exist." << endl;
        return;
    }

    cout << "Player:" << endl;
    cout << (*Tplayer).getName() << ", " << "jersey " <<  (*Tplayer).getJersey()
        << ", " << (*Tplayer).getSalary() << "TL salary" << endl;
    cout << "Plays in team " << (*Tteam).getName() << "." << endl;
}
bool LeagueManagementSystem::checkIfTeamExists(const string teamName) const{
    for(int i=0; i < teamCount; i++){
        if(teams[i].getName() == teamName){
            return true;
        }
    }
    return false;
}


