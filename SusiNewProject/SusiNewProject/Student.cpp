#include "Student.h"
#include "Status.h"
#include <iostream>
#include <cstring>

void Student::init(const char* name, unsigned int fn, Course course, const char* speciality,
	unsigned short group, Status status, double average)
{
	s_name = new char[strlen(name) + 1];
	s_speciality = new char[strlen(speciality) + 1];

	this->s_fn = fn;
	this->s_course = course;
	this->s_group = group;
	this->s_status = status;
	this->s_average = average;

	if (s_name != nullptr && s_speciality != nullptr)
	{
		s_name = new char[strlen(name) + 1];
		s_speciality = new char[strlen(speciality) + 1];

		strcpy(s_name, name);
		strcpy(s_speciality, speciality);
	}
	else
	{
		s_name = nullptr;
		s_speciality = nullptr;
	}

}

void Student::copyFrom(const Student& other)
{
	if (s_name != nullptr && s_speciality != nullptr)
	{
		delete[] s_name;
		delete[] s_speciality;
	}

	s_name = new char[strlen(other.s_name) + 1];
	s_speciality = new char[strlen(other.s_speciality) + 1];

	strcpy(s_name, other.s_name);
	strcpy(s_speciality, other.s_speciality);

	this->s_fn= other.s_fn;
	this->s_course = other.s_course;
	this->s_group = other.s_group;
	this->s_status = other.s_status;
	this->s_average = other.s_average;
}

void Student::clean()
{
	delete[] s_name;
	s_name = nullptr;

	delete[] s_speciality;
	s_speciality = nullptr;
}

Student::Student(const char* name, unsigned int fn, Course course, const char* speciality,
	unsigned short group, Status status, double average)
{
	init(name, fn, course, speciality, group, status, average);
}

Student::Student()
{
	init(" ", 0, Course::FourthYear, " ", 0, Status::Empty, 0);
}

Student::Student(const Student& other)
{
	copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		this->clean();
		this->copyFrom(other);
	}
	return *this;
}

Student::~Student()
{
	delete[] s_name;
	delete[] s_speciality;
}

const char* Student::getName() const
{
	return s_name;
}

unsigned int Student::getFN() const
{
	return s_fn;
}

Course Student::getCourse() const
{
	return s_course;
}

const char* Student::getSpeciality() const
{
	return s_speciality;
}

unsigned short Student::getGroup() const
{
	return s_group;
}

Status Student::getStatus() const
{
	return s_status;
}

double Student::getAverage() const
{
	return s_average;
}

void Student::setName(const char* name)
{
	delete[] s_name;
	s_name = new char[strlen(name) + 1];
	strcpy(s_name, name);
}

void Student::setSpeciality(const char* speciality)
{
	delete[] s_speciality;
	s_speciality = new char[strlen(speciality) + 1];
	strcpy(s_speciality, speciality);
}

void Student::setFN(unsigned fn)
{
	this->s_fn = fn;
}

void Student::setCourse(Course course)
{
	this->s_course = course;
}

void Student::setGroup(unsigned short group)
{
	this->s_group = group;
}

void Student::setStatus(Status status)
{
	this->s_status = status;
}

void Student::setAverage(double average)
{
	this->s_average = average;
}

void Student::print() const
{
	std::cout << "The name is:" << s_name << std::endl;
	std::cout << "The faculty number is:" << s_fn << std::endl;
	std::cout << "The speciality is:" << s_speciality << std::endl;
	std::cout << "The group is:" << s_group << std::endl;
	std::cout << "The average is:" << s_average << std::endl;
}

