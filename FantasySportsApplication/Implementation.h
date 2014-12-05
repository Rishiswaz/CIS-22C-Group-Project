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


void mainMenueImp(int choice, vector<Team> teams)
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
		editMenueImp(teams[intChoice], editMenu());
		break;
	case 2: 
		system("PAUSE");
		intChoice = displayTeams(teams);
		switch (intChoice)
		{

		default:
			break;
		}
		break;
	case 3:
		break;
	case 4:
		break;
	case 5: break;
	default:
		break;
	}
}


void implementation()
{
	HashTable<int, Team> hashTable(37);
	vector<Team> teams;
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
	readDataInput(inputFilePrompt(), teams);
	buildHash(teams, hashTable);
	mainMenueImp(mainMenu(), teams);
}

