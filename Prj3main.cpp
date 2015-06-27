#include <iostream>
#include <fstream>
#include <string>
#include "StackP.h"
#include "StackPImp.h"

void main()
{
	char * fileName = new char [80];
	char* cString= new char[21];
	fstream inFile;
	Stack integerStack;

	cout<< "Enter file name ";
	cin.getline(fileName, 80, '\n');

	//inFile.open("c:\\mydocu~1\\visual~1\\stackc~2\\name.txt", ios::in);
	inFile.open(fileName, ios::in);

	cout<< "\nInput-> ";
	while(!inFile.eof())
	{
		inFile.getline(cString, 20, '\n');
		integerStack.push(cString);
		cout << cString << " ";
	}
	
	cout<< "\n Output-> ";	

	while(!integerStack.isEmpty())
	{
		integerStack.getTop(cString);
		cout << cString << ' ';
		integerStack.pop();
	}


	return;
}