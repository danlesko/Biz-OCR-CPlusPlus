#include "stringBST.h"
#include <iostream>

using namespace std;

//public insert method
//accepts string and then places it into tree
void stringBST::insertNode(string str) {
	TreeNode *newNode;

	newNode = new TreeNode;
	newNode->value = str;
	newNode->left = newNode->right = NULL;

	insert(root, newNode);
}

//does insertion comparison until our new node finds a place on the tree
void stringBST::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL) {
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value) {
		insert(nodePtr->left, newNode);
	}
	else {
		insert(nodePtr->right, newNode);
	}
}

//systematically destroy the tree from bottom up to designated node
void stringBST::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr) {
		if (nodePtr->left) {
			destroySubTree(nodePtr->left);
		}
		if (nodePtr->right) {
			destroySubTree(nodePtr->right);
		}
		delete nodePtr;
	}
}

//search tree for a given string and return true or false
bool stringBST::searchNode(string str)
{
	TreeNode *nodePtr = root;

	while (nodePtr) {
		if (nodePtr->value == str) {
			return true;
		}
		else if (str < nodePtr->value) {
			nodePtr = nodePtr->left;
		}
		else {
			nodePtr = nodePtr->right;
		}
	}
	return false;
}