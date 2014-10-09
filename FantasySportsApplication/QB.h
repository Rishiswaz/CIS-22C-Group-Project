#ifndef __Project__QB__
#define __Project__QB__
#include <stdio.h>
#include "Player.h"
#include "NFLPlayers.h";

class QB : public Player
{
private:
   static const double PASSING_YARD_WEIGHT;
   static const double QB_RATING_WEIGHT;
   static const double YPC_WEIGHT;
   static const double TD_WEIGHT;
   static const double INT_WEIGHT;
private:
   int passingYards;
   double qbRating;
   double yardsPerCatch;
   int touchdowns;
   int interceptions;
public:
   QB();
   double getRating();
   //Eg QB Total Yards: X, QBR: 153.6
   string toString();
   //Should put QB as some constant somewhere
   string getPosition() { return "QB"; };
};

//Tweak this with some real values
const double QB::PASSING_YARD_WEIGHT = 1;
const double QB::QB_RATING_WEIGHT = 2;
const double QB::YPC_WEIGHT = 0.5;
const double QB::TD_WEIGHT = 0.7;
const double QB::INT_WEIGHT = 0.8;

double QB::getRating()
{
   //We can cache this after we do this once, or not. doubt it would be a
   //noticiable difference
   
   double rating;
   
   rating = passingYards * PASSING_YARD_WEIGHT;
   rating += qbRating * QB_RATING_WEIGHT;
   rating += yardsPerCatch * YPC_WEIGHT;
   rating += touchdowns * TD_WEIGHT;
   rating += interceptions * INT_WEIGHT;
   
   return rating;
}

string QB::toString()
{
   string output = Player::toString();
   
   output += "Passing yards: " + to_string(passingYards) + "\n";
   //etc.
   return output;
}

#endif /* defined(__Project__QB__) */
