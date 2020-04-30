#include "Accounts.h"

//default constructor
Accounts::Accounts()
{
}

Accounts::Accounts(const string& newUsername, const string& newPassword)
{
	username = newUsername;
	password = newPassword;
}

//overloaded constructor w/ Account Type
Accounts::Accounts(const string& newUsername, const string& newPassword, const string& newAccountType, const string& newName,
	const string& newAge, const string& newGender, const string& newPosition, const string& newPhoneNumber,
	const string& newEmergencyContact, const string& newEmailAddress, const string& newAddress,
	const string& newCity, const string& newState, const string& newZipcode, const string& newCountry, const string& newAdditionalDetails)
{
	username = newUsername;
	password = newPassword;
	accountType = newAccountType;
	name = newName;
	age = newAge;
	gender = newGender;
	position = newPosition;
	phoneNumber = newPhoneNumber;
	emergencyContact = newEmergencyContact;
	emailAddress = newEmailAddress;
	address = newAddress;
	city = newCity;
	zipcode = newZipcode;
	state = newState;
	country = newCountry;
	additionalDetails = newAdditionalDetails;
}

//getter for ID
int Accounts::getID() const
{
	return ID;
}

//setter for ID
void Accounts::setID(int newID)
{
	ID = newID;
}

//setter for username
void Accounts::setUsername(const string&  newUsername)
{
	username = newUsername;
}

//getter for username
string Accounts::getUsername() const
{
	return username;
}

//setter for password
void Accounts::setPassword(const string&  newPassword)
{
	password = newPassword;
}

//getter for password
string Accounts::getPassword() const
{
	return password;
}

//setter for accountType
void Accounts::setAccountType(const string& newAccountType)
{
	accountType = newAccountType;
}

//getter for accountType
string Accounts::getAccountType() const
{
	return accountType;
}

//getter & setter for name
void Accounts::setName(const string& newName)
{
	name = newName;
}

string Accounts::getName() const
{
	return name;
}

//getter & setter for age
void Accounts::setAge(const string& newAge)
{
	age = newAge;
}
string Accounts::getAge() const
{
	return age;
}

//getter & setter for gender
void Accounts::setGender(const string& newGender)
{
	gender = newGender;
}

string Accounts::getGender() const
{
	return gender;
}

//getter & setter for position
void Accounts::setPosition(const string& newPosition)
{
	position = newPosition;
}

string Accounts::getPosition() const
{
	return position;
}

//getter & setter for phoneNumber
void Accounts::setPhoneNumber(const string& newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
}

string Accounts::getPhoneNumber() const
{
	return phoneNumber;
}

//getter & setter for emergencyContact
void Accounts::setEmergencyContact(const string& newEmergencyContact)
{
	emergencyContact = newEmergencyContact;
}

string Accounts::getEmergencyContact() const
{
	return emergencyContact;
}

//getter & setter for emailAddress
void Accounts::setEmailAddress(const string& newEmailAddress)
{
	emailAddress = newEmailAddress;
}
string Accounts::getEmailAddress() const
{
	return emailAddress;
}

//getter & setter for address
void Accounts::setAddress(const string& newAddress)
{
	address = newAddress;
}
string Accounts::getAddress() const
{
	return address;
}

//getter & setter for city
void Accounts::setCity(const string& newCity)
{
	city = newCity;
}

string Accounts::getCity() const
{
	return city;
}

//getter & setter for state
void Accounts::setState(const string& newState)
{
	state = newState;
}

string Accounts::getState() const
{
	return state;
}

//getter & setter for zipcode
void Accounts::setZipcode(const string& newZipcode)
{
	zipcode = newZipcode;
}

string Accounts::getZipcode() const
{
	return zipcode;
}

//getter & setter for country
void Accounts::setCountry(const string& newCountry)
{
	country = newCountry;
}

string Accounts::getCountry() const
{
	return country;
}

//getter & setter for additionalDetails
void Accounts::setAdditionalDetails(const string& newAdditionalDetails)
{
	additionalDetails = newAdditionalDetails;
}

string Accounts::getAdditionalDetails() const
{
	return additionalDetails;
}

//print
void Accounts::print() const
{
	cout << "Username: " << username << endl
		<< "Password: " << password << endl
		<< "Account Type: " << accountType << endl
		<< "Name: " << name << endl
		<< "Age: " << age << endl
		<< "Gender: " << gender << endl
		<< "Position: " << position << endl
		<< "Phone Number: " << phoneNumber << endl
		<< "Emergency Contact: " << emergencyContact << endl
		<< "Email Address: " << emailAddress << endl
		<< "Address: " << address << endl
		<< "City: " << city << endl
		<< "State: " << state << endl
		<< "Country: " << country << endl
		<< "Additional Details: " << additionalDetails << endl << endl;
}

Accounts& Accounts::operator=(const Accounts& other)
{
	if (&other != this)
	{
		ID = other.getID();
		username = other.getUsername();
		password = other.getPassword();
		accountType = other.getAccountType();
		name = other.getName();
		age = other.getAge();
		gender = other.getGender();
		position = other.getPosition();
		phoneNumber = other.getPhoneNumber();
		emergencyContact = other.getEmergencyContact();
		emailAddress = other.getEmailAddress();
		address = other.getAddress();
		city = other.getCity();
		state = other.getState();
		country = other.getCountry();
		additionalDetails = other.getAdditionalDetails();
	}
	else
		cerr << "Attempted assignment to itself.";

	return *this;
}

//destructor
Accounts::~Accounts()
{
}
