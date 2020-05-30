#include "Product.h"
#include <iostream>
#include<cstring>

Product::Product()
{
	std::cout << "Default Constuctor Product" << std::endl;
}

Product::Product(const char* name, const char* manufacturer, Date addedToWarehouse,
	 Date expiryDate, double unit, unsigned int quantity, Location productLocation, const char* comment)
	: f_name(new char[strlen(name) + 1]), f_manufacturer(new char[strlen(manufacturer) + 1])
		, f_addedToWarehouse(addedToWarehouse), f_expiryDate(expiryDate),
	f_quantity(quantity), f_comment(new char[strlen(comment) + 1])
	{
		strcpy(f_name, name);
		strcpy(f_manufacturer, manufacturer);
		strcpy(f_comment, comment);

		std::cout << "Constuctor Product" << std::endl;
	}

Product::Product(const Product& other)
{
	copy(other);
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		clean();
		copy(other);
	}
	return *this;
}

Product::~Product()
{
	clean();
}

void Product::copy(const Product& other)
{
	f_name = new char[strlen(other.f_name) + 1];
	f_manufacturer = new char[strlen(other.f_manufacturer) + 1];
	f_comment = new char[strlen(other.f_comment) + 1];

	strcpy(f_name, other.f_name);
	strcpy(f_manufacturer, other.f_manufacturer);
	strcpy(f_comment, other.f_comment);

	Date f_addedToWarehouse = other.f_addedToWarehouse;
	Date f_expiryDate = other.f_expiryDate;
	f_unit = other.f_unit;
	f_quantity = other.f_quantity;
	Location f_productLocation = other.f_productLocation;
}

void Product::clean()
{
	delete[] f_name;
	f_name = nullptr;

	delete[] f_manufacturer;
	f_manufacturer = nullptr;

	delete[] f_comment;
	f_comment = nullptr;
}

bool Product::isValidProduct()
{
	{
		if (f_addedToWarehouse.f_isValidDate && f_expiryDate.f_isValidDate &&
			f_unit == 0 && f_unit == 1 && f_quantity <= f_productLocation.f_maximalQuantity)
		{
			return 1;
		}
		return 0;
	}
}

void Product::setname(const char* name)
{
	delete[] f_name;
	f_name = new char[strlen(name) + 1];
	strcpy(f_name, name);
}

void Product::setmanufacturer(const char* manufacturer)
{
	delete[] f_manufacturer;
	f_name = new char[strlen(manufacturer) + 1];
	strcpy(f_manufacturer, manufacturer);
}

void Product::setAddedToWarehouse(Date addedToWarehouse)
{
	this->f_addedToWarehouse = addedToWarehouse;
}

void Product::setExpiryDate(Date expiryDate)
{
	this->f_expiryDate = expiryDate;
}

void Product::setUnit(double unit)
{
	this->f_unit = unit;
}

void Product::setQuantity(unsigned int quantity)
{
	this->f_quantity = quantity;
}

void Product::setProductLocation(Location productLocation)
{
	this->f_productLocation = productLocation;
}

void Product::setComment(const char* comment)
{

	delete[] f_comment;
	f_comment = new char[strlen(comment) + 1];
	strcpy(f_comment, comment);
}


void Product::print() const
{
	std::cout << "The name is:" << f_name << std::endl;
	std::cout << "The manufacturer's name is:" << f_manufacturer << std::endl;
	std::cout << "The unit of measure is:" << f_unit << std::endl;
	std::cout << "The quantity is:" << f_quantity << std::endl;
	std::cout << "The comment is:" << f_comment << std::endl;

	f_addedToWarehouse.print();
	f_expiryDate.print();
	f_productLocation.print();
}
