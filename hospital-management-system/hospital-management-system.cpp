#include <iostream>
using namespace std;

#include "Hospital.h"
#include "Doctor.h"

// Function to display the main menu options
void showMainMenu() {
	cout << "\n==========================================\n";
	cout << "       Hospital Management System\n";
	cout << "========================================\n";
	cout << "[1] Patient Services\n";
	cout << "[2] Doctor Management\n";
	cout << "[3] Nursing Unit\n";
	cout << "[4] Medicine Inventory\n";
	cout << "[5] Room Assignment\n";
	cout << "[6] Billing System\n";
	cout << "[0] Exit\n";
	cout << "---------------------------------------\n";

	cout << "Please enter your choice: ";

}
// Main Program
int main() {
	Hospital object;

	int choiceOne;
	char choiceTwo;

	while (true) {

		showMainMenu();
		cin >> choiceOne;
		// -------------------------- PATIENT SECTION -----------------------
		if (choiceOne == 1) {
			cout << "\n------------------------------\n";
			cout << "          Patient Menu\n";
			cout << "--------------------------------\n";
			cout << " A. Add Patient\n";
			cout << " B. Delete Patient\n";
			cout << " C. Update Patient Info\n";
			cout << " D. Display Patient\n";
			cout << " E. Remove Medicine\n";
			cout << " F. Display All Patients\n";

			cout << "Enter your choice: ";

			cin >> choiceTwo;
			choiceTwo = tolower(choiceTwo);

			if (choiceTwo == 'a') {
				string name, gender, disease;
				int age, patientId;
		
				Doctor* assignedDoctor;
				int dId;

				Nurse* assignedNurse;
				int nId;

				Room* assignedRoom;
				int rId;
				Billing* bill;
				int bId;

				vector<Medicine*> prescribedMedicines;

				cout << "Enter name: ";
				cin.ignore();
				getline(cin, name);

				cout << "Enter Age: ";
				cin >> age;

				cout << "Enter Gender: ";
				cin.ignore();
				getline(cin, gender);

				cout << "Enter Patient ID: ";
				cin >> patientId;

				cout << "Enter Disease: ";
				cin.ignore();
				getline(cin, disease);

				cout << "Enter Doctor ID: ";
				cin >> dId;
				assignedDoctor = object.findDoctor(dId);

				cout << "Enter Nurse ID: ";
				cin >> nId;
				assignedNurse = object.findNurse(nId);

				cout << "Enter Room ID: ";
				cin >> rId;
				assignedRoom = object.findRoom(rId);

				int dd;
				cout << "Enter Medicine ID.. He take: ";
				cin >> dd;
				Medicine* m = object.findMedicine(dd);
				prescribedMedicines.push_back(m);

				cout << "Enter Bill ID: ";
				cin >> bId;
				bill = object.findBill(bId);


				object.addPatient(new Patient(name, age, gender, patientId, disease, assignedDoctor, assignedNurse, assignedRoom, prescribedMedicines, bill));
			}
			else if (choiceTwo == 'b') {
				int patientId;

				cout << "Enter Patient ID to delete: ";
				cin >> patientId;
				object.deletePatient(patientId);
			}

			else if (choiceTwo == 'c') {
				int patientId;

				cout << "Enter Patient ID to update: ";
				cin >> patientId;

				object.updatePatient(patientId);
			}
			else if (choiceTwo == 'd') {
				int patientId;

				cout << "Enter Patient ID: ";
				cin >> patientId;

				object.displayPatient(patientId);
			}
			else if (choiceTwo == 'e') {
				string medicineName;
				int patientId;

				cout << "Enter Patient ID: ";
				cin >> patientId;

				cout << "Enter Medicine Name to remove: ";
				cin.ignore();
				getline(cin, medicineName);


				object.removeMedicineFromPatient(patientId, medicineName);
			}
			else if (choiceTwo == 'f') {
				cout << "\n          Display All Patients           \n";
				object.displayAllPatients();

			}
			else {
				cout << "Invalid Option.\n";
			}

		}
		// ------------------- DOCTOR SECTION -----------------------
		else if (choiceOne == 2) {
			cout << "\n------------------------------\n";
			cout << "          Doctor Menu\n";
			cout << "--------------------------------\n";
			cout << " A. Add Doctor\n";
			cout << " B. Delete Doctor\n";
			cout << " C. Update Doctor Info\n";
			cout << " D. Add Patient to list\n";
			cout << " E. Remove Patient from list\n"; 
			cout << " F. Display All Doctors\n";

			cout << "Enter your choice: ";

			cin >> choiceTwo;
			choiceTwo = tolower(choiceTwo);

			if (choiceTwo == 'a') {
				string name;
				int age;
				string gender;

				int doctorId;
				string specialty;
				vector<Patient*> patients;
				cout << "Enter Name: ";
				cin.ignore();
				getline(cin, name);

				cout << "Enter Age: ";
				cin >> age;

				cout << "Enter Gender: ";
				cin.ignore();
				getline(cin, gender);

				cout << "Enter Doctor ID: ";
				cin >> doctorId;

				cout << "Enter Specialty: ";
				cin.ignore();
				getline(cin, specialty);

				object.addDoctor(new Doctor(name, age, gender, doctorId, specialty, patients));
			}
			else if (choiceTwo == 'b') {
				int doctorId;

				cout << "Enter Doctor ID to delete: ";
				cin >> doctorId;

				object.deleteDoctor(doctorId);
			}
			else if (choiceTwo == 'c') {
				int doctorId;

				cout << "Enter Doctor ID to update: ";
				cin >> doctorId;

				object.updateDoctor(doctorId);
			}
			else if (choiceTwo == 'd') {
				int doctorId, patientId;

				cout << "Enter Doctor ID: ";
				cin >> doctorId;

				cout << "Enter Patient ID to adding: ";
				cin >> patientId;

				object.addPatientToPatientList(doctorId, patientId);
			}
			else if (choiceTwo == 'e') {
				int doctorId;
				string patientName;

				cout << "Enter Doctor ID: ";
				cin >> doctorId;

				cout << "Enter Patient Name to remove: ";
				cin.ignore();
				getline(cin, patientName);

				object.removePatientFromPatients(doctorId, patientName);
			}
			else if (choiceTwo == 'f') {
				cout << "\n           Display All Doctors           \n";
				object.displayAllDoctors();
			}

			else {
				cout << "Invalid Option.\n";
			}
		}
		// --------------------------- NURSE SECTION -------------------------
		else if (choiceOne == 3) {
			cout << "\n------------------------------\n";
			cout << "          Nurse Menu\n";
			cout << "--------------------------------\n";
			cout << " A. Add Nurse\n";
			cout << " B. Delete Nurse\n";
			cout << " C. Update Nurse Info\n";
			cout << " D. Add Patient To List\n";
			cout << " E. Remove Patient From List\n";
			cout << " F. Display All Nurse\n";

			cout << "Enter your choice: ";

			cin >> choiceTwo;
			choiceTwo = tolower(choiceTwo);

			if (choiceTwo == 'a') {
				string name;
				int age;
				string gender;

				int nurseId;
				string shift;

				vector<Patient*> assignedPatients;

				cout << "Enter Name: ";
				cin.ignore();
				getline(cin, name);

				cout << "Enter Age: ";
				cin >> age;

				cout << "Enter Gender: ";
				cin.ignore();
				getline(cin, gender);

				cout << "Enter Nurse ID: ";
				cin >> nurseId;

				cout << "Enter Shift: ";
				cin.ignore();
				getline(cin, shift);

				object.addNurse(new Nurse(name, age, gender, nurseId, shift, assignedPatients));
			}
			else if (choiceTwo == 'b') {
				int nurseId;

				cout << "Enter Nurse ID to delete: ";
				cin >> nurseId;

				object.deleteNurse(nurseId);
			}
			else if (choiceTwo == 'c') {
				int nurseId;

				cout << "Enter Nurse ID to update: ";
				cin >> nurseId;

				object.updateNurse(nurseId);
			}
			else if (choiceTwo == 'd') {
				int nurseId;
				int patientId;

				cout << "Enter Nurse ID: ";
				cin >> nurseId;

				cout << "Enter Patient ID to adding: ";
				cin >> patientId;

				object.addPatientToListNurse(nurseId, patientId);
			}
			else if (choiceTwo == 'e') {
				int nurseId;
				string patientName;

				cout << "Enter Nurse ID: ";
				cin >> nurseId;

				cout << "Enter Patient Name to remove: ";
				cin.ignore();
				getline(cin, patientName);

				object.removePatient(nurseId, patientName);
			}
			else if (choiceTwo == 'f') {
				cout << "\n        Display All Nurses          \n";
				object.displayAllNurses();
			}
			else {
				cout << "Invalid Option.\n";
			}
		}
		// --------------------------- MEDICINE SECTION -------------------------
		else if (choiceOne == 4) {
			cout << "\n------------------------------\n";
			cout << "          Medicine Menu\n";
			cout << "--------------------------------\n";
			cout << " A. Add Medicine\n";
			cout << " B. Delete Medicine\n";
			cout << " C. Update Medicine Info\n";
			cout << " D. Display Medicine\n";
			cout << " E. Display All Medicines\n";

			cout << "Enter your choice: ";
			cin >> choiceTwo;
			choiceTwo = tolower(choiceTwo);

			if (choiceTwo == 'a') {

				int medicineId;
				string name;
				string dosage;
				int stockQuantity;

				cout << "Enter Medicine Id: ";
				cin >> medicineId;

				cin.ignore();

				cout << "Enter Name: ";
				getline(cin, name);

				cout << "Enter Dosage: ";
				getline(cin, dosage);

				cout << "Enter Stock Quantity: ";
				cin >> stockQuantity;

				object.addMedicine(new Medicine(medicineId, name, dosage, stockQuantity));
			}
			else if (choiceTwo == 'b') {
				int medicineId;

				cout << "Enter Medicine ID to delete: ";
				cin >> medicineId;

				object.deleteMedicine(medicineId);
			}
			else if (choiceTwo == 'c') {
				int medicineId;

				cout << "Enter Medicine ID to update: ";
				cin >> medicineId;

				object.updateMedicine(medicineId);
			}
			else if (choiceTwo == 'd') {
				int medicineId;

				cout << "Enter Medicine ID to display: ";
				cin >> medicineId;

				object.displayMedicine(medicineId);
			}

			else if (choiceTwo == 'e') {
				cout << "\n            Display All Medicines           \n";
				object.displayListMedicines();
			}
			else {
				cout << "Invalid Option.\n";
			}
		}
		// ------------------------- ROOM SECTION ------------------------------
		else if (choiceOne == 5) {
			cout << "\n------------------------------\n";
			cout << "          Room Menu\n";
			cout << "--------------------------------\n";
			cout << " A. Add Room\n";
			cout << " B. Delete Room\n";
			cout << " C. Update Room Info\n";
			cout << " D. Display Room\n";
			cout << " E. Display All Rooms\n";

			cout << "Enter your choice: ";
			cin >> choiceTwo;
			choiceTwo = tolower(choiceTwo);

			if (choiceTwo == 'a') {
				int roomNumber;
				string type;

				cout << "Enter Room Number: ";
				cin >> roomNumber;

				cout << "Enter Room Type: ";
				cin.ignore();
				getline(cin, type);

				object.addRoom(new Room(roomNumber, type));
			}

			else if (choiceTwo == 'b') {
				int roomNumber;

				cout << "Enter Room Number to delete: ";
				cin >> roomNumber;

				object.deleteRoom(roomNumber);
			}
			else if (choiceTwo == 'c') {
				int roomNumber;

				cout << "Enter Room Number to update: ";
				cin >> roomNumber;

				object.updateRoom(roomNumber);
			}
			else if (choiceTwo == 'd') {
				int roomId;

				cout << "Enter Room ID to display Info: ";
				cin >> roomId;

				object.displayRoom(roomId);
			}
			else if (choiceTwo == 'e') {
				cout << "\n           Display All Rooms             \n";
				object.displayAllRooms();
			}
			else {
				cout << "Invalid Option.\n";
			}
		}
		// ----------------------------- BILL SECTION ----------------------
		else if (choiceOne == 6) {
			cout << "\n------------------------------\n";
			cout << "          Bill Menu\n";
			cout << "--------------------------------\n";
			cout << " A. Add Bill\n";
			cout << " B. Delete Bill\n";
			cout << " C. Update Bill Info\n";
			cout << " D. Display Bill\n";
			cout << " E. Display All Bills\n";

			cout << "Enter your choice: ";

			cin >> choiceTwo;
			choiceTwo = tolower(choiceTwo);

			if (choiceTwo == 'a') {
				int billId;
				double amount;
				bool paid;

				Patient* patient;
				int pId;


				cout << "Enter Bill ID: ";
				cin >> billId;

				cout << "Enter Amount: ";
				cin >> amount;

				cout << "Enter Patient ID: ";
				cin >> pId;

				cout << "Is the bill paid? (1 for Yes, 0 for No): ";
				cin >> paid;

				patient = object.findPatient(pId);

				Billing* bill = new Billing(billId, patient, amount);
				if (paid) bill->markAsPaid();
				object.addBill(bill);
			}
			else if (choiceTwo == 'b') {
				int billId;

				cout << "Enter Bill ID to delete: ";
				cin >> billId;

				object.deleteBill(billId);

			}
			else if (choiceTwo == 'c') {
				int billId;

				cout << "Enter Bill ID to update: ";
				cin >> billId;

				object.updateBill(billId);
			}
			else if (choiceTwo == 'd') {
				int billId;

				cout << "Enter Bill ID to display: ";
				cin >> billId;

				object.displayBill(billId);
			}
			else if (choiceTwo == 'e') {
				cout << "           Display All Bills             \n";
				object.displayAllBills();
			}

			else {
				cout << "Invalid Option\n";
			}
		}

		else if (choiceOne == 0) {
			cout << "Thank you for using the Hospital Management System. Stay healthy!\n";
			break;
		}

		else {
			cout << "Invalid option! please choose a valid number from the menu.\n";
		}
	}

	return 0;
}