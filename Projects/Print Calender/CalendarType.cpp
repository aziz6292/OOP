#include "CalendarType.h"
CalendarType::CalendarType(int m, int y) :day("Mon"), date(1, m, y)
{
}
void CalendarType::determine1stDay()
{
	long long int d = 0;
	if (date.getYear() >= 1500)
	{
		if (date.getYear() > 1500)
			for (int i = date.getYear() - 1; i >= 1500; i--)
			{
				if (date.isLeap(i))
					d = d + 366;
				else
					d = d + 365;
			}
		for (int i = date.getMonth() - 1; i >= 1; i--)
		{
			if (i == 2)
			{
				if (date.isLeap(date.getYear()))
					d = d + 29;
				else
					d = d + 28;
			}
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				d = d + 30;
			else
				d = d + 31;
		}
	}
	else
	{
		for (int i = 1499; i > date.getYear(); i--)
		{
			if (date.isLeap(i))
				d = d + 366;
			else
				d = d + 365;
		}
		for (int i = date.getMonth() ; i <= 12; i++)
		{
			if (i == 2)
			{
				if (date.isLeap(date.getYear()))
					d = d + 29;
				else
					d = d + 28;
			}
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				d = d + 30;
			else
				d = d + 31;
		}
		d = d * (-1);
	}
	day.setDay(day.calculateDay(d));
}
void CalendarType::setMonth(int m)
{
	date.setMonth(m);
}
void CalendarType::setYear(int y)
{
	date.setYear(y);
}
int CalendarType::getMonth()
{
	return date.getMonth();
}
int CalendarType::getYear()
{
	return date.getYear();
}
void CalendarType::printCalender()
{
	cout << endl << endl;
	day.setDay("Mon");
	determine1stDay();
	date.month_yearStr();
	for (int j = 0; j < 7; j++)
	{
		day.printDay();
		day.setDay(day.nextDay());
	}
	cout << endl;
	int a = date.daysInMonth();
	for (int i = 1; i <= a; i++)
	{
		cout << setw(10) << i;
		if (i % 7 == 0)
			cout << endl;
	}
	cout << endl << endl << endl;
}