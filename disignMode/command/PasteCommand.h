//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Design Mode Command
//  @ File Name : PasteCommand.h
//  @ Date : 2012-3-16
//  @ Author :braveyly
//
//


#if !defined(_PASTECOMMAND_H)
#define _PASTECOMMAND_H

#include "Command.h"

class PasteCommand : public Command {
public:
	PasteCommand(Receiver*);
	void execute();
};

#endif  //_PASTECOMMAND_H