#pragma once
#include "DateType.h"
class extDateType :
    public DateType
{
    string monthStr;
public:
    extDateType(int = 1, int =1, int =0);
    void setMonth(int);
    void display()const;
    void month_yearStr()const;
};

