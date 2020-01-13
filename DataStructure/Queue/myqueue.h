#pragma once
#include <iostream>
using namespace std;

template<class T> class queue {
public:
	T* value;
	int head;
	int tail;
	int length;
	
	queue(T _size);
	void enqueue(T x);
	T dequeue();
	bool isFull();
	bool Empty();
	~queue();

};

