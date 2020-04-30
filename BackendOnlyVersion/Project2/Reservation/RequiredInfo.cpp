#include "RequiredInfo.h"


RequiredInfo::RequiredInfo()
{
	arrivalDate = Date();
	departureDate = Date();
	roomType = "";
}

RequiredInfo::RequiredInfo(Date& newArrivalDate, Date& newDepartureDate, string newRoomtype)
{
	arrivalDate = newArrivalDate;
	departureDate = newDepartureDate;
	roomType = newRoomtype;
}

Date RequiredInfo::getArrivalDate() const
{
	return arrivalDate;
}

void RequiredInfo::setArrivalDate(Date &newArrivalDate)
{
	arrivalDate = newArrivalDate;
}

Date RequiredInfo::getDepartureDate() const
{
	return departureDate;
}

void RequiredInfo::setDepartureDate(Date &newDepartureDate)
{
	departureDate = newDepartureDate;
}

string RequiredInfo::getRoomType() const
{
	return roomType;
}

void RequiredInfo::setRoomType(string newRoomType)
{
	roomType = newRoomType;
}

RequiredInfo& RequiredInfo::operator=(const RequiredInfo& other)
{
	if(&other != this)
	{
		arrivalDate = other.getArrivalDate();
		departureDate = other.getDepartureDate();
		roomType = other.getRoomType();
	}
	else
		cerr << "Attempted assignment to itself";

	return *this;
}

RequiredInfo::~RequiredInfo()
{
	arrivalDate = 0;
	departureDate = 0;
	roomType = "";
}
