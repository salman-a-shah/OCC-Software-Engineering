/*
* RoomType.cpp
*
*  Created on: Mar 22, 2014
*      Author: Salman
*/
#include "RoomType.h"
using namespace std;

RoomType::RoomType()
{
	typeName = "Default";
	typeCode = "Default";
	maximumNumOfAdults = 0;
	maximumNumOfChildren = 0;
	numberOfBeds = 0;
}


RoomType::RoomType(string newTypeName,
	string newCode,
	int newMaxAdults,
	int newMaxChildren,
	int newNumOfBeds,
	std::string desc)
{
	typeName = newTypeName;
	typeCode = newCode;
	maximumNumOfAdults = newMaxAdults;
	maximumNumOfChildren = newMaxChildren;
	numberOfBeds = newNumOfBeds;
	description = desc;
}

int RoomType::getID() const
{
	return ID;
}

string RoomType::getTypeName() const
{
	return typeName;
}
string RoomType::getTypeCode() const
{
	return typeCode;
}
int RoomType::getMaxAdults() const
{
	return maximumNumOfAdults;
}
int RoomType::getMaxChildren() const
{
	return maximumNumOfChildren;
}
int RoomType::getNumberOfBeds() const
{
	return numberOfBeds;
}
string RoomType::getDescription() const
{
	return description;
}


// Setters for the variables.

void RoomType::setID(int newID)
{
	ID = newID;
}

void RoomType::setTypeName(const string& newTypeName)
{
	typeName = newTypeName;
}
void RoomType::setTypeCode(const string& newTypeCode)
{
	typeCode = newTypeCode;
}
void RoomType::setMaxAdults(int newMax)
{
	maximumNumOfAdults = newMax;
}
void RoomType::setMaxChildren(int newMax)
{
	maximumNumOfChildren = newMax;
}
void RoomType::setNumberOfBeds(int newNum)
{
	numberOfBeds = newNum;
}
void RoomType::setDescription(const string& newDesc)
{
	description = newDesc;
}

void RoomType::print() const
{
	cout << "Type Name: " << typeName << endl;
	cout << "Type Code: " << typeCode << endl;
	cout << "Max Adults: " << maximumNumOfAdults << endl;
	cout << "Max Children: " << maximumNumOfChildren << endl;
	cout << "Number of Beds: " << numberOfBeds << endl;
	cout << "Description: " << description << endl;
	cout << endl;
}
