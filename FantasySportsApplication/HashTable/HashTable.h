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
   ~HashTable() { clear(); };
   
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

template <class KeyType, class ItemType>
HashTable<KeyType, ItemType>::HashTable()
{
   hashTableSize = DEFAULT_SIZE;
   itemCount = 0;
   allocateArray();
}

template <class KeyType, class ItemType>
HashTable<KeyType, ItemType>::HashTable(int tableSize)
{
   hashTableSize = tableSize;
   itemCount = 0;
   allocateArray();
}

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

template <class KeyType, class ItemType>
bool HashTable<KeyType, ItemType>::isEmpty() const
{
   return itemCount == 0;
}

template <class KeyType, class ItemType>
int HashTable<KeyType, ItemType>::size() const
{
   return itemCount;
}

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

//This uses C++11 hash function which is quite nice
template <class KeyType, class ItemType>
int HashTable<KeyType, ItemType>::getHashIndex(const KeyType& key) const
{
   hash<KeyType> keyHash;
   return (int)(keyHash(key) % hashTableSize);
}

template <class KeyType, class ItemType>
void HashTable<KeyType, ItemType>::allocateArray()
{
   hashTable = new HashTableEntry<KeyType, ItemType>*[hashTableSize];
}
#endif
