//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Design Mode Mediator
//  @ File Name : Colleage.h
//  @ Date : 2012-3-19
//  @ Author : braveyly
//
//


#if !defined(_COLLEAGE_H)
#define _COLLEAGE_H
#include <iostream>
#include <string>
#include "Mediator.h"
using namespace::std;

class Colleage {
public:
	Colleage(Mediator*);
	void set_state(string);
	string get_state();
	virtual void action();
	Mediator* get_mediator();
private:
	string state;
	Mediator* _mdt;
};

#endif  //_COLLEAGE_H
