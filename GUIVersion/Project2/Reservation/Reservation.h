#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "GeneralInfo.h"
#include "ExtraFeatures.h"
#include "RequiredInfo.h"
#include "CreditCard.h"
#include "Date.h"

using namespace std;

class Reservation
{
public:
	Reservation();

	Reservation(GeneralInfo& newGeneralInfo, RequiredInfo& newRequiredInfo, ExtraFeatures& newExtraInfo, CreditCard& newCreditInfo);

	void setReservation(Reservation& newReservation);

	int getID() const;
	void setID(int newID);

	int getRoomNumber() const;
	void setRoomNumber(int newRoomNumber);

	string getStatus() const;
	void setStatus(const string& newStatus);

	void setGeneralInfo(GeneralInfo& newGeneralInfo);
	GeneralInfo&  getGeneralInfo() const;

	void setRequiredInfo(RequiredInfo& newRequiredInfo);
	RequiredInfo& getRequiredInfo() const;

	void setExtraInfo(ExtraFeatures& newExtraInfo);
	ExtraFeatures& getExtraInfo() const;

	void setCreditInfo(CreditCard& newCreditInfo);
	CreditCard& getCreditInfo() const;

	void copyReservation(const Reservation *other);
	Reservation& operator=(const Reservation& other);

	Date& getArrivalDate() const;

	void print() const;

	bool isReserved() const {
		if (status == "Reserved") { return true; }
		return false;
	}
	bool isCheckedIn() const {
		if (status == "Checked In") { return true; }
		return false;
	}
	bool isCheckedOut() const {
		if (status == "Checked Out") { return true; }
		return false;
	}
	bool isNoShow() const {
		if (status == "No Show") { return true; }
		return false;
	}
	bool isCancelled() const {
		if (status == "Cancelled") { return true; }
		return false;
	}

	// These functions are for changing the status fo the reservation.
	void reserve() {
		status = "Reserved";
	}
	void checkIn() {
		status = "Checked In";
	}
	void checkOut() {
		status = "Checked Out";
	}
	void noShow() {
		status = "No Show";
	}
	void cancel() {
		status = "Cancelled";
	}

	// This function is for randomly generating an ID
	// Only used in the overloaded constructor
	void generateID();

	~Reservation();

private:
	int ID, roomNumber;
	string status;
	GeneralInfo *generalInfo;
	RequiredInfo *requiredInfo;
	ExtraFeatures *extraInfo;
	CreditCard *creditInfo;

};

#endif
