#pragma once

#include "HashTable\HashTable.h"
#include "HashTable\HashTableEntry.h"
#include "HashTable\HashTableTest.h"
#include "LinkedList.h"
#include "Team\Team.h"
#include "BST\binaryTree.h"
#include "fileIO.h"
#include "UX.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ostream>
#include <strstream>
void editMenueImp(Team& editTeam, int choice, vector<Team>& teams);
void addMenuImp(vector<Team>& teams, HashTable<int, Team> &hashTable);
void mainMenueImp(int choice, vector<Team>& teams);
void buildHash(vector<Team> teams, HashTable<int, Team> &hashTable)
{
	for (int i = 0; i < 32; i++)
	{
		hashTable.add(teams[i].keyOutput('y'), teams[i]);
	}
}
void editMenueImp(Team &editTeam, int choice, vector<Team>& teams)
{
	int intInput;
	char charInput;
	L1:
	std::cout << std::endl;
	std::cout << "Please Enter How Much you want to change the value" << std::endl;
	std::cin >> intInput;
	editTeam.changeVals(choice, intInput);
	std::cout << "Do You Want To Change Another Value? [Y/n]" << std::endl;
	std::cin >> charInput;
	if (charInput == 'y' || charInput == 'Y')
	{
		std::cout << "Which one?" << std::endl;
		std::cin >> intInput;
		choice = intInput;
		goto L1;
	
	}
	else if (charInput != 'n' && charInput != 'N')
	{
		std::cout << "You Entered an invalid input, we didn't get this far so nothing bad will happen" << std::endl;
	}
	mainMenueImp(mainMenu(), teams);
}
void addMenuImp(vector<Team>& teams, HashTable<int, Team> &hashTable)
{
	addMenu(teams);

	
}


void mainMenueImp(int choice, vector<Team>& teams)
{
	int intChoice;
	switch (choice)
	{
	case 1:
		for (int i = 0; i < 32; i++)
		{
			std::cout<< i+1 <<")  " << teams[i]<<std::endl;
		};
		std::cout << "Please Enter The Team You Want to Edit";
		std::cin >> intChoice;
		intChoice -= 1;
		editMenueImp(teams[intChoice], editMenu(),teams);
		break;
	case 2:
		addMenu(teams);
		break;
	case 3: displayTeams(teams);
		system("PAUSE");
		mainMenueImp(mainMenu(), teams);
		break;
	case 4:
		std::cout << setw(15) << "PLAYOFF CONTENDERS" << std::endl;
		std::cout << "*****************AFC*********************" << std::endl;
		std::cout << "New England Patriots from the AFC East" << std::endl
			<< "Denver Broncos from the AFC West" << std::endl
			<< "Cincinatti Bengals from the AFC North" << std::endl
			<< "Indianapolis Colts from the AFC South" << std::endl
			<< "San Diego Charger as the first wildcard seed" << std::endl
			<< "Miami Dolphins as the second wildcard seed" << std::endl;
		std::cout << "*****************NFC*********************" << std::endl;
		std::cout << "Philidelphia Eagles from the NFC East" << std::endl
			<< "Arizona Cardinals from the NFC West" << std::endl
			<< "Green Bay Packers from the NFC North" << std::endl
			<< "Carolina Panthers from the NFC South" << std::endl
			<< "Detroit Lions as the first wildcard seed" << std::endl
			<< "Tampa Bay Buccaneers as the second wildcard seed" << std::endl;
		system("Pause");
		mainMenueImp(mainMenu(), teams);
		break;
	case 5: break;
	default:
		break;
	}
}


void implementation(vector<Team> &teams)
{
	HashTable<int, Team> hashTable(37);
	char charInput;
	int intInput;
	
	//all the BSTs
	binarytree::CBinaryTree<int>	 yTree;
	binarytree::CBinaryTree<int>	 wTree;
	binarytree::CBinaryTree<int>	 lTree;
	binarytree::CBinaryTree<int>	 ppiTree;
	binarytree::CBinaryTree<int>	 nTree;
	//end BSTs

	std::string stringInput;
	
	landingPage();
	//readDataInput(inputFilePrompt(), teams);
	createTeams(teams);
	system("CLS");
	buildHash(teams, hashTable);
	mainMenueImp(mainMenu(), teams);
}
