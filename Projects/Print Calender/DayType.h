#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class DayType
{
private:
	string  day;
public:
	DayType(const string = "");
	void setDay(const string);
	void printDay()const;
	const string getDay()const;
	const string nextDay();
	const string previousDay();
	const string calculateDay(long long  int);
};

