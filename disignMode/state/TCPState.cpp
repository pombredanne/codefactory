//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Disign Mode State
//  @ File Name : TCPState.cpp
//  @ Date : 2012-3-19
//  @ Author : braveyly
//
//

#include "TCPConnection.h"
#include "TCPState.h"

void TCPState::change_state(TCPConnection* connect, TCPState* state) {
	connect->_state = state;
}
