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

	int timeWait = 0;

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
	out << left << setw(12) << obj.fileName << setw(15) << obj.department << setw(5) << obj.timePrint << "     " << obj.timeWait;
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
	qPrint.superMethod();

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


template<>
inline void QueuePriority<TaskPrint>::superMethod()
{
	MyData<TaskPrint> *temp = first;
	while (temp)
	{
		temp->value.timeWait++;
		temp = temp->next;
	}
}



/*cout << endl;
	srand(time(0));
	PrintServer ps("10.6.0.155");
	string fName[] = { "zvit.xls", "otchet.doc", "file1.txt", "foto.jpg", "edweqw.ppt" };
	string dept[] = { "Admin", "Economics", "HR", "Transport", "Buhgalteria" };



	int t = 0;
	while (true)
	{
		int m = rand() % 5 +3;
		if (t%m == 0)
			ps.addTaskPrint(TaskPrint(fName[rand() % 5], dept[rand() % 5], rand() % 5 + 5));
		ps.work();
		t++;
		Sleep(1000);
	}*/