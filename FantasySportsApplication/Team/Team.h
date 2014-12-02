#pragma once


#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

class Team
{
public:
	Team();
	~Team();
	//Forward declared these two functions here, placeholder until we get everything together
	//read and update should be handled by fileIO
	void readData(); 
	void updateData(Team changedTeam, int addRemove);
	//Rank manipulation
	void changeRecord(); //used for changing W/L record.
	void setRank(); //this will set the playoffIndexScore to position it on the Playoff Performance Index
					//use this after changing any values or updating any data
	//V-overloaded = operator defined inline (rhs: Right Hand Side)-V
	Team & operator=(const Team & rhs) 
	{
//LHS (destination)    =     RHS (source)
		wins = rhs.wins;
		losses = rhs.yards;
		yards = rhs.yards;
		percentage=rhs.percentage;
		PPI = rhs.PPI;
		division = rhs.division;
		percentage = rhs.percentage;
		teamName = rhs.teamName;
	};
private:
	//explanation for values will be added in a txt file (ie:frDownPerGame: First Downs Per Game)
	int wins, losses, yards, PPI, division;
	double percentage;
	std::string teamName;
	bool inFilter; //bool flag to see if it is within bounds of the applied filters
};

Team::Team()
{
	//Input from file
	inFilter = true; //to make sure that if no query filters are applied that it still appears in the list
}

Team::~Team()
{
}
