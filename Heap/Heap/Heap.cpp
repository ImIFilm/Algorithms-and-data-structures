// Heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int left(int i)
{
	return i * 2 + 1;
}
int right(int i)
{
	return i * 2 + 2;
}
int parent(int i)
{
	if (i == 0) return 0; // z³e dane
	return (i - 1) / 2;
}
void heapify(int A[], int i,int N) // do funkcji podajemy indeks elementu ktorego podejrzewamy o to ¿e jego dzieci s¹ od niego wieksze 
{
	int l = left(i);
	int r = right(i);
	int max=A[i],maximum=i;
	if (l<N && A[l] >max)
	{
		max = A[l];
		maximum = l;
	}
	if (l<N && A[r] > max)
	{
		max = A[r];
		maximum = r;
	}
	if (maximum != i)
	{
		swap(A[i], A[maximum]);
		heapify(A, maximum,N);
	}
}
void coutTab(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
void increaseKey(int key, int i,int A[],int N) // zwieksza klucz elementu o indeksie i i w razie potrzeby naprawia strukture kopca
{
	A[i] = key;
	while (A[i] > A[parent(i)])
	{
		swap(A[i], A[parent(i)]);
		i = parent(i);
	}
}
int extractMax(int A[], int n) // zwraca najwiekszy element kopca i naprawia go
{
	if (n == 0) return 0;
	int max = A[0];
	int i = 0, l, r;
	A[0] = 0;
	while (left(i) < n) // istnienie lewego "syna" determinuje dalsze naprawianie
	{
		l = left(i), r = right(i);
		if (A[l] > A[r]) // wybieram wiekszego syna 
		{
			A[i] = A[l]; i = l;
		}
		else
		{
			A[i] = A[r]; i = r;
		}
	}
	if (i != 0 && i != n - 1) // sprawiam ze "dziura" po elemencie usunietym bedzie na koncu tablicy
	{
		increaseKey(A[n - 1], i, A, n);
		A[n - 1] = 0;
	}

	return max;
}
void buildHeap(int A[], int N)
{
	for (int i = N / 2; i >= 0; i--)
		heapify(A, i, N);
}
void heapSort(int A[], int N)
{
	int size = N-1;
	buildHeap(A, N);
	coutTab(A, N);
	while(size>=2)
	{
		coutTab(A, N);
		swap(A[size], A[0]);
		size--;
		heapify(A, 0, size);
	}
}

int main()
{
	const int N = 10;
	int t[N] = { 0,1,2,3,4,5,6,7,8,9};
	coutTab(t, N);
	heapSort(t, N);
	coutTab(t, N);
}

