#include "Nurse.h"
#include "Patient.h"

Nurse::Nurse(const string& name, int age, const string& gender, int nurseId, const string& shift, vector<Patient*> assignedPatients) : Person(name, age, gender) {
	this->nurseId = nurseId;
	this->shift = shift;
	this->assignedPatients = assignedPatients;
}

void Nurse::displayInfo() const {
	cout << "\n--- Nurse Information ---\n";
	cout << "Name: " << name
		<< ", Age: " << age
		<< ", Gender: " << gender
		<< ", Nurse ID: " << nurseId
		<< ", Shift: " << shift;

	cout << "\n List Assigned Patients: ";
	if (assignedPatients.empty()) {
		cout << "Patients not found.\n";
	}
	for (auto patient : assignedPatients) {
		cout << "Patient Name:" << patient->getName() << " ";
	}
	cout << endl;
}

void Nurse::addPatient(Patient* patient) {
	assignedPatients.push_back(patient);
	cout << "Patient added successfully.\n";
}

void Nurse::removePatient(const string& patientName) {
	for (auto patient = assignedPatients.begin(); patient != assignedPatients.end(); ++patient) {
		if ((*patient)->getName() == patientName) {
			assignedPatients.erase(patient);

			cout << "Patient deleted successfully.\n";
			return;
		}
	}
	cout << "Patient not found.\n";
}

void Nurse::listAssignedPatients() const {
	if (assignedPatients.empty()) {
		cout << "Not found Patient.\n";
		return;
	}

	cout << "Nurse " << name << " has patient: ";
	for (const auto& patient : assignedPatients) {
		cout << patient->getName() << " ";
	}
	cout << endl;
}

void Nurse::displayNumberOfPatients() const {
	cout << name << " has " << assignedPatients.size() << " patients.\n";
}

int Nurse::getNurseId() const {
	return nurseId;
}

void Nurse::setNurseId(int Id) {
	nurseId = Id;
}

void Nurse::setShift(const string& sh) {
	shift = sh;
}