#pragma once

#include "HashTable\HashTable.h"
#include "HashTable\HashTableEntry.h"
#include "HashTable\HashTableTest.h"
#include "LinkedList.h"
#include "Team\Team.h"
#include "BST_nT.h"
#include "fileIO.h"
#include "UX.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ostream>
#include <strstream>
#include <algorithm>
vector<Team> getDivTeams(vector<Team> teams, int inDiv, int& divScalar);
int exit(vector<Team> teams);
vector<Team> playoffBracket(vector<Team> teams);
vector<Team> buildPlayoffBracket(vector<Team> currConf);
void efficeincies(vector<Team> teams, HashTable<int, Team> hashTable);
int treeSelection();
void getWildCards(vector<Team>, vector<Team>&);
void buildTree(vector<Team> teams, CBinaryTree& tree);
void sortedOutputImp(int displayTeamsIn, vector<Team> teams, HashTable<int, Team> &hashTable);
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
	vector<Team> playoffTeams;
	char charInput=' ';
	int intChoice;
	if (choice == 0)
		choice = mainMenu();
	else if (choice == 7)
	{
		system ("CLS");
		std::cout << "Goodbye" << std::endl;
	}
	switch (choice)
	{
	case 1:
		for (int i = 0; i < 32; i++)
		{
			std::cout << i + 1 << ")  " << teams[i] << std::endl;
		};
		std::cout << "Please Enter The Team You Want to Edit"<<std::endl;
		std::cin >> intChoice;
		intChoice -= 1;
		editMenueImp(teams[intChoice], editMenu());
		mainMenueImp(0, teams, hashTable);
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
		system("CLS");
		sortedOutputImp(displayTeams(teams), teams, hashTable);
		system("PAUSE");
		mainMenueImp(0, teams, hashTable);
		break;
	case 4:
		playoffTeams = playoffBracket(teams);
		break;
	case 5:
		efficeincies(teams, hashTable);
		mainMenueImp(0, teams, hashTable);
		break;
	case 6:
		mainMenueImp(exit(teams), teams, hashTable);
			break;
	default:
		break;
		}
	}
void sortedOutputImp(int displayTeamsIn, vector<Team> teams, HashTable<int, Team> &hashTable)
{



	vector<Team> outPutVec;
	CBinaryTree tree;

	switch (displayTeamsIn)
	{
	case 0: mainMenueImp(0, teams, hashTable);
		break;
	case 1:
		switch (treeSelection())
		{
		case 0: mainMenueImp(0, teams, hashTable);
			break;
		case 1:  buildTree(teams, tree);
			tree.inorderTree(tree.root);
			break;
		default:
			break;
		}
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


void buildTree(vector<Team> teams, CBinaryTree& tree)
{
	for (int i = 0; i <= 31; i++)
	{
		tree.insertNode(teams[i].keyOutput('y'), teams[i]);
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

void efficeincies(vector<Team> teams, HashTable<int,Team> hashTable)
{
	system("CLS");
	std::cout << "There was a load factor of " << hashTable.getLoad() << " in this instance " << std::endl;
	std::cout << "Please note: due to the structure of the NFL and a set amount of teams the load factor will be 1 barring any errors in the amount of teams" << std::endl;
	system("PAUSE");
}

int exit(vector<Team> teams)
{
	char charInput;
	int retVal=7;
	std::cout << "Are You Sure You Want To Exit? [Y/n]" << std::endl;
	std::cin >> charInput;
	if (charInput == 'n' || charInput == 'N')
	{
		system("CLS");
		retVal = 0;;
	}
	 else if (charInput == 'y' || charInput != 'Y')
	{

		std::cout << "Do You Want To Output any changes to a text file? [Y/n]" << std::endl;
		std::cin >> charInput;
		if (charInput == 'y' || charInput == 'Y')
		{
			Output(teams);
		}
	} 
	 else
	 {
		 retVal = 6;
		 std::cout << "you entered an invalid input" << std::endl;
		 system("PAUSE");
	 }
	return retVal;
}

void reorderVec(vector<Team>& teams)
{
	Team temp = teams[0];
	int pos=0;

	for (int i = 0; i < teams.size(); i++) 
	{
		pos = i;
		for (int j = 1; j < teams.size(); j++) 
		{
			if (teams[j] < teams[pos])
				pos = j;
		}
		temp = teams[i];
		teams[i] = teams[pos];
		teams[pos] = temp;
		std::cout << i << "reorder counter" << std::endl;
	}

		
	
}


vector<Team> playoffBracket(vector<Team> teams)
{
	vector<Team> bracket;
	vector<Team> bracketAFC;
	vector<Team> bracketNFC;
	vector<Team> currDiv;
	vector<Team> currConf;
	vector<Team> temp= teams;
	
	int pos=0, divScalar = 0;
	reorderVec(temp);
	//GET NFC
	for (int i = 0; i <= 31; i++)
	{
		if (temp[i].getDivVal() == 1 || temp[i].getDivVal() == 2 || temp[i].getDivVal() == 3 || temp[i].getDivVal() == 4)
		{
			currConf.push_back(temp[i]);
		}
	}
		bracketNFC = buildPlayoffBracket(currConf);
	//get NFC wild cards
	getWildCards(currConf, bracketNFC);
	//reorderVec(bracketNFC);
	__noop;

	std::cout << bracketAFC.size() << std::endl;
	std::cout << bracketNFC.size() << std::endl;
	__noop;
	return bracket;
}

vector<Team> buildPlayoffBracket(vector<Team> currConf)
{
	vector<Team> temporary, currDiv, bracket;
	Team test;
	int divScalar;
	for (int i = 1; i <= 4; i++)
	{
		//NFC Playoff bracket no wildcard
		currDiv.clear();
		currDiv = getDivTeams(currConf, i, divScalar);
		for (int j = 0; j < currDiv.size(); j++)
		{
			currDiv[j].scaledPPI(divScalar);
			std::cout << currDiv[j] << " scaled current division" << std::endl;
		}

		test = *std::max_element(currDiv.begin(), currDiv.end());
		bracket.push_back(test);
		std::cout << " START PLAYOFF BRACKET" << std::endl;
		for (int j = 0; j < temporary.size(); j++)
		{
			std::cout << bracket[j] << "** Playoff Bracket **" << std::endl;
		}
	}
	return bracket;
}


vector<Team> getDivTeams(vector<Team> teams, int inDiv, int& divScalar)
{
	vector<Team> retVal;
	
	for (int i = 0; i <= 15; i++)
	{
		if (teams[i].getDivVal() == inDiv)
		{
			retVal.push_back(teams[i]);
		}

	}
	for (int k = 0; k <= 3; k++)
	{
		divScalar += retVal[k].keyOutput('p');
	}
	divScalar /= 4000;
	if (divScalar < 0)
		divScalar *= -1;
	return retVal;
}

void getWildCards(vector<Team> source, vector<Team>& destination)
{
	reorderVec(source);
	Team temp(source[1]);
	int cards = 0;
	for (int i = 0; i < source.size(); i++)
	{
		if (cards <= 2)
		{
			if (source[i] != destination[i])
			{
				temp = source[i];
				destination.push_back(temp);
				cards += 1;
			}
		}
	}
	destination.pop_back();
	for (int j = 0; j < destination.size(); j++)
	{
		std::cout << destination[j] << std::endl;
	}
}