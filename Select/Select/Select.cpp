// Select.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int partition(int A[], int l, int p)
{
	int i = l - 1;
	int q = A[p];
	for (int j = l; j < p; j++)
	{
		if (A[j] < q)
		{
			i++;
			swap(A[j], A[i]);
		}
	}
	swap(A[i + 1],A[p]);
	return i + 1;
}
int select(int A[], int i,int  n) // zwraca wartosc i-tego najmniejszej wartosci w tablic A
{
	if (n == 1) return A[0];
	int q = partition(A, 0, n-1);
	if (i == q) return A[q];
	if (i < q) return select(A, i , q ); // przeszukujemy tylko lewa badz prawa czesc gdyz wiemy w ktorej znajduje sie szukany indeks
	else
		return select(A+q+1, i-q-1, n-q-1 );
}


int main()
{
	int tab[10] = { 1,2,9,32,65,12,43,76,234,76 };
	cout << select(tab, 5,10);
	cout << select(tab, 3,10);
}

