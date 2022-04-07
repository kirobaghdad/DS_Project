#pragma once

#include"Cargo.h"
#include "Node.h"
#include "QueueADT.h"
#include <vector>
using namespace std;


template <typename T>
class LinkedQueue :public QueueADT<T>
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~LinkedQueue();

	
	LinkedQueue(const LinkedQueue<T>& LQ);
	Node<T>* getFrontptr() const;
	bool remove(const int ID);
};

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

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

template<typename T>
inline Node<T>* LinkedQueue<T>::getFrontptr() const
{
	return frontPtr;
}


inline bool LinkedQueue<Cargo>::remove(const int ID)
{
	if (isEmpty())
		return false;

	Node<Cargo>* ptr = frontPtr;
	if (ptr->getItem().getID() == ID)
	{
		frontPtr = frontPtr->getNext();

		if (ptr == backPtr)
			backPtr = nullptr;
		return true;
	}
	ptr = ptr->getNext();
	Node<Cargo>* prev = frontPtr;
	while (ptr)
	{
		if (ptr->getItem().getID() == ID)
		{
			prev->setNext(ptr->getNext());
			return true;
		}
		ptr = ptr->getNext();
		prev = prev->getNext();
	}
	return false;
}

