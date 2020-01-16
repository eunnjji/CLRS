#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Node {
	int key;
	string data;
	Node() {
		this->key = -1;
		this->data = "";
	}
	Node(int k, string str) {
		this->key = k;
		this->data = str;
	}
};
ostream& operator<<(ostream& out, Node& n)
{
	if (n.data == "") {
		out << "this Node is Empty\n";
		return out;
	}
	else {
		out << " key : " << n.key << " | " ;
		out << " data :" << n.data << " \n";
		return out;
	}
};

class DirectAddressTB {
public:
	Node* myTB;
	unsigned int size;
	DirectAddressTB();
	DirectAddressTB(int size);
	Node search(int k);
	void insert(Node x);
	void deletion(Node x);
	~DirectAddressTB();
	
};