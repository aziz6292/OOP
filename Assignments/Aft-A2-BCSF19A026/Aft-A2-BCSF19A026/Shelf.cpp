/*
    Abdul Aziz
    BCSF19A026
    CS Afternoon Add/Drop
*/
#include "Shelf.h"
Shelf::Shelf(int n): maxSize (n),currSize(0)
{
    items = new Media * [maxSize];
    for (int i =0; i<maxSize; i++)
        items[i] = NULL;
}
void Shelf::insert(Media* m)
{
    if (currSize < maxSize)
    {
        items[currSize] = m;
        currSize++;
    }
}
void Shelf::displayContents()const
{
    for (int i = 0; i < currSize; i++)
    {
        cout << "\t**Object #" << i + 1 << " Record**\n";
        items[i]->display();
        cout << endl << endl;
    }
}
Shelf::~Shelf()
{
    for (int i = 0; i < maxSize; i++)
    {
        if (items[i] != NULL)
        {
            delete items[i];
            items[i] = NULL;
        }
    }
    if (items != NULL)
    {
        delete[] items;
        items = NULL;
    }
}
