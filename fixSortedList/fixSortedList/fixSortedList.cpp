// fixSortedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct node
{
	int var;
	node *next;

	node()
	{
		var = 1;
		next = NULL;
	}
	void fill(int n, int skok)// wypelnia liste tworzac  co skok wartosci do maksymalnie n
	{
		node *temp;
		temp = this;
		for (int i = var + skok; i<n; i += skok)
		{
			node *p = new node; 			// tworzymy nowy obiekt
			temp->next = p;				// przepinamy nasz wczesniejszy element na nowo powstaly
			p->var = i;					// nadajemy mu wartosc
			p->next = NULL;
			temp = p;
		}
	}
	bool Exist(int w) // funkcja mowiaca czy dany elemnt istnieje w zbiorze mnogosciowym
	{
		node *temp;
		temp = this;
		while (temp != NULL)
		{
			if (temp->var == w)return true;
			temp = temp->next;
		}
		return false;
	}
	void insert(int w)//funckja dodaje elemnt do uporzadkowanego zbioru
	{
		node *q = new node;
		q->var = w;
		q->next = NULL;
		if (this == NULL) // kiedy zbior jest pusty
		{
			var = w;
		}
		else if (w<var) // kiedy pierwszy elemnt jest wiekszy
		{
			q->var = var;
			var = w;
			next = q;
		}
		else					// dodawanie w srodku i na koncu
		{
			node *temp = new node; // jedzie po calym lancuchu
			temp = next;
			node *tail = this; // do zapamietania wczesniejszej pozycji
			while (temp != NULL && w>temp->var)
			{
				tail = temp;
				temp = temp->next;
			}
			q->next = temp; // przepinanie lancucha
			tail->next = q;
		}
	}
	void shout() // wypisuje caly lancuch
	{
		node *temp = this;
		while (temp != NULL)
		{
			cout << " " << temp->var;
			temp = temp->next;
		}
		cout << endl;
	}
	void destroy(int sz) //usuwa element o zadanej wartosci
	{
		if (this == NULL)return; // jezeli pusta lista
		node *q;
		if (var == sz) // jezeli pierwszy elemnt jest szukanym
		{
			q = this;
			next = this->next;
			var = next->var;
			q = next;
			next = q->next;
			delete q;
		}
		else // jezeli nbie jest to pierwszy element
		{
			q = next;
			node *temp = this; // 2 wskaznikiki poszukiwacze
			while (q != NULL && q->var != sz)
			{
				temp = temp->next;
				q = q->next;
			}
			if (q != NULL && q->var == sz) // jezeli znalazl szukana i przypadkiem nie jest to null bo mogl przeciez wyjechac za lancuch jesli element nie istnieje
			{
				temp->next = q->next;
				delete q;// demolka
			}
		}
	}
};


node *findBug(node **L)
{
	node *a;
	while ((*L)->next != NULL && (*L)->next->var > (*L)->var) //dopoki zachowana jest monotonicznosc  
	{
		L = &((*L)->next);
	}
	a = *L; // element zepsuty
	(*L) = (*L)->next; // przepinam liste
	a->next = NULL;
	return a;
}

void insert(node **L, node * a)//L-posortowana lista , a - dodawany element
{
	while ((*L) != NULL && (*L)->var < a->var)
	{
		L = &((*L)->next);
	}
	node *temp = *L; // w tempie jest lista ktora powinna sie znajdowac za doczepianym elementem
	*L = a; // wskaznik podpiety na a
	a->next = temp; //podpinam
}

node *fixSortedList(node *L)
{
	node *a = findBug(&L);
	if (a != NULL)
		insert(&L, a);
	return L;
}


int main()
{
	node *first = new node();
	first->fill(10, 1);
	first->shout();

	first->var = 5;
	

	first = fixSortedList(first);
	first->shout();

    return 0;
}

