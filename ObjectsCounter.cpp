// ObjectsCounter.cpp: implementation of the ObjectsCounter class.
//
//////////////////////////////////////////////////////////////////////

#include "ObjectsCounter.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template <class BeenCounted>
Counted<BeenCounted>::Counted()
{
	init();
}

template <class BeenCounted>
Counted<BeenCounted>::Counted(const Counted<BeenCounted>& )
{
	init();
}

template <class BeenCounted>
Counted<BeenCounted>::~Counted()
{
	--numOfObjects;
}

template <class BeenCounted>
void Counted<BeenCounted>::init()
{
	if(numOfObjects >= maxNumOfObjects)
		throw TooManyObjects;

	++numOfObjects;
}
