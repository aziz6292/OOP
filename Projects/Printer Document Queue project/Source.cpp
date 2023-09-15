/***************************************************************
****************************************************************
                    Group Memebers
                    **************
                BCSF20A046 Fatima Ansari
                BCSF20A025 Maryam Ali
                BCSF20A016 Zarnab
****************************************************************
****************************************************************/

#include "Document.cpp"
#include "DocPDF.h"
#include "DocWord.h"
#include "QueueD.cpp"

int main()
{
    QueueD list;
    DocPDF pdf;
    DocWord word;
    string filename;
    const Document *doc;
    while (true)
    {
        cout << "1.pushWord\n2.pushPDF\n3.fetch\n4.EatFront\n5.printAll\n6.exit\nYour choice: ";
        char choice;
        cin >> choice;
        cin.ignore();
        while (choice < '1' || choice > '6')
        {
            cout << "Invalid choice: " << choice << endl;
            cout << "Re-enter the number 1-6: ";
            cin >> choice;
        }
        if (choice == '1')
        {
            cout << "Enter the word file ID:";
            getline(cin, filename);
            word = DocWord(filename);
            list.pushWord(word);
        }
        else if (choice == '2')
        {
            cout << "Enter the PDF file ID:";
            getline(cin, filename);
            pdf = DocPDF(filename);
            list.pushPDF(pdf);
        }
        else if (choice == '3')
        {
            list.fetch(doc);
            doc->show();
        }
        else if (choice == '4')
        {
            list.EatFront();
        }
        else if (choice == '5')
        {
            list.printAll();
        }
        else
            exit(0);
        cout << endl
             << endl;
    }
    list.printAll();
    return true;
}