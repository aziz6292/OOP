//Abdul Aziz
//BCSF19A026 

#include "MyString.h"
//1
MyString::MyString() :length(0) // to initilize length to 0
{
	str = new char[1]; // allocating memory on heap
	str[0] = '\0'; // assigning empty string to str
}

//2
MyString::MyString(const char* n) : MyString()// this will 1st initilize the the object
{
	// Calling the setter function where they whole functionality is done 
	setStr(n);
}

//3
MyString ::~MyString()
{
	if (str != NULL) // checking if already NULL
	{
		delete[] str;
		str = NULL;
	}
}

//4
void MyString::display()const
{
	cout << str << endl; //Displaying the memory which str point to
}

//5
const int MyString::getLength()const
{
	return length;
}

//6
MyString::MyString(const MyString& st) : MyString()// this will 1st initilize the the object
{
	setStr(st.str); // This will make deep copy
}

//7
const MyString& MyString :: operator = (const MyString& rhs)
{
	if (this != &rhs)// Checking for assinging to itself i.e obj = obj  
	{
		setStr(rhs.str); // Deep copy
	}
	return *this;
}

//8
ostream& operator <<(ostream& out, const MyString& rhs) // cascading way out put of a Mystring obj
{
	if (&rhs != NULL) // checking if not null 
		out << rhs.str << endl; 
	return out;
}

//9
MyString MyString :: operator + (const MyString& rhs)const
{
	MyString temp;
	if (temp != NULL) // if temp having memory in constructor so to clear it 1st
	{
		delete[] temp;
		temp = NULL;
	}
	temp.length = length + rhs.length; 
	temp.str = new char[temp.length + 1];// allocating memory of the required size
	for (int i = 0; i < temp.length; i++) 
	{
		if (i < length) // 1st assigning the 1st object to temp without changing the object itself
			temp.str[i] = str[i];
		else  // if the 1st object char is assigned than the 2nd object is begin to copy char by char
			temp.str[i] = rhs.str[i - length];
	}
	temp.str[temp.length] = '\0'; // at the end null is place to the last index of temp.str
	return temp; // returning the newly created object
}

//10
bool MyString :: operator == (const MyString& rhs)const
{
	if (length != rhs.length) // if size of both string is not same its mean no need to further check the equility
		return false;
	for (int i = 0; i < length; i++) 
		if (str[i] != rhs.str[i]) // if any char is not same no need to further check
			return false;
	return true; //if  the loop is terminated mean the both are same 
}

//11
bool MyString :: operator < (const MyString& rhs)const
{
	int n; 
	if (length > rhs.length) // 1st we look the smallest element object 
		n = rhs.length;
	else
		n = length;
	for (int i = 0; i < n; i++) // the loop will Go tell the end of smallest string
		if (!(str[i] <= rhs.str[i])) // if this condition true mean the string is not less hance false
			return false;
	return true;
}

//12
bool MyString :: operator <= (const MyString& rhs)const
{
	//Same as above <
	int n;
	if (length > rhs.length)
		n = rhs.length;
	else
		n = length;
	for (int i = 0; i < n; i++)
		if (!(str[i] <= rhs.str[i]))
			return false;
	return true;
}

//13
const MyString& MyString :: operator += (const MyString& rhs)
{
	char* temp = new char[length + rhs.length + 1];
	for (int i = 0; i < length + rhs.length; i++)
	{
		if (i < length)
			temp[i] = str[i];
		else
			temp[i] = rhs.str[i - length];
	}
	temp[length + rhs.length] = '\0';
	setStr(temp);
	delete[]temp;
	temp = NULL;
	return *this;
}

//14
void MyString::setStr(const char* st)
{
	if (str != NULL) // if already pointing to memory
	{
		delete[] str;
		str = NULL;
		length = 0;
	}
	if (st != NULL)
	{
		int i = 0;
		for (; st[i] != '\0'; i++); // calculating the length
		length = i;
		str = new char[length + 1]; //allocating the memory on heap
		for (i = 0; i < length; i++)
			str[i] = st[i];
		str[length] = '\0';
	}
	else
	{
		length = 0;
		str = new char[1];
		str[0] = '\0';
	}
}

//15
MyString ::operator int()
{
	int num = 0; 
	for (int i = 0; i < length; i++)
	{
		if (str[i] < '0' || str[i]> '9') // if the whole string having any other char than digits
			return 0;
		num = num * 10 + (((int)str[i]) - 48); // to convert the string into specific digit and store in int 
	}
	return num;
}

//16
MyString ::operator char* ()
{
	char* temp = new char[length + 1];
	for (int i = 0; i <= length; i++) 
		temp[i] = str[i];
	return temp;
}

//17
MyString& MyString :: operator++()
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') // if any small case char in the string will be overwrite to the capital one by substracting the 32 from its ascii
			str[i] -= (97 - 65); // asscii of A = 65 , a = 97
	}
	return *this;
}

//18

istream& operator >> (istream& in, MyString& rhs)
{
	in.ignore(); // to ignore the already present '\n' in keyboard buffer which is we hit after cin>> 
	char st[100 + 1];// 1 for \n as already given to assume the 100 is max char user can enterd
	in.getline(st, 101); // getting the cstring 
	if (rhs.str != NULL) // to deallocate if str already pointing to some memory
	{
		delete[]rhs.str;
		rhs.str = NULL;
	}
	int i = 0;
	for (; st[i] != '\0'; i++); //calculating the length
	rhs.length = i;
	rhs.str = new char[rhs.length + 1];//allocating the memory of the required size
	for ( int i =0; i < rhs.length; i++) // assigning char from the char array st one by one
	{
		rhs.str[i] = st[i];
	}
	rhs.str[rhs.length] = '\0'; // at the end placing the null to the prevent from garbages
	return in; // for cascading 
}
