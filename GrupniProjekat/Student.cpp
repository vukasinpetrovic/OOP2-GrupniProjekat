// File Name   : Student.cpp
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"

using std::string;
using namespace std;

Student::Student() {
	this->firstName = "";
	this->lastName = "";
	this->ID = "";
}

Student::Student(string firstName, string lastName, string ID) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->ID = ID;
}

string Student::getFirstName() const {
	return firstName;
}

string Student::getLastName() const {
	return lastName;
}

string Student::getId() const {
	return ID;
}

void Student::display() const {
	cout << ID << "\t" << firstName << "\t" << lastName << endl;
}

ostream& operator<< (ostream& os, const Student& st) {
	os << st.ID << " " << st.firstName << " " << st.lastName << endl;
	return os;
}

ofstream& operator<< (ofstream& ofs, const Student& st) {
	ofs << st.ID << " " << st.firstName << " " << st.lastName << " ";
	return ofs;
}

ifstream& operator>> (ifstream& ifs, Student& st) {
	ifs >> st.firstName >> st.lastName >> st.ID;
	if(ifs.bad())
		throw invalid_argument("Invalid argument!");
	return ifs;
}