#include "Warehouse.h"

bool Warehouse
::compareDates(Date f_firstDate, Date f_secondDate)
{
    if (f_firstDate.f_year > f_secondDate.f_year)
    {
        return 0;
    }
    else
    {
        if (f_firstDate.f_year == f_secondDate.f_year)
        {
            if (f_firstDate.f_month > f_secondDate.f_month)
            {
                return 0;
            }
            else
            {
                if (f_firstDate.f_month == f_secondDate.f_month)
                {
                    if (f_firstDate.f_day > f_secondDate.f_day)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                }
                else
                {
                    return 1;
                }
            }
        }
        else
        {
            return 1;
        }
    }
}

Product* Warehouse::allProductWithFixedName(char* f_fixedName)
{
    {
        Product* result;
        int j = 0;
        for (int i = 0; i < f_numberOfProducts; i++)
        {
            if (isEqual(f_fixedName, f_products[i].f_name))
            {
                result[j] = f_products[i];
                j++;
            }
        }
        return result;
    }
}

bool Warehouse::isSomeProductElementOfProducts(Product f_oneProduct, Product* f_someProducts, int f_someProductsSize)
{
    {
        for (i = 0; i < f_productsSize; i++)
        {
            if (f_oneProduct == f_someProducts[i])
            {
                return 1;
            }
        }
        return 0;
    }
}

void Warehouse::allowUserToSetLocation()
{
    {
        std::cout << "Insert section:";
        std::cin >> f_section;
        std::cout << "Insert shelf:";
        std::cin >> f_shelf;
        std::cout << "Insert number:";
        std::cin >> f_number;

        for (int i = 0; i < f_numberOfLocations; i++)
        {
            if (f_section == f_locations[i].f_section && f_shelf == f_locations[i].f_shelf &&
                f_number == f_locations[i].f_number)
            {
                if (f_locations[i].isLocationEmpty)
                {
                    f_addedLocation = new Location(f_section, f_shelf, f_number, f_locations[i].f_maximalQuantity, 1);
                    f_locations[i].isLocationEmpty = 0;
                    x = 1;
                }
                else
                {
                    std::cout << "Sorry this location is not possible.";
                    return;
                }
            }
        }
        std::cout << "Sorry this is not a valid location";

    }
}

void Warehouse::add()
{
    {
        std::cout << "Please fill the data about product" << std::endl;

        std::cout << "Insert product name:";
        std::cin >> f_name;
        std::cout << "Insert manufacturer:";
        std::cin >> f_manufacturer;
        std::cout << "Day when product is added";
        std::cin >> f_day;
        std::cout << "Month when product is added";
        std::cin >> f_month;
        std::cout << "Year when product is added";
        std::cin >> f_year;
        Date f_addedToWarehouse = new Date(f_dayWhenAdded, f_monthWhenAdded, f_yearWhenAdded);

        std::cout << "Day when product expires";
        std::cin >> f_dayOfExpiry;
        std::cout << "Month when product expires";
        std::cin >> f_monthOfExpiry;
        std::cout << "Year when product expires";
        std::cin >> f_yearOfExpiry;
        Date f_expiryDate = new Date(f_dayOfExpiry, f_monthOfExpiry, f_yearOfExpiry);

        std::cout << "Choose units - 0 for kg and 1 for litres: ";
        std::cin >> f_unit;

        std::cout << "Insert quantity: ";
        std::cin >> f_quantity;

        for (int i = 0; i < f_numberOfProducts; i++)
        {
            if (isEqual(f_name, f_products[i].f_name))
            {
                if (isEqual(f_manufacturer, f_products[i].f_manufacturer))
                {
                    std::cout << "Sorry, this trade mark is used by other manufacturer" << std::endl;
                    return;
                }

                if (f_unit != f_products[i].f_unit)
                {
                    std::cout << "You try to use different units. Please try again later!" << std::endl;
                    return;
                }

                if (f_dayOfExpiry == f_products[i].f_expiryDate)
                {
                    Location f_currentProductLocation = f_products[i].f_productLocation;
                    int f_maxCapacity = f_currentProductLocation.f_maximalQuantity;
                    if (f_quantity + f_products[i].f_quantity <= f_currentProductLocation)
                    {
                        Product f_newProduct = new Product(f_name, f_manufacturer, f_addedToWarehouse,
                            f_expiryDate, f_unit, f_quantity, f_products[i].f_productLocation, f_comment);
                        if (f_newProduct == f_products[i])
                        {
                            f_products[i].f_quantity = f_quantity + f_products[i].f_quantity;
                        }

                        else
                        {
                            f_products[f_numberOfProducts] = f_newProduct;
                            f_numberOfProducts++;
                        }
                    }

                    else
                    {
                        allowUserToSetLocation();
                        if (x == 0)
                        {
                            std::cout << "Sorry man, try again";
                            return;
                        }
                        Product f_newProduct = new Product(f_name, f_manufacturer, f_addedToWarehouse, f_expiryDate,
                            f_unit, f_quantity, f_addedLocation, f_comment);
                        f_products[f_numberOfProducts] = f_newProduct;
                        f_numberOfProducts++;
                        x = 0;
                        f_addedLocation = Location();
                    }
                }

            }
        }

        allowUserToSetLocation();
        if (x == 0)
        {
            std::cout << "Sorry man, try again";
            return;
        }

        Product f_newProduct = new Product(f_name, f_manufacturer, f_addedToWarehouse, f_expiryDate,
            f_unit, f_quantity, f_addedLocation, f_comment);
        f_products[f_numberOfProducts] = f_newProduct;
        f_numberOfProducts++;
        x = 0;
        f_addedLocation = Location();
    }
}

