#include <curses.h>
#include "user_management.h"
#include "product_management.h"

// Forward declaration
void postLoginMenu();

void mainMenu() {
    int choice;
    initscr(); // Initialize the screen
    noecho();  // Don't echo input characters
    cbreak();  // Disable line buffering
    keypad(stdscr, TRUE); // Enable special keys like arrows

    while (1) {
        clear();
        mvprintw(1, 1, "Welcome to the Online Retail Shop!");
        mvprintw(3, 1, "1. Register");
        mvprintw(4, 1, "2. Login");
        mvprintw(5, 1, "3. Exit");
        mvprintw(7, 1, "Enter your choice: ");
        refresh();

        choice = getch();
        
        switch (choice) {
            case '1':
                clear();
                registerUser();
                break;
            case '2':
                clear();
                if (loginUser()) {
                    postLoginMenu();
                }
                break;
            case '3':
                endwin(); // End the curses mode
                return;
            default:
                mvprintw(9, 1, "Invalid choice! Please try again.");
                refresh();
                getch(); // Wait for user to acknowledge
        }
    }
}

void postLoginMenu() {
    int choice;

    while (1) {
        clear();
        mvprintw(1, 1, "Post Login Menu");
        mvprintw(3, 1, "1. View Products");
        mvprintw(4, 1, "2. Add Product");
        mvprintw(5, 1, "3. Buy Product");
        mvprintw(6, 1, "4. Sell Product");
        mvprintw(7, 1, "5. Logout");
        mvprintw(9, 1, "Enter your choice: ");
        refresh();

        choice = getch();

        switch (choice) {
            case '1':
                clear();
                viewProducts();
                getch(); // Wait to allow user to read products
                break;
            case '2':
                clear();
                addProduct();
                getch(); // Wait to allow user to acknowledge
                break;
            case '3':
                clear();
                buyProduct();
                getch();
                break;
            case '4':
                clear();
                sellProduct();
                getch();
                break;
            case '5':
                return; // Log out and go back to main menu
            default:
                mvprintw(11, 1, "Invalid choice! Please try again.");
                refresh();
                getch();
        }
    }
}
