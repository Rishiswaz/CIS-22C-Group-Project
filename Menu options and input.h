// PlayoffPictureGroupProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "targetver.h"
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;

const int teams = 32;

void playoffTeams();

bool menu(vector<PlayoffPicture>& teams);//error C2065: 'PlayoffPicture' : undeclared identifier

void getProjections(vector<PlayoffPicture>& teams);//error C2065: 'PlayoffPicture' : undeclared identifier

void whatIf();

bool printData();

int _tmain(int argc, _TCHAR* argv[])
{

	vector<PlayoffPicture>teams;//error C2065: 'PlayoffPicture' : undeclared identifier, error C2133: 'teams' : unknown size, error C2512: 'std::vector' : no appropriate default constructor available

	playoffTeams();

	while(menu(teams)){}

	system("pause");
	system("cls");

	return 0;
}

void playoffTeams()
{
	cout << "Press any key to continue to program" << endl;

	system("pause");
	system("cls");
}

bool menu(vector<PlayoffPicture>& teams)//error C2065: 'PlayoffPicture' : undeclared identifier
{

	bool flag = bool();
	char choice = char();

	cout << "Welcome to the Menu" << endl;
	cout << "" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;

	choice = getch();//error C3861: 'getch': identifier not found
	system("cls");

	switch (choice)
	{
	case '1':
	getProjections(teams)
	flag = true;//error C2146: syntax error : missing ';' before identifier 'flag'
	break;
	case'2':
	whatIf();
	flag=true;
	break;
	default:
	flag=true;
	cout << "Invalid Selection" << endl; 
	system("pause");
	system("cls");
	break;
	}// End Switch Statement

	return flag;
}

void getProjections(vector<PlayoffPicture>& teams)//error C2065: 'PlayoffPicture' : undeclared identifier
{
	teams list[32];//error C2146: syntax error : missing ';' before identifier 'list',   error C2065: 'list' : undeclared identifier
	int count;
	teams temp;//error C2146: syntax error : missing ';' before identifier 'temp',    error C2065: 'temp' : undeclared identifier
	ifstream infile; 

	cout << "Read Teams Data" << endl; 
	cout << "" << endl;
	cout << " ************************** " << endl; 
	cout << "" << endl;

	infile.open("Data.txt");

	if (infile.fail())
	{
		cout << "Data list not found" << endl;
		cout << "" << endl;

	}

	else 
	for(count=0; count < teams; count++)
	/***********
	All for above line ^
	error C2784: 'bool std::operator <(const std::vector<_Ty,_Ax> &,const std::vector<_Ty,_Ax> &)' : could not deduce template argument for 'const std::vector<_Ty,_Ax> &' from 'int'
	error C2784: 'bool std::operator <(const std::unique_ptr<_Ty,_Dx> &,const std::unique_ptr<_Ty2,_Dx2> &)' : could not deduce template argument for 'const std::unique_ptr<_Ty,_Dx> &' from 'int'
	error C2784: 'bool std::operator <(const std::basic_string<_Elem,_Traits,_Alloc> &,const _Elem *)' : could not deduce template argument for 'const std::basic_string<_Elem,_Traits,_Alloc> &' from 'int'
	error C2784: 'bool std::operator <(const _Elem *,const std::basic_string<_Elem,_Traits,_Alloc> &)' : could not deduce template argument for 'const _Elem *' from 'int'
	error C2784: 'bool std::operator <(const std::basic_string<_Elem,_Traits,_Alloc> &,const std::basic_string<_Elem,_Traits,_Alloc> &)' : could not deduce template argument for 'const std::basic_string<_Elem,_Traits,_Alloc> &' from 'int'
	error C2784: 'bool std::operator <(const std::reverse_iterator<_RanIt> &,const std::reverse_iterator<_RanIt2> &)' : could not deduce template argument for 'const std::reverse_iterator<_RanIt> &' from 'int'
	error C2784: 'bool std::operator <(const std::_Revranit<_RanIt,_Base> &,const std::_Revranit<_RanIt2,_Base2> &)' : could not deduce template argument for 'const std::_Revranit<_RanIt,_Base> &' from 'int'
	error C2784: 'bool std::operator <(const std::pair<_Ty1,_Ty2> &,const std::pair<_Ty1,_Ty2> &)' : could not deduce template argument for 'const std::pair<_Ty1,_Ty2> &' from 'int'
	error C2677: binary '<' : no global operator found which takes type 'std::vector' (or there is no acceptable conversion)
	**********/
	{
		infile>>temp.getFirst();// error C2065: 'temp' : undeclared identifier,    error C2228: left of '.getFirst' must have class/struct/union
	}

	system("pause");
	system("cls");

}

void whatIf()
{



}


void printData()
{
	// error C2556: 'void printData(void)' : overloaded function differs only by return type from 'bool printData(void)',     error C2371: 'printData' : redefinition; different basic types
	bool flag = bool();
	char choice = char();

	cout << "Type Number To Select" << endl;
	cout << "" << endl;

	cout << "1 Print Projections" << endl;
	cout << "2 What If?" << endl;

	choice=getch();.//error C3861: 'getch': identifier not found
	system("cls");

	switch(choice)
	{
	case '1':
	printProjections();//error C3861: 'printProjections': identifier not found
	flag=true;
	break;
	case'2':
	printwhatIf();//error C3861: 'printwhatIf': identifier not found
	flag=true;
	break;

	default:
	flag=true;
	cout << "Invalid Selection" << endl;
	system("pause");
	system("cls");
	break;
	}

	return flag;

}
