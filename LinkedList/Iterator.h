#pragma once
#include <iostream>
#include "Node.h"

template<typename T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<T>* node);

	Iterator<T> operator ++();
	Iterator<T> operator --();
	const bool operator ==(const Iterator<T>& iter);
	const bool operator !=(const Iterator<T>& iter);
	T operator*();

private:
	Node<T> m_current;
};

//  Creates a new iterator with no current node.
template<typename T>
inline Iterator<T>::Iterator()
{
	m_current = nullptr;
}

// Creates a new iterator pointing to a certain node.
template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

// sees if there is an  index next in the list
template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	if (m_current->next == nullptr)
		return Iterator<T>(m_current);
	else
		return Iterator<T>(m_current = m_current->next);
}

//sees if there is a previous index in the list
template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	if (m_current->previous == nullptr)
		return Iterator<T>(m_current);
	else
		return Iterator<T>(m_current = m_current->previous);
}

//sees if two iterators have the same node
template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return m_current->data == iter.m_current->data &&
		m_current->next == iter.m_current->next &&
		m_current->previous == iter.m_current->previous;
}

//sees if two iterators have a different node
template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return m_current->data != iter.m_current->data ||
		m_current->next != iter.m_current->next ||
		m_current->previous != iter.m_current->previous;
}

// if a node is pointing to an iterator retunr the data
template<typename T>
inline T Iterator<T>::operator*()
{
	return T(m_current->data);
}
