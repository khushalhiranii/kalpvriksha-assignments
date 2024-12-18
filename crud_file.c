#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// User schema structure
struct User {
    int id;
    char name[MAX_SIZE];
    int age;
};


int isAlphabetic(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}


int validateName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isAlphabetic(name[i]) && (name[i] != ' ')) {
            return 0;
        }
    }
    return 1;
}

int validateAge(int age) {
    return age > 0;
}


int generateId() {
    FILE *idFile = fopen("id_counter.txt", "r+");
    int id = 1;

    if (!idFile) {
        idFile = fopen("id_counter.txt", "w");
        if (!idFile) {
            printf("Error: Could not open or create counter file.\n");
            exit(1);
        }
        fprintf(idFile, "%d", id);
    } else {
        fscanf(idFile, "%d", &id);
        id++;
        rewind(idFile);
        fprintf(idFile, "%d", id);
    }

    fclose(idFile);
    return id;
}


int userExists(int id) {
    FILE *usersData = fopen("users.txt", "r");
    if (!usersData) return 0;

    struct User user;
    char buffer[MAX_SIZE];

    while (fgets(buffer, sizeof(buffer), usersData)) {
        if (sscanf(buffer, "%d,%[^,],%d", &user.id, user.name, &user.age) == 3) {
            if (user.id == id) {
                fclose(usersData);
                return 1;
            }
        }
    }

    fclose(usersData);
    return 0;
}


void addUser() {
    FILE *usersData = fopen("users.txt", "a");
    if (!usersData) {
        printf("Error: Could not open database.\n");
        return;
    }

    struct User user;
    char another = 'y';

    while (another == 'y') {
        user.id = generateId();
        printf("\nAssigned User ID: %d\n", user.id);

        printf("Enter user name: ");
        scanf("%s", user.name);

        while (!validateName(user.name)) {
            printf("Error: Name must contain only alphabetic characters and spaces.\nEnter user name: ");
            scanf("%s", user.name);
        }

        printf("Enter user age: ");
        scanf("%d", &user.age);

        while (!validateAge(user.age)) {
            printf("Error: Age must be a positive integer.\nEnter user age: ");
            scanf("%d", &user.age);
        }
        getchar();

        fprintf(usersData, "%d,%s,%d\n", user.id, user.name, user.age);
        printf("User added successfully.\n");

        printf("Add another user? (y/n): ");
        scanf(" %c", &another);
        getchar();
    }

    fclose(usersData);
}


void displayUsers() {
    FILE *usersData = fopen("users.txt", "r");
    if (!usersData) {
        printf("No users found in the database.\n");
        return;
    }

    struct User user;
    char buffer[MAX_SIZE];
    printf("\nID       Name           Age\n");
    printf("----------------------------------\n");

    while (fgets(buffer, sizeof(buffer), usersData)) {
        if (sscanf(buffer, "%d,%[^,],%d", &user.id, user.name, &user.age) == 3) {
            printf("%-8d %-15s %-3d\n", user.id, user.name, user.age);
        }
    }

    fclose(usersData);
}


int deleteUser(int id) {
    if (!userExists(id)) {
        printf("Error: User with ID '%d' does not exist.\n", id);
        return 0;
    }

    FILE *usersData = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!usersData || !temp) {
        printf("Error: Could not open database.\n");
        return 0;
    }

    struct User user;
    char buffer[MAX_SIZE];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), usersData)) {
        if (sscanf(buffer, "%d,%[^,],%d", &user.id, user.name, &user.age) == 3) {
            if (user.id != id) {
                fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
            } else {
                found = 1;
            }
        }
    }

    fclose(usersData);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt", "users.txt");

    printf("User with ID '%d' deleted successfully.\n", id);
    return found;
}


void updateUser(int id) {
    FILE *usersData = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!usersData || !temp) {
        printf("Error: Could not open database.\n");
        return;
    }

    struct User user;
    char buffer[MAX_SIZE];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), usersData)) {
        if (sscanf(buffer, "%d,%[^,],%d", &user.id, user.name, &user.age) == 3) {
            if (user.id == id) {
                found = 1;
                printf("Enter new name for user: ");
                scanf("%s", user.name);

                while (!validateName(user.name)) {
                    printf("Error: Name must contain only alphabetic characters and spaces.\nEnter new name: ");
                    scanf("%s", user.name);
                }

                printf("Enter new age for user: ");
                scanf("%d", &user.age);
                while (!validateAge(user.age)) {
                    printf("Error: Age must be a positive integer.\nEnter new age: ");
                    scanf("%d", &user.age);
                }
                getchar();

                printf("User updated successfully.\n");
            }
            
            fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
        }
    }

    fclose(usersData);
    fclose(temp);

    if (!found) {
        printf("Error: User with ID '%d' not found.\n", id);
        remove("temp.txt");
    } else {
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }
}


void inputForDelete(){
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    getchar();
    deleteUser(id);
}

void inputForUpdate(){
    int id;
    printf("Enter user ID to update: ");
    scanf("%d", &id);
    getchar();
    updateUser(id);
}

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
        getchar();

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                inputForUpdate();
                break;
            case 4:
                inputForDelete();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
