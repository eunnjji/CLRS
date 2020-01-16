#include <iostream>
#include <cstdlib>
#include <string>
#include "directaddress_TB.h"

using namespace std;
#define MAXSIZE 10

DirectAddressTB::DirectAddressTB() {
	this->size = MAXSIZE;
	this->myTB = new Node[this->size];
	cout << "this table size : " << this->size << "\n";
}


DirectAddressTB::DirectAddressTB(int size)
{
	this->size = size;
	this->myTB = new Node[this->size];
}

Node DirectAddressTB::search(int k)
{
	return this->myTB[k];
}


void DirectAddressTB::insert(Node x)
{
	if (this->myTB[x.key].data == "") {
		this->myTB[x.key] = x;
	}
	else {
		cout << "collison \n";
	}
}


void DirectAddressTB::deletion(Node x)
{
	this->myTB[x.key] = Node(0, "");
}


DirectAddressTB::~DirectAddressTB()
{
	delete[]myTB;
}

ostream& operator<<(ostream& out, DirectAddressTB& tb)
{
	out << " Current direct address table status\n";
	out << "-------------------------------------------\n";
	for (int i = 0; i < tb.size; i++) {
		out << i << " | " << tb.myTB[i] << "\n";
	}
	out << "-------------------------------------------\n";
	return out;
}

int main() {
	DirectAddressTB A;
	for (int i = 0; i < A.size; i+=2) {
		string str = "test" + to_string(i);
		Node tmp(i, str);
		//cout << tmp;
		A.insert(tmp);
	}
	cout << A;
	cout << A.search(0).key <<"|" << A.search(0).data << "\n";
	cout << A.search(1).key << "|" << A.search(1).data << "\n";
	A.deletion(Node(8, "test8"));
	cout << A;
}