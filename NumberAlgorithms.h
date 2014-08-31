// Prime.h: interface for the Prime class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRIME_H__35938C20_E202_479B_8F4D_4E6DFA74472D__INCLUDED_)
#define AFX_PRIME_H__35938C20_E202_479B_8F4D_4E6DFA74472D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class NumberAlgorithms  
{
public:
	NumberAlgorithms();
	virtual ~NumberAlgorithms();

	void GeneratePrimeNumbers(int n);
	bool CheckIfNumberPrime();
	
	void swap1(int var1, int var2);
	void swap2(int var1, int var2);
	
	
	void createArray(int arr[], int n);	
	void printArray(int arr[], int n);	
	void SortInsertion(int array[], int size);	
	void SortSelection(int array[], int size);

	
	void Merge(int array[], int leftIdx, int middleIdx, int rightIdx);
	void SortMerge(int array[], int leftIdx, int rightIdx);

	int removeDuplicates(int a[], int array_size);
	
	int gcd(int a, int b);
	int gcd_recurse(int a, int b);

};

#endif // !defined(AFX_PRIME_H__35938C20_E202_479B_8F4D_4E6DFA74472D__INCLUDED_)
