
// ������������ ������ 7. ������ � �������

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Lab7 {
public:
	//������ 1.
	void Task() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 1." << endl << endl;

		string path = "f.txt";			// ����������, �������� ���� � f-�����
		ofstream fout;
		fout.open(path);				// ������� (���������) f-���� 

		if (!fout.is_open()) {			// ���� ������ � f-����� �� �������, ��...
			cout << "������ �������� �����!" << endl;		// ...������� "������ �������� �����!"
		}
		else {						   // ���� ������ � f-����� �������, ��... 
			cout << "���� ������!" << endl;	cout << endl;	//...������� "���� ������!" �...
			cout << " ������� ������� � ����: " << endl;
			char simvol;
			for (int i = 0; i < 10; i++) {
				cin >> simvol;		   //...���������� � ���� ��������� �������, ���� �� �������� ����
				fout << simvol;
			}
			fout << " e n d " << endl; // ��������� � ����� ����� �������� " e n d "
		}
		fout.close();
		cout << endl << endl;
	}
};