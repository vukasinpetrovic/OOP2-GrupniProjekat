// File Name   : Courses.cpp
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include "Courses.h"

using namespace std;

void Courses::display() const {
	cout << "Konacan broj bodova: " << finalScore << ", ocena: " << letterGrade << endl;
}

void Courses::calcFinalScore() {

}
void Courses::calcLetterGrade() {

}

double Courses::getFinalScore() const {
	return finalScore;
}

ofstream& operator<< (ofstream& ofs, const Courses& cs) {
	ofs << cs.finalScore << " " << cs.letterGrade << endl;
	return ofs;
}

ifstream& operator>> (ifstream& ifs, Courses& cs) {
	for (int i = 0; i < cs.NUM_HW; i++) {
		ifs >> cs.homework[i];
	}
	for (int i = 0; i < cs.NUM_TESTS; i++) {
		ifs >> cs.test[i];
	}
	for (int i = 0; i < cs.NUM_QUIZZES; i++) {
		ifs >> cs.quiz[i];
	}
	return ifs;
}