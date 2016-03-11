#pragma once 
#include <iostream> 
using namespace std;
#define MemSize 100 

class TStack
{
	int Top;   //верхушка стека 
	int *pMem;
	int Size;
public:
	TStack();
	TStack(const TStack &s);
	TStack(int n);
	~TStack(void);
	int IsEmpty(void)const;
	int IsFull(void)const;
	void Push(const int Val);
	int Pop(void);
	int Peek(void) const;
	
};


