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
	if (this->myTB[x.key].key == NULL) {
		this->myTB[x.key] = x;
	}
	else {
		cout << "collison \n";
		this->myTB[x.key] = x;
	}
}


void DirectAddressTB::deletion(Node x)
{
	this->myTB[x.key] = Node(NULL, "");
}


DirectAddressTB::~DirectAddressTB()
{
	delete[]myTB;
}



