#ifndef GENERALINFO_H
#define GENERALINFO_H

#include <iostream>
#include <string>
using namespace std;

class GeneralInfo
{
public:
	GeneralInfo();

	GeneralInfo(string newName, string newAddress, string newCity, string newState, string newZip, string newCountry, string newEmail, string newPhoneNumber, string newNumAdults, string newNumChildren);

	void setName(string newName);
	string getName() const;

	void setAddress(string newAddress);
	string getAddress() const;

	void setCity(string newCity);
	string getCity() const;

	void setState(string newState);
	string getState() const;

	void setZipCode(string newZip);
	string getZipCode() const;

	void setCountry(string newCountry);
	string getCountry() const;

	void setEmail(string newEmail);
	string getEmail() const;

	void setPhoneNumber(string newNumber);
	string getPhoneNumber() const;

	void setNumOfAdults(string newNumAdults);
	string getNumOfAdults() const;

	void setNumOfChildren(string newNumChildren);
	string getNumOfChildren() const;

	void print();

	GeneralInfo& operator=(const GeneralInfo& other);

	~GeneralInfo();

private:
	string name, address, city, state, country, 
		    zipCode, email, phoneNumber, numOfAdults, numOfChildren;
};

#endif
