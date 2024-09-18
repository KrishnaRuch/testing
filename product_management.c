#include <stdio.h>
#include <string.h>
#include "product_management.h"

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Product limit reached. Cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    products[productCount] = newProduct;
    productCount++;

    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products available.\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        printf("%s - $%.2f (Quantity: %d)\n", products[i].name, products[i].price, products[i].quantity);
    }
}

void buyProduct() {
    char productName[50];
    int quantity;

    printf("Enter the product name you want to buy: ");
    scanf("%s", productName);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            if (products[i].quantity >= quantity) {
                products[i].quantity -= quantity;
                printf("Purchase successful!\n");
            } else {
                printf("Not enough stock.\n");
            }
            return;
        }
    }

    printf("Product not found.\n");
}

void sellProduct() {
    char productName[50];
    int quantity;
    float price;

    printf("Enter the product name you want to sell: ");
    scanf("%s", productName);
    printf("Enter the price: ");
    scanf("%f", &price);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            products[i].quantity += quantity;
            products[i].price = price;
            printf("Product stock updated.\n");
            return;
        }
    }

    Product newProduct;
    strcpy(newProduct.name, productName);
    newProduct.price = price;
    newProduct.quantity = quantity;

    products[productCount] = newProduct;
    productCount++;

    printf("Product added successfully!\n");
}

void loadProducts() {
    FILE *file = fopen("C:/Users/vesh4/Documents/testing/products.txt", "rb");
    if (file == NULL) {
        printf("No product data found. Starting fresh.\n");
        return;
    }

    // Read until the end of the file
    while (fread(&products[productCount], sizeof(Product), 1, file)) {
        productCount++;
    }

    fclose(file);
}

void saveProducts() {
    FILE *file = fopen("C:/Users/vesh4/Documents/testing/products.txt", "ab"); // Append new products
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(&products[productCount - 1], sizeof(Product), 1, file); // Only write the new product added
    fclose(file);
}
