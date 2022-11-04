
// Лабораторная работа 5. Перегрузка функций

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Lab5 {
public:
	//Задача.
	//.....а) вычислить сумму отрицательных элементов массива
	int FUNC(int A[], int n, int sum) {
		sum = 0;
		for (int i = 0; i < n; i++) if (A[i] < 0) sum += A[i];
		return sum;
	}

	//.....б) вычислить произведение элементов массива, расположенных между максимальным и минимальным элементами
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

	//.....в) упорядочить элементы массива по возрастанию
	void FUNC(int A[], int n, double temp) {
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (A[i] > A[j]) {
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
	}

	//.....создание одномерного массива, состоящего из n элементов
	void Task() {
		setlocale(LC_ALL, "RUS");
		srand(time(NULL));
		cout << "			Задача 1." << endl << endl;
		const int n = 10;
		cout << "  Размер массива A равен: n = " << n << endl;

		int A[n];						 //создаем массив
		cout << "  Заполним массив A случайными элементами..." << endl; cout << endl;
		cout << "  Массив A будет иметь вид..." << endl; cout << endl; cout << "		A =";

		for (int i = 0; i < n; i++) {{
				A[i] = rand() % 41 - 20; //заполняем массив случайными числами от -20 до 20
			}
			cout << " " << A[i];		 //выводим полученный массив
		} cout << endl << endl;

		//.....а) 
		int sum = 0;
		cout << "  а)Сумма отрицательных элементов массива А равна: " << FUNC(A, n, sum) << endl;

		//.....б)
		int index_min = 0;
		int index_max = 0;
		double mult = 1;
		cout << "  б)Произведение элементов массива А, расположенных между макc. и мин. элементами равно: " << FUNC(A, n, index_min, index_max, mult);
		cout << endl;

		//.....в)  
		double temp = 0;
		FUNC(A, n, temp);
		cout << "  в)Теперь отсортируем массив А по возрастанию..." << endl << endl;
		cout << "    Отсортированный массив А будет иметь вид... " << endl; cout << endl; cout << "		A = ";
		for (int i = 0; i < n; i++) cout << A[i] << " ";
		cout << endl << endl;
	}
};