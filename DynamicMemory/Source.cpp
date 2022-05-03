#include<iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
#define tab "\t"
int* push_back(int arr[],  int n, int value);


void main()
{
	setlocale(LC_ALL, "");
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
	Print(arr, n+1);
	/*arr[n] = value;
	n++;
	Print(arr, n);*/
	delete[]arr;//Heap(куча)-это память, принадлежащая операционной системе. 
	/*Print(arr, n);*/
	
	/*const int SIZE = 5;
	int brr[SIZE];
	cout << typeid(brr).name() << endl;
	FillRand(brr, SIZE);
	Print(brr, SIZE);*/
	//вся память за пределами нашей программы
	
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//либо *(arr + i) = rand() %100;
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
}
int* push_back(int arr[],  int n, int value)
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

