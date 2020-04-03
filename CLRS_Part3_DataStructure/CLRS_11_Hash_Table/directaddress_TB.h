#ifndef _DIRECTADDRESS_TB_
#define _DIRECTADDRESS_TB_
#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "Node.h"
using namespace std;

class DirectAddressTB {
public:
	Node* myTB;
	int size;
	DirectAddressTB();
	DirectAddressTB(int size);
	Node search(int k);
	void insert(Node x);
	void deletion(Node x);
	~DirectAddressTB();
	
};
inline
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

#endif // !1