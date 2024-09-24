#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *data;   // Pointer to raw data (1D array)
    int *shape;    // Shape of the tensor (e.g. [2, 3] for a 2x3 matrix)
    int ndim;      // Number of dimensions
    int size;      // Total number of elements in the tensor
} Tensor;

void print_tensor_recursive(Tensor* t, int *indices, int dim);

// Size calculation function
int calculate_size(int *shape, int ndim) {
    int size = 1;
    // Multiply all dimension sizes to get the total number of elements
    for (int i = 0; i < ndim; i++) {
        size *= shape[i];
    }
    return size;
}

// Tensor initialization function
void tensor_init(Tensor *tensor, int *shape, int ndim) {
    tensor->ndim = ndim;
    tensor->shape = (int *)malloc(ndim * sizeof(int));

    // Copy the shape
    for (int i = 0; i < ndim; i++) {
        tensor->shape[i] = shape[i];
    }

    // Calculate the total size of the data
    tensor->size = calculate_size(shape, ndim);

    // Allocate memory for the data
    tensor->data = (float *)malloc(tensor->size * sizeof(float));

    // Initialize the data with zeros
    for (int i = 0; i < tensor->size; i++) {
        tensor->data[i] = 0.0f;
    }
}

// Fill the tensor data with a specific value
void fill_tensor(Tensor* t, float value) {
    for (int i = 0; i < t->size; i++) {
        t->data[i] = value;
    }
}

// Free tensor memory
void free_tensor(Tensor* t) {
    free(t->data);
    free(t->shape);
}

// Print the contents of a tensor
void print_tensor(Tensor* t) {
    int *indices = (int *)malloc(t->ndim * sizeof(int));
    printf("\nTensor: ");
    print_tensor_recursive(t, indices, 0);
    printf("\n");
    free(indices);
}
// The recursive method
void print_tensor_recursive(Tensor* t, int *indices, int dim) {
    if (dim == t->ndim - 1) {
        // Base case: Print the 1D array at the current level
        printf("[");
        for (int i = 0; i < t->shape[dim]; i++) {
            indices[dim] = i;
            // Calculate the index in the flattened array
            int flat_index = 0;
            int stride = 1;
            for (int j = t->ndim - 1; j >= 0; j--) {
                flat_index += indices[j] * stride;
                stride *= t->shape[j];
            }
            printf("%f", t->data[flat_index]);
            if (i < t->shape[dim] - 1) printf(", ");
        }
        printf("]");
    } else {
        // Recursive case: Print the multi-dimensional arrays
        printf("[");
        for (int i = 0; i < t->shape[dim]; i++) {
            indices[dim] = i;
            print_tensor_recursive(t, indices, dim + 1);
            if (i < t->shape[dim] - 1) printf(", ");
        }
        printf("]");
    }
}