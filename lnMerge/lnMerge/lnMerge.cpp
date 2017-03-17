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

node * listMerge(node *l1, node *l2, node **t) // scala dwie listy zwraca nowa glowe a t zwraca ogon
{
	node *mhead;
	if (l1 == NULL && l2 == NULL) return NULL;
	if (l1 == NULL || l2->var < l1->var)
	{
		mhead = l2; 
		l2 = l2->next;
	}
	else
	{
		mhead = l1;
		l1 = l1->next;
	}
	*t = mhead;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->var < l2->var)
		{
			(*t)->next = l1;
			l1 = l1->next;
		}
		else
		{
			(*t)->next = l2;
			l2 = l2->next;
		}
		(*t) = (*t)->next;
		(*t)->next = NULL;
	}
	if (l1 != NULL)(*t)->next = l1;
	if (l2 != NULL)(*t)->next = l2;
	while ((*t)->next != NULL) (*t) = (*t)->next;
	return mhead;
}
node* listNaturalMerge(node *head) // dostaje head i na podstawie ciagow naturalnych sortuje liste
{
	if (head == NULL) return NULL;
	bool merged = 1;
	node *l = head, *p=head, *q;
	node *shead = head;

	while (merged) // dopoki sa wykonywa zmiany
	{
		merged = false;
		l = shead,p=shead;
		
		while (l!=NULL) // dopoki nie przeszlismy po calej liscie
		{
			while (p->next != NULL && p->var <= p->next->var)	p = p->next; // ustawiam p - poczatek naturalnego ciagu
			q = p->next;
			p->next = NULL;
			p = q;				// q ustawione jako poczatek naturalnego ciagu 2
			if (q == NULL) // jezeli cala lista od l jest posortowana
			{
				break;
			}
			while (q->next != NULL && q->var < q->next->var)	q = q->next; // odpinam drugi ciag i zapamietuje reszte listy
			node * temp = q->next;
			q->next = NULL;
			l=listMerge(l, p, &q); // lacze 2 ciagi
			q->next = temp;
			if (!merged) shead = l; // jesli jest to pierwszy ciag musze zapamietac zmieniona glowe
			l = temp;
			p = temp; // przygotowuje do koljnego laczenia
			merged = true;	//dokonalem zmian
		}	
	}
	return head;
}
void delete_key(node** ww, int val)
{
	node* del;

	while ((*ww)->var != val)
	{
		ww = &((*ww)->next);
	}

	del = (*ww); //usiwanie elmentu z pamieci
	(*ww) = (*ww)->next;
	delete del;

	
}

int main()
{
	node *first = new node();
	node *second = new node();
	node* third = new node();
	node *kappa = new node();
	node* temp=first;
	first->fill(10, 1);
	first->shout();
/*
	delete_key(&first, 2);
	first->shout();
*/
	
	second->fill(10, 1);
	while (temp->next != NULL) temp = temp->next;
	temp->next = second;
	
	third->fill(10, 7);
	while (temp->next != NULL) temp = temp->next;
	temp->next = third;
	
	kappa->fill(20, 4);
	while (temp->next != NULL) temp = temp->next;
	temp->next = kappa;
	
	
	
	
	
	
	first->shout();
	first=listNaturalMerge(first);
	first->shout();
	
	
}

