#pragma once
#include "Account.h"
class Current :
    public Account
{
    double fee;
    int min;
public:
    Current(int);
    double transictionCharges();
    void deposit();
    void withdrawal();
    void setAccount();
    void display()const;
};

