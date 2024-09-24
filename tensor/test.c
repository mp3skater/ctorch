#include "tensor.h"
#include <stdio.h>

int main() {
    // Test 1: Initialize a tensor
    Tensor tensor;
    int shape[] = {2, 5, 4}; // A 2x3 tensor
    int ndim = 3;

    printf("Initializing tensor...");
    tensor_init(&tensor, shape, ndim);
    print_tensor(&tensor);

    // Test 2: Fill the tensor with a value
    printf("\nFilling tensor with value 5.0...");
    fill_tensor(&tensor, 5.0);
    print_tensor(&tensor);

    // Test 3: Free tensor memory
    printf("\nFreeing tensor memory...\n");
    free_tensor(&tensor);
    printf("done...\n");

    return 0;
}