#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/linear_regression.h"


// Inits the coefficients to 0
void initCoefficients(double value, LinearModel* model, int num_features) {
    for (int i = 0; i <= num_features; i++) {
        model->coefficients[i] = value;
    }
}

// Create a new model with a given number of features
LinearModel *create_model(int num_features) {
    LinearModel *model = (LinearModel *)malloc(sizeof(LinearModel));
    model->coefficients = (double *)malloc((num_features + 1) * sizeof(double)); // +1 for b0 (intercept)
    model->num_features = num_features;

    initCoefficients(0.0f, model, num_features);
    
    return model;
}

// Predict the target value (the salary) using the model
double predict(LinearModel *model, DataPoint data) {
    double prediction = model->coefficients[0]; // Start with b0 (intercept)
    for (int i = 0; i < model->num_features; i++) {
        prediction += model->coefficients[i + 1] * data.features[i];
    }
    return prediction;
}

// Perform gradient descent to adjust the coefficients
void gradient_descent(DataPoint data[], int size, LinearModel *model, double learning_rate, int iterations) {
    for (int iter = 0; iter < iterations; iter++) {
        double *gradients = (double *)calloc(model->num_features + 1, sizeof(double)); // To store gradients for b0, b1, ..., bn

        // Calculate gradients
        for (int i = 0; i < size; i++) {
            double prediction = predict(model, data[i]);
            double error = prediction - data[i].target;

            gradients[0] += error; // Gradient for b0 (intercept)
            for (int j = 0; j < model->num_features; j++) {
                gradients[j + 1] += error * data[i].features[j];
            }
        }

        // Update coefficients
        for (int j = 0; j <= model->num_features; j++) {
            model->coefficients[j] -= (learning_rate * gradients[j]) / size;
        }

        free(gradients);
    }
}

// Free the memory allocated for the model
void free_model(LinearModel *model) {
    free(model->coefficients);
    free(model);
}
