#pragma once
#include "Account.h"
class Checking :
    public Account
{
    double fee;
public:
    Checking();
    double transictionCharges();
    void withdrawal();
    void deposit();
    void display()const;
};

