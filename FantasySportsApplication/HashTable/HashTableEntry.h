//
//  HashTableEntry.h
//  HashTable
//
//  Created by Dennis Berko on 10/25/14.
//  Copyright (c) 2014 Dennis. All rights reserved.
//

#ifndef HASHTABLEENTRY_H
#define HASHTABLEENTRY_H

#include <stdio.h>

template <class KeyType, class ItemType>
class HashTableEntry
{
private:
   KeyType key;
   ItemType item;
   HashTableEntry<KeyType, ItemType>* next;
   
public:
   HashTableEntry(KeyType key, ItemType item) : key(key), item(item), next(nullptr) {};
   
   ItemType getItem() const { return item; };
   KeyType getKey() const { return key; };
   HashTableEntry<KeyType, ItemType>* getNext() const { return next; };
   
   void setItem(const ItemType& item) { this->item = item; };
   void setNext(HashTableEntry<KeyType, ItemType>* next) { this->next = next; };
};

#endif
