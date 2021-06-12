#pragma once
#include<iostream>

using namespace std;

//class Weather;
class Humidity;
class Temperatura;

class Weather
{
public:
	void printAllWeather(Temperatura t, Humidity h);
	friend class Temperatura;
	friend class Humidity;
};


class Temperatura
{
	int temp;

public:
	Temperatura() {};
	Temperatura(int t) :temp(t) {};
	void print();
	//void printW(Weather w);

	friend void Weather::printAllWeather(Temperatura t, Humidity h);
	//friend class Weather;
};




class Humidity
{
	int hum;
public:
	Humidity() {};
	Humidity(int h) :hum(h) {};
	void print();
	//void printW(Weather w);
	friend void Weather::printAllWeather(Temperatura t, Humidity h);
	//friend class Weather;
};


void Weather::printAllWeather(Temperatura t, Humidity h)
{
	cout << "Temp    : " << t.temp << "C" << endl;
	cout << "Humidity: " << h.hum << "%" << endl;
}



//void Temperatura::printW(Weather w)
//{
//	cout << "Weather" << endl;
//}
//
//void Humidity::printW(Weather w)
//{
//}