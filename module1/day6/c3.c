#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Structure to represent each entry in the log
struct LogEntry {
    int entryNo;
    char sensorNo[3];
    float temperature;
    int humidity;
    int light;
    char time[9];
};

// Function to extract each line from the CSV file and store it in an array of structures
int readLogFile(struct LogEntry logEntries[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    char line[100];
    int entryCount = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        // Tokenize the line based on comma separator
        char *token = strtok(line, ",");
        
        // Extract and store the values in the log entry structure
        logEntries[entryCount].entryNo = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].sensorNo, token);
        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);
        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);
        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].time, token);

        entryCount++;
    }

    fclose(file);

    return entryCount;
}

// Function to display the contents of the array of structures
void displayLogEntries(const struct LogEntry logEntries[], int entryCount) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");

    for (int i = 0; i < entryCount; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n",
            logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature,
            logEntries[i].humidity, logEntries[i].light, logEntries[i].time);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int entryCount;

    // Read the log file and store the entries in the array of structures
    entryCount = readLogFile(logEntries, "data.csv");

    // Display the contents of the array of structures
    displayLogEntries(logEntries, entryCount);

    return 0;
}

