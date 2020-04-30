#include "AccountsEmployee.h"

//default constructor
AccountsEmployee::AccountsEmployee()
{
	accountType = "employee";
}

//overloaded constructor
AccountsEmployee::AccountsEmployee(const string& newUsername, const string& newPassword)
: Accounts(newUsername, newPassword)
{
	accountType = "employee";
}

//overloaded print
void AccountsEmployee::print() const
{
	cout << "Username: " << Accounts::getUsername() << endl
		<< "Password: " << Accounts::getPassword() << endl
		<< "Account Type: " << accountType << endl;
}

//destructor
AccountsEmployee::~AccountsEmployee()
{
}
