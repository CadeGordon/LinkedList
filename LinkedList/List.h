#pragma once
#include <iostream>
#include "Iterator.h"

template<typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();
	void destroy();
	const Iterator<T> begin();
	Iterator<T> const end();
	bool const contains(const T object);
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);
	void const print();
	void initialize();
	bool const isEmpty();
	bool getData(Iterator<T>& iter, int index);
	int const getLength();
	const List<T>& operator = (const List<T>& otherList);
	void sort();

private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;

};

template<typename T>
inline List<T>::List()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	m_first = other.m_first;
	m_last = other.m_last;
	m_nodeCount = other.m_nodeCount;
}

template<typename T>
inline List<T>::~List()
{
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	for (Iterator<T> iter = begin(); iter.operator* != nullptr; iter++)
		delete iter.operator*;
}

template<typename T>
inline const Iterator<T> List<T>::begin()
{
	return Iterator<T>(m_first);
}

template<typename T>
inline Iterator<T> const List<T>::end()
{
	return Iterator<T>(m_last);
}

template<typename T>
inline bool const List<T>::contains(const T object)
{
	bool itemFound = false;
	Node<T>* currentNode = m_first;
	for (int i = 0; i < m_nodeCount; i++) {
		if (currentNode->data == object) {
			itemFound = true;
		}
		currentNode = currentNode->next;
	}

	return itemFound;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T> * newNode = new Node<T>(value);
	if (m_first != nullptr)
		newNode->next = m_first;
	m_first = newNode;
	if (newNode->next != nullptr)
		newNode->next->previous = newNode;
	else
		m_last = newNode;

	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	newNode->previous = m_last;
	m_last = newNode;
	if (newNode->previous != nullptr)
		newNode->previous->next = newNode;
	else
		m_first = newNode;

	m_nodeCount++;

}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	bool nodeInserted = false;
	Node<T>* newNode = new Node<T>(value);
	Node<T>* currentNode = m_first;
	if (index >= getLength())
		return nodeInserted;

	if (index == 0)
		pushFront(value);
	else if (index == m_nodeCount)
		pushBack(value);

	for (int i = 0; i < index; i++)
		currentNode = currentNode->next;

	newNode->next = currentNode;
	newNode->previous = currentNode->previous;
	currentNode->previous->next = newNode;
	currentNode->previous = newNode;

	m_nodeCount++;
	return nodeInserted;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	return false;
}

template<typename T>
inline void const List<T>::print()
{
	return NULL;
}

template<typename T>
inline void List<T>::initialize()
{
}

template<typename T>
inline bool const List<T>::isEmpty()
{
	return NULL;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	return false;
}

template<typename T>
inline int const List<T>::getLength()
{
	return NULL;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::sort()
{
}



