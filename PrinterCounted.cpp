// PrinterCounted.cpp: implementation of the PrinterCounted class.
//
//////////////////////////////////////////////////////////////////////

#include "PrinterCounted.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int Counted<PrinterCounted>::maxNumOfObjects = 10;

PrinterCounted* PrinterCounted::instance()
{
	return new PrinterCounted;
}

PrinterCounted* PrinterCounted::instance(const PrinterCounted& p)
{	
	return new PrinterCounted(p);
}
