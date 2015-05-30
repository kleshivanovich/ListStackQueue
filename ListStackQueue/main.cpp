#include <iostream>
#include <stdlib.h>
using namespace std;


struct Sp
{
	int value;
	Sp *pNext;
};

class List{
	int n;
	struct Sp *pF;
public:
	List()
	{
		n = 0;
		pF = NULL;
	}
	List(int *pF, int n)
	{
		this->pF = new Sp();
		this->n = n;
		Sp *cur;
		cur = this->pF;
		for (int i = 0; i < n; ++i)
		{
			cur->value = pF[i];
			cur->pNext = new Sp();
			cur = cur->pNext;
		}
		cur->pNext = NULL;
	}
	void SetList(Sp *pF, int n)
	{
		this->pF = pF;
		this->n = n;
	}
	void print()
	{
		Sp *cur=pF;
		while (cur)
		{
			cout << endl << cur->value;
			cur = cur->pNext;
		}
	}
	~List()
	{
		Sp *cur=pF, *next;
		while (cur)
		{
			next = cur->pNext;
			delete cur;
			cur = next;
		}
		
	}
	 void addend(int val)
	{
		Sp *cur = pF;
		for (int i = 0; i < n-1;++i)
		{
			cur = cur->pNext;
		}
		cur->pNext = new Sp();
		cur = cur->pNext;
		cur->value = val;
		cur->pNext = NULL;
		n++;
	}
	 void addbeg(int val)
	{
		Sp *cur = new Sp();
		cur->value = val;
		cur->pNext = pF;
		pF = cur;
	}
};

class Stack
{
	int n;
	struct Sp *pF;
public:
	Stack()
	{
		n = 0;
		pF = NULL;
	}
	Stack(int *pF, int n)
	{
		this->pF = new Sp();
		this->n = n;
		Sp *cur;
		cur = this->pF;
		for (int i = 0; i < n; ++i)
		{
			cur->value = pF[i];
			cur->pNext = new Sp();
			cur = cur->pNext;
		}
		cur->pNext = NULL;
	}
	void add(int val)
	{
		Sp *cur=pF;
		for (int i = 0; i < n - 1; ++i)
		{
			cur = cur->pNext;
		}
		cur->pNext = new Sp();
		cur->pNext->value = val;
		n++;
	}
	Sp del()
	{
		Sp val;
		Sp* cur = pF;
		for (int i = 0; i < n - 2; ++i)
		{
			cur = cur->pNext;
		}
		val = *cur->pNext;
		cur->pNext = NULL;
		n--;
		return val;
	}
	void print()
	{
		Sp *cur = pF;
		while (cur)
		{
			cout << endl << cur->value;
			cur = cur->pNext;
		}
	}
};

class Queue
{
	int n;
	struct Sp *pF;
public:
	Queue()
	{
		n = 0;
		pF = NULL;
	}
	Queue(int *pF, int n)
	{
		this->pF = new Sp();
		this->n = n;
		Sp *cur;
		cur = this->pF;
		for (int i = 0; i < n; ++i)
		{
			cur->value = pF[i];
			cur->pNext = new Sp();
			cur = cur->pNext;
		}
		cur->pNext = NULL;
	}
	void add(int val)
	{
		Sp *cur = pF;
		for (int i = 0; i < n - 1; ++i)
		{
			cur = cur->pNext;
		}
		cur->pNext = new Sp();
		cur->pNext->value = val;
		n++;
	}
	Sp del()
	{
		Sp cur = *pF;
		pF = pF->pNext;
		return cur;
	}
	void print()
	{
		Sp *cur = pF;
		while (cur)
		{
			cout << endl << cur->value;
			cur = cur->pNext;
		}
	}
};

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6 };
	List ls(arr, 7);
	Stack st(arr, 7);
	Queue qt(arr, 7);
	ls.print();
	ls.addend(7);
	ls.addbeg(8);
    ls.print();
	cout<<endl << "||||||||||||||";
    st.print();
	cout << endl << "||||||||||||||";
	st.add(7);
	st.add(8);
	st.print();
	cout << endl << "||||||||||||||";
	st.del();
	st.print();
	cout << endl << "||||||||||||||";
	qt.add(10);
	qt.del();
	qt.print();
	return 0;
}