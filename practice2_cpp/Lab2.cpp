
// ������������ ������ 2. �������

#include <iostream>

using namespace std;

class Lab2 {
public:
	//������ 1.
	int Sum(int a, int y) {
		int s = pow(a, y);
		return s;
	}

	void Task1() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 1." << endl << endl;
		int a, y;
		cout << " ������� �������� �: "; 
		cin >> a;
		cout << " ������� �������� y: "; 
		cin >> y;

		if ((a == 0) && (y == 0)) cout << "��������� '���� � ������� �������' �� ����� ������! ������� �������� ������!" << endl;
		else cout << "�������� � � ������� � �����: " << Sum(a, y);
		cout << endl << endl;
	}

	//������ 2.
	#define V1(x) (x*x*x) 
	#define V2(pi, r, h) (pi*r*r*h)
	#define V3(v2, v1) (v2-v1)

	void Task2() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 2." << endl << endl;
		int x;
		cout << "������� ���� �����: ";
		cin >> x;
		int v1 = V1(x);
		cout << "����� ����� ����� ���� �����: " << v1;
		cout << endl << endl;

		float const pi = 3.14;
		int r, h;
		cout << "������ �������� �����: ";
		cin >> r;
		cout << "������ �������� �����: ";
		cin >> h;

		float v2 = V2(pi, r, h);
		cout << "����� ����� ����� �������� �����: " << v2;
		cout << endl << endl;
		cout << "������ �������� ����� �������� � ���������� ��������, �.�. ������ �� ������ �������� ����� ����" << "." << endl;

		float main(float v2, float v1);
		float v3 = V3(v2, v1);
		cout << "����� �������� � ���������� �������� �����: " << v3;
		cout << endl << endl;
	}

	//������ 3.
	double sum_N(int N) {
		if (N == 0) return 1;
		else return sum_N(N - 1) + pow(2, -N);
	}

	void Task3() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 3." << endl << endl;
		int    N = 20;
		double s_N = 0.0;
		for (int k = 0; k <= N; ++k) {
			s_N += pow(2, -k);
		}
		cout << "��������� ����� ����, ���������� ��� ������ ������������� �����: " << 2.0 / 3 * s_N << endl;
		cout << endl;
		cout << "��������� ����� ����, ���������� ��� ������ ������������ �������: " << 2.0 / 3 * sum_N(N);
		cout << endl << endl;
	}
};