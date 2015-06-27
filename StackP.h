#ifndef Stack_h
#define Stack_h

#include "StackException.h"
typedef char* StackItemType;

class Stack
{
public:
	//constructors and destructors:
	Stack();
	Stack(const Stack& aStack);
	~Stack();

	bool isEmpty() const;
	void push(StackItemType newItem) throw(StackException);
	void pop() throw (StackException);
	void pop(StackItemType& stackTop) throw (StackException);
	void getTop(StackItemType& stackTop) const throw(StackException);

private:
	
	struct StackNode
	{
		 StackItemType item;
		 StackNode *next;
	};

	StackNode *topPtr;
};

#endif