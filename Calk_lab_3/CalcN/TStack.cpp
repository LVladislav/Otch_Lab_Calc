#include "TStack.h" 

TStack::TStack(const TStack &v)
{
	Size = v.Size;
	pMem = new int[Size];
	Top = v.Top;
	for (int i = 0; i < Size; i++)
		pMem[i] = v.pMem[i];
}

TStack::TStack()
{
	Top = -1;
	Size = MemSize;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
		pMem[i] = 0;
}

TStack::TStack(int si) {
	Top = -1;
	Size = si;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
		pMem[i] = 0;
}

TStack::~TStack()
{
	delete[]pMem;
}

int TStack::IsEmpty() const
{
	if (Top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int TStack::IsFull() const
{
	if (Top == Size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TStack::Push(int Val)
{
	if (this->IsFull())
	{
		throw "IsFuul!";
	}
	Top++;
	pMem[Top] = Val;
}

int TStack::Pop(void)
{
	if (this->IsEmpty())
	{
		throw "IsEmpty";
	}
	Top--;
	return pMem[Top + 1];
}

int TStack::Peek() const
{
	return pMem[Top];
}
