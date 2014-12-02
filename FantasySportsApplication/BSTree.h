
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>

template<typename T>
struct BTreeNode
{
	T    Data;
	BTreeNode* pLeft;
	BTreeNode* pRight;
	BTreeNode* pParent;

	BTreeNode(T data = T(), BTreeNode<T>* Parent = NULL,
		BTreeNode<T>* Left = NULL, BTreeNode<T>* Right = NULL)
		: Data(data), pLeft(Left), pRight(Right), pParent(Parent)
	{
	}
};

template<typename T>
class BSTree
{
protected:
	BTreeNode<T>*    m_pRootNode;

public:
	BSTree(BTreeNode<T>* pRoot = NULL)
		: m_pRootNode(pRoot)
	{
	}
	~BSTree();

	void            Display();
	BTreeNode<T>*    Insert(const T& data);
	BTreeNode<T>*    Find(const T& data);
	BTreeNode<T>*    FindMin();
	BTreeNode<T>*    FindMax();
	BTreeNode<T>*    Delete(const T& data);

private:
	void            Display(BTreeNode<T>* p);
	BTreeNode<T>*    Insert(const T& data, BTreeNode<T>* p);
	BTreeNode<T>*    Find(const T& data, BTreeNode<T>* p);
	BTreeNode<T>*    FindMin(BTreeNode<T>* p);
	BTreeNode<T>*    FindMax(BTreeNode<T>* p);
	BTreeNode<T>*    Delete(const T& data, BTreeNode<T>* p);

	void            DestructImpl(BTreeNode<T>* p);
};

#endif
