#ifndef _LINKED_LIST_CORE_H_
#define _LINKED_LIST_CORE_H_

#include "LinkedList.h"

template <class T>
void LinkedList<T>::push_front(const T& data)
{
	Node *tmp = new Node(data);
	if(!tmp)
	{
		std::cout<<"No Memory left"<< std::endl;
		return;
	}

	if(isEmpty())
	{
		tail = tmp;
	}
	tmp->next = head;
	head = tmp;
	++numElements;
}

template <class T>
T LinkedList<T>::peek_front()
{
	return head->data;
}

template <class T>
T LinkedList<T>::peek_back()
{
	return tail->data;
}

template <class T>
T LinkedList<T>::pop_front(void)
{
	if(isEmpty())
	{
		std::cout << "Trying to get items from Empty List" << std::endl;
		return T();
	}

	Node *tmp = head;
	head = head->next;

	T value = tmp->data;

	free(tmp);
	numElements--;
	return value;
}
template <class T>
T LinkedList<T>::pop_back()
{
	if(isEmpty())
	{
		std::cout << "Trying to get items from Empty List" << std::endl;
		return T();
	}

	auto *x = head;
	auto *tmp = tail;
	auto val = tail->data;

	while(x->next != tail)
		x = x->next;

	tail=x;
	tail->next = nullptr;
	free(tmp);
	return val;
}

template <class T>
T LinkedList<T>::getAt(const int index)
{
	Node *x = head;
	if(index > numElements)
	{
		std::cout<< "Index: " << index << "Is greater than the num of elements" <<std::endl;
		return T();
	}
	if(isEmpty())
	{
		std::cout << "Trying to get items from Empty List" << std::endl;
		return T();
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
	return T();
}

template <class T>
bool LinkedList<T>::isEmpty(void)
{
	return (head == NULL);
}

template <class T>
void LinkedList<T>::push_back(const T &data)
{
	Node *tmp = new Node(data);
	Node *x = head;

	if(isEmpty())
	{
		tail = tmp;
		head = tail;
		return;
	}

	tail->next = tmp;
	tail = tmp;
}

template <class T>
std::ostream& operator <<(std::ostream& is, const LinkedList<T>& l)
{
	auto *x = l.head;

	while(x){
		is<<x->data<<" ";
		x= x->next;
	}

	return is;
}
#endif
