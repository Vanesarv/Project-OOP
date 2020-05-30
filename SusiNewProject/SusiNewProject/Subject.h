#pragma once

#include <iostream>
#include "Student.h"

class Subject
{
private:

    char* s_name;   //��� �� �������� ���������� 
    bool s_compulsory;  // ����  �������� ���������� � ������������ ��� ��������� "��/��"
    char* s_specialityDiscipline;     // ������������ � �������� ���������� 
    int s_disciplineCourse;   // ������ ���������� � ����� ����
    unsigned int s_numberDiscipline;   //����� �� �������� � �������� ����������
    Subject** s_students = nullptr;   
    
    int size = 0;
    int capacity = 0;

    void init(const char* name, bool compulsory, const char* specialityDiscipline, 
        unsigned int  disciplineCourse, unsigned int numberDiscipline, Subject** students);
    void copyFrom(const Subject& other);
    void clean();

    bool isValidSD(char* specialityDiscipline) const;
    bool isValidDC(int disciplineCourse) const;
    bool isValidND(int numberDiscipline) const;

public:

    Subject(const char* name, bool compulsory, const char* specialityDiscipline,
        unsigned int  disciplineCourse, unsigned int numberDiscipline, Subject** students);

    Subject();

    Subject(const Subject& other);

    Subject& operator=(const Subject& other);

    ~Subject();

    const char* getName() const;
    bool getCompulsory() const;
    char* getSpecialityDiscipline() const;
    int getDisciplineCourse() const;
    unsigned int getNumberDisciplinep() const;
    Subject** s_students() const;

    void setName(const char* name);
    void setSpecialityDiscipline(const char* specialityDiscipline);

    void print() const;

};

