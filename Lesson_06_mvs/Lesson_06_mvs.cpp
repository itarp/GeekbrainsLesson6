#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void task1();
void task2();
void task3();
void task4();
void task5();

void initArray(unsigned int* pArray, size_t size);
void show(unsigned int* pArray, size_t size);

void initMatrix(int **ptrMatrix,const size_t size);
void showMatrix(int** ptrMatrix, const size_t size);

std::string& generateWord(std::string &str, int numLetters);
std::string& generateWord(std::string &str, int minLetters, int maxLetters);
std::string& sentence(std::string &str, int size);

int main() {
	std::cout << "========================================= task 1 =========================================" << std::endl;
	task1();
	std::cout << "========================================= task 2 =========================================" << std::endl;
	task2();
	std::cout << "========================================= task 3 =========================================" << std::endl;
	task3();
	std::cout << "========================================= task 4 =========================================" << std::endl;
	task4();
	std::cout << "========================================= task 5 =========================================" << std::endl;
	task5();
	return 0;
}

void task1() {
	// =========================================== Задание 1 ===========================================
	//Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя.
	//Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 ... Вывести массив на экран. 
	//Не забыть освободить память. =) Разбить программу на функции.
	size_t size(0);
	unsigned int* pArray = nullptr;
	
	// Запросить у пользователя размер массива
	do {
		std::cout << "Enter the size of the array in the range 1 to 32: ";
		std::cin >> size;
		if (size > 0 && size <= 32)
			break;
	} while (true);
	pArray = new unsigned int[size];
	
	initArray(pArray, size);
	show(pArray, size);
	delete[] pArray;
}

void task2() {
	// =========================================== Задание 2 ===========================================
	//Динамически выделить матрицу 4х4 типа int.Инициализировать ее псевдослучайными числами через функцию rand.
	//Вывести на экран.Разбейте вашу программу на функции которые вызываются из main.
	
	const size_t size = 4;
	// Выделение памяти для матрицы
	int **ptrMatrix = nullptr;
	ptrMatrix = new int* [size];
	for (int i = 0; i < size; i++)
		ptrMatrix[i] = new int[size];
	
	initMatrix(ptrMatrix, size);
	showMatrix(ptrMatrix, size);

	// Освобождение памяти
	for (size_t i = 0; i < size; i++) {
		delete[] ptrMatrix[i];
	}
	delete[] ptrMatrix;
}

void task3() {
	// =========================================== Задание 3 ===========================================
	//Написать программу, которая создаст два текстовых файла(*.txt), примерно по 50 - 100 символов в каждом
	//(особого значения не имеет с каким именно содержимым).Имена файлов запросить у польлзователя.
	std::string text;
	srand(time(NULL));

	std::string fileName; // Общая переменная для имен первого и второго файлов
	std::cout << "Enter the name of the first file: ";
	std::cin >> fileName;
	std::ofstream fout(fileName);
	if (fout.is_open()) {
		fout << sentence(text, 50); //Генерируется предложение из слов не более 50 символов
		fout.close();
	}

	std::cout << "Enter the name of the second file: ";
	std::cin >> fileName;
	std::ofstream fout2(fileName);
	if (fout2.is_open()) {
		fout2 << sentence(text, 50); //Генерируется предложение из слов не более 50 символов
		fout2.close();
	}
}

void task4() {
	// =========================================== Задание 4 ===========================================
	//Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
	std::string fileName1;
	std::string fileName2;
	std::string fileNameOut;

	std::cout << "Enter the name of the output file: ";
	std::cin >> fileNameOut;
	std::ofstream fout(fileNameOut);
	if (fout.is_open()) {
		std::cout << "Enter the name of the input file1: ";
		std::cin >> fileName1;
		std::ifstream fin1(fileName1);
		if (fin1.is_open()) {
			std::string buf;
			while (!fin1.eof()) {
				getline(fin1, buf);
				fout << buf << std::endl;;
			}
		}
		std::cout << "Enter the name of the input file2: ";
		std::cin >> fileName2;
		std::ifstream fin2(fileName2);
		if (fin2.is_open()) {
			std::string buf;
			while (!fin2.eof()) {
				getline(fin2, buf);
				fout << buf << std::endl;
			}
		}
		fin1.close();
		fin2.close();
		fout.close();
	}
}

void task5() {
	// =========================================== Задание 5 ===========================================
	//Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы
	//слово в указанном пользователем файле (для простоты работаем только с латиницей).
	//Используем функцию find которая есть в строках std::string.
	bool isFind = false;
	std::string fileName;
	std::cout << "Enter file name: ";
	std::cin >> fileName;
	std::ifstream fin(fileName);
	std::string buf;
	std::string strFind;
	std::cout << "Enter a search word: ";
	std::cin >> strFind;
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, buf);
			if (buf.find(strFind) != std::string::npos) {
				isFind = true;
				break;
			}
		}
		if(isFind == true)
			std::cout << "Yes we found " << strFind << std::endl;
		else 
			std::cout << "We can not find " << strFind << std::endl;
	}
	fin.close();
}

void initArray(unsigned int* pArray, size_t size) {
	// Заполнить выделенный массив числами степенями двойки
	int temp = *pArray = 1;
	for (int i = 1; i < size; i++)
		*(pArray + i) = temp << i;
}

void show(unsigned int *pArray, size_t size) {
	// Вывести массив на экран
	for (int i = 0; i < size; i++)
		std::cout << *(pArray + i) << ' ';;
	std::cout << std::endl;
}

void initMatrix(int** ptrMatrix, const size_t size) {
	// Инициализировать матрицу
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		for (int ii = 0; ii < size; ii++)
			ptrMatrix[i][ii] = (rand()) % 100;
}

void showMatrix(int** ptrMatrix, const size_t size) {
	// Вывод на экран матрицы
	for (int i = 0; i < size; i++) {
		for (int ii = 0; ii < size; ii++)
			std::cout << (ptrMatrix[i][ii]) << "\t";
		std::cout << std::endl;
	}
}

std::string& generateWord(std::string &str, int numLetters) {
	str.clear();
	int min = 97, max = 122;
	//srand(time(NULL));
	for (int i = 0; i < numLetters; i++)
		str += min + rand() % (max - min + 1);
	return str;
}

std::string& generateWord(std::string &str, int minLetters, int maxLetters) {
	str.clear();
	int numLetters;
	//srand(time(NULL));
	numLetters = minLetters + rand() % (maxLetters - minLetters + 1);
	str = generateWord(str, numLetters);
	return str;
}

std::string& sentence(std::string &str, int size) {
	str.clear();
	int len = 0;
	std::string word;
	while(len <= size) {
		generateWord(word, 2, 10);
		len += word.length();
		if (len <= size) {
			if (!str.empty()) {
				str += ' ';
				len++;
				}
			str += word;
		}
	}  
	return str;
}