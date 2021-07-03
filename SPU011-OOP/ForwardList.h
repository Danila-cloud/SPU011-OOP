#pragma once
#include"MyData.h"


template<class T>
class ForwardList
{
	MyData<T> * first = nullptr;
	MyData<T> * last = nullptr;
	int length = 0;

public:
	~ForwardList() { clear(); };
	ForwardList() {}
	//List(const List & obj);
	//List operator=(const List & obj);
	void push_front(T val);
	void push_back(T val);
	void push_at(T val, int ind);
	T pop_front();
	T pop_back();
	T pop_at(int ind);
	T peek_front();
	T peek_back();
	T peek_at(int ind);
	T operator[](int ind);
	bool isEmpty();
	void print();
	void print(int x, int y);
	void clear();
	int  getLength();
	void sort();
	void sort_reverse();
	ForwardList<T> operator+(const ForwardList & obj);
	ForwardList<T> operator*(const ForwardList & obj);

	template<class T>
	friend ostream & operator <<(ostream & out, const ForwardList<T> & obj);

};

template<class T>
inline void ForwardList<T>::push_front(T val)
{
	if (length == 0)
	{
		first = last = new MyData<T>;
		first->value = val;
	}
	else
	{
		MyData<T> * temp = new MyData<T>;
		temp->value = val;
		temp->next = first;
		first->prev = temp;
		first = temp;
	}
	length++;
}

template<class T>
inline void ForwardList<T>::push_back(T val)
{
	if (length == 0)
	{
		first = last = new MyData<T>;
		first->value = val;
	}
	else
	{
		MyData<T> * temp = new MyData<T>;
		temp->value = val;
		temp->prev = last;
		last->next = temp;
		last = temp;
	}
	length++;
}

template<class T>
inline void ForwardList<T>::push_at(T val, int ind)
{
	if (ind >= 0 && ind <= length)
	{
		if (ind == 0)
			push_front(val);
		else
		{
			if (ind == length)
				push_back(val);
			else
			{
				MyData<T> * temp = new MyData<T>;
				temp->value = val;
				MyData<T> * temp2;
				if (ind <= length / 2)
				{
					temp2 = first;
					for (size_t i = 0; i < ind - 1; i++)
					{
						temp2 = temp2->next;
					}
				}
				else
				{
					temp2 = last;
					for (size_t i = 0; i < length - ind; i++)
					{
						temp2 = temp2->prev;
					}
				}
				temp->next = temp2->next;
				temp->prev = temp2;
				temp2->next->prev = temp;
				temp2->next = temp;
				length++;
			}
		}
	}
	else
	{
		//
	}
}

template<class T>
inline T ForwardList<T>::pop_front()
{
	if (length)
	{
		T val = first->value;
		first = first->next;
		if (first)
		{
			delete first->prev;
			first->prev = nullptr;
		}
		length--;
		return val;
	}
	return T();
}

template<class T>
inline T ForwardList<T>::pop_back()
{
	if (length)
	{
		T val = last->value;
		last = last->prev;
		if (last)
		{
			delete last->next;
			last->next = nullptr;
		}
		length--;
		return val;
	}
	return T();
}

template<class T>
inline T ForwardList<T>::pop_at(int ind)
{
	if (ind >= 0 && ind <= length)
	{
		if (ind == 0)
			return pop_front();
		else
		{
			if (ind == length - 1)
				return pop_back();
			else
			{
				
				MyData<T> * temp;
				if (ind <= length / 2)
				{
					temp = first;
					for (size_t i = 0; i < ind - 1; i++)
					{
						temp = temp->next;
					}
				}
				else
				{
					temp = last;
					for (size_t i = 0; i < length - ind; i++)
					{
						temp = temp->prev;
					}
				}
				T val = temp->next->value;
				temp->next = temp->next->next;
				delete temp->next->prev;
				temp->next->prev = temp;
				length--;
				return val;
			}
		}
	}
	return T();
}

template<class T>
inline void ForwardList<T>::print()
{
	if (length == 0)
	{
		cout << "ForwardList empty";
		return;
	}
	MyData<T> * temp = first;
	while (temp)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
}

template<class T>
inline void ForwardList<T>::clear()
{
	while (length)
		pop_front();
}
