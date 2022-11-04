
// ������������ ������ 4. ��������� �������� � ����� � ����� �++. ������ � �������. ������

#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Lab4 {
public:
	//������ 1.
	void Task1() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 1." << endl << endl;
		string str;
		int length = 0;

		cout << " ������� ������... ";
		cout << "\n ��� ����������� ������ ��������� ������� ����� quit ����� ��������� ������...";
		cout << endl << endl;

		while (true) {
			cout << " ������: ";
			getline(cin, str);
			string word{};
			stringstream words(str);
			int i = 1;
			while (words >> word && word != "quit") {
				if (i % 2 != 0)
					length += word.length();
				i++;
			}
			if (word == "quit") break;
		}
		cout << endl;
		cout << " ����� ����� ���� �� �������� �������� � ��������� ������ �����: " << length;
		cout << endl << endl;
	}

	//������ 2.
	void Task2() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 2." << endl << endl;
		ifstream ifs { 
			"in.txt" 
		};
		if (ifs.is_open()) {
			string str {
				istreambuf_iterator<char>{ifs.rdbuf()}, {} 
			};
			regex rgx { 
				"(?:^|[.!?])([^.!?]*)(?=[.!?])" 
			};
			auto imin = min_element(sregex_token_iterator { 
				str.begin(), str.end(), rgx, 1 
			}, {}, [](auto const& a, auto const& b) { 
				return a.length() < b.length(); 
			});
			str.replace(imin->first, imin->second + 1, " � ����� �����!");
			cout << str << endl;
			ifs.close();
		}
		else {
			std::cerr << " ���������� ������� ����!\n";
		}
		cout << endl << endl;
	}

	//������ 3.
	struct MARSH {
		int NUMER;		  //����� �������� 
		int TIME;	      //������� ����� � ���� 
		char* BEGST;      //�������� ���������� ������ �������� 
		char* TERM;       //�������� ��������� ������ �������� 
	};
	MARSH TRAFIC[8];

	void Task3() {
		setlocale(LC_ALL, "RUS");
		cout << "			������ 3." << endl << endl;
		for (int i = 1; i <= 8; i++) {
			TRAFIC[i].BEGST = (char*)malloc(30 * sizeof(char));
			TRAFIC[i].TERM = (char*)malloc(30 * sizeof(char));
		}
		cout << " ������ ���� 8 ���������..." << endl << endl << endl;

		for (int i = 1; i <= 8; i++) {
			cout << " ����� ��������: " << i;
			TRAFIC[i].NUMER = i;
			cout << endl;

			cout << " ������� ����� � ���� (� �����): ";
			cin >> TRAFIC[i].TIME;

			cout << " �������� ���������� ������ ��������: ";
			cin >> TRAFIC[i].BEGST;

			cout << " �������� ��������� ������ ��������: ";
			cin >> TRAFIC[i].TERM;
			cout << endl;
		}
		cout << endl;

		cout << " ������� �������� �������� (��������� ��� ����������) ������ ��������: ";
		char* naz;
		naz = (char*)malloc(30 * sizeof(char));
		cin >> naz;
		cout << endl << endl;
		int k = 0;
		for (int i = 1; i <= 8; i++) {
			if ((strcmp(TRAFIC[i].BEGST, naz) == 0) || (strcmp(TRAFIC[i].TERM, naz) == 0)) {
				cout << " ���������� ������ �������� �� ��������� (��������� ��� ����������) ������... " << endl << endl;
				cout << " ����� ��������: " << TRAFIC[i].NUMER << "\n";
				cout << " ������� ����� � ����: " << TRAFIC[i].TIME << "\n";
				cout << " �������� ���������� ������ ��������: " << TRAFIC[i].BEGST << "\n";
				cout << " �������� ��������� ������ ��������: " << TRAFIC[i].TERM << "\n";
				k++;
			}
		}
		if (k == 0) cout << " ���������� ������ �������� �� ��������� (��������� ��� ����������) ������... " << endl << endl;
		cout << " ���������� ��������� �� �������!\n";
		cout << endl << endl;
	}
};