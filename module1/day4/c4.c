#include <stdio.h>
#include <stdlib.h>

// Structure definition for a student
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int n;

    // Read the number of students from the user
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of students
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    // Read data for each student from the user
    for (int i = 0; i < n; i++) {
        printf("Enter the details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }

    // Print the data for each student
    printf("Student Data:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}

