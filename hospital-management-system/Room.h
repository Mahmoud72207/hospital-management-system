#ifndef ROOM_H
#define ROOM_H

#include <iostream>
using namespace std;

class Patient;

class Room {
private:
	int roomNumber;
	string type; // Room type
	bool isOccupied; // Room is busy or not 
	Patient* assignedPatient;

public:
	Room(int roomNumber, const string& type);

	void displayInfo() const;

	void assignPatient(Patient* patient);
	void removePatient();

	int getRoomNumber() const;

	void setRoomNum(int roomNum);
	void setType(const string& t);

};


#endif