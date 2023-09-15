#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <fstream>
#include "TelDirectory.h"

using namespace std;

//Global Variables
const int N = 30;
const int MAX = 100;
ofstream fout;


//main functions Prototypes

char manu();
void writingData(TelDirectory*);
void byName(TelDirectory*);
void byNum(TelDirectory*);
void display(TelDirectory*);

int main()
{
	cout << "********************\n";
	cout << "* AsSalamo Alaikum *\n";
	cout << "********************\n";
	cout << endl;
	char repeat = 0;
	TelDirectory* arr;
	arr = new TelDirectory[MAX];
	do
	{
		char choice = manu();
		cout << endl;
		if (choice == '1')
		{
			writingData(arr);
		}
		else if (choice == '2')
		{
			byName(arr);
		}
		else if (choice == '3')
		{
			byNum(arr);
		}
		else
		{
			display(arr);
		}

		/****************************
			Asking for another Task *
		*****************************/
		cout << "Do you want to repeat the program or quit? (R/Q) ";
		cin >> repeat;
		while (!(toupper(repeat) == 'R' || toupper(repeat) == 'Q'))
		{
			cout << "Please enter R or Q: ";
			cin >> repeat;
		}
	} while (toupper(repeat) == 'R');

	delete[] arr;
	arr = nullptr;
	return 0;
}
char manu()
{
	char choice;
	cout << "Chose the option\n\n";
	cout << "Press 1 for Writing Data on the file\n";
	cout << "Press 2 for Searching By Name\n";
	cout << "Press 3 for Searching By Number\n";
	cout << "Press 4 to Display all directories\n";
	cout << "Your Selection: ";
	cin >> choice;
	while (choice < '1' || choice>'4')
	{
		cout << "ERROR! invalid input\n";
		cout << "Re-enter in range of 1-3: ";
		cin >> choice;
	}
	return choice;
}


void writingData(TelDirectory* arr)
{
	fout.open("teledir.txt");
	if (!fout)
	{
		cout << "ERROR! Some Technical Error!\n";
		cout << "The file could not be created Successfully\n";
	}
	else
	{

		char name[MAX][N] = { 0 };
		long long no[MAX];
		char address[MAX][N];
		int list;
		cout << "Kindly Tell us How many Directory you want to Stored: ";
		cin >> list;
		cin.ignore();
		for (int i = 0; i < list; i++)
		{
			cout << "Enter Name of Person #" << i + 1 << ": ";
			cin.getline(name[i], N);
			arr[i].setName(name[i]);
			fout << "Name: " << arr[i].getName() << endl;
			cout << name[i] << "\'s no: ";
			cin >> no[i];
			arr[i].setNum(no[i]);
			fout << arr[i].getName() << "'s Number: " << arr[i].getNum() << endl;
			cout << "Address: ";
			cin.ignore();
			cin.getline(address[i], N);
			arr[i].setAddress(address[i]);
			fout << arr[i].getName() << "'s Address: " << arr[i].getAddress() << endl << endl;
			cout << endl;
		}
		fout.close();
	}
}

void byName(TelDirectory* arr)
{
	char key[N];
	cout << "Enter the Name You want to Search: ";
	cin.ignore();
	cin.getline(key, N);
	cout << "Search Result:\n";
	for (int i = 0; i < MAX; i++)
	{
		if (arr[i].getNum() > 0)
		{
			arr[i].searchByName(key);
		}
	}
}


void byNum(TelDirectory* arr)
{
	long long noKey;
	cout << "Enter the Number You want to Search: ";
	cin >> noKey;
	cout << "Search Result:\n";
	for (int i = 0; i < MAX; i++)
	{
		if (arr[i].getNum() > 0)
		{
			arr[i].searchByNumber(noKey);
		}
	}
}

void display(TelDirectory* arr)
{
	for (int i = 0; i < MAX; i++)
	{
		if (arr[i].getNum() > 0)
		{
			arr[i].printDirectory();
		}
	}
}