#include <iostream>
#include "binaryTree.h"
#include "binaryTree.cpp"
#include <fstream>
#include <string>
using namespace binarytree;
using namespace std;
int main()
{
	int keylist[5] = { 333, 111, 222, 444, 555 };
	CBinaryTree<int> teamtree;
	CTreeNode<int> *searchteam;
	for (int i = 0; i < 5; i++)
	{
		teamtree.insertElement(keylist[i]);
	}
	
	teamtree.deleteValue(555);
	searchteam = teamtree.search(333);
	cout << searchteam->key << endl;;
	
	 
	 teamtree.inorderTree(teamtree.root);


	system("pause");
	return 1;
}
