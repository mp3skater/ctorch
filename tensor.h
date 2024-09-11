#ifndef TENSOR_H
#define TENSOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    float* data;
} Tensor;

// Create a new tensor
Tensor* create_tensor(int rows, int cols);

// Fill tensor with a constant value
void fill_tensor(Tensor* t, float value);

// Free memory associated with the tensor
void free_tensor(Tensor* t);

// Print the content of a tensor
void print_tensor(Tensor* t);

#endif