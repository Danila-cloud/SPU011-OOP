#pragma once
#include"MyData.h"

template<class T, int size>
class StaticStack
{
	MyData<T> data[size];
	int top = 0;

public:
	void push(T val);  //положить в стек
	T pop();           // извлечение из стека
	T peek();          //просмотреть последний
	int getSize();     //получение текущего размера
	bool isEmpty();    //проверка на пустоту
	bool isFull();     //проверка на заполненность
	void clear();      //очистка стека
	void print();
};

template<class T, int size>
inline void StaticStack<T, size>::push(T val)
{
	if (top < size)
	{
		data[top++].value = val;
	}
	else
	{
		cout << "Stack overflow" << endl;
	}
}

template<class T, int size>
inline T StaticStack<T, size>::pop()
{
	return data[--top].value;
}

template<class T, int size>
inline T StaticStack<T, size>::peek()
{
	return data[top - 1].value;
}

template<class T, int size>
inline int StaticStack<T, size>::getSize()
{
	return top;
}

template<class T, int size>
inline bool StaticStack<T, size>::isEmpty()
{
	return top == 0;
}

template<class T, int size>
inline bool StaticStack<T, size>::isFull()
{
	return top == size;
}

template<class T, int size>
inline void StaticStack<T, size>::clear()
{
	top = 0;
}

template<class T, int size>
inline void StaticStack<T, size>::print()
{
	for (size_t i = 0; i < top; i++)
	{
		cout << data[i].value << " ";
	}
	cout << endl;
}





template<class T, int size>
class DynamicStack
{
	MyData<T> *data = nullptr;
	int top = 0;

public:
	~DynamicStack();
	void push(T val);  //положить в стек
	T pop();           // извлечение из стека
	T peek();          //просмотреть последний
	int getSize();     //получение текущего размера
	bool isEmpty();    //проверка на пустоту
	bool isFull();     //проверка на заполненность
	void clear();      //очистка стека
	void print() const;
};

template<class T, int size>
inline DynamicStack<T, size>::~DynamicStack()
{
	clear();
}

template<class T, int size>
inline void DynamicStack<T, size>::push(T val)
{
	if (top < size)
	{
		if (top == 0)
		{
			data = new MyData<T>;
			data->value = val;
		}
		else
		{
			MyData<T>* temp = new MyData<T>;
			temp->value = val;
			temp->next = data;
			data = temp;
		}
		top++;
	}
	else
	{
		cout << "Stack overflow" << endl;
	}
}

template<class T, int size>
inline T DynamicStack<T, size>::pop()
{
	T val = data->value;
	MyData<T> *temp = data;
	data = data->next;
	delete temp;
	top--;
	return val;
}

template<class T, int size>
inline T DynamicStack<T, size>::peek()
{
	if (top > 0)
		return data->value;
	else
	{
		cout << "Stack is empty!!!" << endl;
		system("pause");
		exit(1);
	}
}

template<class T, int size>
inline int DynamicStack<T, size>::getSize()
{
	return top;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isEmpty()
{
	return top == 0;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isFull()
{
	return top == size;
}

template<class T, int size>
inline void DynamicStack<T, size>::clear()
{
	MyData<T>* temp = data;
	while (data)
	{
		data = data->next;
		delete temp;
		temp = data;
		top--;
	}
}

template<class T, int size>
inline void DynamicStack<T, size>::print() const
{
	MyData<T> *temp = data;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
