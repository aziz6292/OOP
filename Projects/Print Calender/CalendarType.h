#pragma once
#include "DayType.h"
#include "extDateType.h"
class CalendarType
{
	DayType day;
	extDateType date;
public:
	CalendarType(int = 1, int = 1500);
	void determine1stDay();
	void setMonth(int);
	void setYear(int);
	int getMonth();
	int getYear();
	void printCalender();
};

