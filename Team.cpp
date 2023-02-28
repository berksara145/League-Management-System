/* Name:Berk Sara
 * Section = 02
 * StudentNumber = 22102354
 * */

#include <string>
#include "Team.h"
#include "Player.h"
#include <iostream>
using namespace std;

Team::Team(string thename, int theyear){
    setName(thename);
    setYear(theyear);

    players = nullptr;
    playerCount = 0;
}

Team::Team(){
    setName("none");
    setYear(-1);

    players = nullptr;
    playerCount = 0;
}
/*
Player Team::getPlayer(std::string namee){

    if( !checkIfNameExists(namee) ){
        for(int i=0; i < playerCount; i++){
            if( players[i].getName() == namee){
                return players[i];
            }
        }
    }
}
 */
Team::~Team() {
    if( !(playerCount == 0) ){
        if(playerCount == 1){
            delete players;
        }
        else{
            delete [] players;
        }
    }
}
string Team::getName(){
    return name;
}

int Team::getYear(){
    return year;
}

int Team::getPlayerCount(){
    return playerCount;
}

void Team::setName(string teamName){
    this->name = teamName;
}
void Team::setYear(int year){
    this->year = year;
}

/*checks if jersey number already exists creates and adds
a new player  to the players
*/
bool Team::setPlayer(const string playerName,
                   const int jersey, const int salary){
    if( checkIfJerseyExists(jersey) ){
        return false;
    }

    if( players == nullptr){
        players = new Player(playerName, salary, jersey);
    }
    else{
        Player* newPlayers = new Player[playerCount + 1];
        Player* newPlayer = new Player(playerName, salary, jersey);
        newPlayers[playerCount] = *newPlayer;
        delete newPlayer;

        for(int i=0; i < playerCount; i++){
            newPlayers[i] = players[i];
        }
        if(playerCount == 1){
            delete players;
        }
        else{
            delete [] players;
        }
        players = newPlayers;
    }
    playerCount++;
    return true;
}
//should also checks if exists
bool Team::removePlayer(const string playerName){
    if( !checkIfNameExists(playerName) ){
        return false;
    }

    if(playerCount <= 0){
        return false;
    }
    else if(playerCount == 1){
        delete players;
    }
    else{
        Player* newPlayers = new Player[playerCount - 1];

        int count = 0;
        for(int i=0; i < playerCount; i++){
            if( !(players[i].getName() == playerName) ){
                newPlayers[count] = players[i];
                count++;
            }
        }

        delete [] players;
        players = newPlayers;
    }
    playerCount--;
    return true;
}
bool Team::checkIfJerseyExists(int jerseynumber){
    for(int i=0; i < playerCount; i++){
        if(players[i].getJersey() == jerseynumber){
            return true;
        }
    }
    return false;
}

bool Team::checkIfNameExists(string playerName){
    for(int i=0; i < playerCount; i++){
        if(players[i].getName() == playerName){
            return true;
        }
    }
    return false;
}

Team& Team::operator=(const Team & right) {
    if(&right != this){
        name = right.name;
        year = right.year;
        if(playerCount > 0){
            delete [] players;
        }
        playerCount = right.playerCount;
        if(playerCount > 0){
            players = new Player[playerCount];
        }
        else{
            players = nullptr;
        }
        for (int i = 0; i < playerCount; ++i) {
            players[i] = right.players[i];
        }
    }
    return *this;
}
