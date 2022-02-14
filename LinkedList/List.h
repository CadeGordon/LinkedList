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
	for (int i = 0; i < m_nodeCount; i++) 
	{
		if (currentNode->data == object) 
		{
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
	bool objectRemoved = false;
	Node<T>* nodeToRemove = m_first;
	for (int i = 0; i < m_nodeCount; i++) 
	{
		if (nodeToRemove->data == value) 
		{
			nodeToRemove->next->previous = nodeToRemove->previous;
			nodeToRemove->previous->next = nodeToRemove->next;
			delete nodeToRemove;
			m_nodeCount--;
			break;
		}
		nodeToRemove = nodeToRemove->next;
	}

	return objectRemoved;
}

template<typename T>
inline void const List<T>::print()
{
	Node<T>* currentNode = m_first;

	for (int i = 0; i < getLength(); i++)
		if (currentNode != nullptr)
		{
			std::cout << currentNode->data << std::endl;
			currentNode = currentNode->next;
		}
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool const List<T>::isEmpty()
{
	if (m_last == nullptr && m_last == nullptr && m_nodeCount = 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	if (index <= 0 || index > getLength())
		return false;

	Iterator<T> tempIterator = begin();

	for (int i = 0; i < getLength(); i++)
	{
		if (tempIterator == iter)
		{
			++iter;
		}
		++tempIterator;
	}

	return true;
}

template<typename T>
inline int const List<T>::getLength()
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	destroy();
	Node<T>* currentNode = otherList.m_first;
	for (int i = 0; i < otherList.m_nodeCount; i++) 
	{
		insert(currentNode->data, i);
		currentNode = currentNode->next;
	}
	return *this;
}

template<typename T>
inline void List<T>::sort()
{
	Node<T>* currentNode = m_first;
	Node<T>* tempNode = new Node<T>();

	for (int i = 0; i < m_nodeCount - 1; i++) 
	{
		currentNode = m_first;
		for (int j = 0; j < m_nodeCount - 1; j++) 
		{
			if (currentNode->data > currentNode->next->data) 
			{
				tempNode->data = currentNode->next->data;
				currentNode->next->data = currentNode->data;
				currentNode->data = tempNode->data;
			}
			currentNode = currentNode->next;
		}

	}
}



