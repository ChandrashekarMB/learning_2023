#include <stdio.h>

int main() {
    FILE *source_file, *destination_file;
    char source_filename[100], destination_filename[100];
    char ch;

    // Get the source file name from the user
    printf("Enter the source file name: ");
    scanf("%s", source_filename);

    // Open the source file in read mode
    source_file = fopen(source_filename, "r");
    if (source_file == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    // Get the destination file name from the user
    printf("Enter the destination file name: ");
    scanf("%s", destination_filename);

    // Open the destination file in write mode
    destination_file = fopen(destination_filename, "w");
    if (destination_file == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(source_file);
        return 1;
    }

    // Copy the contents of the source file to the destination file
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }

    // Close the files
    fclose(source_file);
    fclose(destination_file);

    printf("File copied successfully.\n");

    return 0;
}

