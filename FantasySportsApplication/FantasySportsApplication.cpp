#include <iostream>
#include "HashTable/HashTableTest.h"
#include "Implementation.h"


int main(int argc, const char * argv []) {
	//testHashTable();
	//displayTeams();
	//implementation();
	vector<Team> teams;
	std::string fileName = "data.csv";
	readDataInput(fileName, teams);
	//std::cout << teams[0] << std::endl << teams[31];
	displayTeams(teams);
	system("PAUSE");
	return 0;

}
