/*
* Room.h
*
*  Created on: Mar 22, 2014
*      Author: Salman
*/


#ifndef ROOM_H_
#define ROOM_H_

#include "RoomType.h"
#include "Features.h"
#include <vector>
#include <iostream>
#include <map>

using namespace std;

typedef vector<Features>::iterator featuresIter;
typedef map<string, int>::iterator mapIter;

class Room
{
public:
	// Constructors
	Room();
	Room(int newRoomNumber, RoomType* newType);

	// Getters
	//BRIAN
	int getID() const;
	int getRoomNumber() const;

	RoomType* getRoomType() const;

	// Setters
	//BRIAN
	void setID(int newID);
	void setRoomNumber(int newNum);
	void setRoomType(RoomType* newType);




	/// FEATURES FUNCTIONS ///
	//////////////////////////
	void addFeature(const string& newFeature);
	void deleteFeature(const string& featureToDelete);
	void changeFeature(const string& featureToChange, const string& whatToChangeTo);
	featuresIter findFeatures(const string& featureToFind);
	//BRIAN
	string featuresToString();
	void stringToFeatures(string newFeatures);

	// This function is for testing only.
	// It will not be used in the actual program.
	void print();

	/* start: listOfBlockedDays */

	// returns true if the room is blocked for that date
	bool isBlocked(string date);

	void blockRoom(string date);
	void unblockRoom(string date);

	void addReservationBlock(string date, int reservationID);
	void deleteReservationBlock(string date);
	void deleteReservationBlock(int reservationID);

	// this is used in the Hotel object for deleting rooms.
	int getFirstReservationID();

	// this is used in the Hotel object for deleting rooms.
	void deleteFirstBlock();

	// this is used in the Hotel object for deleting rooms.
	bool noBlocksExist();

	int getNumOfBlockedDays();

	int getReservationID(string date);

	void printListOfBlockedDays();

	/* end: listOfBlockedDays */

private:
	int ID;
	int roomNumber;
	RoomType *type;
	int numOfFeatures;
	//BRIAN
	vector<Features> featuresVector;

	// SALMAN
	map <string, int> listOfBlockedDays;
};


#endif /* ROOM_H_ */