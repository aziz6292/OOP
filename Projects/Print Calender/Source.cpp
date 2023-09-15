#include "CalendarType.h"
int main()
{
	while (1)
	{
		CalendarType thisMonth(2, 2022);
		cout << "Current Calender is\n";
		thisMonth.printCalender();
		int i = 1, j = 0;
		cout << "Set Month and Year to print Calender\n";
		cout << "Month: ";
		cin >> i;
		while (i < 1 || i > 12)
		{
			cout << "Invalid.......\n";
			cout << "Re-enter: ";
			cin >> i;
		}
		thisMonth.setMonth(i);
		cout << "Year: ";
		cin >> j;
		while (j < 0)
		{
			cout << "Invalid.......\n";
			cout << "Re-enter: ";
			cin >> j;
		}
		thisMonth.setYear(j);
		while (1)
		{

			system("cls");
			thisMonth.printCalender();
			char c;
			cout << "Select From the Following\n";
			cout << "1. to Next Month\n";
			cout << "2. to Previous Month\n";
			cout << "3. to Next Year\n";
			cout << "4. to Previous Year\n";
			cout << "5. to Set New Date\n";
			cout << "0. to exit\n";
			cin >> c;
			while (c < '0' || c > '5')
			{
				cout << "Invalid\nRe-enter: ";
				cin >> c;
			}
			switch (c)
			{
			case '0':
			{
				exit(0);
			}
			break;
			case '1':
			{
				i++;
				if (i == 13)
				{
					i = 1;
					j++;
				}
			}
			break;
			case '2':
			{
				i--;
				if (i == 0)
				{
					i = 12;
					j--;
				}
			}
			break;
			case '3':
			{
				j++;
			}
			break;
			case '4':
			{
				j--;
				if (j == -1)
					j = 0;
			}
			}
			if (c == '5')
			{
				system("cls");
				break;
			}
			thisMonth.setMonth(i);
			thisMonth.setYear(j);
		}
	}
	return 0;
}