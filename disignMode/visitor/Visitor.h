//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Disign Mode Visitor
//  @ File Name : Visitor.h
//  @ Date : 2012-3-20
//  @ Author : braveyly
//
//


#if !defined(_VISITOR_H)
#define _VISITOR_H
#include <iostream>
using namespace::std;

class ElementA;
class ElementB;

class Visitor {
public:
	virtual void visit_concrete_element_a(ElementA*)=0;
	virtual void visit_concrete_element_b(ElementB*)=0;
};

#endif  //_VISITOR_H