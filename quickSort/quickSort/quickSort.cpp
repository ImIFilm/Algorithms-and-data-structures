// quickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int cnt = 0;
const int N = 12;

void print(int A[], int N,int l ,int p) // print wyswietla # jesli miejsce w tablicy w tym momencie nie jest sortowane obok pelna tablica
{
	for (int i = 0; i < N; i++)
	{
		if (i >= l && i<= p)
			cout << A[i] << " ";
		else
			cout << "#" << " ";
	}
	cout << "             ";
	for (int i = 0; i < N; i++)
	{
			cout << A[i] << " ";
	}
	cout << endl;
}
int partitionHorae(int A[], int l, int p)
{
	int i = l - 1, j = p + 1;
	int q = A[l];
	while (true)
	{
		do
		{
			j--;
		} while (A[j] > q);
		do
		{
			i++;
		} while (A[i] < q);
		if (i < j)
		{
			swap(A[i], A[j]);
		}
		else
			return j;
	}
}
void quickSortHorae(int A[], int l, int p)
{
	cnt++;
	print(A, N,l,p);
	while (l < p)
	{
		int q = partitionHorae(A, l, p);
		if (q - l + 1 > p - q)
		{
			quickSortHorae(A, q + 1, p);
			p = q;
		}
		else
		{
			quickSortHorae(A, l, q);
			l = q + 1;
		}
	}
}
int partition(int A[], int l, int p) // dostaje indeks na lewy i prawy koniec podtalbicy A, zwraca indeks na miejsce podzialu
{									// pomiedzy elementami mniejszymi i wiekszymi od q gdzie q=A[p]
	int i = l - 1;
	int q = A[p];
	for (int j = l; j < p; j++)
	{
		if (A[j] < q)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[p]);
	return i + 1;
}
void quickSort(int A[], int l, int p) // wywoluje podzialy dozace do posortowania tablicy obciazajac jak najmniej stos systemowy
{
	cnt++;
	while (l < p)
	{
		int q = partition(A, l, p);
		if (q - l > p - q)
		{
			quickSort(A, q+1, p);
			p = q - 1;
		}
		else
		{
			quickSort(A, l, q-1);
			l = q + 1;
		}
	}
}


int main()
{
	int A[N] = {13,19,9,5,12,8,7,4,11,2,6,21};
	quickSortHorae(A, 0, N - 1);
	print(A,N,0,9);
	cout << cnt;

    return 0;
}

