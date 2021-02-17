//#include <cuda_runtime_api.h>
#include <cuda.h>
#include <stdio.h>
#include <cstdlib>
#define SIZE 1024

/*
void VectorAdd(int *a, int *b, int *c,int n) {
    int i = 0;
    for(; i < n; ++i) {
        c[i] = a[i] + b[i];
    }
}
*/
__global__ void VectorAdd(int *a, int *b, int *c,int n) {
    int i = threadIdx.x;
    
    if( i < n)
        c[i] = a[i] + b[i];
}

int main()
{
    int *a, *b, *c;

    //a = (int *) std::malloc(SIZE * sizeof(int));
    cudaMallocManaged(&a, SIZE * sizeof(int));
    //b = (int *) std::malloc(SIZE * sizeof(int));
    cudaMallocManaged(&b, SIZE * sizeof(int));
    //c = (int *) std::malloc(SIZE * sizeof(int));
    cudaMallocManaged(&c, SIZE * sizeof(int));

    for(int i = 0; i < SIZE; ++i) {
      a[i] = i;
      b[i] = i;
      c[i] = 0;  
    }  

    //VectorAdd(a, b, c, SIZE);
    VectorAdd  <<<1, SIZE>>> (a, b, c, SIZE); // block and thread size
    cudaDeviceSynchronize();

    for(int i = 0; i < 10; ++i) 
        printf("C[%d] = %d \n", i, c[i]);

    //free(a);
    cudaFree(a);
    //free(b);
    cudaFree(b);
    //free(c);
    cudaFree(c);

    return 0;
}