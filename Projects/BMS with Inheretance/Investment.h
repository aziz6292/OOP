#pragma once
#include "Account.h"
class Investment : public Account
{
	double fee;
	int min;
	double percentProfit;
public:
	Investment(int);
	double transictionCharges();
	void deposit();
	void withdrawal();
	void setAccount();
	void profit();
	void display()const;
};

