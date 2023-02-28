/* Name:Berk Sara
 * Section = 02
 * StudentNumber = 22102354
 * */

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string aname, int salary, int jersey){
    setName(aname);
    setJersey(jersey);
    setSalary(salary);
}

Player::~Player(){

}

Player::Player(){
    setName("No name");
    setJersey(-1);
    setSalary(-1);
}

int Player::getJersey(){
    return jersey;
}


string Player::getName() {
    return name;
}

int Player::getSalary(){
    return salary;
}

void Player::setName(string Name){
    name = Name;
}

void Player::setSalary(int Salary){
    salary = Salary;
}

void Player::setJersey(int jersey){
    this->jersey = jersey;
}
