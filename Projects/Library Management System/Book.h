//Fatima Ansari BCSF20A046
//Maryam Ali BCSF20A025
//Zarnab BCSF20A016
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;
class Book
{
private:
    int score;

public:
    Book(int = 0);
    void set(int);
    int get();
    ~Book();
};
#endif
