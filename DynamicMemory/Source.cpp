#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);
#define tab "\t"
int* push_back(int arr[],  int& n, int value);
int* insert(int arr[], int& n, int value, int ind);
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	//new
	int n;

	/*delete &n;*/ //Debug Assertion Failed

	cout << "������� ������ �������: "; cin >> n;

	int* arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� �������� "; cin >> value;
	arr=push_back(arr, n, value);
	Print(arr, n);
	/*arr[n] = value;
	n++;
	Print(arr, n);*/
	/*Print(arr, n);*/
	 int ind;
	cout << "������� �������� "; cin >> value;
	cout << "������� ������ "; cin >> ind;
	arr = insert(arr, n, value, ind);
	Print(arr, n);
	
	delete[]arr;//Heap(����)-��� ������, ������������� ������������ �������. 
	/*const int SIZE = 5;
	int brr[SIZE];
	cout << typeid(brr).name() << endl;
	FillRand(brr, SIZE);
	Print(brr, SIZE);*/
	//��� ������ �� ��������� ����� ���������
	
#endif
	int rows; //���-�� ����� ���
	int cols; //���-�� ��. ������
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	//1. ������ ������ ���������� 
	int** arr = new int*[rows];
	//2. ������ ������ ��
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	//3. ��������� � ��������� ���
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//4. �������� ������� 
	//4.1 �������� �����
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//4.2 �������� ������ ����������
	delete[] arr;
}



void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//���� *(arr + i) = rand() %100;
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
		//[]-�������� ��������������
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
	//1. ������ ��������� ������ ������� ������� (� ������ ������ �� 1 ��. ������)
	int* buffer = new int[n + 1];
	//2. �������� ��� ������ �� �����. ������� � ���������
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	//3. ����� ����������� ������ � ����� ������, ������ ������ �������
	delete[] arr;
	//4. ��������� ������ ������� ������� � ������� ������ �������
	arr = buffer;
	//5. ������ ����� 4, � ����� ������ ����� �����. ��������
	arr[n] = value;
	//6. ����� ���. ��. � ������, ���-�� ��� ��. ����. �� 1
	n++;
	//7. ������� �������� 
	return buffer;
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

