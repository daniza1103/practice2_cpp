
// ������������ ������ 5. ���������� �������

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Lab5 {
public:
	//������.
	//.....�) ��������� ����� ������������� ��������� �������
	int FUNC(int A[], int n, int sum) {
		sum = 0;
		for (int i = 0; i < n; i++) if (A[i] < 0) sum += A[i];
		return sum;
	}

	//.....�) ��������� ������������ ��������� �������, ������������� ����� ������������ � ����������� ����������
	double FUNC(int A[], int n, int index_min, int index_max, double mult) {
		index_min = 0;
		index_max = 0;
		mult = 1;

		for (int i = 0; i < n; i++) {
			if (A[i] < A[index_min])
				index_min = i;
			if (A[i] > A[index_max])
				index_max = i;
		}
		if (index_min > index_max) {
			double temp_index = index_min;
			index_min = index_max;
			index_max = temp_index;
		}

		for (int i = index_min + 1; i < index_max; i++) mult *= A[i];
		return mult;
	}

	//.....�) ����������� �������� ������� �� �����������
	void FUNC(int A[], int n, double temp) {
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (A[i] > A[j]) {
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
	}

	//.....�������� ����������� �������, ���������� �� n ���������
	void Task() {
		setlocale(LC_ALL, "RUS");
		srand(time(NULL));
		cout << "			������ 1." << endl << endl;
		const int n = 10;
		cout << "  ������ ������� A �����: n = " << n << endl;

		int A[n];						 //������� ������
		cout << "  �������� ������ A ���������� ����������..." << endl; cout << endl;
		cout << "  ������ A ����� ����� ���..." << endl; cout << endl; cout << "		A =";

		for (int i = 0; i < n; i++) {{
				A[i] = rand() % 41 - 20; //��������� ������ ���������� ������� �� -20 �� 20
			}
			cout << " " << A[i];		 //������� ���������� ������
		} cout << endl << endl;

		//.....�) 
		int sum = 0;
		cout << "  �)����� ������������� ��������� ������� � �����: " << FUNC(A, n, sum) << endl;

		//.....�)
		int index_min = 0;
		int index_max = 0;
		double mult = 1;
		cout << "  �)������������ ��������� ������� �, ������������� ����� ���c. � ���. ���������� �����: " << FUNC(A, n, index_min, index_max, mult);
		cout << endl;

		//.....�)  
		double temp = 0;
		FUNC(A, n, temp);
		cout << "  �)������ ����������� ������ � �� �����������..." << endl << endl;
		cout << "    ��������������� ������ � ����� ����� ���... " << endl; cout << endl; cout << "		A = ";
		for (int i = 0; i < n; i++) cout << A[i] << " ";
		cout << endl << endl;
	}
};