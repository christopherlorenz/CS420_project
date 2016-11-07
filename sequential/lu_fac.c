#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"

//double A[3][3] = {{1,1,1},{2,3,5},{4,6,8}};
double A[3][3] = {{1,1,1,},{0,0,3},{1,2,3}};
double L[sizeof(A[0])/8][sizeof(A[0])/8]; 
double temp[1][sizeof(A[0])/8];

double tolerance = 0.0000001;
double max = 0;
int maxRow = 0;

int main(int argc, char**argv)
{
    //Test ability to compile C code without being handed code
    for(int j = 0; j < sizeof(A[0])/8; j++)
    {
	//Create unit diagonal in L
	L[j][j] = 1;
	//Check if pivot is zero
	if(abs(A[j][j]) < tolerance)
	{
	    //Iterate through column below pivot to find max
	    for(int k = j; k < sizeof(A[0])/8; k++)
	    {
		if(abs(A[k][j]) > abs(max))
		{
		    max = A[k][j];
		    maxRow = k;
		}
	    }
	    //Perform row pivot
	    for(int k = j; k < sizeof(A[0])/8; k++)
	    {
		temp[0][k] = A[j][k];
		A[j][k] = A[maxRow][k];
		A[maxRow][k] = temp[0][k];
	    }
	}
	//Iterate through all rows
	for(int i = j+1; i < sizeof(A[0])/8; i++)
	{
	    if(abs(A[i][j]) > tolerance)
	    {
      	        L[i][j] = A[i][j]/A[j][j];
		for(int k = j; k < sizeof(A[0])/8;k++)
		{
		    A[i][k] = A[i][k] - L[i][j]*A[j][k];
		} 
	    }
	    else
	    {
		L[i][j] = 0;
	    }
	}
    }
   
    printf("The Matrix U: \n");

    for(int i = 0; i < sizeof(A[0])/8; i++)
    {
	for(int j = 0; j < sizeof(A[0])/8; j++)
	{
	    printf("%f\t",A[i][j]);
	}
    printf("\n");
    }
    printf("\nThe Matrix L: \n");
    for(int i = 0; i < sizeof(A[0])/8; i++)
    {
	for(int j = 0; j < sizeof(A[0])/8; j++)
	{
	    printf("%f\t",L[i][j]);
	}
    printf("\n");
    }


}

