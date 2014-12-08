#pragma once


#include <string>
#include <strstream>
#include "Team\Team.h"


class CTreeNode
{
public:
	Team data;
int key;
CTreeNode *lchild;
CTreeNode *rchild;
CTreeNode(Team dataIn, int value) :data(dataIn), key(value), lchild(NULL), rchild(NULL) {};
~CTreeNode(){ lchild = NULL; rchild = NULL; };
};

class CBinaryTree
{
public:
CBinaryTree();
~CBinaryTree();
bool treeEmpty();
bool insertNode(int value, Team dataIn);
void inorderTree(CTreeNode *root);
CTreeNode * minValue(CTreeNode * root);
CTreeNode * maxValue(CTreeNode * root);
CTreeNode  * search(int value);
bool deleteValue(int value);
CTreeNode  * parent(CTreeNode  * child);
CTreeNode  * postNode(CTreeNode  * node);
public:
CTreeNode  *root;
};


//
CBinaryTree ::CBinaryTree()
{
root = NULL;
}
//
CBinaryTree ::~CBinaryTree()
{
root = NULL;
}
//
bool CBinaryTree ::treeEmpty()
{
return root == NULL;
}
//
bool CBinaryTree ::insertNode(int value, Team dataIn)
{
CTreeNode  *p = root;
CTreeNode  *q = NULL;
while (p != NULL)
{
q = p;
if (value < p->key)
p = p->lchild;
else
p = p->rchild;
}
if (q == NULL)
{
root = new CTreeNode (dataIn, value);
return true;
}
else if (value < q->key)
{
q->lchild = new CTreeNode (dataIn, value);
return true;
}
else
{
q->rchild = new CTreeNode (dataIn, value);
return true;
}
return false;
}


void CBinaryTree::inorderTree(CTreeNode  *root)
{
if (root != NULL)
{
inorderTree(root->rchild);
std::cout << root->data << " "<<std::endl;
inorderTree(root->lchild);
}


}


CTreeNode  * CBinaryTree ::search(int value)
{
CTreeNode  *p = root;
while (p != NULL && p->key != value)
{
if (value < p->key)
p = p->lchild;
else
p = p->rchild;
}
return p;
}

CTreeNode  * CBinaryTree ::parent(CTreeNode  * child)
{
CTreeNode  *p = root;
CTreeNode  *q = NULL;
while (p != NULL && p->key != child->key)
{
q = p;
if (p->key > child->key)
{
p = p->lchild;
}
else
{
p = p->rchild;
}
}
return q;
}


CTreeNode  * CBinaryTree ::minValue(CTreeNode  * root)
{
CTreeNode  *p = root;
while (p->lchild != NULL)
{
p = p->lchild;
}
return p;
}


CTreeNode  * CBinaryTree ::maxValue(CTreeNode  * root)
{
CTreeNode  *p = root;
while (p->rchild != NULL)
{
p = p->rchild;
}
return p;
}


CTreeNode  * CBinaryTree ::postNode(CTreeNode  * node)
{
if (node->rchild != NULL)
return minValue(node->rchild);
CTreeNode  *p = node;
CTreeNode  *par = parent(p);
while (par != NULL && par->rchild == p)
{
p = par;
par = parent(p);
}
return par;
}


bool CBinaryTree ::deleteValue(int Value)
{
CTreeNode  * p = search(Value);
CTreeNode  * q = NULL;
CTreeNode  * s = NULL;
if (p->lchild == NULL || p->rchild == NULL)
{
q = p;
}
else
q = postNode(p);
s = parent(q);
if (q->lchild != NULL)
{
if (s != NULL && s->lchild == q)
s->lchild = q->lchild;
else if (s != NULL && s->rchild == q)
s->rchild = q->lchild;
}
else
{
if (s != NULL && s->lchild == q)
s->lchild = q->rchild;
else if (s != NULL && s->rchild == q)
s->rchild = q->rchild;
}
if (s == NULL)
root->key = q->key;
if (q != p)
p->key = q->key;
delete q;
return true;
}
