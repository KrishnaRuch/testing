#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#define MAX_USERS 100

typedef struct {
    char username[50];
    char password[50];
} User;

extern User users[MAX_USERS];
extern int userCount;

void registerUser();
int loginUser();
void loadUsers();
void saveUsers();

#endif
