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
	std::string inputName = "data.csv";
	std::cout << "The default input file is data.csv, would you like to enter a different data file? [Y/n]"
		<< std::endl;
	std::cin >> charInput;
	if (charInput == 'y' || charInput == 'Y')
	{
		std::cout << "Please enter the datafile you would like to use."
			<< " Keep in mind that it must be a .csv file with the same format as the default input."
			<< std::endl;
		getline(cin, inputName);
	}
	else if (charInput != 'n' || charInput != 'N')
	{
		std::cout << "You Entered an invalid input, the default file name will be used" << std::endl;
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
		<< "5) Quit" << std::endl;
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
	if (charInput == 'y' || charInput == 'Y')
	{
		std::cout << "Please Select the sort order."<<std::endl;
		return 1;
	}
	else if (charInput != 'n' && charInput != 'N')
	{
		for (int i = 0; i <= 31;i++)
			std::cout<<teams[i];
		return 2;
	}
	std::cerr << "You Entered An Invalid Option" << std::endl;
	return 0;
	/*vector <Team> teams;
	std::string namestr= "Denver Broncos";
	Team dummy1(namestr, 9, 3, 4967, 0.75, 8);
	teams.push_back(dummy1);
	namestr = "Indianapolis Colts";
	Team dummy2(namestr,8, 4, 5259, 0.667, 7);
	teams.push_back(dummy2);
	namestr = "New England Patriots";
	Team dummy3(namestr, 9, 3, 4565, 0.75, 6);
	teams.push_back(dummy3);
	namestr = "Philadelphia Eagles";
	Team dummy4(namestr, 9, 3, 4994, 0.75, 2);
	teams.push_back(dummy4);
	namestr = "New Orleans Saints";
	Team dummy5(namestr, 5, 7, 5163, 0.417, 3);
	teams.push_back(dummy5);
	namestr = "Green Bay Packers";
	Team dummy6(namestr, 9, 3, 4535, 0.75, 1);
	teams.push_back(dummy6);
	namestr = "Pittsburgh Steelers";
	Team dummy7(namestr, 7, 5, 5008, 0.583, 5);
	teams.push_back(dummy7);
	namestr = "Baltimore Ravens";
	Team dummy8(namestr, 7, 5, 4447, 0.583, 5);
	teams.push_back(dummy8);
	namestr = "Miami Dolphins";
	Team dummy9(namestr, 7, 5, 4008, 0.583, 6);
	teams.push_back(dummy9);
	namestr = "Dallas Cowboys";
	Team dummy10(namestr, 8, 4, 4527, 0.667, 2);
	teams.push_back(dummy10);
	namestr = "Seattle Seahawks";
	Team dummy11(namestr, 8, 4, 4332, 0.667, 4);
	teams.push_back(dummy11);
	namestr = "Kansas City Chiefs";
	Team dummy12(namestr, 7, 5, 3744, 0.583, 8);
	teams.push_back(dummy12);
	namestr = "Cincinnati Bengals";
	Team dummy13(namestr, 8, 4, 4123, 0.667, 5);
	teams.push_back(dummy13);
	namestr = "Atlanta Falcons";
	Team dummy14(namestr, 5, 7, 4488, 0.417, 3);
	teams.push_back(dummy14);
	namestr = "Arizona Cardinals";
	Team dummy15(namestr, 9, 3, 3863, 0.75, 4);
	teams.push_back(dummy15);
	namestr = "Cleveland Browns";
	Team dummy16(namestr, 7, 5, 4351, 0.583, 5);
	teams.push_back(dummy16);
	namestr = "Houston Texans";
	Team dummy17(namestr, 6, 6, 4249, 0.5, 7);
	teams.push_back(dummy17);
	namestr = "San Diego Chargers";
	Team dummy18(namestr, 8, 4, 4154, 0.667, 8);
	teams.push_back(dummy18);
	namestr = "Chicago Bears";
	Team dummy19(namestr, 5, 7, 4081, 0.417, 1);
	teams.push_back(dummy19);
	namestr = "Buffalo Bills";
	Team dummy20(namestr, 7, 5, 3839, 0.583, 6);
	teams.push_back(dummy20);
	namestr = "New York Giants";
	Team dummy21(namestr, 3, 9, 4167, 0.25, 2);
	teams.push_back(dummy21);
	namestr = "Washington Redskins";
	Team dummy22(namestr, 3, 9, 4442, 0.25, 2);
	teams.push_back(dummy22);
	namestr = "San Francisco 49ers";
	Team dummy23(namestr, 7, 5, 3904, 0.583, 4);
	teams.push_back(dummy23);
	namestr = "Detroit Lions";
	Team dummy24(namestr, 8, 4, 4132, 0.667, 1);
	teams.push_back(dummy24);
	namestr = "Carolina Panthers";
	Team dummy25(namestr, 3, 7, 3947, 0.292, 3);
	teams.push_back(dummy25);
	namestr = "Tampa Bay Buccaneers";
	Team dummy26(namestr, 2, 9, 3763, 0.167, 3);
	teams.push_back(dummy26);
	namestr = "Minnesota Vikings";
	Team dummy27(namestr, 5, 7, 3609, 0.417, 1);
	teams.push_back(dummy27);
	namestr = "St Louis Rams";
	Team dummy28(namestr, 5, 7, 3794, 0.417, 4);
	teams.push_back(dummy28);
	namestr = "Tennessee Titans";
	Team dummy29(namestr, 2, 10, 3761, 0.167, 7);
	teams.push_back(dummy29);
	namestr = "New York Jets";
	Team dummy30(namestr, 2, 10, 3738, 0.167, 6);
	teams.push_back(dummy30);
	namestr = "Oakland Raiders";
	Team dummy31(namestr, 1, 11, 3359, 0.167, 8);
	teams.push_back(dummy31);
	namestr = "Jacksonville Jaguars";
	Team dummy32(namestr, 2, 10, 3603, 0.083, 7);
	teams.push_back(dummy32);

	for (int j = 0; j < teams.size(); j++)
	{
		teams[j].setRank();
		cout << teams[j];
	}
	*/
}