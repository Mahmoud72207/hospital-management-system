#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
using namespace std;

class Medicine {
private:
	int medicineId;
	string name;
	string dosage; // Information we give to patient about Quantity it can take
	int stockQuantity; // Quantity availability

public:
	Medicine(int id, const string& n, const string& d, int qty);
	void updateStock(int qty); // Update Quantity is(increase or decrease)
	void displayInfo() const;

	int getMedicineId() const;
	string getName() const;

	void setMedicineId(int id);
	void setMedicineName(const string& n);
	void setDosage(const string& d);
};


#endif