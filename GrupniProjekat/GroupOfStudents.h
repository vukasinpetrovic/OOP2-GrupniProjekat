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
	string filename, type, path;

public:
	GroupOfStudents() {}
	GroupOfStudents(const vector< StudentCourses >& v);

	// add required methods
	const vector<StudentCourses>& getStudentCourses() const;
	void display();
	void displaySorted();
	void displayHighest() const;
	void merge(vector<StudentCourses>& courses, int leftIndex, int middleIndex, int rightIndex, bool sortById) const;
	void mergeSort(vector<StudentCourses>& courses, int leftIndex, int rightIndex, bool sortById) const;
	vector<StudentCourses> sort(bool sortById) const;
	void readFile();
	void writeToFile() const;
	void setArguments(string filename, string type, string path);

	friend ofstream& operator<< (ofstream& ofs, const GroupOfStudents& gs);
	friend ifstream& operator>> (ifstream& ifs, GroupOfStudents& gs);
};

#endif