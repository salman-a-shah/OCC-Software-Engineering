#pragma warning(disable: 4996)
#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include "SQLite\sqlite3.h"
#include "Accounts\Accounts.h"
#include "Reservation\Reservation.h"
#include "Room\RoomType.h"
#include "Room\Room.h"
#include "Room\Features.h"
#include "Reservation\Date.h"
#include "Hotel.h"

using namespace std;

class DB
{
public:
	DB(char* filename);
	~DB();

	bool open(char* filename);
	vector<vector<string> > query(char* query);
	void close();
	void startup(DB *db, vector<Accounts*>& vAccounts,
		vector<Room*>& vRooms, vector<RoomType*>& vRoomType,
		vector<Features*>& vFeatures, vector<Reservation*>& vReservations);

	void createDateTable(DB *db);
	void addDate(DB *db, Date* d);
	void updateDate(DB *db, Date* d, Date* temp);
	void printDate(DB *db, Date* d);
	void getDate(DB *db, Date* d);

	void createAccountsTable(DB *db);
	void addAccount(DB *db, Accounts *a);
	void updateAccount(DB *db, Accounts *a, Accounts* temp);
	void deleteAccount(DB *db, Accounts *a);
	void printAccount(DB *db, Accounts *a);
	void getAccount(DB *db, Accounts* newAccounts, int ID);

	void createReservationsTable(DB *db);
	void addReservation(DB *db, Reservation *r);
	void updateReservation(DB *db, Reservation *r, Reservation* temp);
	void deleteReservation(DB *db, Reservation *r);
	void printReservation(DB *db, Reservation *r);
	void getReservation(DB *db, Reservation& newReservation, int ID);
	void populateReservations(DB *db, vector<Reservation*>& vReservations, Date& endDate);

	void createRoomTypeTable(DB *db);
	void addRoomType(DB *db, RoomType *rt);
	void updateRoomType(DB *db, RoomType *rt, RoomType* temp);
	void deleteRoomType(DB *db, RoomType *rt);
	void printRoomType(DB *db, RoomType *rt);
	void getRoomType(DB *db, RoomType* newRoomType, int ID);
	void getRoomType(DB *db, RoomType* newRoomType, const string& typeName);

	void createRoomTable(DB *db);
	void addRoom(DB *db, Room *ro);
	void updateRoom(DB *db, Room *ro, Room* temp);
	void deleteRoom(DB *db, Room *ro);
	void printRoom(DB *db, Room *ro);
	void getRoom(DB *db, Room* newRoom, int ID);

	void createFeaturesTable(DB *db);
	void addFeature(DB *db, Features *f);
	void updateFeature(DB *db, Features *f, Features* temp);
	void deleteFeature(DB *db, Features *f);
	void printFeature(DB *db, Features *f);
	void getFeature(DB *db, Features* newFeature, int ID);

private:
	sqlite3 *database;
};

#endif


