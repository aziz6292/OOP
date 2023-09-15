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
#ifndef DOCPDF_H
#define DOCPDF_H
class DocPDF : public Document
{
public:
    DocPDF() : Document() {}
    DocPDF(string id) : Document(id) {}
    void show() const override
    {
        cout << ID;
    }
    Document *dynCopy() override
    {
        Document *d = new DocPDF(ID);
        return d;
    }
};
#endif