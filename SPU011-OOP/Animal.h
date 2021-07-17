#pragma once
#include<string>

using namespace std;

class Animal
{
protected:
	string name;
	int age;
public:
	Animal() {}
	virtual ~Animal() { cout << "Des Animal" << endl; }
	Animal(string n, int a) : name(n), age(a) {  }
	string getName() { return name; }
	virtual int getAge() { return age; }
	string getType() { return "Animal"; }
	virtual string voice() const = 0;
};

string Animal::voice() const
{
	return "?????????";
}

class Cat : public Animal
{
public:
	~Cat() { cout << "Des Cat" << endl; }
	Cat(string n, int a) : Animal(n, a) {  }
	string getType() { return "Cat"; }
	virtual string voice() const  override { return "Myau Myau"; }
	virtual int getAge()  override { return age * 2; }
	void kogti() { cout << "Прощай мебель" << endl; }
};


class Dog : public Animal
{
public:
	Dog(string n, int a) : Animal(n, a) {}
	string getType() { return "Dog"; }
	virtual string voice() const override { return "Gaw Gaw"; }
	virtual int getAge() override { return age * 3; }
};

class SiamCat : public Cat
{
public:
	SiamCat(string n, int a) : Cat(n, a) {}
	string getType() { return "SiamCat"; }
	virtual string voice() const { return "MyaW MyaW"; }
	virtual int getAge() override { return age * 4; }
};


class Ulitka : public Animal
{
public:
	Ulitka(string n, int a) : Animal(n, a) {}
	string voice() const override { return Animal::voice(); }
};



Animal* getAnimal()
{
	int r = rand() % 4;
	switch (r)
	{
	case 0:
		return new Cat("Tom", 2);
	case 1:
		return new Dog("Spike", 6);
	case 2:
		return new SiamCat("Siam", 8);
	default:
		return new Ulitka("Dora", 3);
	}
}