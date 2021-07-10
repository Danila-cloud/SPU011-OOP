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
	int getExper() const { return experience; }
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
