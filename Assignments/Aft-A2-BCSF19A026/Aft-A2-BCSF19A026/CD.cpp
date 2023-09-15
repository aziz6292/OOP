/*
	Abdul Aziz
	BCSF19A026
	CS Afternoon Add/Drop
*/
#include "CD.h"
CD:: CD(string t, int c):Media(t), capacity(c)
{}
void CD::display()const
{
	cout << "Tittle: " << title << endl;
	cout << "Capicity in MB: " << capacity << endl;
}