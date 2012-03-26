//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Disign Mode Memento
//  @ File Name : Memento.h
//  @ Date : 2012-3-19
//  @ Author : braveyly
//
//


#if !defined(_MEMENTO_H)
#define _MEMENTO_H
#include <iostream>
#include <string>
using namespace::std;

class Memento {
public:
	friend class Originator;
private:
	int _state;
	Memento();
	Memento(int);
	void set_state(int);
	int get_state();
};

#endif  //_MEMENTO_H
