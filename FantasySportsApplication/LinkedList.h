/*--------------------------------
LinkedList.h
Linked List Implementation File
--------------------------------*/
#include<iostream>

#indef _LINKED_LIST
#define _LINKED_LIST

using namespace std;
/*--------------------------------
ListInterface Class
--------------------------------*/
template<class ItemType>
class ListInterface
{
public:
	virtual bool isEmpty() const = 0;													// sees if list is empty
	virtual int getLength() const = 0;													// gets the current number of entries in this list
	virtual bool insert(int newPosition, const ItemType& newEntry) = 0;					// inserts an entry into this list at a given position
	virtual bool remove(int position) = 0;												// removes an entry into this list at a given position
	virtual void clear() = 0;															// removes all entries from this list
	virtual ItemType getEntry(int position) const = 0;									// gets the entry at the given position in this list
	virtual void setEntry(int position, const ItemType& newEntry) = 0;					// replaces the entry atthe given position in this list
};

/*--------------------------------
Node Class
--------------------------------*/
template<class ItemType>
class Node
{
private:
	ItemType item;																		// data item
	Node<ItemType>* next;																// pointer to next node

public:
	/* Constructors and Destructors */
	Node();																				// Default Constructor
	Node(const ItemType& anItem);														// Constructor
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);							// Constructor

	/* Public Accessors and Mutators*/
	void setItem(const ItemType& anItem);												// assigns data to "item" value
	void setNext(Node<ItemType>* nextNodePtr);											// sets next pointer
	ItemType getItem() const;															// returns data from current pointer
	Node<ItemType>* getNext() const;													// returns data from next pointer
};

/*--------------------------------
LinkedList Class
--------------------------------*/
template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;															// pointer to first node; contains first entry
	Node<ItemType>* getNodeAt(int position) const;										// Locates specified node in list
	int itemCount;																		// current count of list items
	
public:
	/* Constructors and Destructors */
	LinkedList();																		// Default Constructor
	LinkedList(const LinkedList<ItemType>& aList);										// Copy Constructor
	virtual ~LinkedList();																// Destructor

	/* ListInterface Functions */
	bool isEmpty();																		// sees if list is empty
	int getLength() const;																// gets the current number of entries in this list	
	bool insert(int newPosition, const ItemType& newEntry);								// inserts an entry into this list at a given position
	bool remove(int position);															// removes an entry into this list at a given position
	void clear();																		// removes all entries from this list

	ItemType getEntry(int position) const;												// checks if given position is legal
	void setEntry(int position, const ItemType& newEntry);								// sets entry at given position
};

/*--------------------------------
Node Class Implementations
--------------------------------*/
template<class ItemType>
Node<ItemType>::Node() : next(null)
{

}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{

}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{

}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}

/*--------------------------------
LinkedList Class Implementations
--------------------------------*/
//constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{

}

//getNodeAt
template<class ItemType>
Node<ItemType>* LinkedList < ItemType::getNodeAt(int position) const
{
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
	{
		curPtr = curPtr->getNext();
	}

	return curPtr;
}

//getEntry
template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		cout << "getEntry() called with empty list or invalid position" << endl;
	}
}

//insert
template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry);
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

		if (newPosition == 1)
		{
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(newPosition = 1);
			prevPtr->setNext(newNodePtr);
		}

		itemCount++
	}

	return ableToInsert;
}

//remove
template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullPtr;
		if (position == 1)
		{
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			curPtr = prev->getNext();
			prevPtr->setNext(cur->getNext());
		}

		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;

		itemCount--;
	}

	return ableToRemove;
}

//clear
template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}

//destructor
template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}