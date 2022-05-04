#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2; //перменная
	int& ra=a; //ссылка на а
	ra += 3;
	cout << a << endl;
	a += 3;
	cout << ra << endl;
	cout << &a << endl;
	cout << &ra << endl;
}
//ссылка-это перменная, которая содержит адрес другой переменной. 
//отлич. от указателя тем, что не нужно разыменовывать, делает это кампилятор.
