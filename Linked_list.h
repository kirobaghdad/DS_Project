#pragma once
#include "Node.h"

template<typename T>
class Linked_list
{
	Node<T>* Header;
	int count;
	Node<T>* getpointerto(const Node<T>& N);
public:
	Linked_list();
	~Linked_list();
	int getcurrentsize()const;
	bool isEmpty();
	bool add(const T& newItem);
	bool remove(const T& Item);
	void clear();
	int getfrequencyof(const T& Item);
	bool contain(const T& Item);
	Node<T>* getHeader()const;
	void PrintList()const;
	void setHeader(Node<T>* n);
};


template<typename T>
Node<T>* Linked_list<T>::getpointerto(const Node<T>& N)
{
	Node<T>* currptr = Header;
	while (currptr)
	{
		if (currptr->getData() == N.getData())
		{
			return currptr;
		}
		else
		{
			currptr = currptr->getNext();
		}
	}

	return nullptr;
}

template<typename T>
inline Linked_list<T>::Linked_list()
{
	Header = nullptr;
	count = 0;
}

template<typename T>
Linked_list<T>::~Linked_list()
{
	delete Header;
}

template<typename T>
int Linked_list<T>::getcurrentsize() const
{
	return count;
}

template<typename T>
bool Linked_list<T>::isEmpty()
{
	if (Header)
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
	temp->setData(newItem);
	temp->setNext(Header);
	Header = temp;
	count++;
	return true;
}

template<typename T>
bool Linked_list<T>::remove(const T& Item)
{
	Node<T>* ptr = getpointerto(Item);
	bool canremove = !isEmpty() && ptr != nullptr;
	if (canremove)
	{
		ptr->setData(Header->getData());
		Node<T>* todelete = Header;
		Header = Header->getNext();
		todelete->setNext(nullptr);
		delete todelete;
		count--;
	}
	return canremove;
}

template<typename T>
void Linked_list<T>::clear()
{
	Node<T>* curptr = Header;
	while (curptr)
	{
		Header = Header->getNext();
		delete curptr;
		curptr = Header;
	}
	count = 0;
}

template<typename T>
int Linked_list<T>::getfrequencyof(const T& Item)
{
	Node<T>* ptr = Header;
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
	return (getpointerto(Item) != nullptr);
}

template<typename T>
inline Node<T>* Linked_list<T>::getHeader()const
{
	return Header;
}

template<typename T>
inline void Linked_list<T>::PrintList() const
{
	cout << "\nprinting list contents:\n\n";
	Node<T>* p = Header;

	while (p)
	{
		cout << "[ " << p->getData() << " ]";
		cout << "--->";
		p = p->getNext();
	}
	cout << "NULL\n";
}

template<typename T>
inline void Linked_list<T>::setHeader(Node<T>* n)
{
	Header = n;
}


