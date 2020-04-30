#ifndef REQUIREDINFO_H
#define REQUIREDINFO_H

#include<string>
#include<iostream>
#include "Date.h"
using namespace std;

class RequiredInfo
{
public:
	//Constructor
	RequiredInfo(void);

	//Overloaded Constructor
	RequiredInfo(Date& newArrivalDate, Date& newDepartureDate, string newRoomType);

	//Destructor
	~RequiredInfo(void);

	//getArrivalDate
	//@return int
	Date getArrivalDate() const;

	//setArrivalDate
	//@param int 
	void setArrivalDate(Date&);

	//getDepartureDate
	//@return int
	Date getDepartureDate() const;
	void setDepartureDate(Date&);

	string getRoomType() const;
	void setRoomType(string);

	RequiredInfo& operator=(const RequiredInfo& other);

private:
	Date arrivalDate;
	Date departureDate;
	string roomType;
};

#endif

