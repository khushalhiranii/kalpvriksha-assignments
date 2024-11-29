#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// User schema structure
struct User {
    char id[MAX_SIZE];
    char name[MAX_SIZE];
    int age;
};

// Helper function to check if a user exists
int userExists(const char *id) {
    FILE *fp = fopen("users.txt", "r");
    if (!fp) return 0;

    char buffer[MAX_SIZE];
    struct User user;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "%[^,],%[^,],%d", user.id, user.name, &user.age) == 3) {
            if (strcmp(user.id, id) == 0) {
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

// Add a new user to the database
void addUser() {
    FILE *fp = fopen("users.txt", "a");
    if (!fp) {
        printf("Error: Could not open database.\n");
        return;
    }

    struct User user;
    char another = 'y';

    while (another == 'y') {
        fflush(stdin);
        printf("\nEnter user ID: ");
        fgets(user.id, MAX_SIZE, stdin);
        strtok(user.id, "\n");  // Remove trailing newline

        while (userExists(user.id)) {
            printf("Error: User with this ID already exists. Enter a different ID: ");
            fgets(user.id, MAX_SIZE, stdin);
            strtok(user.id, "\n");
        }

        printf("Enter user name: ");
        fgets(user.name, MAX_SIZE, stdin);
        strtok(user.name, "\n");

        printf("Enter user age: ");
        scanf("%d", &user.age);

        fprintf(fp, "%s,%s,%d\n", user.id, user.name, user.age);
        printf("User added successfully.\n");

        printf("Add another user? (y/n): ");
        fflush(stdin);
        scanf(" %c", &another);
    }

    fclose(fp);
}

// Display all users
void displayUsers() {
    FILE *fp = fopen("users.txt", "r");
    if (!fp) {
        printf("No users found in the database.\n");
        return;
    }

    struct User user;
    char buffer[MAX_SIZE];
    printf("ID       Name           Age\n");
    printf("----------------------------------\n");

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "%[^,],%[^,],%d", user.id, user.name, &user.age) == 3) {
            printf("%-8s %-15s %-3d\n", user.id, user.name, user.age);
        }
    }

    fclose(fp);
}

// Delete a user by ID
int deleteUser(const char *id) {
    if (!userExists(id)) {
        printf("Error: User with ID '%s' does not exist.\n", id);
        return 0;
    }

    FILE *fp = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        printf("Error: Could not open database.\n");
        return 0;
    }

    char buffer[MAX_SIZE];
    struct User user;
    int found = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "%[^,],%[^,],%d", user.id, user.name, &user.age) == 3) {
            if (strcmp(user.id, id) != 0) {
                fprintf(temp, "%s,%s,%d\n", user.id, user.name, user.age);
            } else {
                found = 1;
            }
        }
    }

    fclose(fp);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found) {
        printf("User with ID '%s' deleted successfully.\n", id);
    }
    return found;
}

// Update a user by ID
void updateUser(const char *id) {
    if (!deleteUser(id)) {
        return;
    }

    struct User user;
    strcpy(user.id, id);

    printf("Enter new name for user: ");
    fflush(stdin);
    fgets(user.name, MAX_SIZE, stdin);
    strtok(user.name, "\n");

    printf("Enter new age for user: ");
    scanf("%d", &user.age);

    FILE *fp = fopen("users.txt", "a");
    if (!fp) {
        printf("Error: Could not open database.\n");
        return;
    }

    fprintf(fp, "%s,%s,%d\n", user.id, user.name, user.age);
    fclose(fp);

    printf("User updated successfully.\n");
}

// Menu to handle user operations
void menu() {
    int choice;

    do {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. Display All Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3: {
                char id[MAX_SIZE];
                printf("Enter the ID of the user to update: ");
                fflush(stdin);
                fgets(id, MAX_SIZE, stdin);
                strtok(id, "\n");
                updateUser(id);
                break;
            }
            case 4: {
                char id[MAX_SIZE];
                printf("Enter the ID of the user to delete: ");
                fflush(stdin);
                fgets(id, MAX_SIZE, stdin);
                strtok(id, "\n");
                deleteUser(id);
                break;
            }
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
