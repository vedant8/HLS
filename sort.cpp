
#include "sort.h"
#include <ap_int.h>

//#include<stdio.h>
//#include<math.h>
//#include<hls_math.h>
//using namespace std;
 

// Count sort of arr[].
void countSort(ap_int<5>  arr[9][6], int exp)
{
#pragma HLS PIPELINE II=6
	// Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place.
	ap_int<5>  output[9][6];
	int i, count[2] = {0};
#pragma HLS ARRAY_PARTITION variable=output complete dim=0
#pragma HLS ARRAY_PARTITION variable=count complete dim=0

	// Count the number of times each digit occurred at (exp)th place in every input.
	for (i = 0; i < 9; i++)
     {
		#pragma HLS unroll
		count[arr[i][exp]]++;
     }
	// Calculating their cumulative count.

		count[1] += count[0];

	// Inserting values according to the digit '(arr[i] / exp) % 10' fetched into count[(arr[i] / exp) % 10].
	for (i = 9 - 1; i >= 0; i--)
	{
      #pragma HLS unroll
		for(int j=0;j<6;j++)
	   {
        #pragma HLS unroll
		output[count[arr[i][exp]] - 1][j] = arr[i][j];
	  }
		count[arr[i][exp]]--;

	}

	// Assigning the result to the arr pointer of main().
	for (i = 0; i < 9; i++)
		{
		   #pragma HLS unroll
			for(int j=0;j<6;j++)
			{
           #pragma HLS unroll
			arr[i][j]=output[i][j];
			}
		}

}

// Sort arr[] of size n using Radix Sort.
void sort(ap_int<5>  arr[9][6])
{
#pragma HLS ARRAY_PARTITION variable=arr complete dim=0
	int exp;
//	// Calling countSort() for digit at (exp)th place in every input.
	for (exp = 5; exp>=0; exp --)
	{
#pragma HLS unroll
		countSort(arr,exp);
	}


}
