//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Design Mode
//  @ File Name : Application.cpp
//  @ Date : 2012-3-16
//  @ Author : braveyly
//
//


#include "Application.h"

void Application::print_helper(HelpType type) {
	if( get_help_type() == type || NULL == get_help_handler() )
		cout<<"the help info of appication"<<endl;
	else
		cout<<"No successor print help info"<<endl;
}

Application::Application(HelpType type, HelpHandler* handler):HelpHandler(type, handler) {

}

