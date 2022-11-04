#include <iostream>
#include "Lab1.cpp"
#include "Lab2.cpp"
#include "Lab3.cpp"
#include "Lab4.cpp"
#include "Lab5.cpp"
#include "Lab6.cpp"
#include "Lab7.cpp"

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	int lab_number, task_number;
	cout << " Введите номер лабораторной работы: ";
	cin >> lab_number;
	cout << " Введите номер задачи: ";
	cin >> task_number;
	cout << endl;

	Lab1 obj1;
	Lab2 obj2;
	Lab3 obj3;
	Lab4 obj4;
	Lab5 obj5;
	Lab6 obj6;
	Lab7 obj7;
			
	if (lab_number == 1) {
		if (task_number == 1) {
			obj1.Task1();
		}
		else if (task_number == 2) {
			obj1.Task2();
		}
		else if (task_number == 3) {
			obj1.Task3();
		}
		else {
			cout << " Такой задачи нет!" << endl << endl;
		}
	}
	else if (lab_number == 2) {
		if (task_number == 1) {
			obj2.Task1();
		}
		else if (task_number == 2) {
			obj2.Task2();
		}
		else if (task_number == 3) {
			obj2.Task3();
		}
		else {
			cout << " Такой задачи нет!" << endl << endl;
		}
	}
	else if (lab_number == 3) {
		if (task_number == 1) {
			obj3.Task1();
		}
		else if (task_number == 2) {
			obj3.Task2();
		}
		else if (task_number == 3) {
			obj3.Task3();
		}
		else {
			cout << " Такой задачи нет!" << endl << endl;
		}
	}
	else if (lab_number == 4) {
		if (task_number == 1) {
			obj4.Task1();
		}
		else if (task_number == 2) {
			obj4.Task2();
		}
		else if (task_number == 3) {
			obj4.Task3();
		}
		else {
			cout << " Такой задачи нет!" << endl << endl;
		}
	}
	else if (lab_number == 5) {
		if (task_number == 1) {
			obj5.Task();
		}
	}
	else if (lab_number == 6) {
		if (task_number == 1) {
			obj6.Task();
		}
	}
	else if (lab_number == 7) {
		if (task_number == 1) {
			obj7.Task();
		}
	}
	else {
		cout << " Такой лабораторной работы нет!" << endl << endl;
	}	

	system("PAUSE");
	return 0;
}
