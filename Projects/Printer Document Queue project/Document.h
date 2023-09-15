/***************************************************************
****************************************************************
                    Group Memebers
                    **************
                BCSF20A046 Fatima Ansari
                BCSF20A025 Maryam Ali
                BCSF20A016 Zarnab
****************************************************************
****************************************************************/
#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
using namespace std;

class Document
{
protected:
    string ID;

public:
    Document(string = "");
    virtual void show() const = 0;
    virtual Document *dynCopy();
};
#endif