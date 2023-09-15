/***************************************************************
****************************************************************
                    Group Memebers
                    **************
                BCSF20A046 Fatima Ansari
                BCSF20A025 Maryam Ali
                BCSF20A016 Zarnab
****************************************************************
****************************************************************/
#include "DocPDF.h"
#include "DocWord.h"
#ifndef QUEUED_H
#define QUEUED_H
class Node
{
public:
    Document *doc;
    Node *next;
    Node() : doc(NULL), next(NULL) {}
    Node(DocPDF pdf) : next(NULL)
    {
        doc = pdf.dynCopy();
    }
    Node(DocWord word) : next(NULL)
    {
        doc = word.dynCopy();
    }
    ~Node()
    {
        if (doc)
        {
            delete doc;
            doc = NULL;
        }
    }
};
class QueueD
{
    Node *front, *back;

public:
    QueueD() : front(NULL), back(NULL) {}
    QueueD(const QueueD &);
    const QueueD &operator=(const QueueD &);
    ~QueueD();
    void pushPDF(DocPDF d);
    bool fetch(const Document *&);
    void pushWord(DocWord);
    bool EatFront();
    void printAll() const;
};
#endif
