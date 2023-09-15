#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
class Time
{
private:
    int D;
public:
    Time(int = 0);
    void set(int);
    int get();
    ~Time();
};
#endif

