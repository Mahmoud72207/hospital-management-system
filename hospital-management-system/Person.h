
#ifndef PERSON_H
#define PERSON_H


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class -> Abstract class
class Person {   
protected:
	string name;
	int age;
	string gender;

public:
	Person(const string& name, int age, const string& gender);

	virtual ~Person() {} // Virtual destructor to ensure proper cleanup of derived classes

	virtual void displayInfo() const = 0; // Pure virtual function to use after 
	

	string getName() const;
	void setName(const string& n);

	int getAge() const;
	void setAge(int a);

	string getGender() const;
	void setGender(const string& g);
};

#endif 