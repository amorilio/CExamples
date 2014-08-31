// Tree.h: interface for the Tree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREE_H__745398D5_D39D_45CA_885E_7EDF4F56D67C__INCLUDED_)
#define AFX_TREE_H__745398D5_D39D_45CA_885E_7EDF4F56D67C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>


class Tree
{
	
public:

	template<typename T>
	class TreeNode  
	{
		public:
			TreeNode<T>();
			virtual ~TreeNode<T>();
	
			T data;
			std::vector<TreeNode<T> *> branches;
	};

	Tree();
	virtual ~Tree();
	Tree (const TreeNode &srcRoot);
	//TreeNode& operator=(const TreeNode& srtRoot);

	void RandomPopulate(TreeNode<int>* node);


private:
	TreeNode<int>* root;
};


#endif // !defined(AFX_TREE_H__745398D5_D39D_45CA_885E_7EDF4F56D67C__INCLUDED_)
