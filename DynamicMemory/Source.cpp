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

	cout << "������� ������ �������: "; cin >> n;

	int* arr = new int[n];
	cout << typeid(arr).name() << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� �������� "; cin >> value;
	arr=push_back(arr, n, value);
	Print(arr, n+1);
	/*arr[n] = value;
	n++;
	Print(arr, n);*/
	delete[]arr;//Heap(����)-��� ������, ������������� ������������ �������. 
	/*Print(arr, n);*/
	
	/*const int SIZE = 5;
	int brr[SIZE];
	cout << typeid(brr).name() << endl;
	FillRand(brr, SIZE);
	Print(brr, SIZE);*/
	//��� ������ �� ��������� ����� ���������
	
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//���� *(arr + i) = rand() %100;
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
}
int* push_back(int arr[],  int n, int value)
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

