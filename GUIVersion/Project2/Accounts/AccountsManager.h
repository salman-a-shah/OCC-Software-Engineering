#ifndef ACCOUNTSMANAGER_H
#define ACCOUNTSMANAGER_H

#include "Accounts.h"
#include <string>
#include <iostream>
using namespace std;

class AccountsManager : public Accounts
{
public:
	//default constructor
	AccountsManager();

	//overloaded constructor
	AccountsManager(const string& newUserName, const string& newPassword);

	//overloaded print
	void print() const;

	//destructor
	~AccountsManager();

private:
	string accountType;
};

#endif

