//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Design Mode Mediator
//  @ File Name : Colleage.cpp
//  @ Date : 2012-3-19
//  @ Author : braveyly
//
//


#include "Colleage.h"

Colleage::Colleage ( Mediator* mdt )
{
    _mdt = mdt;
}

void Colleage::set_state ( string str )
{
    state = str;
}

string Colleage::get_state()
{
    return state;
}

void Colleage::action()
{

}

Mediator* Colleage::get_mediator()
{
	return _mdt;
}