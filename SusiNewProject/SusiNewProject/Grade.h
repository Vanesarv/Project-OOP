#pragma once

#include "Student.h"
#include "Subject.h"
#include <iostream>

class Grade
{
public:

     unsigned int s_grade;
     Student s_gradedStudent;  //оценка на студент
     Subject s_gradedSubject;  //оценка по предмет

public:
    Grade();
    Grade(unsigned int grade, Student gradedStudent, Subject gradedGubject);
    ~Grade();

    unsigned int getgrade() const { return s_grade; }
    Student getGradedStudent() const { return s_gradedStudent; }
    Subject getGradedSubject() const { return s_gradedSubject; }

    void setGrade(unsigned int grade);
    void setGradedStudent(Student gradedStudent);
    void setGradedSubject(Subject gradedSubject);

    void print() const;
};

