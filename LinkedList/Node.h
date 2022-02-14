#pragma once
#include <iostream>

template<typename T>
class Node
{
public:
	Node();
	Node(T value);

	T data;
	Node<T>* next;
	Node<T>* previous;

private:


};


template<typename T>
inline Node<T>::Node()
{
	data = 0;
	next = nullptr;
	previous = nullptr;
}

template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
	next = nullptr;
	previous = nullptr;
}


