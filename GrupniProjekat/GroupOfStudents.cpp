// File Name   : GroupOfStudents.cpp
// Authors     : Radojcin Milos, Petrovic Vukasin, Radovic Adam
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project

#include "stdafx.h"
#include "GroupOfStudents.h"

using namespace std;

GroupOfStudents::GroupOfStudents(const vector< StudentCourses >& v) {
	this->stVec = v;
}

void GroupOfStudents::setArguments(string filename, string type, string path) {
	this->filename = filename;
	this->type = type;
	this->path = path;
}

void GroupOfStudents::searchForHighest(vector<int>& indices_max) const {
	float max = 0;
	for (int i = 0; i < stVec.size(); i++) {
		if (stVec.at(i).getFinalScore() > max) max = stVec.at(i).getFinalScore();
	}
	for (int i = 0; i < stVec.size(); i++) {
		if (stVec.at(i).getFinalScore() == max) {
			indices_max.push_back(i);
		}
	}
}

const vector<StudentCourses>& GroupOfStudents::getStudentCourses() const {
	return stVec;
}

void GroupOfStudents::display() {
	for (int i = 0; i < stVec.size(); i++) {
		stVec.at(i).display();
	}
}

void GroupOfStudents::displaySorted() {
	mergeSort(stVec, 0, stVec.size() - 1);
	display();
}

void GroupOfStudents::displayHighest() const {
	vector<int> indexes;
	searchForHighest(indexes);
	for (int i = 0; i < indexes.size(); i++) {
		stVec.at(indexes.at(i)).getStudent().display();
	}
}

void GroupOfStudents::merge(vector<StudentCourses>& courses, int leftIndex, int middleIndex, int rightIndex) const {
	int i, j, k;
	int n1 = middleIndex - leftIndex + 1;
	int n2 = rightIndex - middleIndex;

	vector<StudentCourses> leftVector;
	vector<StudentCourses> rightVector;

	for (i = 0; i < n1; i++)
		leftVector.push_back(courses.at(leftIndex + i));
	for (j = 0; j < n2; j++)
		rightVector.push_back(courses.at(middleIndex + 1 + j));

	i = 0; // Initial index of first subvector
	j = 0; // Initial index of second subvector
	k = leftIndex; // Initial index of merged subvector
	while (i < n1 && j < n2)
	{
		if (leftVector.at(i).getStudent().getLastName().compare(rightVector.at(j).getStudent().getLastName()) < 0)
		{
			courses.at(k) = leftVector.at(i);
			i++;
		}
		else if (leftVector.at(i).getStudent().getLastName().compare(rightVector.at(j).getStudent().getLastName()) > 0)
		{
			courses.at(k) = rightVector.at(j);
			j++;
		}
		else 
		{
			if (leftVector.at(i).getStudent().getFirstName().compare(rightVector.at(j).getStudent().getFirstName()) < 0)
			{
				courses.at(k) = leftVector.at(i);
				i++;
			}
			else if (leftVector.at(i).getStudent().getFirstName().compare(rightVector.at(j).getStudent().getFirstName()) > 0)
			{
				courses.at(k) = rightVector.at(j);
				j++;
			}
			else
			{
				if (leftVector.at(i).getStudent().getId() <= rightVector.at(j).getStudent().getId())
				{
					courses.at(k) = leftVector.at(i);
					i++;
				}
				else
				{
					courses.at(k) = rightVector.at(j);
					j++;
				}
			}
		}
		k++;
	}

	while (i < n1)
	{
		courses.at(k) = leftVector.at(i);
		i++;
		k++;
	}

	while (j < n2)
	{
		courses.at(k) = rightVector.at(j);
		j++;
		k++;
	}
}

void GroupOfStudents::mergeSort(vector<StudentCourses>& courses, int leftIndex, int rightIndex) const {
	if (leftIndex < rightIndex)
	{
		int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

		mergeSort(courses, leftIndex, middleIndex);
		mergeSort(courses, middleIndex + 1, rightIndex);

		merge(courses, leftIndex, middleIndex, rightIndex);
	}
}

vector<StudentCourses> GroupOfStudents::sort() const {
	vector<StudentCourses> tmpVec;
	for (int i = 0; i < stVec.size(); i++) tmpVec.push_back(stVec.at(i));
	mergeSort(tmpVec, 0, tmpVec.size() - 1);
	return tmpVec;
}

void GroupOfStudents::readFile() {
	stVec.clear();

	ifstream ifs;

	if (!type.compare("txt"))
		ifs.open(filename + "." + type);
	else if (!type.compare("bin"))
		ifs.open(filename + "." + type, ios::binary);

	if (!ifs.is_open()) {
		cerr << "Greska pri otvaranju fajla!";
		return;
	}

	while (!ifs.eof()) {
		StudentCourses sc;
		ifs >> sc;

		if (!ifs.fail()) {
			sc.getCourse().calcFinalScore();
			sc.getCourse().calcLetterGrade();
			sc.display();
			stVec.push_back(sc);
		}
		else {
			cout << "Fajl nije ispravan!\n\n";
			stVec.clear();
			ifs.close();
			return;
		}
	}
	ifs.close();

	cout << "Citanje datoteke uspesno zavrseno.\n";
}

void GroupOfStudents::writeToFile() const {
	ofstream ofs;

	if (!type.compare("txt"))
		ofs.open(path + "output." + type);
	else if (!type.compare("bin"))
		ofs.open(path + "output." + type, ios::binary);

	if (!ofs.is_open()) {
		cout << "Greska pri otvaranju fajla!";
		return;
	}

	for (StudentCourses sc : stVec) {
		ofs << sc;
	}
	ofs.close();

	if (!type.compare("bin")) {
		ofs.open(path + "output.txt");
		if (!ofs.is_open()) {
			cout << "Greska pri otvaranju fajla!";
			return;
		}
	}

	for (StudentCourses sc : stVec) {
		ofs << sc;
	}
	ofs.close();
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