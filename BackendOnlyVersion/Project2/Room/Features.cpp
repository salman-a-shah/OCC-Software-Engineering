#include "Features.h"
#include <iostream>
using namespace std;

// Constructor
Features::Features()
{
	featureName = "";
}

Features::Features(const string& newFeatureName)
{
	featureName = newFeatureName;
}

// Getters
int Features::getID() const
{
	return ID;
}

void Features::setID(int newID)
{
	ID = newID;
}

string Features::getFeatureName() const
{
	return featureName;
}

// Functions
void Features::setFeatureName(const string& newFeatureName)
{
	featureName = newFeatureName;
}

// This function is used only for testing purposes.
// Won't be used in the actual program.
void Features::print() const
{
	cout << featureName;
}
