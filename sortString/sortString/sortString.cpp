// sortString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
const int N=4;

void coutTable(string A[]) // wypisuej tab stringow
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i];
		cout << endl;
	}
}

void getLength(int l[],string A[]) // zapisuje do tablicy intow ich dlugosci
{
	for (int i = 0; i < N; i++)
	{
		l[i] = A[i].length();
	}
}

int partition(int l[], string A[], int left, int right) // partition dzialajace na dwoch tablicach
{
	int i = left - 1, q = l[right];
	for (int j = left; j < right; j++)
	{
		if (l[j] < q)
		{
			i++;
			swap(l[i], l[j]);
			swap(A[i], A[j]);
		}
	}
	swap(l[i + 1], l[right]);
	swap(A[i + 1], A[right]);
	return i + 1;
}

void sortByLength(int l[], string A[],int left, int right) // quicksort dwoch tablic naraz 
{
	int q = partition(l, A, left, right);
	if (left < q - 1) sortByLength(l, A, left, q - 1);
	if (q + 1 < right) sortByLength(l, A, q + 1, right);
}

void sortByPos(string A[], int pos, int from, int to) // sortowanie pozycyjne w obrebie jeden litery w wielu wyrazach
{
	// TODO
}

void sortString(string A[])
{
	int *l = new int[N];
	getLength(l,A);
	sortByLength(l,A,0,N-1);

	int from=N-1;

	for (int pos = l[N - 1]; pos >= 0; pos--)
	{
		while (from >= N - 1 && l[from] == l[from - 1]) from--;
		sortByPos(A, pos, from, N-1);
		if (from > 0 && pos - 1 == l[from - 1])from--;
	}
	delete l;
}


int main()
{
	string A[N] = { "ala", "csadsa" , "a", "b" };
	sortString(A);
	coutTable(A);
}

