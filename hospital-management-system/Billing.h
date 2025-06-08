#ifndef	BILLING_H
#define BILLING_H

#include <iostream>
using namespace std;

class Patient;

class Billing {
private:
	int billId;
	Patient* patient;
	double amount;
	bool isPaid;

public:
	Billing(int id, Patient* p, double amt);

	void generateBill();
	void markAsPaid(); // Do billing it's paid
	void markNotPaid();

	int getBillId() const;

	void setBillId(int Id);
	void setAmount(double a);

	void displayInfo() const;

};

#endif