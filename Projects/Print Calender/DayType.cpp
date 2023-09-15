#include "DayType.h"
DayType::DayType(string d)
{

	setDay(d);
}
void DayType::setDay(string d)
{
	if (d == "sunday" || d == "Sunday" || d == "sun" || d == "Sun")
		day = "Sunday";
	else if (d == "monday" || d == "Monday" || d == "mon" || d == "Mon")
		day = "Monday";
	else if (d == "tuesday" || d == "Tuesday" || d == "tue" || d == "Tue")
		day = "Tuesday";
	else if (d == "wednesday" || d == "Wednesday" || d == "wed" || d == "Wed")
		day = "Wednesday";
	else if (d == "thursday" || d == "Thursday" || d == "thu" || d == "Thu")
		day = "Thursday";
	else if (d == "friday" || d == "Friday" || d == "fri" || d == "Fri")
		day = "Friday";
	else if (d == "saturday" || d == "Saturday" || d == "sat" || d == "Sat")
		day = "Saturday";
	else
		day = day.empty();
}
void DayType::printDay()const
{
	if (!day.empty())
	{
		cout << setw(10) << day;
	}
	else
	{
		cout << "1st Set the Day i.e for Sunday (sun, Sun , sunday, Sunday) to set Day!!\n";
	}
}
const string DayType::getDay()const
{
	if (!day.empty())
	{
		return day;
	}
	else
	{
		cout << "1st Set the Day i.e for Sunday (sun, Sun , sunday, Sunday) to set Day!!\n";
		return day;
	}
}
const string DayType::nextDay()
{
	string day1 = "\0";
	if (!day.empty())
	{
		if (day == "Sunday")
			day1 = "Monday";
		else if (day == "Monday")
			day1 = "Tuesday";
		else if (day == "Tuesday")
			day1 = "Wednesday";
		else if (day == "Wednesday")
			day1 = "Thursday";
		else if (day == "Thursday")
			day1 = "Friday";
		else if (day == "Friday")
			day1 = "Saturday";
		else
			day1 = "Sunday";
	}
	else
	{
		cout << "1st Set the Day i.e for Sunday (sun, Sun , sunday, Sunday) to set Day!!\n";
	}
	return day1;
}
const string DayType::previousDay()
{
	string day1 = "\0";
	if (!day.empty())
	{
		if (day == "Sunday")
			day1 = "Saturday";
		else if (day == "Monday")
			day1 = "Sunday";
		else if (day == "Tuesday")
			day1 = "Monday";
		else if (day == "Wednesday")
			day1 = "Tuesday";
		else if (day == "Thursday")
			day1 = "Wednesday";
		else if (day == "Friday")
			day1 = "Thursday";
		else
			day1 = "Friday";
	}
	else
	{
		cout << "1st Set the Day i.e for Sunday (sun, Sun , sunday, Sunday) to set Day!!\n";
	}
	return day1;
}
const string DayType::calculateDay(long long int a)
{
	string day1 = day;
	if (!day.empty())
	{
		int temp = a % 7, i = 0;
		if (temp < 0)
		{
			while (i > temp)
			{
				day1 = previousDay();
				setDay(day1);
				i--;
			}

		}
		else if (temp > 0)
		{
			i = 0;
			while (i < temp)
			{
				day1 = nextDay();
				setDay(day1);
				i++;
			}
		}
	}
	else
	{
		cout << "1st Set the Day i.e for Sunday (sun, Sun , sunday, Sunday) to set Day!!\n";
	}
	return day1;
}