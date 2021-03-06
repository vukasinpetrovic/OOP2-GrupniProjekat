// GrupniProjekat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Menu.h"


int main(int argc, char *argv[])
{
	if (argc == 4) {
		Menu menu;
		menu.getGS().setArguments(argv[1], argv[2], argv[3]);
		int opcija = 0;
		do {
			menu.displayMenu();
			cout << "Izabrana opcija: ";
			cin >> opcija;
			if (cin && opcija >= 1 && opcija <= 8) {
				switch (opcija) {
				case 1: menu.displayInfo(); break;
				case 2: menu.getGS().readFile(); break;
				case 3: menu.enterStudentID(); break;
				case 4: menu.displayHighestScore(); break;
				case 5: menu.displayStudentsSorted(); break;
				case 6: menu.displayStudents(); break;
				case 7: menu.getGS().writeToFile(); break;
				case 8: exit(0); break;
				}
			}
			else {
				cout << "\n Niste uneli dobru opciju!";
			}
			cout << "\n\n";
		} while (true);
	}
	else {
		cout << "Pogresan broj argumenata";
	}
    return 0;
}