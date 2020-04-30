#include "MainMenu.h"
#include "Hotel.h"

using namespace Project2;
using namespace std;

[STAThreadAttribute]
//int main(array<System::String ^> ^args)
int main(int argc, int** argv)
{
	Hotel h;

	//Reservation * r = h.getReservationFromDB(6);
	//h.removeRoomAssignment(*r);
	
	h.printRooms();
	
	
	//h.addRoom(800, "Western");
	//h.addRoomFeature(800, "Big TV");
	//h.addRoomFeature(800, "Beach View");

	//h.printRooms();
	//cout << "---------------------------" << endl;
	//h.deleteRoomFeature(800, "Beach View");
	//h.printRooms();



	
	//h.setCurrentDate(Date("5/15/2014"));

	//Reservation * r = h.getReservationFromDB(8);
	//r->getGeneralInfo().setName("Megan W. Fox");
	//h.modifyReservation(*r, 8);

	//h.printReservationArray();



	//h.addRoom(800, "Western");

	//h.printRooms();

	//cout << "---------------------------" << endl;

	//h.modifyRoom(800, 900, "Suite King");

	//h.printRooms();
	//Reservation * r = h.getReservationFromDB(3);
	//h.reserve(*r);
	//h.assignRoomNumber(*r, 800);
	//h.checkInRes(*r);
	//if (h.deleteRoom(800)) {
	//	cout << "Room Deletion successful." << endl;
	//}


	//h.printRooms();

	//reservationIter iter = h.findReservation(4, 8);
	//(*iter)->print();


	//cout << "Welcome to our Hotel. Please choose from the following options: \n" << endl;
	//cout << "\t1. Manage Reservations\n"
	//	<< "\t2. Manage Room Types\n"
	//	<< "\t3. Manage Rooms\n"
	//	<< "\t4. Manage Accounts\n" << endl;
	//cout << "Choose a number: " << endl;



	/* MEGAN FOX'S RESERVATION */
	//GeneralInfo gen3 = GeneralInfo("Megan Fox", "23 Fast St.", "New York", "NY", "65789", "USA", "MeganFox@gmail.com", "1236547890", "5", "10");
	//RequiredInfo req3 = RequiredInfo(Date(5, 19, 2014), Date(5, 20, 2014), "Western");
	//CreditCard cred3 = CreditCard("Megan Fox", "23 Fast St.", "New York", "NY", "65789", "9999555511112222", "0515", "321", "VISA");
	//ExtraFeatures ex3 = ExtraFeatures();
	//Reservation r3 = Reservation(gen3, req3, ex3, cred3);

	//h.addReservation(r3);

	//h.printReservationArray();

	//////\\\\\\\\\	
	//db->createDateTable(db);
	//Date *current = new Date(5, 14, 2014);
	//db->addDate(db, current);
	
	//////\\\\\\\\\	
	//db->createAccountsTable(db);

	//Accounts *a1 = new Accounts("bvu1", "vuu222", "manager", "Brian Vu", "26", "M",
	//	"General Manager", "7772223333", "1112220000", "brianvu@gmail.com",
	//	"101 Central St.", "Irvine", "CA", "93740", "USA", "the boss");

	//Accounts *a2 = new Accounts("sal0", "salsal", "employee", "Salman Shah", "22", "M",
	//	"Front Desk", "1112224948", "7773336658", "salmanshah@gmail.com",
	//	"101 Park St.", "Tustin", "CA", "91175", "USA", "bob marley");

	//Accounts *a3 = new Accounts("jh2", "hir0", "employee", "Jahiro Otzoy", "24", "M",
	//	"Front Desk", "1112227777", "8884446666", "jahirootzoy@gmail.com",
	//	"101 Main St.", "Long Beach", "CA", "93585", "USA", "other half");

	//db->addAccount(db, a1);
	//db->addAccount(db, a2);
	//db->addAccount(db, a3);

	//////\\\\\\\\\	

	//db->createReservationsTable(db);

	//r1->setStatus("Reserved");
	//r1->setRoomNumber(100);
	//db->addReservation(db, r1);

	//arrival = Date(1, 12, 2014);
	//depart = Date(11, 4, 2014);
	//gen1 = GeneralInfo("Brad Bradson", "888 Eighth St.", "Largeville", "CA", "91718", "USA", "bradBradson@gmail.com", "0198247495", "1", "0");
	//req1 = RequiredInfo(arrival, depart, "Suite");
	//cred1 = CreditCard("Brad Bradson", "888 Eighth St.", "Largeville", "CA", "91718", "1234567812345678", "0819", "837", "Discover");
	//ex1 = ExtraFeatures();
	//Reservation *r2 = new Reservation(gen1, req1, ex1, cred1);
	//r2->setStatus("Reserved");
	//r2->setRoomNumber(101);
	//db->addReservation(db, r2);



	//////\\\\\\\\\

	//db->createRoomTypeTable(db);

	//RoomType *rt1 = new RoomType("Deluxe Queen", "dq1", 4, 2, 2, "Deluxe sized room with two queen beds");
	//db->addRoomType(db, rt1);
	//RoomType *rt2 = new RoomType("Regular King", "rk1", 4, 2, 1, "Regular sized room with one king bed");
	//db->addRoomType(db, rt2);
	//RoomType *rt3 = new RoomType("Suite King", "sk1", 4, 2, 1, "Suite sized room with one king bed");
	//db->addRoomType(db, rt3);
	//cout << endl;

	//////\\\\\\\\\

	//db->createFeaturesTable(db);

	//Features *f1 = new Features("Big TV");
	//Features *f2 = new Features("Big Living Room");
	//Features *f3 = new Features("Kitchen");
	//Features *f4 = new Features("Mini Fridge");
	//Features *f5 = new Features("Hot Tub Time Machine");

	//db->addFeature(db, f1);
	//db->addFeature(db, f2);
	//db->addFeature(db, f3);
	//db->addFeature(db, f4);
	//db->addFeature(db, f5);

	////////\\\\\\\\\

	//db->createRoomTable(db);

	//Room *ro1 = new Room(100, rt1);
	//ro1->addFeature("Big TV");
	//Room *ro2 = new Room(101, rt1);
	//ro2->addFeature("Big TV");
	//Room *ro3 = new Room(200, rt2);
	//ro3->addFeature("Mini Fridge");
	//ro3->addFeature("Big TV");
	//Room *ro4 = new Room(201, rt2);
	//ro4->addFeature("Mini Fridge");
	//

	//db->addRoom(db, ro1);
	//db->addRoom(db, ro2);
	//db->addRoom(db, ro3);
	//db->addRoom(db, ro4);
	system("Pause");
 
	////\\\\\\\\\
	////\\\\\\\\\
	
	//// Enabling Windows XP visual effects before any controls are created
	//Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false); 
	//// Create the main window and run it
	//Application::Run(gcnew MyForm());
	return 0;
}