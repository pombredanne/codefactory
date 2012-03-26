//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Disign Mode State
//  @ File Name : TCPEstablished.h
//  @ Date : 2012-3-19
//  @ Author : braveyly
//
//


#if !defined(_TCPESTABLISHED_H)
#define _TCPESTABLISHED_H

#include "TCPState.h"

class TCPEstablished : public TCPState {
public:
	static TCPState* instance();
	void active_open(TCPConnection*);
	void passive_open(TCPConnection*);
	void close(TCPConnection*);
	void acknowlege(TCPConnection*);
	void synchronize(TCPConnection*);
private:
	static TCPEstablished* _instance;
	TCPEstablished(){};
};

#endif  //_TCPESTABLISHED_H
