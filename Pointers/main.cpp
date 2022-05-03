#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
//#define pointers_basics
void main()
{
	//*-возвращает значение по адресу (разыменование)
	//&-оператор взятия адреса 
	setlocale(LC_ALL, "");
#ifdef pointers_basics
	int a = 2; //объявление переменной
	int *pa = &a; //объявили перменную ра и присвоили &a
	//p-pointer (венгерская нотация)
	cout << a << endl; //вывод значения переменной 'a' на экран
	cout << &a << endl; //взятие адпреса переменной 'a' прямо при выводе 
	cout << pa << endl; //вывод на экран адреса переменной 'a' , хран. в указателе 'рa'
	cout << *pa << endl; //разыменование указателя 'рa' и вывод на экран знач. по адресу

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
// int* - указатель на int 
	//double-double
	//double*-указатель на double
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

	/*1. Показывает кол-во передаваемых парам. в списке аргументов.
    2. В конце списка передаваемых параметров пишется детерминированное (заранее определенное)
		значение*/
}