#ifndef EXTRAFEATURES_H
#define EXTRAFEATURES_H

#include <iostream>
#include <string>
using namespace std;

class ExtraFeatures
{
public:
	ExtraFeatures();
	ExtraFeatures(string newText);

	void setUserText(string newText);
	string getUserText() const;

	ExtraFeatures& operator=(const ExtraFeatures& other);

	~ExtraFeatures();
private:
	string userText;
};

#endif
