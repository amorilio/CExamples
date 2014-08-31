// Tree.cpp: implementation of the Tree class.
//
//////////////////////////////////////////////////////////////////////

#include "Tree.h"
#include <IOSTREAM>


using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template <typename T>
Tree::TreeNode<T>::TreeNode()
{
	this->data = 0;
}

template <typename T>
Tree::TreeNode<T>::~TreeNode()
{
	branches.clear();
}


template <typename T>
print(Tree::TreeNode<T> root)
{
	static int iLevel = 0;
	int i = 0;
	
	for (i = 0; i < iLevel; i++)
	{
		cout<<"\t";
	}
	cout<<root.data<<endl;
	int iNumOfChildren = root.branches.size();
	for(i = 0; i < iNumOfChildren; i++)
	{
		iLevel++;
		print(*root.branches[i]);
		iLevel--;
	}
}

#include "math.h"
void Tree::RandomPopulate(TreeNode<int>* node)
{
	int iValue		= rand() % 100;
	int iChildren	= rand() % 4;

	static int iLevel = 0;

	node->data = iValue;
	for ( int i = 0; i < iChildren; i++)
	{
		cout << "Processing Level: "<< iLevel << " ,Child:" << i << " ,Value:"<< iValue << " ,Total Children on level:" << iChildren<< endl;
		node->branches.push_back(new TreeNode<int>);
		if (iLevel < 5) {
			iLevel++;
			RandomPopulate(node->branches[i]);
		}
	}
	iLevel--;
}


Tree::Tree()
{
	root = new TreeNode<int>;
	RandomPopulate(root);
	print(*root);
}


Tree::~Tree()
{
	
}

Tree::Tree (const Tree::TreeNode &srcRoot)
{

}

// Tree::TreeNode& Tree::operator=(const Tree::TreeNode& srtRoot)
// {
// 	Tree::TreeNode<int> tmp;
// 	return tmp;
// }