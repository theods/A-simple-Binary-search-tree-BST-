#ifndef BSTTEMP_H
#define BSTTEMP_H
#include <iostream>
#include <string>

using namespace std;

template <class T>
struct nodeType { //represents the node
	T info;
	nodeType<T>* lLink;
	nodeType<T>* rLink;
};

template <class T>
class BSTtemp {
public:
	BSTtemp();
	~BSTtemp();
	//bool search(const int i) const;
	void Insert(T i);
	bool isEmpty();
	void inorderTraversal() const;
	void preorderTraversal() const;
	void postorderTraversal() const;
	void destroy(nodeType<T>* &p);
private:
	void inorder(nodeType<T>* p) const;
	void preorder(nodeType<T>* p) const;
	void postorder(nodeType<T>* p) const;
	nodeType<T>* root;
};

template <class T>
BSTtemp<T>::BSTtemp() {
	root = NULL;
}

template <class T>
BSTtemp<T>::~BSTtemp() {
	destroy(root);
}

template <class T>
void BSTtemp<T>::destroy(nodeType<T>* &p) {
	if (p != NULL) {
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = NULL;
	}
}

template <class T>
void BSTtemp<T>::Insert(T i) {
	nodeType<T>* newNode = new nodeType<T>;
	nodeType<T>* trailCurrent = NULL;
	nodeType<T>* current;

	//setting the newNode values
	newNode->info = i;
	newNode->lLink = NULL;
	newNode->rLink = NULL;

	if (isEmpty() == true) {
		root = newNode;
	}
	else {
		current = root;

		//Find the node's trailCurrent. Find where there is appropriate space
		while (current != NULL) {
			trailCurrent = current;
			if (i == current->info) {
				cout << i << "Item already inserted! No duplicates allowed" << endl;
				return;
			}
			else if (i > current->info) {
				current = current->rLink;
			}
			else {
				current = current->lLink;
			}
		} //endwhile
		if (i > trailCurrent->info) {
			trailCurrent->rLink = newNode;
			cout << newNode->info << " Inserted!" << endl; //not needed (for testing only)
		}
		else {
			trailCurrent->lLink = newNode;
			cout << newNode->info << " Inserted!" << endl; //not needed (for testing only)
		}
	}
}

template <class T>
bool BSTtemp<T>::isEmpty() {
	return (root == NULL);
}

template <class T>
void BSTtemp<T>::inorderTraversal() const {
	inorder(root);
}

template <class T>
void BSTtemp<T>::inorder(nodeType<T>* p) const {
	if (p != NULL) {
		inorder(p->lLink);
		cout << p->info << " ";
		inorder(p->rLink);
	}
}

template <class T>
void BSTtemp<T>::preorderTraversal() const {
	preorder(root);
}

template <class T>
void BSTtemp<T>::preorder(nodeType<T>* p) const {
	if (p != NULL) {
		cout << p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}

template <class T>
void BSTtemp<T>::postorderTraversal() const {
	postorder(root);
}

template <class T>
void BSTtemp<T>::postorder(nodeType<T>* p) const {
	if (p != NULL) {
		postorder(p->lLink);
		postorder(p->rLink);
		cout << p->info << " ";
	}
}
#endif