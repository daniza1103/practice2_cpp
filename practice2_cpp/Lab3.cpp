
// Лабораторная работа 3. Указатели. Передача параметров в функцию по указателю. Сортировка одномерного массива. Структуры

#include <iostream>

using namespace std;

class Lab3 {
public:
	//Задача 1.
	void value(int* a, int* b) {
		cout << " Введите значения a и b..." << endl;
		cout << " Значение a равно: ";
		cin >> *a;
		cout << " Значение b равно: ";
		cin >> *b;
	}

	int raschet(int* a, int* b, int* zn1, int* zn2) {
		*zn1 = pow(*a, *b);
		*zn2 = pow(*b, *a);
		cout << " Тогда..." << endl;
		cout << " Значение a^b равно: " << *zn1 << endl;
		cout << " Значение b^a равно: " << *zn2;
		return *zn1, *zn2;
	}

	void Task1() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 1." << endl << endl;
		int a, b;
		int zn1, zn2;
		value(&a, &b);
		raschet(&a, &b, &zn1, &zn2);
		cout << endl << endl;
	}

	//Задача 2.
	void Input(int arr[], int size) {
		cout << "Введите " << size << " элементов... ";
		cout << endl << endl;
		for (int i = 0; i < size; i++) {
			cout << "Элемент[" << i + 1 << "]= ";
			cin >> arr[i];
		}
	}

	void Show(int arr[], int size) {
		cout << endl;
		cout << "Исходный массив: ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << "  ";
	}

	void Func(int arr[], int size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] > 0) arr[i] = arr[i] * arr[i];
		}
		cout << endl;
		cout << "Преобразованный массив: ";
		for (int i = 0; i < size; i++) cout << arr[i] << "  ";
	}

	void Task2() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 2." << endl << endl;
		const int SIZE = 10;
		int A[SIZE];
		Input(A, SIZE);
		Show(A, SIZE);
		Func(A, SIZE);
		cout << endl << endl;
	}

	//Задача 3.
	int** Create(int n, int m) {
		int** M = new int* [n];
		int** N = new int* [n];
		for (int i = 0; i < n; i++) {
			M[i] = new int[m];
			N[i] = new int[m];
		}
		return M, N;
	}

	void Input(int** M, int** N, int n, int m) {
		cout << "Первая матрица:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				M[i][j] = rand() % 100;
				cout << "\t" << M[i][j];
			}
		}
		cout << endl << endl;
		cout << "Вторая матрица:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				N[i][j] = rand() % 100;
				cout << "\t" << N[i][j];
			}
		}
		cout << endl << endl;
		cout << "Складываем матрицы..." << endl;
		cout << endl;
	}

	void Process(int** M, int** N, int** Res, int n, int m) {
		cout << "Матрица, полученная после сложения двух предыдущих: " << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				Res[i][j] = M[i][j] + N[i][j];
				cout << "\t" << Res[i][j];
			}
		}
	}

	void Task3() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 3." << endl << endl;
		srand(time(NULL));
		cout << "Введите размерности матриц..." << endl << endl;
		int n, m;
		cout << "Количество строк матрицы: ";
		cin >> n;
		cout << "Количество столбцов матрицы: ";
		cin >> m;
		cout << endl;

		int** A = Create(n, m);
		int** B = Create(n, m);
		int** C = Create(n, m);

		Input(A, B, n, m);
		Process(A, B, C, n, m);
		cout << endl << endl;
	}
};