#pragma once
# include <stdlib.h>
using namespace std;
#define MAXSIZE 10

template<class T> class stack {
private:
	int top;
	T* buf;
public:
	int size;
	stack();
	stack(int size);
	void push(T x);
	T pop();
	bool Empty();
	T Top();
	~stack();
};
