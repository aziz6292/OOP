//Fatima Ansari BCSF20A046
//Maryam Ali BCSF20A025
//Zarnab BCSF20A016
#include "Book.h"
Book::Book(int b)
{
    set(b);
}
void Book::set(int b)
{
    if (b >= 0 && b <= 100000)
    {
       score = b;
    }
    else
    {
        cout << "Book ID is not valid\n";
        exit(0);
    }
}
int Book ::get()
{
    return score;
}
Book::~Book()
{
    cout << "\n~Book()\n";
}
