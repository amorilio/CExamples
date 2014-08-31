// ObjectsCounter.h: interface for the ObjectsCounter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECTSCOUNTER_H__E5179473_1B04_4A49_8871_02AF3B2E16CB__INCLUDED_)
#define AFX_OBJECTSCOUNTER_H__E5179473_1B04_4A49_8871_02AF3B2E16CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class BeenCounted>
class Counted  
{
public:
	class TooManyObjects
	{
	public:
		char* what() { return "Too Many Objects Created";}
	};

	static int objectsCount() {return numOfObjects; }
protected:

	Counted();
	Counted(const Counted& oc);
	~Counted();

private:
	static int numOfObjects;
	static const int maxNumOfObjects;
	void init();

};

#endif // !defined(AFX_OBJECTSCOUNTER_H__E5179473_1B04_4A49_8871_02AF3B2E16CB__INCLUDED_)
