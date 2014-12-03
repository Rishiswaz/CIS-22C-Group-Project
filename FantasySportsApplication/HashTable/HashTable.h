//
//  HashTable.h
//  HashTable
//
//  Created by Dennis Berko on 10/20/14.
//  Copyright (c) 2014 Dennis. All rights reserved.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <functional>
#include "HashTableEntry.h"

using namespace std;

template <class KeyType, class ItemType>
class HashTable {
private:
   HashTableEntry<KeyType, ItemType>** hashTable;
   int itemCount;
   int hashTableSize;
   static const int DEFAULT_SIZE = 101;
   
public:
   HashTable();
   HashTable(int tableSize);
   HashTable(const HashTable &table);
   ~HashTable() { clear(); delete hashTable; };
   
   bool add(const KeyType& key, const ItemType& item);
   bool remove(const KeyType& key);
   ItemType get(const KeyType& key) const;
   
   bool isEmpty() const;
   int size() const;
   void clear();
   bool contains(const KeyType& key) const;
   void traverse(void visit(ItemType&)) const;
   
   class NotFoundException { };
private:
   int getHashIndex(const KeyType& key) const;
   void allocateArray();
};

/*
 Instantiates a HashTable with default values
 
 @pre none
 @post none
 @return none
 */
template <class KeyType, class ItemType>
HashTable<KeyType, ItemType>::HashTable()
{
   hashTableSize = DEFAULT_SIZE;
   itemCount = 0;
   allocateArray();
}

/*
 Instantiates a HashTable with a custom table size that *should* be a prime number
 
 @pre the size of the table
 @post none
 @return none
 */
template <class KeyType, class ItemType>
HashTable<KeyType, ItemType>::HashTable(int tableSize)
{
   hashTableSize = tableSize;
   itemCount = 0;
   allocateArray();
}

/*
 Copy constructor
 
 @pre The table to copy
 @post none
 @return none
 */
template <class KeyType, class ItemType>
HashTable<KeyType, ItemType>::HashTable(const HashTable &table)
{
   if (this != &table) {
      this->itemCount = table.itemCount;
      this->hashTableSize = table.hashTableSize;
      allocateArray();
      
      for (int i = 0; i < this->hashTableSize; i++) {
         if (table.hashTable[i] != nullptr) {
            HashTableEntry<KeyType, ItemType>* tablePtr = table.hashTable[i];
            HashTableEntry<KeyType, ItemType>* curPtr =
               new HashTableEntry<KeyType, ItemType>(tablePtr->getKey(), tablePtr->getItem());
            
            hashTable[i] = curPtr;
            tablePtr = tablePtr->getNext();
            
            
            while (tablePtr != nullptr) {
               HashTableEntry<KeyType, ItemType>* entry =
                  new HashTableEntry<KeyType, ItemType>(tablePtr->getKey(), tablePtr->getItem());
               
               curPtr->setNext(entry);
               curPtr = entry;
               tablePtr = tablePtr->getNext();
            }
         }
      }
   }
   
}

/*
 Adds or updates an item for a key
 If the key is new, it will insert a new item with that key
 If the key is not new, it will update the item for that key
 
 @pre
   key - The unique key to use
   item - The item stored for that unique key
 @post none
 @return true/false depnding on success
 */
template <class KeyType, class ItemType>
bool HashTable<KeyType, ItemType>::add(const KeyType& key, const ItemType& item)
{
   HashTableEntry<KeyType, ItemType>* entryToAddPtr;
   int itemHashIndex = getHashIndex(key);
   
   if (hashTable[itemHashIndex] == nullptr) {
      entryToAddPtr = new HashTableEntry<KeyType, ItemType>(key, item);
      hashTable[itemHashIndex] = entryToAddPtr;
      itemCount++;
   } else {
      //Key might be already present, lets check
      HashTableEntry<KeyType, ItemType>* curPtr = hashTable[itemHashIndex];
      bool found = false;
      
      while (curPtr != nullptr) {
         if (curPtr->getKey() == key) {
            curPtr->setItem(item);
            found = true;
            break;
         }
         
         curPtr = curPtr->getNext();
      }
      
      if (!found) {
         entryToAddPtr = new HashTableEntry<KeyType, ItemType>(key, item);
         entryToAddPtr->setNext(hashTable[itemHashIndex]);
         hashTable[itemHashIndex] = entryToAddPtr;
         
         itemCount++;
      }
   }
   return true;
}

/*
 Removes an entry from the table with that key
 
 @pre key to remove from the table
 @post none
 @return true if key was present/false if it was not
 */
template <class KeyType, class ItemType>
bool HashTable<KeyType, ItemType>::remove(const KeyType& key)
{
   bool itemFound = false;
   int itemHashIndex = getHashIndex(key);
   
   //We eliminate the need for an extra long "special case" as provided in the book
   //by introducing switch inside the loop
   if (hashTable[itemHashIndex] != nullptr) {
      HashTableEntry<KeyType, ItemType>* prevPtr = nullptr;
      HashTableEntry<KeyType, ItemType>* curPtr = hashTable[itemHashIndex];
      
      while ((curPtr != nullptr) && !itemFound) {
         if (key == curPtr->getKey()) {
            //If it's the first pointer, simply set it to the next one
            if (prevPtr == nullptr) {
               hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
            } else {
               prevPtr->setNext(curPtr->getNext());
            }
            delete curPtr;
            curPtr = nullptr;
            itemFound = true;
         } else {
            prevPtr = curPtr;
            curPtr = curPtr->getNext();
         }
      }
   }
   
   if (itemFound) {
      itemCount--;
   }
   
   return itemFound;
}

/*
 Retrieves an item assigned to that key in the table
 
 @pre The key to lookup in the table
 @post none
 @return The item if found, otherwise throws an exception
 */
template <class KeyType, class ItemType>
ItemType HashTable<KeyType, ItemType>::get(const KeyType& key) const
{
   bool itemFound = false;
   ItemType item;
   int itemHashIndex = getHashIndex(key);
   
   if (hashTable[itemHashIndex] != nullptr) {
      HashTableEntry<KeyType, ItemType>* curPtr = hashTable[itemHashIndex];
      
      while ((curPtr != nullptr) && !itemFound) {
         if (key == curPtr->getKey()) {
            item = curPtr->getItem();
            itemFound = true;
         } else {
            curPtr = curPtr->getNext();
         }
      }
   }
   
   if (!itemFound) {
      throw NotFoundException();
   }
   
   return item;
}

/*
 Checks if the table is empty
 
 @pre none
 @post none
 @return True if empty/false if not empty
 */
template <class KeyType, class ItemType>
bool HashTable<KeyType, ItemType>::isEmpty() const
{
   return itemCount == 0;
}

/*
 Returns the number of elements in the table
 
 @pre none
 @post none
 @return Number of elements
 */
template <class KeyType, class ItemType>
int HashTable<KeyType, ItemType>::size() const
{
   return itemCount;
}

/*
 Removes all elements from the table
 
 @pre none
 @post none
 @return none
 */
template <class KeyType, class ItemType>
void HashTable<KeyType, ItemType>::clear()
{
   if (itemCount == 0) {
      return;
   }
   
   for (int i = 0; i < hashTableSize; i++) {
      while (hashTable[i] != nullptr) {
         HashTableEntry<KeyType, ItemType>* temp = hashTable[i]->getNext();
         delete hashTable[i];
         hashTable[i] = temp;
         itemCount--;
      }
   }
}

/*
 Check if key is present in the table
 
 @pre The key to lookup
 @post none
 @return True if found/False if not
 */
template <class KeyType, class ItemType>
bool HashTable<KeyType, ItemType>::contains(const KeyType& key) const
{
   bool itemFound = false;
   int itemHashIndex = getHashIndex(key);
   
   if (hashTable[itemHashIndex] != nullptr) {
      HashTableEntry<KeyType, ItemType>* curPtr = hashTable[itemHashIndex];
      
      while ((curPtr != nullptr) && !itemFound) {
         if (key == curPtr->getKey()) {
            itemFound = true;
         } else {
            curPtr = curPtr->getNext();
         }
      }
   }
   
   return itemFound;
}

/*
 A function that calls the passed function for every element in the table
 can be use for something like a print table function, or to retrieve every item
 
 @pre The function to call for each element
 @post none
 @return none
 */
template <class KeyType, class ItemType>
void HashTable<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
   for (int i = 0; i < hashTableSize; i++) {      
      HashTableEntry<KeyType, ItemType> *curPtr = hashTable[i];
      
      while (curPtr != nullptr) {
         ItemType item = curPtr->getItem();
         visit(item);
         curPtr = curPtr->getNext();
      }
   }
}

/*
 We need to generate a hash for every key to place accordingly. This method leverages
 the C++11 hash function which handles the task nicely
 
 @pre They key to hash
 @post none
 @return What index in the array to place the key
 */
template <class KeyType, class ItemType>
int HashTable<KeyType, ItemType>::getHashIndex(const KeyType& key) const
{
   hash<KeyType> keyHash;
   return (int)(keyHash(key) % hashTableSize);
}

/*
 Used by the constructor(s) to dynamically allocate the array
 
 @pre none
 @post none
 @return none
 */
template <class KeyType, class ItemType>
void HashTable<KeyType, ItemType>::allocateArray()
{
   hashTable = new HashTableEntry<KeyType, ItemType>*[hashTableSize];

   for (int i = 0; i < hashTableSize; i++) {
	   hashTable[i] = nullptr;
   }
}

#endif