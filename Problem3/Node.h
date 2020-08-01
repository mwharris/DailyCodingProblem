#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
	Node();
	Node(const std::string);
	Node(const std::string, Node*);
	Node(const std::string, Node*, Node*);

	std::string val;
	Node* left;
	Node* right;
};

#endif // !NODE_H
