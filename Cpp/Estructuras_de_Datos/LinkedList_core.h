#ifndef _LINKED_LIST_CORE_H_
#define _LINKED_LIST_CORE_H_

#include "LinkedList.h"

template <class T>
void LinkedList<T>::add(T data)
{
	Node *tmp = new Node(data);
	if(!tmp)
		std::cout<<"No Memory left"<< std::endl;

	tmp->next = head;
	head = tmp;
	++numElements;
}

template <class T>
T LinkedList<T>::peek()
{
	return head->data;
}

template <class T>
T LinkedList<T>::get(void)
{
	if(isEmpty())
	{
		std::cout << "Trying to get items from Empty List" << std::endl;
		return NULL;
	}

	Node *tmp = head;
	head = head->next;

	T value = tmp->data;

	free(tmp);
	numElements--;
	return value;
}

template <class T>
T LinkedList<T>::get(int index)
{
	Node *x = head;
	if(index > numElements)
	{
		std::cout<< "Index: " << index << "Is greater than the num of elements" <<std::endl;
		return NULL;
	}
	if(isEmpty())
	{
		std::cout << "Trying to get items from Empty List" << std::endl;
		return NULL;
	}

	for(int i = 0; i < numElements; ++i)
	{
		x = x->next;
		if(i == index)
		{
			numElements--;
			return x->data;
		}
	}

	std::cout << "Element is not in the LinkedList" << std::endl;
	return NULL;
}

template <class T>
bool LinkedList<T>::isEmpty(void)
{
	return (head == NULL)? true : false;
}

template <class T>
void LinkedList<T>::addToTail(T data)
{
	Node *tmp = new Node(data);
	Node *x = head;

	while(x->next != NULL)
		x = x->next;

	x->next = tmp;
}
#endif
