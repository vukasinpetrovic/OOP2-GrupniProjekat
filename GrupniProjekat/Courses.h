#pragma once

// File Name   : Courses.h
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#ifndef COURSES_H_
#define COURSES_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Courses {
public:
	static const int NUM_QUIZZES = 10;
	static const int NUM_HW = 6;
	static const int NUM_TESTS = 4;

private:
	// this will not compile
	// non-integral constants must be initialized in Courses.cpp
	// with these values 0.05, 0.5, 0.45
	static const double QUIZ_WEIGHT;
	static const double HOMEWORK_WEIGHT;
	static const double TEST_WEIGHT;

	// private data
	vector<int> quiz;
	vector<int> homework;
	vector<int> test;
	double finalScore;
	char letterGrade;

public:
	// constructors
	Courses() : quiz(NUM_QUIZZES), homework(NUM_HW), test(NUM_TESTS) {}
	Courses(const vector<int>& q, const vector<int>& h, const vector<int>& t)
		: quiz(q), homework(h), test(t), finalScore(0), letterGrade('F') {}

	// utility functions
	void display() const;
	void calcFinalScore();
	void calcLetterGrade();
	double getFinalScore() const;

	friend ofstream& operator<< (ofstream& ofs, const Courses& cs);
	friend ifstream& operator>> (ifstream& ifs, Courses& st);
};
#endif