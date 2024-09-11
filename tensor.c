#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    float* data;
} Tensor;

// Create a new tensor
Tensor* create_tensor(int rows, int cols) {
    Tensor* t = (Tensor*) malloc(sizeof(Tensor));
    t->rows = rows;
    t->cols = cols;
    t->data = (float*) malloc(rows * cols * sizeof(float));
    return t;
}

// Fill tensor with a constant value
void fill_tensor(Tensor* t, float value) {
    for (int i = 0; i < t->rows * t->cols; i++) {
        t->data[i] = value;
    }
}

// Free memory
void free_tensor(Tensor* t) {
    free(t->data);
    free(t);
}

// Print the content of a tensor
void print_tensor(Tensor* t) {
    for(int i = 0; i < t->rows * t->cols; i++) {
        printf("Output[%d]: %f\n", i, t->data[i]);
    }
}