#pragma once

template <typename T>
class PriorityNode
{
	T item;
	PriorityNode<T>* next;
public:
	float priority;
	PriorityNode();
	PriorityNode(const T& r_Item);
	PriorityNode(const T& r_Item, PriorityNode<T>* nextNodePtr);


	void setItem(const T& r_Item);
	void setNext(PriorityNode<T>* nextNodePtr);
	T& getItem() ;
	PriorityNode<T>* getNext() const;
};

template < typename T>
PriorityNode<T>::PriorityNode()
{
	next = nullptr;
}

template < typename T>
PriorityNode<T>::PriorityNode(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template < typename T>
PriorityNode<T>::PriorityNode(const T& r_Item, PriorityNode<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}

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
T& PriorityNode<T>::getItem() 
{
	return item;
}

template < typename T>
PriorityNode<T>* PriorityNode<T>::getNext() const
{
	return next;
}
