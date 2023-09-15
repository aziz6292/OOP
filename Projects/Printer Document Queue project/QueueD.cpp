/***************************************************************
****************************************************************
                    Group Memebers
                    **************
                BCSF20A046 Fatima Ansari
                BCSF20A025 Maryam Ali
                BCSF20A016 Zarnab
****************************************************************
****************************************************************/
#include "QueueD.h"
QueueD::QueueD(const QueueD &obj) : QueueD()
{
    Node *cur = obj.front;
    while (cur)
    {
        DocPDF *pdf = dynamic_cast<DocPDF *>(cur->doc);
        DocWord *word = dynamic_cast<DocWord *>(cur->doc);
        if (pdf)
            pushPDF(*pdf); // dynCopy() is done here through Node parametrize constructor
        else
            pushWord(*word); // dynCopy() is done here through Node parametrize constructor
        cur = cur->next;
    }
}
const QueueD &QueueD::operator=(const QueueD &obj)
{
    if (this == &obj)
        return *this;
    this->~QueueD();
    Node *cur = obj.front;
    while (cur)
    {
        DocPDF *pdf = dynamic_cast<DocPDF *>(cur->doc);
        DocWord *word = dynamic_cast<DocWord *>(cur->doc);
        if (pdf)
            pushPDF(*pdf); // dynCopy() is done here through Node parametrize constructor
        else
            pushWord(*word); // dynCopy() is done here through Node parametrize constructor
        cur = cur->next;
    }
    return *this;
}

void QueueD::pushPDF(DocPDF d)
{
    if (front == back && front == NULL)
    {
        front = new Node(d); // dynCopy() is done here through Node parametrize constructor
        back = front;
    }
    else
    {
        back->next = new Node(d); // dynCopy() is done here through Node parametrize constructor
        back = back->next;
    }
}
void QueueD::pushWord(DocWord d)
{
    if (front == back && front == NULL)
    {
        back = new Node(d);
        front = back;
    }
    else
    {
        back->next = new Node(d);
        back = back->next;
    }
}
bool QueueD::fetch(const Document *&docPtr)
{
    if (front->doc != NULL)
    {
        docPtr = front->doc;
        return true;
    }
    else
        docPtr = NULL;
    return false;
}
bool QueueD::EatFront()
{
    if (front != NULL)
    {
        Node *cur = front;
        front = front->next;
        delete cur;
        cur = NULL;
        return true;
    }
    return false;
}
void QueueD::printAll() const
{
    Node *cur = front;
    while (cur)
    {
        cur->doc->show();
        cout << " ";
        cur = cur->next;
    }
}
QueueD::~QueueD()
{
    Node *cur = front;
    while (front)
    {
        front = front->next;
        if (cur)
        {
            delete cur;
            cur = NULL;
        }
        cur = front;
    }
}