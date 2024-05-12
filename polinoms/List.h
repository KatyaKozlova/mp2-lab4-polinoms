#pragma once
# include<iostream>
#include<vector>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* pNext;
	Node(T _val) : data(_val), pNext(nullptr) {}
	Node(T _val, Node* next) : data(_val), pNext(next) {}
};

template<typename T>
class myList {
	Node<T>* pFirst;
	size_t sz;
public:
	myList()
	{
		pFirst = nullptr;
		sz = 0;
	}
	myList(myList&& list) noexcept {
		pFirst = nullptr;
		swap(*this, list);
	}
	myList(const myList& list) :
		pFirst(nullptr), sz(list.sz) {
		if (list.pFirst == nullptr)
			return;
		Node<T>* pNew = pFirst = new Node<T>{ *list.pFirst };
		for (; pNew->pNext != nullptr; pNew = pNew->pNext)
			pNew->pNext = new Node<T>{ *pNew->pNext };
	}
	myList& operator=(const myList& list) {
		if (this != &list) {
			while (pFirst != nullptr) {
				Node<T>* p = pFirst;
				pFirst = pFirst->pNext;
				delete p;
			}

			for (Node<T>* node = list.pFirst; node != nullptr; node = node->pNext) {
				pushFront(node->data);
			}
		}
		return *this;
	}
	myList& operator=(myList&& list) noexcept {
		swap(*this, list);
		return *this;
	}
	~myList() {
		Node<T>* p;
		while (pFirst != nullptr) {
			p = pFirst;
			pFirst = pFirst->pNext;
			delete p;
		}
	}
	size_t size() const noexcept {
		return sz;
	}
	bool IsEmpty() const noexcept {
		return sz == 0;
	}
	T& Front() noexcept {
		return pFirst->data;
	}
	Node<T>* FrontNode() {
		return pFirst;
	}
	void pushFront(const T& val) {
		Node<T>* node = new Node<T>{ val, pFirst };
		pFirst = node;
		sz++;
	}
	void popFront() {
		if (IsEmpty()) throw "list is empty";
		Node<T>* p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		sz--;
	}
	Node<T>* ToPos(size_t pos) {
		if (sz <= pos) throw "size < pos";
		Node<T>* current = pFirst;
		for (size_t i = 0; i < pos; ++i) {
			current = current->pNext;
		}
		return current;
	}
	T& operator[](size_t pos) {
		Node<T>* p = ToPos(pos);
		return p->data;
	}
	void pushAfter(size_t pos, const T& val) {
		Node<T>* p = ToPos(pos);
		Node<T>* pNew = new Node<T>( val, p->pNext );
		p->pNext = pNew;
		sz++;
	}
	void eraseAfter(size_t pos) {
		if (IsEmpty()) throw "list is empty";
		Node<T>* p = ToPos(pos);
		Node<T>* pDel = p->pNext;
		p->pNext = pDel->pNext;
		delete pDel;
		sz--;
	}
	void addNode(T d)
	{
		Node<T>* nd = new Node<T>(d);   
		if (pFirst == nullptr)     
			pFirst = nd;
		else                 
		{
			Node<T>* current = pFirst;
			while (current->pNext != nullptr)
				current = current->pNext;
			current->pNext = nd;
		}
		sz++;
	}

	void removeZeroCoefficient() {
		Node<T>* current = pFirst;
		Node<T>* prev = nullptr;
		while (current != nullptr) {
			if (current->data.coef == 0) {
				if (prev == nullptr) {
					pFirst = current->pNext;
					delete current;
					current = pFirst;
				}
				else {
					prev->pNext = current->pNext;
					delete current;
					current = prev->pNext;
				}
			}
			else {
				prev = current;
				current = current->pNext;
			}
		}
	}
};
