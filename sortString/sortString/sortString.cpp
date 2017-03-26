// sortString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
const int N=6;

void coutTable(string A[]) // wypisuej tab stringow
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i];
		cout << endl;
	}
}

void coutTable(int A[],int n) // wypisuje tablice intow
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
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

void sortByLength(int l[], string A[],int left, int right) // quicksort dwoch tablic naraz sortuje stringi i ich dlugosci
{
	int q = partition(l, A, left, right);
	if (left < q - 1) sortByLength(l, A, left, q - 1);
	if (q + 1 < right) sortByLength(l, A, q + 1, right);
}

void sortByPos(string A[], int pos, int from, int to) // sortowanie pozycyjne w obrebie jednej litery w wyrazach z tablicy A od from do to wlacznie z indeksowanymi
{
	string *temp = new string[N];
	const int n = 26;
	int tab[n];
	for (int i = 0; i < n; i++) tab[i] = 0;
	for (int i = from; i <= to; i++) // ilosc wystapien
	{
		tab[int(A[i][pos]) - int('a')]++;
	}
	for (int i = 1; i < n; i++) // miejsce w nowej tablicy
	{
		tab[i] += tab[i - 1];
	}


	for (int i = to; i >= from; i--) // wpisywanie do nowej tablicy
	{
		int index = int(A[i][pos]) - int('a');
		temp[tab[index] - 1 + from] = A[i]; // -1 gdyz miejsca w tab liczone sa od 1 , + from dlatego ze sortujemy tylko miejsce od from do konca tablicy
		tab[index]--;
	}
	for (int i = to; i >=from ; i--)
	{
		A[i] = temp[i];
	}
	delete[] temp;
}

void sortString(string A[]) // glowna funkcja sortujaca stringi o roznej dlugosci
{
	int *l = new int[N];
	getLength(l,A);
	sortByLength(l,A,0,N-1);

	int from=N-1;
	
	for (int pos = l[N - 1]-1; pos >= 0; pos--)
	{
		while (from > 0 && l[from] == l[from - 1]) from--;
		sortByPos(A, pos, from, N-1);
		if (from > 0 && pos == l[from - 1])from--;
	}
	delete[] l;
}


int main()
{
	string A[N] = { "a", "b","ala", "czadsa","czat","cza" };
	sortString(A);
	coutTable(A);
}

