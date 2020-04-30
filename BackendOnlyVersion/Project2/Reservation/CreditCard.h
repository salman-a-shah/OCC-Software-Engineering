#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CreditCard
{
public:

	friend class Reservation;

	//default constructor
	CreditCard();

	//overloaded constructor
	CreditCard(string, string, string, string, string, string, string, string, string);

	//bName getter & setter
	string getBName() const;
	void setBName(string);

	//bAddress getter & setter
	string getBAddress() const;
	void setBAddress(string);

	//bCity getter & setter
	string getBCity() const;
	void setBCity(string);

	//bState getter & setter
	string getBState() const;
	void setBState(string);

	//bZipCode getter & setter
	string getBZipCode() const;
	void setBZipCode(string);

	//CreditCardNumber getter & setter
	string getCreditCardNumber() const;
	void setCreditCardNumber(string);

	//verification code getter & setter
	string getVerificationCode() const;
	void setVerificationCode(string);

	//expiration date getter & setter
	string getExpirationDate() const;
	void setExpirationDate(string);

	//credit card type getter & setter
	string getCreditCardType() const;
	void setCreditCardType(string);

	//determines if names and address match with reservation
	bool creditCardVerification(Reservation& r) const;

	//prints out credit card info for testing
	void print() const;

	~CreditCard();

private:

	string bName;
	string bAddress;
	string bState;
	string bCity;
	string bZipCode;

	string creditCardNumber;
	string verificationCode;
	string expirationDate;
	string creditCardType;
};

#endif
