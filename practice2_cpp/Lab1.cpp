
// ������������ ������ 1. ����������� ��������� ����� �++

#include <iostream>

using namespace std;

class Lab1 {
public:
	//������ 1.
	void Task1() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 1." << endl << endl;
		const float pi = 3.14;

		int storona1 = 10;
		cout << " ������ ��������� ������� ������������ �����: " << storona1 << "��.";
		cout << endl;

		int storona2 = 15;
		cout << " ������ ��������� ������� ������������ �����: " << storona2 << "��.";
		cout << endl;

		float ugol = pi / 3;
		cout << " ���� � �������� �����: �/3.";
		cout << endl;

		float storona3 = sqrt((storona1 * storona1) + (storona2 * storona2) - (2 * storona1 * storona2 * cos(ugol)));
		cout.precision(3);
		cout << " �������� ����������� ������� ������������ �� ������� ���������, �������, ��� ��� �����: " << storona3 << "��.";
		cout << endl << endl;
	}

	//������ 2.
	void Task2() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 2." << endl << endl;
		int d, i;
		cout << " ������� ���� ������:";
		cin >> d;
		for (i = 1; i < 7; i++)
			if ((d < 1) || (d > 7)) cout << " ������ ��� �� ����������!";
				if ((d > 0) && (d < 6)) cout << " ��� ������� ����!";
				if (d == 6) cout << " ��� �������!";
				if (d == 7) cout << " ��� �����������!";
		cout << endl << endl;
	}

	//������ 3.
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
		cout << "			������ 3." << endl << endl;
		int n, m, k = 0;

		cout << " ������� n: ";
		cin >> n;
		cout << " ������� m: ";
		cin >> m;

		cout << " ��� �����: " << NOK(n, m);
		cout << endl;
		cout << " ��� �����: " << NOD(n, m);
		cout << endl;

		k = NOK(n, m) - NOD(n, m);
		cout << " �������� ��� � ��� �����: " << k;
		cout << endl << endl;
	}
};