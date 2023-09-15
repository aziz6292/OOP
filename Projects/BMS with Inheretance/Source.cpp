#include "Checking.h"
#include "Current.h"
#include "Saving.h"
#include "Investment.h"

char manu();
int main()
{
	cout << fixed << showpoint << setprecision(2);
	Saving accSav;
	Checking accCheck;
	Current accCurrent(500);
	Investment accInvest(1000);

	while (1)
	{
		char choice = manu();
		switch (choice)
		{
		case '0': {exit(0); }
				break;
		case '1':
		{
			Saving  acc;
			acc.setAccount();
			acc.deposit();
			acc.withdrawal();
			acc.interestCalc();
			acc.display();
			accSav = acc;
		}
		break;
		case '2':
		{
			Checking  acc;
			acc.setAccount();
			acc.deposit();
			acc.withdrawal();
			acc.display();
			accCheck = acc;
		}
		break;
		case '3':
		{
			cout << "Enter the Amount to Create ie (min = 500): ";
			double a;
			cin >> a;
			while (a < 500)
			{
				cout << "Amount shoud be Greater than 500: ";
				cin >> a;
			}
			Current acc(a);
			acc.setAccount();
			acc.deposit();
			acc.withdrawal();
			acc.display();
			accCurrent = acc;
		}
		break;
		case '4':
		{
			cout << "Enter the Amount to Create ie (min = 1000): ";
			double a;
			cin >> a;
			while (a < 500)
			{
				cout << "Amount shoud be Greater than 1000: ";
				cin >> a;
			}
			Investment acc(a);
			acc.setAccount();
			acc.deposit();
			acc.withdrawal();
			acc.display();
			acc.profit();
			accInvest = acc;
		}
		}
		cout << "\n\nEnter any key to continue........\n";
		system("pause>0");
		system("cls");
	}
	return 0;
}
char manu()
{
	char a;
	cout << "Select From the Following.\n";
	cout << "1. for Saving Account\n";
	cout << "2. for Checking Account\n";
	cout << "3. for Current Account\n";
	cout << "4. for Investment Account\n";
	cout << "0. to exit\n";
	cout << "Your Selection: ";
	cin >> a;
	while (a < '0' || a>'4')
	{
		cout << "Invalid\nRe-Select: ";
		cin >> a;
	}
	return a;
}