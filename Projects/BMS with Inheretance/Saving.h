#pragma once
#include "Account.h"
class Saving
	:public Account
{
	double interest;
public:
	Saving();
	void interestCalc();
	void display()const;
};

