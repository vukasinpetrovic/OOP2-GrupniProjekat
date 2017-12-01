// File Name   : StudentCoursesManager.cpp
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#include "stdafx.h"
#include "StudentCoursesManager.h"
#include "StudentCourses.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

StudentCoursesManager::StudentCoursesManager() {}

void StudentCoursesManager::loadFile() {
	string filename, type;
	ifstream ifs;
	cout << "Ime datoteke: ";
	cin >> filename;
	cout << "Tip datoteke (txt ili bin): ";
	cin >> type;

	try {
		if (!type.compare("txt")) {
			ifs.open(filename);
		}
		else if (!type.compare("bin")) {
			ifs.open(filename, ios::binary);
		}
	}
	catch (const std::exception&) {
		cout << "Greska pri otvaranju fajla!";
	}

	while (ifs.good()) {
		StudentCourses sc;
		ifs >> sc;
		if (ifs.good()) {
			studentCourses.push_back(sc);
		}
	}
}

vector<StudentCourses> StudentCoursesManager::getStudentCourses() {
	return studentCourses;
}