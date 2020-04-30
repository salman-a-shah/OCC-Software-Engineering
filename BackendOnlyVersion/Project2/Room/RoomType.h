/*
* RoomType.h
*
*  Created on: Mar 22, 2014
*      Author: Salman
*/
#include <string>
#include <iostream>
#ifndef ROOMTYPE_H_
#define ROOMTYPE_H_
using namespace std;

class RoomType
{
public:
	// Constructors
	RoomType();
	RoomType(string newTypeName,
		string newCode,
		int newMaxAdults,
		int newMaxChildren,
		int newNumOfBeds,
		string desc);


	// Getters for the variables.

	int getID() const;
	string getTypeName() const;
	string getTypeCode() const;
	int getMaxAdults() const;
	int getMaxChildren() const;
	int getNumberOfBeds() const;
	string getDescription() const;

	// Setters for the variables.

	void setID(int newID);
	void setTypeName(const string& newTypeName);
	void setTypeCode(const string& newTypeCode);
	void setMaxAdults(int newMax);
	void setMaxChildren(int newMax);
	void setNumberOfBeds(int newNum);
	void setDescription(const string& newDesc);


	// Other functions.

	// This print function is mainly used for testing.
	// Probably won't be used in actual program.
	// It's used in object Hotel to print available roomtypes.
	void print() const;

private:
	int ID;
	string typeName;
	string typeCode;
	int maximumNumOfAdults;
	int maximumNumOfChildren;
	int numberOfBeds;
	string description;
};


#endif /* ROOMTYPE_H_ */
