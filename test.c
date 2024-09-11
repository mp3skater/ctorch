#include "tensor.h"
#include <stdio.h>

int main() {
    // Create input tensor (e.g., a 3x1 vector)
    Tensor* input = create_tensor(3, 7);

    fill_tensor(input, 1.0f);

    // Create a linear layer (e.g., 2 output neurons, 3 input features)
    //LinearLayer* layer = create_linear_layer(3, 2);

    // Forward pass
    //Tensor* output = forward(layer, input);

    // Apply activation function (ReLU)
    //relu(output);

    // Print the result
    print_tensor(input);

    // Free memory
    free_tensor(input);
    //free_tensor(output);
    //free_linear_layer(layer);

    return 0;
}