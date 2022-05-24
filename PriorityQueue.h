#pragma once
#include"PriorityNode.h"

using namespace std;



template <typename T>
class PriorityQueue
{
private:
	float count;
	PriorityNode<T>* backPtr;
	PriorityNode<T>* frontPtr;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, float p);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~PriorityQueue();
	float GetCount();
	PriorityQueue(const PriorityQueue<T>& LQ);
	void print();

};

template<typename T>
void PriorityQueue<T>::print()
{
	PriorityNode<T>* ptr = frontPtr;
	while (ptr)
	{
		cout << ptr->getItem();
		if (ptr->getNext() != NULL)
			cout << ", ";
		ptr = ptr->getNext();
	}
}

template <typename T>
float PriorityQueue<T>::GetCount()
{
	return count;
}



template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	count = 0;
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
bool PriorityQueue<T>::enqueue(const T& newEntry, float p)
{

	PriorityNode<T>* start = frontPtr;
	// Create new Node
	PriorityNode<T>* temp = new PriorityNode<T>;
	temp->setItem(newEntry);
	temp->priority = p;

	if (isEmpty())
	{
		frontPtr = temp;
		backPtr =  temp;
		count++;
		temp->setNext(NULL);
		return true;
	}

	if (frontPtr->priority < p)
	{
		// Insert New Node before head
		temp->setNext(frontPtr);
		frontPtr = temp;
	}
	else
	{
		// Traverse the list and find a
		// position to insert new node
		if (frontPtr==backPtr)
		{
			if (frontPtr->priority < p)
			{
				temp->setNext(backPtr);
				frontPtr = temp;
				count++;
				return true;
			}
			else
			{
				backPtr = temp;
				temp->setNext(nullptr);
				frontPtr->setNext(backPtr);
				count++;
				return true;
			}
		}
		while (start->getNext() != nullptr && start->getNext()->priority >= p)
		{
			start = start->getNext();
		}
		// Either at the ends of the list
		// or at required position
		temp->setNext(start->getNext());
		start->setNext(temp);
	}
	count++;
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
	count--;
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
	count =LQ.count;
	PriorityNode<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	PriorityNode<T>* ptr = new PriorityNode<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();


	while (NodePtr)
	{
		PriorityNode<T>* ptr = new PriorityNode<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}



