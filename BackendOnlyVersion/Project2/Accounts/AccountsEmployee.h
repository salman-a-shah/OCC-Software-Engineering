#ifndef ACCOUNTSEMPLOYEE_H
#define ACCOUNTSEMPLOYEE_H

#include "Accounts.h"
#include <string>
#include <iostream>
using namespace std;

class AccountsEmployee : public Accounts
{
public:
	//default constructor
	AccountsEmployee();

	//overloaded constructor
	AccountsEmployee(const string& newUserName, const string& newPassword);
	
	//overloaded print
	void print() const;

	//destructor
	~AccountsEmployee();

private:
	string accountType;
};

#endif
