/***************************************************************
****************************************************************
                    Group Memebers
                    **************
                BCSF20A046 Fatima Ansari
                BCSF20A025 Maryam Ali
                BCSF20A016 Zarnab
****************************************************************
****************************************************************/
#include "Document.h"
#ifndef DOCWORD_H
#define DOCWORD_H
class DocWord : public Document
{
public:
    DocWord() : Document() {}
    DocWord(string id) : Document(id) {}
    void show() const override
    {
        cout << ID;
    }
    Document *dynCopy() override
    {
        Document *d = new DocWord(ID);
        return d;
    }
};
#endif