//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Design Mode Command
//  @ File Name : Invoker.h
//  @ Date : 2012-3-16
//  @ Author :braveyly
//
//


#if !defined(_INVOKER_H)
#define _INVOKER_H
#include "Command.h"

class Invoker {
public:
	Invoker(Command*);
	virtual void DoInvoke();
private:
	Command* _cmd;
};

#endif  //_INVOKER_H
