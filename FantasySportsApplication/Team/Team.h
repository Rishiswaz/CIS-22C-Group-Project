#pragma once


#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

class Team
{
public:
	Team();
	Team(std::string, int, int, int, double, int);
	~Team();
	//to access private member yards for the key for the hash table
	int keyOutput()
	{
		return yards;
	}
	
	int keyOutput(char keyVal)
	{
		switch (keyVal)
		{
		case 'w':return wins;
			break;
		case 'l':return losses;
			break;
		case 'p':return PPI;
			break;
		case 'n':return getASCII();
			break;
		default:
			std::cout << "An error occured parsing your input, default key will be used" << std::endl;
			break;
		}
		return yards;
	};
	//to access private members or this class from fileIO
	void input(std::string t, int w, int l, int y, double p, int d)
	{
		wins = w;
		losses = l;
		yards = y;
		percentage = p;
		division = d;
		teamName = t;
		setRank();
	}
	std::string getDiv()
	{
		std::string returnValue;
		switch (division)
		{
		case 1: returnValue = "NFC North";
			break;
		case 2: returnValue = "NFC East";
			break;
		case 3: returnValue = "NFC South";
			break;
		case 4: returnValue = "NFC West";
			break;
		case 5: returnValue = "AFC North";
			break;
		case 6: returnValue = "AFC East";
			break;
		case 7: returnValue = "AFC South";
			break;
		case 8: returnValue = "AFC West";
			break;
		default: std::cerr << "There was an error reading the division"<<std::endl
			<<"Please make sure that the division value for "<<teamName<<" is valid.";
			break;
		}
		return returnValue;
	}
	//Rank manipulation
	void setRank()
	{
		double value;
		value = yards*percentage;
		trunc(value);
		PPI = value;
	}//this will set the playoffIndexScore to position it on the Playoff Performance Index
					//use this after changing any values or updating any data
	//V-overloaded = operator defined inline (rhs: Right Hand Side)-V
	Team & operator=(const Team& rhs) 
	{
//LHS (destination)    =     RHS (source)
		Team dummy;
		dummy.wins = rhs.wins;
		dummy.losses = rhs.yards;
		dummy.yards = rhs.yards;
		dummy.percentage = rhs.percentage;
		dummy.PPI = rhs.PPI;
		dummy.division = rhs.division;
		dummy.percentage = rhs.percentage;
		dummy.teamName = rhs.teamName;
		return dummy;
	};
	friend std::ostream& operator<<(std::ostream& os, Team& dt)
	{
		os << dt.teamName << " " << dt.wins << " Wins, " << dt.losses << " Losses, " << std::endl
			<< "In "<<dt.getDiv()<< " with a PPI of "<< dt.PPI<<std::endl<<std::endl;
		return os;
	}
	int getASCII()
	{
		stringASCII = 0;
		for (int i = 0; i < teamName.length(); i++)
		{
			stringASCII += int(teamName.at(i));
		}
		return stringASCII;
	}
	void changeVals(int choice, int val)
	{
		switch (choice)
		{
		case 1: yards += val;
			break;
		case 2: yards -= val;
			break;
		case 3: wins += val;
			break;
		case 4: wins -= val;
			break;
		case 5: losses += val;
			break;
		case 6: losses -= val;
			;
			break;
		default:
			break;
		};
	};
	void editStuff(int win, int loss, std::string name)
	{
		wins = win;
		losses = loss;
		teamName = name;
		percentage = win / loss;
		setRank();
	}
private:
	//explanation for values will be added in a txt file (ie:frDownPerGame: First Downs Per Game)
	int wins, losses, yards, PPI, division,stringASCII;
	double percentage;
	std::string teamName;
	
};

Team::Team(std::string name, int win, int loss, int yard, double percent, int div)
{
	teamName = name;
	wins = win;
	losses = loss;
	yards = yard;
	percentage = percent;
	division = div;
}
Team::Team()
{
	//Input from file
	
}

Team::~Team()
{
}
