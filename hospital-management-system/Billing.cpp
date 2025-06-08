#include "Billing.h"
#include "Patient.h"

Billing::Billing(int id, Patient* p, double amt) : billId(id), patient(p), amount(amt), isPaid(false) {

}

void Billing::generateBill() {
	cout << "Generated bill of " << amount << " for patient." << endl;
}

void Billing::markAsPaid() {
	isPaid = true;
}
void Billing::markNotPaid() {
	isPaid = false;
}

int Billing::getBillId() const {
	return billId;
}

void Billing::setBillId(int id) {
	billId = id;
}

void Billing::setAmount(double a) {
	amount = a;
}

void Billing::displayInfo() const {
	cout << "\n--- Display Bill ---\n";
	cout << "Bill Id: " << billId
		<< " ,Price Bill: " << amount
		<< " ,Patient Name: " << (patient ? patient->getName() : "None")
		<< " ,Bill Is Paid: " << (isPaid ? "Yes" : "No") << endl;
}