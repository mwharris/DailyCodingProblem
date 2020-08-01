/*
Problem 3
Given the root to a binary tree, implement serialize(root), which serializes the tree into a string,
and deserialize(s), which deserializes the string back into the tree.
*/

#include <iostream>
#include <stack>
#include "Node.h"

using std::string;
using std::stack;
using std::cout;
using std::endl;

// Turn a tree of Nodes into a string representation
string serialize(Node& root, bool isRoot) 
{
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

// Helper function to find a ')' associated with a '('
int findSubtreeEndIndex(string treeStr, int startIndex, int endIndex) 
{
	if (startIndex > endIndex) {
		return -1;
	}
	
	stack<char> parenthesisStack;
	for (int i = startIndex; i <= endIndex; i++) {
		if (treeStr[i] == '(') {
			parenthesisStack.push(treeStr[i]);
		}
		else if (treeStr[i] == ')') {
			parenthesisStack.pop();
		}
		if (parenthesisStack.empty()) {
			return i;
		}
	}

	return -1;
}

// Helper function to create a new Node
Node* newNode(char data) 
{
	return new Node(string(1, data), NULL, NULL);
}

// Deserialize a tree string into an actual tree of Nodes
Node* deserialize(string treeStr, int startIndex, int endIndex) 
{
	if (startIndex > endIndex) {
		return NULL;
	}

	// Create a new node
	Node* n = newNode(treeStr[startIndex]);

	// If we find a '(', find the associated ')' index
	int index = -1;
	if (startIndex + 1 <= endIndex && treeStr[startIndex + 1] == '(') {
		index = findSubtreeEndIndex(treeStr, startIndex + 1, endIndex);
	}

	// If we found a subtree, process left and right subtrees
	if (index > -1) {
		n->left = deserialize(treeStr, startIndex + 2, index);
		n->right = deserialize(treeStr, index + 2, endIndex - 1);
	}
	
	return n;
}

// Print a tree of Nodes in preorder for testing
void preOrder(Node* node)
{
	if (node == NULL) {
		return;
	}
	cout << node->val << " ";
	preOrder(node->left);
	preOrder(node->right);
}

void freeNodes(Node* n) 
{
	if (n == NULL) {
		return;
	}
	freeNodes(n->left);
	freeNodes(n->right);
	free(n);
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
	Node* n = deserialize(treeStr, 0, treeStr.length() - 1);
	cout << "Deserialized tree from string (preorder display): ";
	preOrder(n);

	// Make sure to free all of our Nodes
	freeNodes(n);
}