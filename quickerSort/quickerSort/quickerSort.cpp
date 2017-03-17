// quickerSort.cpp : Defines the entry point for the console application.
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

void divide(node *head, node *l, node *e, node *b) // dzieli lancuch na 3 mniejsze od pierwszej wartosci rowne i wieksze
{
	int q = head->var;
	while (head != NULL)
	{
		node *temp = head->next;
		if (head->var == q)
		{
			head->next = e->next;
			e->next = head;
		}
		else if (head->var < q)
		{
			head->next = l->next;
			l->next = head;
		}
		else
		{
			head->next = b->next;
			b->next = head;
		}
		head = temp;
	}
}
node *quickerSort(node *head) // zwraca wskaznik na posrtowana liste
{
	node l, b, e; // 3 warownikow
	node *temp;
	l.next = NULL; b.next = NULL; e.next = NULL; // zerowanie ich wartosci
	if (head != NULL)
	{
		divide(head, &l, &e, &b);//dzielimy heada na 3
		l.next=quickerSort(l.next); // rekurencyjne wywolanie lewej i prawej strony
		b.next=quickerSort(b.next);
		if (l.next != NULL) // laczenie list najpierw jesli istnieje lewa czesc
		{
			head = l.next;
			temp = head;
			while (temp->next!= NULL)
				temp = temp->next;
			temp->next = e.next;
		}
		else // srodkowa czesc istnieje zawsze !
		{
			head = e.next;
			temp = head;
		}
		while (temp->next != NULL) // podpiecie prawej czesci
			temp = temp->next;
		temp->next = b.next;
	}
	return head;
}


int main()
{
	node *first = new node();
	first->fill(10,1);
	first->var = 12;
	first->next->next->next->var = 17;
	first->next->next->var = 42;
	first->next->var = 86;
	first->shout();

	first=quickerSort(first);
	first->shout();
}

