#include "DB.h"
#include <iostream>

DB::DB(char* filename)
{
	database = NULL;
	open(filename);
}

DB::~DB()
{
}

bool DB::open(char* filename)
{
	if (sqlite3_open(filename, &database) == SQLITE_OK)
		return true;

	return false;
}

vector<vector<string> > DB::query(char* query)
{
	sqlite3_stmt *statement;
	vector<vector<string> > results;
	
	if (sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		while (true)
		{
			result = sqlite3_step(statement);

			if (result == SQLITE_ROW)
			{
				vector<string> values;
				for (int col = 0; col < cols; col++)
				{
					values.push_back((char*)sqlite3_column_text(statement, col));
				}
				results.push_back(values);
			}
			else
			{
				break;
			}
		}

		sqlite3_finalize(statement);
	}

	string error = sqlite3_errmsg(database);
	if (error != "not an error") cout << query << " " << error << endl;

	return results;
}

void DB::close()
{
	sqlite3_close(database);
}

void DB::startup(DB *db, vector<Accounts*>& vAccounts,
	vector<Room*>& vRooms, vector<RoomType*>& vRoomType,
	vector<Features*>& vFeatures, vector<Reservation*>& vReservations)
{
	//if (!db->open("db"))
	//{
	//	createAccountsTable(db);
	//	createReservationsTable(db);
	//	createRoomTypeTable(db);
	//	createRoomTable(db);
	//	createFeaturesTable(db);
	//}

	//POPULATING ACCOUNTS VECTOR
	string sqlstmt = "SELECT * FROM Accounts;";
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator iterA = result.begin(); iterA < result.end(); ++iterA)
	{
		vector<string> row = *iterA;
		Accounts *temp = new Accounts();
		temp->setID(stoi(row.at(0)));
		temp->setUsername(row.at(1));
		temp->setPassword(row.at(2));
		temp->setAccountType(row.at(3));
		temp->setName(row.at(4));
		temp->setAge(row.at(5));
		temp->setGender(row.at(6));
		temp->setPosition(row.at(7));
		temp->setPhoneNumber(row.at(8));
		temp->setEmergencyContact(row.at(9));
		temp->setEmailAddress(row.at(10));
		temp->setAddress(row.at(11));
		temp->setCity(row.at(12));
		temp->setState(row.at(13));
		temp->setZipcode(row.at(14));
		temp->setCountry(row.at(15));
		temp->setAdditionalDetails(row.at(16));
		vAccounts.push_back(temp);
	}

	//POPULATING ROOMTYPE VECTOR
	sqlstmt = "SELECT * FROM RoomType;";
	c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator iterRt = result.begin(); iterRt < result.end(); ++iterRt)
	{
		vector<string> row = *iterRt;
		RoomType *temp = new RoomType();
		temp->setID(stoi(row.at(0)));
		temp->setTypeName(row.at(1));
		temp->setTypeCode(row.at(2));
		temp->setMaxAdults(stoi(row.at(3)));
		temp->setMaxChildren(stoi(row.at(4)));
		temp->setNumberOfBeds(stoi(row.at(5)));
		temp->setDescription(row.at(6));
		vRoomType.push_back(temp);
	}

	//POPULATING ROOM VECTOR
	sqlstmt = "SELECT * FROM Room;";

	c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator iterRo = result.begin(); iterRo < result.end(); ++iterRo)
	{
		vector<string> row = *iterRo;
		Room *temp = new Room();
		RoomType *rt = new RoomType();

		temp->setID(stoi(row.at(0)));
		temp->setRoomNumber(stoi(row.at(1)));
		db->getRoomType(db, rt, row.at(2));
		temp->setRoomType(rt);
		temp->stringToFeatures(row.at(3));

		sqlstmt = "SELECT * FROM Blocks WHERE RoomNumber='" + row.at(1) + "';";
		c = new char[sqlstmt.length() + 1];
		strcpy(c, sqlstmt.c_str());
		vector<vector<string> > result2 = db->query(c);
		delete[] c;

		for (vector<vector<string>>::iterator iterRo2 = result2.begin(); iterRo2 < result2.end(); ++iterRo2)
		{
			vector<string> row2 = *iterRo2;
			temp->addReservationBlock(row2.at(3), stoi(row2.at(1)));
		}

		vRooms.push_back(temp);
	}

	//POPULATING FEATURES VECTOR
	sqlstmt = "SELECT * FROM Features;";
	c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator iterF = result.begin(); iterF < result.end(); ++iterF)
	{
		vector<string> row = *iterF;
		Features *temp = new Features();
		temp->setID(stoi(row.at(0)));
		temp->setFeatureName(row.at(1));
		vFeatures.push_back(temp);
	}

	//POPULATING RESERVATIONS VECTOR
	sqlstmt = "SELECT * FROM Reservation;";
	c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator iterRe = result.begin(); iterRe < result.end(); ++iterRe)
	{
		vector<string> row = *iterRe;
		Reservation *temp = new Reservation();

		temp->setID(stoi(row.at(0)));
		temp->getGeneralInfo().setName(row.at(1));
		temp->getGeneralInfo().setAddress(row.at(2));
		temp->getGeneralInfo().setCity(row.at(3));
		temp->getGeneralInfo().setState(row.at(4));
		temp->getGeneralInfo().setZipCode(row.at(5));
		temp->getGeneralInfo().setCountry(row.at(6));
		temp->getGeneralInfo().setEmail(row.at(7));
		temp->getGeneralInfo().setPhoneNumber(row.at(8));
		temp->getRequiredInfo().setArrivalDate(Date(row.at(9)));
		temp->getRequiredInfo().setDepartureDate(Date(row.at(10)));
		temp->getRequiredInfo().setRoomType(row.at(11));
 		temp->getCreditInfo().setCreditCardNumber(row.at(12));
		temp->getCreditInfo().setExpirationDate(row.at(13));
		temp->getCreditInfo().setVerificationCode(row.at(14));
		temp->getCreditInfo().setCreditCardType(row.at(15));
		temp->getGeneralInfo().setNumOfAdults(row.at(16));
		temp->getGeneralInfo().setNumOfChildren(row.at(17));
		temp->getExtraInfo().setUserText(row.at(18));
		temp->setStatus(row.at(19));
		temp->setRoomNumber(stoi(row.at(20)));
		vReservations.push_back(temp);
	}
}

/////////\\\\\\\\
/////DATE\\\\
/////////\\\\\\\\

void DB::createDateTable(DB *db)
{
	char *stmt = "CREATE TABLE Date (" \
		"ID					INTEGER PRIMARY KEY, " \
		"CurrentDate		TEXT		NULL	UNIQUE);";
	db->query(stmt);
}

void DB::addDate(DB *db, Date* d)
{
	string sqlstmt = "INSERT INTO Date(CurrentDate) VALUES ('" + d->dateToString() + "');";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

void DB::updateDate(DB *db, Date *d, Date *temp)
{
	string sqlstmt = "UPDATE Date SET CurrentDate='" + temp->dateToString() + "' WHERE ID='1';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

void DB::getDate(DB *db, Date *d)
{
	string sqlstmt = "SELECT * FROM Date;";

	//code that converts string to char* to use in query()
	 char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;
		Date temp = Date(row.at(1));
		d->setDate(temp.getMonth(), temp.getDay(), temp.getYear());
	}
}

/////////\\\\\\\\
/////ACCOUNTS\\\\
/////////\\\\\\\\

//create accounts table
void DB::createAccountsTable(DB *db)
{
	char *stmt = "CREATE TABLE Accounts (" \
		"ID					INTEGER PRIMARY KEY, " \
		"Username			TEXT		NULL	UNIQUE," \
		"Password			TEXT		NULL," \
		"AccountType		TEXT		NULL," \
		"Name				TEXT		NULL," \
		"Age				TEXT		NULL," \
		"Gender				TEXT		NULL," \
		"Position			TEXT		NULL," \
		"PhoneNumber 		TEXT		NULL," \
		"EmergencyContact 	TEXT		NULL," \
		"EmailAddress 		TEXT		NULL," \
		"Address			TEXT		NULL," \
		"City				TEXT		NULL," \
		"State				TEXT		NULL," \
		"Zipcode			TEXT		NULL," \
		"Country			TEXT		NULL," \
		"AdditionalDetails  TEXT		NULL);";
	db->query(stmt);
}

//add account
void DB::addAccount(DB *db, Accounts *a)
{
	string sqlstmt = "INSERT INTO Accounts(Username, Password, AccountType, Name, Age, Gender, Position, " \
		"PhoneNumber, EmergencyContact, EmailAddress, Address, City, State, Zipcode, Country, AdditionalDetails) VALUES ('" \
		+ a->getUsername() + "', '" + a->getPassword() + "', '" + a->getAccountType() + "', '"
		+ a->getName() + "', '" + a->getAge() + "', '" + a->getGender() + "', '" + a->getPosition() + "', '"
		+ a->getPhoneNumber() + "', '" + a->getEmergencyContact() + "', '" + a->getEmailAddress() + "', '"
		+ a->getAddress() + "', '" + a->getCity() + "', '" + a->getState() + "', '" + a->getZipcode() + "', '"
		+ a->getCountry() + "', '" + a->getAdditionalDetails() + "');";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//update account. When modify button is clicked, a temp account is created with all current settings.  
//After modifications made, if current values are different, then setters will change the variables of the temp->
//Then, this temp account will update all values of old account.
void DB::updateAccount(DB *db, Accounts *a, Accounts* temp)
{
	int ID = a->getID();
	string sqlstmt = "UPDATE Accounts SET Username='" + temp->getUsername() + "', Password='" +
		temp->getPassword() + "', AccountType='" + temp->getAccountType() + "', Name='" +
		temp->getName() + "', Age='" + temp->getAge() + "', Gender='" + temp->getGender() +
		"', Position='" + temp->getPosition() + "', PhoneNumber='" + temp->getPhoneNumber() +
		"', EmergencyContact='" + temp->getEmergencyContact() + "', EmailAddress='" +
		temp->getEmailAddress() + "', Address='" + temp->getAddress() + "', City='" +
		temp->getCity() + "', State='" + temp->getState() + "', Zipcode='" + temp->getZipcode() +
		"', Country='" + temp->getCountry() + "', AdditionalDetails='" + temp->getAdditionalDetails() + "' WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//delete account
void DB::deleteAccount(DB *db, Accounts *a)
{
	int ID = a->getID();
	string sqlstmt = "DELETE FROM Accounts WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//print account
void DB::printAccount(DB *db, Accounts *a)
{
	string sqlstmt = "SELECT * FROM Accounts WHERE ID='" + to_string(a->getID()) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;
		cout << "ID: " << row.at(0) << endl
			<< "Username: " << row.at(1) << endl
			<< "Password: " << row.at(2) << endl
			<< "Account Type: " << row.at(3) << endl
			<< "Name: " << row.at(4) << endl
			<< "Age: " << row.at(5) << endl
			<< "Gender: " << row.at(6) << endl
			<< "Position: " << row.at(7) << endl
			<< "Phone Number: " << row.at(8) << endl
			<< "Emergency Contact: " << row.at(9) << endl
			<< "Email Address: " << row.at(10) << endl
			<< "Address: " << row.at(11) << endl
			<< "City: " << row.at(12) << endl
			<< "State: " << row.at(13) << endl
			<< "Zip Code: " << row.at(14) << endl
			<< "Country: " << row.at(15) << endl
			<< "Additional Details: " << row.at(16) << endl;
	}
}

//returns a Account object with all attributes
void DB::getAccount(DB *db, Accounts* newAccount, int ID)
{
	string sqlstmt = "SELECT * FROM Accounts WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;
		newAccount->setID(stoi(row.at(0)));
		newAccount->setUsername(row.at(1));
		newAccount->setPassword(row.at(2));
		newAccount->setAccountType(row.at(3));
		newAccount->setName(row.at(4));
		newAccount->setAge(row.at(5));
		newAccount->setGender(row.at(6));
		newAccount->setPosition(row.at(7));
		newAccount->setPhoneNumber(row.at(8));
		newAccount->setEmergencyContact(row.at(9));
		newAccount->setEmailAddress(row.at(10));
		newAccount->setAddress(row.at(11));
		newAccount->setCity(row.at(12));
		newAccount->setState(row.at(13));
		newAccount->setZipcode(row.at(14));
		newAccount->setCountry(row.at(15));
		newAccount->setAdditionalDetails(row.at(16));
	}
}

///////////\\\\\\\\\\\
/////RESERVATIONS\\\\\
///////////\\\\\\\\\\\

//create reservations table
void DB::createReservationsTable(DB *db)
{
	char *stmt = "CREATE TABLE Reservation (" \
		"ID					INTEGER PRIMARY KEY," \
		"Name				TEXT		NULL," \
		"Address			TEXT		NULL," \
		"City				TEXT		NULL," \
		"State				TEXT		NULL," \
		"ZipCode			TEXT		NULL," \
		"Country			TEXT		NULL," \
		"Email				TEXT		NULL," \
		"PhoneNumber 		TEXT		NULL," \
		"ArrivalDate 		TEXT		NULL," \
		"DepartureDate 		TEXT		NULL," \
		"RoomType			TEXT		NULL," \
		"CreditCardNumber	TEXT		NULL	UNIQUE," \
		"ExpirationDate		TEXT		NULL," \
		"VerificationCode	TEXT		NULL," \
		"CreditCardType		TEXT		NULL," \
		"NumOfAdults		TEXT		NULL," \
		"NumOfChildren		TEXT		NULL," \
		"ExtraFeatures		TEXT		NULL," \
		"Status				TEXT		NULL," \
		"RoomNumber			TEXT		NULL);";
	db->query(stmt);
}

//add reservation
void DB::addReservation(DB *db, Reservation *r)
{
	string sqlstmt = "INSERT INTO Reservation(Name, Address, City, State, ZipCode, Country, Email, " \
		"PhoneNumber, ArrivalDate, DepartureDate, RoomType, CreditCardNumber, ExpirationDate, VerificationCode, CreditCardType, NumOfAdults, NumOfChildren, ExtraFeatures, Status, RoomNumber) VALUES ('" \
		+ r->getGeneralInfo().getName() + "', '" + r->getGeneralInfo().getAddress() + "', '" + r->getGeneralInfo().getCity() + "', '"
		+ r->getGeneralInfo().getState() + "', '" + r->getGeneralInfo().getZipCode() + "', '" + r->getGeneralInfo().getCountry() + "', '" + r->getGeneralInfo().getEmail() + "', '"
		+ r->getGeneralInfo().getPhoneNumber() + "', '" + r->getRequiredInfo().getArrivalDate().dateToString() + "', '" + r->getRequiredInfo().getDepartureDate().dateToString() + "', '"
		+ r->getRequiredInfo().getRoomType() + "', '" + r->getCreditInfo().getCreditCardNumber() + "', '" + r->getCreditInfo().getExpirationDate() + "', '"
		+ r->getCreditInfo().getVerificationCode() + "', '" + r->getCreditInfo().getCreditCardType() + "', '" + r->getGeneralInfo().getNumOfAdults()
		+ "', '" + r->getGeneralInfo().getNumOfChildren() + "', '" + r->getExtraInfo().getUserText() + "', '" + r->getStatus() + "', '" + to_string(r->getRoomNumber()) + "');";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//update reservation
void DB::updateReservation(DB *db, Reservation *r, Reservation* temp)
{

	int ID = r->getID();
	string sqlstmt = "UPDATE Reservation SET Name='" + temp->getGeneralInfo().getName() + "', Address='" +
		temp->getGeneralInfo().getAddress() + "', City='" + temp->getGeneralInfo().getCity() + "', State='" +
		temp->getGeneralInfo().getState() + "', Zipcode='" + temp->getGeneralInfo().getZipCode() + "', Country='" +
		temp->getGeneralInfo().getCountry() + "', Email='" + temp->getGeneralInfo().getEmail() + "', PhoneNumber='" +
		temp->getGeneralInfo().getPhoneNumber() + "', ArrivalDate='" + temp->getRequiredInfo().getArrivalDate().dateToString() +
		"', DepartureDate='" + temp->getRequiredInfo().getDepartureDate().dateToString() + "', RoomType='" +
		temp->getRequiredInfo().getRoomType() + "', CreditCardNumber='" + temp->getCreditInfo().getCreditCardNumber() +
		"', VerificationCode='" + temp->getCreditInfo().getVerificationCode() + "', ExpirationDate='" + temp->getCreditInfo().getExpirationDate() +
		"', CreditCardType='" + temp->getCreditInfo().getCreditCardType() + "', numOfAdults='" + r->getGeneralInfo().getNumOfAdults() + 
		"', numOfChildren='" + r->getGeneralInfo().getNumOfChildren() + "', ExtraFeatures='" + temp->getExtraInfo().getUserText() +
		"', Status='" + temp->getStatus() + "', RoomNumber='" + to_string(temp->getRoomNumber()) + "' WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//delete reservation
void DB::deleteReservation(DB *db, Reservation *r)
{
	int ID = r->getID();
	string sqlstmt = "DELETE FROM Reservation WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//print reservation
void DB::printReservation(DB *db, Reservation *r)
{
	int ID = r->getID();
	string sqlstmt = "SELECT * FROM Reservation WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;
		cout << "Name: " << row.at(1) << endl
			<< "Address: " << row.at(2) << endl
			<< "City: " << row.at(3) << endl
			<< "State: " << row.at(4) << endl
			<< "Zip Code: " << row.at(5) << endl
			<< "Country: " << row.at(6) << endl
			<< "Email: " << row.at(7) << endl
			<< "Phone Number: " << row.at(8) << endl
			<< "Arrival Date: " << row.at(9) << endl
			<< "Departure Date: " << row.at(10) << endl
			<< "RoomType: " << row.at(11) << endl
			<< "Credit Card Number: " << row.at(12) << endl
			<< "Expiration Date: " << row.at(13) << endl
			<< "Verification Code: " << row.at(14) << endl
			<< "Credit Card Type: " << row.at(15) << endl
			<< "Number of Adults: " << row.at(16) << endl
			<< "Number of Children: " << row.at(17) << endl
			<< "Extra Features: " << row.at(18) << endl
			<< "Status: " << row.at(19) << endl
			<< "Room Number: " << row.at(20) << endl;
	}
}

//returns a Reservations object with all attributes
void DB::getReservation(DB *db, Reservation& newReservation, int ID)
{
	string sqlstmt = "SELECT * FROM Reservation WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;

		newReservation.setID(stoi(row.at(0)));
		newReservation.getGeneralInfo().setName(row.at(1));
		newReservation.getGeneralInfo().setAddress(row.at(2));
		newReservation.getGeneralInfo().setCity(row.at(3));
		newReservation.getGeneralInfo().setState(row.at(4));
		newReservation.getGeneralInfo().setZipCode(row.at(5));
		newReservation.getGeneralInfo().setCountry(row.at(6));
		newReservation.getGeneralInfo().setEmail(row.at(7));
		newReservation.getGeneralInfo().setPhoneNumber(row.at(8));
		newReservation.getRequiredInfo().setArrivalDate(Date(row.at(9)));
		newReservation.getRequiredInfo().setDepartureDate(Date(row.at(10)));
		newReservation.getRequiredInfo().setRoomType(row.at(11));
		newReservation.getCreditInfo().setCreditCardNumber(row.at(12));
		newReservation.getCreditInfo().setExpirationDate(row.at(13));
		newReservation.getCreditInfo().setVerificationCode(row.at(14));
		newReservation.getCreditInfo().setCreditCardType(row.at(15));
		newReservation.getGeneralInfo().setNumOfAdults(row.at(16));
		newReservation.getGeneralInfo().setNumOfChildren(row.at(17));
		newReservation.getExtraInfo().setUserText(row.at(18));
		newReservation.setStatus(row.at(19));
		newReservation.setRoomNumber(stoi(row.at(20)));
	}
}

void DB::populateReservations(DB *db, vector<Reservation*>& vReservations, Date& endDate)
{
	string sqlstmt = "SELECT * FROM Reservation;";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;

		Reservation *temp = new Reservation();
		temp->setID(stoi(row.at(0)));
		temp->getGeneralInfo().setName(row.at(1));
		temp->getGeneralInfo().setAddress(row.at(2));
		temp->getGeneralInfo().setCity(row.at(3));
		temp->getGeneralInfo().setState(row.at(4));
		temp->getGeneralInfo().setZipCode(row.at(5));
		temp->getGeneralInfo().setCountry(row.at(6));
		temp->getGeneralInfo().setEmail(row.at(7));
		temp->getGeneralInfo().setPhoneNumber(row.at(8));
		temp->getRequiredInfo().setArrivalDate(Date(row.at(9)));
		temp->getRequiredInfo().setDepartureDate(Date(row.at(10)));
		temp->getRequiredInfo().setRoomType(row.at(11));
		temp->getCreditInfo().setCreditCardNumber(row.at(12));
		temp->getCreditInfo().setExpirationDate(row.at(13));
		temp->getCreditInfo().setVerificationCode(row.at(14));
		temp->getCreditInfo().setCreditCardType(row.at(15));
		temp->getGeneralInfo().setNumOfAdults(row.at(16));
		temp->getGeneralInfo().setNumOfChildren(row.at(17));
		temp->getExtraInfo().setUserText(row.at(18));
		temp->setStatus(row.at(19));
		temp->setRoomNumber(stoi(row.at(20)));
		if (temp->getRequiredInfo().getArrivalDate() < endDate)
		{
			vReservations.push_back(temp);
		}
	}
}

/////////\\\\\\\\\
/////ROOMTYPE\\\\\
/////////\\\\\\\\\

//create roomtype table
void DB::createRoomTypeTable(DB *db)
{
	char *stmt = "CREATE TABLE RoomType (" \
		"ID						INTEGER PRIMARY KEY," \
		"TypeName				TEXT		NULL," \
		"TypeCode				TEXT		NULL	UNIQUE," \
		"MaximumNumOfAdults		INTEGER		NULL," \
		"MaximumNumOfChildren	INTEGER		NULL," \
		"NumberOfBeds			INTEGER		NULL," \
		"Description			TEXT		NULL);";
	db->query(stmt);
}


//add roomType
void DB::addRoomType(DB *db, RoomType *rt)
{
	string sqlstmt = "INSERT INTO RoomType(TypeName, TypeCode, MaximumNumOfAdults, MaximumNumOfChildren, NumberOfBeds, Description) VALUES ('"
		+ rt->getTypeName() + "', '" + rt->getTypeCode() + "', '" + to_string(rt->getMaxAdults()) + "', '"
		+ to_string(rt->getMaxChildren()) + "', '" + to_string(rt->getNumberOfBeds()) + "', '" + rt->getDescription() + "');";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//update roomType
void DB::updateRoomType(DB *db, RoomType *rt, RoomType* temp)
{
	int ID = rt->getID();
	string sqlstmt = "UPDATE RoomType SET TypeName='" + temp->getTypeName() + "', TypeCode='" +
		temp->getTypeCode() + "', MaximumNumOfAdults='" + to_string(temp->getMaxAdults()) + "', MaximumNumOfChildren='" +
		to_string(temp->getMaxChildren()) + "', NumberOfBeds='" + to_string(temp->getNumberOfBeds()) + "', Description='" + temp->getDescription() +
		"' WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//delete roomType
void DB::deleteRoomType(DB *db, RoomType *rt)
{
	int ID = rt->getID();
	string sqlstmt = "DELETE FROM RoomType WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//print roomType
void DB::printRoomType(DB *db, RoomType *rt)
{
	int ID = rt->getID();
	string sqlstmt = "SELECT * FROM RoomType WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;
		cout << "TypeName: " << row.at(1) << endl
			<< "TypeCode: " << row.at(2) << endl
			<< "Maximum Number Of Adults: " << row.at(3) << endl
			<< "Maximum Number Of Children: " << row.at(4) << endl
			<< "Number of Beds: " << row.at(5) << endl
			<< "Description: " << row.at(6) << endl;
	}
}

//returns a Roomtype object with all attributes
void DB::getRoomType(DB *db, RoomType* newRoomType, int ID)
{
	string sqlstmt = "SELECT * FROM RoomType WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;

		newRoomType->setID(stoi(row.at(0)));
		newRoomType->setTypeName(row.at(1));
		newRoomType->setTypeCode(row.at(2));
		newRoomType->setMaxAdults(stoi(row.at(3)));
		newRoomType->setMaxChildren(stoi(row.at(4)));
		newRoomType->setNumberOfBeds(stoi(row.at(5)));
		newRoomType->setDescription(row.at(6));
	}
}

//overloaded roomType operator
void DB::getRoomType(DB *db, RoomType* newRoomType, const string& typeName)
{
	string sqlstmt = "SELECT * FROM RoomType WHERE TypeName='" + typeName + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;

		newRoomType->setID(stoi(row.at(0)));
		newRoomType->setTypeName(row.at(1));
		newRoomType->setTypeCode(row.at(2));
		newRoomType->setMaxAdults(stoi(row.at(3)));
		newRoomType->setMaxChildren(stoi(row.at(4)));
		newRoomType->setNumberOfBeds(stoi(row.at(5)));
		newRoomType->setDescription(row.at(6));
	}
}

////\\\\\\\\
///ROOM\\\\\
/////\\\\\\\

//create room table
void DB::createRoomTable(DB *db)
{
	char *stmt = "CREATE TABLE Room (" \
		"ID						INTEGER PRIMARY KEY," \
		"RoomNumber				INTEGER		NULL	UNIQUE," \
		"RoomType				TEXT		NULL," \
		"RoomFeatures			TEXT		NULL);";
	db->query(stmt);
}


//add room
void DB::addRoom(DB *db, Room *ro)
{
	string sqlstmt = "INSERT INTO Room(RoomNumber, RoomType, RoomFeatures) VALUES ('"
		+ to_string(ro->getRoomNumber()) + "', '" + ro->getRoomType()->getTypeName() + "', '" + ro->featuresToString() 
		+ "');";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//update room

void DB::updateRoom(DB *db, Room *ro, Room* temp)
{
	int ID = ro->getID();

	string sqlstmt = "UPDATE Room SET RoomNumber='" + to_string(temp->getRoomNumber()) +
		"', RoomType='" + temp->getRoomType()->getTypeName() + "', RoomFeatures='" +
		temp->featuresToString() + "' WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//delete roomType
void DB::deleteRoom(DB *db, Room *ro)
{
	string sqlstmt = "DELETE FROM Room WHERE RoomNumber='" + to_string(ro->getRoomNumber()) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

//print room
void DB::printRoom(DB *db, Room *ro)
{
	int ID = ro->getID();
	string sqlstmt = "SELECT * FROM Room WHERE RoomNumber='" + to_string(ro->getRoomNumber()) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;
		cout << "ID: " << row.at(0) << endl
			<< "RoomNumber: " << row.at(1) << endl
			<< "RoomType: " << row.at(2) << endl
			<< "RoomFeatures: " << row.at(3) << endl;
	}
}

//get room
void DB::getRoom(DB *db, Room* newRoom, int ID)
{
	string sqlstmt = "SELECT * FROM Room WHERE ID='" + to_string(newRoom->getRoomNumber()) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;

		newRoom->setID(stoi(row.at(0)));
		newRoom->setRoomNumber(stoi(row.at(1)));
		newRoom->getRoomType()->setTypeName(row.at(2));
		newRoom->stringToFeatures(row.at(3));
	}
}

/////\\\\\\\\
//FEATURES\\\\
/////\\\\\\\\

void DB::createFeaturesTable(DB *db)
{
	char *stmt = "CREATE TABLE Features (" \
		"ID				INTEGER PRIMARY KEY," \
		"Feature		TEXT		NULL);";
	db->query(stmt);
}

void DB::addFeature(DB *db, Features *f)
{
	string sqlstmt = "INSERT INTO Features(Feature) VALUES ('"
		+ f->getFeatureName() + "');";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

void DB::updateFeature(DB *db, Features *f, Features* temp)
{
	int ID = f->getID();
	string sqlstmt = "UPDATE Features SET Feature='" + temp->getFeatureName() +
		"' WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}


void DB::deleteFeature(DB *db, Features *f)
{
	int ID = f->getID();
	string sqlstmt = "DELETE FROM Features WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

void DB::printFeature(DB *db, Features *f)
{
	int ID = f->getID();
	string sqlstmt = "SELECT * FROM Features WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;
		cout << "ID: " << row.at(0) << endl
			<< "Feature: " << row.at(1) << endl;
	}
}

void DB::getFeature(DB *db, Features* newFeature, int ID)
{
	string sqlstmt = "SELECT * FROM Features WHERE ID='" + to_string(ID) + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	vector<vector<string> > result = db->query(c);
	delete[] c;

	for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
	{
		vector<string> row = *it;

		newFeature->setID(stoi(row.at(0)));
		newFeature->setFeatureName(row.at(1));
	}
}

/////////\\\\\\\\
//////BLOCKS\\\\
/////////\\\\\\\\

void DB::createBlocksTable(DB *db)
{
	char *stmt = "CREATE TABLE Blocks (" \
		"ID					INTEGER PRIMARY KEY," \
		"RoomNumber			TEXT	NULL," \
		"ReservationID		TEXT	NULL," \
		"Date				TEXT	NULL);";
	db->query(stmt);
}

void DB::addBlock(DB *db, Reservation *re, int roomNumber, Date *d)
{
	string sqlstmt = "INSERT INTO Blocks(RoomNumber, ReservationID, Date) VALUES ('"
		+ to_string(roomNumber) + "', '" + to_string(re->getID()) +
		+"', '" + d->dateToString() + "');";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}

void DB::deleteBlock(DB *db, Reservation *re, int roomNumber, Date *d)
{
	string sqlstmt = "DELETE FROM Blocks WHERE RoomNumber='" + to_string(roomNumber)
		+ "' AND Date='" + d->dateToString() + "';";

	//code that converts string to char* to use in query()
	char *c = new char[sqlstmt.length() + 1];
	strcpy(c, sqlstmt.c_str());
	db->query(c);
	delete[] c;
}
