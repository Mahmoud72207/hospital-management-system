#include "Medicine.h"


Medicine::Medicine(int id, const string& n, const string& d, int qty) : medicineId(id), name(n), dosage(d), stockQuantity(qty) {

}

void Medicine::updateStock(int qty) {
	stockQuantity += qty;
}

void Medicine::displayInfo() const {
	cout << "\n--- Information About Medicine ---\n";
	cout << "Name: " << name << "\n"
		<< "Dosage: " << dosage << "\n"
		<< "Stock: " << stockQuantity << "\n";
}


string Medicine::getName() const {
	return name;
}

int Medicine::getMedicineId() const {
	return medicineId;
}

void Medicine::setMedicineId(int id) {
	medicineId = id;
}

void Medicine::setMedicineName(const string& n) {
	name = n;
}

void Medicine::setDosage(const string& d) {
	dosage = d;
}



