// possible.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
bool possible(char *u, char *v, char *w)
{
	int tab[26];
	for (int i = 0; i < 26; i++)tab[i] = 0;
	for (int i = 0; i < strlen(u); i++)tab[int(u[i]) - int('a')]++;
	for (int i = 0; i < strlen(v); i++)tab[int(v[i]) - int('a')]++;
	for (int i = 0; i < strlen(w); i++)tab[int(w[i]) - int('a')]--;
	for (int i = 0; i < 26; i++)
		if (tab[i] < 0)	return false;
	return true;
}

int main()
{
	char *u = "ala", *v = "ola", *w = "lola";
	if (possible(u, v, w))
		cout << "mozna";
	else
		cout << " niemozna";
    return 0;
}

