//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Design Mode
//  @ File Name : HelpHandler.cpp
//  @ Date : 2012-3-16
//  @ Author : braveyly
//
//


#include "HelpHandler.h"

HelpHandler::HelpHandler(HelpType type, HelpHandler* handler):_help_type(type),_successer(handler) {

}

void HelpHandler::print_helper(HelpType) {

}

HelpType HelpHandler::get_help_type(){
	return _help_type;
}

HelpHandler* HelpHandler::get_help_handler()
{
	return _successer;
}

