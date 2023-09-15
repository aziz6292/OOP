#include "Current.h"
Current::Current(int m): Account("", 0, m), min(500)
{
	fee = 0;
}
void Current::setAccount()
{
	cout << "Enter the Name of the Account Holder: ";
	cin.ignore();
	getline(cin, title);
	bool flag = false;
	while (!flag)
	{
		flag = true;
		cout << "Enter the Account No (only 16-digit ): ";
		cin >> AcNo;
		for (int i = 0; i < 16; i++)
		{
			if (AcNo[i] < '0' || AcNo[i] > '9')
			{
				flag = false;
				break;
			}
		}
		if (!flag)
		{
			cout << "Invalid Acount No!\n";
			cout << "Account No should be only Digit and should be 16 digit.\n";
		}
		else
		{
			break;
		}
	}
	cout << "Enter the Balance for " << title << " ; " << AcNo << ": ";
	cin >> balance;
	while (balance < 500)
	{
		cout << "invalid\nBalance Should be at least 500\nRe-enter: ";
		cin >> balance;
	}
}
double Current::transictionCharges()
{
	double temp;
	cout << "Enter the Charges Rate/Transiction_Amount (Checking Account): ";
	cin >> temp;
	while (fee < 0)
	{
		cout << "Invalid\nRe-enter: ";
		cin >> temp;
	}
	return temp;
}
void Current::withdrawal()
{
	double wdr;
	cout << "Enter the amount to Withdrawal: ";
	cin >> wdr;
	while (wdr < 0 || wdr > balance - 500)
	{
		cout << "Invalid\nThe amount is either negative or greater than the availible balance\n";
		cout << "Re-enter: ";
		cin >> wdr;
	}
	balance -= wdr;
	double temp = wdr * transictionCharges()/100.0;
	balance -= temp;
	fee = fee + temp;
	cout << "Transiction Charges: " << temp << endl;
}
void Current::deposit()
{
	double temp = Account::deposit() * transictionCharges()/100.0;
	balance -= temp;
	fee = fee + temp;
	cout << "Transiction Charges: " << temp << endl;
}
void Current:: display()const
{
	Account::display();
	cout << "Total Transiction Charges (Deposit/Withdrawal): " << fee << endl;
	cout << "The Minmum Balance for Investment Acount: " << min << endl;
}