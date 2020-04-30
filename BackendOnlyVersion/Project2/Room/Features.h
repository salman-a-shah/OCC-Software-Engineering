
#ifndef FEATURES_H
#define FEATURES_H

#include <vector>
#include <string>
using namespace std;

//typedef vector<string>::iterator featuresIter;

class Features
{
public:
	Features();
	Features(const string&);

	// Getters
	int getID() const;
	string getFeatureName() const;

	// Setters
	void setID(int newID);
	void setFeatureName(const string& newFeatureName);
	void print() const;

private:
	int ID;
	string featureName;

};

#endif

