/*
	Abdul Aziz
	BCSF19A026
	CS Afternoon Add/Drop
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Media
{
protected:
	string title;
public:
	Media(string str);
	virtual void display()const = 0;
};

