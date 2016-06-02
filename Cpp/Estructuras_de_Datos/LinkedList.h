#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <iostream>

template<class T>
class LinkedList;

template<class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& l);

template <class T>
class LinkedList
{
	public:
		void push_back(const T& data);
		void push_front(const T& data);
		T getIndexFromEnd(const int index);
		T peek_front();
		T peek_back();
		T pop_front();
		T pop_back();
		T getAt(int index);
		bool isEmpty();
		int Size(void) { return numElements; }
		friend std::ostream& operator<< <T>(std::ostream& os, const LinkedList& l);
		LinkedList():head(NULL), tail(NULL), numElements(0) {}
	private:
		class Node
		{
			friend class LinkedList<T>;
			friend std::ostream& operator<< <T>(std::ostream& os, const LinkedList& l);
			public:
			Node(const T& d): data(d), next(nullptr){}
			private:
			T data;
			Node *next;
		};

		Node *head;
		Node *tail;
		int numElements;
};
#endif
