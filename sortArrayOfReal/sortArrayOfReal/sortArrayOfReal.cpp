// sortowanie tablicy liczb rzeczywistych o n elementach ktora przyjmuje tylko logn roznych wartosci zlozonosc nlog(logn)
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
const int N = 8;

struct Counter
{
	double index;
	int quant;
};

void coutTab(double A[], int n)
{
	for (int i = 0 ; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl; 
}

void coutCounterTab(Counter A[], int n)
{
	cout << "index  quant" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i].index << "  " << A[i].quant << endl;
	}

}

int find(Counter tab[], int n, double key) // szuka indeksu w tablicy tab na ktorym znajduje sie element o podanym kluczu jesli nie ma zwraca -1
{
	int l = 0, r = n ,q;
	while (l < r)
	{
		q = (l + r) / 2;
		if (tab[q].index == key)return q;
		if (tab[q].index < key) l = q + 1 ;
		else
			r = q -1  ;
	}
	if (tab[l].index == key) return l;
	else
		return - 1;
}

void zeroCounter(Counter tab[], int n)//zerowanie tablicy
{
	for (int i = 0; i < n; i++)
	{
		tab[i].index = 0;
		tab[i].quant = 0;
	}
}

int insert(Counter tab[], int cap, double val) // dodaje nowy indeks do tablicy tak zeby byla posortowana po indeksach zlozonosc log^2(n)
{
	
		int i = cap;
		while (i >= 0 && tab[i].index > val)
		{
			tab[i + 1].index = tab[i].index;
			tab[i + 1].quant = tab[i].quant;
			i--;
		}
		tab[i + 1].index = val; tab[i + 1].quant = 0;
		return i+1;
}

void fillCounterArray(double A[], int n, Counter tab[]) // uzupelnia indeksy i ilosc liczb ktora pojawila sie w zadanej tablicy pod counting sorta
{
	int size = log2(n);
	int cap = -1, ind = 0;
	for (int i = 0; i < n; i++)	// ile razy sie pojawila 
	{
		ind = find(tab, cap, A[i]);
		if (ind == -1)
		{
			ind =insert(tab, cap, A[i]);
			cap++;
		}
		tab[ind].quant++;
	}
	for (int i = 1; i < size; i++) // ustawianie kolejnosci
	{
		tab[i].quant += tab[i - 1].quant;
	}
}

void sortArrayOfReal(double A[], int n) // sortowanie przez zliczanie 
{
	int size = log2(n);
	Counter *tab=new Counter[size];
	double *B = new double[n];
	zeroCounter(tab, size);
	fillCounterArray(A, n, tab);
	//coutCounterTab(tab, size);
	for (int i = n-1; i >= 0; i--)
	{
		int ind = find(tab, size-1, A[i]);
		B[tab[ind].quant-1] = A[i];
		tab[ind].quant--;
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = B[i];
	}
	
	
}

int main()
{
	double A[N] = { 12.3, 12.3, 4.56, 12.3, 4.56, 12.3, 0.987, 12.3 };
	sortArrayOfReal(A, N);
	coutTab(A,N);
    return 0;
}

