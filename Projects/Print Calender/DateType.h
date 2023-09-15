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
class DateType 
{
protected:
	int day, month, year;
public:
	DateType(int = 1, int = 1, int = 0);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	bool isLeap(int)const;
	int daysInMonth()const;
	int passedDaysInYear()const;
	int remainingDayInYear()const;
	virtual void display()const;
	virtual void month_yearStr()const{}
	DateType newDate(int);
};

