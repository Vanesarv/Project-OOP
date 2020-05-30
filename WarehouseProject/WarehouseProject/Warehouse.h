#ifndef __WAREHOUSE_H
#define __WAREHOUSE_H 

#include"Date.h"
#include "Location.h"
#include "Product.h"
#include "Location.h"
#include <iostream>
#include <cstring>

class Warehouse
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

    int f_section;
    int f_shelf;
    int f_number;
    double f_maximalQuantity;

    int f_day;
    int f_month;
    int f_year;

    int f_numberOfLocations;
    Location f_locations[100];
    int f_numberOfProducts;
    Product f_products[100];
    int x = 0;
    Location f_addedLocation;
    int f_dayWhenAdded;
    int f_monthWhenAdded;
    int f_yearWhenAdded;
    int f_dayOfExpiry;
    int f_monthOfExpiry;
    int f_yearOfExpiry;

    bool compareDates(Date f_firstDate, Date f_secondDate);  /// връща истина при f_firstDate е не по-късно f_secondDate

    Product* allProductWithFixedName(char* f_fixedName);

    bool isSomeProductElementOfProducts(Product f_oneProduct, Product* f_someProducts, int f_someProductsSize);

    void allowUserToSetLocation();

    void add();

};
#endif
