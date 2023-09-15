#include "DateType.h"
DateType::DateType(int d, int m, int y)
{
	setYear(y);
	setMonth(m);
	setDay(d);

}
void DateType::setDay(int d)
{
	if (d > 0 && d <= 31)
	{
		if (month == 2 && isLeap(year))
		{
			if (d < 30)
				day = d;
			else
				day = 1;
		}
		else if (month == 2 && !isLeap(year))
		{
			if (d < 29)
				day = d;
			else
				day = 1;
		}
		else if (month == 9 || month == 6 || month == 4 || month == 11)
		{
			if (d < 31)
			{
				day = d;
			}
			else
				day = 1;
		}
		else
		{
			day = d;
		}
	}
	else
	{
		day = 1;
	}
}
void DateType::setMonth(int m)
{
	if (m <= 0 || m > 12)
		month = 1;
	else
		month = m;
}
void DateType::setYear(int y)
{
	if (y >= 0)
		year = y;
	else
		year = 0;
}
int DateType::getDay()const
{
	return day;
}
int DateType::getMonth()const
{
	return month;
}
int DateType::getYear()const
{
	return year;
}
bool DateType::isLeap(int y)const
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
int DateType::daysInMonth()const
{
	if (month == 2 && isLeap(year))
		return 29;
	else if (month == 2 && !isLeap(year))
		return 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31;
}

int DateType::passedDaysInYear()const
{
	int pDays = 0;
	for (int i = 1; i < month; i++)
	{
		if (i == 2)
			if (isLeap(year))
				pDays += 29;
			else
				pDays += 28;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			pDays += 30;
		else
			pDays += 31;
	}
	return pDays + day;
}
int DateType::remainingDayInYear()const
{
	if (isLeap(year))
		return 366 - passedDaysInYear();
	else
		return 365 - passedDaysInYear();
}
DateType DateType::newDate(int d)
{
	DateType temp = *this;
	while (d > 0)
	{
		if (temp.month == 2)
		{
			if (isLeap(temp.year))
			{
				if (temp.day < 29)
					temp.day++;
				else
				{
					temp.day = 1;
					temp.month++;
				}
			}
			else
			{
				if (temp.day < 28)
					temp.day++;
				else
				{
					temp.day = 1;
					temp.month++;
				}
			}
	    }
		else if (temp.month == 4 || temp.month == 9 || temp.month == 11 || temp.month == 6)
		{
			if (temp.day < 30)
				temp.day++;
			else
			{
				temp.day = 1;
				temp.month++;
			}
		}
		else
		{
			if (temp.month == 12 && temp.day == 31)
			{
				temp.day = 1;
				temp.month = 1;
				temp.year++;
			}
			else
			{
				if (temp.day < 31)
					temp.day++;
				else
				{
					temp.day = 1;
					temp.month++;
				}
			}
		}
		d--;
	}
	return temp;
}
void DateType::display()const
{
	cout << month << "-" << day << "-" << year << endl;
}