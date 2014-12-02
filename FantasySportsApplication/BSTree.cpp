
#include <iostream>
#include "BSTree.h"

template<typename T>
BSTree<T>::~BSTree()
{
	DestructImpl(m_pRootNode);
}

template<typename T>
void BSTree<T>::DestructImpl(BTreeNode<T>* p)
{
	if (NULL == p)
		return;

	DestructImpl(p->pLeft);
	DestructImpl(p->pRight);
	p->pLeft = NULL;
	p->pRight = NULL;
	p->pParent = NULL;
	delete p;
	p = NULL;
}

template<typename T>
void BSTree<T>::Display()
{
	Display(m_pRootNode);
}

template<typename T>
void BSTree<T>::Display(BTreeNode<T>* p)
{
	if (NULL == p)
		return;

	Display(p->pLeft);
	std::cout << "Node = " << p->Data << std::endl;
	Display(p->pRight);
}

template<typename T>
BTreeNode<T>* BSTree<T>::Insert(const T& data)
{
	return Insert(data, m_pRootNode);
}

template<typename T>
BTreeNode<T>* BSTree<T>::Insert(const T& data, BTreeNode<T>* p)
{
	if (NULL == p)
	{
		p = new BTreeNode<T>(data);

		if (NULL == p)
		{
			return NULL;
		}
		else if (NULL == m_pRootNode)
		{
			m_pRootNode = p;
		}
	}
	else if (data > p->Data)
	{
		p->pRight = Insert(data, p->pRight);
		if (NULL != p->pRight)
		{
			p->pRight->pParent = p;
		}
	}
	else
	{
		p->pLeft = Insert(data, p->pLeft);
		if (NULL != p->pLeft)
		{
			p->pLeft->pParent = p;
		}
	}

	return p;
}

template<typename T>
BTreeNode<T>* BSTree<T>::Find(const T& data)
{
	return Find(data, m_pRootNode);
}

template<typename T>
BTreeNode<T>* BSTree<T>::Find(const T& data, BTreeNode<T>* p)
{
	if (NULL == p)
	{
		return NULL;
	}
	else
	{
		if (data == p->Data)
		{
			return p;
		}
		else if (data > p->Data)
		{
			return Find(data, p->pRight);
		}
		else
		{
			return Find(data, p->pLeft);
		}
	}
}

template<typename T>
BTreeNode<T>* BSTree<T>::FindMin()
{
	return FindMin(m_pRootNode);
}

template<typename T>
BTreeNode<T>* BSTree<T>::FindMin(BTreeNode<T>* p)
{
	if (NULL == p)
	{
		return NULL;
	}

	if (NULL != p->pLeft)
	{
		return FindMin(p->pLeft);
	}
	else
	{
		return p;
	}
}

template<typename T>
BTreeNode<T>* BSTree<T>::FindMax()
{
	return FindMax(m_pRootNode);
}

template<typename T>
BTreeNode<T>* BSTree<T>::FindMax(BTreeNode<T>* p)
{
	if (NULL == p)
	{
		return NULL;
	}

	if (NULL != p->pRight)
	{
		return FindMax(p->pRight);
	}
	else
	{
		return p;
	}
}

template<typename T>
BTreeNode<T>* BSTree<T>::Delete(const T& data)
{
	return Delete(data, m_pRootNode);
}

template<typename T>
BTreeNode<T>* BSTree<T>::Delete(const T& data, BTreeNode<T>* p)
{
	if (NULL == p)
	{
		return NULL;
	}
	else if (data < p->Data)
	{
		p->pLeft = Delete(data, p->pLeft);
	}
	else if (data > p->Data)
	{
		p->pRight = Delete(data, p->pRight);
	}
	else if (NULL != p->pLeft && NULL != p->pRight)
	{
	
		BTreeNode<T>* pNode;

		pNode = FindMin(p->pRight);
		p->Data = pNode->Data;
		p->pRight = Delete(p->Data, p->pRight);
	}
	else
	{
		
		BTreeNode<T>* pNode = p;
		if (NULL == p->pLeft)
		{
			p = p->pRight;
		}
		else if (NULL == p->pRight)
		{
			p = p->pLeft;
		}
		delete pNode;
		pNode = NULL;
	}

	return p;
}
