#include "matrix_mul.hpp"
#define CRITICAL_SIZE 64

void multiply_step(int *A, int *B, int *C, int i1, int j1, int i2, int j2, int m, int n) {
  if (m <= CRITICAL_SIZE) { 
    for (int i = 0; i < m; ++i){
      for (int j = 0; j < m; ++j){
         for (int k = 0; k < m; ++k){          
            C[index(i+i1,j+j2,n)] += A[index(i+i1,j1+k,n)]*B[index(i2+k,j+j2,n)];
         }
      }
    }
  }
  else {
    m = m/2;
    multiply_step(A, B, C, i1,   j1,   i2,   j2,   m, n);
    multiply_step(A, B, C, i1,   j1+m, i2+m, j2,   m, n);
    multiply_step(A, B, C, i1,   j1,   i2,   j2+m, m, n);  
    multiply_step(A, B, C, i1,   j1+m, i2+m, j2+m, m, n);    
    multiply_step(A, B, C, i1+m, j1,   i2,   j2,   m, n);
    multiply_step(A, B, C, i1+m, j1+m, i2+m, j2,   m, n);
    multiply_step(A, B, C, i1+m, j1,   i2,   j2+m, m, n);  
    multiply_step(A, B, C, i1+m, j1+m, i2+m, j2+m, m, n);
  }  
}


void multiply(int *A, int *B, int *C, int n) {  
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
       C[index(i,j,n)] = 0;
    }
  } 
  multiply_step(A,B,C,0,0,0,0,n,n);
}

