#ifndef TELDIRECTORY_H
#define TELDIRECTORY_H
class TelDirectory
{
private:
	char name [30];
	long long int num;
	char address [30];
public:
	//Class Functions Prototypes
	TelDirectory();
	TelDirectory(char*, char*, long long);
	const char* getName()const;
	const char* getAddress()const;
	const int getNum()const;
	void setName(char*);
	void setAddress(char*);
	void setNum(long long);
	const long long searchByName(char*)const;
	const char* searchByNumber(long long)const;
	void printDirectory()const;

};

#endif