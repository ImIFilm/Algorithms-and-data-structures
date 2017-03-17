// mergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
const int N = 10;
void print(int A[], int N) 
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
void merge(int A[], int l, int q, int p)
{
	int *t=new int[p-l+1];
	int i = l, j = q+1,k=0;
	while (i <=q && j<=p)
	{
		if (A[i] <= A[j])
		{
			t[k] = A[i];
			i++;
		}
		else
		{
			t[k] = A[j];
			j++;
		}
		k++;
	}
	while (i <= q)
	{
		t[k] = A[i];
		i++;
		k++;
	}
	while (j<=p)
	{
		t[k] = A[j];
		j++;
		k++;
	}
	for (int i = 0; i < p-l+1; i++)
	{
		A[l+i] = t[i];
	}
}

void mergeSort(int A[], int l, int p)
{
	
		int q = (l + p) / 2;
		if(l<q)mergeSort(A, l, q);
		if(q+1<p)mergeSort(A, q+1, p);
		merge(A, l, q, p);

}


int main()
{
	int A[N] = { 7,8,3,4,6,2,8,7,1,0 };
	print(A, N);
	mergeSort(A, 0, N-1 );
	print(A, N);

}

