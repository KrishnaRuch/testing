#ifndef PRODUCT_MANAGEMENT_H
#define PRODUCT_MANAGEMENT_H

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

extern Product products[MAX_PRODUCTS];
extern int productCount;

void addProduct();
void viewProducts();
void buyProduct();
void sellProduct();
void loadProducts();
void saveProducts();

#endif
