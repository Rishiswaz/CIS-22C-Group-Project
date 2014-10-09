#ifndef __Project__PlayerBucket__
#define __Project__PlayerBucket__

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

class PlayerBucket
{
private:
   vector<Player *> players;
public:
   PlayerBucket(vector<Player *> players);
   //"Algorithim" #2 -- requirement
   Player* draftPlayer(string position);
private:
   //Algorithim #1 -- requirement
   void sortPlayers();
};

PlayerBucket::PlayerBucket(vector<Player *> players)
{
   this->players = players;
   sortPlayers();
}

void PlayerBucket::sortPlayers()
{
   //Use some good sorting here using Player->getRating();
}

Player* PlayerBucket::draftPlayer(string position)
{
   //Find the first player of that position in the vector, remove it from the vector
   //then return it, since it's already sorted by rating
   //Using player->getPosition();
   return nullptr;
}

#endif /* defined(__Project__PlayerBucket__) */
