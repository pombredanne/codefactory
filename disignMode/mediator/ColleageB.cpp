//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Design Mode Mediator
//  @ File Name : ColleageB.cpp
//  @ Date : 2012-3-19make clean
//  @ Author : braveyly
//
//


#include "ColleageB.h"

ColleageB::ColleageB(Mediator* mdt):Colleage(mdt)
{

}

void ColleageB::action() {
	get_mediator()->doActionFromAToB();
	cout<<"b state is"<<get_state();
}

