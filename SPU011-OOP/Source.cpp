#include<iostream>
#include"Array.h"
#include"Drob.h"
#include"Weather.h"
#include"Stack.h"
#include"Queue.h"
#include"List.h"
#include"PrintServer.h"
#include<Windows.h>
#include"ForwardList.h"
#include<list>
#include<forward_list>
#include"BasePenalty.h"

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


	/*Array<string> a(10);
	Array<string> b(5);

	a.setRand();
	b.setRand();
	a.print();

	cout << b << endl;
	a = b;
	cout << a << endl;*/

	/*DynamicStack<Drob, 5> st;
	st.push(Drob(3,5));
	st.push(Drob(3, 4));
	st.push(Drob(3, 8));
	st.print();
	Drob a = st.pop();
	Drob b = st.pop();
	Drob c = st.peek();
	st.push(Drob(3, 9));
	st.push(Drob(3, 7));
	st.push(Drob(3, 2));

	st.print();
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << st.getSize() << endl;*/


	/*DynamicStack<Array<int>, 5> d;
	Array<int> a1(5);
	a1.setRand();
	Array<int> a2(8);
	a2.setRand();
	d.push(a1);
	d.push(a2);
	d.print();
	d.pop();
	d.print();*/

	//Queue<Array<int>> q;
	//Array<int> a1(5);
	//a1.setRand();
	//Array<int> a2(8);
	//a2.setRand();
	//q.push(a1);
	//q.push(a2);

	//q.print();

	////q.pop();
	//q.print();
	//cout << q.getSize() << endl;
	//q.clear();
	//cout << q.getSize() << endl;

	//QueuePriority<int> q;
	//q.push(1, LOW);
	//q.push(2, LOW);
	//q.push(3, MEDIUM);
	//q.push(4, HIGH);
	//q.print();
	//q.pop();
	//q.print();
	////q.superMethod();

	//List<int> l1;

	//{
	//	List<int> l;
	//	l.push_front(10);
	//	l.push_front(20);
	//	l.push_front(30);
	//	//l.push_back(40);
	//	//l.push_back(50);
	//	//l.push_at(100, 2);
	//	//l.print();
	//	cout << l << endl;
	//	//int a = l.pop_front();
	//	//l.pop_front();
	//	//cout << l << endl;
	//	//l.pop_back();
	//	//l.push_front(20);
	//	//l.push_back(10);

	//	l.pop_at(5);

	//	cout << l;

	//	cout << l[1] << endl;
	//	l1 = l;
	//	cout << l.peek_back() << endl;
	//}
	//cout << l1.getLength() << endl;

	/*ForwardList<int> fl;
	fl.push_front(10);
	fl.push_front(20);
	fl.push_front(30);
	fl.push_back(40);
	fl.push_back(50);
	fl.push_back(60);
	fl.print();
	cout << endl;
	fl.push_at(100, 5);
	fl.print();*/

	/*fl.pop_front();
	cout << endl;
	fl.print();
	

	fl.pop_back();
	cout << endl;
	fl.print();*/

	/*fl.pop_at(5);
	cout << endl;
	fl.print();*/

	//forward_list<int>l1;
	
	BasePenalty bs;
	bs.menu();



	system("pause");
}