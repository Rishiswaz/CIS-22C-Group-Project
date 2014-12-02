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

int inWins, inLosses, inYards, inPPI, inDivision;
string inTeamName;
Team dummy;
Team inTeam;
char separator;
ifstream myfile;
myfile.open(inputFileName);
while (myfile >> inTeamName >> separator >> inWins >> separator >> inLosses >> separator >> inYards >> separator >> inPPI >> inDivision)
{
	
	getline(myfile, teams, '\n');

	inTeam.input(inWins, inLosses, inYards, inPPI, inDivision);
	dummy.insertValues(inTeam, inTeamName);
	teams.push_back(dummy);
	teams [i].key = i + 1;

	i += 1;
};
myfile.close(); 
}

void Output()
{
	ofstream outputFile;
	outputFile.open("Output.txt");
	Team array[32];

	if (outputFile.is_open())
	{
		cout << "File Opened successfully!. Writing data from array to file" << endl;

		for (int i = 0; i < 32; i++)
		{
			outputFile << array[i];
		}
		cout << "Array data successfully saved into the file Output.txt" << endl;
	}
	else 
		cout << "File could not be opened." << endl;

}

