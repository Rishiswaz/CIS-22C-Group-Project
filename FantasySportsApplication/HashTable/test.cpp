//
//  test.cpp
//  HashTable
//
//  Created by Dennis Berko on 10/25/14.
//  Copyright (c) 2014 Dennis. All rights reserved.
//

#include "test.h"

using namespace std;

void testHashTable()
{
   //Prints out true/false to screen rather than 1/0 for readability
   cout.setf(ios::boolalpha);
   
   HashTable<int, string> table;
   table.add(0, "a");
   table.add(1, "b");
   table.add(2, "c");
   
   cout << "##### Begin HashTable testing #####\nIf something is \"false\" there is a bug\n" << endl;
   
   cout << "--Testing adding items--" << endl;
   cout << "Size as expected: " << (table.size() == 3) << endl;
   cout << "isEmpty works: " << (!table.isEmpty()) << endl << endl;
   
   HashTable<int, string> table2(table);
   cout << "--Testing copy constructor--" << endl;
   cout << "Size as expected: " << (table2.size() == 3) << endl << endl;
   table2.clear();
   
   table.add(2, "d");
   
   cout << "--Testing duplicate key insertion--" << endl;
   cout << "Size as expected: " << (table.size() == 3) << endl;
   cout << "isEmpty works: " << (!table.isEmpty()) << endl;
   cout << "Record updated: " << (table.get(2) == "d") << endl << endl;
   
   
   cout << "--Testing retrieving items--" << endl;
   cout << "Existing items: " << (table.get(0) == "a" && table.get(1) == "b") << endl;
   cout << "Fetching non-existing throws exception: ";
   try {
      table.get(5);
      cout << false;
   } catch (HashTable<int, string>::NotFoundException) {
      cout << true;
   }
   
   cout << endl << endl;
   
   cout << "--Testing contains--" << endl;
   cout << "Contains element thats there: " << (table.contains(0)) << endl;
   cout << "Doesn't contain element thats not there: " << (!table.contains(10)) << endl << endl;
   
   table.remove(2);
   
   cout << "--Testing removal--" << endl;
   cout << "Size as expected: " << (table.size() == 2) << endl;
   cout << "isEmpty works: " << (!table.isEmpty()) << endl;
   cout << "Fetching non-existing throws exception: ";
   try {
      table.get(2);
      cout << false;
   } catch (HashTable<int, string>::NotFoundException) {
      cout << true;
   }
   
   cout << endl << endl;
   
   cout << "--Testing traverse--" << endl;
   table.traverse(printItem);
   cout << endl;
   
   table.clear();
   
   cout << "--Testing clear--" << endl;
   cout << "Size as expected: " << (table.size() == 0) << endl;
   cout << "isEmpty works: " << (table.isEmpty()) << endl;
   cout << "Doesn't contain element thats not there: " << (!table.contains(1)) << endl << endl;
}

void printItem(string &item)
{
   cout << item << endl;
}