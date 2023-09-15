//Fatima Ansari BCSF20A046
//Maryam Ali BCSF20A025
//Zarnab BCSF20A016
#include "Lib.h"
Lib::Lib(int bs, int d, int bspd) : books(NULL)
{
    setbSize(bs);
    setTime(d);
    setBSPD(bspd);
}
Lib::Lib(const Lib &obj)
{
    days = obj.days;
    bSize = obj.bSize;
    bkScannedPerDay = obj.bkScannedPerDay;
    books = new int[bSize]{};
    for (int i{0}; i < bSize; i++)
        books[i] = obj.books[i];
}
const Lib &Lib ::operator=(const Lib &obj)
{
    if (this == &obj)
        return *this;
    if (books)
        this->~Lib();
    days = obj.days;
    bSize = obj.bSize;
    bkScannedPerDay = obj.bkScannedPerDay;
    books = new int[bSize]{};
    for (int i{0}; i < bSize; i++)
        books[i] = obj.books[i];
    return *this;
}
void Lib::setBook(int index, int score)
{
    if (index >= 0 && index <= bSize)
        books[index] = score;
    else
    {
        cout << "\nInvalid Book Index\n";
        exit(0);
    }
}
void Lib::setTime(int d)
{
    if (d >= 1 && d <= 100000)
        days = d;
    else
    {
        cout << "\nInvalid Days to signup\n";
        exit(0);
    }
}
void Lib::setBSPD(int bspd) // BSPD = Book Scanned Per Day
{
    if (bspd >= 1)
        bkScannedPerDay = bspd;
    else
    {
        cout << "\nInvalid Days to signup\n";
        exit(0);
    }
}
void Lib::setbSize(int bs)
{
    if (bs > 0 && bs < 100000)
    {
        bSize = bs;
        if (books)
            delete[] books;
        books = new int[bSize]{};
        for (int i =0; i<bSize; i++)
        books[i] = -1;
    }
    else
    {
        cout << "\nInvalid Book Size\n";
        exit(0);
    }
}
int Lib::getBook(int index)
{
    return books[index];
}
int Lib::getTime()
{
    return days;
}
int Lib::getbSize()
{
    return bSize;
}

int Lib::getBSPD()
{
    return bkScannedPerDay;
}
Lib::~Lib()
{
    cout << "\n~Lib()\n";
    if (books)
    {
        delete[] books;
        books = NULL;
    }
}