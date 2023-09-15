/*
    Abdul Aziz
    BCSF19A026
    CS Afternoon Add/Drop
*/
#pragma once
#include "Media.h"
class Magazine :
    public Media
{
private:
    string month;
    int year;
public:
    Magazine( string, string , int );
    int getYear();
    void display()const;
};

