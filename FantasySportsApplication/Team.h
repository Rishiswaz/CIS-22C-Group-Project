#ifndef __Project__Team__
#define __Project__Team__

#include <stdio.h>
#include "PlayerBucket.h"
#include "Position.h"

class Team
{
private:
   string teamName;
   PlayerBucket *playerBucket;
   vector<Player*> myTeam;
   
   //When we select a player for the person they can either accept or reject
   //During that limbo they are held here
   Player *playerOnDeck;
public:
   //Main should get a list of players, import it into the PlayerBucket
   //Vector of positions are the positions needed for this sport which should be created by the main?
   //Well not here at least
   Team(PlayerBucket *playerBucket, vector<Position> position);
   //Algorithim #3  -- requirement
   Player *draftPlayer();
   
   //After we pick a player, use can accept/reject a pick. Here we add a count to the position.
   void confirmPlayer(); //Add to team
   void rejectPlayer() { delete playerOnDeck; playerOnDeck = nullptr; } //Set to null, forget about that dude
   //Returns team
   string toString();
};

Player* Team::draftPlayer()
{
   //In case player is on deck and someone hit draft, throw him out.
   rejectPlayer();
   
   //Use some whacky alogrithim to figure out which position in the position vector
   //needs to be picked next.
   //Position has: numStarters eg. WR = 2 QB = 1
   //weight of position. eg Kicker 0.1 QB 10
   //current selection and max selection
   
   //First fill up all of the starters of the position with max weight
   //Then so forth until all starters are filled up
   //Then based on weight of position fill up 1 at a time until rosters spots maxed out
   
   return nullptr;
}

#endif /* defined(__Project__Team__) */
