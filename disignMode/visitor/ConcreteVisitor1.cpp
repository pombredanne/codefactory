//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Disign Mode Visitor
//  @ File Name : ConcreteVisitor1.cpp
//  @ Date : 2012-3-20
//  @ Author : braveyly
//
//


#include "ConcreteVisitor1.h"
#include "ElementA.h"
#include "ElementB.h"

void ConcreteVisitor1::visit_concrete_element_a(ElementA* elea) {
	cout<<"Some operations added in concrete visitor 1"<<endl;
	elea->operation_a();
}

void ConcreteVisitor1::visit_concrete_element_b(ElementB* eleb) {
	eleb->operation_b();
}
