#pragma once

template <typename T>
class PriorityNode
{
	T item;
	
	PriorityNode<T>* next;
public:
	int priority;
	void setItem(const T& r_Item);
	void setNext(PriorityNode<T>* nextNodePtr);
	T getItem() const;
	PriorityNode<T>* getNext() const;
};



template < typename T>
void PriorityNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void PriorityNode<T>::setNext(PriorityNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < typename T>
T PriorityNode<T>::getItem() const
{
	return item;
}

template < typename T>
PriorityNode<T>* PriorityNode<T>::getNext() const
{
	return next;
}
