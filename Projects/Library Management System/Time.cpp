//Fatima Ansari BCSF20A046
//Maryam Ali BCSF20A025
//Zarnab BCSF20A016
#include "Time.h"
Time::Time(int d)
{
    set(d);
}
void Time::set(int d)
{
    if (d >= 0 && d <= 100000)
        D = d;
    else
    {
        cout << "Time in days is not valid\n";
        exit(0);
    }
}
int Time::get()
{
    return D;
}
Time::~Time()
{
    cout << "\n~Time()\n";
}