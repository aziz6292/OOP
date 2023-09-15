/*
	Abdul Aziz
	BCSF19A026
	CS Afternoon Add/Drop
*/
#include "Book.h"
#include "Magazine.h" 
#include "CD.h"
#include "Shelf.h"

//Global Function Prototype for Task 1.2
void searchByYear(Media**, int);
int main()
{
	char choice;
	//To check again for another input untill user want to exit:
	while (1)
	{
		cout << "\tSelect from the manu.\n";
		cout << "1|2. for task 01 and 02\n";
		cout << "3. for task 03\n";
		cout << "4. for task 04\n";
		cout << "0. exit\n";
		cout << "Your Selection: ";
		cin >> choice;
		while (choice < '0' || choice > '4')
		{
			cout << "Invalid Input! Enter again: ";
			cin >> choice;
		}
		string name, month, tittle, author, ISBN;
		int year, n = 0, capacity;
		Media** ptr = NULL;
		if (choice == '0')
		{
			cout << "Thank You\n";
			exit(0);
		}
		//Task 01:
		else if (choice == '1' || choice == '2')
		{
			cout << "\t\t****Task: 01****\n\n";
			cout << "How many Media items you wanna create: ";
			cin >> n;
			while (n < 0)
			{
				cout << "Invalid\nRe-enter:";
				cin >> n;
			}
			ptr = new Media * [n ];
			for (int i = 0; i < n ; i++)
			{
				system("cls");
				cout << "Menu\n****\nPlease select an option:\n\n1. Book\n2. Magazine\n\nGive your choice: ";
				cin >> choice;
				while (choice < '1' || choice > '2')
				{
					cout << "Invalid Input! Enter again: ";
					cin >> choice;
				}
				cin.ignore();
				if (choice == '1')
				{
					cout << "Book's Tittle: ";
					getline(cin, tittle);
					cout << "Author's Name: ";
					getline(cin, author);
					cout << "Enter ISBN: ";
					getline(cin, ISBN);
					ptr[i] = new Book(tittle, author, ISBN);
				}
				else
				{
					cout << "\nMagazine Name: ";
					getline(cin, name);
					cout << "Month i.e (Jan,Feb): ";
					getline(cin, month);
					cout << "Give Publication Year: ";
					cin >> year;
					while (year < 0)
					{
						cout << "Invalid\nRe-enter: ";
						cin >> year;
					}
					cin.ignore();
					ptr[i] = new Magazine(name, month, year);
				}
				cout << "Record saved sucessfully!\n\nPress enter key to continue...";
				cin.get();
			}
			system("cls");
			cout << "\t\t****OUT PUT****\n\n";
			for (int i = 0; i < n ; i++)
			{
				cout << "\t**Object #" << i + 1 << " Record**\n";
				ptr[i]->display();
				cout << endl << endl;
			}

			//Task 2
			cout << "\t\t****Task: 02****\n\n";
			searchByYear(ptr, n );
		}
		//Task 3
		else if (choice == '3')
		{
			cout << "\t\t****Task: 03****\n\n";
			cout << "How many Media items you wanna create: ";
			cin >> n ;
			while (n  < 0)
			{
				cout << "Invalid\nRe-enter:";
				cin >> n ;
			}
			ptr = new Media * [n ];
			for (int i = 0; i < n ; i++)
			{
				system("cls");
				cout << "Menu\n----\nPlease select an option:\n\n1. Book\n2. Magazine\n3. CD\n\nGive your choice: ";
				cin >> choice;
				while (choice < '1' || choice > '3')
				{
					cout << "Invalid Input! Enter again: ";
					cin >> choice;
				}
				cin.ignore();
				if (choice == '1')
				{
					cout << "\nBook's Tittle: ";
					getline(cin, tittle);
					cout << "Author's Name: ";
					getline(cin, author);
					cout << "Enter ISBN: ";
					getline(cin, ISBN);
					ptr[i] = new Book(tittle, author, ISBN);
				}
				else if (choice == '2')
				{
					cout << "\nMagazine Name: ";
					getline(cin, name);
					cout << "Month i.e(Jan,Feb): ";
					getline(cin, month);
					cout << "Give Publication Year: ";
					cin >> year;
					while (year < 0)
					{
						cout << "Invalid\nRe-enter: ";
						cin >> year;
					}
					cin.ignore();
					ptr[i] = new Magazine(name, month, year);
				}
				else
				{
					cout << "\nCD's Name: ";
					getline(cin, name);
					cout << "CD's Capacity in MB: ";
					cin >> capacity;
					while (capacity < 0)
					{
						cout << "Invalid\nRe-enter: ";
						cin >> capacity;
					}
					cin.ignore();
					ptr[i] = new CD(name, capacity);
				}
				cout << "Record saved sucessfully!\n\nPress enter key to continue...";
				cin.get();
			}
			system("cls");
			cout << "\t\t****OUT PUT****\n\n";
			for (int i = 0; i < n ; i++)
			{
				cout << "\t**Object #" << i + 1 << " Record**\n";
				ptr[i]->display();
				cout << endl << endl;
			}
		}
		//Task 04
		else
		{
			Media* p = NULL;
			int noOfObj = 0;
			cout << "\t\t****Task: 04****\n\n";
			cout << "How many Media items you wanna create: ";
			while (noOfObj < 0)
			{
				cout << "Invalid\nRe-enter:";
				cin >> noOfObj;
			}
			cin >> noOfObj;
			Shelf s(noOfObj);
			for (int i = 0; i < noOfObj; i++)
			{
				system("cls");
				cout << "Menu\n----\nPlease select an option:\n\n1. Book\n2. Magazine\n3. CD\n\nGive your choice: ";
				cin >> choice;
				while (choice < '1' || choice > '3')
				{
					cout << "Invalid Input! Enter again: ";
					cin >> choice;
				}
				cin.ignore();
				if (choice == '1')
				{
					cout << "\nBook's Tittle: ";
					getline(cin, tittle);
					cout << "Author's Name: ";
					getline(cin, author);
					cout << "Enter ISBN: ";
					getline(cin, ISBN);
					p = new Book(tittle, author, ISBN);
				}
				else if (choice == '2')
				{
					cout << "\nMagazine Name: ";
					getline(cin, name);
					cout << "Month i.e (Jan,Feb): ";
					getline(cin, month);
					cout << "Give Publication Year: ";
					cin >> year;
					while (year < 0)
					{
						cout << "Invalid\nRe-enter: ";
						cin >> year;
					}
					cin.ignore();
					p = new Magazine(name, month, year);
				}
				else
				{
					cout << "\nCD's Name: ";
					getline(cin, name);
					cout << "CD's Capacity in MB: ";
					cin >> capacity;
					while (capacity < 0)
					{
						cout << "Invalid\nRe-enter: ";
						cin >> capacity;
					}
					cin.ignore();
					p = new CD(name, capacity);
				}
				s.insert(p);
				cout << "Record saved sucessfully!\n\nPress enter key to continue...";
				cin.get();
			}
			system("cls");
			cout << "\t\t****OUT PUT****\n\n";
			s.displayContents();
			//as p is pass by reference to s(shelf) 
			//so p located memory is already deallocated in the
			//destructor of shelf
			//we just NULL it to preserve the issue of dingling pointer
			p = NULL;
		}
		if (n  > 0)
		{
			for (int i = 0; i < n ; i++)
			{
				if (ptr[i] != NULL)
				{
					delete ptr[i];
					ptr[i] = NULL;
				}
			}
			if (ptr != NULL)
			{
				delete[] ptr;
				ptr = NULL;
			}
		}
		cout << "\nPress any key to check for another input........";
		system("Pause>0");
		system("cls");
	}
	return 0;
}
void searchByYear(Media** m, int size)
{
	int yearToSearch;
	cout << "Searching for Magazine by year.\nEnter Year: ";
	cin >> yearToSearch;
	while (yearToSearch < 0)
	{
		cout << "Invalid\nRe-enter: ";
		cin >> yearToSearch;
	}
	for (int i = 0, j = 1; i < size; i++)
	{
		Magazine* mPtr = dynamic_cast<Magazine*> (m[i]);
		if (mPtr != NULL)
		{
			if (mPtr->getYear() == yearToSearch)
			{
				cout << "\n\t**Object #" << j << " Record**\n";
				m[i]->display();
				cout << endl;
				j++;
			}
		}
	}
}