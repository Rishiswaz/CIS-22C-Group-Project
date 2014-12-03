#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
namespace binarytree
{
	template<typename Element>
	class CTreeNode
	{
	public:
		Element key;
		CTreeNode<Element> *lchild;
		CTreeNode<Element> *rchild;
		CTreeNode(Element value) :key(value), lchild(NULL), rchild(NULL){};
		~CTreeNode(){ lchild = NULL; rchild = NULL; };
	};
	template <typename Element>
	class CBinaryTree
	{
	public:
		CBinaryTree();
		~CBinaryTree();
		bool treeEmpty();
		bool insertElement(Element value);
		void inorderTree(CTreeNode<Element> *root);
		CTreeNode<Element> * minValue(CTreeNode<Element> * root);
		CTreeNode<Element> * maxValue(CTreeNode<Element> * root);
		CTreeNode<Element> * search(Element value);
		bool deleteValue(Element value);
		CTreeNode<Element> * parent(CTreeNode<Element> * child);
		CTreeNode<Element> * postNode(CTreeNode<Element> * node);
	public:
		CTreeNode<Element> *root;
	};


	template<typename Element>
	CBinaryTree<Element>::CBinaryTree()
	{
		root = NULL;
	}
	template<typename Element>
	CBinaryTree<Element>::~CBinaryTree()
	{
		root = NULL;
	}
	template<typename Element>
	bool CBinaryTree<Element>::treeEmpty()
	{
		return root == NULL;
	}
	template<typename Element>
	bool CBinaryTree<Element>::insertElement(Element value)
	{
		CTreeNode<Element> *p = root;
		CTreeNode<Element> *q = NULL;
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
			root = new CTreeNode<Element>(value);
			return true;
		}
		else if (value < q->key)
		{
			q->lchild = new CTreeNode<Element>(value);
			return true;
		}
		else
		{
			q->rchild = new CTreeNode<Element>(value);
			return true;
		}
		return false;
	}
	template<typename Element>
	void CBinaryTree<Element>::inorderTree(CTreeNode<Element> *root)
	{
		if (root != NULL)
		{
			inorderTree(root->lchild);
			cout << root->key << endl;
			inorderTree(root->rchild);
		}
	}
	template<typename Element>
	CTreeNode<Element> * CBinaryTree<Element>::search(Element value)
	{
		CTreeNode<Element> *p = root;
		while (p != NULL && p->key != value)
		{
			if (value < p->key)
				p = p->lchild;
			else
				p = p->rchild;
		}
		return p;
	}

	template<typename Element>
	CTreeNode<Element> * CBinaryTree<Element>::parent(CTreeNode<Element> * child)
	{
		CTreeNode<Element> *p = root;
		CTreeNode<Element> *q = NULL;
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
	template<typename Element>
	CTreeNode<Element> * CBinaryTree<Element>::minValue(CTreeNode<Element> * root)
	{
		CTreeNode<Element> *p = root;
		while (p->lchild != NULL)
		{
			p = p->lchild;
		}
		return p;
	}
	template<typename Element>
	CTreeNode<Element> * CBinaryTree<Element>::maxValue(CTreeNode<Element> * root)
	{
		CTreeNode<Element> *p = root;
		while (p->rchild != NULL)
		{
			p = p->rchild;
		}
		return p;
	}
	template<typename Element>
	CTreeNode<Element> * CBinaryTree<Element>::postNode(CTreeNode<Element> * node)
	{
		if (node->rchild != NULL)
			return minValue(node->rchild);
		CTreeNode<Element> *p = node;
		CTreeNode<Element> *par = parent(p);
		while (par != NULL && par->rchild == p)
		{
			p = par;
			par = parent(p);
		}
		return par;
	}
	template<typename Element>
	bool CBinaryTree<Element>::deleteValue(Element Value)
	{
		CTreeNode<Element> * p = search(Value);
		CTreeNode<Element> * q = NULL;
		CTreeNode<Element> * s = NULL;
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
}

#endif
