#include <stdio.h>
#include <string.h>
#include "user_management.h"

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[userCount] = newUser;
    userCount++;

    printf("Registration successful!\n");

    // Save the new user immediately after registration
    saveUsers();
}

int loginUser() {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return 1;
        }
    }
    printf("Login failed! Invalid credentials.\n");
    return 0;
}

void loadUsers() {
    FILE *file = fopen("C:/Users/vesh4/Documents/testing/usersinfo.txt", "rb");  // Open in read binary mode
    if (file == NULL) {
        printf("No user data found. Starting fresh.\n");
        return;
    }

    // Read the users from the file until EOF is reached
    while (fread(&users[userCount], sizeof(User), 1, file)) {
        userCount++;
    }

    fclose(file);
}

void saveUsers() {
    FILE *file = fopen("C:/Users/vesh4/Documents/testing/usersinfo.txt", "ab");  // Append mode to add new user data
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Save the last registered user only
    fwrite(&users[userCount - 1], sizeof(User), 1, file);

    fclose(file);
}

