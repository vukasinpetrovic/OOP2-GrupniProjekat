#pragma once

// File Name   : GroupOfStudents.h
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#ifndef GROUPOFSTUDENTS_H_
#define GROUPOFSTUDENTS_H_

#include <vector>
#include "StudentCourses.h"

using std::vector;

class GroupOfStudents {
private:
	vector<StudentCourses> stVec;
	void searchForHighest(vector<int>& indices_max) const; // utility

public:
	GroupOfStudents() {}
	GroupOfStudents(const vector< StudentCourses >& v);

	// add required methods
	const vector<StudentCourses>& getStudentCourses() const;
	void display();
	void displaySorted();
	void displayHighest();
	void writeToFile();
};

#endif