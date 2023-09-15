//Abdul Aziz
//BCSF19A026 
#include "MyString.h"
int main()
{
	char choice;
	do
	{
		cout << "\tSelect from the Manu\n";
		cout << "Press 0 to exit\n";
		cout << "Press 1 to Check for Constructor Test\n";
		cout << "Press 2 to Check for Operator Test (=) and (+)\n";
		cout << "Press 3 to Check for Operator Test (<) and (<=)\n";
		cout << "Press 4 to Check for Operator Test (+=)\n";
		cout << "Press 5 to Check for setStr Test\n";
		cout << "Press 6 to Check for Operator int Test\n";
		cout << "Press 7 to Check for Operator char* Test\n";
		cout << "Press 8 to Check for Operator Test (pre ++)\n";
		cout << "Press 9 to Check for Operator Test (<<) and (>>)\n";
		cout << "Your Selection: ";
		cin >> choice;
		cout << "\nOUT PUT\n";
		if (choice == '1')
		{
			//Test 1 Constructors
			cout << "\t Constructors test\n";
			MyString s1;
			MyString s2("OOP is Fun!!");
			char name[15] = "pakistan";
			MyString s3(name);
			cout << s1.getLength() << endl;
			cout << s2.getLength() << endl;
			cout << s3.getLength() << endl;
		}
		if (choice == '2')
		{
			//Operators Test
			cout << "\n\tOperator test (+) on cascading\n";
			MyString ms1("One"), ms2("Two"), ms3("Three");
			MyString ms4;
			ms4 = ms1 + ms2 + ms3;
			cout << ms1 << ms2 << ms3 << ms4;
		}
		if (choice == '3')
		{
			cout << "\n\tConditional operator\n";
			MyString s1("abc");
			MyString s2("ABC");
			MyString s3("az");
			MyString s4("abc");
			cout << "(s1 == s2) " << (s1 == s2) << endl;// should display: 0 (false)
			cout << "(s4 == s1) " << (s4 == s1) << endl; // should display: 1 (true)
			cout << "(s4 == s4) " << (s4 == s4) << endl << endl; // should display: 1 (true)
			cout << "(s1 < s2) " << (s1 < s2) << endl; // should display: 0 (false)
			cout << "(s2 < s2) " << (s2 < s1) << endl << endl; // should display: 1 (true)
			cout << "(s1 < s3) " << (s1 < s3) << endl; // should display: 1 (true)
			cout << "(s1 <= s3) " << (s1 <= s3) << endl; // should display: 1 (true)
			cout << "(s1 <= s4) " << (s1 <= s4) << endl; // should display: 1 (true)
			cout << "(s2 <= s2) " << (s2 <= s2) << endl << endl; // should display: 1 (true)
			cout << "(s3 < s1) " << (s3 < s1) << endl; // should display: 0 (false)
			cout << "(s3 <= s1) " << (s3 <= s1) << endl; // should display: 0 (false)
			cout << "(s3 <= s3) " << (s3 <= s3) << endl; // should display: 1 (true)
		}

		if (choice == '4')
		{
			//Operator += test
			cout << "\n\t += Operator with Cascading test\n";
			MyString ms1("One"), ms2("Two"), ms3("Three");
			ms1 += ms2 += ms3;
			ms1.display();// should display: OneTwoThree
			ms2.display(); // should display: TwoThree
			ms3.display(); // should display: Three
		}
		if (choice == '5')
		{
			//Setter test
			cout << "\n\tTest for setStr\n";
			MyString s1("Hello");
			cout << s1; // should display: Hello
			s1.setStr("Welcome to OOP");
			cout << s1; // should display: Welcome to OOP
		}
		if (choice == '6')
		{
			//Conversion operator int test
			cout << "\n\tConversion operator int test\n";
			MyString s1("7504");
			MyString s2("56 abc def");
			int i1 = s1;// using the conversion operator int
			int i2 = s2; // using the conversion operator int
			cout << i1 << endl; // should display: 7504
			cout << i2 << endl; // should display: 0
		}
		if (choice == '7')
		{
			//Conversion operator char* test
			cout << "\n\tConversion operator char* test\n";
			MyString s1("Hello World");
			cout << s1; // should display: Hello World
			char* cp = s1; // using the conversion operator char*
			cout << cp << endl; // should display: Hello World
			delete[] cp; // Deallocating the dynamically allocated memory
			cp = nullptr;
			cout << s1; // should still display: Hello World
		}
		if (choice == '8')
		{
			//Pre increment test
			cout << "\n\tPre Increment test\n";
			MyString s1("One !#^; 123 two");
			MyString s2;
			s2 = ++s1;
			s1.display(); // should display: ONE !#^; 123 TWO
			s2.display(); // should display: ONE !#^; 123 TWO
		}
		if (choice == '9')
		{
			
			//Extrection Operator test
			cout << "\n\tExtrection Operator (>>) test\n";
			MyString s1("Hello");
			cout << s1; // should display: Hello
			cout << "Enter a MyString: ";
			cin >> s1; // Suppose the user enters: Pakistan Zindabad!!
			cout << s1; // should display: Pakistan Zindabad!!
		}
		cout << endl << endl;
		cout << "Press any key to continue....\n";
		system("pause>0");
		cout << endl << endl << endl;
	} while (choice != '0');
	return 0;
}