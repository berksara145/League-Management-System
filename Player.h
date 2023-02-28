/* Name:Berk Sara
 * Section = 02
 * StudentNumber = 22102354
 * */

#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
using namespace std;
class Player{
public:
    Player(std::string aname, int salary, int jersey);
    Player();
    ~Player();

    string getName();
    int getSalary();
    int getJersey();

private:
    string name;
    int jersey;
    int salary;

    void setName(string name);
    void setJersey(int jersey);
    void setSalary(int salary);


};

#endif // _PLAYER_H
