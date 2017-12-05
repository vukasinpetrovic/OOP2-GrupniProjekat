#pragma once

// File Name   : StudentCourses.h
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#ifndef _STUDENTCOURSES_H_
#define _STUDENTCOURSES_H_

#include "Student.h"
#include "Courses.h"
#include <iostream>
#include <fstream>

class StudentCourses {
	Student student;
	Courses course;
public:

	Student getStudent() const;
	Courses getCourseConst() const;
	Courses& getCourse();
	double getFinalScore() const;
	void display();

	friend ofstream& operator<< (ofstream& ofs, const StudentCourses& st);
	friend ifstream& operator>> (ifstream& ifs, StudentCourses& st);
};

#endif