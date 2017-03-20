// SumSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct pairOfInt
{
	int index;
	int sum;
};
void swap(pairOfInt &a, pairOfInt &b)
{
	pairOfInt temp = a;
	a = b;
	b = temp;
}
void sumOfTable(int A[], pairOfInt sum[], int n) // w czasie O(n) sumuje tablice
{
	int part;
	for (int i = 0; i < n; i++)
	{
		part = 0;
		for (int j = 0; j < n; j++)
		{
			part += A[i*n + j];
		}
		sum[i].index=i;
		sum[i].sum = part;
	}
}

int partition(pairOfInt A[], int l , int p) // partition quicksorta w wersj Lemuto
{
	int i = l - 1,  q = A[p].sum;
	for (int j = l; j < p; j++)
	{
		if (A[j].sum < q)
		{
			i++;
			swap(A[j], A[i]);
		}
	}
	swap(A[i + 1], A[p]);
	return i + 1;
}
void quickSort(pairOfInt sum[], int l,int p)
{
	int min = 0;
	if (l < p)
	{
		int q = partition(sum, l, p);
		quickSort(sum, l, q - 1);
		quickSort(sum, q+1, p);
	}
}

void sumSort(int A[], int B[], int n)
{
	pairOfInt *sum = new pairOfInt[n];
	sumOfTable(A, sum, n); // zlozonosc m=n^2 -> liniowe
	quickSort(sum, 0, n - 1); // -> zlozonosc nlogn < m -> mniej niz liniowe
	for (int i = 0; i < n; i++)
	{
		int k = sum[i].index;
		for (int j = 0; j < n; j++)
		{
			B[i*n + j] = A[k*n + j];
		}
	}
}
int main()
{
	int A[] = { 4,3,2,6,
				1,2,3,4,
				9,8,43,8,
				1,2,3,2 };
	int B[16];
	for (int i = 0; i < 16; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	sumSort(A, B, 4);
	for (int i = 0; i < 16; i++)
	{
		cout << B[i] << " ";
	}
    return 0;
}

