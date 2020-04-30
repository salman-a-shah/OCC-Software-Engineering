#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
public:

	Date(int = 1, int = 1, int = 1900);
	Date(string newDate);
	void setDate(int, int, int);
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void nextDay();
	void prevDay();
	void print() const;

	int monthDays();
	int monthDays(int);

	string dateToString() const;
	void stringToDate(string& newDate);

	//Overloaded operators
	Date& operator=(const Date &other);

	Date& operator+=(int numOfDays);
	Date& operator-=(int numOfDays);
	const Date operator+(int numOfDays) const;
	const Date operator-(int numOfDays) const;

	void operator++();
	void operator--();
	Date operator++(int);
	Date operator--(int);

	bool operator==(const Date &other) const;
	bool operator!=(const Date &other) const;
	bool operator>(const Date &other) const;
	bool operator<(const Date &other) const;
	bool operator>=(const Date &other) const;
	bool operator<=(const Date &other) const;

private:
	int year, month, day;
	bool leapYear();
	

};

#endif 
