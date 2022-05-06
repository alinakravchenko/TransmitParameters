#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);
void Print(int** arr,  int rows, const int cols);
#define tab "\t"
int* push_back(int arr[],  int& n, int value);
int* insert(int arr[], int& n, int value, int ind);
int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void push_rows_back(int**& arr, int& rows, const int cols);
void push_rows_front(int**& arr, int& rows,  const int cols);
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	//new
	int n;

	/*delete &n;*/ //Debug Assertion Failed

	cout << "Введите размер массива: "; cin >> n;

	int* arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение "; cin >> value;
	arr=push_back(arr, n, value);
	Print(arr, n);
	/*arr[n] = value;
	n++;
	Print(arr, n);*/
	/*Print(arr, n);*/
	 int ind;
	cout << "Введите значение "; cin >> value;
	cout << "Введите индекс "; cin >> ind;
	arr = insert(arr, n, value, ind);
	Print(arr, n);
	int hex;
	cout << "Введите значение: "; cin >> hex;
	arr = push_front(arr, n, value);
	Print(arr, n);
	int m;
	cout << "Введите значение: "; cin >> m;
	arr = pop_back(arr, n);
	Print(arr, n);
	delete[]arr;//Heap(куча)-это память, принадлежащая операционной системе. 
	/*const int SIZE = 5;
	int brr[SIZE];
	cout << typeid(brr).name() << endl;
	FillRand(brr, SIZE);
	Print(brr, SIZE);*/
	//вся память за пределами нашей программы
	
#endif
#ifdef DYNAMIC_MEMORY_2
	int rows; //кол-во строк ддм
	int cols; //кол-во эл. строки
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	//1. создаём массив указателей 
	int** arr = new int*[rows];
	//2. создаём строки дм
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	//3. обращение к элементам ддм
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//4. удаление массива 
	//4.1 удаление строк
	//4.2 удаление массив указателей
	
	int value;
	cout << "Введите добавляемое значение "; cin >> value;
	push_rows_back (arr, rows, cols);
	Print(arr, rows,cols);
	int hex;
	cout << "Введите добавляемое значение "; cin >> hex;
	 push_rows_front(arr, rows, cols);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
#endif
}



void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//либо *(arr + i) = rand() %100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int* arr, const int n)
{
	cout << typeid(arr).name() << endl; //RTTI - Runtime Type Information
	for (int i = 0; i < n; i++)
	{
		//[]-оператор индексирования
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[],  int& n, int value)
{
	//1. Создаём буфферный массив нужного размера (в данном случае на 1 эл. больше)
	int* buffer = new int[n + 1];
	//2. Копируем все данные из исход. массива в буфферный
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	//3. После копирования данных в новый массив, старый массив ненужен
	delete[] arr;
	//4. Подменяем адресс старого массива с адресом нового массива
	arr = buffer;
	//5. Только после 4, в новый массив можно добав. значение
	arr[n] = value;
	//6. После доб. эл. в массив, кол-во его эл. увел. на 1
	n++;
	//7. Элемент добавлен 
	return buffer;
}
int* push_front(int arr[], int& n, int value)
{
	int*buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* insert(int arr[], int& n, int value, int ind)
{
	int* newint = new int[n + 1];
	for (int i = 0; i < ind; i++)newint[i] = arr[i];
	/*delete[] arr;*/
	newint[ind] = value;
	for (int i = ind; i < n; i++)newint[i + 1] = arr[i];
	delete[] arr;
	n++;
	/*arr = newint;*/ 
	return newint;
}
void push_rows_back(int**& arr, int& rows,  const int cols)
{
	int** buffer = new int*[rows + 1];
	for (int i = 0; i < rows+1; i++) 
	{      
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[rows] = new int [cols] {};
	++rows;
}
void push_rows_front(int**& arr, int& rows, const int cols)
{
	int** buffer = arr;
	buffer = new int*[rows+1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new int [cols] {};
	arr = buffer;
	rows++;
	
}
