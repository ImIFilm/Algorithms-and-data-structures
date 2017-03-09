// lnMerge.cpp : Defines the entry point for the console application.
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
		node *temp = new node;
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
		node *temp = new node;
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

int main()
{
    return 0;
}

