#pragma once
#include<string>

using namespace std;

class Human
{
	string name;
	int age;
	const int countEye;
public:
	Human() : countEye(2)
	{ 
		/*cout << "Human" << endl;*/
	}
	Human(string n, int a) : name(n), age(a), countEye(2) { /*cout << "Human2" << endl;*/ }
	string getName() const { return name; }
	int getAge() const { return age; }
	void print() const
	{
		cout << "Name   : " << name << endl;
		cout << "Age    : " << age<< endl;
	}
	void method() const { cout << "Method" << endl; }
};


class Doctor : public Human
{

	int salary;
	int experience;
public:

	Doctor() { /*cout << "Doctor" << endl;*/ }
	Doctor(int s, int e) : salary(s), experience(e) 
	{ 
		/*cout << "Doctor2" << endl;*/ 
	}
	Doctor(string n, int a, int s, int e) : salary(s), experience(e), Human(n, a)
	{
		/*cout << "Doctor2" << endl;*/
	}
	void print() const
	{
		Human::print();
		cout << "Salary : " << salary << endl;
		cout << "Exp    : " << experience << endl;
	}
	int getSalary()const { return salary; }
	int getExper() const { return experience; Human::method(); }
	void method() const = delete;
};

class Patalogoanatom : public Doctor
{
	bool diplom;
public:
	Patalogoanatom() { /*cout << "Patalogoanatom" << endl;*/ }
	Patalogoanatom(string n, int a, int s, int e, bool d): Doctor(n, a, s, e), diplom(d)  { /*cout << "Patalogoanatom" << endl;*/ }
	
	void print()const
	{
		Doctor::print();
		cout << "Diplom : " << ((diplom)?"Yes":"No") << endl;
	}
};

class Adapter
{
public:
	int id;
	Adapter() {}
	Adapter(int id) :id(id) {}
};


class USBAdapter : virtual public Adapter
{
	int id;
public:
	USBAdapter(int id, int idA): id(id), Adapter(idA){	}
	int getID() { return id; }
};

class LANAdapter : virtual public Adapter
{
	int id;
public:
	LANAdapter(int id, int idA) : id(id), Adapter(idA) {	}
	int getID() { return id; }
};

class WIFIDevice : public USBAdapter, public LANAdapter
{
public:
	WIFIDevice(int idUSB, int idLAN, int idA) : USBAdapter(idUSB, idA), LANAdapter(idLAN, idA) {};
};



class Base
{
public:
	virtual void f1() { cout << "Base F1" << endl; }
	virtual void f2() { cout << "Base F2" << endl; }
};

class C1 : public Base
{
public:
	void f1() { cout << "C1 F1" << endl; }
};

class C2 : public Base
{
public:
	void f2() { cout << "C2 F2" << endl; }
};