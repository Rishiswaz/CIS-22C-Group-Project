#pragma once


#include "Team\Team.h"
#include "BST\binaryTree.H"
#include "fileIO.h"
#include "HashTable\HashTable.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <strstream>
#include <ostream>
#include <istream>
#include <fstream>
#include <stdio.h>




std::string inputFilePrompt()
{
	system("CLS");
	char charInput;
	std::string inputName;
	std::string defaultName = "data.csv";
	std::cout << "The default input file is data.csv, would you like to enter a different data file? [Y/n]"
		<< std::endl;
	std::cin >> charInput;
	if (charInput == 'y' || charInput == 'Y')
	{
		std::cout << "Please enter the datafile you would like to use."
			<< " Keep in mind that it must be a .csv file with the same format as the default input."
			<< std::endl;
		cin.ignore();
		getline(cin, inputName);
		system("PAUSE");
	}
	else if (charInput != 'n' || charInput != 'N')
	{
		std::cout << "Moving on to program, default data file being used." << std::endl;
		system("PAUSE");
		return defaultName;
	}
	return inputName;
}

void landingPage()
{
	system("CLS");
	std::cout	<< "Welcome to the Perfect Playoff Predections" << std::endl
				<< std::endl
				<< "Brought to you by Team 2 (also known as The Best Team)"
				<< "Playoff brackets are our best apporximations, we can't read in account for heart...yet"
				<< std::endl;
	std::cin.get();
}

int mainMenu()
{
	int retVal;
	system("CLS");
	std::cout << std::setw(15) << "PPP Main Menu" << std::endl;
	std::cout
		<< "1) Edit Current Teams" << std::endl
		<< "2) Add or Remove a Team" << std::endl
		<< "3) Display Teams" << std::endl
		<< "4) Who Will Make The Playoffs?" << std::endl
		<< "5) Efficency" << std::endl
		<< "6) Quit" << std::endl;
	std::cin >> retVal;
	return retVal;
}

int editMenu()
{
	int retVal;
	system("CLS");
	std::cout	<< std::setw(15) << "Edit Current Teams" << std::endl;
	std::cout	<< "Please Select an operation to perform on the selected team" << std::endl;
	std::cout	<< "1) Add Yards" <<std::endl
				<< "2) Sub Yards"<<std::endl
				<< "3) Add Wins"<<std::endl
				<< "4) Sub Wins"<<std::endl
				<< "5) Add Losses"<<std::endl
				<< "6) Sub Losses"<<std::endl
				<< std::endl;
	std::cin >> retVal;
	return retVal;
	;
}
void addMenu()
{
	system("CLS");
	std::cout	<< std::setw(15) << "Add/Remove Team Menu" << std::endl;
	std::cout	<< "PLEASE NOTE: In Order To Keep NFL Playoff Structure intact if you add a team you MUST remove one"
				<< std::endl
				<< "Likewise You MUST Remove A Team Before You Can Add A New One"
				<< std::endl;
	std::cout << "Please Select a Team to Remove" << std::endl;
	std::cout << "Please select a Team to Add" << std::endl;
}

//BIG NOTE!!! PLEASE READ for this class please if you are not using C++14 put "-> int" after the input parameters
auto displayTeams(vector<Team>teams)
{
	//uses C++14 function definition, please read the comment above the function definition for proper C++11 syntax
	char charInput= ' ';
	std::cout << "Do you want to order the input? [Y/n]"
		<< std::endl;
	std::cin >> charInput;
	std::cout << std::endl;
	if (charInput == 'y' || charInput == 'Y')
	{
		return 1;
	}
	else if (charInput == 'n' || charInput == 'N')
	{
		for (int i = 0; i <= 31; i++)
		{
			std::cout << teams[i] << std::endl << std::endl;
			
		}
		system("PAUSE");
		return 0;
	}
	if (charInput!= 'y'&& charInput!='Y' && charInput!='n'&&charInput!='N')
	std::cerr << "You Entered An Invalid Option, you will be returned to the main menu" << std::endl;
	system("PAUSE");
	return 0;
	
}


void playoffDisplay(vector<Team> bracket)
{
	system("CLS");
	std::cout << setfill('*') << setw(100);
	std::cout << "******************************************************************************************" << std::endl;
	std::cout << "***          NFL                         PLAYOFFS                  2015                ***" << std::endl;
	std::cout << "******************************************************************************************" << std::endl;
	std::cout << "**                                                                                      **" << std::endl;
	std::cout << "**                                                                                      **" << std::endl;
	std::cout << "******************************************************************************************" << std::endl;
	std::cout << "**                                        NFC                                           **" << std::endl;
	std::cout << "******************************************************************************************" << std::endl;
	for (int i = 0; i <= 5; i++)
	{
		std::cout << "**" << bracket[i].playoffOutput(i+1).str() << "                                       **" << std::endl;
	}
}

