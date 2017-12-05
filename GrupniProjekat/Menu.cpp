// File Name   : Menu.cpp
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#include "stdafx.h"
#include "Menu.h"

Menu::Menu() {

}

GroupOfStudents& Menu::getGS() {
	return gs;
}

void Menu::displayMenu() const {
	cout << "Izaberite opciju iz menija: \n";
	cout << "[1] Prikazi osnovne informacije o autorima\n";
	cout << "[2] Ucitaj studente iz datoteke\n";
	cout << "[3] Prikazi informacije o studentu\n";
	cout << "[4] Prikazi studente sa najboljim prosekom\n";
	cout << "[5] Sortiraj\n";
	cout << "[6] Prikazi informacije o svim studentima\n";
	cout << "[7] Upisi u izlaznu datoteku\n";
	cout << "[8] Izlaz iz programa\n";
}

bool Menu::isIdValid(string id) const {
	bool isValid = true;
	int i = 0;
	for (i = 0; i < gs.getStudentCourses().size(); i++) {
		if (gs.getStudentCourses().at(i).getStudent().getId() == id) break;
	}
	if (i == gs.getStudentCourses().size()) isValid = false;
	return isValid;
}

void Menu::enterStudentID() const {
	string id;
	cout << "Unesite ID studenta: ";
	cin >> id;
	bool isValid = isIdValid(id);
	cout << isValid;
	if (isIdValid(id)) {
		for (int i = 0; i < gs.getStudentCourses().size(); i++) {
			if (!gs.getStudentCourses().at(i).getStudent().getId().compare(id))
				gs.getStudentCourses().at(i).getStudent().display();
		}
	}
	else {
		cout << "\nNiste uneli ispravan ID (ne postoji student sa datim ID-em)!";
	}
}

void Menu::displayInfo() const {
	cout << "Autori projekta:\n" << "Radojcin Milos SW56-2016\n" << "Petrovic Vukasin EE150-2016\n" << "Radovic Adam SW73-2016" << endl;
}

void Menu::displayStudents() const {
	for (int i = 0; i < gs.getStudentCourses().size(); i++) {
		gs.getStudentCourses().at(i).getStudent().display();
	}
}

void Menu::displayStudentsSorted() const {
	vector<StudentCourses> sorted = gs.sort();
	for (int i = 0; i < sorted.size(); i++) {
		sorted.at(i).getStudent().display();
	}
}

void Menu::displayHighestScore() const {
	cout << "Studenti sa najboljim prosekom:\n";
	gs.displayHighest();
}