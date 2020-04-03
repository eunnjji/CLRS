#ifndef _Node_
#define _Node_
#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Node {
	int key;
	string data;
	Node() {
		this->key = NULL;
		this->data = "";
	}
	Node(int k, string str) {
		this->key = k;
		this->data = str;
	}
};
inline ostream& operator<<(ostream& out, Node& n)
{
	if (n.key == NULL) {
		out << "this Node is Empty\n";
		return out;
	}
	else {
		out << " key : " << n.key << " | ";
		out << " data :" << n.data << " \n";
		return out;
	}
};

#endif // !_Node_