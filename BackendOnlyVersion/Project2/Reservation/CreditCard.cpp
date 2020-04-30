#include "CreditCard.h"
#include "Reservation.h"

//default constructor
CreditCard::CreditCard()
{
}

//overloaded constructor
CreditCard::CreditCard(string newName, string newAddress, string newCity,
	string newState, string newZipCode, string newCreditCardNumber,
	string newExpirationDate, string newVerificationCode, string newCreditCardType)
{
	bName = newName;
	bAddress = newAddress;
	bCity = newCity;
	bZipCode = newZipCode;
	bState = newState;
	creditCardNumber = newCreditCardNumber;
	expirationDate = newExpirationDate;
	verificationCode = newVerificationCode;
	creditCardType = newCreditCardType;
}


//lastName getter
string CreditCard::getBName() const
{
	return bName;
}

//lastName setter
void CreditCard::setBName(string newName)
{
	bName = newName;
}

//address getter
string CreditCard::getBAddress() const
{
	return bAddress;
}

//streetName setter
void CreditCard::setBAddress(string newAddress)
{
	bAddress = newAddress;
}

//city getter
string CreditCard::getBCity() const
{
	return bCity;
}

//city setter
void CreditCard::setBCity(string newCity)
{
	bCity = newCity;
}

//state getter
string CreditCard::getBState() const
{
	return bState;
}

void CreditCard::setBState(string newState)
{
	bState = newState;
}
//zipCode getter
string CreditCard::getBZipCode() const
{
	return bZipCode;
}

//zipCode setter
void CreditCard::setBZipCode(string newZipCode)
{
	bZipCode = newZipCode;
}

//creditCardNumber getter
string CreditCard::getCreditCardNumber() const
{
	return creditCardNumber;
}

//creditCardNumber setter
void CreditCard::setCreditCardNumber(string newCreditCardNumber)
{
	creditCardNumber = newCreditCardNumber;
}

//verificationCode getter
string CreditCard::getVerificationCode() const
{
	return verificationCode;
}

//verificationCode setter
void CreditCard::setVerificationCode(string newVerificationCode)
{
	verificationCode = newVerificationCode;
}

//expirationDate getter
string CreditCard::getExpirationDate() const
{
	return expirationDate;
}

//expirationDate setter
void CreditCard::setExpirationDate(string newExpirationDate)
{
	expirationDate = newExpirationDate;
}

//credit card type getter
string CreditCard::getCreditCardType() const
{
	return creditCardType;
}

//credit card type setter
void CreditCard::setCreditCardType(string newCreditCardType)
{
	creditCardType = newCreditCardType;
}

//determines if names and address match with reservation
bool CreditCard::creditCardVerification(Reservation& r) const
{
	return (bName == r.getGeneralInfo().getName() && bAddress == r.getGeneralInfo().getAddress()
		&& bCity == r.getGeneralInfo().getCity() && bState == r.getGeneralInfo().getState()
		&& bZipCode == r.getGeneralInfo().getZipCode());
}

//print
void CreditCard::print() const
{
	cout << "American Express" << endl << "Card Number: " << creditCardNumber << endl
		<< "Expiration Date: " << expirationDate.substr(0, 2) << "/" << expirationDate.substr(2, -1)
		<< endl << "Verification Code: " << verificationCode << "Credit Card Type: " << creditCardType << endl << endl;

	cout << "Billing Address: " << endl
		<< bName << endl << bAddress << endl << bCity << ", " << bState << " " << bZipCode << endl << endl;
}

CreditCard::~CreditCard()
{

}
