#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"
class Patient; // Forward declaration to avoid circular dependency

class Doctor : public Person {
private:
	int doctorId;
	string specialty;
	vector<Patient*> listOfPatients;

public:
	Doctor(const string& name, int age, const string& gender, int d, const string& spe, vector<Patient*> patients);
	void displayInfo() const override;

	void addPatient(Patient* patient);
	void removePatient(const string& patientName);

	void showAllPatients() const;
	void numberPatients() const;

	void setDoctorId(int newId);
	int getDoctorId() const;
};


#endif