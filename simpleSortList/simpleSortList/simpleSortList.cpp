// simpleSortList.cpp : Defines the entry point for the console application.
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

node* min(node **head)//zakladamy ze nie dostaniemy pustej listy zwraca najmniejszy element
{
	node* temp = (*head);
	int min = ((*head)->var);
	node* m =NULL;
	while (temp->next != NULL) // szukamy poprzednika mina
	{
		if (temp->next->var < min)
		{
			min = temp->next->var;
			m = temp;
		}
		temp = temp->next;
	}
	if (m != NULL) // jezeli nie jest to pierwszy element nasz wskaznik head wskazuje na wskaznik do najmniejszego elemntu
	{
		head = &(m->next);
	}
	temp = *head; // temp przyjmuje wartosc wskazywana przez wskaznik
	*head = (*head)->next; // wskaznik ktory wczesniej wskazywal wartosc minimalna wskazuje jedna dalej
	temp->next = NULL; // minimalna wartosc nie ma kolejnych elementow
	return temp;
}
void insert(node **head,node *el)//do posorotwanej lisy wskazywanej przez head wrzuca element el
{
	if ((*head) == NULL) 
	{
		(*head) = el;
		return;
	}
	while ((*head) != NULL && (*head)->var < el->var)
	{
		head = &((*head)->next);
	}
	node *temp = *head;
	*head = el;
	el->next = temp;
}
node* insertionSort(node *head)
{
	node* shead = NULL;
	while (head != NULL)
	{
		node *temp = head;
		head = head->next;
		temp->next = NULL;
		insert(&shead, temp);
	}
	return shead;
}
node* selectionSort(node *head)
{
	node *shead=NULL;
	node *tail = NULL;
	if (head != NULL) 
	{
		tail = shead = min(&head);
	}
	while (head != NULL)
	{
		tail->next = min(&head);
		tail = tail->next;
	}
	return shead;
}


int main()
{

	node *first=new node();
	first->fill(10, 2);
	first->next->var = 19;
	first->next->next->var= 15;
	first->shout();
	first = insertionSort(first);
	first->shout();
	

	return 0;
}

