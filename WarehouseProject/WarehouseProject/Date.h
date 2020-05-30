#ifndef __DATE_H
#define __DATE_H 

#include <iostream>
 
class Date
{
public:
    int f_day;
    int f_month;
    int f_year;

    bool f_isLeapYear();
    bool f_isValidDate();

public:
    Date(int day = 0, int month = 0, int year = 0);
    ~Date();

    int getDay() const { return f_day; }
    int getMonth() const { return f_month; }
    int getYear() const { return f_year; }

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    void print() const;

};

#endif