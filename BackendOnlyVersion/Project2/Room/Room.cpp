/*
* Room.cpp
*
*  Created on: Mar 22, 2014
*      Author: Salman
*/
#include "Room.h"

Room::Room()
{
	type = nullptr;
	roomNumber = 0;
	numOfFeatures = 0;
}

Room::Room(int newRoomNumber, RoomType * newType)
{
	roomNumber = newRoomNumber;
	type = newType;
	numOfFeatures = 0;
}

int Room::getID() const
{
	return ID;
}

int Room::getRoomNumber() const
{
	return roomNumber;
}

RoomType* Room::getRoomType() const
{
	return type;
}

void Room::setID(int newID)
{
	ID = newID;
}

void Room::setRoomNumber(int newNum)
{
	roomNumber = newNum;
}

void Room::setRoomType(RoomType* newType)
{
	type = newType;
}

/// FEATURES FUNCTIONS ///
//////////////////////////
/**
* These functions are already written in Features class:
* 		addFeatures();
* 		deleteFeatures();
* 		changeFeatures();
* They are re-written here for easier modification
* in the future.
*/

void Room::addFeature(const string& newFeature)
{
	Features f = Features();
	f.setFeatureName(newFeature);
	featuresVector.push_back(f);
	numOfFeatures++;
}

void Room::deleteFeature(const string& featureToDelete)
{
	featuresIter iter = findFeatures(featureToDelete);
	if (iter != featuresVector.end())
	{
		featuresVector.erase(iter);
		numOfFeatures--;
	}
}

void Room::changeFeature(const string& featureToChange, const string& whatToChangeTo)
{
	featuresIter iter = findFeatures(featureToChange);

	if (iter != featuresVector.end())
		iter->setFeatureName(whatToChangeTo);
}

featuresIter Room::findFeatures(const string& featureToFind)
{
	featuresIter iter = featuresVector.begin();

	while (iter != featuresVector.end()) {
		if ((iter->getFeatureName()) == featureToFind) {
			break;
		}
		iter++;
	}
	return iter;
}

//BRIAN
string Room::featuresToString()
{
	featuresIter iter = featuresVector.begin();
	string result = "";
	if (numOfFeatures > 0)
	{
		while (iter != featuresVector.end())
		{
			result.append(iter->getFeatureName());
			result.append("/");
			iter++;
		}
		result.pop_back();
	}

	return result;
}

//splits up string of features and 
//adds individual features to vector
void Room::stringToFeatures(string newFeatures)
{
	if (!(newFeatures == ""))
	{
		newFeatures.append("/");
		string delimiter = "/";
		size_t pos = 0;
		while ((pos = newFeatures.find(delimiter, 1)) != newFeatures.size() && (!newFeatures.empty()))
		{
			string token = newFeatures.substr(0, pos);
			Features f = Features();
			f.setFeatureName(token);
			featuresVector.push_back(f);
			numOfFeatures++;
			newFeatures.erase(0, pos + 1);
		}
	}
}

void Room::print()
{
	cout << "Room Number: " << roomNumber;
	//if (blocked) {
	//	cout << " blocked by " << resID;
	//}
	cout << endl;

	cout << "Room Type: " << type->getTypeName() << endl;


	cout << "Room Features: ";
	for (int i = 0; i < numOfFeatures; i++)
	{
		featuresVector[i].print();
		cout << endl;
	}
	cout << endl;
	cout << "Blocked days: " << endl;
	printListOfBlockedDays();
	cout << endl;
}

/* START FUNCTIONS OF LISTOFBLOCKEDDAYS */

// returns true if the room is blocked for that date
bool Room::isBlocked(string date) {
	mapIter iter;
	for (iter = listOfBlockedDays.begin(); iter != listOfBlockedDays.end(); iter++) {
		if (iter->first == date) {
			return true;
		}
	}
	return false;
}

void blockRoom(string date) {

}
void unblockRoom(string date) {

}

void Room::addReservationBlock(string date, int reservationID) {
	listOfBlockedDays.insert(make_pair(date, reservationID));
}
void Room::deleteReservationBlock(string date) {
	listOfBlockedDays.erase(date);

	//mapIter iter;
	//for (iter = listOfBlockedDays.begin(); iter != listOfBlockedDays.end(); iter++) {
	//	if (iter->first == date) {
	//		listOfBlockedDays.erase(iter);
	//	}
	//}
}

void Room::deleteReservationBlock(int reservationID) {
	mapIter iter;
	for (iter = listOfBlockedDays.begin(); iter != listOfBlockedDays.end(); iter++) {
		if (iter->second == reservationID) {
			listOfBlockedDays.erase(iter);
		}
	}
}

// this is used in the Hotel object for deleting rooms.
int Room::getFirstReservationID() {
	/* returns the reservation ID in the first object */
	return listOfBlockedDays.begin()->second;
}

// this is used in the Hotel object for deleting rooms.
void Room::deleteFirstBlock() {
	if (!listOfBlockedDays.empty()) {
		listOfBlockedDays.erase(listOfBlockedDays.begin());
	}
}

// this is used in the Hotel object for deleting rooms.
bool Room::noBlocksExist() {
	return listOfBlockedDays.empty();
}
int Room::getNumOfBlockedDays() {
	return listOfBlockedDays.size();
}

int Room::getReservationID(string date) {
	mapIter iter = listOfBlockedDays.find(date);
	if (iter != listOfBlockedDays.end()) {
		return iter->second;
	}
	return -1;
}

void Room::printListOfBlockedDays() {
	mapIter iter;
	for (iter = listOfBlockedDays.begin(); iter != listOfBlockedDays.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
}

/* END FUNCTIONS FOR LISTOFBLOCKEDDAYS */
