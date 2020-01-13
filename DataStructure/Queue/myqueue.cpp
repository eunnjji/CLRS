// Queue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "myqueue.h"
using namespace std;

#define MAXSIZE 10


template<class T>
inline queue<T>::queue(T _size)
{
    this->value = new T[_size];
    this->head = 0;
    this->tail = 0;
    this->length = _size;
}

template<class T>
void queue<T>::enqueue(T x)
{
    if (isFull())
    {
        cout << "overflow\n";
        exit(-1);
    }
    this->value[this->tail] = x;
    // this->tail = (this->tail +1)%this->length
    if (this->tail == this->length - 1)
        this->tail = 0;
    else
        this->tail += 1;
}

template<class T>
T queue<T>::dequeue()
{
    if (Empty()) {
        cout << "underflo\n";
        exit(-1);
    }
    T x = this->value[this->head];
    // this->head = (this->head +1)%this->length
    if (this->head == this->length - 1)
        this->head = 0;
    else
        this->head += 1;
    return x;
}

template<class T>
bool queue<T>::isFull()
{
    if ((this->tail+1)%this->length == this->head)
        return true;
    else
        return false;
}

template<class T>
bool queue<T>::Empty()
{
    if (this->tail == this->head)
        return true;
    else return false;
}

template<class T>
queue<T>::~queue()
{
    delete[] this->value;
}

template<class T>
ostream& operator<<(ostream& out, queue<T>& q)
{
    T* tmp = q.value;
    out << "head [ ";
    for (int i = q.head; i < q.tail; i++) {
        out << tmp[i];
        if (i < q.tail - 1) out << " ] [ ";
    }
    out << " ] tail \n";
    return out;
}



int main()
{
    queue<int> a(MAXSIZE);
    cout << a;
    a.enqueue(4);
    cout << a;
    a.enqueue(1);
    cout << a;
    a.enqueue(3);
    cout << a;
    a.dequeue();
    cout << a;
    a.enqueue(8);
    cout << a;
    a.dequeue();
    cout << a;


}
