#include "Reservation.h"


Reservation::Reservation()
{
	ID = 0;
	roomNumber = -1;
	generalInfo = new GeneralInfo();
	requiredInfo = new RequiredInfo();
	extraInfo = new ExtraFeatures();
	creditInfo = new CreditCard();
	reserve();
}

Reservation::Reservation(GeneralInfo& newGeneralInfo, RequiredInfo& newRequiredInfo, ExtraFeatures& newExtraInfo, CreditCard& newCreditInfo)
{
	roomNumber = -1;
	generalInfo = &newGeneralInfo;
	requiredInfo = &newRequiredInfo;
	extraInfo = &newExtraInfo;
	creditInfo = &newCreditInfo;
	reserve();
}

void Reservation::setReservation(Reservation& newReservation)
{
	generalInfo = &newReservation.getGeneralInfo();
	requiredInfo = &newReservation.getRequiredInfo();
	extraInfo = &newReservation.getExtraInfo();
	creditInfo = &newReservation.getCreditInfo();
	ID = newReservation.getID();
	roomNumber = newReservation.getRoomNumber();
}

int Reservation::getID() const
{
	return ID;
}

void Reservation::setID(int newID)
{
	ID = newID;
}

string Reservation::getStatus() const
{
	return status;
}

void Reservation::setStatus(const string& newStatus)
{
	status = newStatus;
}

int Reservation::getRoomNumber() const
{
	return roomNumber;
}
void Reservation::setRoomNumber(int newRoomNumber)
{
	roomNumber = newRoomNumber;
}

void Reservation::setGeneralInfo(GeneralInfo& newGeneralInfo)
{
	generalInfo = &newGeneralInfo;
}

GeneralInfo& Reservation::getGeneralInfo() const
{
	return *generalInfo;
}

void Reservation::setRequiredInfo(RequiredInfo& newRequiredInfo)
{
	requiredInfo = &newRequiredInfo;
}

RequiredInfo& Reservation::getRequiredInfo() const
{
	return *requiredInfo;
}

void Reservation::setExtraInfo(ExtraFeatures& newExtraInfo)
{
	extraInfo = &newExtraInfo;
}

ExtraFeatures& Reservation::getExtraInfo() const
{
	return *extraInfo;
}

void Reservation::setCreditInfo(CreditCard& newCreditInfo)
{
	creditInfo = &newCreditInfo;
}

CreditCard& Reservation::getCreditInfo() const
{
	return *creditInfo;
}

Date& Reservation::getArrivalDate() const
{
	return requiredInfo->getArrivalDate();
}

void Reservation::print() const
{
	cout << "ID: " << ID << endl;
	generalInfo->print();
	cout << "Status: " << status << endl;
	cout << "Room Number: ";
	if (roomNumber >= 0) {
		cout << roomNumber << endl;
	}
	else {
		cout << "N/A" << endl;
	}
}

void Reservation::generateID() {
	ID = rand() % 100000000 + 1000000000;
}

Reservation& Reservation::operator=(const Reservation& other)
{
	if (&other != this)
	{
		ID = other.ID;
		status = other.status;
		roomNumber = other.roomNumber;
		generalInfo = other.generalInfo;
		requiredInfo = other.requiredInfo;
		extraInfo = other.extraInfo;
		creditInfo = other.creditInfo;
	}
	else
		cerr << "Attempted assignment to itself.";

	return *this;
}

void Reservation::copyReservation(const Reservation* other)
{
	ID = other->ID;
	status = other->status;
	roomNumber = other->roomNumber;
	generalInfo = other->generalInfo;
	requiredInfo = other->requiredInfo;
	extraInfo = other->extraInfo;
	creditInfo = other->creditInfo;
}

Reservation::~Reservation()
{
	//generalInfo->~GeneralInfo();
	//delete [] generalInfo;
	//generalInfo = NULL;

	//requiredInfo->~RequiredInfo();
	//delete [] requiredInfo;
	//requiredInfo = NULL;

	//extraInfo->~ExtraFeatures();
	//delete [] extraInfo;
	//extraInfo = NULL;

	//creditInfo->~CreditCard();
	//delete[] creditInfo;
	//creditInfo = NULL;
}
