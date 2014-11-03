/* Binary Search Tree
Notes: I think I have all the declarations necessary for the BST, maybe even a little more. 
I just copied what was in the book, so I hope I got everything.
Working on function implementations right now, feel free to tell me all the stuff I'm doing wrong :)
*/

template<class ItemType>
class BinaryTreeInterface
{
public:
	/* Tests whether this binary tree is empty */
	virtual bool isEmpty() const = 0;

	/* Gets the height of this binary tree */
	virtual int getHeight() const = 0;

	/* Gets the number of nodes in this binary tree */
	virtual int getNumberOfNodes() const = 0;

	/* Gets the data that is in the root of this binary tree */
	virtual ItemType getRootData() const = 0;

	/* Replaces the data item in the root of this binary tree with the given data, if the tree is not empty. However, if the tree is empty, inserts a new root node containing the given data into the tree */
	virtual void setRootData(const ItemType& newData) = 0;

	/* Adds a new node containing the given data to this binary tree */
	virtual bool add(const ItemType& newData) = 0;

	/* Removes the node containing the given data item from this binary tree */
	virtual bool remove(const ItemType& data) = 0;

	/* Removes all nodes from this binary tree
	virtual void clear() = 0;

	/* Gets a specific entry in this binary tree */
	virtual ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException) = 0;

	/* Tests whether a given entry occurs in this binary tree */
	Virtual bool contains(const ItemType& anEntry const = 0;

	/* Traverses this binary tree in preorder (inorder, postorder) and calls the function visit once for each node */
	virtual void preorderTraverse(void visit(ItemType&)) const = 0;
	virtual void inorderTraverse(void visit(ItemType&)) const = 0;
	virtual void postorderTraverse(void visit(ItemType&)) const = 0;
};

//BinaryNode Base Class
template<class ItemType>
class BinaryNode
{
private:
	ItemType item;						          	// Data portion
	BinaryNode<ItemType>* leftChildPtr;		// Pointer to left child
	BinaryNode<ItemType>* rightChildPtr;	// Pointer to right child
public:
	BinaryNode();						            	// Default Constructor
	BinaryNode(const ItemType& anItem);
	BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr);

	void setItem(const ItemType& anItem);
	ItemType getItem() const;

	bool isLeaf() const;

	BinaryNode<ItemType>* getLeftChildPtr() const;
	BinaryNode<ItemType>* getRightChildPtr() const;

	void setLeftChildPtr(BinaryNode<ItemType* leftPtr);
	void setRightChildPtr(BinaryNode<ItemType>* rightPtr;
};

//BinaryNodeTree Class (Child of BinaryTreeInterface)
template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
	BinaryNode<ItemType>* rootPtr;	

protected:
	/* ***Protected Utility Methods Section: Recursive helper methods for the public methods*** */

	int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePrt) const;

	/* Recursively deletes all nodes from the tree */
	void destroyTree(BinaryNode<ItemType>* subTreePtr);

	/* Recursively adds a new node to the tree in a left/right fashion to keep tree balanced  */
	BinaryNode<ItemType>* balanced(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);

	/* Removes the target value from the tree by calling moveValuesUpTree to overwrite value with value from child */
	BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);

	/* Copies values up the tree to overwrite value in current node until a leaf is reached; the leaf is then removed, since its value is stored in the parent */
	BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);

	/* Recursively searches for target value in the tree by using a preorder traversal */
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const;

	/* Copies the tree rooted at treePtr and returns a pointer to the copy */
	BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;

	/* ***Recursive traversal helper methods:*** */
	void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

public:
	/* ***Constructor and Destructor Section*** */
	BinaryNodeTree();
	BinaryNodeTree(const ItemType& rootItem);
	BinaryNodeTree(const ItemType& rootItem,
		const BinaryNodeTree<ItemType>* leftTreePtr,
		const BinaryNodeTree<ItemType>* rightTreePtr);
	BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
	virtual ~BinaryNodeTree();

	/* ***Public BinaryTreeInterface Methods Section*** */
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw(PrecondViolatedExcep);
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData);	// Adds a node
	bool remove(const ItemType& data);	// Removes a node
	void clear();
	ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
	bool contains(const ItemType& anEntry) const;

	/* ***Public Traversals Section*** */
	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;

	/* ***Overloaded Operator Section*** */
	BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
};

//BinaryNodeTree Implementations


//BinarySearchTree Class (Child of BinaryNodeTree)
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
private:
	BinaryNode<ItemType>* rootPtr;

protected:
	/* ***Protected Utility Methods Section: Recursive helper methods for the public methods*** */

	/* Recursively finds where the given node should be placed and inserts it in a leaf at that point */
	BinaryNode<ItemType>* insertOrder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode);

	/* Removes the given target value from the tree while maintaining a binary search tree */
	BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);

	/* Removes a given node from a tree while maintaining a binary search tree */
	BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);

	/* Removes the leftmost node in the left subtree of the node pointed to by nodePtr.
	Sets inorderSuccessor to the value in this node.
	Returns a pointer to the revised subtree. */
	BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSueccessor);

	/* Returns a pointer to the node containing the given value, or nullptr if not found */
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const;

public:
	/* ***Constructor and Destructor Section*** */
	BinarySearchTree();
	BinarySearchTree(const ItemType& rootItem);
	BinarySearchTree(const BinarySearchTree<ItemType>& tree);
	virtual ~BinarySearchTree();

	/* ***Public Methods Section*** */
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw(PrecondViolatedExcep);
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newEntry);	// Adds a node
	bool remove(const ItemType& anEntry);	// Removes a node
	void clear();
	ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
	bool contains(const ItemType& anEntry) const;

	/* ***Public Traversals Section *** */
	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;

	/* ***Overloaded Operator Section*** */
	BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);
};

//BinarySearchTree Function Implimentations
