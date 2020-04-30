#ifndef ACCOUNTSVECTORS_H
#define ACCOUNTSVECTORS_H

#include "Accounts.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class AccountsVector : public Accounts
{
public:
	AccountsVector();
	
	void addAccount(const string& newUsername, const string& newPassword, const string& newName, const string& newAccountType,
		const string& newAge, const string& newGender, const string& newPosition, const string& newPhoneNumber,
		const string& newEmergencyContact, const string& newEmailAddress, const string& newAddress,
		const string& newCity, const string& newState, const string& newZipcode, const string& newCountry, const string& newAdditionalDetails);
	void addAccount(const Accounts& newAccount);
	void deleteAccount(const string&);
	void changeAccount(const string&, const string&, const string&, const string&);

	int getIndex(const string&);
	int getNumOfAccounts() const;

	bool findDuplicates(const string&) const;
	void printAccount(const string&) const;
	void printAllAccounts() const;

	~AccountsVector();

private:
	vector<Accounts> *vectorAccounts;
	int numOfAccounts;
};

#endif

