#include "Node.h"

Node::Node()
{
	val = "";
	left = NULL;
	right = NULL;
}

Node::Node(const std::string v) : val(v), left(NULL), right(NULL) { }
Node::Node(const std::string v, Node* l) : val(v), left(l), right(NULL) { }
Node::Node(const std::string v, Node* l, Node* r) : val(v), left(l), right(r) { }