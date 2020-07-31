/*
Problem 3
Given the root to a binary tree, implement serialize(root), which serializes the tree into a string,
and deserialize(s), which deserializes the string back into the tree.
*/

#include <iostream>
#include "Node.h"

using std::string;
using std::cout;
using std::endl;

string serialize(Node& root, bool isRoot) {
	string s = "";
	
	// Us
	s += root.val;
	// Left
	if (root.left != NULL) {
		string l = serialize(*(root.left), false);
		s += "(" + l;
	}
	// Right
	if (root.right != NULL) {
		string r = serialize(*(root.right), false);
		s += "(" + r;
	}
	
	// Add a ')' only if we're not the starting root
	if (isRoot) {
		return s;
	}
	else {
		return s + ")";
	}
}

Node deserialize(string treeStr) {
	Node r = Node();
	return r;
}

int main()
{
	// Create test tree structure
	Node leftLeft = Node("4");
	Node left = Node("2", &leftLeft);
	Node right = Node("3");
	Node root = Node("1", &left, &right);
	
	// Serliaze our test tree
	string treeStr = serialize(root, true);
	cout << "Serialized tree structure: " << treeStr << endl;
	
	// Deserialize our string back into a tree
	Node n = deserialize(treeStr);
	cout << "Deserialized tree from string: " << treeStr << endl;
	
	// Confirm our code worked properly
	if (n.left != NULL && n.left->left != NULL && n.left->left->val == "4") {
		cout << "We did it!" << endl;
	}
	else {
		cout << "You fucked up" << endl;
	}
}