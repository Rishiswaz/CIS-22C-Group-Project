#pragma once

#include "HashTable\HashTable.h"
#include "HashTable\HashTableEntry.h"
#include "HashTable\HashTableTest.h"
#include "LinkedList.h"
#include "Team\Team.h"
#include "bst.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ostream>
#include <strstream>


/*
void runInput(std::string inputFileName, std::vector<Person>& people)
{
int inDay, inMonth, inYear,i=0;
Birthday inBday;
char separator;
std::string inName;
std::ifstream myfile;
myfile.open(inputFileName);
while (myfile.good())
{

myfile >> inDay;

myfile >> separator;

myfile >> inMonth;

myfile >> separator;

myfile >> inYear;

myfile >> separator;

std::getline(myfile, inName, '\n');
// Ignore the newline, as it is still in the buffer.
myfile.ignore(10000, '\n');
people[i].insertValues(inBday, inName);
i += 1;
}
myfile.close();
}
*/