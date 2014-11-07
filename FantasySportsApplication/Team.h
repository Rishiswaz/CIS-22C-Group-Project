#ifndef TEAM_H
#define TEAM_H

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
	void updateData();
	//Rank manipulation
	void changeRecord(); //used for changing W/L record.
	void setRank();
	//V-overloaded = operator defined inline (rhs: Right Hand Side)-V
	Team & operator=(const Team & rhs) 
	{
//LHS (destination)    =     RHS (source)
		gamesPlayed    = rhs.gamesPlayed;
		thDownsMade    = rhs.thDownsMade;
		foDownsMade    = rhs.foDownsMade;
		penalties      = rhs.penalties;
		penYdsLost     = rhs.penYdsLost;
		rank           = rhs.rank;
		teamNumber     = rhs.teamNumber;
		pointsPerGame  = rhs.pointsPerGame;
		tYdsPerGame    = rhs.tYdsPerGame;
		pYdsPerGame    = rhs.pYdsPerGame;
		rYdsPerGame    = rhs.rYdsPerGame;
		frDownsPerGame = rhs.frDownsPerGame;
		tDownPrct      = rhs.tDownPrct;
		foDownPrct     = rhs.foDownPrct;
		timeOP         = rhs.timeOP;
		teamName       = rhs.teamName;
		inFilter       = rhs.inFilter;
	};
private:
	//explanation for values will be added in a txt file (ie:frDownPerGame: First Downs Per Game)
	int gamesPlayed, thDownsMade, foDownsMade, penalties, penYdsLost, rank, teamNumber,position;
	float pointsPerGame, tYdsPerGame, pYdsPerGame,rYdsPerGame, frDownsPerGame, tDownPrct, foDownPrct;
	float timeOP; //Not sure how to store this because in the CSV it is stored in Hours:Min:Sec format
	std::string teamName;
	bool inFilter; //bool flag to see if it is within bounds of the applied filters
	int maxVectorSize, count, conference, division;
};

Team::Team()
{
	//Input from file
	inFilter = true; //to make sure that if no query filters are applied that it still appears in the list
}

Team::~Team()
{
}

/*
***************************NOTE**********************************
*																*
* Not sure where/how to implement these filters and because I	*
* don't want to work on a dead end too long I just put my		*
* class for it here and if we do use it I can put it into its	*
* own header and include the functions to pass to the user IO	*
* files.														*
*															  	*
*****************************************************************
*/
class DataFilter
{
	friend class Team;

public:
	DataFilter();
	~DataFilter();
	DataFilter(int chkVal, int inputMinVal, int inputMaxVal);
	void applyFilter(std::vector<Team> outputVector,const std::vector<Team> inputVector);
private:
	int valueChecked, minVal, maxVal;
	std::vector <Team> filteredTeamList;
};

DataFilter::DataFilter(int chkVal, int inputMinVal, int inputMaxVal)
{

	valueChecked = chkVal;
	minVal = inputMinVal;
	maxVal = inputMaxVal;

}

DataFilter::DataFilter()
{
}

DataFilter::~DataFilter()
{
}

void DataFilter::applyFilter(std::vector<Team> outputVector,const std::vector<Team> inputVector)
{
	//for filter assign values for total yards, passing yards, rushing yards, rank, conference, division
	//loop through all values on the input vector
	//do not use a literal for the loop max because to apply multiple filters it would be easier to use the size of the vector
}
#endif