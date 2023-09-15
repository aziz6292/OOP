#include "Saving.h"
Saving::Saving()
{
	interest = 0.0;
}
void Saving::interestCalc()
{
	double rate;
	cout << "Enter the interest Rate on the Balance: ";
	cin >> rate;
	while (rate < 0)
	{
		cout << "Invalid\n the rate should be positive: ";
		cin >> rate;
	}
	interest = rate * balance/100.0;
}
void Saving::display()const
{
	Account :: display();
	cout << "Interest: " << interest << endl;
}