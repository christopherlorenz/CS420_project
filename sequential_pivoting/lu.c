#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"

double A[3][3] = {{1,1,1},{2,1,3},{1,2,3}};
double U = A;
int size = sizeof(A)
double L[sizeof(A[0])/8][sizeof(A[0])/8];
double temp[1][sizeof(A[0])/8];

int main(int argc, char ** argv)
{
  printf("%f", A[0][1]);
}
