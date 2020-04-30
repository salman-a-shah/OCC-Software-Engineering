/*
 * Hotel.h

 *
 *  Created on: Mar 22, 2014
 *      Author: Salman
 */
#ifndef HOTEL_H
#define HOTEL_H

#include "Room\Room.h"
#include "Reservation\Reservation.h"
#include "DB.h"
#include "Accounts\Accounts.h"
#include <vector>
#include <list>
#include <iostream>
using namespace std;

typedef list<Reservation*>::iterator reservationIter;
typedef vector<Room*>::iterator roomIter;
typedef vector<RoomType*>::iterator roomTypeIter;
typedef vector<Accounts*>::iterator accountsIter;
const int CAPACITY = 112;

class Hotel
{
public:
	friend class DB;
	// Default Constructor
	// Initiates the array of lists of type Reservation.
	Hotel();

	//////////////////////////////////////////////////////////////////////////////////
	/////////////////////////// DIVIDER FOR EASIER READING ///////////////////////////


	///// FUNCTIONS FOR ROOMTYPE ///////
	// These are functions to manipulate the
	// vector containing all roomType pointers: allRoomTypes


	// This function will add a roomType object pointer to the vector allRoomTypes
	//
	// @param typeName 		the name of the roomType
	// @param typeCode		the code for the room type
	// @param maxAdults		the maximum number of adults allowed in this roomtype
	// @param maxChildren	the maximum number of children allowed in this roomtype
	// @param numberOfBeds	the number of beds assigned to this roomType
	// @param description	a string for the description.
	// @return bool			true if successful, false if not.
	bool addRoomType(const string& typeName,
					 const string& typeCode,
					 int maxAdults,
					 int maxChildren,
					 int numberOfBeds,
					 const string& description);

	// This function will delete a roomType object and return true if successful
	//
	// @param typeName		the name is all thats needed to find the roomType
	//						and delete it
	// @return bool			true if successful, false if not.
	bool deleteRoomType(const string& typeName);


	// This function will modify a roomType object in the vector allRoomTypes
	// It overrides all of the information saved in a RoomType object
	//
	// @param typeName 		the name of the room type to modify
	// @param typeCode		a new code for the room type
	// @param maxAdults		new number for the maximum number of adults allowed
	// @param maxChildren	new number for the maximum number of children allowed
	// @param numberOfBeds	the new number of beds to assign to this roomType
	// @param description	a new description to override the previous with
	// @return bool			true if successful, false if not.
	bool modifyRoomType(const string& typeName,
						const string& typeCode,
						int maxAdults,
						int maxChildren,
						int numberOfBeds,
						const string& description);


	// This function finds a specific roomType from the vector allRoomTypes
	// It is used to navigate around the vector for deletion or modification
	// Returns an iterator to the end if not found. When using this function,
	// check to make sure its not at the end with (iter != theVector.end())
	//
	// @param typeName		the name of the roomType to find
	// @return roomTypeIter	the location where the roomType pointer lives,
	//						returns the end of the vector if not found
	roomTypeIter findRoomType(const string& typeName);


	// This function is for testing whether or not there exists a room type with the given name.
	// It will mostly be used to avoid having duplicate type names
	//
	// @param typeName 		the name of the room type to check
	// @return bool			true if it exists. false if it does not
	bool roomTypeExists(const string& typeName);


	// This is for testing only. Will most likely never be used in the actual program
	// This function will print all the roomTypes that exist in the vector using
	// the print function from the roomType Object.
	//
	// @param
	// @return
	void printRoomTypes() const;


	//////////////////////////////////////////////////////////////////////////////////
	/////////////////////////// DIVIDER FOR EASIER READING ///////////////////////////


	/////// FUNCTIONS FOR ROOMS ///////////
	// These are functions to manipulate the
	// vector containing all room pointers: allRooms


	// This function adds a room object pointer in the vector allRooms
	//
	// @param roomNumber	a unique room for the new room
	// @param roomType		a string to decide which room type to assign
	// @return bool			true if successful, false if not.
	bool addRoom(int roomNumber, const string& roomType);


	// This function deletes a room object pointer in the vector allRooms
	// Cannot have any CHECKED IN reservation blocking it
	//
	// @param roomNumber	room number of an existing room
	// @return bool			true if successful, false if not
	bool deleteRoom(int roomNumber);


	// This function will modify a Room object in the vector allRooms
	//
	// @param roomNumber	the room number to modify
	// @param newNumber		a new room number to assign
	// @param newType		a new roomtype to assign
	// @return bool			true if successful, false if not.
	bool modifyRoom(int roomNumber,
					int newNumber,
					const string& newType);


	// The following functions are for modifying room features.
	// They use the same functions as found in Room class.

	// This function adds a string to the features instance
	//
	// @param roomNumber	the room number to edit
	// @param newFeature	a string to add to the features instance
	// @return bool			true if successful, false if not
	bool addRoomFeature(int roomNumber, const std::string& newFeature);


	// This function deletes a string from the features instance
	//
	// @param roomNumber	the room number to edit
	// @param featureToDelete	the string to delete from the features class
	// @return bool			true if successful, false if not
	bool deleteRoomFeature(int roomNumber, const std::string& featureToDelete);


	// This function changes the feature from one string to another string.
	//
	// @param roomNumber	the room number to edit
	// @param toChange		the string to change
	// @param whatToChangeTo	the new string to replace with
	// @return bool			true if successful, false if not
	bool changeRoomFeature(int roomNumber,
				const std::string& toChange,
				const std::string& whatToChangeTo);

	// This is for testing the features objects.
	void printRoomFeatures();

	// returns true if the feature exists already
	bool featureExists(const string &featureToCheck);


	// This function finds a specific room from the vector allRooms
	// It is used to navigate around the vector for deletion or modification
	// Returns an iterator to the end if not found. When using this function,
	// check to make sure its not at the end with (iter != theVector.end())
	//
	// @param roomNumber	room number of an existing room
	// @return roomIter		the location where the room object pointer lives,
	//						returns the end of the vector if not found
	roomIter findRoom(int roomNumber);


	// This function is for testing whether or not there exists a room with a specific roomNumber.
	// It will mostly be used to avoid having duplicate room numbers
	//
	// @param roomNumber	the room number to check
	// @return bool			true if it exists. false if it does not
	bool roomNumberExists(int roomNumber);


	// This is for testing only. Will mostly likely not be used in the actual program
	// This function prints all of the rooms using the print() function available
	// inside of Room class.
	//
	// @param
	// @return
	void printRooms() const;


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////DIVIDER FOR EASIER READING///////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Reservation * getReservationFromDB(int ID);
	void deleteReservationFromDB(int reservationID);

	void setCurrentDate(Date& newCurrentDate);

	Date& getCurrentDate()  const;

	int calculateDateIndex(Date& reservationDate) const;

	reservationIter findReservation(int dateIndex, int reservationID);
	reservationIter findReservation(int reservationID);

	void populateArray();

	//This adds an object of type Reservation to the array sorted based on the current date.
	void addReservation(Reservation& newReservation);

	void modifyReservation(Reservation& modifiedReservation, Date& reservationDate, int reservationID);
	void modifyReservation(Reservation& modifiedReservation, int reservationID);

	void deleteReservation(Date& reservationDate, int reservationID);
	void deleteReservation(int reservationID);




	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////DIVIDER FOR EASIER READING///////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// This will connect the reservation to the room and block off that room for that reservation so
	// that no other reservation may choose that room.
	//
	// @param theReservation	the reservation object that will hold the room number.
	// @param roomNumber		the room number to block off
	void assignRoomNumber(Reservation& theReservation, int roomNumber);


	// This will unassign a room number from a reservation and make the blocked room
	// available to other reservations
	//
	// @param theReservation	the reservation object that will lose its room number
	void removeRoomAssignment(Reservation& theReservation);

	// This will insure the date is the current date and then
	// change the reservation status to "CheckedIn". It's bool
	// because it has a chance of failing.
	// arrival date much match current date
	// room number must be assigned
	// 
	// @param theReservation	the reservation object to manipulate
	// @return bool				true if successful, false otherwise
	bool checkInRes(Reservation& theReservation);


	// This will unblock the room and then change the
	// reservation status to "CheckedOut". It's void becuase
	// it cannot fail.
	//
	// @param theReservation	the reservation object to manipulate
	void checkOutRes(Reservation& theReservation);


	// This will change the reservation object's status to "Cancelled",
	// (if necessary) unassign room number, and unblock room.
	// It's void because it cannot fail.
	//
	// @param theReservation	the reservation object to manipulate
	void cancelRes(Reservation& theReservation);

	// This will change the reservation status to "No Show"
	// It's void (as opposed to bool) because users will not
	// use this function. This will only be used during
	// Night Audit
	//
	// (if necessary) will unassign room number, and unblock room
	// The date must match current date
	//
	// @param theReservation	the reservation object to manipulate
	void noShowRes(Reservation& theReservation);

	// This function is for putting reservations from other states
	// back to "Reserved." It's a bool function because it's possible
	// for it to fail to put the reservation back.
	//
	// Will check to make sure the date hasn't passed yet
	// if the date is current or in the future, it will
	// change the reservation status to "Reserved" and
	// unassign the room number.
	// 
	// @param theReservation	the reservation to manipulate
	// @return bool				true if successfully returned
	bool reserve(Reservation& theReservation);

	// This is for testing purposes only. 
	void printReservationArray() const;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////DIVIDER FOR EASIER READING///////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool addAccount(const string& newUsername, const string& newPassword, const string& newAccountType,
		const string& newName, const string& newAge, const string& newGender, const string& newPosition,
		const string& newPhoneNumber, const string& newEmergencyContact, const string& newEmailAddress,
		const string& newAddress, const string& newCity, const string& newState, const string& newZipcode,
		const string& newCountry, const string& newAdditionalDetails);

	bool deleteAccount(const string& newUsername);

	bool modifyAccount(const string& newUsername, const string& newPassword, const string& newAccountType,
		const string& newName, const string& newAge, const string& newGender, const string& newPosition,
		const string& newPhoneNumber, const string& newEmergencyContact, const string& newEmailAddress,
		const string& newAddress, const string& newCity, const string& newState, const string& newZipcode,
		const string& newCountry, const string& newAdditionalDetails);

	accountsIter findAccount(const string& newUsername);

	bool accountExists(const string& newUsername);

	void printAccount() const;

	~Hotel();

private:
	vector<RoomType *> allRoomTypes;
	vector<Room *> allRooms;
	vector<Accounts *> allAccounts;
	vector<Reservation *> allReservations;
	vector<Features *> allFeatures;
	list<Reservation *> *calendarArray;
	Date *currentDate;
	DB *db;
};


#endif /* HOTEL_H_ */
