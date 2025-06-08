#include "Doctor.h"
#include "Patient.h"

Doctor::Doctor(const string& name, int age, const string& gender, int d, const string& spe, vector<Patient*> patients) : Person(name, age, gender), doctorId(d), specialty(spe), listOfPatients(patients) {}

void Doctor::displayInfo() const {
	cout << "\n--- Doctor Information ---\n";
	cout << "Name     : " << name << "\n"
		<< "Age      : " << age << "\n"
		<< "Gender   : " << gender << "\n"
		<< "Doctor ID: " << doctorId << "\n"
		<< "Specialty: " << specialty << "\n";

	if (listOfPatients.empty()) {
		cout << "No patients assigned.\n";
	}
	else {
		cout << "List of Patients:\n";
		for (const auto& patient : listOfPatients) {
			cout << "  - Name: " << patient->getName()
				<< ", ID: " << patient->getPatientId()
				<< ", Disease: " << patient->getDisease()
				<< "\n";
		}
	}
}

void Doctor::numberPatients() const {
	cout << name << " has " << listOfPatients.size() << " patients." << endl;

}

void Doctor::addPatient(Patient* patient) {
	listOfPatients.push_back(patient);
	cout << "Patient added successfully.\n";
}

void Doctor::showAllPatients() const {
	if (listOfPatients.empty()) {
		cout << "Not found patient.\n";
		return;
	}
	cout << "Doctor " << name << " has patients: ";
	for (const auto& patient : listOfPatients) {
		cout << patient->getName() << " ";
	}
	cout << endl;
}

int Doctor::getDoctorId() const {
	return doctorId;
}

void Doctor::setDoctorId(int newId) {
	doctorId = newId;
}

void Doctor::removePatient(const string& patientName) {
	for (auto it = listOfPatients.begin(); it != listOfPatients.end(); ++it) {
		if ((*it)->getName() == patientName) {
			listOfPatients.erase(it);

			cout << "Patient delete successfully.\n";
			return;
		}
	}
	cout << "Patient not found.\n";
}

