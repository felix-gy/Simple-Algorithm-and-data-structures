#include <iostream>
using namespace std;

struct NodoArray
{
	int valor[5] = {};
	NodoArray* next;
	NodoArray(NodoArray* n)
	{
		next = n;
	}
};

class OLinkedList
{
public:
	bool find(int v, NodoArray** &pnod, int*&parr);
	void add(int v);
	void remove(int v);
	void print();
	bool empty() {
		return !head;
	}
private:
	// Pointers
	NodoArray* head = NULL;
	int *top = NULL;
};

bool OLinkedList::find(int v, NodoArray **&pnod, int*&parr)
{
	parr = NULL;

	for (pnod = &head; *pnod && (*pnod)->next != NULL &&  (*pnod)->valor[0] != v && ((*pnod)->next)->valor[0] < v; pnod = &(*pnod)->next);
	
	if (*pnod)
	{
		for (parr = (*pnod)->valor;parr && parr != top + 1 && *parr != v && *parr < v; parr++);

		if (parr == (*pnod)->valor + 5)
		{
			pnod = &(*pnod)->next;
		}
	}

	return parr && *parr == v;
}

void OLinkedList::add(int v)
{
	NodoArray** pnod;
	int* parr;
	if (!find(v, pnod, parr))
	{

		if (*pnod)
		{

			int* arr = parr;
			NodoArray* last = *pnod;

			for (NodoArray* nod = *pnod; nod; nod = nod->next, arr = nod->valor)
			{
				for (; arr < nod->valor + 5 && arr != top + 1; arr++)
				{
					swap(*parr, *arr);
				}
				NodoArray* last = nod;
			}

			top++;

			if (top > last->valor + 5)
			{
				last->next = new NodoArray(NULL);
				top = last->valor;
			}

			*top = *parr;

		}
		else
		{
			*pnod = new NodoArray(NULL);
			parr = top = (*pnod)->valor;
		}

		*parr = v;
	}
}

void OLinkedList::remove(int v)
{
}

void OLinkedList::print()
{
	int* j = head->valor;
	cout << "Head ->";
	for (NodoArray* i = head; i; i = i->next, j = i->valor)
	{
		cout << "[ ";
		for (; j <= i->valor + 4 && j != top + 1; j++)
		{
			cout << *j << " ";
		}
		cout << "] -> ";
	}
	cout << "NULL" << endl;
}	
int main() {
	OLinkedList lis;
	lis.add(5);
	lis.add(3);
	lis.add(2);
	lis.add(4);
	lis.add(1);
	lis.add(6);
	lis.add(8);
	lis.add(7);

	lis.print();

}

