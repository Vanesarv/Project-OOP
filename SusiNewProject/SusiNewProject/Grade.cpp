#include "Grade.h"
#include <iostream>

Grade::Grade()
{
	std::cout << "Default Constuctor Grade" << std::endl;
}

Grade::Grade(unsigned int grade, Student gradedStudent, Subject gradedSubject)
	:s_grade(grade), s_gradedStudent(gradedStudent), s_gradedSubject(gradedSubject)
{
	std::cout << "Constuctor Date" << std::endl;
}

Grade::~Grade()
{
	std::cout << "Destructor Grade" << std::endl;
}

void Grade::setGrade(unsigned int grade)
{
	this->s_grade = grade;
}

void Grade::setGradedStudent(Student gradedStudent)
{
	this->s_gradedStudent = gradedStudent;
}

void Grade::setGradedSubject(Subject gradedSubject)
{
	this->s_gradedSubject = gradedSubject;
}

void Grade::print() const
{
	std::cout << "The grade is:" << s_grade << std::endl;

	s_gradedStudent.print();
	s_gradedSubject.print();
}
