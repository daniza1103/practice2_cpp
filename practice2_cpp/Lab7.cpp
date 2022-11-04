
// Лабораторная работа 7. Работа с файлами

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Lab7 {
public:
	//Задача 1.
	void Task() {
		setlocale(LC_ALL, "RUS");
		cout << "			Задача 1." << endl << endl;

		string path = "f.txt";			// переменная, хранящая путь к f-файлу
		ofstream fout;
		fout.open(path);				// создаем (открываем) f-файл 

		if (!fout.is_open()) {			// если доступ к f-файлу не получен, то...
			cout << "Ошибка открытия файла!" << endl;		// ...выводим "Ошибка открытия файла!"
		}
		else {						   // если доступ к f-файлу получен, то... 
			cout << "Файл открыт!" << endl;	cout << endl;	//...выводим "Файл открыт!" и...
			cout << " Введите символы в файл: " << endl;
			char simvol;
			for (int i = 0; i < 10; i++) {
				cin >> simvol;		   //...записываем в него различные символы, пока не кончится цикл
				fout << simvol;
			}
			fout << " e n d " << endl; // добавляем в конец файла символсы " e n d "
		}
		fout.close();
		cout << endl << endl;
	}
};