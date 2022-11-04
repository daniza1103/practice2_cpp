
// Лабораторная работа 2. Функции

#include <iostream>

using namespace std;

class Lab2 {
public:
	//Задача 1.
	int Sum(int a, int y) {
		int s = pow(a, y);
		return s;
	}

	void Task1() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 1." << endl << endl;
		int a, y;
		cout << " Введите значение а: "; 
		cin >> a;
		cout << " Введите значение y: "; 
		cin >> y;

		if ((a == 0) && (y == 0)) cout << "Выражение 'ноль в нулевой степени' не имеет смысла! Введите значения заново!" << endl;
		else cout << "Значение а в степени у равно: " << Sum(a, y);
		cout << endl << endl;
	}

	//Задача 2.
	#define V1(x) (x*x*x) 
	#define V2(pi, r, h) (pi*r*r*h)
	#define V3(v2, v1) (v2-v1)

	void Task2() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 2." << endl << endl;
		int x;
		cout << "Сторона куба равна: ";
		cin >> x;
		int v1 = V1(x);
		cout << "Тогда объем этого куба равен: " << v1;
		cout << endl << endl;

		float const pi = 3.14;
		int r, h;
		cout << "Радиус цилиндра равен: ";
		cin >> r;
		cout << "Высота цилиндра равна: ";
		cin >> h;

		float v2 = V2(pi, r, h);
		cout << "Тогда объем этого цилиндра равен: " << v2;
		cout << endl << endl;
		cout << "Теперь вычислим объем цилиндра с кубической полостью, т.е. вычтем из объема цилиндра объем куба" << "." << endl;

		float main(float v2, float v1);
		float v3 = V3(v2, v1);
		cout << "Объем цилиндра с кубической полостью равен: " << v3;
		cout << endl << endl;
	}

	//Задача 3.
	double sum_N(int N) {
		if (N == 0) return 1;
		else return sum_N(N - 1) + pow(2, -N);
	}

	void Task3() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 3." << endl << endl;
		int    N = 20;
		double s_N = 0.0;
		for (int k = 0; k <= N; ++k) {
			s_N += pow(2, -k);
		}
		cout << "Частичная сумма ряда, полученная при помощи итерационного цикла: " << 2.0 / 3 * s_N << endl;
		cout << endl;
		cout << "Частичная сумма ряда, полученная при помощи рекуррентной формулы: " << 2.0 / 3 * sum_N(N);
		cout << endl << endl;
	}
};