/*
    Abdul Aziz
    BCSF19A026
    CS Afternoon Add/Drop
*/
#pragma once
#include "Media.h"
class Book :
    public Media
{
private:
    string author, ISBN;
public:
    Book(string ,string , string );
    void display()const;
};

