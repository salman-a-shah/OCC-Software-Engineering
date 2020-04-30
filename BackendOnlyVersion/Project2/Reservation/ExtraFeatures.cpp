#include "ExtraFeatures.h"


ExtraFeatures::ExtraFeatures()
{
	userText = "";
}

ExtraFeatures::ExtraFeatures(string newText)
{
	userText = newText;
}

void ExtraFeatures::setUserText(string newText)
{
	userText = newText;
}

string ExtraFeatures::getUserText() const
{
	return userText;
}

ExtraFeatures& ExtraFeatures::operator=(const ExtraFeatures& other)
{
	if(&other != this)
	{
		userText = other.getUserText();
	}
	else
		cerr << "Attempted assignment to itself.";

	return *this;
}


ExtraFeatures::~ExtraFeatures()
{
	userText = "";
}
