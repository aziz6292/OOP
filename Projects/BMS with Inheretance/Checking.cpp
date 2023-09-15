#include "Checking.h"
Checking::Checking()
{
	fee = 0;
}
double Checking::transictionCharges()
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
void Checking::withdrawal()
{

	double temp = Account::withdrawal() * transictionCharges()/100.0;
	balance -= temp;
	fee = fee + temp;
	cout << "Transiction Charges: " << temp << endl;
}
void Checking::deposit()
{
	double temp = Account::deposit() * transictionCharges()/100.0;
	balance -= temp;
	fee = fee + temp;
	cout << "Transiction Charges: " << temp << endl;
}
void Checking  :: display() const
{
	Account::display();
	cout << "Total Transiction Charges (Deposit/Withdrawal): " << fee << endl;
}
