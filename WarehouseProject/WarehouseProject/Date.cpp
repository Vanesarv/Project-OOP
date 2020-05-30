#include "Date.h"

bool Date::f_isLeapYear()
{
    {
        if (f_year % 4 == 0)
        {
            if (f_year % 100 != 0)
            {
                return 1;
            }

            if (f_year % 400 == 0)
            {
                return 1;
            }
        }
        return 0;
    }
}

bool Date::f_isValidDate()
{
    {
        if (f_month < 1 && f_month > 12)
        {
            return 0;
        }

        if (f_month == 1 || f_month == 3 || f_month == 5 || f_month == 7 || f_month == 8 || f_month == 10 || f_month == 12)
        {
            if (f_day < 1 && f_day > 31)
            {
                return 0;
            }
        }

        if (f_month == 4 || f_month == 6 || f_month == 9 || f_month == 11)
        {
            if (f_day < 1 && f_day > 30)
            {
                return 0;
            }
        }

        if (f_isLeapYear())
        {
            if (f_day != 29)
            {
                return 0;
            }

        }
        else
        {
            if (f_day != 28)
            {
                return 0;
            }
        }

        return 1;
    }
}

Date::Date(int day, int month, int year)
    :f_day(day),f_month(month),f_year(year)
{
    std::cout << "Constuctor Date" << std::endl;
}

Date::~Date()
{
    std::cout << "Destructor Date" << std::endl;
}


void Date::setDay(int day)
{
    this->f_day = day;
}

void Date::setMonth(int month)
{
    this->f_month = month;
}

void Date::setYear(int year)
{
    this->f_year = year;
}

void Date::print() const
{
    std::cout << "The day is:" << f_day << std::endl;
    std::cout << "The month is:" << f_month << std::endl;
    std::cout << "The year is:" << f_year << std::endl;
}
