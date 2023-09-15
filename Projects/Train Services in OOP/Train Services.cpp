#include <iostream>
#include <string >
#include <fstream>


using namespace std;
const int MAX = 100;
int i = 0, j = 0;
const int N = 30;



class Train
{
private:
	char name[N];
	int seatNo;
	int payment;
	char time[N];
	char departure[N];
	char arraivel[N];
public:
	Train();
	Train(char*, char*, char*, char*, int, int);
	void setName(char*);
	void setSeatNo(int);
	void setPayment(int);
	const char* getName()const;
	const char* getTime()const;
	const char* getArraivel()const;
	const char* getDeparture()const;
	const int getSeatNo()const;
	const int getPayment()const;
	void display()const;

};

Train::Train()
{
	strcpy(name, " ");
	seatNo = 0;
	payment = 0;
	strcpy(time, " ");
	strcpy(departure, " ");
	strcpy(arraivel, " ");

}
Train::Train(char* n, char* t, char* d, char* a, int p, int s)
{
	strcpy(name, n);
	seatNo = s;
	payment = p;
	strcpy(time, t);
	strcpy(departure, d);
	strcpy(arraivel, a);

}
void Train::setName(char* a)
{
	strcpy(name, a);
}
void Train::setSeatNo(int  a)
{
	seatNo = a;
}
void Train::setPayment(int a)
{
	payment = a;
}
const char* Train::getName()const
{
	return name;
}
const char* Train::getTime()const
{
	return time;
}
const char* Train::getArraivel()const
{
	return arraivel;
}
const char* Train::getDeparture()const
{
	return departure;
}
const int Train::getSeatNo()const
{
	return seatNo;
}
const int Train::getPayment()const
{
	return payment;
}

void Train::display()const
{
	cout << "Train Details!" << endl;
	cout << "Train Name: " << name << endl;
	cout << "Departure: " << departure << endl;
	cout << "Arraivel: " << arraivel << endl;
	cout << "Timing: " << time << endl;
	cout << "Seat No: " << seatNo << endl;
	cout << "Fare: " << payment << endl << endl;
}





class Passenger
{
private:
	char name[N];
	char id[N];
	char phoneNo[N];
	int noOfSeat;
public:
	Passenger();
	void setName(char*);
	void setId(char*);
	void setPhoneNo(char*);
	void setNoOfSeats(int);
	const char* getName()const;
	const char* getId()const;
	const char* getPhoneNo()const;
	const int getNoOfSeats()const;
	void display()const;
	

};

Passenger::Passenger()
{
	strcpy(name, " ");
	strcpy(id, " ");
	strcpy(phoneNo, " ");
	noOfSeat = 0;
}
void Passenger::setName(char* a)
{
	strcpy(name, a);
}
void Passenger::setId(char* a)
{
	strcpy(id, a);
}
void Passenger::setPhoneNo(char* a)
{
	strcpy(phoneNo, a);
}
void Passenger::setNoOfSeats(int a)
{
	noOfSeat = a;
}
const char* Passenger::getName()const
{
	return name;
}
const char* Passenger::getPhoneNo()const
{
	return phoneNo;
}
const char* Passenger::getId()const
{
	return id;
}
const int Passenger::getNoOfSeats()const
{
	return noOfSeat;
}
void Passenger::display() const
{
	cout << "Passenger's Name: " << name << endl;
	cout << "Passenger's CNIC No: " << id << endl;
	cout << "Passenger's Phone No: " << phoneNo << endl;
	cout << "No of Seats Reserved: " << noOfSeat << endl << endl;
}









char manu();
bool trainDetail(char*, char*, char*, char*, int&);
void reservation(Passenger* p, Train* t);
void show(Passenger* p, Train* t);
void cancelation(Passenger* p, Train* t);
void schedule(Train* t);



int main()
{

	cin.sync_with_stdio(0);
	cin.tie(0);


	cout << "\t\t********************\n";
	cout << "\t\t* AsSalamo Alaikum *\n";
	cout << "\t\t********************\n";
	cout << endl;
	cout << "~.~*WELCOME TO THE TRAIN BOOCKING *~.~\n";
	cout << "     ~.~*SERVICES OF PAKISTAN~.~*\n\n";
	//Declering 2D Pointers/Arrays Dynamically
	Passenger* passenger = nullptr;
	passenger = new Passenger[MAX];
	Train* train = nullptr;
	train = new Train[MAX];
	char choice;

	do
	{
		choice = manu();
		cout << endl << endl;
		if (choice == '1')
		{
			reservation(passenger, train);

		}
		else if (choice == '2')
		{
			show(passenger, train);
		}
		else if (choice == '3')
		{
			cancelation(passenger, train);
		}
		else if (choice == '4')
		{
			schedule(train);
		}
		else
		{
			cout << "Thank You For Using the App\n";
		}
		system("cls");

	} while (choice != '5');

	delete[] passenger;
	passenger = nullptr;
	delete[] train;
	train = nullptr;
	return 0;
}

char manu()
{
	char choice;
	cout << "Chose from the following!\n\n";
	cout << "1. Reservation\n";
	cout << "2. Checking Your Reservation\n";
	cout << "3. Cancellation\n";
	cout << "4. Schedule\n";
	cout << "5. Exit\n";
	cout << "\nYour Selection: ";
	cin >> choice;
	while (choice < '1' || choice >'5')
	{
		cout << "ERROR!! Invalid input\n";
		cout << "Re-enter in range of 1-5: ";
		cin >> choice;
	}
	return choice;
}

bool trainDetail(char* name, char* time, char* departure, char* arrival, int& fare)
{

	int i, j;
	cout << "Chose Departure Point\n\n";
	cout << "1. Peshawer\n";
	cout << "2. Lahore\n";
	cout << "3. Karachi\n";
	cout << "4. Rawalpendi\n";
	cout << "5. Quetta\n";
	cout << "Your Selection: ";
	cin >> i;
	cout << "Chose Arrival Point\n\n";
	cout << "1. Peshawer\n";
	cout << "2. Lahore\n";
	cout << "3. Karachi\n";
	cout << "4. Rawalpendi\n";
	cout << "5. Quetta\n";
	cout << "Your Selection: ";
	cin >> j;
	cout << endl;
	if (i == 1 && j == 2)
	{
		cout << "Fare = PKR# 700/-\n";
		cout << "Khushal khan Express\n";
		cout << "Timing  8:00am to 5:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Khushal Khan Express");
			strcpy(time, "8:00am to 5:00pm");
			strcpy(departure, "Peshawer");
			strcpy(arrival, "Lahore");
			fare = 700;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 2 && j == 1)
	{
		cout << "Fare = PKR# 700/-\n";
		cout << "Khushal khan Express\n";
		cout << "Timing  8:00am to 5:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Khushal Khan Express");
			strcpy(time, "8:00am to 5:00pm");
			strcpy(departure, "Lahore");
			strcpy(arrival, "Peshawar");
			fare = 700;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}





	else if (i == 1 && j == 3)
	{
		cout << "Fare = PKR# 3000/-\n";
		cout << "Tezgam Express\n";
		cout << "Timing  8:00am to 10:00am\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Tezgam Express");
			strcpy(time, "8:00am to Next day 10:00am");
			strcpy(departure, "Peshawer");
			strcpy(arrival, "Karachi");
			fare = 3000;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 3 && j == 1)
	{
		cout << "Fare = PKR# 3000/-\n";
		cout << "Tezgam Express\n";
		cout << "Timing  8:00am to 10:00am\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Tezgam Express");
			strcpy(time, "8:00am to Next day 10:00am");
			strcpy(departure, "Karachi");
			strcpy(arrival, "Peshawar");
			fare = 3000;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 1 && j == 4)
	{
		cout << "Fare = PKR# 500/-\n";
		cout << "Rawalpendi Express\n";
		cout << "Timing  8:00am to 12:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Rawalpendi Express");
			strcpy(time, "8:00am to Next day 12:00pm");
			strcpy(departure, "Peshawer");
			strcpy(arrival, "Rawalpendi");
			fare = 500;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 4 && j == 1)
	{
		cout << "Fare = PKR# 500/-\n";
		cout << "Rawalpendi Express\n";
		cout << "Timing  8:00am to 12:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Rawalpendi Express");
			strcpy(time, "8:00am to Next day 12:00pm");
			strcpy(departure, "Rawalpendi");
			strcpy(arrival, "Peshawar");
			fare = 500;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 1 && j == 5)
	{
		cout << "Fare = PKR# 3500/-\n";
		cout << "Khybar Express\n";
		cout << "Timing  8:00am to 12:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Khyber Express");
			strcpy(time, "8:00am to Next day 12:00pm");
			strcpy(departure, "Peshawer");
			strcpy(arrival, "Quetta");
			fare = 3500;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 5 && j == 1)
	{
		cout << "Fare = PKR# 3500/-\n";
		cout << "Khyber Express\n";
		cout << "Timing  8:00am to 12:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Khyber Express");
			strcpy(time, "8:00am to Next day 12:00pm");
			strcpy(departure, "Quetta");
			strcpy(arrival, "Peshawar");
			fare = 3500;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 2 && j == 3)
	{
		cout << "Fare = PKR# 2500/-\n";
		cout << "Khyber Express\n";
		cout << "Timing  8:00am to 6:00am\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Khyber Express");
			strcpy(time, "8:00am to Next day 6:00am");
			strcpy(departure, "Lahore");
			strcpy(arrival, "Karachi");
			fare = 2500;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 3 && j == 2)
	{
		cout << "Fare = PKR# 2500/-\n";
		cout << "Khyber Express\n";
		cout << "Timing  8:00am to 6:00am\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Khyber Express");
			strcpy(time, "8:00am to Next day 6:00am");
			strcpy(departure, "Karachi");
			strcpy(arrival, "Lahore");
			fare = 2500;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 2 && j == 4)
	{
		cout << "Fare = PKR# 500/-\n";
		cout << "Shalamar Express\n";
		cout << "Timing  8:00am to 1:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Shalamar Express");
			strcpy(time, "8:00am to 1:00pm");
			strcpy(departure, "Lahore");
			strcpy(arrival, "Rawalpendi");
			fare = 500;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 4 && j == 2)
	{
		cout << "Fare = PKR# 500/-\n";
		cout << "Shalamar Express\n";
		cout << "Timing  8:00am to 1:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Shalamar Express");
			strcpy(time, "8:00am to  1:00pm");
			strcpy(departure, "Rawalpendi");
			strcpy(arrival, "Lahore");
			fare = 500;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 2 && j == 5)
	{
		cout << "Fare = PKR# 3000/-\n";
		cout << "Shalamar Express\n";
		cout << "Timing  8:00am to Next Day 1:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Shalamar Express");
			strcpy(time, "8:00am to Next day 1:00pm");
			strcpy(departure, "Lahore");
			strcpy(arrival, "Quetta");
			fare = 3000;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 5 && j == 2)
	{
		cout << "Fare = PKR# 3000/-\n";
		cout << "Tezgam Express\n";
		cout << "Timing  8:00am to Next Day 1:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Tezgam Express");
			strcpy(time, "8:00am to Next day 1:00pm");
			strcpy(departure, "Quetta");
			strcpy(arrival, "Lahore");
			fare = 3000;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 3 && j == 4)
	{
		cout << "Fare = PKR# 3000/-\n";
		cout << "Tezgam Express\n";
		cout << "Timing  8:00am to Next Day 1:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Tezgam Express");
			strcpy(time, "8:00am to Next day 1:00pm");
			strcpy(departure, "Karachi");
			strcpy(arrival, "Rawalpendi");
			fare = 3000;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 4 && j == 3)
	{
		cout << "Fare = PKR# 3000/-\n";
		cout << "Tezgam Express\n";
		cout << "Timing  8:00am to Next Day 1:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Tezgam Express");
			strcpy(time, "8:00am to Next day 1:00pm");
			strcpy(departure, "Rawalpendi");
			strcpy(arrival, "Karachi");
			fare = 3000;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 3 && j == 5)
	{
		cout << "Fare = PKR# 1800/-\n";
		cout << "Khybar Express\n";
		cout << "Timing  8:00am to 11:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Khyber Express");
			strcpy(time, "8:00am to 11:00pm");
			strcpy(departure, "Karachi");
			strcpy(arrival, "Quetta");
			fare = 1800;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 5 && j == 3)
	{
		cout << "Fare = PKR# 1800/-\n";
		cout << "Khyber Express\n";
		cout << "Timing  8:00am to 11:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Khyber Express");
			strcpy(time, "8:00am to 11:00pm");
			strcpy(departure, "Quetta");
			strcpy(arrival, "Karachi");
			fare = 1800;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 4 && j == 5)
	{
		cout << "Fare = PKR# 2800/-\n";
		cout << "Shalamar Express\n";
		cout << "Timing  8:00am to 8:00pm\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Shalamar Express");
			strcpy(time, "8:00am to 8:00am");
			strcpy(departure, "Rawalpendi");
			strcpy(arrival, "Quetta");
			fare = 2800;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else if (i == 5 && j == 4)
	{
		cout << "Fare = PKR# 2800/-\n";
		cout << "Shalamar Express\n";
		cout << "Timing  8:00am to 8:00am\n";
		cout << "Do you want to confirm Your Reservation\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cout << "Your selection: ";
		char k;
		cin >> k;
		while (k < '1' || k >'2')
		{
			cout << "ERROR! Invalid input\n";
			cout << "Chose 1 or 2: ";
			cin >> k;
		}
		if (k == '1')
		{
			strcpy(name, "Shalamar Express");
			strcpy(time, "8:00am to  8:00am");
			strcpy(departure, "Quetta");
			strcpy(arrival, "Rawalpendi");
			fare = 2800;
		}
		else
		{
			cout << "Allah Hafiz\n";
		}
	}
	else
	{
		cout << "Departure and Arrival Could'nt be Same\n";
		return false;
	}
	return true;
}





















void reservation(Passenger* p, Train* t)
{
	ofstream fout;
	fout.open("list.txt", ios::app);
	if (!fout)
	{
		cout << "File not Created successfully!\n";
	}
	else
	{
		cin.ignore();
		cout << "Enter Passenger's Name: ";
		char name[N];
		cin.getline(name, N);
		p[i].setName(name);

		cout << "Enter Passenger's CNIC: ";
		cin.getline(name, N);
		p[i].setId(name);

		cout << "Enter Passenger's Phone No: ";
		cin.getline(name, N);
		p[i].setPhoneNo(name);

		char time[N];
		char departure[N];
		char arraivel[N];
		int fare;
		bool isValid;
		isValid = trainDetail(name, time, departure, arraivel, fare);
		int noOfSeats = 0;
		if (isValid)
		{
			cout << "How many Seats Do you want to reserve: ";
			cin >> noOfSeats;
			p[i].setNoOfSeats(noOfSeats);
			j = j + noOfSeats;
			Train temp(name, time, departure, arraivel, fare, j);
			t[i] = temp;
			fout << "Passenger's Name: " << p[i].getName() << endl;
			fout << "Passenger's CNIC: " << p[i].getId() << endl;
			fout << "Passenger's Phone No: " << p[i].getPhoneNo() << endl;

			fout << "\tTrain Details!! ";
			fout << "Train Name" << t[i].getName() << endl;
			fout << "Departure: " << t[i].getDeparture() << endl;
			fout << "Arraival: " << t[i].getArraivel() << endl;
			fout << "Timing: " << t[i].getTime() << endl;
			fout << "Seat No: ";
			for (int n = 1; n <= j; n++)
			{
				fout << n << ", ";
			}
			fout << "\b\b";
			fout << endl << endl;
			i++;
			fout.close();
			cout << "\nSeats Sucessfully Reserved\n";
		}
		else
		{
			cout << "Seats Not Reserved Successfully\n";
		}
		system("pause>0");
	}

}


void show(Passenger* p, Train* t)
{
	char choice;
	char temp[N];
	cout << "Select search method!\n";
	cout << "1. By Passenger Name\n";
	cout << "2. By Passenger CNIC\n";
	cout << "3. By Phone No\n";
	cout << "Your selection: ";
	cin >> choice;
	while (choice < '1' || choice >'3')
	{
		cout << "ERROR! Invalid input\n";
		cout << "Please press 1,2 or 3: ";
		cin >> choice;
	}
	cin.ignore();
	bool isfound = false;
	if (choice == '1')
	{
		cout << "Enter Your Name: ";
		cin.getline(temp, N);
		for (int n = 0; n < i; n++)
		{
			if (strcmp(temp, p[n].getName()) == 0)
			{
				p[n].display();
				t[n].display();
				isfound = true;

			}
		}
		if (!isfound)
		{
			cout << "Passenger with Name " << temp << " not Found in the reservation list\n";
		}
	}
	else if (choice == '2')
	{
		cout << "Enter Your CNIC: ";
		cin.getline(temp, N);
		for (int n = 0; n < i; n++)
		{
			if (strcmp(temp, p[n].getId()) == 0)
			{
				p[n].display();
				t[n].display();
				isfound = true;

			}
		}
		if (!isfound)
		{
			cout << "Passenger with CNIC No: " << temp << " not Found in the reservation list\n";
		}
	}
	else
	{
		cout << "Enter Your Phone No: ";
		cin.getline(temp, N);
		for (int n = 0; n < i; n++)
		{
			if (strcmp(temp, p[n].getPhoneNo()) == 0)
			{
				p[n].display();
				t[n].display();
				isfound = true;

			}
		}
		if (!isfound)
		{
			cout << "Passenger with Phone No: " << temp << " not Found in the reservation list\n";
		}

	}
	system("pause>0");

}
void cancelation(Passenger* p, Train* t)
{

	char choice;
	char temp[N];
	cout << "Select search method!\n";
	cout << "1. By Passenger Name\n";
	cout << "2. By Passenger CNIC\n";
	cout << "3. By Phone No\n";
	cout << "Your selection: ";
	cin >> choice;
	while (choice < '1' || choice >'3')
	{
		cout << "ERROR! Invalid input\n";
		cout << "Please press 1,2 or 3: ";
		cin >> choice;
	}
	cin.ignore();
	bool isfound = false;
	if (choice == '1')
	{
		cout << "Enter Your Name: ";
		cin.getline(temp, N);
		for (int n = 0; n < i; n++)
		{
			if (strcmp(temp, p[n].getName()) == 0)
			{
				while (n < i)
				{
					p[n] = p[n + 1];
					t[n] = t[n + 1];
					n++;
				}
				isfound = true;
				i--;
			}
		}
		if (!isfound)
		{
			cout << "Passenger with Name " << temp << " not Found in the reservation list\n";
		}
	}
	else if (choice == '2')
	{
		cout << "Enter Your CNIC: ";
		cin.getline(temp, N);
		for (int n = 0; n < i; n++)
		{
			if (strcmp(temp, p[n].getId()) == 0)
			{
				while (n < i)
				{
					p[n] = p[n + 1];
					t[n] = t[n + 1];
					n++;
				}
				isfound = true;
				i--;

			}
		}
		if (!isfound)
		{
			cout << "Passenger with CNIC No: " << temp << " not Found in the reservation list\n";
		}
	}
	else
	{
		cout << "Enter Your Phone No: ";
		cin.getline(temp, N);
		for (int n = 0; n < i; n++)
		{
			if (strcmp(temp, p[n].getPhoneNo()) == 0)
			{
				while (n < i)
				{
					p[n] = p[n + 1];
					t[n] = t[n + 1];
					n++;
				}
				isfound = true;
				i--;

			}
		}
		if (!isfound)
		{
			cout << "Passenger with Phone No: " << temp << " not Found in the reservation list\n";
		}
	}
	if (isfound)
	{
		ofstream fout;
		fout.open("list.txt");
		{
			if (!fout)
			{
				cout << "File not open successfully\n";
			}
			else
			{
				j = 0;
				for (int n = 0; n < i; n++)
				{

					fout << "Passenger's Name: " << p[n].getName() << endl;
					fout << "Passenger's CNIC: " << p[n].getId() << endl;
					fout << "Passenger's Phone No: " << p[n].getPhoneNo() << endl;
					fout << "No of Seats reserved: " << p[n].getNoOfSeats() << endl;
					fout << "\tTrain Details!! ";
					fout << "Train Name" << t[n].getName() << endl;
					fout << "Departure: " << t[n].getDeparture() << endl;
					fout << "Arraival: " << t[n].getArraivel() << endl;
					fout << "Timing: " << t[n].getTime() << endl;
					fout << "Seat No: ";
					j = j + p[n].getNoOfSeats();
					for (int k = 1; k <= j; k++)
					{
						fout << k << ", ";
					}
					fout << "\b\b";
					fout << endl << endl;
				}
				fout.close();
				cout << "You Successfully Cancelled Your Reservation\n";
			}
		}

	}
	system("pause>0");
}



void schedule(Train* t)
{
	for (int n = 0; n < i; n++)
	{
		cout << "Train Name: " << t[n].getName() << endl;
		cout << "From " << t[n].getDeparture() << " to " << t[n].getArraivel() << endl;
		cout << "Timing: " << t[n].getTime() << endl;
		cout << "Fare Economy Class " << t[n].getPayment() << ", Business Class " << float(t[n].getPayment()) * 1.7 << " PKR" << endl;
		cout << "Filled Seats: " << j;
		cout << endl << endl;
	}
	system("pause>0");

}