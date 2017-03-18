// twoListstSplit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node *next;
};

struct TwoLists
{
	Node *even;
	Node *odd;
};


TwoLists split(Node *list)
{
	TwoLists l;
	l.even = NULL;
	l.odd = NULL;
	Node *t,*temp;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		if (temp->val % 2 == 0)
		{
			t = l.even;
			l.even = temp;
			temp->next = t;
		}
		else
		{
			t = l.odd;
			l.odd = temp;
			temp->next = t;
		}
	}
	return l;
}

void print(Node *first)
{
	while (first != NULL)
	{
		cout << first->val << " ";
		first = first->next;
	}
	cout << endl;
}

int main()
{
	Node *first = new Node;
	first->val = 1;
	Node *t=first,*t2;
	for (int i = 0; i < 10; i++)
	{
		t2 = new Node;
		t2->val = i;
		t->next = t2;
		t = t->next;
		t2 = NULL;
	}
	t->next = NULL;

	TwoLists l;
	l = split(first);

	first = l.even;
	print(first);
	first = l.odd;
	print(first);
}

