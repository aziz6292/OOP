#ifndef LIB_H
#define LIB_H
#include "Book.cpp"
//Fatima Ansari BCSF20A046
//Maryam Ali BCSF20A025
//Zarnab BCSF20A016
#include "Time.cpp"
class Lib
{
private:
    int *books;
    int days;
    int bSize;
    int bkScannedPerDay;

public:
    Lib(int = 1, int = 1, int = 1);
    Lib(const Lib &);
    const Lib &operator=(const Lib &);
    void setBook(int, int);
    void setTime(int);
    void setBSPD(int); // BSPD = Book Scanned Per Day
    void setbSize(int);
    int getBook(int);
    int getTime();
    int getbSize();
    int getBSPD();
    ~Lib();
};
#endif
