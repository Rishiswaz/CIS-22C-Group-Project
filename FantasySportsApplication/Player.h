#ifndef __Project__Player__
#define __Project__Player__

#include <stdio.h>
#include <iostream>

using namespace std;

class Player
{
private:
   string firstName;
   string lastName;
   int jerseyNumber;
public:
   //Polymorphism brownie points here
   
   //Rating implemented on per-position basis
   virtual double getRating() = 0;
   //Eg QB Total Yards: X, QBR: 153.6
   virtual string toString();
   
   virtual string getPosition();
};

string Player::toString()
{
   return lastName + ", " + firstName + " #" + to_string(jerseyNumber) + "\n";
}

#endif /* defined(__Project__Player__) */
