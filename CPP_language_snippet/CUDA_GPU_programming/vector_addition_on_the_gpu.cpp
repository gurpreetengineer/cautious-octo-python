#include <iostream>
#include <chrono>

// CUDA kernel function that performs vector addition on the GPU
__global__
void vectorAdd(int *a, int *b, int *c, int size) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < size) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    // Define the size of the vector to add
    int size = 10000000;

    // Allocate memory for the vectors on the host (CPU)
    int *h_a = new int[size];
    int *h_b = new int[size];
    int *h_c = new int[size];

    // Initialize the vectors with random values on the host (CPU)
    for (int i = 0; i < size; ++i) {
        h_a[i] = rand() % 100;
        h_b[i] = rand() % 100;
    }

    // Allocate memory for the vectors on the device (GPU)
    int *d_a, *d_b, *d_c;
    cudaMalloc(&d_a, size * sizeof(int));
    cudaMalloc(&d_b, size * sizeof(int));
    cudaMalloc(&d_c, size * sizeof(int));

    // Copy the vectors from the host (CPU) to the device (GPU)
    cudaMemcpy(d_a, h_a, size * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size * sizeof(int), cudaMemcpyHostToDevice);

    // Define the number of threads per block and the number of blocks
    int threadsPerBlock = 256;
    int blocksPerGrid = (size + threadsPerBlock - 1) / threadsPerBlock;

    // Record the start time
    auto start = std::chrono::high_resolution_clock::now();

    // Call the CUDA kernel function to perform vector addition on the GPU
    vectorAdd<<<blocksPerGrid, threadsPerBlock>>>(d_a, d_b, d_c, size);

    // Record the end time
    auto end = std::chrono::high_resolution_clock::now();

    // Copy the result vector from the device (GPU) to the host (CPU)
    cudaMemcpy(h_c, d_c, size * sizeof(int), cudaMemcpyDeviceToHost);

    // Print the first 10 values of the result vector
    for (int i = 0; i < 10; ++i) {
        std::cout << h_c[i] << " ";
    }
    std::cout << std::endl;

    // Calculate and print the time taken to perform the vector addition on the GPU
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken to perform vector addition on the GPU: " << duration.count() << " microseconds" << std::endl;

    // Free the memory allocated on the host (CPU) and the device (GPU)
    delete[] h_a;
    delete[] h_b;
    delete[] h_c;
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}

/**
 * @brief explanation
 * This program performs vector addition on the GPU using CUDA/GPU programming. 
 * The program first allocates memory for three integer vectors on the host (CPU): h_a, h_b, and h_c. 
 * It then initializes h_a and h_b with random values.
 * 
 * The program then allocates memory for the three vectors on the device (GPU) using cudaMalloc(), and copies h_a
 * 
 */
