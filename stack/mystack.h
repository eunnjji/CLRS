#pragma once
# include <stdlib.h>
using namespace std;

class stack {
private:

public:
	stack();
	stack(int capacity);
	void push(int x);
	int pop();
	bool Empty();
	int top();
	~stack();
};