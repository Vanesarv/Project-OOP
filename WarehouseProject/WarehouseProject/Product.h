#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "Date.h"
#include "Location.h"
#include <iostream>
#include <fstream>
#include <ostream>

class Product
{
public:
	char* f_name;
	char* f_manufacturer;
	Date f_addedToWarehouse;       
	Date f_expiryDate;             
	double f_unit;                 //0 - kg, 1 - l
	double f_quantity;
	Location f_productLocation;
	char* f_comment;

	void copy(const Product& other);
	void clean();

	bool isValidProduct();

public:

	Product();

	Product(const char* name, const char* manufacturer,
		 Date addedToWarehouse, Date expiryDate, double unit, unsigned int quantity,
		 Location productLocation, const char* comment);

	Product(const Product& other);

	Product& operator=(const Product& other);

	~Product();

	 const char* getname() const { return f_name; }
	 const char* getmanufacturer() const { return f_manufacturer; }
	 Date getAddedToWarehouse() const { return f_addedToWarehouse; }
	 Date getExpiryDate() const { return f_expiryDate; }
	 double getunit() const { return f_unit; }
	 unsigned int getquantity() const { return f_quantity; }
	 Location getProductLocation() const { return f_productLocation; }
	 const char* getComment() const { return f_comment; }

	void setname(const char* name);
	void setmanufacturer(const char* manufacturer);
	void setAddedToWarehouse(Date addedToWarehouse);
	void setExpiryDate(Date expiryDate);
	void setUnit(double unit);
	void setQuantity(unsigned int quantity);
	void setProductLocation(Location productLocation);
	void setComment(const char* comment);

	void print() const;
};

#endif



