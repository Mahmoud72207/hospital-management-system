#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"

// forward declaration

class Doctor;
class Nurse;
class Room;
class Medicine;
class Billing;


// Inheritance class
class Patient : public Person {
private:
	int patientID;
	string disease;
	Doctor* assignedDoctor;
	Nurse* assignedNurse;
	Room* assignedRoom;
	Billing* bill;
	vector<Medicine*> prescribedMedicines;

public:
	Patient(const string& name, int age, const string& gender, int patientID, const string& disease, Doctor* assignedDoctor, Nurse* assignedNurse, Room* assignedRoom, vector<Medicine*> prescribedMedicines, Billing* bill);
	void displayInfo() const override;

	void removeMedicine(const string& medicineName);

	int getPatientId() const;
	string getDisease() const;

	void setPatientId(int id);
	void setDisease(const string& d);

	void addMedicine(Medicine* medicine);

};

#endif