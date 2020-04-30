#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
}

Date::Date(string newDate)
{
	string temp;	
	int pos = newDate.find("/");
	temp = newDate.substr(0, pos);
	month = stoi(temp);
	newDate.erase(0, pos + 1);

	pos = newDate.find("/");
	temp = newDate.substr(0, pos);
	day = stoi(temp);
	newDate.erase(0, pos + 1);
	
	temp = newDate;
	year = stoi(temp);
}

void Date::setDate(int mo, int d, int y)
{
	setMonth(mo);
	setDay(d);
	setYear(y);
}

void Date::setMonth(int mo)
{
	/*if(mo < 13 && mo >= 1)
	{month = mo;}else month = 1;*/
	if (mo == 0) {
		month = 12;
	} else {
		month = mo <= 12 && mo >= 1 ? mo : 1;
	}

}

void Date::setDay(int d)
{
	if (month == 2 && leapYear())
	{
		if (d <= 29 && d >= 1)
		{
			day = d;
		}
		else if (d == 0) {
			day = 31;
		}
		else
			day = 1;

	}
	else
	{
		if (d <= monthDays() && d >= 1)
		{
			day = d;
		}
		else if (d == 0) {
			day = monthDays(month - 1);
		}
		else
			day = 1;
	}

}

void Date::setYear(int y)
{
	if (y >= 1900)
	{
		year = y;
	}
	else year = 1900;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}

void Date::nextDay()
{
	setDay(day + 1);
	if (day == 1)
	{
		setMonth(month + 1);
		if (month == 1)
			setYear(year + 1);
	}
}

void Date::prevDay()
{
	int temp = getDay();
	setDay(day - 1);
	if (temp - getDay() < 0) {
		setMonth(month - 1);
		if (month == 12) {
			setYear(year - 1);
		}
	}
}

bool Date::leapYear()
{

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else
		return false;
}

int Date::monthDays()
{
	const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (month == 2 && leapYear()) ? 29 : days[(month - 1)];
}

int Date::monthDays(int specificMonth)
{
	const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (specificMonth <= 0) {
		specificMonth = 12;
	}

	return (specificMonth == 2 && leapYear()) ? 29 : days[(specificMonth - 1)];
}

void Date::print() const
{
	cout << month << '/' << day << '/' << year << endl;
}

string Date::dateToString() const
{
	string result = "";
	//if (month <= 9)
		//result += "0" + to_string(month) + "/";
	//else
	result += to_string(month) + "/";
	//if (day <= 9)
		//result += "0" + to_string(day) + "/";
	//else
	result += to_string(day) + "/";
	result += to_string(year);
	return result;
}

void Date::stringToDate(string& newDate) 
{
	string temp;
	int pos = newDate.find("/");
	temp = newDate.substr(0, pos);
	month = stoi(temp);
	newDate.erase(0, pos + 1);

	pos = newDate.find("/");
	temp = newDate.substr(0, pos);
	day = stoi(temp);
	newDate.erase(0, pos + 1);

	temp = newDate;
	year = stoi(temp);
}

// Overloaded Operators.
Date& Date::operator=(const Date &other) {
	//self assignment
	if (this == &other) {
		return *this;
	}

	setDay(other.getDay());
	setMonth(other.getMonth());
	setYear(other.getYear());

	return *this;
}
Date & Date::operator+=(int numOfDays) {

	for (int i = 0; i < numOfDays; i++) {
		nextDay();
	}
	return *this;
}
Date & Date::operator-=(int numOfDays) {

	for (int i = 0; i < numOfDays; i++) {
		prevDay();
	}
	return *this;
}
const Date Date::operator+(int numOfDays) const {

	Date temp = *this;
	temp += numOfDays;
	return temp;
}
const Date Date::operator-(int numOfDays) const {

	Date temp = *this;
	temp += numOfDays;
	return temp;
}
void Date::operator++() {

	nextDay();
}
void Date::operator--() {

	prevDay();
}
Date Date::operator++(int uselessInt) {

	Date temp = *this;
	nextDay();
	return temp;
}
Date Date::operator--(int uselessInt) {

	Date temp = *this;
	prevDay();
	return temp;
}
bool Date::operator==(const Date &other) const {

	if (getDay() == other.getDay() &&
		getMonth() == other.getMonth() &&
		getYear() == other.getYear())
	{
		return true;
	}

	return false;
}
bool Date::operator!=(const Date &other) const {

	return !(*this == other);
}
bool Date::operator>(const Date &other) const {
	if (getYear() > other.getYear()) {
		return true;
	}

	else if (getYear() == other.getYear()) {
		if(getMonth() > other.getMonth()) {
			return true;
		}

		else if (getMonth() == other.getMonth()) {
			if (getDay() > other.getDay()) {
				return true;
			}
		}
	}

	return false;
}
bool Date::operator<(const Date &other) const {
	return (other > *this);
}
bool Date::operator>=(const Date &other) const {
	return ((*this > other) || getDay() == other.getDay());
}
bool Date::operator<=(const Date &other) const {
	return (other >= *this);
}
