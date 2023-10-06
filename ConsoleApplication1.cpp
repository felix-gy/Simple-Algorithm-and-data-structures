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
	bool find(int v, NodoArray**& pnode, int*& arr);
	void add(int v);
	void remove(int v);
	void print();
	bool empty() {
		return !head;
	}
private:
	// Pointers
	NodoArray* head = NULL;
	int* top = NULL;
};

bool OLinkedList::find(int v, NodoArray**& pnode, int*& arr)
{
	for (pnode = &head, arr = NULL;
		*pnode && (*pnode)->next != NULL && *((*pnode)->valor + 4) < v;
		pnode = &(*pnode)->next);

	if (*pnode)
	{
		for (arr = (*pnode)->valor; arr && arr != top + 1 && *arr != v && *arr < v; arr++);

		if (arr == (*pnode)->valor + 5)
		{
			pnode = &(*pnode)->next;
		}
	}

	return pnode && arr && *arr == v;
}

void OLinkedList::add(int v)
{
	//Nodo donde se debe añadir v
	NodoArray** pnode;
	//Nodo anterior de pnode
	//Posicion en el array donde se debe añadir v
	int* arr;

	if (!find(v, pnode, arr))
	{
		if (*pnode)
		{
			int* swap_arr = arr;

			NodoArray* last = *pnode;
			for (NodoArray* n = *pnode; n; pnode, n = n->next, swap_arr = n->valor)
			{
				for (; swap_arr < n->valor + 5 && swap_arr != top + 1; swap_arr++)
				{
					swap(*arr, *swap_arr);
				}
				last = n;
			}

			top++;


			if (top == last->valor + 5)
			{
				last->next = new NodoArray(NULL);
				top = last->next->valor;
			}

			*top = *arr;
		}
		else
		{
			*pnode = new NodoArray(NULL);
			arr = top = (*pnode)->valor;
		}
		*arr = v;
	}
}

void OLinkedList::remove(int v)
{
	//Nodo donde se debe añadir v
	NodoArray** pnode;
	//Posicion en el array donde se debe añadir v
	int* arr;
	if (find(v, pnode, arr))
	{
		int* swap_arr = arr;

		//Ultimo nodo visitado
		NodoArray* last *pnode;

		for (NodoArray* n = *pnode;n; n = n->next, swap_arr = n->valor)
		{
			for (; swap_arr != n->valor + 5 && swap_arr != top + 1; swap_arr++, arr = swap_arr-1)
			{
				swap(*arr, *swap_arr);
			}

			last = n;

			// pnode apuntara al nodo anterior del ulitmo nodo visitado si esque existe 
			if ( n->next && n->next->next)
			{
				pnode = &((*pnode)->next);
			}
		}

		top--;

		if (top == last->valor-1)
		{
			NodoArray* tmp = *pnode;
			top = NULL;
			if ((*pnode)->next)
			{
				tmp = (*pnode)->next;
				top = (*pnode)->valor + 4;
				(*pnode)->next = NULL;
			}
			else
			{
				*pnode = NULL;
			}
			delete(tmp);
		}
	}
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
	lis.add(4);
	lis.add(3);
	lis.add(2);
	lis.add(8);
	lis.add(4);
	lis.add(6);
	lis.add(9);
	//lis.add(11);
	//lis.add(4);
	//lis.add(1);
	//lis.add(6);
	//lis.add(8);
	//lis.add(9);
	//lis.add(44);
	//lis.add(18);
	//lis.add(17);
	//lis.add(6);
	//lis.add(8);
	//lis.add(55);
	//lis.add(34);
	//lis.add(24);
	//lis.add(45);
	//lis.add(35);
	//lis.add(36);
	//lis.add(55);
	//lis.add(65);
	//lis.add(44);
	//lis.add(44);

	lis.print();
	
	lis.remove(8);
	//lis.remove(55);
	//lis.remove(6);
	//lis.remove(8);
	//lis.remove(1);
	//lis.remove(44);
	//lis.remove(24);
	//lis.remove(17);
	
	
	lis.print();

}

