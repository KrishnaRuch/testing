#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_management.h"
#include "product_management.h"

// Forward declarations
void postLoginMenu();

void mainMenu() {
    int choice;
    while (1) {
        printf("Welcome to the Online Retail Shop!\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    postLoginMenu(); // Call the function for the next menu after successful login
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void postLoginMenu() {
    int choice;
    while (1) {
        printf("\nPost Login Menu\n");
        printf("1. View Products\n");
        printf("2. Add Product\n");
        printf("3. Buy Product\n");
        printf("4. Sell Product\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewProducts(); // View available products
                break;
            case 2:
                addProduct(); // Add a new product (both buyer and seller can access this)
                break;
            case 3:
                buyProduct(); // Buy a product
                break;
            case 4:
                sellProduct(); // Sell a product
                break;
            case 5:
                return; // Log out and go back to main menu
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    loadUsers();
    loadProducts();
    mainMenu();
    saveUsers();
    saveProducts();
    return 0;
}
