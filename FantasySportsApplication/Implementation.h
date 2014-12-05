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
int treeSelection();
void sortedOutputImp(int,vector<Team>, HashTable<int,Team>);
void displayMenuImp(int passedVal)
{
	std::cout << "did something?" << std::endl;
};
void buildHash(vector<Team> teams, HashTable<int, Team> &hashTable)
{
	for (int i = 0; i < 32; i++)
	{
		hashTable.add(teams[i].keyOutput('y'), teams[i]);
	}
}
void editMenueImp(Team editTeam, int choice)
{
	int intInput;
	char charInput;
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
		editMenueImp(editTeam, intInput);
	}
	else if (charInput != 'n' && charInput != 'N')
	{
		std::cout << "You Entered an invalid input" << std::endl;

	}
}
void addMenuImp(vector<Team> teams, HashTable<int, Team> &hashTable)
{
	int intChoice;

	for (int i = 0; i < 32; i++)
	{
		std::cout << i + 1 << ")  " << teams[i] << std::endl;
	};
	std::cout << "Please Enter The Team You Want to Edit";
	std::cin >> intChoice;
	
}


void mainMenueImp(int choice, vector<Team> teams, HashTable<int, Team> hashTable)
{
	char charInput=' ';
	int intChoice;
	if (choice == 0)
		choice = mainMenu();
	switch (choice)
	{
	case 1:
		for (int i = 0; i < 32; i++)
		{
			std::cout << i + 1 << ")  " << teams[i] << std::endl;
		};
		std::cout << "Please Enter The Team You Want to Edit";
		std::cin >> intChoice;
		intChoice -= 1;
		editMenueImp(teams[intChoice], editMenu());
		break;
	case 2:
		system("PAUSE");
		
		switch (displayTeams(teams))
		{

		default:
			break;
		}
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		system("CLS");
		std::cout << "There was a load factor of " << hashTable.getLoad() << " in this instance " << std::endl;
		std::cout << "Please note: due to the structure of the NFL and a set amount of teams the load factor will be 1 barring any errors in the amount of teams" << std::endl;
		system("PAUSE");
		mainMenueImp(0, teams, hashTable);
		break;
	case 6:
		std::cout << "Are You Sure You Want To Exit?" << std::endl;
		std::cin >> charInput;
		if (charInput != 'n' || charInput != 'N')
		{
			std::cout << "Do You Want To Output any changes to a text file? [Y/n]" << std::endl;
			std::cin >> charInput;
			if (charInput == 'y' || charInput == 'Y')
			{
				Output(teams);
			}
		}
		std::cout << "Goodbye";
		system("PAUSE");
			break;
	default:
		break;
		}
	}



void implementation()
{
	HashTable<int, Team> hashTable;
	vector<Team> teams;
	char charInput;
	int intInput;
	


	std::string stringInput;
	
	landingPage();

	readDataInput(inputFilePrompt(), teams);
	buildHash(teams, hashTable);
	mainMenueImp(mainMenu(), teams, hashTable);
}

void buildTree(vector<Team> teams, binarytree::CBinaryTree<int>& tree)
{
	for (int i = 0; i <= 31; i++)
	{

		tree.insertElement(teams[i].keyOutput('y'));
	};
}

int treeSelection()
{
	int selection;
	std::cout << "Please Select Which Value you would like to sort by" << std::endl;
	std::cout 
		<< "1)Yards" << std::endl 
		<< "2)Wins" << std::endl 
		<< "3)Losses" <<std::endl 
		<< "4)PPI" << std::endl 
		<< "5)Name" << std::endl;
	std::cin >> selection;
	return selection;
}

void sortedOutputImp(int displayTeamsIn,vector<Team>& teams, HashTable<int,Team> hashTable)
{

	//all the BSTs
	binarytree::CBinaryTree<int>	 yTree;
	binarytree::CBinaryTree<int>	 wTree;
	binarytree::CBinaryTree<int>	 lTree;
	binarytree::CBinaryTree<int>	 ppiTree;
	binarytree::CBinaryTree<int>	 nTree;
	//end BSTs
	vector<Team> outPutVec;


	switch (displayTeamsIn)
	{
	case 1:
		switch (treeSelection())
			{
		case 0: mainMenueImp(0, teams, hashTable);
			break;
		case 1:  buildTree(teams, yTree);
				
				break;
			default:
				break;
			}
	default:
		break;
	}
}