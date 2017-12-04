// File Name   : Menu.cpp
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#include "stdafx.h"
#include "Menu.h"

void Menu::displayMenu() const {
	cout << "Izaberite ";
}

void Menu::readStudents() {
	ifstream ifs;
	cout << "Ime datoteke: ";
	cin >> filename;
	cout << "Tip datoteke (txt ili bin): ";
	cin >> type;
	cout << "Putanja datoteke: ";
	cin >> path;

	try {
		if (!type.compare("txt")) {
			ifs.open(path + "\output" + filename + type);
		}
		else if (!type.compare("bin")) {
			ifs.open(path + "\output" + filename + type, ios::binary);
		}
	}
	catch (const std::exception&) {
		throw exception("Greska pri otvaranju fajla!");
	}

	try {

	}
	catch (const std::exception&) {
		cout << "Greska pri citanju iz fajla " << path << "\output" << filename << type << endl;
	}
	ifs >> gs;
	ifs.close();
}

void Menu::writeStudents() {
	ofstream ofs;

	try {
		if (!type.compare("txt")) {
			ofs.open(path + "\output" + filename + type);
		}
		else if (!type.compare("bin")) {
			ofs.open(path + "\output" + filename + type, ios::binary);
		}
	}
	catch (const std::exception&) {
		throw exception("Greska pri otvaranju fajla!");
	}

	ofs << gs;
	ofs.close();

	try {
		if (!type.compare("bin")) {
			ofs.open(path + "\output" + filename + ".txt");
		}
	}
	catch (const std::exception&) {
		throw exception("Greska pri otvaranju fajla!");
	}

	ofs << gs;
	ofs.close();
}