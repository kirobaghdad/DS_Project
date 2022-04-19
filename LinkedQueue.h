#pragma once

#include"Cargo.h"
#include "Node.h"
#include "QueueADT.h"
#include<iostream>
using namespace std;


template <typename T>
class LinkedQueue :public QueueADT<T>
{
private:
	int count;
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~LinkedQueue();
	int GetCount();

	LinkedQueue(const LinkedQueue<T>& LQ);
	void print();
};

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	count = 0;
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
int LinkedQueue<T>::GetCount() 
{
	return count;
}

template<typename T>
void LinkedQueue<T>::print()
{
	Node<T>* ptr = frontPtr;
	while (ptr)
	{
		cout << ptr->getItem() << ",";
		ptr = ptr->getNext();
	}
}


template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}


template <typename T>
bool LinkedQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);

	if (isEmpty())
		frontPtr = newNodePtr;
	else
		backPtr->setNext(newNodePtr);

	backPtr = newNodePtr;
	count++;
	return true;

}




template <typename T>
bool LinkedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if (nodeToDeletePtr == backPtr)
		backPtr = nullptr;

	delete nodeToDeletePtr;
	count--;
	return true;

}

template <typename T>
bool LinkedQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	T temp;

	while (dequeue(temp));
}


template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
{
	Node<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	Node<T>* ptr = new Node<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();


	while (NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}

