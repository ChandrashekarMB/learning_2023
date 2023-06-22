#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert text to upper case
void convertToUpper(char *text) {
    while (*text) {
        *text = toupper((unsigned char)*text);
        text++;
    }
}

// Function to convert text to lower case
void convertToLower(char *text) {
    while (*text) {
        *text = tolower((unsigned char)*text);
        text++;
    }
}

// Function to convert text to sentence case
void convertToSentenceCase(char *text) {
    int len = strlen(text);
    int i = 0;

    if (len > 0) {
        text[0] = toupper((unsigned char)text[0]);

        for (i = 1; i < len; i++) {
            if (text[i - 1] == ' ' || text[i - 1] == '.' || text[i - 1] == '!') {
                text[i] = toupper((unsigned char)text[i]);
            } else {
                text[i] = tolower((unsigned char)text[i]);
            }
        }
    }
}

// Function to perform the file copy operation
void copyFile(const char *source_filename, const char *destination_filename, char option) {
    FILE *source_file, *destination_file;
    char ch;

    // Open the source file in read mode
    source_file = fopen(source_filename, "r");
    if (source_file == NULL) {
        printf("Failed to open the source file.\n");
        return;
    }

    // Open the destination file in write mode
    destination_file = fopen(destination_filename, "w");
    if (destination_file == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(source_file);
        return;
    }

    // Copy the contents of the source file to the destination file
    while ((ch = fgetc(source_file)) != EOF) {
        if (option == 'u') {
            fputc(toupper(ch), destination_file);
        } else if (option == 'l') {
            fputc(tolower(ch), destination_file);
        } else if (option == 's') {
            fputc(ch, destination_file);
        } else {
            fputc(ch, destination_file);
        }
    }

    // Close the files
    fclose(source_file);
    fclose(destination_file);

    printf("File copied successfully.\n");
}

int main(int argc, char *argv[]) {
    // Check if the correct number of command line arguments are provided
    if (argc < 3) {
        printf("Insufficient arguments!\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        return 1;
    }

    // Get the option and filenames from command line arguments
    char option = argv[1][1];
    char *source_filename = argv[2];
    char *destination_filename = argv[3];

    // Perform the file copy operation based on the option
    if (option == 'u' || option == 'l' || option == 's') {
        copyFile(source_filename, destination_filename, option);
    } else {
        printf("Invalid option!\n");
    }

    return 0;
}

