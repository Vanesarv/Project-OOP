#include "Subject.h"
#include <iostream>
#include <cstring>

void Subject::init(const char* name, bool compulsory, const char* specialityDiscipline,
	unsigned int disciplineCourse, unsigned int numberDiscipline, Subject** students)
{
	s_name = new char[strlen(name) + 1];
	s_specialityDiscipline = new char[strlen(specialityDiscipline) + 1];

	this->s_compulsory = compulsory;
	this->s_disciplineCourse = disciplineCourse;
	this->s_numberDiscipline = numberDiscipline;
	this->s_students = students;
	

	if (s_name != nullptr && s_specialityDiscipline != nullptr)
	{
		s_name = new char[strlen(name) + 1];
		s_specialityDiscipline = new char[strlen(specialityDiscipline) + 1];

		strcpy(s_name, name);
		strcpy(s_specialityDiscipline, specialityDiscipline);
	}
	else
	{
		s_name = nullptr;
		s_specialityDiscipline = nullptr;
	}
}

void Subject::copyFrom(const Subject& other)
{
	if (s_name != nullptr && s_specialityDiscipline != nullptr)
	{
		delete[] s_name;
		delete[] s_specialityDiscipline;
	}

	s_name = new char[strlen(other.s_name) + 1];
	s_specialityDiscipline = new char[strlen(other.s_specialityDiscipline) + 1];

	strcpy(s_name, other.s_name);
	strcpy(s_specialityDiscipline, other.s_specialityDiscipline);

	this->s_compulsory = other.s_compulsory;
	this->s_disciplineCourse = other.s_disciplineCourse;
	this->s_numberDiscipline = other.s_numberDiscipline;
	this->s_students = other.s_students;
}

void Subject::clean()
{
	delete[] s_name;
	delete[] s_specialityDiscipline;
}

bool Subject::isValidSD(char* specialityDiscipline) const
{
	return false;
}

bool Subject::isValidDC(int disciplineCourse) const
{
	return false;
}

bool Subject::isValidND(int numberDiscipline) const
{
	return false;
}

Subject::Subject(const char* name, bool compulsory, const char* specialityDiscipline,
	unsigned int disciplineCourse, unsigned int numberDiscipline, Subject** students)
{
	init(name, compulsory, specialityDiscipline, disciplineCourse, numberDiscipline, students);
}

Subject::Subject()
{
	init(" ", 0, " ", 0, 0, 0);
}

Subject::Subject(const Subject& other)
{
	copyFrom(other);
}

Subject& Subject::operator=(const Subject& other)
{
	if (this != &other)
	{
		clean();
		copyFrom(other);
	}
	return *this;
}

Subject::~Subject()
{
	delete[] s_name;
	delete[] s_specialityDiscipline;
}

const char* Subject::getName() const
{
	return s_name;
}

bool Subject::getCompulsory() const
{
	return s_compulsory;
}

char* Subject::getSpecialityDiscipline() const
{
	return s_specialityDiscipline;
}

int Subject::getDisciplineCourse() const
{
	return s_disciplineCourse;
}

unsigned int Subject::getNumberDisciplinep() const
{
	return s_numberDiscipline;
}

Subject** Subject::s_students() const
{
	return nullptr;
}

void Subject::setName(const char* name)
{
	delete[] s_name;
	s_name = new char[strlen(name) + 1];
	strcpy(s_name, name);
}

void Subject::setSpecialityDiscipline(const char* specialityDiscipline)
{
	delete[] s_specialityDiscipline;
	s_specialityDiscipline = new char[strlen(specialityDiscipline) + 1];
	strcpy(s_specialityDiscipline, specialityDiscipline);
}

void Subject::print() const
{
	std::cout << "The name is:" << s_name << std::endl;
	std::cout << "The compulsory is:" << s_compulsory << std::endl;
	std::cout << "The specialityDiscipline is:" << s_specialityDiscipline << std::endl;
	std::cout << "The disciplineCourse is:" << s_disciplineCourse << std::endl;
	std::cout << "The numberDiscipline is:" << s_numberDiscipline << std::endl;
	
	s_students.print();
}
