#pragma once

// File Name   : Menu.h
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <stdexcept>
#include "GroupOfStudents.h"

using std::string;

class Menu {
public:
	struct InvalidData : std::runtime_error {
		InvalidData() : runtime_error("Invalid input data format") {}
	};

	struct InvalidFile : std::runtime_error {
		InvalidFile() : runtime_error("Invalid input file name") {}
	};

	enum OPTIONS { INFO = 1, READ_FILE, DISPLAY, DISPLAY_SORTED, HIGHEST, EXIT };

private:
	GroupOfStudents gs;
	string filename, type, path;
public:
	Menu();

	bool isIdValid(string id) const;
	void displayMenu() const;
	void displayInfo() const;
	void displayStudents() const;
	void displayStudentsSorted() const;
	void displayHighestScore() const;
};

#endif