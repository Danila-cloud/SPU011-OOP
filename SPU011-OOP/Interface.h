#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class ILogger
{
public:
	virtual ~ILogger() {}
	virtual void openLog() = 0;
	virtual void closeLog() = 0;
	virtual void writeError(string message) = 0;
};


class ConsoleLog : public ILogger
{
public:
	virtual void openLog() override {};
	virtual void closeLog() override {};
	virtual void writeError(string message) override 
	{
		cout << message << endl;
	}
};

class FileLog : public ILogger
{
	string fName;
	ofstream out;
public:
	FileLog(string n) :fName(n) {}
	virtual void openLog() override 
	{
		out.open(fName, ios::app);
	}
	virtual void closeLog() override 
	{
		out.close();
	}
	virtual void writeError(string message) override
	{
		openLog();
		out << message << endl;
		closeLog();
	}
};


double mySQRT(double value, ILogger & log)
{
	if (value < 0)
	{
		char buff[80];
		_itoa(value, buff, 10);
		log.writeError("Value negativ: " + (string)buff);
		return 0;
	}
	return sqrt(value);
}

