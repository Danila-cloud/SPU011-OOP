#pragma once
#include"BTree.h"
#include"List.h"
#include<string>
#include<iomanip>



class Protokol
{
	string numTS;
	string date;
	string numPPN;
	string tag;
	int sum;
	bool pay = false;

public:
	Protokol() {}
	string getNumTS() { return numTS; }

	friend ostream & operator << (ostream & out, const Protokol & p);
	friend ostream & operator << (ostream & out, const Protokol * p);
	friend istream & operator >> (istream & in, Protokol & p);
	friend istream & operator >> (istream & in, Protokol * p);

};

ostream & operator<<(ostream & out, const Protokol & p)
{
	out << p.numTS << "  " << p.date << "  " << setw(6) << left << p.numPPN << setw(20) << p.tag << setw(6) << p.sum
		<< ((p.pay) ? "��������" : "�� ��������") << endl;
	return out;
}

ostream& operator<<(ostream& out, const Protokol * p)
{
	out << p->numTS << "  " << p->date << "  " << setw(6) << left << p->numPPN << setw(20) << p->tag << setw(6) << p->sum
		<< ((p->pay) ? "��������" : "�� ��������") << endl;
	return out;
}

inline istream & operator>>(istream & in, Protokol & p)
{
	cout << "����� �� : "; getline(in, p.numTS);
	cout << "����     : "; getline(in, p.date);
	cout << "����� �� : "; getline(in, p.numPPN);
	cout << "�������� : "; getline(in, p.tag);
	cout << "�����    : "; in >> p.sum;
	in.ignore();
	return in;
}

inline istream & operator>>(istream & in, Protokol * p)
{
	cout << "����� �� : "; getline(in, p->numTS);
	cout << "����     : "; getline(in, p->date);
	cout << "����� �� : "; getline(in, p->numPPN);
	cout << "�������� : "; getline(in, p->tag);
	cout << "�����    : "; in >> p->sum;
	in.ignore();
	return in;
}

class BasePenalty
{
	BTree<string, List<Protokol*>> base;

public:
	void menu();
	void addProtokol();
	void print();
	void find();
	void setPay();
};

void BasePenalty::menu()
{
	do
	{
		system("cls");
		cout << "1. �������� ��������" << endl;
		cout << "2. ������ ����" << endl;
		cout << "3. ����� �� ������ ��" << endl;
		cout << "4. ���������� ������" << endl;
		cout << "5. ������ �� ������" << endl;
		cout << "0. �����" << endl;
		int n;
		cin >> n;
		cin.ignore();
		switch (n)
		{
		case 1:
			addProtokol();
			break;
		case 2:
			print();
			break;
		case 0:
			exit(0);
		default:
			break;
		}

	} while (true);
	
}

inline void BasePenalty::addProtokol()
{
	cout << " �������� ��������:" << endl;
	cout << "------------------------" << endl;
	Protokol * prot = new Protokol;
	cin >> prot;
	List<Protokol*> * list = base.get(prot->getNumTS());
	if (!list)
	{
		cout << "������ ����� �� ����������� � ���� � ����� ��������" << endl;
		List<Protokol*> newList;
		newList.push_front(prot);
		base.push_r(prot->getNumTS(), newList);
	}
	else
	{
		list->push_front(prot);
	}
	cout << "����� ������� ��������" << endl;
}

inline void BasePenalty::print()
{
	base.print();
	system("pause");
}
