#include <stdio.h>
#include <stdlib.h>
#include "linear_regression.h"
#include "parser.h"

#define NUM_POINTS 373
#define NUM_FEATURES 4

// Create a function to allocate memory for the features
double *create_features(double age, double male, double female, double yoe) {
    double *features = (double *)malloc(3 * sizeof(double));
    features[0] = age;
    features[1] = male;
    features[2] = female;
    features[3] = yoe;
    return features;
}

int main() {
    // Training data: age, male(bool), female(bool), age, years_experience, salary (target)
    int num_points;
    DataPoint *data = read_csv("data/salaries.csv", &num_points, NUM_FEATURES);
    LinearModel *model = create_model(NUM_FEATURES);

    // Train the model using gradient descent
    gradient_descent(data, NUM_POINTS, model, 0.001, 10000);

    // Output final coefficients
    printf("\nFinal coefficients:\n");
    printf("Intercept (b0): %f\n", model->coefficients[0]);
    printf("Coefficient for age: %f\n", model->coefficients[1]);
    printf("Coefficient for man: %f\n", model->coefficients[2]);
    printf("Coefficient for women: %f\n", model->coefficients[3]);
    printf("Coefficient for years of experience: %f\n", model->coefficients[4]);

    // Predict salary for a new person (e.g., sex=1, age=28, years_experience=3)
    double *my_features = create_features(17, 1, 0, 2);
    DataPoint me = (DataPoint){my_features, 0};  // Target is not needed
    double predicted_salary = predict(model, me);
    printf("\nPredicted salary for me (age=17,male=1,female=0,yoe=2): %.2f$\n\n", predicted_salary);

    // Free the allocated memory
    for (int i = 0; i < NUM_POINTS; i++) {
        free(data[i].features);
    }

    printf("Freeing memory...\n\n");
    free(my_features);
    free_model(model);

    printf("done\n\n");

    return 0;
}