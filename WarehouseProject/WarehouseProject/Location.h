#ifndef __LOCATION_H
#define __LOCATION_H 

#include <iostream>

class Location
{
    public:
	int f_section; 
	int f_shelf;
	int f_number;
	double f_maximalQuantity;

	bool isLocationEmpty;

public:

    Location(int section = 0, int shelf = 0, int number = 0, double maximalQuantity = 0);
    ~Location();

    int getSection() const { return f_section; }
    int getShelf() const { return f_shelf; }
    int getNumber() const { return f_number; }
    double getMaximalQuantity() const { return f_maximalQuantity; }

    void setSection(int section);
    void setShelf(int shelf);
    void setNumber(int number);
    void setMaximalQuantity(double maximalQuantity);


    void print() const;
};

#endif