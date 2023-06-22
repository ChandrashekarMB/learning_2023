#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for a student
struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to parse the string and initialize an array of structures
void parse_string(const char *input, struct Student *students, int size) {
    char *token;
    int i = 0;

    // Copy the input string to a temporary buffer
    char buffer[100];
    strcpy(buffer, input);

    // Tokenize the string using space as the delimiter
    token = strtok(buffer, " ");

    // Process each token and initialize the corresponding structure field
    while (token != NULL) {
        if (i >= size)
            break;

        // Initialize the roll number
        students[i].rollno = atoi(token);

        // Move to the next token
        token = strtok(NULL, " ");

        // Initialize the name
        strcpy(students[i].name, token);

        // Move to the next token
        token = strtok(NULL, " ");

        // Initialize the marks
        students[i].marks = atof(token);

        // Move to the next token
        token = strtok(NULL, " ");

        i++;
    }
}

int main() {
    int size;

    // Read the size of the array from the user
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); // Read the newline character

    // Allocate memory for the array of structures
    struct Student *students = (struct Student *)malloc(size * sizeof(struct Student));

    // Read the input string from the user
    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the trailing newline character

    // Parse the string and initialize the array of structures
    parse_string(input, students, size);

    // Print the data for each student
    printf("Student Data:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Free the memory allocated for the array of structures
    free(students);

    return 0;
}

