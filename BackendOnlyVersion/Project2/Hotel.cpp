/*
 * Hotel.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: Salman
 */
#include "Hotel.h"


// The default constructor
// Initiates the array of lists of type Reservation.
Hotel::Hotel()
{
	calendarArray = new list<Reservation *>[CAPACITY];
	db = new DB("DB.sqlite");
	db->startup(db, allAccounts, allRooms, allRoomTypes, allFeatures, allReservations);
	Date *currentDate = new Date();
	db->getDate(db, currentDate);
	setCurrentDate(*currentDate);
	populateArray();
}


// This function is for adding roomTypes to the vector of roomType pointers
// Objects are dynamically created and a pointer is inserted into the vector
bool Hotel::addRoomType(const string& typeName,
						const string& typeCode,
						int maxAdults,
						int maxChildren,
						int numberOfBeds,
						const string& description)
{
	if (!roomTypeExists(typeName))
	{
		RoomType * newRoomType = new RoomType(typeName,
											typeCode,
											maxAdults,
											maxChildren,
											numberOfBeds,
											description);
		allRoomTypes.push_back(newRoomType);
		db->addRoomType(db, newRoomType);
		return true;
	}
	return false;
}

// This function will delete a roomType object and return true if successful
bool Hotel::deleteRoomType(const string& typeName)
{
	roomTypeIter iter = findRoomType(typeName);
	if (iter != allRoomTypes.end()) {
		db->deleteRoomType(db, *iter);
		allRoomTypes.erase(iter);
		return true;
	}
	return false;
}

// This function will modify a roomType object in the vector allRoomTypes
// It finds the room to modify then assigns all the new information within it
bool Hotel::modifyRoomType(const string& typeName,
	const string& typeCode,
	int maxAdults,
	int maxChildren,
	int numberOfBeds,
	const string& description)
{
	RoomType *temp = new RoomType(typeName, typeCode, maxAdults,
		maxChildren, numberOfBeds, description);
	roomTypeIter iter = findRoomType(typeName);
	if (iter != allRoomTypes.end())
	{
		(*iter)->setTypeCode(typeCode);
		(*iter)->setMaxAdults(maxAdults);
		(*iter)->setMaxChildren(maxChildren);
		(*iter)->setDescription(description);
		(*iter)->setNumberOfBeds(numberOfBeds);
		db->updateRoomType(db, *iter, temp);
		return true;
	}
	return false;
}


// This function finds a specific roomType from the vector allRoomTypes
// It is used to navigate around the vector for deletion or modification
roomTypeIter Hotel::findRoomType(const string& typeName)
{
	roomTypeIter iter = allRoomTypes.begin();

	while (iter != allRoomTypes.end())
	{
		if ((*iter)->getTypeName() == typeName) {
			break;
		}
		else {
			iter++;
		}
	}
	return iter;
}

// This function is for testing whether or not there exists a room type with the given name.
// It will mostly be used to avoid having duplicate type names
bool Hotel::roomTypeExists(const std::string& typeName)
{
	if (findRoomType(typeName) != allRoomTypes.end())
	{
		return true;
	}
	return false;
}


// This is for testing only. Will most likely never be used in the actual program
// This function will print all the roomTypes that exist in the vector using
// the print function from the roomType Object.
void Hotel::printRoomTypes() const
{
	for (RoomType * temp : allRoomTypes) {
		temp->print();
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////DIVIDER FOR EASIER READING///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


// This function adds a room object pointer in the vector allRooms
// Todo: unlink all reservations before deleting room.
bool Hotel::addRoom(int roomNumber, const string& roomType)
{
	roomTypeIter iter = findRoomType(roomType);
	if (!roomNumberExists(roomNumber) && iter != allRoomTypes.end())
	{
		Room * newRoom = new Room(roomNumber, (*iter));
		allRooms.push_back(newRoom);
		db->addRoom(db, newRoom);
		return true;
	}
	return false;
}


// This function deletes a room object pointer in the vector allRooms
// Cannot have any CHECKED IN reservation blocking it
bool Hotel::deleteRoom(int roomNumber)
{
	roomIter iter = findRoom(roomNumber);
	if (iter != allRooms.end()) {
		
		/* returns false if any reservations are checked in */
		if (!(*iter)->noBlocksExist()) {
			for (int i = 0; i < (*iter)->getNumOfBlockedDays(); i++) {
				int resID = (*iter)->getFirstReservationID();
				Reservation * r = getReservationFromDB(resID);
				if (r->isCheckedIn()) {
					delete r;
					return false;
				}
				delete r;
			}
		}

		/* if no reservations are checked in then change reservations
		   pointing to this room so that they need to be reassigned */
		while (!(*iter)->noBlocksExist()) {
			int resID = (*iter)->getFirstReservationID();
			Reservation * r = getReservationFromDB(resID);
			removeRoomAssignment(*r);
			delete r;
			(*iter)->deleteFirstBlock();
		}

		db->deleteRoom(db, (*iter));	/* Todo: Brian look at this */
		allRooms.erase(iter);
		return true;
	}
	return false;
}


// This function will modify a Room object in the vector allRooms
// This function takes all the
bool Hotel::modifyRoom(int roomNumber,
	int newNumber,
	const std::string& newType)
{
	roomIter iter = findRoom(roomNumber);
	roomTypeIter rtIter = findRoomType(newType);
	Room *temp = new Room(newNumber, (*rtIter));		//?????

	if (iter != allRooms.end() && rtIter != allRoomTypes.end()) {
		db->updateRoom(db, (*iter), temp);

		(*iter)->setRoomNumber(newNumber);
		(*iter)->setRoomType(*rtIter);
		return true;
	}
	return false;
}


// This function adds a string to the features instance
bool Hotel::addRoomFeature(int roomNumber, const std::string& newFeature)
{
	roomIter iter = findRoom(roomNumber);
	if (iter != allRooms.end()) {
		(*iter)->addFeature(newFeature);
		Features *f = new Features();
		f->setFeatureName(newFeature);
		if (!featureExists(newFeature)) {
			db->addFeature(db, f);
			allFeatures.push_back(f);
		}
		delete f;
		
		
		Room *tempRo = new Room();
		tempRo = (*iter);
		db->updateRoom(db, *iter, tempRo);

		return true;
	}
	return false;
}


// This function deletes a string from the features instance
bool Hotel::deleteRoomFeature(int roomNumber, const std::string& featureToDelete)
{
	roomIter iter = findRoom(roomNumber);
	if (iter != allRooms.end()) {
		(*iter)->deleteFeature(featureToDelete);
		return true;
	}
	return false;
}


// This function changes the feature from one string to another string.
bool Hotel::changeRoomFeature(int roomNumber,
	const std::string& toChange,
	const std::string& whatToChangeTo)
{
	roomIter iter = findRoom(roomNumber);
	if (iter != allRooms.end()) {
		(*iter)->changeFeature(toChange, whatToChangeTo);
		

		Room *tempRo = new Room();
		tempRo = (*iter);
		db->updateRoom(db, *iter, tempRo);
		return true;
	}
	return false;
}


void Hotel::printRoomFeatures() {

	vector<Features *>::iterator iter;
	for (iter = allFeatures.begin(); iter != allFeatures.end(); iter++) {
		(*iter)->print();
		cout << endl;
	}
}

bool Hotel::featureExists(const string &featureToCheck) {
	
	vector<Features *>::iterator iter;
	for (iter = allFeatures.begin(); iter != allFeatures.end(); iter++) {
		if ((*iter)->getFeatureName() == featureToCheck) {
			return true;
		}
	}
	return false;
}


// This function finds a specific room from the vector allRooms
// It is used to navigate around the vector for deletion or modification
// Returns an iterator to the end if not found. When using this function,
// check to make sure its not at the end with (iter != theVector.end())
roomIter Hotel::findRoom(int roomNumber)
{
	roomIter iter = allRooms.begin();

	while (iter != allRooms.end())
	{
		if ((*iter)->getRoomNumber() == roomNumber)	{
			break;
		}
		else {
			iter++;
		}
	}
	return iter;
}


// This function is for testing whether or not there exists a room with a specific roomNumber.
// It will primarily be used to avoid having duplicate room numbers
bool Hotel::roomNumberExists(int roomNumber)
{
	if (findRoom(roomNumber) != allRooms.end())
	{
		return true;
	}
	return false;
}


// This is for testing only. Will mostly likely not be used in the actual program
// This function prints all of the rooms using the print() function available
void Hotel::printRooms() const
{
	for (Room * temp : allRooms)
	{
		temp->print();
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////DIVIDER FOR EASIER READING///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Reservation * Hotel::getReservationFromDB(int ID) {
	Reservation * r = new Reservation();
	db->getReservation(db, *r, ID);
	return r;
}

void Hotel::deleteReservationFromDB(int reservationID)
{
	db->deleteReservation(db, getReservationFromDB(reservationID));
}


void Hotel::setCurrentDate(Date& newCurrentDate)
{
	db->updateDate(db, currentDate, &newCurrentDate);
	currentDate = &newCurrentDate;
}

Date& Hotel::getCurrentDate() const
{
	return *currentDate;
}

int Hotel::calculateDateIndex(Date& tempDate) const
{
	int dateIndex = 0;
	
	if(currentDate->getYear() == tempDate.getYear() && currentDate->getMonth() == tempDate.getMonth())
	{
		dateIndex = tempDate.getDay() - currentDate->getDay();
	}
	else if(currentDate->getYear() == tempDate.getYear())
	{
		dateIndex += currentDate->monthDays() - currentDate->getDay();

		for(int i =  currentDate->getMonth() + 1; i <= tempDate.getMonth(); i++)
		{
			if(i == tempDate.getMonth())
			{
				dateIndex += tempDate.getDay();
			}
			else
				dateIndex += tempDate.monthDays(i);
		}
	}
	else
	{
		dateIndex += currentDate->monthDays() - currentDate->getDay();
		
		for(int i = currentDate->getMonth() + 1; i <= 12; i++)
		{
			dateIndex += currentDate->monthDays(i);
		}

		for(int i = 1; i <= tempDate.getMonth(); i++)
		{
			if(i == tempDate.getMonth())
			{
				dateIndex += tempDate.getDay();
			}
			else
				dateIndex += tempDate.monthDays(i);
		}
	}
	return dateIndex;
}

reservationIter Hotel::findReservation(int dateIndex, int reservationID)
{
	reservationIter iter = calendarArray[dateIndex].begin();

	while(iter != calendarArray[dateIndex].end())
	{
		if((*iter)->getID() == reservationID)
		{
			break;
		}
		else
			iter++;
	}

	return iter;
}

reservationIter Hotel::findReservation(int reservationID)
{
	Reservation * r = getReservationFromDB(reservationID);
	int dateIndex = calculateDateIndex(r->getRequiredInfo().getArrivalDate());
	reservationIter iter = calendarArray[dateIndex].begin();

	while (iter != calendarArray[dateIndex].end())
	{
		if ((*iter)->getID() == reservationID)
		{
			break;
		}
		else
			iter++;
	}
	delete r;
	return iter;
}

void Hotel::populateArray()
{
	Date endDate = getCurrentDate() + CAPACITY;
	vector<Reservation*> tempVRes;
	db->populateReservations(db, tempVRes, endDate);
	
	vector<Reservation*>::iterator resIter = tempVRes.begin();
	for (int i = 0; i < CAPACITY; i++)
	{
		list<Reservation *> tempList;
		for (resIter = tempVRes.begin(); resIter != tempVRes.end(); resIter++)
		{
			if ((calculateDateIndex((*resIter)->getRequiredInfo().getArrivalDate()) == i) &&
				((*resIter)->isReserved() || (*resIter)->isCheckedIn()))
			{
				tempList.push_back(*resIter);
			}		
		}
		calendarArray[i] = tempList;
	}
}

void Hotel::addReservation(Reservation& newReservation)
{
	RequiredInfo tempReq = newReservation.getRequiredInfo();
	Date tempDate = tempReq.getArrivalDate();

	int dateIndex = calculateDateIndex(tempDate);
	if (dateIndex >= 0 && dateIndex < 112) {
		calendarArray[dateIndex].push_back(&newReservation);
	}
	db->addReservation(db, &newReservation);
}

void Hotel::modifyReservation(Reservation& modifiedReservation, Date& reservationDate, int reservationID)
{
	int dateIndex = calculateDateIndex(reservationDate);
	reservationIter iter = findReservation(dateIndex, reservationID);
	(*iter)->setReservation(modifiedReservation);	
	db->updateReservation(db, (*findReservation(calculateDateIndex(reservationDate), reservationID)), &modifiedReservation);
}

void Hotel::modifyReservation(Reservation& modifiedReservation, int reservationID)
{
	Reservation * r = getReservationFromDB(reservationID);
	Date tempDate = r->getRequiredInfo().getArrivalDate();
	int dateIndex = calculateDateIndex(tempDate);
	reservationIter iter = findReservation(dateIndex, reservationID);
	(*iter)->setReservation(modifiedReservation);
	db->updateReservation(db, r, &modifiedReservation);
	delete r;
}

void Hotel::deleteReservation(Date& reservationDate, int reservationID)
{
	int dateIndex = calculateDateIndex(reservationDate);
	reservationIter iter = findReservation(dateIndex, reservationID);
	if (dateIndex >= 0 && dateIndex < 112) {
		calendarArray[dateIndex].erase(iter);
	}
	//db->deleteReservation(db, (*findReservation(calculateDateIndex(reservationDate), reservationID)));
}

void Hotel::deleteReservation(int reservationID)
{
	Reservation * tempRes = getReservationFromDB(reservationID);
	Date temp = tempRes->getRequiredInfo().getArrivalDate();

	int dateIndex = calculateDateIndex(temp);
	reservationIter iter = findReservation(dateIndex, reservationID);
	if (dateIndex >= 0 && dateIndex < 112) {
		calendarArray[dateIndex].erase(iter);
	}
	delete tempRes;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////DIVIDER FOR EASIER READING///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


// This will connect the reservation to the room and block off that room for that reservation so
// that no other reservation may choose that room.
void Hotel::assignRoomNumber(Reservation& theReservation, int roomNumber)
{
	roomIter iter = findRoom(roomNumber);
	if (iter == allRooms.end()) {
		cout << "Room number not available." << endl;
	}
	else {
		Date temp = theReservation.getRequiredInfo().getArrivalDate();
		Date end = theReservation.getRequiredInfo().getDepartureDate();
		bool blocked = false;

		// check if room is blocked or not for any of the dates
		while (temp < end) {
			string tempDateStr = temp.dateToString();
			if (((*iter)->isBlocked(tempDateStr)) &&
				((*iter)->getReservationID(tempDateStr) != theReservation.getID())) {
				blocked = true;
				break;
			}
			else {
				temp++;
			}
		}

		// if not blocked, apply the reservation block
		if (!blocked) {
			// set room number in reservation
			theReservation.setRoomNumber(roomNumber);
			
			// block off all the days in room
			temp = theReservation.getRequiredInfo().getArrivalDate();
			while (temp < end) {
				string tempDateStr = temp.dateToString();
				(*iter)->addReservationBlock(tempDateStr, theReservation.getID());
				db->addBlock(db, &theReservation, roomNumber, &Date(tempDateStr));
				temp++;
			}

			// update reservation to database
			Reservation tempRe = Reservation();
			tempRe = theReservation;
			db->updateReservation(db, &theReservation, &tempRe);

			// update room to database
			// uncomment when DB has been re-coded
			Room *tempRo = new Room();
			tempRo = (*iter);
			db->updateRoom(db, *iter, tempRo);
		}
	}
}

// This will unassign a room number from a reservation and make the blocked room
// available to other reservations
void Hotel::removeRoomAssignment(Reservation& theReservation)
{
	// remove blocks from the room object
	roomIter iter = findRoom(theReservation.getRoomNumber());
	if (iter != allRooms.end()) {
		Date temp = theReservation.getRequiredInfo().getArrivalDate();
		Date end = theReservation.getRequiredInfo().getDepartureDate();
		
		while (temp < end) {
			string tempDateStr = temp.dateToString();
			(*iter)->deleteReservationBlock(tempDateStr);
			db->deleteBlock(db, &theReservation, (*iter)->getRoomNumber(), &Date(tempDateStr));
			temp++;
		}
	}

	// remove room number from reservation
	theReservation.setRoomNumber(-1);

	// update reservation to database
	Reservation tempRe = Reservation();
	tempRe = theReservation;
	db->updateReservation(db, &theReservation, &tempRe);

	// update room to database
	// uncomment when DB has been re-coded
	Room *tempRo = new Room();
	tempRo = (*iter);
	db->updateRoom(db, *iter, tempRo);
}


// This will insure the date is the current date and then
// change the reservation status to "CheckedIn". It's bool
// because it has a chance of failing.
// arrival date much match current date.
// room number must be assigned
bool Hotel::checkInRes(Reservation& theReservation)
{
	/* if the room is already checked into a room, return false */
	if (theReservation.isCheckedIn()) {
		return false;
	}

	Date arrival = theReservation.getRequiredInfo().getArrivalDate();
	int roomNum = theReservation.getRoomNumber();

	// Case for successful Check In
	if (arrival == *currentDate &&  roomNum >= 0) {
		theReservation.checkIn();
		assignRoomNumber(theReservation, roomNum);
		return true;
	}

	// List of possible errors.
	if (arrival != *currentDate) {
		cout << "Arrival date must be today." << endl;
	}
	if (roomNum < 0) {
		cout << "Room number must be assigned." << endl;
	}

	return false;
}


// This will unblock the room and then change the
// reservation status to "CheckedOut". It's void becuase
// it cannot fail.
void Hotel::checkOutRes(Reservation& theReservation)
{
	roomIter iter = findRoom(theReservation.getRoomNumber());
	theReservation.checkOut();
	removeRoomAssignment(theReservation);
	deleteReservation(theReservation.getID()); /* Deletes from the array of reservations */
}


// This will change the reservation object's status to "Cancelled",
// (if necessary) unassign room number, and unblock room.
// It's void because it cannot fail.
void Hotel::cancelRes(Reservation& theReservation)
{
	theReservation.cancel();

	if (theReservation.getRoomNumber() >= 0) {
		removeRoomAssignment(theReservation);
	}
	else {
		Reservation tempRe = Reservation();
		tempRe = theReservation;
		db->updateReservation(db, &theReservation, &tempRe);
	}
}


// This will change the reservation status to "No Show"
// It's void (as opposed to bool) because users will not
// use this function. This will only be used during
// Night Audit
//
// (if necessary) will unassign room number, and unblock room
// The date must match current date
void Hotel::noShowRes(Reservation& theReservation)
{
	Date arrival = theReservation.getRequiredInfo().getArrivalDate();

	if (arrival == *currentDate) {
		theReservation.noShow();

		if (theReservation.getRoomNumber() >= 0) {
			removeRoomAssignment(theReservation);
		}
		else {
			Reservation tempRe = Reservation();
			tempRe = theReservation;
			db->updateReservation(db, &theReservation, &tempRe);
		}
	}
}

// This function is for putting reservations from other states
// back to "Reserved." It's a bool function because it's possible
// for it to fail to put the reservation back.
//
// Will check to make sure the date hasn't passed yet
// if the date is current or in the future, it will
// change the reservation status to "Reserved" and
// unassign the room number.
// It will not affect any room objects.
bool Hotel::reserve(Reservation& theReservation)
{
	Date arrival = theReservation.getRequiredInfo().getArrivalDate();
	if (arrival >= *currentDate) {
		theReservation.reserve();
		theReservation.setRoomNumber(-1);

		Reservation tempRe = Reservation();
		tempRe = theReservation;
		db->updateReservation(db, &theReservation, &tempRe);
		return true;
	}

	return false;
}


// This is for testing purposes only.
void Hotel::printReservationArray() const
{
	int total = 0;
	cout << getCurrentDate().dateToString() << endl;
	for (int i = 0; i < CAPACITY; i++)	{
		reservationIter iter;

		for (iter = calendarArray[i].begin(); iter != calendarArray[i].end(); iter++) {
			(*iter)->print();
			cout << endl;
			total++;
		}
	}
	cout << "Total Reservations: " << total << endl;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////DIVIDER FOR EASIER READING///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


// This function is for adding roomTypes to the vector of roomType pointers
// Objects are dynamically created and a pointer is inserted into the vector
bool Hotel::addAccount(const string& newUsername, const string& newPassword, const string& newAccountType,
	const string& newName, const string& newAge, const string& newGender, const string& newPosition,
	const string& newPhoneNumber, const string& newEmergencyContact, const string& newEmailAddress,
	const string& newAddress, const string& newCity, const string& newState, const string& newZipcode,
	const string& newCountry, const string& newAdditionalDetails)
{
	if (!accountExists(newUsername))
	{
		Accounts *temp = new Accounts(newUsername, newPassword, newAccountType, 
			newName, newAge, newGender, newPosition, newPhoneNumber, newEmergencyContact, newEmailAddress,
			newAddress, newCity, newState, newZipcode, newCountry, newAdditionalDetails);
		allAccounts.push_back(temp);
		db->addAccount(db, temp);
		return true;
	}
	return false;
}


// This function will delete a roomType object and return true if successful
bool Hotel::deleteAccount(const string& newUsername)
{
	accountsIter iterAccounts = findAccount(newUsername);
	if (iterAccounts != allAccounts.end()) {
		db->deleteAccount(db, *iterAccounts);
		allAccounts.erase(iterAccounts);
		return true;
	}
	return false;
}


// This function will modify a roomType object in the vector allRoomTypes
// It finds the room to modify then assigns all the new information within it
bool Hotel::modifyAccount(const string& newUsername, const string& newPassword, const string& newAccountType,
	const string& newName, const string& newAge, const string& newGender, const string& newPosition,
	const string& newPhoneNumber, const string& newEmergencyContact, const string& newEmailAddress,
	const string& newAddress, const string& newCity, const string& newState, const string& newZipcode,
	const string& newCountry, const string& newAdditionalDetails)
{
	Accounts *temp = new Accounts(newUsername, newPassword, newAccountType, newName, newAge,
		newGender, newPosition, newPhoneNumber, newEmergencyContact, newEmailAddress,
		newAddress, newCity, newState, newZipcode, newCountry, newAdditionalDetails);
	accountsIter iterAccounts = findAccount(newUsername);
	if (iterAccounts != allAccounts.end())
	{
		(*iterAccounts)->setUsername(newUsername);
		(*iterAccounts)->setPassword(newPassword);
		(*iterAccounts)->setAccountType(newAccountType);
		(*iterAccounts)->setName(newName);
		(*iterAccounts)->setAge(newAge);
		(*iterAccounts)->setGender(newGender);
		(*iterAccounts)->setPosition(newPosition);
		(*iterAccounts)->setPhoneNumber(newPhoneNumber);
		(*iterAccounts)->setEmergencyContact(newEmergencyContact);
		(*iterAccounts)->setEmailAddress(newEmailAddress);
		(*iterAccounts)->setAddress(newAddress);
		(*iterAccounts)->setCity(newCity);
		(*iterAccounts)->setZipcode(newZipcode);
		(*iterAccounts)->setState(newState);
		(*iterAccounts)->setCountry(newCountry);
		(*iterAccounts)->setAdditionalDetails(newAdditionalDetails);
		db->updateAccount(db, *iterAccounts, temp);
		return true;
	}
	return false;
}

accountsIter Hotel::findAccount(const string& newUsername)
{
	accountsIter iter = allAccounts.begin();

	while (iter != allAccounts.end())
	{
		if ((*iter)->getUsername() == newUsername){
			break;
		}
		else {
			iter++;
		}
	}
	return iter;
}

bool Hotel::accountExists(const string& newUsername)
{
	if (findAccount(newUsername) != allAccounts.end())
	{
		return true;
	}
	return false;
}

void Hotel::printAccount() const
{
	for (Accounts * temp : allAccounts) {
		temp->print();
	}
}

Hotel::~Hotel()
{
	db->close();
}