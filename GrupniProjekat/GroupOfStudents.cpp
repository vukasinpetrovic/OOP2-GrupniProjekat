// File Name   : GroupOfStudents.cpp
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#include "stdafx.h"
#include "GroupOfStudents.h"

GroupOfStudents::GroupOfStudents(const vector< StudentCourses >& v) {
	this->stVec = v;
}

ofstream& operator<< (ofstream& ofs, const GroupOfStudents& gs) {
	for(StudentCourses sc : gs.stVec) {
		ofs << sc;
	}

	return ofs;
}

ifstream& operator>> (ifstream& ifs, GroupOfStudents& gs) {
	while (!ifs.eof()) {
		StudentCourses sc;
		try {
			ifs >> sc;
			gs.stVec.push_back(sc);
		}
		catch (const std::exception&) {
			throw invalid_argument("Invalid argument!");
		}
	}

	return ifs;
}