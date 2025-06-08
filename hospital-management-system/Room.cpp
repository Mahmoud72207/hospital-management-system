
#include "Room.h"
#include "Patient.h"

Room::Room(int roomNumber, const string& type) : roomNumber(roomNumber), type(type) , isOccupied(false), assignedPatient(nullptr) {}

void Room::displayInfo() const {
	cout << "\n--- Information About Room ---\n";
	cout << "Room Number: " << roomNumber << "\n"
		<< "Room Type: " << type << "\n"
		<< "Status: " << (isOccupied ? "Busy" : "Not Busy") << "\n"
		<< "Assigned Patient: " << (assignedPatient ? assignedPatient->getName() : "None") << "\n";
}

void Room::assignPatient(Patient* patient) {
	if (!isOccupied) {
		assignedPatient = patient;
		isOccupied = true;
	}
	else {
		cout << "Room is already occupied.\n";
	}
}

void Room::removePatient() {
	assignedPatient = nullptr;
	isOccupied = false;
}

int Room::getRoomNumber() const {
	return roomNumber;
}

void Room::setRoomNum(int roomNum) {
	roomNumber = roomNum;
}

void Room::setType(const string& t) {
	type = t;
}