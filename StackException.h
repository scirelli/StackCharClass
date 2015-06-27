#ifndef StackException_h
#define StackException_h

#include<exception>
#include<string>

using namespace std;


class StackException: public exception
{
public:
	StackException(const string & message="") : exception(message.c_str())
	{
	}
};

#endif