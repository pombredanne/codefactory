//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Disign Mode Visitor
//  @ File Name : ConcreteVisitor2.cpp
//  @ Date : 2012-3-20
//  @ Author : braveyly
//
//


#include "ConcreteVisitor2.h"
#include "ElementA.h"
#include "ElementB.h"

void ConcreteVisitor2::visit_concrete_element_a(ElementA* elea) {
	elea->operation_a();
}

void ConcreteVisitor2::visit_concrete_element_b(ElementB* eleb) {
	eleb->operation_b();
}
