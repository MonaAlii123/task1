#include <stdio.h>
#include <string.h>

#define MAX_USERS 200
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PASSWORD_LENGTH 100

struct User {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int userCount = 0;

// Registration

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    struct User newUser;
    printf(" please Enter  your name: ");
    fgets(newUser.name, MAX_NAME_LENGTH, stdin);
    printf("please Enter  your email: ");
    fgets(newUser.email, MAX_EMAIL_LENGTH, stdin);
    printf("please Enter  your password: ");
    fgets(newUser.password, MAX_PASSWORD_LENGTH, stdin);

    // Remove trailing newline characters from fgets
    newUser.name[strcspn(newUser.name, "\n")] = '\0';
    newUser.email[strcspn(newUser.email, "\n")] = '\0';
    newUser.password[strcspn(newUser.password, "\n")] = '\0';

    users[userCount++] = newUser;

    printf("Registration successful!\n");
}

//login

void loginUser() {
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("please Enter  your email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    printf("please Enter  your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    email[strcspn(email, "\n")] = '\0';
    password[strcspn(password, "\n")] = '\0';

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].email, email) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Invalid email or password. Please try again.\n");
}

//invalid operation or exist

int main() {
    int operation;

    do {
        printf("1. Register\n");
        printf("2.  Login\n");
        printf("3. Exit\n");
        printf("Enter your operation: ");
        scanf("%d", &operation);
        getchar(); // Consume the newline character left by scanf

        switch (operation) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid operation. Please try again.\n");
                break;
        }

        printf("\n");
    } while (operation != 3);

    return 0;
}



