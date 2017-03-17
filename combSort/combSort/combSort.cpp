// combSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int MAX = 6;

int max(int a, int b)
{
	if (a > b)return a;
	return b;
}
void Combsort(int tab[MAX])
{
	int top, gap, x;
	bool swapped = true;

	gap = MAX;
	while (gap > 1 || swapped)//wykonujemy az dojdziemy do bubble sorta lub dalej bede dokonywane zmiany
	{
		gap = max(int(gap / 1.3), 1); // ustalenie dlugosci na jaka beda sprawdzane liczby
		top = MAX - gap; //ustalenie ilosci zamian wzgledem gap i MAX-rozmiarowi tablicy
		swapped = false;
		for (int i = 0; i < top; i++)
		{
			int j = i + gap;
			if (tab[i] > tab[j]) // jesli zla kolejnos
			{
				int temp = tab[i]; tab[i] = tab[j]; tab[j] = temp; //swap(tab[i],tab[j])
				swapped = true;
			}
		}
	}
}

int main()
{
	int tab[] = { 2,7,2,4,3,8 };
	Combsort(tab);
	for (int i = 0; i < MAX; i++)
	{
		cout << tab[i] << " ";
	}
	return 0;
}

