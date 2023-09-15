#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Account
{
protected:
	string title;
	char AcNo[17];// 16 bit for account no and 1 bit for \0.
	double balance;
public:
	Account(string = "\0", char* = NULL, double = 0.0);
	void setAccount();
	string getTitle()const;
	const char* getAcNo()const;
	double getBalance()const;
	void display()const;
	double deposit();
	double withdrawal();
};

