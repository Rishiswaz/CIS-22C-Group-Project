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
	std::string inputName = "Data.csv";
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