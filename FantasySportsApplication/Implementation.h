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


void buildHash(vector<Team> teams, HashTable<int, Team> &hashTable)
{
	for (int i = 0; i < 32; i++)
	{
		hashTable.add(teams[i].keyOutput('y'), teams[i]);
	}
}
void mainMenueImp(int choice)
{
	switch (choice)
	{
	case 1:
		break;
	case 2:
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
	binarytree::CBinaryTree<char>	 nTree;
	binarytree::CBinaryTree<double>  pTree;
	//end BSTs

	std::string stringInput;
	
	landingPage();
	readDataInput(inputFilePrompt(), teams);
	buildHash(teams, hashTable);
	mainMenueImp(mainMenu());
}
