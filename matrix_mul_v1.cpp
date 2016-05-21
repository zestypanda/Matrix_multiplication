#include "matrix_mul.hpp"

void multiply(int *A, int *B, int *C, int n) {
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
       C[index(i,j,n)] = 0;
       for (int k = 0; k < n; ++k)
         C[index(i,j,n)] += A[index(i,k,n)]*B[index(k,j,n)];
    }
  } 
}
