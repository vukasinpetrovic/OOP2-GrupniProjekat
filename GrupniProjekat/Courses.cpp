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
	float hwScore = 0;
	float quizScore = 0;
	float testScore = 0;

	for (int i = 0; i < NUM_HW; i++) {
		hwScore += homework.at(i);
	}
	hwScore *= HOMEWORK_WEIGHT;

	for (int i = 0; i < NUM_QUIZZES; i++) {
		quizScore += quiz.at(i);
	}
	quizScore *= QUIZ_WEIGHT;

	for (int i = 0; i < NUM_TESTS; i++) {
		testScore += test.at(i);
	}
	testScore *= TEST_WEIGHT;

	finalScore = hwScore + quizScore + testScore;
}

void Courses::calcLetterGrade() {
	if (finalScore > 85) letterGrade = 'A';
	else if (finalScore > 75) letterGrade = 'B';
	else if (finalScore > 65) letterGrade = 'C';
	else if (finalScore > 55) letterGrade = 'D';
	else letterGrade = 'F';
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
		if (ifs.bad())
			throw invalid_argument("Invalid argument!");
	}
	for (int i = 0; i < cs.NUM_TESTS; i++) {
		ifs >> cs.test[i];
		if (ifs.bad())
			throw invalid_argument("Invalid argument!");
	}
	for (int i = 0; i < cs.NUM_QUIZZES; i++) {
		ifs >> cs.quiz[i];
		if (ifs.bad())
			throw invalid_argument("Invalid argument!");
	}
	return ifs;
}