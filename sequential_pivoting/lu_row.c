#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"
#include "math.h"

int main(int argc, char ** argv)
{
  
  // Initialization
  int size = 3;
  double A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  //double A[size][size];
  double U[sizeof(A[0])/8][sizeof(A[0])/8];
  double L[sizeof(A[0])/8][sizeof(A[0])/8];
  int P[sizeof(A[0])/8]; // Sparse matrix with only one 1 per row and col
                         // the position in the array is the row and value col
  for (int i=0; i<size; i++)
  {
    P[i] = i;
    for (int j=0; j<size; j++)
    {
      if (i==j) L[i][j] = 1.0;
      else L[i][j] = 0.0;
      U[i][j] = A[i][j];
    }
  }


  // Computation
  for (int i=0; i<size; i++)
  {

    // Pivoting
    int max_pivot = i;
    for (int j=i+1; j<size; j++)
    {
      if (fabs(U[j][i]) > fabs(U[max_pivot][i])) max_pivot = j;
    }
    for (int j=0; j<size; j++)
    {
      double temp_U = U[i][j];
      U[i][j] = U[max_pivot][j];
      U[max_pivot][j] = temp_U;
    }
    for (int j=0; j<i; j++)   // Very important the j<i!!!
    {
      double temp_L = L[i][j];
      L[i][j] = L[max_pivot][j];
      L[max_pivot][j] = temp_L;
    }

    int temp_P = P[i];
    P[i] = P[max_pivot];
    P[max_pivot] = temp_P;
    
    // And elimination
    for (int j=i+1; j<size; j++)
    {
      L[j][i] = U[j][i] / U[i][i];
      for (int k=i; k<size; k++)
      {
        if (k==i) U[j][k] = 0.0;
        else U[j][k] -= L[j][i] * U[i][k];
      }
    }
  }
  

  // Matrix multiplication
  // L * U
  double M[sizeof(A[0])/8][sizeof(A[0])/8];
  for (int i=0; i<size; i++)
  {
    for (int j=0; j<size; j++)
    {
      for (int k=0; k<size; k++)
      {
        M[i][j] += L[i][k] * U[k][j];
      }
    }
  } 
  // P^T * (L * U)
  int PT[sizeof(A[0])/8];
  for (int i=0; i<size; i++)
  {
    PT[P[i]] = i;
  }
  double PTM[sizeof(A[0])/8][sizeof(A[0])/8];
  for (int i=0; i<size; i++)
  {
    for (int j=0; j<size; j++)
    {
      PTM[i][j] = M[PT[i]][j];
    }
  }
  

  // Printing
  printf("L:\n");
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      printf("%f\t", L[i][j]);
    }
    printf("\n");
  }
  printf("U:\n");
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      printf("%f\t", U[i][j]);
    }
    printf("\n");
  }
  printf("A:\n");
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      printf("%f\t", A[i][j]);
    }
    printf("\n");
  }
  printf("PTM:\n");
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      printf("%f\t", PTM[i][j]);
    }
    printf("\n");
  }
}
