#include "Account.h"
Account :: Account(string t, char* ac, double b)
{
	title = t;
	if (ac != NULL)
	{
		for (int i = 0; ac[i] != '\0'; i++)
		{
			if (!isdigit(ac[i]))
			{
				strcpy(AcNo, "");
				break;
			}
			AcNo[i] = ac[i];
		}
	}
	if (b > 0)
	{
		balance = b;
	}
	else
	{
		balance = 0.0;
	}
}
void Account :: setAccount()
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
	while (balance < 0)
	{
		cout << "invalid\nBalance Should not be negative\nRe-enter: ";
		cin >> balance;
	}

}
string Account :: getTitle()const
{
	return title;
}
const char* Account:: getAcNo()const
{
	return AcNo;
}
double Account:: getBalance()const
{
	return balance;
}
void Account :: display()const
{
	cout << "<" << title << ";" << AcNo << ";" << balance << ">\n";
}
double Account :: deposit()
{
	double dep;
	cout << "Enter the amount to Deposit: ";
	cin >> dep;
	while (dep < 0)
	{
		cout << "Invalid\n";
		cout << "Re-enter: ";
		cin >> dep;
	}
	balance += dep;
	return dep;
}
double Account :: withdrawal()
{
	double wdr;
	cout << "Enter the amount to Withdrawal: ";
	cin >> wdr;
	while (wdr < 0 || wdr > balance)
	{
		cout << "Invalid\nThe amount is either negative or greater than the availible balance\n";
		cout << "Re-enter: ";
		cin >> wdr;
	}
	balance -= wdr;
	return wdr;
}