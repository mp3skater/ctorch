#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include "parser.h"

typedef struct {
    double *coefficients;  // Coefficients (weights) for the model
    int num_features;      // Number of features in the model
} LinearModel;

// Function declarations
LinearModel *create_model(int num_features);
void free_model(LinearModel *model);
double predict(LinearModel *model, DataPoint data);
void gradient_descent(DataPoint data[], int size, LinearModel *model, double learning_rate, int iterations);

#endif // LINEAR_REGRESSION_H