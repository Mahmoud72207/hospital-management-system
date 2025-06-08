#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <vector>
using namespace std;

#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Medicine.h"
#include "Room.h"
#include "Billing.h"


class Hospital {
private:
	vector<Patient*> listOfPatients;
	vector<Doctor*> listOfDoctors;
	vector<Nurse*> listOfNurses;
	vector<Medicine*> listOfMedicines;
	vector<Room*> listOfRooms;
	vector<Billing*> listOfBills;

public:
	void addPatient(Patient* p);
	void deletePatient(int patientId);
	Patient* findPatient(int patientId) const;
	void updatePatient(int patientId);
	void displayPatient(int patientId) const;
	void removeMedicineFromPatient(int patientId, const string& medicineName) const;
	void displayAllPatients() const;

	void addDoctor(Doctor* d);
	void deleteDoctor(int doctorId);
	Doctor* findDoctor(int doctorId) const;
	void updateDoctor(int doctorId);
	void addPatientToPatientList(int doctorId, int patientId) const;
	void removePatientFromPatients(int doctorId, const string& patientName) const;
	void displayAllDoctors() const; 

	void addNurse(Nurse* n);
	void deleteNurse(int nurseId);
	Nurse* findNurse(int nurseId) const;
	void updateNurse(int nurseId);
	void addPatientToListNurse(int nurseId, int patientId) const;
	void removePatient(int nurseId, const string& patientName) const;
	void displayAllNurses() const;

	void addMedicine(Medicine* m);
	void deleteMedicine(int medicineId);
	Medicine* findMedicine(int medicineId) const;
	void updateMedicine(int medicineId);
	void displayMedicine(int medicineId) const;
	void displayListMedicines() const;


	void addRoom(Room* r);
	void deleteRoom(int roomNumber);
	Room* findRoom(int roomNumber) const;
	void updateRoom(int roomNumber);
	void displayRoom(int roomId) const;
	void displayAllRooms() const;
	

	void addBill(Billing* b);
	void deleteBill(int b);
	Billing* findBill(int billId) const;
	void updateBill(int billId);
	void displayBill(int billId) const;
	void displayAllBills() const;

	~Hospital();

};

#endif