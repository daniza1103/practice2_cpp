
// Лабораторная работа 6. Шаблоны функций

#include <iostream>

using namespace std;

class Lab6 {
public:
	//Задача 1.
	//.....поиск пар совпадающих чисел
	template <typename T>
	void SearchCouples(T* arr, const size_t SIZE) {
		bool flag = false;		//создаем переменную типа "bool" и присваиваем ей значение "false"
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (arr[i] == arr[j] && i != j) {	//если два элемента массива равны, при этом не равны их индексы, то...
					flag = true; //...присваиваем переменной типа "bool" значение "true", т.е. в массиве есть пара(ы) совпадающих чисел
					break;
				}
			}
		}
		if (flag) {		//если в массиве есть пара(ы) совпадающих чисел, то...
			cout << " В последовательности есть хотя бы одна пара совпадающих чисел!"; //...выводим "В последовательности есть хотя бы одна пара совпадающих чисел!"
			cout << endl;
		}
		else {			//если в массиве нет пар(ы) совпадающих чисел, то...
			cout << " В последовательности нет ни одной пары совпадающих чисел!"; //...выводим "В последовательности нет ни одной пары совпадающих чисел!"
			cout << endl;
		}
	}

	//.....формируем новый массив из найденных пар
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

	//.....преобразуем массив, как сказано в условии 
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
		cout << "			Задача 1." << endl << endl;

		size_t SIZE;
		cout << " Введите размер массивов: \n";
		cin >> SIZE;
		int count = 0;

		int* arr = new int[SIZE];
		cout << "\n Введем данные в массив типа int: \n";
		for (int i = 0; i < SIZE; i++) {
			cin >> arr[i];
		}
		SearchCouples(arr, SIZE);

		float* farr = new float[SIZE];
		cout << "\n Введем данные в массив типа float: \n";
		for (int i = 0; i < SIZE; i++) {
			cin >> farr[i];
		}
		SearchCouples(farr, SIZE);

		cout << "\n Составим новые массивы из парных элементов старых массивов...\n";
		cout << "\n Новый массив типа int: \n";
		int *new_arr = new int [SIZE];
		FormNewArr(arr, new_arr, SIZE);
		cout << endl;

		cout << "\n Новый массив типа float: \n";
		float *new_farr = new float [SIZE];
		FormNewArr(farr, new_farr, SIZE);
		cout << endl;

		cout << "\n Преобразуем новые массивы так, чтобы сначала располагались все элементы,";
		cout << "\n целая часть которых не превышает заданное число, а потом — все остальные...\n";
		int k;
		cout << "\n Задайте число: ";
		cin >> k;

		cout << "\n Получаем...\n";

		cout << "\n Преобразованый массив типа int: \n";
		REbuildArr(arr, new_arr, SIZE, k);
		cout << endl;

		cout << "\n Преобразованый массив типа float: \n";
		REbuildArr(farr, new_farr, SIZE, k);
		cout << endl << endl;
	}
};