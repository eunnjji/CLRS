#include <stdlib.h>
#include <iostream>
#include "mystack.h"
using namespace std;
#define MAXSIZE 10

template<class T>
stack<T>::stack()
{
	size = MAXSIZE;
	this->buf = new T[size];
}

template<class T>
stack<T>::stack(int size)
{
	this->size = size;
	this->buf = new T[this->size];
	top = -1;
}

template<class T>
void stack<T>::push(T x)
{
	this->top = this->top + 1;
	this->buf[top] = x;
}

template<class T>
T stack<T>::pop()
{
	if (Empty() == true)
	{
		cout << "스택이 비어있음";
		return -1;
	}
	else {
		this->top = this->top - 1;
		return this->buf[this->top + 1];
	}
}

template<class T>
bool stack<T>::Empty()
{
	if (this->top == -1)
		return true;
	else
		return false;
}

template<class T>
T stack<T>::Top()
{
	return this->buf[this->top];
}

template<class T>
stack<T>::~stack()
{
	delete[] this->buf;
}


//int main() {
//	stack<int> a(5);
//	for (int i = 1; i < 6; i++) {
//		a.push(i);
//	}
//	for (int i = 0; i < 5; i++) {
//		cout << a.pop();
//	}
//}