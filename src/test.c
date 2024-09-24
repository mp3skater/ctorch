#include <stdio.h>
#include <stdlib.h>
#include "linear_regression.h"
#include "parser.h"

// Create a function to allocate memory for the features
double *create_features(double age, double male, double female, double yoe) {
    double *features = (double *)malloc(3 * sizeof(double));
    features[0] = age;
    features[1] = male;
    features[2] = female;
    features[2] = yoe;
    return features;
}

int main() {
    // Training data: age, male(bool), female(bool), age, years_experience, salary (target)
    int num_features = 4;
    int num_points;
    DataPoint *data = read_csv("data/salaries.csv", &num_points, num_features);
    LinearModel *model = create_model(num_features);

    // Train the model using gradient descent
    gradient_descent(data, 10, model, 0.001, 10000);

    // Output final coefficients
    printf("\nFinal coefficients:\n");
    printf("Intercept (b0): %f\n", model->coefficients[0]);
    printf("Coefficient for age (b1): %f\n", model->coefficients[1]);
    printf("Coefficient for age (b2): %f\n", model->coefficients[2]);
    printf("Coefficient for age (b2): %f\n", model->coefficients[3]);
    printf("Coefficient for age (b2): %f\n", model->coefficients[4]);
    printf("Coefficient for years of experience (b3): %f\n", model->coefficients[3]);

    // Predict salary for a new person (e.g., sex=1, age=28, years_experience=3)
    double *new_person_features = create_features(17, 1, 0, 2);
    DataPoint new_person = (DataPoint){new_person_features, 0};  // Target is not needed
    double predicted_salary = predict(model, new_person);
    printf("\nPredicted salary for me (age=17,male=1,female=0,yoe=2): %f$\n\n", predicted_salary);

    // Free the allocated memory
    for (int i = 0; i < 10; i++) {
        free(data[i].features);
    }

    printf("Freeing memory...\n\n");
    free(new_person_features);
    free_model(model);

    printf("done\n\n");

    return 0;
}