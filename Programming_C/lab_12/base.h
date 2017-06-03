#ifndef BASE_H
#define BASE_H

#include <string.h>

typedef struct{
    int ProductID;
    char ProductName[50];
    char Color[25];
    float Price;
    float Weight;
    char City[25];
}
product;

typedef struct{
    int ShipmentID;
    int SupplierID;
    int ProductID;
    int Qty;
}ship;

typedef struct{
    int SupplierID;
    char SupplierName[50];
    int Status;
    char City[25];
} supplier;

#endif // BASE_H
