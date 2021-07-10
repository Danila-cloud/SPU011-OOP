#pragma once
#include<iostream>
#include"List.h"

using namespace std;

namespace Composition
{
	class Engine
	{
	public:
		void start()
		{
			cout << "Engine start" << endl;
		}
	};

	class Car
	{
		Engine * engine;

	public:
		Car()
		{
			engine = new Engine;
		}
		~Car()
		{
			delete engine;
		}
		void move()
		{
			engine->start();
			cout << "I`m moving" << endl;
		}
	};
}



namespace Agrigation
{
	class Engine
	{
	public:
		void start()
		{
			cout << "Engine start" << endl;
		}
	};

	class Car
	{
		Engine * engine;

	public:
		void setEngine(Engine * en)
		{
			engine = en;
		}
		Engine* getEngine()
		{
			return engine;
		}
		void move()
		{
			engine->start();
			cout << "I`m moving" << endl;
		}
	};

	class Stend
	{
		Engine * engine;

	public:
		void setEngine(Engine * en)
		{
			engine = en;
		}
		Engine* getEngine()
		{
			return engine;
		}
		void test()
		{
			cout << "Set correct!!" << endl;
		}
	};
}


namespace Association
{
	class Teacher;

	class Student
	{
		string name;
		List<Teacher*> teachers;
		void addTeacher(Teacher * t);
	public:
		Student(string n) :name(n) {}
		string getName() { return name; }
		friend ostream & operator << (ostream & out, const Student & st);

		friend class Teacher;
	};


	class Teacher
	{
		string name;
		List<Student*> students;

	public:
		Teacher(string n) :name(n) {}
		string getName()const { return name; }
		void addStudent(Student* st)
		{
			students.push_back(st);
			st->addTeacher(this);
		}
		friend ostream & operator << (ostream & out, const Teacher & t)
		{
			if (t.students.getLength() == 0)
			{
				out << t.name << " не обучает никаких студентов" << endl;
				return out;
			}
			out << t.name << " обучает студентов : ";
			for (size_t i = 0; i < t.students.getLength(); i++)
			{
				out << t.students[i]->getName() << ", ";
			}
			return out;
		}



	};

	void Association::Student::addTeacher(Teacher * t)
	{
		teachers.push_back(t);
	}

	ostream & Association::operator<<(ostream & out, const Student & st)
	{
		if (st.teachers.getLength() == 0)
		{
			out << st.name << " не обучается ни у одного преподавателя" << endl;
			return out;
		}
		out << st.name << " обучается у преподавателя(ей) : ";
		for (size_t i = 0; i < st.teachers.getLength(); i++)
		{
			out << st.teachers[i]->getName() << ", ";
		}
		return out;
	}
}