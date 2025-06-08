#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Room.h"
#include "Medicine.h"
#include "Billing.h"

Patient::Patient(const string& name, int age, const string& gender, int patientID, const string& disease, Doctor* assignedDoctor, Nurse* assignedNurse, Room* assignedRoom, vector<Medicine*> prescribedMedicines, Billing* bill) : Person(name, age, gender) {
	this->patientID = patientID;
	this->disease = disease;
	this->assignedDoctor = assignedDoctor;
	this->assignedNurse = assignedNurse;
	this->assignedRoom = assignedRoom;
	this->prescribedMedicines = prescribedMedicines;

}

void Patient::displayInfo() const {
	cout << "\n--- Patient Information ---\n";
	cout << "Name: " << name
		<< ", Age: " << age
		<< ", Gender: " << gender
		<< ", Patient ID: " << patientID
		<< ", Disease: " << disease;

	cout << ", Assigned Doctor: " << (assignedDoctor ? assignedDoctor->getName() : "None");
	cout << ", Assigned Nurse: " << (assignedNurse ? assignedNurse->getName() : "None");
	cout << ", assigned Room: " << (assignedRoom ? assignedRoom->getRoomNumber() : -1);
	cout << ", Bill: " << (bill ? bill->getBillId() : -1);


	cout << "\nPrescribed Medicines: ";
	for (const auto& medicine : prescribedMedicines) {
		cout << medicine->getName() << " ";

	}
	cout << endl;
}

int Patient::getPatientId() const {
	return patientID;
}
void Patient::setPatientId(int id) {
	patientID = id;
}

void Patient::setDisease(const string& d) {
	disease = d;
}

string Patient::getDisease() const {
	return disease;
}

void Patient::addMedicine(Medicine* medicine) {
	prescribedMedicines.push_back(medicine);
}

void Patient::removeMedicine(const string& medicineName) {
	for (auto m = prescribedMedicines.begin(); m != prescribedMedicines.end(); ++m) {
		if ((*m)->getName() == medicineName) {

			prescribedMedicines.erase(m);
			cout << "Medicine Deleted Successfully.\n";
			return;
		}
	}
	cout << "Medicine not found.\n";
}

