#pragma once

// File Name   : Student.h
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using namespace std;

class Student {
private:
	string firstName, lastName, ID;

public:
	Student();
	Student(string firstName, string lastName, string ID);

	string getFirstName() const;
	string getLastName() const;
	string getId() const;
	void display() const;

	friend ostream& operator<< (ostream& ofs, const Student& st);
	friend ofstream& operator<< (ofstream& ofs, const Student& st);
	friend ifstream& operator>> (ifstream& ifs, Student& st);
};

#endif