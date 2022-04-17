#pragma once
#include"PriorityNode.h"
using namespace std;



template <typename T>
class PriorityQueue
{
private:

	PriorityNode<T>* backPtr;
	PriorityNode<T>* frontPtr;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, int p);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~PriorityQueue();


	PriorityQueue(const PriorityQueue<T>& LQ);
	PriorityNode<T>* getFrontptr() const;
	bool remove(const int ID);
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}


template <typename T>
bool PriorityQueue<T>::enqueue(const T& newEntry, int p)
{

	PriorityNode<T>* start = frontPtr;

	// Create new Node
	PriorityNode<T>* temp = new PriorityNode<T>;
	temp->setItem(newEntry);
	temp->priority = p;

	// Special Case: The head of list has
	// lesser priority than new node. So
	// insert newnode before head node
	// and change head node.

	if (isEmpty())
	{
		frontPtr = temp;
		return true;
	}
	
		if (frontPtr->priority > p)
		{
			// Insert New Node before head
			temp->setNext(frontPtr);
			frontPtr = temp;
		}
	
	else
	{
		// Traverse the list and find a
		// position to insert new node
		while (start->getNext() != nullptr && start->getNext()->priority < p)
		{
			start = start->getNext();
		}
		// Either at the ends of the list
		// or at required position
		temp->setNext(start->getNext());
		start->setNext(temp);
	}
	return true;
}



template <typename T>
bool PriorityQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	PriorityNode<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if (nodeToDeletePtr == backPtr)
		backPtr = nullptr;


	delete nodeToDeletePtr;

	return true;

}

template <typename T>
bool PriorityQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	T temp;

	while (dequeue(temp));
}


template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& LQ)
{
	PriorityNode<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr)
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	PriorityNode<T>* ptr = new Node<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();


	while (NodePtr)
	{
		PriorityNode<T>* ptr = new Node<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}

template<typename T>
inline PriorityNode<T>* PriorityQueue<T>::getFrontptr() const
{
	return frontPtr;
}

template <typename T>
inline bool PriorityQueue<T>::remove(const int ID)
{
	if (isEmpty())
		return false;

	PriorityNode<Cargo>* ptr = frontPtr;
	if (ptr->getItem().getID() == ID)
	{
		frontPtr = frontPtr->getNext();

		if (ptr == backPtr)
			backPtr = nullptr;
		return true;
	}
	ptr = ptr->getNext();
	PriorityNode<Cargo>* prev = frontPtr;
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

