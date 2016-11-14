#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"


int main(int argc, char ** argv)
{
  
  // Initialization
  int size = 3;
  double A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  //double A[size][size];
  double U[sizeof(A[0])/8][sizeof(A[0])/8];
  double L[sizeof(A[0])/8][sizeof(A[0])/8];
  for (int i=0; i<size; i++)
  {
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
  

  // Printing
  int rows = sizeof(A[0])/8;
  int cols = sizeof(A[0])/8;
  printf("L:\n");
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      printf("%f\t", L[i][j]);
    }
    printf("\n");
  }
  printf("U:\n");
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      printf("%f\t", U[i][j]);
    }
    printf("\n");
  }
  printf("A:\n");
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      printf("%f\t", A[i][j]);
    }
    printf("\n");
  }
  printf("M:\n");
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<cols; j++)
    {
      printf("%f\t", M[i][j]);
    }
    printf("\n");
  }
}
