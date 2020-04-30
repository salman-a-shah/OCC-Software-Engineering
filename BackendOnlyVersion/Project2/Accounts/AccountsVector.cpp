#include "AccountsVector.h"

AccountsVector::AccountsVector()
{
	vectorAccounts = new vector<Accounts>;
}

void AccountsVector::addAccount(const string& newUsername, const string& newPassword, const string& newAccountType, const string& newName, 
	const string& newAge, const string& newGender, const string& newPosition, const string& newPhoneNumber,
	const string& newEmergencyContact, const string& newEmailAddress, const string& newAddress,
	const string& newCity, const string& newState, const string& newZipcode, const string& newCountry, const string& newAdditionalDetails)
{
	if (findDuplicates(newUsername))
		cerr << "-- The username \"" << newUsername << 
		"\" has already been used. Please enter a different username";
	else
	{
		vectorAccounts->push_back(Accounts(newUsername, newPassword, newAccountType, newName, newAge, 
		newGender, newPosition, newPhoneNumber, newEmergencyContact, newEmailAddress, 
		newAddress, newCity, newState, newZipcode, newCountry, newAdditionalDetails));
		numOfAccounts++;
	}
}

void AccountsVector::addAccount(const Accounts& newAccount)
{
	if (findDuplicates(newAccount.getUsername()))
		cerr << "-- The account \"" << newAccount.getUsername() <<
		"\" is already in the system." << endl << endl;
	else
	{
		vectorAccounts->push_back(newAccount);
		numOfAccounts++;
	}
}

//implement
void AccountsVector::deleteAccount(const string& newUsername)
{
	vector<Accounts>::iterator it = vectorAccounts->begin();
	if (getIndex(newUsername) == -1)
		cerr << "-- The account \"" << newUsername <<
		"\" was not found, hence no deletion occured" << endl << endl;
	else
	{
		it = vectorAccounts->erase(it + getIndex(newUsername));
		numOfAccounts--;
	}
}

//implement
void AccountsVector::changeAccount(const string& oldUsername, const string& newUsername, const string& newPassword, const string& newAccountType)
{
	if (getIndex(oldUsername) == -1)
		cerr << "-- The account \"" << oldUsername << 
		"\" is not in the system." << endl << endl;
	else if (findDuplicates(newUsername))
	{
		cerr << "-- Cannot use \"" << newUsername << 
			"\". It is already in the system." << endl << endl;
	}
	else
	{
		vector<Accounts>::iterator it = vectorAccounts->begin() + getIndex(oldUsername);
		if (newUsername == ""){}
		else 
			(it->setUsername(newUsername));
		if (newPassword == ""){}
		else
			(it->setPassword(newPassword));
		if (newAccountType == ""){}
		else
			(it->setAccountType(newAccountType));
	}
}

int AccountsVector::getIndex(const string& newUsername)
{
	vector<Accounts>::const_iterator it = vectorAccounts->begin();
	int n = 0;
	while (it != vectorAccounts->end())
	{
		if (it->getUsername() == newUsername)
			return n;
		else
		{
			n++;
			it++;
		}
	}
	return -1;
}

int AccountsVector::getNumOfAccounts() const
{
	return numOfAccounts;
}

bool AccountsVector::findDuplicates(const string& newUsername) const
{
	vector<Accounts>::const_iterator it = vectorAccounts->begin();
	while (it != vectorAccounts->end())
	{
		if (it->getUsername() == newUsername)
			return true;
		else
			it++;
	}
	return false;
}

void AccountsVector::printAccount(const string& newUsername) const
{
	vector<Accounts>::const_iterator it;
	for (it = vectorAccounts->begin(); it != vectorAccounts->end(); it++)
	{
		if (it->getUsername() == newUsername)
		{
			it->print();
		}
	}
}

void AccountsVector::printAllAccounts() const
{
	vector<Accounts>::const_iterator it;
	for (it = vectorAccounts->begin(); it != vectorAccounts->end(); it++)
	{
		it->print();
		cout << endl;
	}
}

AccountsVector::~AccountsVector()
{
}
