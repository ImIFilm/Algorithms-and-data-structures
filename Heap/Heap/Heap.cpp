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
	return i - 1 / 2;
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
	if (l<N&& A[r] > max)
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

int main()
{
	const int N = 15;
	int t[N] = { 10,1,8,7,6,5,4,2,2,2,2,2,2,2,2 };
	coutTab(t, N);
	heapify(t, 1,N);
	coutTab(t, N);
}

