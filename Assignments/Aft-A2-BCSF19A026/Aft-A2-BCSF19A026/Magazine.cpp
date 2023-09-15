/*
    Abdul Aziz
    BCSF19A026
    CS Afternoon Add/Drop
*/
#include "Magazine.h"
Magazine::Magazine(string t,string m,int y):Media(t),month(m),year(y)
{}
int Magazine::getYear()
{
    return year;
}
void Magazine::display()const
{
    cout << "Tittle: " << title << endl;
    cout<<"Month: "<<month<<endl;
    cout<<"Publication Year: "<<year<<endl;
}