#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
	short day, month, year;     // will take 2 bytes for each member 
	bool leapYear(short)const;  // private member function to find out the year is leap or not
	static Date defaultDate;    // Static object of Date class to store defaultDate
public:
	//Default Constructer
	/*
	1 -> Dafault Consturcter is use to initilize all the member of the class with default value.
	2 -> Having no perameter in the perameter list.
	3 -> Having no return type.
	4 -> Called at the time of object creation by itself when we just daclere an object in the main OR elsewhere.
	5 -> Compiler Do write the Default constructer for each of our Class and keep
			it empty (some compiler set default value to the members of the Class as well).
	6 -> In case we have to use the peremetrize Constructer in our Class in such sciniaro Compiler
			do not write the Default Constructer for us in such case we have to implement the Default Constructer by ownself.
	7 -> Default Constructer must be not const function as we inilize the members of the class in it.
	8 -> It only Called once for each object durring declaration.
	9 -> In it the (this pointer) get the Address of the object for which the Constructer Called.
	*/
	inline Date();
	//Perametrized/Overloaded Constructer
	/*
	1 -> Same points of Default Constructer except having Perameter list.
	2 -> The no of peremeter depend upon the requirment of the program.
	3 -> at most it will have as much peremeter as the Class member.
	4 -> at least one peremeter will pass through it.
	*/
	inline Date(short, short, short);

	//Copy Constructer
	/*
	1 -> A compiler write copy Constructer for us as well
	2 -> By default it will do nothing except to make a shellow copy.
	3 -> It recieved a const object by reference and inilized the object for which that Copy Constructer
			has been Called to make exectly copy of that object.
	4 -> Only when we use pointer in our class members the copy constructer is needed to write for our class
			and we should to make it suitable for the pointer to make deep copy instead of shallow copy to
			resolve the issue of dingling pointer i.e
			Student a;
			Student *p, *q;
			p = new Student;
			p = &a;
			q = new Student;
			q = &a;
			delete p;
			p = NULL;
			in the above example
			q is a dingling pointer having the address of object a but a is deleted by pointer p before.
			so, q is pointing to a memory which does'nt exist.
			therefore q is a dingling pointer.
	*/
	Date(const Date&);

	//Setter Functions/Mutators Functions
	/*
	1 -> having return type void.
	2 -> can not make it constent.
	3 -> in the peremeter list it will pass the varriable of data type same as the class memeber
			for which it have to set value.
	*/
	inline void setDay(short);
	inline void setMonth(short);
	inline void setYear(short);

	//Getter Functions/Accessors Functions
	/*
	1 -> Always make it const functions.
	2 -> Always having return type as same as the class member data type to get.
	3 -> we should keep that return type const to make sure the idea of information hiding for further use.
	*/
	inline const short getDay()const;
	inline const short getMonth()const;
	inline const short getYear()const;

	//Other Functions
	inline void addDay(short);
	inline void addMonth(short);
	inline void addYear(short);
	//Display Function should be const (as a good programming practice
	inline void display()const;
	// Static function.
	/*
	1 -> to set value / get Value in a const member of the Class we should use the static functions
			in case when the declaration of the static member of the class occure private.
	2 -> in case of static functions we should only to add the static keyword before the class return type
			only in the prototype of the memeber functions that's enough.
	3 -> same for inline keyword only use it with the prototypes of the member functions.
	*/
	inline static void setDefaultDate(short, short, short);
	inline const static Date getDefaultDate();

	//Destructer
	/*
	1 -> Compiler write Destructer for our class too.
	2 -> Having no perameter in the perameter list.
	3 -> Having no return type.
	4 -> Called at the time of object destrying by itself.
	5 -> Compiler Do write the Default Destructer for each of our Class and keep that empty.
	6 -> In case we have to use the peremetrize Constructer in our Class in such sciniaro Compiler
	7 -> we have only to write the destructer for our class only when we use a pointer in our class members.
	8 -> To deallocate/delete the memory that we created on heap by pointer of our class we have to overwrite the
			destructer and use it for that purpose.
			i.e
			if ( ptr !=NULL)
			{
				delete ptr; OR //delete [] ptr; //if ptr points to an array on heap
				ptr = NULL;
			}
	9 -> in the above example ptr is must be the pointer inside the Class.
	10-> Destructer is use to resolve the issue of memory leakage as we know if we creat memory
			on heap using pointer of the in the class member and do not
			delete it before the destructer called in such case memory leakage occure in our program.
	*/
	inline ~Date();

};


// leap Year Calculation :) private member function
bool Date::leapYear(short a)const
{
	// a is nothing but the year which we pass in the peremater to that function
	if (a % 4 == 0)// condition to check the year is divisible by 4 OR not
	{
		if (a % 100 == 0) // condition to check for 100
		{
			// now if divisible by 100 as well as by 400 than leap year else not leap year
			// i.e 1900, 2100 is divisible by 100 and 4 but still not leap year
			// 2000 is divisible by 4 , 100 and 400 so leap year.
			if (a % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else // if only divisible by 4 and not by 100 no need to check further it is leap year.
		{
			return true;
		}
	}
	else // if not divisible by 4 it is not leap year at all.
	{
		return false;
	}
}
Date::Date() :day(1), month(1), year(0)
{

}
Date::Date(const Date& d)
{

	setDay(d.day);
	setMonth(d.month);
	setYear(d.year);
}
Date::Date(short d, short m, short y)
{
	setDay(d);
	setMonth(m);
	setYear(y);
}

void Date::setDay(short d)
{
	if (d > 0 && d <= 31) // if day is 0 , less than 0 OR greater than 31 it is invalid
	{
		if (month == 2 && leapYear(year)) // in Februry Day should be less or equal to 29 only if leap year else 28
		{
			if (d < 30)
			{
				day = d;
			}
		}
		else if (month == 2 && !leapYear(year))// if Februry but not leap year.
		{
			if (d < 29)
				day = d;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) // For all month of 30 Days.
		{
			if (d != 31)
			{
				day = d;
			}
		}
		else // as we already check the condition for 31 above so in else part no need to check further more
		{
			day = d;
		}
	}
	else
	{
		day = 1;
	}

}
void Date::setMonth(short m)
{
	if (m > 0 && m <= 12) // month validation
	{
		month = m;
	}
	else
	{
		month = 1;
	}
}
void Date::setYear(short y)
{
	if (y > 0)
		year = y;
	else
		year = 0;
}
const short Date::getDay()const
{
	return day;
}
const short Date::getMonth()const
{
	return month;
}
const short Date::getYear()const
{
	return year;
}
void Date::addDay(short d)
{

	if (month == 2) // for Februry 2 possiblity leap year / nor leap year
	{
		if (leapYear(year)) // if Leap year
		{
			if (day + d > 29) // if privous day and the adding days (d) combinelly greater than 29.
			{
				addMonth(1); // increament in month 
				d = d - 29; // decrement in day 29 because of februry and leap year.
				addDay(d);
			}
			else  // if less than 29 just add it to the privous days.
			{
				day += d; // increament in days
			}

		}
		else //Now if not leap year and month is Februry.
		{
			//same logic but we replace 29 by 28 as we check not leap year.
			if (day + d > 28)
			{
				addMonth(1);
				d = d - 28;
				addDay(d);
			}
			else
			{
				day += d;
			}
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) // For months of 30 days
	{
		// Same logic as above but we use now for 30.
		if (day + d > 30)
		{
			addMonth(1);
			d = d - 30;
			addDay(d);
		}
		else
		{
			day += d;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)// months of 31 days
	{
		// For 31
		if (day + d > 31)
		{
			addMonth(1);
			d = d - 31;
			addDay(d);
		}
		else
		{
			day += d;
		}
	}


}
void Date::addMonth(short m)
{
	month = month + m;
	if (month > 12)// if month is greater than 12 become an year
	{
		// year become incremented by the (month/12)
		//=> i.e  month = 100 ,  year = year + ( 100/12)  => (year = year + 8)
		year = year + (month / 12);
		// to keep month below 12 we should take modulus with 12
		// i.e month = 100 => month = month % 12 =>(month = 4)
		month = month % 12;
	}
}
void Date::addYear(short y)
{
	year = year + y;
}
void Date::setDefaultDate(short d, short m, short y)
{
	defaultDate.setDay(d);
	defaultDate.setMonth(m);
	defaultDate.setYear(y);
}
Date ::~Date()
{

}
void Date::display()const
{
	cout.fill('0'); // just to keep the right formatting of date 
	cout << fixed << right;
	cout << "Date: " << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << endl;
}
const Date Date::getDefaultDate()
{
	return defaultDate; // returning default date using static member function.
}


//We have to inilized the static variable/object of the Class in the following way.
//(data type of the staic variable/object) followed by (Class name) followed by scope resolution (::) followed by (name of static variable/object) = (default value)
Date Date::defaultDate(1, 1, 0);


//Global Functions
char manu();
void ageCalculation();
int main()
{
	Date date;// rendom Date 
	while (1)
	{
		char choice = manu();// the manu function will called and return will return 1, 2, 3, 4 or 5 to store in choice.
		short temp = 0; // to set the value for setter functions
		if (choice == '0')
		{
			cout << "Before the Date\n\t";
			date.display();
			cout << "\tSetting Data\n";
			cout << "Set your Date\n";
			cout << "Day: ";
			cin >> temp;
			date.setDay(temp);
			cout << "Month: ";
			cin >> temp;
			date.setMonth(temp);
			cout << "Year: ";
			cin >> temp;
			date.setYear(temp);
			cout << "After setting the Date\n\t";
			date.display();
		}
		else if (choice == '1')
		{
			cout << "Before the Date\n\t";
			date.display();
			cout << "Enter the Day/Days to Add in Date: ";
			cin >> temp;
			date.addDay(temp);
			cout << "After Adding the Date\n\t";
			date.display();
		}
		else if (choice == '2')
		{
			cout << "Before the Date\n\t";
			date.display();
			cout << "Enter the Month/Months to Add in Date: ";
			cin >> temp;
			date.addMonth(temp);
			cout << "After Adding the Date\n\t";
			date.display();
		}
		else if (choice == '3')
		{
			cout << "Before the Date\n\t";
			date.display();
			cout << "Enter the Year/Years to Add in Date: ";
			cin >> temp;
			date.addYear(temp);
			cout << "After Adding the Date\n\t";
			date.display();
		}
		else if (choice == '4')
		{
			//Now You Can Set the Default Date as Well and also Display it when ever for any 
			// reason you want.
			short d, m, y;
			cout << "Enter Day, month and year Respectivally to set the Default Date: ";
			cin >> d >> m >> y;
			Date::setDefaultDate(d, m, y);
			// To Display the Default Date we first to store it by calling getDefaultDate Function.
			Date dftDate = Date::getDefaultDate();
			cout << "\n**********************\n";
			cout << "Default Date\n\t";
			dftDate.display();
			cout << "\n**********************\n\n\n\n";
		}
		else if (choice == '5')
		{
			ageCalculation();
		}
		else
		{
			exit(0);
		}
		cout << endl << endl << endl;
	}
	return 0;
}
char manu()
{
	char a;
	cout << "Select from the following manu\n";
	cout << "Press '0' to Set a Date of your Choice\n";
	cout << "Press '1' for Adding Day OR no of Days\n";
	cout << "Press '2' for Adding Month OR no of Months\n";
	cout << "Press '3' for Adding Year OR no of Year\n";
	cout << "Press '4' To set the Default Date\n";
	cout << "Press '5' To Calculate Your Age\n";
	cout << "Press '6' to 'Quit' the program!\n";
	cout << "Your Selection: ";
	cin >> a;
	while (a < '0' || a> '6')
	{
		cout << "Invalid\n";
		cout << "Re-select: ";
		cin >> a;
	}
	cout << endl << endl;
	return a;
}

void ageCalculation()
{

	Date dob; // Date of Birth by Dafaul Constructer
	Date currentDate; // Current Date (today Date) By DC.
	Date age(1, 1, 0); // Object to keep Age in form of (years, months and days) By Peremetrizedd Constructer.
	long long a = 0, b = 0;

	// Getting Date of Birth of the User
	short setDate;
	cout << "\n\n\tGetting Data\n";
	cout << "Set your Date of Birth\n";
	cout << "Day: ";
	cin >> setDate;
	dob.setDay(setDate);
	cout << "Month: ";
	cin >> setDate;
	dob.setMonth(setDate);
	cout << "Year: ";
	cin >> setDate;
	dob.setYear(setDate);

	//Convertting into Days the DOB of user.
	long long  temp;
	temp = dob.getYear();
	a = temp * 365;
	temp = dob.getDay();
	a = a + temp;
	temp = dob.getMonth();
	a = a + (temp * 30);

	//Getting Current Date from the user
	cout << "\nSet Today's Date'\n";
	cout << "Day: ";
	cin >> setDate;
	currentDate.setDay(setDate);
	cout << "Month: ";
	cin >> setDate;
	currentDate.setMonth(setDate);
	cout << "Year: ";
	cin >> setDate;
	currentDate.setYear(setDate);

	//Convertting into Days the Current Date of user.
	temp = currentDate.getYear();
	b = temp * 365;
	temp = currentDate.getDay();
	b = b + temp;
	temp = currentDate.getMonth();
	b = b + (temp * 30);

	//Current - DOB
	b = b - a;
	//Now setting The Vaue in Age of the User
	age.setYear(b / 365);
	b = b % 365;
	age.setMonth(b / 30);
	b = b % 30;
	age.setDay(b);

	//Displaying output
	cout << "\n\n\n\tDisplaying Output\n";
	cout << "**********************\n";
	cout << "Date of Birth\n\t";
	dob.display();
	cout << "\nCurrent Date\n\t";
	currentDate.display();

	//Displaying Your Age exectly in the form of years, months and Days.
	cout << "\nYour Age\n\t";
	cout << "You are  " << age.getYear() << " years, " << age.getMonth() << " months & " << age.getDay() << " days old\n";
	cout << "\n**********************\n";
}
