#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
//#define pointers_basics
void main()
{
	//*-���������� �������� �� ������ (�������������)
	//&-�������� ������ ������ 
	setlocale(LC_ALL, "");
#ifdef pointers_basics
	int a = 2; //���������� ����������
	int *pa = &a; //�������� ��������� �� � ��������� &a
	//p-pointer (���������� �������)
	cout << a << endl; //����� �������� ���������� 'a' �� �����
	cout << &a << endl; //������ ������� ���������� 'a' ����� ��� ������ 
	cout << pa << endl; //����� �� ����� ������ ���������� 'a' , ����. � ��������� '�a'
	cout << *pa << endl; //������������� ��������� '�a' � ����� �� ����� ����. �� ������

	int *pb;
	int b = 3;
	pb = &b;
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;
	/*pb = b;*/
//(int*)  (int)
//int - int 
// int* - ��������� �� int 
	//double-double
	//double*-��������� �� double
#endif
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
	for (int*p_arr = arr; *p_arr != 0xCCCCCCCC; p_arr++)
	{
		cout << *p_arr << "\t";
	}
	cout << endl;

	/*1. ���������� ���-�� ������������ �����. � ������ ����������.
    2. � ����� ������ ������������ ���������� ������� ����������������� (������� ������������)
		��������*/
}