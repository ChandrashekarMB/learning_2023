#include <stdio.h>

// Structure definition for a student
struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to display all members of the array of structures
void display_students(const struct Student *students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    // Define the size of the array
    int size = 3;

    // Declare and initialize an array of structures
    struct Student students[size] = {
        {1001, "Aron", 100.0},
        {1002, "Bob", 90.5},
        {1003, "Charlie", 85.5}
    };

    // Display all members of the array of structures
    display_students(students, size);

    return 0;
}

