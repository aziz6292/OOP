/*
	Abdul Aziz
	BCSF19A026
	CS Afternoon Add/Drop
*/
#pragma once
#include "Media.h"
class CD :
	public Media
{
private:
	int capacity;
public:
	CD(string, int);
	void display()const;
};

