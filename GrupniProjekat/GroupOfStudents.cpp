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
	mergeSort(stVec, 0, stVec.size() - 1, false);
	display();
}

void GroupOfStudents::displayHighest() const {
	vector<int> indexes;
	searchForHighest(indexes);
	for (int i = 0; i < indexes.size(); i++) {
		stVec.at(indexes.at(i)).getStudent().display();
	}
}

void GroupOfStudents::merge(vector<StudentCourses>& courses, int leftIndex, int middleIndex, int rightIndex, bool sortById) const {
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
	if (!sortById) {
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
					if (leftVector.at(i).getStudent().getId().compare(rightVector.at(j).getStudent().getId()) < 0)
					{
						courses.at(k) = leftVector.at(i);
						i++;
					}
					else if (leftVector.at(i).getStudent().getId().compare(rightVector.at(j).getStudent().getId()) > 0)
					{
						courses.at(k) = rightVector.at(j);
						j++;
					}
				}
			}
			k++;
		}
	}
	else {
		while (i < n1 && j < n2)
		{
			if (leftVector.at(i).getStudent().getId().compare(rightVector.at(j).getStudent().getId()) < 0)
			{
				courses.at(k) = leftVector.at(i);
				i++;
			}
			else if (leftVector.at(i).getStudent().getId().compare(rightVector.at(j).getStudent().getId()) > 0)
			{
				courses.at(k) = rightVector.at(j);
				j++;
			}
			k++;
		}
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

void GroupOfStudents::mergeSort(vector<StudentCourses>& courses, int leftIndex, int rightIndex, bool sortById) const {
	if (leftIndex < rightIndex)
	{
		int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

		mergeSort(courses, leftIndex, middleIndex, sortById);
		mergeSort(courses, middleIndex + 1, rightIndex, sortById);

		merge(courses, leftIndex, middleIndex, rightIndex, sortById);
	}
}

vector<StudentCourses> GroupOfStudents::sort(bool sortById) const {
	vector<StudentCourses> tmpVec;
	for (int i = 0; i < stVec.size(); i++) tmpVec.push_back(stVec.at(i));
	mergeSort(tmpVec, 0, tmpVec.size() - 1, sortById);
	return tmpVec;
}

void GroupOfStudents::readFile() {
	try {
		stVec.clear();
		vector<StudentCourses> tmpSC;

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
				tmpSC.push_back(sc);
			}
			else {
				cout << "Fajl nije ispravan!\n\n";
				tmpSC.clear();
				stVec.clear();
				ifs.close();
				return;
			}
		}
		ifs.close();

		while (tmpSC.size() != 0) {
			StudentCourses sc = tmpSC.at(0);
			double points = 0;
			int noOfCopies = 0;
			for (int i = tmpSC.size() - 1; i >= 0; i--) {
				StudentCourses sc2 = tmpSC.at(i);
				if (sc.getStudent().getFirstName() == sc2.getStudent().getFirstName()
					&& sc.getStudent().getLastName() == sc2.getStudent().getLastName()
					&& sc.getStudent().getId() == sc2.getStudent().getId()) {
					points += sc2.getFinalScore();
					noOfCopies += 1;
					tmpSC.erase(tmpSC.begin() + i);
				}
			}
			sc.getCourse().setScore(points / noOfCopies);
			stVec.push_back(sc);
		}

		cout << "Citanje datoteke uspesno zavrseno.\n";
	}
	catch (const std::exception&) {
		cout << "\nFajl nije ispravan!\n";
	}
}

void GroupOfStudents::writeToFile() const {
	if (stVec.size() == 0) {
		cout << "\nLista studenata je prazna.";
	}
	else {
		vector<StudentCourses> tmpVec;
		for (int i = 0; i < stVec.size(); i++) tmpVec.push_back(stVec.at(i));
		mergeSort(tmpVec, 0, tmpVec.size() - 1, true);

		ofstream ofs;

		if (!type.compare("txt"))
			ofs.open(path + "output." + type);
		else if (!type.compare("bin"))
			ofs.open(path + "output." + type, ios::binary);

		if (!ofs.is_open()) {
			cout << "Greska pri otvaranju fajla!";
			return;
		}

		for (StudentCourses sc : tmpVec) {
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

		for (StudentCourses sc : tmpVec) {
			ofs << sc;
		}
		ofs.close();
	}
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