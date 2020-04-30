#include "AccountsManager.h"

//default constructor
AccountsManager::AccountsManager()
{
	accountType = "manager";
}

//overloaded constructor
AccountsManager::AccountsManager(const string& newUsername, const string& newPassword)
: Accounts(newUsername, newPassword)
{
	accountType = "manager";
}

//overloaded print
void AccountsManager::print() const
{
	cout << "Username: " << Accounts::getUsername() << endl
		<< "Password: " <<  Accounts::getPassword() << endl
		<< "Account Type: " << accountType << endl;
}

//destructor
AccountsManager::~AccountsManager()
{
}
