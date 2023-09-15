#include <iostream>
#include "TelDirectory.h"
using namespace std;

//Class Functions 
TelDirectory::TelDirectory()
{
	strcpy(name, " ");
	strcpy(address, " ");
	num = 0;
}

TelDirectory::TelDirectory(char* n, char* m, long long no)
{
	strcpy(name, n);
	strcpy(address, m);
	num = no;
}

const char* TelDirectory::getName()const
{
	return name;
}

const char* TelDirectory::getAddress()const
{
	return address;
}

const int TelDirectory::getNum()const
{
	return num;
}

void TelDirectory::setName(char* n)
{
	strcpy(name, n);
}

void TelDirectory::setAddress(char* m)
{
	strcpy(address, m);
}

void TelDirectory::setNum(long long n)
{
	num = n;
}

const long long TelDirectory::searchByName(char* n)const
{
	if (strcmp(n, name) == 0)
	{
		cout << num;
		cout << endl;
		return num;
	}

}

const char* TelDirectory::searchByNumber(long long n)const
{
	if (n == num)
	{
		cout << name;
		cout << endl;
		return name;
	}
}

void TelDirectory::printDirectory()const
{
	cout << "Name: " << name << endl;
	cout << "Telephone No: " << num << endl;
	cout << "Address: " << address << endl;
	cout << endl;
}