#pragma once

#include <iostream>

#include "Status.h"

#include "Course.h"

class Student
{
public:
    char* s_name;
    unsigned int s_fn;
    Course s_course;      //course - enum class със стойности 1, 2, 3, 4
    char* s_speciality;
    unsigned short s_group;
    Status s_status;     //status - enum class със записан, прекъснал, завършил
    double s_average;

    void init(const char* name, unsigned int fn, Course course, const char* speciality, 
        unsigned short group, Status status, double average);
    void copyFrom(const Student& other);
    void clean();

    /*bool isValidFN(unsigned int fn) const;
    bool isValidGroup(unsigned short group) const;
    bool isValidSpeciality(const char* speciality) const;*/

public:

    Student(const char* name, unsigned int fn, Course course, const char* speciality,
        unsigned short group, Status status, double average);

    Student();

    Student(const Student& other);

    Student& operator=(const Student& other);

    ~Student();

    const char* getName() const;
    unsigned int getFN() const;
    Course getCourse() const;
    const char* getSpeciality() const;
    unsigned short getGroup() const;
    Status getStatus() const;
    double getAverage() const;

    void setName(const char* name);
    void setSpeciality(const char* speciality);

    void setFN(unsigned fn);
    void setCourse(Course course);
    void setGroup(unsigned short group);
    void setStatus(Status status);
    void setAverage(double average);

    void print() const;
};

