#include <stdio.h>
#include <string.h>

// Structure definition for a student
struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to perform a search operation based on the name of the student
void search_student(const struct Student *students, int size, const char *name) {
    int found = 0;

    // Iterate over each student in the array
    for (int i = 0; i < size; i++) {
        // Compare the name of the student with the given name
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found!\n");
            printf("Roll Number: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    // Define the size of the array
    int size = 5;

    // Declare and initialize an array of structures
    struct Student students[size] = {
        {1001, "Aron", 85.0},
        {1002, "Bob", 92.5},
        {1003, "Charlie", 76.5},
        {1004, "David", 88.0},
        {1005, "Emma", 94.5}
    };

    // Perform a search operation based on the name of the student
    char search_name[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", search_name);
    search_student(students, size, search_name);

    return 0;
}

