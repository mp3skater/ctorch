#ifndef TENSOR_H
#define TENSOR_H

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    float *data;   // Pointer to raw data (1D array)
    int *shape;    // Shape of the tensor (e.g. [2, 3] for a 2x3 matrix)
    int ndim;      // Number of dimensions
    int size;      // Total number of elements in the tensor
} Tensor;

// Size calculation function
int calculate_size(int *shape, int ndim);

// Tensor initialization function
void tensor_init(Tensor *tensor, int *shape, int ndim);

// Fill the tensor data with a specific value
void fill_tensor(Tensor* t, float value);

// Free tensor memory
void free_tensor(Tensor* t);

// Print the contents of a tensor
void print_tensor(Tensor* t);

#endif