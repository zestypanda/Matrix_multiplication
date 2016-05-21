#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <random>
#include "matrix_mul.hpp"

void initialize(int **A, int **B, int **C, int n) {
  printf("step 1\n");
  *A = new int[n*n];
  *B = new int[n*n];
  *C = new int[n*n];
  printf("step 2\n");
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      (*A)[index(i,j,n)] = 1;
      (*B)[index(i,j,n)] = 1;
    }
  }
}

void verify(int *C, int n) {
  assert(C[index(n/2,n/2,n)] == n);  
  srand (100);
  for (int k = 0; k < 100; ++k) {
    int i = rand()%n, j = rand()%n;
    assert(C[index(i,j,n)] == n);
  }
}


int main() {
  int *A, *B, *C;
  int  n = 2048;
  initialize(&A, &B, &C, n);
  printf("step 3\n");
  clock_t begin = clock();
  multiply(A, B, C, n); 
  clock_t end = clock();
  verify(C, n);
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  printf("Elpased time %f seconds.\n", elapsed_secs);

  return 0;
}

