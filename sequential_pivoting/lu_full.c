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
  int Q[sizeof(A[0])/8]; // Sparse matrix with only one 1 per row and col
                         // the position in the array is the row and value col
  for (int i=0; i<size; i++)
  {
    P[i] = i;
    Q[i] = i;
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
    int max_row = i;
    int max_col = i;
    for (int j=i; j<size; j++)
    {
      for (int k=i; k<size; k++)
      {
        if (fabs(U[j][k]) > fabs(U[max_row][max_col])) max_row = j, max_col = k;
      }
    }
    // Permute rows
    for (int j=0; j<size; j++)
    {
      double temp_U = U[i][j];
      U[i][j] = U[max_row][j];
      U[max_row][j] = temp_U;
    }
    for (int j=0; j<i; j++)   // Very important the j<i!!!
    {
      double temp_L = L[i][j];
      L[i][j] = L[max_row][j];
      L[max_row][j] = temp_L;
    }
    int temp_P = P[i];
    P[i] = P[max_row];
    P[max_row] = temp_P;
    // Permute cols
    for (int j=0; j<size; j++)
    {
      double temp_U = U[j][i];
      U[j][i] = U[j][max_col];
      U[j][max_col] = temp_U;
    } // Only permutation of cols in U, not L
    int temp_Q = Q[i];
    Q[i] = Q[max_col];
    Q[max_col] = temp_Q;
    
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
  int QT[sizeof(A[0])/8];
  for (int i=0; i<size; i++)
  {
    PT[P[i]] = i;
    QT[Q[i]] = i;
  }
  double PTM[sizeof(A[0])/8][sizeof(A[0])/8];
  for (int i=0; i<size; i++)
  {
    for (int j=0; j<size; j++)
    {
      PTM[i][j] = M[PT[i]][j];
    }
  }
  double PTMQT[sizeof(A[0])/8][sizeof(A[0])/8];
  for (int i=0; i<size; i++)
  {
    for (int j=0; j<size; j++)
    {
      PTMQT[j][i] = PTM[j][QT[i]];
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
  printf("PTMQT:\n");
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      printf("%f\t", PTMQT[i][j]);
    }
    printf("\n");
  }
}
