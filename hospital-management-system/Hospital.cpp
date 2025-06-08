
#include "Hospital.h"


// ------------------------- PATIENT SECTION ------------------------
void Hospital::addPatient(Patient* p) {
	listOfPatients.push_back(p);
	cout << "Patient added successfully.\n";
}

void Hospital::deletePatient(int patientId) {
	for (auto p = listOfPatients.begin(); p != listOfPatients.end(); ++p) { // P is iterator
		if ((*p)->getPatientId() == patientId) { // P is pointer on element

			delete* p; // Delete element(Prevent memory leaks)

			listOfPatients.erase(p); // Delete iterator(Memory address)
			cout << "Patient deleted successfully.\n";
			return;
		}
	}
	cout << "Patient not found.\n";
}

Patient* Hospital::findPatient(int patientId) const {
	for (auto p : listOfPatients) {
		if (p->getPatientId() == patientId) {
			return p;
		}
	}
	return nullptr;
}

void Hospital::updatePatient(int patientId) {
	Patient* p = findPatient(patientId);

	if (p) {
		string newName, newGender, newDisease;
		int newAge, newId;

		cout << "Updating patient information...\n";

		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, newName);

		cout << "Enter new age: ";
		cin >> newAge;

		cout << "Enter new gender: ";
		cin.ignore();
		getline(cin, newGender);


		cout << "Enter new ID: ";
		cin >> newId;

		cout << "Enter new Disease: ";
		cin.ignore();
		getline(cin, newDisease);


		p->setName(newName);
		p->setGender(newGender);
		p->setAge(newAge);
		p->setPatientId(newId);
		p->setDisease(newDisease);

		cout << "Patient information updated successfully.\n";
	}

	else {
		cout << "Patient not found.\n";
	}
}

void Hospital::displayPatient(int patientId) const {
	Patient* p = findPatient(patientId);

	if (p) {
		p->displayInfo();
	}
	else {
		cout << "Patient not found.\n";
	}
}

void Hospital::removeMedicineFromPatient(int patientId, const string& medicineName) const {
	Patient* p = findPatient(patientId);

	if (p) {
		p->removeMedicine(medicineName);
	}
	else {
		cout << "Patient not found, Cannot delete medical.\n";
	}

}

void Hospital::displayAllPatients() const {
	if (listOfPatients.empty()) {
		cout << "No patients found.\n";
		return;
	}

	for (auto patient : listOfPatients) {
		patient->displayInfo();
	}
}

// --------------------------- DOCTOR SECTION ----------------------
void Hospital::addDoctor(Doctor* d) {
	listOfDoctors.push_back(d);
	cout << "Doctor added successfully.\n";
}

void Hospital::deleteDoctor(int doctorId) {
	for (auto d = listOfDoctors.begin(); d != listOfDoctors.end(); ++d) {
		if ((*d)->getDoctorId() == doctorId) {
			delete* d;

			listOfDoctors.erase(d);
			cout << "Doctor deleted successfully.\n";
			return;
		}
	}
	cout << "Doctor not found.\n";
}
 
Doctor* Hospital::findDoctor(int doctorId) const {
	for (auto d : listOfDoctors) {
		if (d->getDoctorId() == doctorId) {
			return d;
		}
	}
	return nullptr;
}

void Hospital::updateDoctor(int doctorId) {
	Doctor* d = findDoctor(doctorId);

	if (d) {
		string newName, newGender;
		int newAge, newId;

		cout << "Updating doctor information...\n";

		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, newName);

		cout << "Enter new age: ";
		cin >> newAge;

		cout << "Enter new gender: ";
		cin.ignore();
		getline(cin, newGender);

		cout << "Enter new ID: ";
		cin >> newId;

		d->setName(newName);
		d->setAge(newAge);
		d->setGender(newGender);
		d->setDoctorId(newId);
		
		cout << "Doctor information updated successfully.\n";

	}

	else {
		cout << "Doctor not found.\n";
	}
}

void Hospital::addPatientToPatientList(int doctorId, int patientId) const {
	Doctor* doctor = findDoctor(doctorId);
	Patient* patient = findPatient(patientId);

	if (doctor) {
		doctor->addPatient(patient);
	}
	else {
		cout << "Doctor not found, Cannot adding patient.\n";
	}
}

void Hospital::removePatientFromPatients(int doctorId, const string& patientName) const{
	Doctor* doctor = findDoctor(doctorId);

	if (doctor) {
		doctor->removePatient(patientName);
	}
	else {
		cout << "Doctor not found, Cannot delete patient.\n";
	}

}

void Hospital::displayAllDoctors() const {
	if (listOfDoctors.empty()) {
		cout << "No doctors found.\n";
	}
	for (auto doctor : listOfDoctors) {
		doctor->displayInfo();
	}
}

// ------------------------	NURSE SECTION -------------------------
void Hospital::addNurse(Nurse* n) {
	listOfNurses.push_back(n);
	cout << "Nurse added successfully.\n";
}

void Hospital::deleteNurse(int nurseId) {
	for (auto n = listOfNurses.begin(); n != listOfNurses.end(); ++n) {
		if ((*n)->getNurseId() == nurseId) {
			delete* n;

			listOfNurses.erase(n);
			cout << "Nurse deleted successfully.\n";
			return;
		}
	}
	cout << "Nurse not found.\n";
}

Nurse* Hospital::findNurse(int nurseId) const {
	for (auto n : listOfNurses) {
		if (n->getNurseId() == nurseId) {
			return n;
		}
	}
	return nullptr;
}

void Hospital::updateNurse(int nurseId) {
	Nurse* n = findNurse(nurseId);

	if (n) {
		string newName, newGender, newShift;
		int newAge, newId;

		cout << "Updating nurse information...\n";

		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, newName);

		cout << "Enter new age: ";
		cin >> newAge;

		cout << "Enter new gender: ";
		cin.ignore();
		getline(cin, newGender);

		cout << "Enter new ID: ";
		cin >> newId;

		cout << "Enter new shift: ";
		cin.ignore();
		getline(cin, newShift);

		n->setName(newName);
		n->setAge(newAge);
		n->setGender(newGender);
		n->setNurseId(newId);
		n->setShift(newShift);

		cout << "Nurse information updated successfully.\n";
	}

	else {
		cout << "Nurse not found.\n";
	}
}

void Hospital::addPatientToListNurse(int nurseId, int patientId) const {
	Nurse* nurse = findNurse(nurseId);
	Patient* patient = findPatient(patientId);

	if (nurse) {
		nurse->addPatient(patient);
	}
	else {
		cout << "Nurse not found. Cannot adding patient.\n";
	}

}
void Hospital::removePatient(int nurseId, const string& patientName) const {
	Nurse* nurse = findNurse(nurseId);
	
	if (nurse) {
		nurse->removePatient(patientName);
	}
	else {
		cout << "Nurse not found. Cannot deleted patient\n";
	}
}

void Hospital::displayAllNurses() const {
	if (listOfNurses.empty()) {
		cout << "Not nurses found.\n";
		return;
	}
	for (auto nurse : listOfNurses) {
		nurse->displayInfo();
	}
}

// ------------------------- MEDICINE SECTION ------------------------------
void Hospital::addMedicine(Medicine* m) {
	listOfMedicines.push_back(m);
	cout << "Medicine added successfully.\n";
}

void Hospital::deleteMedicine(int medicineId) {
	for (auto m = listOfMedicines.begin(); m != listOfMedicines.end(); ++m) {
		if ((*m)->getMedicineId() == medicineId) {
			delete* m;

			listOfMedicines.erase(m);
			cout << "Medicine deleted successfully.\n";
			return;
		}
	}
	cout << "Medicine not found.\n";
}

Medicine* Hospital::findMedicine(int medicineId) const {
	for (auto m : listOfMedicines) {
		if (m->getMedicineId() == medicineId) {
			return m;
		}
	}
	return nullptr;
}

void Hospital::updateMedicine(int medicineId) {
	Medicine* m = findMedicine(medicineId);

	if (m) {
		int newId, updateStock;
		string newName, newDosage;

		cout << "Updating medicine information...\n";

		cout << "Enter new ID: ";
		cin >> newId;

		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, newName);

		cout << "Enter new dosage: ";
		cin.ignore();
		getline(cin, newDosage);

		cout << "Enter update stock quantity: ";
		cin >> updateStock;

		m->setMedicineId(newId);
		m->setMedicineName(newName);
		m->setDosage(newDosage);
		m->updateStock(updateStock);

		cout << "Medicine update successfully.\n";
	}
	else {
		cout << "Medicine not found.\n";
	}
}

void Hospital::displayMedicine(int medicineId) const {
	Medicine* medicine = findMedicine(medicineId);

	if (medicine) {
		medicine->displayInfo();
	}
	else {
		cout << "Medicine not found. Cannot display medicine\n";
	}
}

void Hospital::displayListMedicines() const {
	if (listOfMedicines.empty()) {
		cout << "No medicines found.\n";
		return;
	}
	for (auto medicine : listOfMedicines) {
		medicine->displayInfo();
	}
}

// ------------------------------ ROOM SECTION ---------------------------
void Hospital::addRoom(Room* r) {
	listOfRooms.push_back(r);
	cout << "Room added successfully.\n";
}

void Hospital::deleteRoom(int roomNumber) {
	for (auto r = listOfRooms.begin(); r != listOfRooms.end(); ++r) {
		if ((*r)->getRoomNumber() == roomNumber) {
			delete* r;

			listOfRooms.erase(r);
			cout << "Room deleted successfully.\n";
			return;
		}
	}
	cout << "Room not found.\n";
}

Room* Hospital::findRoom(int roomNumber) const {
	for (auto room : listOfRooms) {
		if (room->getRoomNumber() == roomNumber) {
			return room;
		}
	}
	return nullptr;
}

void Hospital::updateRoom(int roomNumber) {
	Room* r = findRoom(roomNumber);

	if (r) {
		int newRoomNum, patientId;
		string newType;
		char status;

		cout << "Updating room details...\n";

		cout << "Enter new room number: ";
		cin >> newRoomNum;

		cout << "Enter new room type: ";
		cin.ignore();
		getline(cin, newType);

		cout << "Is room vacant (y/n)?: ";
		cin >> status;

		if (tolower(status) == 'y') {
			r->removePatient();  
		}
		else if (tolower(status) == 'n') {
			cout << "Enter patient ID to assign: ";
			cin >> patientId;

			Patient* p = findPatient(patientId);
			if (p) {
				r->assignPatient(p);  
			}
			else {
				cout << "Patient not found. Room remains vacant.\n";
				r->removePatient();
			}
		}
		else {
			cout << "Invalid input. Room status unchanged.\n";
		}

		r->setRoomNum(newRoomNum);
		r->setType(newType);

		cout << "Room updated successfully.\n";
	}
	else {
		cout << "Room not found.\n";
	}
}

void Hospital::displayRoom(int roomId) const {
	Room* room = findRoom(roomId);

	if (room) {
		room->displayInfo();
	}
	else {
		cout << "Room not found. Cannot display room\n";
	}
}

void Hospital::displayAllRooms() const {
	if (listOfRooms.empty()) {
		cout << "No rooms found.\n";
		return;
	}
	for (auto room : listOfRooms) {
		room->displayInfo();
	}
}

// ------------------------ BILLING SECTION ----------------------
void Hospital::addBill(Billing* b) {
	listOfBills.push_back(b);
	cout << "Bill added successfully.\n";
}

void Hospital::deleteBill(int billId) {
	for (auto b = listOfBills.begin(); b != listOfBills.end(); ++b) {
		if ((*b)->getBillId() == billId) {
			delete* b;

			listOfBills.erase(b);
			cout << "Bill deleted successfully.\n";
			return;
		}
	}
	cout << "Bill not found.\n";
}

Billing* Hospital::findBill(int billId) const {
	for (auto bill : listOfBills) {
		if (bill->getBillId() == billId) {
			return bill;
		}
	}
	return nullptr;
}

void Hospital::updateBill(int billId) {
	Billing* b = findBill(billId);

	if (b) {
		int newId, status;
		double newAmount;

		cout << "Updating bill...\n";

		cout << "Enter new bill ID: ";
		cin >> newId;

		cout << "Enter new amount: ";
		cin >> newAmount;

		cout << "Is the bill paid? (1 = Yes, 0 = No): ";
		cin >> status;

		if (status == 1) {
			b->markAsPaid();
		}
		else if (status == 0) {
			b->markNotPaid();
		}

		b->setBillId(newId);
		b->setAmount(newAmount);

		cout << "Bill updated successfully.\n";
	}
	else {
		cout << "Bill not found.\n";
	}
}

void Hospital::displayBill(int billId) const {
	Billing* bill = findBill(billId);

	if (bill) {
		bill->displayInfo();
	}
	else {
		cout << "Bill not found. Cannot display bill\n";
	}

}

void Hospital::displayAllBills() const {
	if (listOfBills.empty()) {
		cout << "No bills found.\n";
		return;
	}
	for (auto bill : listOfBills) {
		bill->displayInfo();
	}
}

// ------------------------ DESTRUCTOR ---------------------
Hospital::~Hospital() {

	for (auto p : listOfPatients) {
		delete p; // delete element
	}
	listOfPatients.clear(); // delete all pointers

	for (auto d : listOfDoctors) {
		delete d;
	}
	listOfDoctors.clear();

	for (auto n : listOfNurses) {
		delete n;
	}
	listOfNurses.clear();


	for (auto m : listOfMedicines) {
		delete m;
	}
	listOfMedicines.clear();

	for (auto r : listOfRooms) {
		delete r;
	}
	listOfRooms.clear();

	for (auto b : listOfBills) {
		delete b;
	}
	listOfBills.clear();
}
