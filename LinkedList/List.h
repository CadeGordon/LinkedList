#pragma once
#include <iostream>
#include "Iterator.h"

template<typename T>
class List
{
public:

	//creates a new list with no data
	List();

	//creates a new list using the same elements from another list
	List(const List<T>& other);

	//destroys the list using destroy function
	~List();

	//deletes all elemtnts of a list
	void destroy();

	//Creates a new iterator that points to teh first node
	const Iterator<T> begin();

	//creates a ew iterator that points to the last node
	Iterator<T> const end();

	//finds out where or not a specific item could be found
	bool const contains(const T object);

	//adds a node to the front of the list
	void pushFront(const T& value);

	//adds a node to the back of the list
	void pushBack(const T& value);

	//insersts a new node in to the index if it is valid
	bool insert(const T& value, int index);

	//removes node of the given value from the list
	bool remove(const T& value);

	//prints each element that is apart of the lsit
	void const print();

	//sets the frist and last node to nothing
	void initialize();

	//sees if the list has any elements
	bool const isEmpty();

	//sets the iterator to point at the index
	bool getData(Iterator<T>& iter, int index);

	//finds the number of nodes in teh list
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
	//creates an empty list
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
	//Destroys the list
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	//Sets current node and next node for iterating
	Node<T>* currentNode = m_first;
	Node<T>* nextNode;

	//for the length of the list
	for (int i = 0; i < m_nodeCount; i++) 
	{
		//deletes each node and moves on to the next
		nextNode = currentNode->next;
		delete currentNode;
		m_nodeCount--;
		currentNode = nextNode;
	}
	initialize();
}

template<typename T>
inline const Iterator<T> List<T>::begin()
{
	//Return the first node in the list
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
	//Sets current node for iterating
	Node<T>* currentNode = m_first;

	//for the length of the list
	for (int i = 0; i < m_nodeCount; i++) 
	{
		//if the current node is the object we need to find
		if (currentNode->data == object) 
		{
			//set that the object has been found
			itemFound = true;
		}
		currentNode = currentNode->next;
	}
	//return the object found bool
	return itemFound;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//Creates a new node with the given value
	Node<T> * newNode = new Node<T>(value);
	//if the first node is null
	if (m_first != nullptr)
		//set the new nodes next to be the first
		newNode->next = m_first;
	//Sets the new node as the first node
	m_first = newNode;
	//if the newnode next is not null
	//meaning that this is not the root
	if (newNode->next != nullptr)
		newNode->next->previous = newNode;
	else
		//set the last node to be the new node
		m_last = newNode;
	//Increases the node count
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//Creates a new node with the given value
	Node<T>* newNode = new Node<T>(value);
	//Sets the new nodes previous to be the last node
	newNode->previous = m_last;
	//Sets the new node to be the last
	m_last = newNode;
	//if the last nodes previous is not null
	//meaning that it is not the root
	if (newNode->previous != nullptr)
		//set the new nodes previous next to be the new node
		newNode->previous->next = newNode;
	else
		//set the first node to be the new node
		m_first = newNode;
	//Increases the node count
	m_nodeCount++;

}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	//Create a bool to return
	bool nodeInserted = false;
	//Two temp variables to use to insert the new node
	Node<T>* newNode = new Node<T>(value);
	Node<T>* currentNode = m_first;
	//If the index is 0
	if (index > getLength())
		return nodeInserted;
	//Make a new node at the front
	if (index == 0)
	{
		//Make a new node at the front
		pushFront(value);
		return true;
	}
	//If the index is at the end of the list
	else if (index == m_nodeCount)
	{
		//Make a new node at the back
		pushBack(value);
		return true;
	}
		
	//Loop through the list to get the the index
	for (int i = 0; i < index; i++)
		currentNode = currentNode->next;
	//Set the new nodes next and previous
	newNode->next = currentNode;
	newNode->previous = currentNode->previous;
	//Set the current nodes previous next
	currentNode->previous->next = newNode;
	//Set the current nodes previous
	currentNode->previous = newNode;

	m_nodeCount++;
	return nodeInserted;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	//Create a bool to return
	bool objectRemoved = false;
	//Two temp variables to use to insert the new node
	Node<T>* nodeToRemove = m_first;

	for (int i = 0; i < m_nodeCount; i++) 
	{
		
		if (nodeToRemove->data == value) 
		{
			if (nodeToRemove->next != nullptr)
				nodeToRemove->next->previous = nodeToRemove->previous;
			else
				m_last = nodeToRemove->previous;
			if (nodeToRemove->previous != nullptr)
				nodeToRemove->previous->next = nodeToRemove->next;
			else
				m_first = nodeToRemove->next;
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
	//Set a new node to be the first
	Node<T>* currentNode = m_first;

	for (int i = 0; i < getLength(); i++)
		//If the current node is not null
		if (currentNode != nullptr)
		{
			//Print out the data for every node
			std::cout << currentNode->data << std::endl;
			currentNode = currentNode->next;
		}
}

template<typename T>
inline void List<T>::initialize()
{
	//Sets all variables to be base
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool const List<T>::isEmpty()
{
	return (m_first == nullptr && m_last == nullptr && m_nodeCount == 0);

}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	//if the index is outside of the bounds return false
	if (index <= 0 || index > getLength())
		return false;

	//set the iter to look at the first node
	Iterator<T> tempIterator = begin();

	//for the number of the index
	for (int i = 0; i < getLength(); i++)
	{
		//cycle through until the iter is pointing at the correct node
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
	//return the number of nodes
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	//destroy the list and create a node for iterating
	destroy();
	Node<T>* currentNode = otherList.m_first;
	//for the length of the other list
	for (int i = 0; i < otherList.m_nodeCount; i++) 
	{
		//insert the nodes at the same points in the new list as the other list and iterate
		insert(currentNode->data, i);
		currentNode = currentNode->next;
	}
	return *this;
}

template<typename T>
inline void List<T>::sort()
{
	//Set a current node and temp node to iterate
	Node<T>* currentNode = m_first;
	Node<T>* tempNode = new Node<T>();

	//for the number of nodes minus 1
	for (int i = 0; i < m_nodeCount - 1; i++) 
	{
		//set the current node back to the first one on every loop
		currentNode = m_first;
		for (int j = 0; j < m_nodeCount - 1; j++) 
		{
			//if the currents next is less than the current
			if (currentNode->data > currentNode->next->data) 
			{
				//Swap the nodes data
				tempNode->data = currentNode->next->data;
				currentNode->next->data = currentNode->data;
				currentNode->data = tempNode->data;
			}
			currentNode = currentNode->next;
		}

	}
}



