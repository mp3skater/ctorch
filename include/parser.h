#ifndef PARSER_H
#define PARSER_H

// Define the DataPoint struct
typedef struct {
    double *features; // Array of feature values
    double target;    // Target value
} DataPoint;

// Function declarations
int count_features(const char *line);
DataPoint *read_csv(const char *filename, int *num_points, int num_features);
void free_data_points(DataPoint *data_points, int num_data_points);

#endif // PARSER_H