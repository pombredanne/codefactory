//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Design Mode
//  @ File Name : Forum.h
//  @ Date : 2012-3-16
//  @ Author : braveyly
//
//


#if !defined(_FORUM_H)
#define _FORUM_H

#include <iostream>
#include <string>
using namespace::std;

class Forum {
public:
	virtual int set_forum_name(string name);
	int get_authorization();
	Forum(int);
	~Forum(){};
private:
	int authorization;
};

#endif  //_FORUM_H