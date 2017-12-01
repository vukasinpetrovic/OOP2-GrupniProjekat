#pragma once

// File Name   : StudentCoursesManager.h
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#ifndef STUDENTCOURSESMANAGER_H_
#define STUDENTCOURSESMANAGER_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "GroupOfStudents.h"

using namespace std;

class StudentCoursesManager {
	GroupOfStudents gs;

public:
	StudentCoursesManager();
	void loadFile();
	vector<StudentCourses> getStudentCourses();
};

#endif