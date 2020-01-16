#ifndef __OPEN_ADDR_HASH_TB__
#define __OPEN_ADDR_HASH_TB__
#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;
const int TB_SIZE = 10;
class hashNode {
public:
	int k;
	int v;
	hashNode(int k, int v) {
		this->k = k;
		this->v = v;
	}
};

class openAddrHashTB {
private:
	hashNode** tb;
public:
	openAddrHashTB() {
		tb = new hashNode *[TB_SIZE];
		for (int i = 0; i < TB_SIZE; i++) {
			tb[i] = NULL;
		}
	}
	int hash(int k) {
		return k % TB_SIZE;
	}
	int insert(int k, int v) {
		int h_k = hash(k);
		int i = 0;
		do {
			cout <<"h_k : "<< h_k<<", i : "<< i << "\n";
			h_k = hash(h_k + i);
			if (tb[h_k] == NULL)
			{
				tb[h_k] = new hashNode(k, v);
				return h_k;
			}
			else {
				cout << "collision\n";
				i = i + 1;
			}
		} while (i != TB_SIZE);
		cout << "hash table overflow\n";
		return -1;
	}
	int search(int k) {
		int i = 0;
		int h_k=hash(k);
		do {
			h_k = hash(k + i);
			if (tb[h_k]->k == k) {
				return h_k;
			}
			i = i + 1;
		} while (tb[h_k] != NULL || i != TB_SIZE );
		return NULL;
	}
	void remove(int k) {
		int h_k = hash(k);
		while (tb[h_k] != NULL) {
			if (tb[h_k]->k == k) {
				break;
			}
			h_k = hash(k + 1);
		} // end while
		if (tb[h_k] == NULL) {
			cout << "not found \n";
			return;
		}
		else {
			delete tb[h_k];
		}
		cout << "delete success\n";
	}
	~openAddrHashTB() {
		for (int i = 0; i < TB_SIZE; i++) {
			if (tb[i] != NULL) {
				delete tb[i];
			}
			delete[] tb;
		}
	}
	
};



#endif // !__OPEN_ADDR_HASH_TB__


