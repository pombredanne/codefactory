//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Disign Mode Observe
//  @ File Name : TableObserve.h
//  @ Date : 2012-3-19
//  @ Author : braveyly
//
//


#if !defined(_TABLEOBSERVE_H)
#define _TABLEOBSERVE_H
#include "Subject.h"
#include "Observe.h"

class TableObserve : public Observe {
public:
	void operate(int);
	void show_view();
	TableObserve(){};
};

#endif  //_TABLEOBSERVE_H