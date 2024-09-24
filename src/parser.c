#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

// Function to count lines in the CSV file
int count_lines(FILE *file) {
    int lines = 0;
    char ch;
    while (!feof(file)) {
        ch = fgetc(file);
        if (ch == '\n') {
            lines++;
        }
    }
    rewind(file);  // Reset file pointer to beginning
    return lines;
}

// Function to parse a line of CSV and store it in a DataPoint structure
DataPoint parse_line(char *line, int num_features) {
    DataPoint dp;
    dp.features = (double *)malloc(num_features * sizeof(double));

    // Age
    char *token = strtok(line, ",");
    dp.features[0] = atof(token);  

    // Gender
    token = strtok(NULL, ",");  // Corrected to NULL for subsequent tokens
    if(strcmp(token, "Male") == 0) {
        dp.features[1] = 1;
        dp.features[2] = 0;
    } else {
        dp.features[1] = 0;
        dp.features[2] = 1;
    }

    token = strtok(NULL, ","); // Skip Education Level
    token = strtok(NULL, ","); // Skip Job Title

    // Years of Experience
    token = strtok(NULL, ",");  
    dp.features[3] = atof(token);  // Corrected index for years of experience

    // Salary
    token = strtok(NULL, ",");  
    dp.target = atof(token);

    return dp;
}

// Function to read a CSV file and load data into an array of DataPoint structs
DataPoint *read_csv(const char *filename, int *num_points, int num_features) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Count the number of lines (data points)
    *num_points = count_lines(file) - 1;  // Exclude the header line

    // Allocate memory for DataPoint array
    DataPoint *data = malloc((*num_points) * sizeof(DataPoint));

    if (!data) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    char line[1024];
    fgets(line, sizeof(line), file);  // Skip the header line

    int index = 0;
    while (fgets(line, sizeof(line), file)) {
        // Parse each line and store it in the DataPoint array
        data[index] = parse_line(line, num_features);
        index++;
    }

    fclose(file);
    return data;
}

// Function to free allocated memory for the features array in each DataPoint
void free_data(DataPoint *data, int num_points) {
    for (int i = 0; i < num_points; i++) {
        free(data[i].features);
    }
    free(data);
}