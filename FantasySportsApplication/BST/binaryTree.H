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
}
#endif
