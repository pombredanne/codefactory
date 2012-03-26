//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Design Mode
//  @ File Name : Glyph_Factory.h
//  @ Date : 2012-3-15
//  @ Author : 
//
//


#if !defined(_GLYPH_FACTORY_H)
#define _GLYPH_FACTORY_H
#include "common_def.h"
#include "Charactor.h"
#include "Row.h"

class Glyph_Factory {
public:
	Glyph_Factory();
	Charactor* get_charactor(int key);
	Row* get_row(int total);
private:
	vector<Charactor*> _char_vec;
};

#endif  //_GLYPH_FACTORY_H