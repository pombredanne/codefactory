//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Disign Mode Observe
//  @ File Name : DataSubject.h
//  @ Date : 2012-3-19
//  @ Author : braveyly
//
//


#if !defined(_DATASUBJECT_H)
#define _DATASUBJECT_H

#include "Subject.h"

class DataSubject : public Subject {
public:
	void set_data(int);
	int get_data();
	DataSubject();
private:
	int _data;
};

#endif  //_DATASUBJECT_H
