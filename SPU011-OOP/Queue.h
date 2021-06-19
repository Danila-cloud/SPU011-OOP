#pragma once
#include"MyData.h"

template<class T>
class Queue
{
	MyData<T> *first = nullptr;
	MyData<T> *last = nullptr;
	int size = 0;

public:
	~Queue();
	void push(T val);
	T pop();
	T peek();
	int getSize();     //получение текущего размера
	void clear();      //очистка стека
	void print() const;

};

template<class T>
inline Queue<T>::~Queue()
{
	clear();
}

template<class T>
inline void Queue<T>::push(T val)
{
	if (size == 0)
	{
		first = new MyData<T>;
		first->value = val;
		last = first;
	}
	else
	{
		MyData<T> *temp = new MyData<T>;
		temp->value = val;
		last->next = temp;
		last = temp;
	}
	size++;
}

template<class T>
inline T Queue<T>::pop()
{
	if (size == 0)
	{
		cout << "Queue is empty!!!" << endl;
		system("pause");
		exit(1);
	}

	T val = first->value;
	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		MyData<T> *temp = first;
		first = first->next;
		delete temp;
	}
	size--;
	return val;
}

template<class T>
inline T Queue<T>::peek()
{
	if (size > 0)
	{
		return first->value;
	}
	else
	{
		cout << "Queue is empty!!!" << endl;
		system("pause");
		exit(1);
	}
}

template<class T>
inline int Queue<T>::getSize()
{
	return size;
}

template<class T>
inline void Queue<T>::clear()
{
	while (size)
		pop();
	first = last = nullptr;
}

template<class T>
inline void Queue<T>::print() const
{
	MyData<T> *temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}


template<class T>
class QueuePriority
{
	MyData<T> *first = nullptr;
	MyData<T> *last = nullptr;
	int size = 0;

public:
	~QueuePriority();
	void push(T val, PRIORITY pri);
	T pop();
	T peek();
	int getSize();     //получение текущего размера
	void clear();      //очистка стека
	void print() const;

};

template<class T>
inline void QueuePriority<T>::push(T val, PRIORITY pri)
{
	if (size == 0)
	{
		first = new MyData<T>;
		first->value = val;
		first->pri = pri;
		last = first;
	}
	else
	{
		MyData<T> *temp = new MyData<T>;
		temp->value = val;
		first->pri = pri;
		MyData<T> *temp2 = first;
		MyData<T> *temp3 = first;
		while (temp2->pri >= pri)
		{
			temp3 = temp2;
			temp2 = temp2->next;
		}
		temp3->next = temp;
		temp->next = temp2;
	}
	size++;
}

template<class T>
inline void QueuePriority<T>::print() const
{
	MyData<T> *temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
