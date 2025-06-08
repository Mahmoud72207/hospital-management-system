#include "Person.h"

Person::Person(const string& name, int age, const string& gender) {
	this->name = name;
	this->age = age;
	this->gender = gender;
}

string Person::getName() const {
	return name;
}
void Person::setName(const string& n) {
	name = n;
}

int Person::getAge() const {
	return age;
}
void Person::setAge(int a) {
	age = a;
}

string Person::getGender() const {
	return gender;
}
void Person::setGender(const string& g) {
	gender = g;
}
