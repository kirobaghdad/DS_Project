#pragma once

template<typename T>
class Node
{
	T Data;
	Node* ptr;
public:
	Node();
	Node(const T& d);
	Node(const T& d, const Node* N);
	~Node();
	void setData(const T& d);
	void setNext(Node* N);
	T getData() const;
	Node<T>* getNext() const;

};



template<typename T>
inline Node<T>::Node()
{
}

template<typename T>
inline Node<T>::Node(const T& d)
{
	Data = d;
	ptr = nullptr;
}

template<typename T>
Node<T>::Node(const T& d, const Node* N)
{
	Data = d;
	ptr = N;
}

template<typename T>
Node<T>::~Node()
{
	delete ptr;
}


template<typename T>
void Node<T>::setData(const T& d)
{
	Data = d;
}

template<typename T>
void Node<T>::setNext(Node* N)
{
	ptr = N;
}

template<typename T>
T Node<T>::getData() const
{
	return Data;
}



template<typename T>
Node<T>* Node<T>::getNext() const
{
	return ptr;
}