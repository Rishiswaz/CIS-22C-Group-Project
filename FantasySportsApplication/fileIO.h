#pragma once

#include "Team\Team.h"
#include <fstream>
#include <istream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void readDataInput();
void Output();

void readDataInput(string inputFileName, vector<Team>& teams)
{
int inWins, inLosses, inYards, inDivision;
string inTeamName;
Team dummy;
//Team inTeam;
char separator;
double inPercent;
ifstream myfile;
myfile.open(inputFileName);

if (myfile.good())
{
	for (int i = 0; i <= 31; i++)
	{
		myfile >> inWins >> separator >> inLosses >> separator >> inYards >> separator >> inPercent >> separator >> inDivision >> separator;
		std::getline(myfile, inTeamName);
		//cin.ignore('/n');
		dummy.input(inTeamName, inWins, inLosses, inYards, inPercent, inDivision);
		teams.push_back(dummy);
	};
}
else
{
	std::cout << "There was an error opening the file"<<std::endl;
}
myfile.close(); 
}

void Output(vector<Team> teams)
{
	ofstream outputFile;
	outputFile.open("Output.txt");

	if (outputFile.is_open())
	{
		cout << "File Opened successfully!. Writing data from array to file" << endl;

		for (int i = 0; i < 32; i++)
		{
			outputFile << teams[i]<<std::endl;
		}
		cout << "Team data successfully saved into the file Output.txt" << endl;
	}
	else 
		cout << "File could not be opened." << endl;

}


