#include "GeneralInfo.h"


GeneralInfo::GeneralInfo()
{
	name = "";
	address = "";
	city = "";
	state = "";
	zipCode = "";
	country = "";
	email = "";
	phoneNumber = "";
	numOfAdults = "";
	numOfChildren = "";
}
GeneralInfo::GeneralInfo(string newName, string newAddress, string newCity, string newState, string newZip, string newCountry, string newEmail, string newPhoneNumber, string newNumAdults, string newNumChildren)
{
	name = newName;
	address = newAddress;
	city = newCity;
	state = newState;
	zipCode = newZip;
	country = newCountry;
	email = newEmail;
	phoneNumber = newPhoneNumber;
	numOfAdults = newNumAdults;
	numOfChildren = newNumChildren;
}

void GeneralInfo::setName(string newName)
{
	name = newName;
}

string GeneralInfo::getName() const
{
	return name;
}

void GeneralInfo::setAddress(string newAddress)
{
	address = newAddress;
}

string GeneralInfo::getAddress() const
{
	return address;
}

void GeneralInfo::setCity(string newCity)
{
	city = newCity;
}

string GeneralInfo::getCity() const
{
	return city;
}

void GeneralInfo::setState(string newState)
{
	state = newState;
}

string GeneralInfo::getState() const
{
	return state;
}

void GeneralInfo::setZipCode(string newZip)
{
	zipCode = newZip;
}

string GeneralInfo::getZipCode() const
{
	return zipCode;
}

void GeneralInfo::setCountry(string newCountry)
{
	country = newCountry;
}

string GeneralInfo::getCountry() const
{
	return country;
}

void GeneralInfo::setEmail(string newEmail)
{
	email = newEmail;
}

string GeneralInfo::getEmail() const
{
	return email;
}

void GeneralInfo::setPhoneNumber(string newNumber)
{
	phoneNumber = newNumber;
}

string GeneralInfo::getPhoneNumber() const
{
	return phoneNumber;
}

void GeneralInfo::setNumOfAdults(string newNumAdults)
{
	numOfAdults = newNumAdults;
}

string GeneralInfo::getNumOfAdults() const
{
	return numOfAdults;
}

void GeneralInfo::setNumOfChildren(string newNumChildren)
{
	numOfChildren = newNumChildren;
}

string GeneralInfo::getNumOfChildren() const
{
	return numOfChildren;
}

GeneralInfo& GeneralInfo::operator=(const GeneralInfo& other)
{
	if(&other != this)
	{
		name = other.getName();
		address = other.getAddress();
		city = other.getCity();
		state = other.getState();
		zipCode = other.getZipCode();
		country = other.getCountry();
		email = other.getEmail();
		phoneNumber = other.getPhoneNumber();
		numOfAdults = other.getNumOfAdults();
		numOfChildren = other.getNumOfChildren();
	}
	else
		cerr << "Attempted assignment to itself.";

	return *this;
}

void GeneralInfo::print() 
{
	cout << name << endl << address << endl << city << ", " << state << " " << zipCode << endl << country << endl << email << endl << phoneNumber << endl;
}


GeneralInfo::~GeneralInfo()
{
	name = "";
	address = "";
	city = "";
	state = "";
	zipCode = "";
	country = "";
	email = "";
	phoneNumber = "";
	numOfAdults = "";
	numOfChildren = "";
}
