
// ������������ ������ 6. ������� �������

#include <iostream>

using namespace std;

class Lab6 {
public:
	//������ 1.
	//.....����� ��� ����������� �����
	template <typename T>
	void SearchCouples(T* arr, const size_t SIZE) {
		bool flag = false;		//������� ���������� ���� "bool" � ����������� �� �������� "false"
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (arr[i] == arr[j] && i != j) {	//���� ��� �������� ������� �����, ��� ���� �� ����� �� �������, ��...
					flag = true; //...����������� ���������� ���� "bool" �������� "true", �.�. � ������� ���� ����(�) ����������� �����
					break;
				}
			}
		}
		if (flag) {		//���� � ������� ���� ����(�) ����������� �����, ��...
			cout << " � ������������������ ���� ���� �� ���� ���� ����������� �����!"; //...������� "� ������������������ ���� ���� �� ���� ���� ����������� �����!"
			cout << endl;
		}
		else {			//���� � ������� ��� ���(�) ����������� �����, ��...
			cout << " � ������������������ ��� �� ����� ���� ����������� �����!"; //...������� "� ������������������ ��� �� ����� ���� ����������� �����!"
			cout << endl;
		}
	}

	//.....��������� ����� ������ �� ��������� ���
	template <typename T>
	void FormNewArr(T* arr, T* new_arr, const size_t SIZE) {
		int count = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (arr[i] == arr[j] && i != j) {
					new_arr[count] = arr[i];
					count++;
				}
			}
		}
		for (int i = 0; i < count; i++) {
			cout << " |" << new_arr[i] << "|";
		}
	}

	//.....����������� ������, ��� ������� � ������� 
	template <typename T>
	void REbuildArr(T* arr, T* new_arr, const size_t SIZE, int k) {
		int count = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (arr[i] == arr[j] && i != j) {

					new_arr[count] = arr[i];
					count++;
				}
			}
		}
		int place = 0;
		for (int i = 0; i < count; i++) {
			if (((int)new_arr[i]) < k) {
				for (int j = i; j > place; j--) {
					swap(new_arr[j], new_arr[j - 1]);
				}
				place++;
			}
		}
		for (int i = 0; i < count; i++) {
			cout << " |" << new_arr[i] << "|";
		}
	}

	void Task() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 1." << endl << endl;

		size_t SIZE;
		cout << " ������� ������ ��������: \n";
		cin >> SIZE;
		int count = 0;

		int* arr = new int[SIZE];
		cout << "\n ������ ������ � ������ ���� int: \n";
		for (int i = 0; i < SIZE; i++) {
			cin >> arr[i];
		}
		SearchCouples(arr, SIZE);

		float* farr = new float[SIZE];
		cout << "\n ������ ������ � ������ ���� float: \n";
		for (int i = 0; i < SIZE; i++) {
			cin >> farr[i];
		}
		SearchCouples(farr, SIZE);

		cout << "\n �������� ����� ������� �� ������ ��������� ������ ��������...\n";
		cout << "\n ����� ������ ���� int: \n";
		int *new_arr = new int [SIZE];
		FormNewArr(arr, new_arr, SIZE);
		cout << endl;

		cout << "\n ����� ������ ���� float: \n";
		float *new_farr = new float [SIZE];
		FormNewArr(farr, new_farr, SIZE);
		cout << endl;

		cout << "\n ����������� ����� ������� ���, ����� ������� ������������� ��� ��������,";
		cout << "\n ����� ����� ������� �� ��������� �������� �����, � ����� � ��� ���������...\n";
		int k;
		cout << "\n ������� �����: ";
		cin >> k;

		cout << "\n ��������...\n";

		cout << "\n �������������� ������ ���� int: \n";
		REbuildArr(arr, new_arr, SIZE, k);
		cout << endl;

		cout << "\n �������������� ������ ���� float: \n";
		REbuildArr(farr, new_farr, SIZE, k);
		cout << endl << endl;
	}
};