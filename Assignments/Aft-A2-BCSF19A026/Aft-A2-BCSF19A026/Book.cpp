/*
	Abdul Aziz
	BCSF19A026
	CS Afternoon Add/Drop
*/
#include "Book.h"
Book::Book(string t, string a, string I) :Media(t), author(a), ISBN(I)
{}
void Book::display()const
{
	cout << "Tittle: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "ISBN: " << ISBN << endl;
}