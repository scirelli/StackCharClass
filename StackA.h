#include "StackException.h"
const int MAX_STACK = 100;
typedef int StackItemType;

class Stack
{
public:
//constructor and destructor:
	Stack(); //default constructor
	//copy contructor and destructor are
	//supplied by the compiler

//stack operations:
	bool isEmpty() const;
	void push(StackItemType newItem) throw(StackException);
	void pop() throw(StackException);
	void pop(StackItemType& stackTop) throw(StackException);
	void getTop(StackItemType& stackTop) const
		throw(StackException);


private:
	StackItemType items[MAX_STACK];
	int           top;
};