/*
    Abdul Aziz
    BCSF19A026
    CS Afternoon Add/Drop
*/
#pragma once
#include "Media.h"
class Shelf
{
private:
    Media** items; // Pointer to a dynamically allocated array of Media*
    int maxSize;   // Max no. of items that can be stored in the Shelf
    int currSize;  // No. of items that are currently stored in the Shelf
public:
    Shelf(int);
    void insert(Media*);
    void displayContents()const;
    ~Shelf();
};

