#include <stdio.h>
#include <iostream>
#include "LinkedList_core.h"

int main()
{
	LinkedList<int> l;
	LinkedList<std::string> s;

	s.add("el Richard");
	s.add("se la come");
	s.add("doblada");
	std::cout<<s.get()<<std::endl;
	std::cout<<s.get()<<std::endl;
	std::cout<<s.get()<<std::endl;
	for(int i =0; i < 10; ++i) {
		l.add(rand()%100);
		std::cout<<l.peek() <<std::endl;
	}

	std::cout <<"Inicio"<< "->";
	for(int i = 0; i < 10; ++i)
		std::cout <<l.get()<< "->";
	std::cout <<"END"<< std::endl;
}
