
#include "sort.h"
#include <ap_int.h>

//#include<stdio.h>
//#include<math.h>
//#include<hls_math.h>
//using namespace std;
 

// Count sort of arr[].
void countSort(ap_int<2>  arr[18][6], int exp)
{
#pragma HLS PIPELINE II=6
	// Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place.
	ap_int<2>  output[18][6];
	int i, count[2] = {0};
#pragma HLS ARRAY_PARTITION variable=output complete dim=0
#pragma HLS ARRAY_PARTITION variable=count complete dim=0

	// Count the number of times each digit occurred at (exp)th place in every input.
	for (i = 0; i < 18; i++)
     {
		#pragma HLS unroll
		count[arr[i][exp]]++;
     }
	// Calculating their cumulative count.

		count[1] += count[0];

	// Inserting values according to the digit '(arr[i] / exp) % 18' fetched into count[(arr[i] / exp) % 18].
	for (i = 18 - 1; i >= 0; i--)
	{
      #pragma HLS unroll

		output[count[arr[i][exp]] - 1][0] = arr[i][0];
		output[count[arr[i][exp]] - 1][1] = arr[i][1];
		output[count[arr[i][exp]] - 1][2] = arr[i][2];
		output[count[arr[i][exp]] - 1][3] = arr[i][3];
		output[count[arr[i][exp]] - 1][4] = arr[i][4];
		output[count[arr[i][exp]] - 1][5] = arr[i][5];

		count[arr[i][exp]]--;

	}

	// Assigning the result to the arr pointer of main().
	for (i = 0; i < 18; i++)
		{
		   #pragma HLS unroll

			arr[i][0]=output[i][0];
			arr[i][1]=output[i][1];
			arr[i][2]=output[i][2];
			arr[i][3]=output[i][3];
			arr[i][4]=output[i][4];
			arr[i][5]=output[i][5];


		}

}

// Sort arr[] of size n using Radix Sort.
void sort(ap_int<2>  arr[18][6])
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
