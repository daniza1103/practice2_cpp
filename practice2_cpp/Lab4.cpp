
// Лабораторная работа 4. Обработка символов и строк в языке С++. Работа с файлами. Ссылки

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
	//Задача 1.
	void Task1() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 1." << endl << endl;
		string str;
		int length = 0;

		cout << " Введите строку... ";
		cout << "\n Для продолжения работы программы введите слово quit после введенной строки...";
		cout << endl << endl;

		while (true) {
			cout << " Строка: ";
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
		cout << " Общая длина слов на нечётных позициях в введенной строке равна: " << length;
		cout << endl << endl;
	}

	//Задача 2.
	void Task2() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 2." << endl << endl;
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
			str.replace(imin->first, imin->second + 1, " С новым годом!");
			cout << str << endl;
			ifs.close();
		}
		else {
			std::cerr << " Невозможно открыть файл!\n";
		}
		cout << endl << endl;
	}

	//Задача 3.
	struct MARSH {
		int NUMER;		  //номер маршрута 
		int TIME;	      //среднее время в пути 
		char* BEGST;      //название начального пункта маршрута 
		char* TERM;       //название конечного пункта маршрута 
	};
	MARSH TRAFIC[8];

	void Task3() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 3." << endl << endl;
		for (int i = 1; i <= 8; i++) {
			TRAFIC[i].BEGST = (char*)malloc(30 * sizeof(char));
			TRAFIC[i].TERM = (char*)malloc(30 * sizeof(char));
		}
		cout << " Данные всех 8 маршрутов..." << endl << endl << endl;

		for (int i = 1; i <= 8; i++) {
			cout << " Номер маршрута: " << i;
			TRAFIC[i].NUMER = i;
			cout << endl;

			cout << " Среднее время в пути (в часах): ";
			cin >> TRAFIC[i].TIME;

			cout << " Название начального пункта маршрута: ";
			cin >> TRAFIC[i].BEGST;

			cout << " Название конечного пункта маршрута: ";
			cin >> TRAFIC[i].TERM;
			cout << endl;
		}
		cout << endl;

		cout << " Введите название искомого (конечного или начального) пункта маршрута: ";
		char* naz;
		naz = (char*)malloc(30 * sizeof(char));
		cin >> naz;
		cout << endl << endl;
		int k = 0;
		for (int i = 1; i <= 8; i++) {
			if ((strcmp(TRAFIC[i].BEGST, naz) == 0) || (strcmp(TRAFIC[i].TERM, naz) == 0)) {
				cout << " Результаты поиска маршрута по заданному (конечному или начальному) пункту... " << endl << endl;
				cout << " Номер маршрута: " << TRAFIC[i].NUMER << "\n";
				cout << " Среднее время в пути: " << TRAFIC[i].TIME << "\n";
				cout << " Название начального пункта маршрута: " << TRAFIC[i].BEGST << "\n";
				cout << " Название конечного пункта маршрута: " << TRAFIC[i].TERM << "\n";
				k++;
			}
		}
		if (k == 0) cout << " Результаты поиска маршрута по заданному (конечному или начальному) пункту... " << endl << endl;
		cout << " Подходящих маршрутов не найдено!\n";
		cout << endl << endl;
	}
};