#pragma once
#include<iostream>
#include<typeinfo>
#include"Drob.h"
#include<string>

using namespace std;

template<class T>
class Array
{
public:
	explicit Array(int s);
	~Array();
	Array(const Array &obj);
	Array& operator=(const Array &obj);
	Array operator+(T num);
	Array operator+(const Array & obj);
	T operator[](int ind) const;
	T & operator[](int ind);
	void setRand();
	void print()const;
	int getSize()const;
private:
	T *arr = nullptr;
	int size = 0;

	template<class T>
	friend Array<T> operator+(T num, Array<T> &obj);

	template<class T>
	friend ostream & operator<<(ostream & out, const Array<T> & obj);

	template<class T>
	friend istream & operator>>(istream & in, Array<T> & obj);
};

template<class T>
Array<T>::Array(int s)
{
	if (s > 0)
	{
		size = s;
		arr = new T[size];
	}
}

template<class T>
Array<T>::~Array()
{
	delete[] arr;
}

template<class T>
inline Array<T>::Array(const Array<T> & obj)
{
	size = obj.size;
	arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
}

template<class T>
inline Array<T> & Array<T>::operator=(const Array<T> & obj)
{
	if (this == &obj)
		return *this;

	if (arr)
		delete[]arr;

	size = obj.size;
	arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}

template<class T>
inline Array<T> Array<T>::operator+(T num)
{
	T *temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = num;
	size++;
	delete[]arr;
	arr = temp;
	return *this;
}

template<class T>
inline T Array<T>::operator[](int ind) const
{
	if (ind >= size || ind < 0)
		exit(1);
	return arr[ind];
}

template<class T>
inline T & Array<T>::operator[](int ind)
{
	if (ind >= size || ind < 0)
		exit(1);
	return arr[ind];
}

template<class T>
inline void Array<T>::setRand()
{
	for (size_t i = 0; i < size; i++)
	{
		if(typeid(T).name() == (string)"int")
			arr[i] = rand() % 100;
		if (typeid(T).name() == (string)"float")
			arr[i] = (rand() % 1000)/10.;
	}
}

inline void Array<string>::setRand()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = "fgdsfgsdfgsdf";
	}
}

inline void Array<char>::setRand()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 26 + 65;
	}
}

inline void Array<Drob>::setRand()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = Drob(rand()%10, rand()%10+1);
	}
}

template<class T>
inline void Array<T>::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
void printArr(Array<T> a)
{
	//a.print();
}

template<class T>
Array<T> operator+(T num, Array<T> &obj)
{
	Array<T> temp(obj.size+1);
	temp.arr[0] = num;
	for (size_t i = 0; i < obj.size; i++)
	{
		temp.arr[i+1] = obj.arr[i];
	}
	return temp;
}

template<class T>
ostream & operator<<(ostream & out, const Array<T> & obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		out << obj[i] << " ";
	}
	return out;
}

template<class T>
istream & operator>>(istream & in, Array<T> & obj)
{
	cout << "Введите " << obj.size << " элементов: ";
	for (size_t i = 0; i < obj.size; i++)
	{
		in >> obj.arr[i];
	}
	return in;
}
