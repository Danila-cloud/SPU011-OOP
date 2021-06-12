#include<iostream>
#include"Array.h"
#include"Drob.h"
#include"Weather.h"
using namespace std;

int main()
{
	setlocale(0, "");
	cout << endl;

	//Array a(10);
	//a.setRand();
	//a.print();
	//Array b(10);
	//b.setRand();
	//cin >> b;
	//a = a;
	//b.print();
	//b = a + 3; // a.op+(3)
	//b = 3 + a; // op+(3, a)
	//b.print();
	//cout << b[4] << endl;
	//b[2] = 100;
	//b.print();
	//cout << b << endl << 4 << endl;


	//Drob d(2, 5);
	//d.print();
	////d.init(3, 7);
	//d(3); // d.op(3,7);
	//d.print();

	/*Temperatura t(25);
	Humidity h(50);
	Weather w;
	w.printAllWeather(10, 50);*/


	Array<string> a(10);
	Array<string> b(5);

	a.setRand();
	b.setRand();
	a.print();

	cout << b << endl;
	a = b;
	cout << a << endl;
	system("pause");
}