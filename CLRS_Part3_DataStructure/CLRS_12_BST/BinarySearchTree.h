#ifndef __BinarySearchTree__
#define __BinarySearchTree__
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#pragma once
class Node {
protected:
	int data;
	Node* parent;
	Node* left;
	Node* right;
public:
	Node(int a = 0, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr)
		: data(a), left(l), right(r), parent(p) {}
	void setData(int d) { data = d; }
	void setLeft(Node* l) { left = l; }
	void setRight(Node* r) { right = r; }
	void setParent(Node* p) { parent = p; }
	int getData() {
		return data;
	}
	Node* getLeft() {
		return left;
	}
	Node* getRight() {
		return right;
	}
	Node* getParent() {
		return parent;
	}
	bool isLeaf() {
		return left == nullptr && right == nullptr;
	}
};

class BinarySearchTree {
public:
	Node* root;
	BinarySearchTree() :root(nullptr) {}
	bool isEmpty() { return root == nullptr; }
	void setRoot(Node* x) {root = x;	}
	Node* getRoot() { return root;	}
	// Add Node in Tree ---------------------------------------------
	void add_repeat(Node* z) { // book p296  Implement
		if (z == nullptr) return;
		Node* y = nullptr;
		Node* x = root;
		while (x != nullptr) {
			y = x;
			if (z->getData() < x->getData())
				x = x->getLeft();
			else
				x = x->getRight();
		}
		z->setParent(y);
		if (y == nullptr)
			root = z;
		else if (z->getData() < y->getData())
			y->setLeft(z);
		else
			y->setRight(z);

	}
	void add_recur(Node* z) { // reference 1
		if (z == nullptr) return;
		if (root == nullptr) root = z;
		else add_recur_(root, z);
	}
	void add_recur_(Node* p, Node* z) {
		if (z->getData() == p->getData()) return;
		else if (z->getData() < p->getData()) {
			if (p->getLeft() == nullptr)
			{
				z->setParent(p);
				p->setLeft(z);
			}
			else add_recur_(p->getLeft(), z);
		}
		else {
			if (p->getRight() == nullptr) {
				z->setParent(p);
				p->setRight(z);
			}
			else add_recur_(p->getRight(), z);
		}
	}
	// Tree tour---------------------------------------------------------
	void inorder_recur(Node* x) {
		if (x != nullptr) {
			inorder_recur(x->getLeft());
			printf(" [%d] ", x->getData());
			inorder_recur(x->getRight());
		}
	}
	void preorder_recur(Node* x) { // problem 12.1-4, p290
		if (x != nullptr) {
			printf(" [%d] ", x->getData());
			preorder_recur(x->getLeft());
			preorder_recur(x->getRight());
		}
	} 
	void postorder_recur(Node* x) { // problem 12.1-4, p290
		if (x != nullptr) {
			postorder_recur(x->getLeft());
			postorder_recur(x->getRight());
			printf(" [%d] ", x->getData());
		}
	}
	// level tour º¸·ù
	// Search Node in Tree ------------------------------------------
	Node* search_recur(Node* x, int k) { // usually root on x, search root first
		if (x == nullptr || k == x->getData()) {
			if(k == x->getData())
				return x;
			else {
				cout << "fail....\n";
				return nullptr;
			}
		}
		if (k < x->getData())
			return search_recur(x->getLeft(), k);
		else return search_recur(x->getRight(), k);
	}
	Node* search_repeat(Node* x, int k) {
		while (x != nullptr && k != x->getData()) {
			if (k < x->getData())
				x = x->getLeft();
			else
				x = x->getRight();
		}
		if (x == nullptr) {
			cout << "search fail....\n";
			exit(-1);
		}
		else return x;
	}
	// Remove Node in Tree -----------------------------------------
	void transplant(Node* u, Node* v) {
		if (u->getParent() == nullptr)
			setRoot(v);
		else if (u == u->getParent()->getLeft())
			u->getParent()->setLeft(v);
		else u->getParent()->setRight(v);
		if (v != nullptr)
			v->setParent(u->getParent());
	}
	void remove(int k) {
		Node* z = search_recur(root, k);
		if (z->getLeft() == nullptr) {
			transplant(z, z->getRight());
		}
		else if (z->getRight() == nullptr) {
			transplant(z, z->getLeft());
		}
		else
		{
			Node* y = minimum(z->getRight());
			if (y->getParent() != z) {
				transplant(y, y->getRight());
				y->setRight(z->getRight());
				y->getRight()->setParent(y);
			}
			transplant(z, y);
			y->setLeft(z->getLeft());
			y->getLeft()->setParent(y);
		}
	}
	// Maximum or Minimum Node in Tree------------------------
	Node* maximum(Node* x) { // Find x the highest element by root
		while (x->getRight() != nullptr)
			x = x->getRight();
		return x;
	}
	Node* minimum(Node* x) {
		while (x->getLeft() != nullptr)
			x = x->getLeft();
		return x;
	}
	Node* max_recur(Node* x) { // problem 12.2-2, p294
		if (x->getRight() == nullptr)
			return x;
		max_recur(x->getRight());
	}
	Node* min_recur(Node* x) { // problem 12.2-2, p294
		if (x->getLeft() == nullptr)
			return x;
		min_recur(x->getLeft());
	}
	// successor or predecessor Node in Tree---------------------------------
	Node* successor(int k) {
		Node* x = search_recur(root, k);
		if (x->getRight() != nullptr)
			return minimum(x->getRight());
		Node* y = x->getParent();
		while (y != nullptr && x == y->getRight()) {
			x = y;
			y = y->getParent();
		}
		return x;
	} // smallest node greater than x
	Node* predecessor(int k) {
		Node* x = search_recur(root, k);
		if (x->getLeft() != nullptr)
			return maximum(x->getLeft());
		Node* y = x->getParent();
		while (y != nullptr && x == y->getLeft()) {
			x = y;
			y = y->getParent();
		}
	} // largest node less than x
	
};

#endif // !__BinarySearchTree__
/*
reference 1 : https://jeongw00.tistory.com/307
*/