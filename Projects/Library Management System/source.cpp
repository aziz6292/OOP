// Fatima Ansari BCSF20A046
// Maryam Ali BCSF20A025
// Zarnab BCSF20A016
#include "Lib.cpp"
#include <fstream>
void validate (int &, int , int);
void getAndStroeToFileInputs();
void display();
void generateOutputFile();
int main()
{
    getAndStoreToFileInputs();
    display();
    generateOutputFile();
    return 0;
}

void validate(int &val, int i, int j)
{
    while (val < i || val > j)
    {
        cout << "Invalid Re-enter: ";
        cin >> val;
    }
}
void getAndStoreToFileInputs()
{
    // Getting Input();
    ofstream fout;
    fout.open("input.txt");
    if (fout)
    {
        int B, L, D;
        cout << "Enter no of Books: ";
        cin >> B;
        validate(B, 1, 100000);
        fout << B << " ";
        cout << "Enter no of library: ";
        cin >> L;
        validate(L, 1, 100000);
        fout << L << " ";
        cout << "Enter days for scanning: ";
        cin >> D;
        validate(D, 1, 100000);
        fout << D << "\n\n";
        cout << "Enter Score for All Books one by one.....\n";
        cout << "Score for ID #\n";
        int score;
        for (int i{}; i < B; i++)
        {
            cout << "#" << i << ": ";
            cin >> score;
            validate(score, 1, INT32_MAX);
            fout << score << " ";
        }
        fout << endl
             << endl;
        cout << "\n\nGetting input for each Library......\n";
        int noBook, days, booksPerDayScanned;
        for (int i{}; i < L; i++)
        {
            cout << "Library #" << i << " Data\n";
            cout << "Books: ";
            cin >> noBook;
            validate(noBook, 1, B);
            fout << noBook << " ";
            cout << "Days for sign up process: ";
            cin >> days;
            validate(days, 1, D);
            fout << days << " ";
            cout << "# Books can ship per Day: ";
            cin >> booksPerDayScanned;
            validate(booksPerDayScanned, 1, B);
            fout << booksPerDayScanned << endl
                 << endl
                 << endl;
            cout << "\nNow getting books ID's...\n";
            int id;
            for (int j{}; j < noBook; j++)
            {
                cout << "ID #: ";
                cin >> id;
                validate(id, 0, B - 1);
                fout << id << " ";
            }
            cout << endl;
            fout << endl
                 << endl;
        }
        cout << "Data are stored into file successfully\n";
        cout << "File Name (input.txt)\n";
        cout << "Press any key to continue.....";
        system("pause>0");
        system("cls");
        fout.close();
    }
    else
    {
        cout << "File not found\n";
        exit(0);
    }
}
void display()
{
    ifstream fin;
    fin.open("input.txt");
    if (fin)
    {
        cout << "\t\t*****Input File*****\n";
        char ch;
        while (fin.get(ch))
            cout << ch;
        cout << "Press any key to continue.....";
        system("pause>0");
        fin.close();
        system("cls");
    }
    else
    {
        cout << "File Not found\n";
        exit(0);
    }
}
void generateOutputFile()
{
    ifstream fin;
    fin.open("input.txt");
    if (fin)
    {
        int L, B, D;
        fin >> B >> L >> D;
        Lib *libraries = new Lib[L]{};
        Book *books = new Book[B]{};
        Time times{D};
        int tempBookScore;

        for (int i{}; i < B; i++)
        {
            fin >> tempBookScore;
            books[i].set(tempBookScore);
        }
        int tempBookForEachLib, tempDays, tempBkTimePerDay;
        for (int i{}; i < L; i++)
        {
            fin >> tempBookForEachLib >> tempDays >> tempBkTimePerDay;
            libraries[i].setbSize(B);
            libraries[i].setTime(tempDays);
            libraries[i].setBSPD(tempBkTimePerDay);
            // to store Each books ID
            int tempID;
            for (int j{}; j < tempBookForEachLib; j++)
            {
                fin >> tempID;
                libraries[i].setBook(tempID, tempID);
            }
            cout <<endl;
        }
        fin.close();
        // Generating output();
        ofstream fout;
        fout.open("output.txt");
        if (fout)
        {
            int TotalScore{};
            int signup{};
            int day{};
            fout << L << "\n\n";
            while (signup < times.get())
            {
                cout << "Enter the library to scanned books from i.e 0-" << L - 1 << ": ";
                int libID;
                cin >> libID;
                validate(libID, 0, L - 1);
                if (signup - day < libraries[libID].getTime())
                    signup += libraries[libID].getTime();
                if (signup > times.get())
                    break;
                fout << libID << " ";
                cout << "Enter no of Books You Wanted to scanned\n";
                cout << "Note: (You can only scanned " << libraries[libID].getBSPD() << " per days)\n";
                cout << "# of books: ";
                cin >> tempBookForEachLib;
                validate(tempBookForEachLib, 0, B - 1);
                fout << tempBookForEachLib << "\n\n";
                int bkID;
                for (day = 0; day < tempBookForEachLib; day++)
                {
                    if ((day == libraries[libID].getBSPD()) || (day % libraries[libID].getBSPD() == 0 && day > libraries[libID].getBSPD()))
                        signup++;
                    if (signup > times.get())
                        break;
                line:
                    cout << "Book ID: ";
                    cin >> bkID;
                    validate(bkID, 0, B - 1);
                    if (libraries[libID].getBook(bkID) != -1)
                    {
                        fout << bkID << " ";
                        //  Association in Classes
                        //  searching in library
                        //  and then getting its score
                        TotalScore += books[bkID].get();
                        // once scanned so to get no score we make it 0
                        books[bkID].set(0);
                    }
                    else
                    {
                        cout <<"Invalid\n";
                        goto line;
                    }
                }
                fout << endl
                     << endl;
            }
            cout << "\n\n\tTotal Score: " << TotalScore << endl
                 << endl;
            delete[] libraries;
            libraries = NULL;
            delete[] books;
            books = NULL;
            cout << "Data are stored into file successfully\n";
            cout << "File Name (output.txt)\n";
            cout << "Press any key to continue.....";
            system("pause>0");
            system("cls");
            fout.close();
        }
        else
        {
            cout << "File not found\n";
            exit(0);
        }
    }
    else
    {
        cout << "File Not found\n";
        exit(0);
    }
}