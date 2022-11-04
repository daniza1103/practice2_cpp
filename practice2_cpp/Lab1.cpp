
// Лабораторная работа 1. Управляющие структуры языка С++

#include <iostream>

using namespace std;

class Lab1 {
public:
	//Задача 1.
	void Task1() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 1." << endl << endl;
		const float pi = 3.14;

		int storona1 = 10;
		cout << " Первая известная сторона треугольника равна: " << storona1 << "см.";
		cout << endl;

		int storona2 = 15;
		cout << " Вторая известная сторона треугольника равна: " << storona2 << "см.";
		cout << endl;

		float ugol = pi / 3;
		cout << " Угол в радианах равен: П/3.";
		cout << endl;

		float storona3 = sqrt((storona1 * storona1) + (storona2 * storona2) - (2 * storona1 * storona2 * cos(ugol)));
		cout.precision(3);
		cout << " Вычисляя неизвестную сторону треугольника по теореме косинусов, находим, что она равна: " << storona3 << "см.";
		cout << endl << endl;
	}

	//Задача 2.
	void Task2() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 2." << endl << endl;
		int d, i;
		cout << " Введите день недели:";
		cin >> d;
		for (i = 1; i < 7; i++)
			if ((d < 1) || (d > 7)) cout << " Такого дня не существует!";
				if ((d > 0) && (d < 6)) cout << " Это рабочий день!";
				if (d == 6) cout << " Это суббота!";
				if (d == 7) cout << " Это воскресенье!";
		cout << endl << endl;
	}

	//Задача 3.
	int NOD(int n, int m) {
		int div;
		if (n == m)  return n;
		int d = n - m;
		if (d < 0) {
			d = -d;  div = NOD(n, d);
		}
		else div = NOD(m, d);
		return div;
	}

	int NOK(int n, int m) {
		return n * m / NOD(n, m);
	}

	void Task3() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 3." << endl << endl;
		int n, m, k = 0;

		cout << " Введите n: ";
		cin >> n;
		cout << " Введите m: ";
		cin >> m;

		cout << " НОК равен: " << NOK(n, m);
		cout << endl;
		cout << " НОД равен: " << NOD(n, m);
		cout << endl;

		k = NOK(n, m) - NOD(n, m);
		cout << " Разность НОК и НОД равна: " << k;
		cout << endl << endl;
	}
};