#pragma once
#include"Queue.h"
#include"List.h"
#include<iostream>
#include<iomanip>
#include<string>


using namespace std;




class TaskPrint
{
	string fileName;
	string department;
	int timePrint = -1;

public:
	TaskPrint() {}
	TaskPrint(string f, string d, int t) :fileName(f), department(d), timePrint(t) {}
	int getTimePrint();
	void setTimePrint(int t);
	PRIORITY getPriority() const;

	friend ostream & operator <<(ostream & out, const TaskPrint & obj);
};

int TaskPrint::getTimePrint()
{
	return timePrint;
}

inline void TaskPrint::setTimePrint(int t)
{
	timePrint = t;
}

inline PRIORITY TaskPrint::getPriority() const
{
	if (department == "Admin")
		return MEGAHIGH;
	if (department == "Economics")
		return HIGH;
	if (department == "HR")
		return MEDIUM;
	return LOW;
}

ostream & operator<<(ostream & out, const TaskPrint & obj)
{
	out << left << setw(12) << obj.fileName << setw(15) << obj.department << setw(5) << obj.timePrint;
	return out;
}

class PrintServer
{
	string ip;
	QueuePriority<TaskPrint> qPrint;
	List<TaskPrint> logs;
	TaskPrint currPrint, forLogs;


public:
	PrintServer(string ip) :ip(ip) {}
	void addTaskPrint(const TaskPrint &tp);
	void work();
};

void PrintServer::addTaskPrint(const TaskPrint & tp)
{
	qPrint.push(tp, tp.getPriority());
}

inline void PrintServer::work()
{
	if (currPrint.getTimePrint() == 0)
	{
		logs.push_back(forLogs);
	}

	if (currPrint.getTimePrint() != -1)
	{
		currPrint.setTimePrint(currPrint.getTimePrint() - 1);
	}

	system("cls");
	cout << "PrintServer: " << ip << endl;
	cout << "-------------------------------------" << endl;

	cout << endl << "Printing: " << endl;
	cout << "----------------------" << endl;
	if (currPrint.getTimePrint() != -1)
		cout << currPrint << endl;
	else
		cout << endl;

	cout << endl << "Waitings:                     Logs: " << endl;
	cout << "---------------------------         --------------------" << endl;
	qPrint.print();

	logs.print(40, 9);


	if (!qPrint.isEmpty() && currPrint.getTimePrint() == -1)
		currPrint = forLogs = qPrint.pop();

}
