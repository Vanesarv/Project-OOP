#include "Location.h"
#include <iostream>

Location::Location(int section, int shelf, int number, double maximalQuantity)
    :f_section(section), f_shelf(shelf), f_number(number), f_maximalQuantity(maximalQuantity)
{
    std::cout << "Constuctor Product" << std::endl;
}

Location::~Location()
{
    std::cout << "Destructor Location" << std::endl;
}

void Location::setSection(int section)
{
    this->f_section = section;
}

void Location::setShelf(int shelf)
{
    this->f_shelf = shelf;
}

void Location::setNumber(int number)
{
    this->f_number = number;
}

void Location::setMaximalQuantity(double maximalQuantity)
{
    this->f_maximalQuantity = maximalQuantity;
}

void Location::print() const
{
    std::cout << "The section is:" << f_section << std::endl;
    std::cout << "The shelf is:" << f_shelf << std::endl;
    std::cout << "The number is:" << f_number << std::endl;
    std::cout << "The maximal quantity is:" << f_maximalQuantity << std::endl;
}
