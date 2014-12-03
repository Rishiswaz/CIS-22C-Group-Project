#pragma once

#include "HashTable\HashTable.h"
#include "HashTable\HashTableEntry.h"
#include "HashTable\HashTableTest.h"
#include "LinkedList.h"
#include "Team\Team.h"
#include "BST\binaryTree.H"
#include "fileIO.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ostream>
#include <strstream>


void implementation()
{
	HashTable<int, Team> hashTable(37);
	vector<Team> teams;
	std::string inputName = "Data.csv";
	readDataInput(inputName, teams);
	for (int i = 0; i < 32; i++)
	{
		hashTable.add(1, teams[i]);
	}
}
