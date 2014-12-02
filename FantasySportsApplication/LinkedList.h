/*--------------------------------
LinkedList.h
Linked List Implementation File
--------------------------------*/
#include<iostream>
#include<string>
#include<fstream>
#include<team.h>

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
	virtual void setEntry(int position, const ItemType& newEntry) = 0;					// replaces the entry at the given position in this list
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
	/* File Data */
	string teamName;
	int wins;
	int losses;
	int yards;
	double percentage;
	int finalScore;
	int ppi;

public:
	/* Constructors and Destructors */
	Node();																											// Default Constructor
	Node(const string tName, const int w, const int l, const int y, const double per, const int fs, const int pp);	// Constructor with File Data parameters
	Node(const ItemType& anItem);																					// Constructor
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);														// Constructor

	/* Public Accessors and Mutators*/
	bool readData();																	// reads data from file
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
	Node<ItemType>* curPtr;                                                             // pointer at current entry
	Node<ItemType>* nullPtr;															// pointer to nothing
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
	void sort();                                                                        // sorts list based on input criteria
};

/*--------------------------------
Node Class Implementations
--------------------------------*/
//Default constructor
template<class ItemType>
Node<ItemType>::Node()
{
	teamName = " ";
	wins = 0;
	losses = 0;
	yards = 0;
	percentage = 0;
	ppi = 0;
	next = NULL;
}

//constructor w/ file data parameters
template<class ItemType>
Node<ItemType>::Node(const string tName, const int w, const int l, const int y, const double per, const int fs, const int pp)
{
	teamName = tName;
	wins = w;
	losses = l;
	yards = y;
	percentage = per;
	finalScore = fs;
	ppi = pp;
	next = NULL;
}

//constructor
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{

}

//readData
template<class ItemType>
bool Node<ItemType>::readData()
{
	string tName;
	int w;
	int l;
	int y;
	double per;
	int fs
	int pp;
	string file = "data.csv";

	// Open input file
	ifstream din;
	din.open(file.c_str());
	if (din.fail())
	{
		cerr << "Could not open file: " << file << endl;
		return false;
	}

	// Read data
	Node<ItemType> *head = NULL;
	while (!din.eof())
	{
		din >> tName >> w >> l >> y >> per >> fs >> pp;

		Node<ItemType> *temp = new Node(tName, w, l, y, per, fs, pp);
		temp->setNext(head);
		head = temp;
	}

	din.close();
	return true;
}

//setItem
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

//setNext
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

//getItem
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

//getNext
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}

/*--------------------------------
LinkedList Class Implementations
--------------------------------*/
//Need to create default constructor
/*
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullPtr), itemCount(0)
{

}
*/

//getNodeAt
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	Node<ItemType>* curPtr = headPtr;
	for (int i = 1; i < position; i++)
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
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
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

		itemCount++;
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
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}

		curPtr->setNext(nullPtr);
		delete curPtr;
		curPtr = nullPtr;

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
/*
//sort
template<class ItemType>
void LinkedList<ItemType>::sort()
{
    int sortInput;
    Node<ItemType>* head = headPtr;


    cout << "Please input desired sort: " << endl;
    cout << "(1)- Team Name" << endl;
    cout << "(2)- Wins" << endl;
    cout << "(3)- Losses" << endl;
    cout << "(4)- Yards" << endl;
    cin >> sortInput;

    switch(sortInput)
    {
        case 1:
        {
            if (head != 0)
            {
                Node* current = head;
                Node* prev = 0;
                Node* tempNode = 0;
                bool changeFlag = false;
                for (int i = 0; i < itemCount; i++)
                {
                    while (current->next != 0)
                    {
                        tempNode = current->next;

                        if (current->teamName > tempNode->teamName)
                        {
                            changeFlag = true;
                            current->next = tempNode->next;
                            tempNode->next = current;
                            if (prev != 0)
                                prev->next = tempNode;
                            prev = tempNode;
                            if (head == current)
                                head = tempNode;
                            if (current->next == 0)
                                end = current;
                        }
                        else
                        {
                            prev = current;
                            current = current->next;
                        }
                    }
                    if (changeFlag == false)
                        break;
                    else
                    {
                        prev = 0;
                        current = head;
                        changeFlag = false;
                    }
                }
            }
        }

        case 2:
        {
            if (head != 0)
            {
                Node* current = head;
                Node* prev = 0;
                Node* tempNode = 0;
                bool changeFlag = false;
                for (int i = 0; i < itemCount; i++)
                {
                    while (current->next != 0)
                    {
                        tempNode = current->next;

                        if (current->wins > tempNode->wins)
                        {
                            changeFlag = true;
                            current->next = tempNode->next;
                            tempNode->next = current;
                            if (prev != 0)
                                prev->next = tempNode;
                            prev = tempNode;
                            if (head == current)
                                head = tempNode;
                            if (current->next == 0)
                                end = current;
                        }
                        else
                        {
                            prev = current;
                            current = current->next;
                        }
                    }
                    if (changeFlag == false)
                        break;
                    else
                    {
                        prev = 0;
                        current = head;
                        changeFlag = false;
                    }
                }
            }
        }

        case 3:
        {
            if (head != 0)
            {
                Node* current = head;
                Node* prev = 0;
                Node* tempNode = 0;
                bool changeFlag = false;
                for (int i = 0; i < itemCount; i++)
                {
                    while (current->next != 0)
                    {
                        tempNode = current->next;

                        if (current->losses > tempNode->losses)
                        {
                            changeFlag = true;
                            current->next = tempNode->next;
                            tempNode->next = current;
                            if (prev != 0)
                                prev->next = tempNode;
                            prev = tempNode;
                            if (head == current)
                                head = tempNode;
                            if (current->next == 0)
                                end = current;
                        }
                        else
                        {
                            prev = current;
                            current = current->next;
                        }
                    }
                    if (changeFlag == false)
                        break;
                    else
                    {
                        prev = 0;
                        current = head;
                        changeFlag = false;
                    }
                }
            }
        }

        case 4:
        {
            if (head != 0)
            {
                Node* current = head;
                Node* prev = 0;
                Node* tempNode = 0;
                bool changeFlag = false;
                for (int i = 0; i < itemCount; i++)
                {
                    while (current->next != 0)
                    {
                        tempNode = current->next;

                        if (current->yards > tempNode->yards)
                        {
                            changeFlag = true;
                            current->next = tempNode->next;
                            tempNode->next = current;
                            if (prev != 0)
                                prev->next = tempNode;
                            prev = tempNode;
                            if (head == current)
                                head = tempNode;
                            if (current->next == 0)
                                end = current;
                        }
                        else
                        {
                            prev = current;
                            current = current->next;
                        }
                    }
                    if (changeFlag == false)
                        break;
                    else
                    {
                        prev = 0;
                        current = head;
                        changeFlag = false;
                    }
                }
            }
        }

    }
}
*/
