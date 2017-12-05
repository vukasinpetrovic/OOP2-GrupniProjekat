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

static const double QUIZ_WEIGHT = 0.05;
static const double HOMEWORK_WEIGHT = 0.5;
static const double TEST_WEIGHT = 0.45;

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
	hwScore /= NUM_HW;
	hwScore *= HOMEWORK_WEIGHT;

	for (int i = 0; i < NUM_QUIZZES; i++) {
		quizScore += quiz.at(i);
	}
	quizScore /= NUM_QUIZZES;
	quizScore *= QUIZ_WEIGHT;

	for (int i = 0; i < NUM_TESTS; i++) {
		testScore += test.at(i);
	}
	testScore /= NUM_TESTS;
	testScore *= TEST_WEIGHT;

	finalScore = hwScore + quizScore + testScore;
}

void Courses::calcLetterGrade() {
	//cout << "\nFinal score = " << finalScore;
	if (finalScore >= 85) letterGrade = 'A';
	else if (finalScore >= 75) letterGrade = 'B';
	else if (finalScore >= 65) letterGrade = 'C';
	else if (finalScore >= 55) letterGrade = 'D';
	else letterGrade = 'F';
	//cout << " Letter grade = " << letterGrade;
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