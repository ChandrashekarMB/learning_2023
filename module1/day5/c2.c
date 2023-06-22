#include <stdio.h>
#include <string.h>

// Structure definition for a student
struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to initialize all members of the array of structures
void initialize_students(struct Student *students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main() {
    // Define the size of the array
    int size = 3;

    // Declare and initialize an array of structures
    struct Student students[size];

    // Initialize all members of the array of structures
    initialize_students(students, size);

    // Print the data for each student
    printf("Student Data:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}

