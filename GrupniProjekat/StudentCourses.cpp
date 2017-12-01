// File Name   : StudentCourses.cpp
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#include "stdafx.h"
#include "StudentCourses.h"
#include <iostream>
#include <fstream>

using namespace std;

Student StudentCourses::getStudent() const {
	return student;
}

Courses StudentCourses::getCourse() const {
	return course;
}

double StudentCourses::getFinalScore() const {
	return course.getFinalScore();
}

void StudentCourses::display() {
	cout << student;
	course.display();
}

ofstream& operator<< (ofstream& ofs, const StudentCourses& sc) {
	ofs << sc.student << sc.course;
	return ofs;
}

ifstream& operator>> (ifstream& ifs, StudentCourses& sc) {
	ifs >> sc.student >> sc.course;
	return ifs;
}