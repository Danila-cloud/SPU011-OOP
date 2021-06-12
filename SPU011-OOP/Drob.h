#pragma once
#include<iostream>
using namespace std;

class Drob
{
	int ch = 0, zn = 1;

public:
	Drob();
	Drob(int c);
	Drob(int c, int z);
	void print();
	float printToDec();
	int getCh();
	int getZn();
	void setCh();
	void setZn();
	void init();
	void init(int c, int z);
	void sum(Drob d1, Drob d2);
	bool operator==(const Drob &d1);
	Drob operator+(const Drob &d1);
	Drob operator-(Drob d1);
	Drob operator-();
	Drob operator+();
	Drob& operator++(); // префиксный
	Drob operator++(int); // постфиксный
	void operator()(int c, int z);
	void operator()(int c);

	friend ostream & operator<<(ostream & out, const Drob & obj);
};


ostream & operator<<(ostream & out, const Drob & obj)
{
	out << obj.ch << "/" << obj.zn << endl;
	return out;
}

inline Drob::Drob()
{
}

inline Drob::Drob(int c)
{
	ch = c;
}

inline Drob::Drob(int c, int z)
{
	ch = c;
	if (z)
		zn = z;

}

void Drob::print()
{
	cout << ch << "/" << zn << endl;
}


void Drob::sum(Drob d1, Drob d2)
{
	ch = d1.ch * d2.zn + d1.zn * d2.ch;
	zn = d1.zn * d2.zn;
}

inline bool Drob::operator==(const Drob & d1)
{
	return (float)ch / zn == (float)d1.ch / d1.zn;
}

inline Drob Drob::operator+(const Drob& d2)
{
	Drob d;
	d.ch = d2.ch * this->zn + d2.zn * this->ch;
	d.zn = d2.zn * this->zn;
	return d;
}

inline Drob Drob::operator-(Drob d2)
{
	Drob d;
	d.ch = d2.zn * this->ch - d2.ch * this->zn;
	d.zn = d2.zn * this->zn;
	return d;
}

inline Drob Drob::operator-()
{
	return Drob(-ch, zn);
}

inline Drob Drob::operator+()
{
	return Drob(++ch, zn);
}

inline Drob& Drob::operator++()
{
	ch += zn;
	return *this;
}

inline Drob Drob::operator++(int)
{
	Drob d(ch, zn);
	this->ch += this->zn;
	return d;
}

inline void Drob::operator()(int c, int z)
{
	ch = c;
	zn = z;
}

inline void Drob::operator()(int c)
{
	ch = c;
	zn = 1;
}

//Drob operator+(Drob d1, Drob d2)
//{
//	
//}

