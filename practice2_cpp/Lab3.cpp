
// ������������ ������ 3. ���������. �������� ���������� � ������� �� ���������. ���������� ����������� �������. ���������

#include <iostream>

using namespace std;

class Lab3 {
public:
	//������ 1.
	void value(int* a, int* b) {
		cout << " ������� �������� a � b..." << endl;
		cout << " �������� a �����: ";
		cin >> *a;
		cout << " �������� b �����: ";
		cin >> *b;
	}

	int raschet(int* a, int* b, int* zn1, int* zn2) {
		*zn1 = pow(*a, *b);
		*zn2 = pow(*b, *a);
		cout << " �����..." << endl;
		cout << " �������� a^b �����: " << *zn1 << endl;
		cout << " �������� b^a �����: " << *zn2;
		return *zn1, *zn2;
	}

	void Task1() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 1." << endl << endl;
		int a, b;
		int zn1, zn2;
		value(&a, &b);
		raschet(&a, &b, &zn1, &zn2);
		cout << endl << endl;
	}

	//������ 2.
	void Input(int arr[], int size) {
		cout << "������� " << size << " ���������... ";
		cout << endl << endl;
		for (int i = 0; i < size; i++) {
			cout << "�������[" << i + 1 << "]= ";
			cin >> arr[i];
		}
	}

	void Show(int arr[], int size) {
		cout << endl;
		cout << "�������� ������: ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << "  ";
	}

	void Func(int arr[], int size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] > 0) arr[i] = arr[i] * arr[i];
		}
		cout << endl;
		cout << "��������������� ������: ";
		for (int i = 0; i < size; i++) cout << arr[i] << "  ";
	}

	void Task2() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 2." << endl << endl;
		const int SIZE = 10;
		int A[SIZE];
		Input(A, SIZE);
		Show(A, SIZE);
		Func(A, SIZE);
		cout << endl << endl;
	}

	//������ 3.
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
		cout << "������ �������:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				M[i][j] = rand() % 100;
				cout << "\t" << M[i][j];
			}
		}
		cout << endl << endl;
		cout << "������ �������:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				N[i][j] = rand() % 100;
				cout << "\t" << N[i][j];
			}
		}
		cout << endl << endl;
		cout << "���������� �������..." << endl;
		cout << endl;
	}

	void Process(int** M, int** N, int** Res, int n, int m) {
		cout << "�������, ���������� ����� �������� ���� ����������: " << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				Res[i][j] = M[i][j] + N[i][j];
				cout << "\t" << Res[i][j];
			}
		}
	}

	void Task3() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 3." << endl << endl;
		srand(time(NULL));
		cout << "������� ����������� ������..." << endl << endl;
		int n, m;
		cout << "���������� ����� �������: ";
		cin >> n;
		cout << "���������� �������� �������: ";
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