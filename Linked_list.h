#pragma once
#include "Node.h"

template<typename T>
class Linked_list
{
	Node<T>* Head;
	int count;
public:
	Linked_list();
	~Linked_list();
	int getcurrentsize()const;
	bool isEmpty();
	bool add(const T& newItem);
	bool removeID(const int ID);
	bool removeBeg(T& frntEntry);
	void clear();
	int getfrequencyof(const T& Item);
	bool contain(const T& Item);
	Node<T>* getHead()const;
	void print();
};


template<typename T>
void Linked_list <T>::print()
{
	Node<T>* ptr = Head;
	while (ptr)
	{
		cout << ptr->getItem() << ",";
		if (ptr->getNext() != NULL)
			cout << ",";
		ptr = ptr->getNext();
	}
}



template<typename T>
inline Linked_list<T>::Linked_list()
{
	Head = nullptr;
	count = 0;
}

template<typename T>
Linked_list<T>::~Linked_list()
{
	delete Head;
}

template<typename T>
int Linked_list<T>::getcurrentsize() const
{
	return count;
}

template<typename T>
bool Linked_list<T>::isEmpty()
{
	if (Head)
	{
		return false;
	}
	else
		return true;
}

template<typename T>
bool Linked_list<T>::add(const T& newItem)
{
	Node<T>* temp = new Node<T>();
	temp->setItem(newItem);
	temp->setNext(nullptr);
	Node<T>* ptr = Head;
	if (isEmpty())
	{
		Head = temp;
		count++;
		return true;
	}
	while (ptr->getNext())
	{
		ptr = ptr->getNext();
	}
	ptr->setNext(temp);
	count++;
	return true;
}

template<typename T>
bool Linked_list<T>::removeID(const int ID)
{
	if (isEmpty())
	{
		return false;
	}

	if (Head->getItem() == ID)
	{
		Node<Cargo>* todelete = Head;
		Head = Head->getNext();
		delete todelete;
		count--;
		return true;
	}

	bool found = false;

	Node<T>* ptr = Head->getNext();
	Node<T>* prev = Head;
	while (ptr && !found)
	{
		if (ptr->getItem().getID() == ID)
		{
			found = true;
		}
		else
		{
			ptr = ptr->getNext();
			prev = prev->getNext();
		}
	}
	if (found)
	{
		prev->setNext(ptr->getNext());
		delete ptr;
		count--;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline bool Linked_list<T>::removeBeg(T& Item)
{
	if (isEmpty())
	{
		return false;
	}
	Node<T>* todelete = Head;
	Item = todelete->getItem();
	Head = Head->getNext();
	delete todelete;
	count--;
}

template<typename T>
void Linked_list<T>::clear()
{
	Node<T>* curptr = Head;
	while (curptr)
	{
		Head = Head->getNext();
		delete curptr;
		curptr = Head;
	}
	count = 0;
}

template<typename T>
int Linked_list<T>::getfrequencyof(const T& Item)
{
	Node<T>* ptr = Head;
	int f = 0;
	while (ptr)
	{
		if (ptr->getData() == Item)
		{
			f++;
		}
		ptr = ptr->getNext();
	}
	return f;
}

template<typename T>
bool Linked_list<T>::contain(const T& Item)
{
	Node<T>* ptr = Head;
	bool found = false;
	while (ptr&&!found)
	{
		if (ptr->getData() == Item)
		{
			found = true;
		}
		else
		{
			ptr = ptr->getNext();
		}
	}
	return (found);
}

template<typename T>
inline Node<T>* Linked_list<T>::getHead() const
{
	return Head;
}
