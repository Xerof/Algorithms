#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template <class T>
class LinkedList
{
	public:
		void add(T data);
		T peek();
		T get();
		T get(int index);
		bool isEmpty();
		void addToTail(T data);
		LinkedList():head(NULL), tail(NULL), numElements(0) {}
	private:
		struct Node
		{
			T data;
			Node *next;
			Node(const T& d): data(d), next(NULL){}
		};

		Node *head;
		Node *tail;
		int numElements;
};
#endif
