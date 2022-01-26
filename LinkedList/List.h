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
	const Iterator<T> being();
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
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::destroy()
{
}

template<typename T>
inline const Iterator<T> List<T>::being()
{
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> const List<T>::end()
{
	return NULL;
}

template<typename T>
inline bool const List<T>::contains(const T object)
{
	return NULL;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	return false;
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



