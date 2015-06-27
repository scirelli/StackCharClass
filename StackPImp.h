#include "StackP.h"
#include <cstddef>
#include <cassert>

Stack::Stack() : topPtr(NULL)
{
}//end default constructor

Stack::Stack(const Stack& aStack)
{
	if (aStack.topPtr == NULL)
		topPtr = NULL; //original list is empty
	else //copy rest of list
	{
		topPtr = new StackNode;
		assert(topPtr != NULL);
		topPtr->item = aStack.topPtr->item;
		

		StackNode *newPtr = topPtr;
		for(StackNode *origPtr = aStack.topPtr->next; origPtr != NULL; origPtr = origPtr->next)
		{
			newPtr->next = new StackNode;
			assert(newPtr->next != NULL);
			newPtr = newPtr->next;
		} //end for for-loop

		newPtr->next = NULL;
	}  //end if
} //end copy contructor

Stack:: ~Stack()
{
	while (!isEmpty())
		pop();
}

bool Stack::isEmpty() const 
{
	return topPtr == NULL;
}  //end is empty

//Pushes items on stack
void Stack::push(StackItemType newItem)
{
	StackNode *newPtr = new StackNode;

	if (newPtr == NULL)
		throw StackException("StackException: stack push cannot allocate memory");
	else
	{
		newPtr->item = newItem;
		newPtr->next = topPtr;
		topPtr = newPtr;
	}
}

void Stack::pop()
{
	if (isEmpty())
		throw StackException("StackException: stack empty on pop");
	else
	{
		StackNode *temp = topPtr;
		topPtr = topPtr->next;
		temp->next = NULL;
		delete temp;
	}
}

void Stack::pop(StackItemType & stackTop)
{
	if (isEmpty())
		throw StackException("StackException: stack empty on pop");
	else
	{
		strcpy(stackTop, topPtr->item);
		StackNode *temp = topPtr;
		topPtr = topPtr->next;

		temp->next = NULL;
		delete temp;
	}
}

void Stack::getTop(StackItemType & stackTop) const
{
	if(isEmpty())
		throw StackException("StackException: Stack empty on getTop");
	else
		strcpy(stackTop, topPtr->item);
}