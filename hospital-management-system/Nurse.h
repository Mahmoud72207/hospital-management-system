#ifndef NURSE_H
#define NURSE_H

#include "Person.h"
class Patient;

class Nurse : public Person {
private:
	int nurseId;
	string shift;
	vector<Patient*> assignedPatients;

public:
	Nurse(const string& name, int age, const string& gender, int nurseId, const string& shift, vector<Patient*> assignedPatients);
	void displayInfo() const override;
	
	void addPatient(Patient* patient);
	void removePatient(const string& patientName);



	void listAssignedPatients() const;
	void displayNumberOfPatients() const;

	int getNurseId() const;

	void setNurseId(int id);
	void setShift(const string& sh);

};

#endif