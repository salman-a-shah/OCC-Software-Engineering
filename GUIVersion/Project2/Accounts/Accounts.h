#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Accounts
{
public:

	//default constructor 
	Accounts();

	//overloaded constructor
	Accounts(const string& newUsername, const string& newPassword);

	//overloaded constructor
	Accounts(const string& newUsername, const string& newPassword, const string& newAccountType, const string& newName,
		const string& newAge, const string& newGender, const string& newPosition, const string& newPhoneNumber,
		const string& newEmergencyContact, const string& newEmailAddress, const string& newAddress,
		const string& newCity, const string& newState, const string& newZipcode, const string& newCountry, const string& newAdditionalDetails);

	//copy constructor
	//Accounts(const Accounts& other);

	//getter for ID
	int getID() const;

	//setter for ID
	void setID(int newID);

	//getter & setter for username
	void setUsername(const string& newUsername);
	string getUsername() const;

	//getter & setter for password
	void setPassword(const string& newPassword);
	string getPassword() const;

	//getter & setter for accountType
	void setAccountType(const string& newAccountType);
	string getAccountType() const;

	//getter & setter for name
	void setName(const string& newName);
	string getName() const;

	//getter & setter for age
	void setAge(const string& newAge);
	string getAge() const;

	//getter & setter for gender
	void setGender(const string& newGender);
	string getGender() const;

	//getter & setter for position
	void setPosition(const string& newPosition);
	string getPosition() const;

	//getter & setter for phoneNumber
	void setPhoneNumber(const string& newPhoneNumber);
	string getPhoneNumber() const;

	//getter & setter for emergencyContact
	void setEmergencyContact(const string& newEmergencyContact);
	string getEmergencyContact() const;

	//getter & setter for emailAddress
	void setEmailAddress(const string& newEmailAddress);
	string getEmailAddress() const;

	//getter & setter for address
	void setAddress(const string& newAddress);
	string getAddress() const;

	//getter & setter for city
	void setCity(const string& newCity);
	string getCity() const;

	//getter & setter for state
	void setState(const string& newState);
	string getState() const;

	//getter & setter for zipcode
	void setZipcode(const string& newZipcode);
	string getZipcode() const;

	//getter & setter for country
	void setCountry(const string& newCountry);
	string getCountry() const;

	//getter & setter for additionalDetails
	void setAdditionalDetails(const string& newAdditionalDetails);
	string getAdditionalDetails() const;

	//print
	void print() const;

	Accounts& operator=(const Accounts& other);

	//destructor
	~Accounts();

private:
	int ID;
	string username;
	string password;
	string accountType;
	string name;
	string age;
	string gender;
	string position;
	string phoneNumber;
	string emergencyContact;
	string emailAddress;
	string address;
	string city;
	string state;
	string zipcode;
	string country;
	string additionalDetails;
};

#endif

