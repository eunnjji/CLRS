#pragma once
# include <stdlib.h>
using namespace std;

template<class T> class stack {
private:
	int top;
	int size;

public:

	stack();
	stack(int size);
	void push(T x);
	T pop();
	bool Empty();
	T top();
	~stack();
};