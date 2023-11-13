#include <stdio.h>
#include <string.h>

union Flag {
    int active;
    char status[10];
};

struct User {
    char username[50];
    char password[50];
    union Flag userFlag;
};

void registerUser() {
    struct User newUser;

    printf("Enter a username: ");
    scanf("%s", newUser.username);

    printf("Enter a password: ");
    scanf("%s", newUser.password);

    printf("Set user flag (true/1 or false/0): ");
    scanf("%s", newUser.userFlag.status);

    printf("Registration successful! Username: %s, Password: %s, Flag: %s\n",
           newUser.username, newUser.password, newUser.userFlag.status);
}


void loginUser() {
    struct User enteredUser;
    struct User storedUser;

    strcpy(storedUser.username, "exampleUser");
    strcpy(storedUser.password, "examplePassword");
    storedUser.userFlag.active = 1; 
    printf("Enter your username: ");
    scanf("%s", enteredUser.username);

    printf("Enter your password: ");
    scanf("%s", enteredUser.password);

    if (strcmp(enteredUser.username, storedUser.username) == 0 &&
        strcmp(enteredUser.password, storedUser.password) == 0 &&
        storedUser.userFlag.active) {
        printf("Login successful!\n");
    } else {
        printf("Login failed. Incorrect username, password, or user inactive.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}