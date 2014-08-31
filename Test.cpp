#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/timeb.h>
#include "time.h"
#include <conio.h>

#include <iostream>
using namespace std;

void GetOngoingTime(char *pFullTime)
{
	struct timeb xTimeb;
   ::ftime(&xTimeb);
   int nSeconds = xTimeb.time;
   char cBuffer[1000];
	int nMilliSec = xTimeb.millitm;
	
	time_t xTime_t;
	struct tm * pTimeinfo;
	time (&xTime_t);	
	pTimeinfo = localtime(&xTime_t);
	strftime(pFullTime,60,"%H:%M:%S:",pTimeinfo);
	sprintf(cBuffer, "%03d", nMilliSec);
	
	strcat(pFullTime, cBuffer);
	strcat(pFullTime, " ");
}

#include "BubbleSort.h"
#include "SingleLinkList.h"
#include "InheritanceTest.h"
#include "NamedConstructor.h"
#include "Tree.h"
#include "BinaryTree.h"
#include "StringAlgoritms.h"
#include "NumberAlgorithms.h"
#include "QuickFind.h"
#include "VirtualCopyConstructor.h"
#include "Threads.h"

#include "Printer.h"
#include "SmartPtr.h"
#include "BigNumber.h"
#include "Stack.h"
#include "DoubleLinkList.h"

#include<iostream>
using namespace std;

void fun(const int &i)
{
    cout << "fun(const int &) called ";
}
void fun(int &i)
{
    cout << "fun(int &) called " ;
}

void main()
{	
	DoubleLinkList dList;
	dList.unitTest();

	BigNumberTest();

    const int i = 10;
    fun(i);

	//testSmartPtr();

	StackTest();

	try
	{
		Printer* p1 = Printer::instance();
		Printer* p2 = Printer::instance();
		Printer* p3 = Printer::instance(*p2);
		Printer* p4 = Printer::instance(*p2);
	} catch (Printer::TooManyObjects e)
	{
		printf("%s", e.what());
	}

	Threads threadTest;

	//VirtualCopyConstructor 
    User *user = new User(); 
    user->Action(); 
    delete user;

	BubbleSort			bubbleSort;
	QuickFind			qf;
	StringAlgoritms		stringAlgo;
	NumberAlgorithms	numberAlgo;
	SingleLinkList		list;

	NamedConstructorTest();
	InheritanceTest();

//	Tree				tree;
	BinaryTree		bTree;
	getch();
}
