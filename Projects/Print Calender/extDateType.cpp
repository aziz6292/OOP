#include "extDateType.h"
extDateType::extDateType(int d, int m, int y) :DateType(d, m, y)
{
	setMonth(m);

}
void extDateType::setMonth(int m)
{
	DateType::setMonth(m);
	switch (m)
	{
	case 1: { monthStr = "January"; }
		  break;
	case 2: { monthStr = "February"; }
		  break;
	case 3: { monthStr = "March"; }
		  break;
	case 4: { monthStr = "April"; }
		  break;
	case 5: { monthStr = "May"; }
		  break;
	case 6: { monthStr = "June"; }
		  break;
	case 7: { monthStr = "July"; }
		  break;
	case 8: { monthStr = "August"; }
		  break;
	case 9: { monthStr = "September"; }
		  break;
	case 10: { monthStr = "October"; }
		   break;
	case 11: { monthStr = "November"; }
		   break;
	case 12: { monthStr = "December"; }
		   break;
	}
}
void extDateType::display()const
{
	cout << monthStr << " " << day << ", " << year << endl;
}
void extDateType::month_yearStr()const
{
	cout << monthStr << " " << year << endl;
}
