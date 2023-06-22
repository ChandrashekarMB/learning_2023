#include <stdio.h>

// Structure definition for a student
struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to swap two students
void swap_students(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array of structures in descending order based on marks
void sort_students(struct Student *students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                swap_students(&students[j], &students[j + 1]);
            }
        }
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

    // Sort the array of structures in descending order based on marks
    sort_students(students, size);

    // Display the sorted array of structures
    printf("Sorted Student Data:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}

