//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Disign Mode Observe
//  @ File Name : ColumnObserve.cpp
//  @ Date : 2012-3-19
//  @ Author : braveyly
//
//


#include "ColumnObserve.h"

void ColumnObserve::operate(int data) {
	get_subject()->set_data(data);
}

void ColumnObserve::show_view() {
	cout<<"refresh column view to"<<get_subject()->get_data()<<endl;
}
