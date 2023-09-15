//Abdul Aziz
//BCSF19A026 

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class MyString
{
private:
	char* str;
	int length;
public:
	//Function prototypes
	MyString();
	MyString(const char*);
	~MyString();
	void display()const;
	const int getLength()const;
	MyString(const MyString&);
	const MyString& operator = (const MyString&);
	friend ostream& operator<<(ostream&, const MyString&);
	MyString operator + (const MyString&)const;
	bool operator == (const MyString&)const;
	bool operator < (const MyString&)const;
	bool operator <= (const MyString&)const;
	const MyString& operator += (const MyString&);
	void setStr(const char*);
	operator int();
	operator char* ();
	MyString& operator++();
	friend istream& operator >> (istream&, MyString&);
};

