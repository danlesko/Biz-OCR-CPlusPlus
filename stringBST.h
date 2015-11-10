#ifndef STRINGBST_H
#define STRINGBST_H
#include <iostream>

using namespace std;

class stringBST {
private:
	//node definition for string BST
	struct TreeNode {
		string value;
		TreeNode *left;
		TreeNode *right;
	};

	//root pointer
	TreeNode *root;

	//no advanced functions, just insert and destroy
	//private versions of insert / destroy
	void insert(TreeNode *&, TreeNode*&);
	void destroySubTree(TreeNode *);

public:
	//tree constructor
	stringBST() {
		root = NULL;
	}

	//tree destructor
	~stringBST() {
		destroySubTree(root);
	}

	//public insert / search functions
	void insertNode(string);
	bool searchNode(string);
};

#endif