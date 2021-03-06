#include "bitonic.h"


#include <iostream>
using namespace std;
struct Cluster{
 ap_fixed<16,9>   Deposits;
  uint16_t  PeakEta;
  uint16_t  PeakPhi;
  uint16_t  TowerEta;
  uint16_t  TowerPhi;
};

void  bitonic_16( Cluster arr[16])
{// sorting blocks of size 16
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<8;i++)
  {
  #pragma HLS unroll
  if( arr[i].Deposits< arr[i+8].Deposits)
    {
      temp= arr[i+8].Deposits;
       arr[i+8].Deposits= arr[i].Deposits;
       arr[i].Deposits=temp;
      temp= arr[i].PeakEta;
         arr[i].PeakEta= arr[i+8].PeakEta;
         arr[i+8].PeakEta=temp;
        temp= arr[i].PeakPhi;
         arr[i].PeakPhi= arr[i+8].PeakPhi;
         arr[i+8].PeakPhi=temp;
         temp= arr[i].TowerEta;
         arr[i].TowerEta= arr[i+8].TowerEta;
         arr[i+8].TowerEta=temp;
        temp= arr[i].TowerPhi;
         arr[i].TowerPhi= arr[i+8].TowerPhi;
         arr[i+8].TowerPhi=temp;
    }

    }

  
   for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if( arr[i].Deposits< arr[i+4].Deposits)
    {
      temp= arr[i+4].Deposits;
       arr[i+4].Deposits= arr[i].Deposits;
       arr[i].Deposits=temp;
      temp= arr[i].PeakEta;
         arr[i].PeakEta= arr[i+4].PeakEta;
         arr[i+4].PeakEta=temp;
        temp= arr[i].PeakPhi;
         arr[i].PeakPhi= arr[i+4].PeakPhi;
         arr[i+4].PeakPhi=temp;
          temp= arr[i].TowerEta;
         arr[i].TowerEta= arr[i+4].TowerEta;
         arr[i+4].TowerEta=temp;
        temp= arr[i].TowerPhi;
         arr[i].TowerPhi= arr[i+4].TowerPhi;
         arr[i+4].TowerPhi=temp;
    }
    }
   for(int i=8;i<12;i++)
  {
  #pragma HLS unroll
  if( arr[i].Deposits< arr[i+4].Deposits)
    {
      temp= arr[i+4].Deposits;
       arr[i+4].Deposits= arr[i].Deposits;
       arr[i].Deposits=temp;
      temp= arr[i].PeakEta;
         arr[i].PeakEta= arr[i+4].PeakEta;
         arr[i+4].PeakEta=temp;
        temp= arr[i].PeakPhi;
         arr[i].PeakPhi= arr[i+4].PeakPhi;
         arr[i+4].PeakPhi=temp;
         temp= arr[i].TowerEta;
         arr[i].TowerEta= arr[i+4].TowerEta;
         arr[i+4].TowerEta=temp;
        temp= arr[i].TowerPhi;
         arr[i].TowerPhi= arr[i+4].TowerPhi;
         arr[i+4].TowerPhi=temp;
    }
    }
  

  for(int i=0;i<13;i=i+4)
  {
  #pragma HLS unroll
  if( arr[i].Deposits< arr[i+2].Deposits)
    {
      temp= arr[i+2].Deposits;
       arr[i+2].Deposits= arr[i].Deposits;
       arr[i].Deposits=temp;
      temp= arr[i].PeakEta;
           arr[i].PeakEta= arr[i+2].PeakEta;
           arr[i+2].PeakEta=temp;
          temp= arr[i].PeakPhi;
           arr[i].PeakPhi= arr[i+2].PeakPhi;
           arr[i+2].PeakPhi=temp;
            temp= arr[i].TowerEta;
           arr[i].TowerEta= arr[i+2].TowerEta;
           arr[i+2].TowerEta=temp;
          temp= arr[i].TowerPhi;
           arr[i].TowerPhi= arr[i+2].TowerPhi;
           arr[i+2].TowerPhi=temp;
    }

    if( arr[i+1].Deposits< arr[i+3].Deposits)
    {
      temp= arr[i+3].Deposits;
       arr[i+3].Deposits= arr[i+1].Deposits;
       arr[i+1].Deposits=temp;
       temp= arr[i+1].PeakEta;
               arr[i+1].PeakEta= arr[i+3].PeakEta;
               arr[i+3].PeakEta=temp;
              temp= arr[i+1].PeakPhi;
               arr[i+1].PeakPhi= arr[i+3].PeakPhi;
               arr[i+3].PeakPhi=temp;
               temp= arr[i+1].TowerEta;
               arr[i+1].TowerEta= arr[i+3].TowerEta;
               arr[i+3].TowerEta=temp;
              temp= arr[i+1].TowerPhi;
               arr[i+1].TowerPhi= arr[i+3].TowerPhi;
               arr[i+3].TowerPhi=temp;
    }
    }
  
 
   

  for(int i=0;i<15;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if( arr[i].Deposits< arr[i+1].Deposits)
    {
      temp= arr[i+1].Deposits;
       arr[i+1].Deposits= arr[i].Deposits;
       arr[i].Deposits=temp;
       temp= arr[i].PeakEta;
               arr[i].PeakEta= arr[i+1].PeakEta;
               arr[i+1].PeakEta=temp;
              temp= arr[i].PeakPhi;
               arr[i].PeakPhi= arr[i+1].PeakPhi;
               arr[i+1].PeakPhi=temp;
               temp= arr[i].TowerEta;
               arr[i].TowerEta= arr[i+1].TowerEta;
               arr[i+1].TowerEta=temp;
              temp= arr[i].TowerPhi;
               arr[i].TowerPhi= arr[i+1].TowerPhi;
               arr[i+1].TowerPhi=temp;
    }

    }
 


  }

void  bitonic_8( Cluster arr[16])
{// sorting blocks of size 8
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<4;i++)
  {
    #pragma HLS unroll
    if( arr[i].Deposits< arr[i+4].Deposits)
      {
        temp= arr[i+4].Deposits;
         arr[i+4].Deposits= arr[i].Deposits;
         arr[i].Deposits=temp;
        temp= arr[i].PeakEta;
         arr[i].PeakEta= arr[i+4].PeakEta;
         arr[i+4].PeakEta=temp;
        temp= arr[i].PeakPhi;
         arr[i].PeakPhi= arr[i+4].PeakPhi;
         arr[i+4].PeakPhi=temp;
         temp= arr[i].TowerEta;
         arr[i].TowerEta= arr[i+4].TowerEta;
         arr[i+4].TowerEta=temp;
        temp= arr[i].TowerPhi;
         arr[i].TowerPhi= arr[i+4].TowerPhi;
         arr[i+4].TowerPhi=temp;
      }
  }
  for(int i=8;i<12;i++)
  {
    #pragma HLS unroll
    if( arr[i].Deposits> arr[i+4].Deposits)
      {
        temp= arr[i+4].Deposits;
         arr[i+4].Deposits= arr[i].Deposits;
         arr[i].Deposits=temp;
        temp= arr[i].PeakEta;
         arr[i].PeakEta= arr[i+4].PeakEta;
         arr[i+4].PeakEta=temp;
        temp= arr[i].PeakPhi;
         arr[i].PeakPhi= arr[i+4].PeakPhi;
         arr[i+4].PeakPhi=temp;
         temp= arr[i].TowerEta;
         arr[i].TowerEta= arr[i+4].TowerEta;
         arr[i+4].TowerEta=temp;
        temp= arr[i].TowerPhi;
         arr[i].TowerPhi= arr[i+4].TowerPhi;
         arr[i+4].TowerPhi=temp;
      }
  }
 

  for(int i=0;i<5;i=i+4)
  {
    #pragma HLS unroll
    if( arr[i].Deposits< arr[i+2].Deposits)
      {
        temp= arr[i+2].Deposits;
         arr[i+2].Deposits= arr[i].Deposits;
         arr[i].Deposits=temp;
        temp= arr[i+2].PeakEta;
         arr[i+2].PeakEta= arr[i].PeakEta;
         arr[i].PeakEta=temp;
        temp= arr[i+2].PeakPhi;
         arr[i+2].PeakPhi= arr[i].PeakPhi;
         arr[i].PeakPhi=temp;
          temp= arr[i+2].TowerEta;
         arr[i+2].TowerEta= arr[i].TowerEta;
         arr[i].TowerEta=temp;
        temp= arr[i+2].TowerPhi;
         arr[i+2].TowerPhi= arr[i].TowerPhi;
         arr[i].TowerPhi=temp;
      }
    if( arr[i+1].Deposits< arr[i+3].Deposits)
      {
        temp= arr[i+3].Deposits;
         arr[i+3].Deposits= arr[i+1].Deposits;
         arr[i+1].Deposits=temp;
          temp= arr[i+1].PeakEta;
         arr[i+1].PeakEta= arr[i+3].PeakEta;
         arr[i+3].PeakEta=temp;
        temp= arr[i+1].PeakPhi;
         arr[i+1].PeakPhi= arr[i+3].PeakPhi;
         arr[i+3].PeakPhi=temp;
          temp= arr[i+1].TowerEta;
         arr[i+1].TowerEta= arr[i+3].TowerEta;
         arr[i+3].TowerEta=temp;
        temp= arr[i+1].TowerPhi;
         arr[i+1].TowerPhi= arr[i+3].TowerPhi;
         arr[i+3].TowerPhi=temp;
      }
  }
  for(int i=8;i<13;i=i+4)
  {
    #pragma HLS unroll
    if( arr[i].Deposits> arr[i+2].Deposits)
      {
        temp= arr[i+2].Deposits;
         arr[i+2].Deposits= arr[i].Deposits;
         arr[i].Deposits=temp;
        temp= arr[i+2].PeakEta;
         arr[i+2].PeakEta= arr[i].PeakEta;
         arr[i].PeakEta=temp;
        temp= arr[i+2].PeakPhi;
         arr[i+2].PeakPhi= arr[i].PeakPhi;
         arr[i].PeakPhi=temp;
         temp= arr[i+2].TowerEta;
         arr[i+2].TowerEta= arr[i].TowerEta;
         arr[i].TowerEta=temp;
        temp= arr[i+2].TowerPhi;
         arr[i+2].TowerPhi= arr[i].TowerPhi;
         arr[i].TowerPhi=temp;
      }
    if( arr[i+1].Deposits> arr[i+3].Deposits)
      {
        temp= arr[i+3].Deposits;
         arr[i+3].Deposits= arr[i+1].Deposits;
         arr[i+1].Deposits=temp;
         temp= arr[i+1].PeakEta;
         arr[i+1].PeakEta= arr[i+3].PeakEta;
         arr[i+3].PeakEta=temp;
        temp= arr[i+1].PeakPhi;
         arr[i+1].PeakPhi= arr[i+3].PeakPhi;
         arr[i+3].PeakPhi=temp;
         temp= arr[i+1].TowerEta;
         arr[i+1].TowerEta= arr[i+3].TowerEta;
         arr[i+3].TowerEta=temp;
        temp= arr[i+1].TowerPhi;
         arr[i+1].TowerPhi= arr[i+3].TowerPhi;
         arr[i+3].TowerPhi=temp;
      }
  }
  
  for(int i=0;i<7;i=i+2)
  {
    #pragma HLS unroll
    if( arr[i].Deposits< arr[i+1].Deposits)
      {
        temp= arr[i+1].Deposits;
         arr[i+1].Deposits= arr[i].Deposits;
         arr[i].Deposits=temp;
          temp= arr[i].PeakEta;
           arr[i].PeakEta= arr[i+1].PeakEta;
           arr[i+1].PeakEta=temp;
          temp= arr[i].PeakPhi;
           arr[i].PeakPhi= arr[i+1].PeakPhi;
           arr[i+1].PeakPhi=temp;
           temp= arr[i].TowerEta;
           arr[i].TowerEta= arr[i+1].TowerEta;
           arr[i+1].TowerEta=temp;
          temp= arr[i].TowerPhi;
           arr[i].TowerPhi= arr[i+1].TowerPhi;
           arr[i+1].TowerPhi=temp;
      }
  }
  for(int i=8;i<15;i=i+2)
  {
    #pragma HLS unroll
    if( arr[i].Deposits> arr[i+1].Deposits)
      {
        temp= arr[i+1].Deposits;
         arr[i+1].Deposits= arr[i].Deposits;
         arr[i].Deposits=temp;
          temp= arr[i].PeakEta;
           arr[i].PeakEta= arr[i+1].PeakEta;
           arr[i+1].PeakEta=temp;
          temp= arr[i].PeakPhi;
           arr[i].PeakPhi= arr[i+1].PeakPhi;
           arr[i+1].PeakPhi=temp;
           temp= arr[i].TowerEta;
           arr[i].TowerEta= arr[i+1].TowerEta;
           arr[i+1].TowerEta=temp;
          temp= arr[i].TowerPhi;
           arr[i].TowerPhi= arr[i+1].TowerPhi;
           arr[i+1].TowerPhi=temp;
      }
  }
  bitonic_16( arr);
}
void  bitonic_4( Cluster arr[16])
{
  int temp;
// #pragma HLS dataflow
// comparators in blocks of 4
  for(int i=0;i<2;i++)
  {
    #pragma HLS unroll
      if( arr[i].Deposits< arr[i+2].Deposits)
              {temp= arr[i].Deposits;
               arr[i].Deposits= arr[i+2].Deposits;
               arr[i+2].Deposits=temp;
               temp= arr[i].PeakEta;
               arr[i].PeakEta= arr[i+2].PeakEta;
               arr[i+2].PeakEta=temp;
              temp= arr[i].PeakPhi;
               arr[i].PeakPhi= arr[i+2].PeakPhi;
               arr[i+2].PeakPhi=temp;
               temp= arr[i].TowerEta;
               arr[i].TowerEta= arr[i+2].TowerEta;
               arr[i+2].TowerEta=temp;
              temp= arr[i].TowerPhi;
               arr[i].TowerPhi= arr[i+2].TowerPhi;
               arr[i+2].TowerPhi=temp;
              }
  }
  for(int i=4;i<6;i++)
  {
#pragma HLS unroll
    if( arr[i].Deposits> arr[i+2].Deposits)
              {temp= arr[i].Deposits;
               arr[i].Deposits= arr[i+2].Deposits;
               arr[i+2].Deposits=temp;
               temp= arr[i].PeakEta;
               arr[i].PeakEta= arr[i+2].PeakEta;
               arr[i+2].PeakEta=temp;
              temp= arr[i].PeakPhi;
               arr[i].PeakPhi= arr[i+2].PeakPhi;
               arr[i+2].PeakPhi=temp;
               temp= arr[i].TowerEta;
               arr[i].TowerEta= arr[i+2].TowerEta;
               arr[i+2].TowerEta=temp;
              temp= arr[i].TowerPhi;
               arr[i].TowerPhi= arr[i+2].TowerPhi;
               arr[i+2].TowerPhi=temp;
              }
  }
  for(int i=8;i<10;i++)
  {
#pragma HLS unroll
      if( arr[i].Deposits< arr[i+2].Deposits)
              {temp= arr[i].Deposits;
               arr[i].Deposits= arr[i+2].Deposits;
               arr[i+2].Deposits=temp;
               temp= arr[i].PeakEta;
               arr[i].PeakEta= arr[i+2].PeakEta;
               arr[i+2].PeakEta=temp;
              temp= arr[i].PeakPhi;
               arr[i].PeakPhi= arr[i+2].PeakPhi;
               arr[i+2].PeakPhi=temp;
               temp= arr[i].TowerEta;
               arr[i].TowerEta= arr[i+2].TowerEta;
               arr[i+2].TowerEta=temp;
              temp= arr[i].TowerPhi;
               arr[i].TowerPhi= arr[i+2].TowerPhi;
               arr[i+2].TowerPhi=temp;
              }
  }
  for(int i=12;i<14;i++)
  {
#pragma HLS unroll
      if( arr[i].Deposits> arr[i+2].Deposits)
              {temp= arr[i].Deposits;
               arr[i].Deposits= arr[i+2].Deposits;
               arr[i+2].Deposits=temp;
               temp= arr[i].PeakEta;
               arr[i].PeakEta= arr[i+2].PeakEta;
               arr[i+2].PeakEta=temp;
              temp= arr[i].PeakPhi;
               arr[i].PeakPhi= arr[i+2].PeakPhi;
               arr[i+2].PeakPhi=temp;
               temp= arr[i].TowerEta;
               arr[i].TowerEta= arr[i+2].TowerEta;
               arr[i+2].TowerEta=temp;
              temp= arr[i].TowerPhi;
               arr[i].TowerPhi= arr[i+2].TowerPhi;
               arr[i+2].TowerPhi=temp;
              }
  }
  
  for(int i=0;i<3;i=i+2)
  {
  #pragma HLS unroll
    if( arr[i].Deposits< arr[i+1].Deposits)
              {temp= arr[i].Deposits;
               arr[i].Deposits= arr[i+1].Deposits;
               arr[i+1].Deposits=temp;
                temp= arr[i].PeakEta;
               arr[i].PeakEta= arr[i+1].PeakEta;
               arr[i+1].PeakEta=temp;
              temp= arr[i].PeakPhi;
               arr[i].PeakPhi= arr[i+1].PeakPhi;
               arr[i+1].PeakPhi=temp;
                 temp= arr[i].TowerEta;
               arr[i].TowerEta= arr[i+1].TowerEta;
               arr[i+1].TowerEta=temp;
              temp= arr[i].TowerPhi;
               arr[i].TowerPhi= arr[i+1].TowerPhi;
               arr[i+1].TowerPhi=temp;
              }
  }
  for(int i=4;i<7;i=i+2)
  {
  #pragma HLS unroll
    if( arr[i].Deposits> arr[i+1].Deposits)
              {temp= arr[i].Deposits;
               arr[i].Deposits= arr[i+1].Deposits;
               arr[i+1].Deposits=temp;
                temp= arr[i].PeakEta;
               arr[i].PeakEta= arr[i+1].PeakEta;
               arr[i+1].PeakEta=temp;
              temp= arr[i].PeakPhi;
               arr[i].PeakPhi= arr[i+1].PeakPhi;
               arr[i+1].PeakPhi=temp;
                 temp= arr[i].TowerEta;
               arr[i].TowerEta= arr[i+1].TowerEta;
               arr[i+1].TowerEta=temp;
              temp= arr[i].TowerPhi;
               arr[i].TowerPhi= arr[i+1].TowerPhi;
               arr[i+1].TowerPhi=temp;
              }
  }
  for(int i=8;i<11;i=i+2)
  {
  #pragma HLS unroll
    if( arr[i].Deposits< arr[i+1].Deposits)
              {temp= arr[i].Deposits;
               arr[i].Deposits= arr[i+1].Deposits;
               arr[i+1].Deposits=temp;
                temp= arr[i].PeakEta;
               arr[i].PeakEta= arr[i+1].PeakEta;
               arr[i+1].PeakEta=temp;
              temp= arr[i].PeakPhi;
               arr[i].PeakPhi= arr[i+1].PeakPhi;
               arr[i+1].PeakPhi=temp;
                 temp= arr[i].TowerEta;
               arr[i].TowerEta= arr[i+1].TowerEta;
               arr[i+1].TowerEta=temp;
              temp= arr[i].TowerPhi;
               arr[i].TowerPhi= arr[i+1].TowerPhi;
               arr[i+1].TowerPhi=temp;
              }
  }
  for(int i=12;i<15;i=i+2)
  {
  #pragma HLS unroll
    if( arr[i].Deposits> arr[i+1].Deposits)
              {temp= arr[i].Deposits;
               arr[i].Deposits= arr[i+1].Deposits;
               arr[i+1].Deposits=temp;
                temp= arr[i].PeakEta;
               arr[i].PeakEta= arr[i+1].PeakEta;
               arr[i+1].PeakEta=temp;
              temp= arr[i].PeakPhi;
               arr[i].PeakPhi= arr[i+1].PeakPhi;
               arr[i+1].PeakPhi=temp;
                 temp= arr[i].TowerEta;
               arr[i].TowerEta= arr[i+1].TowerEta;
               arr[i+1].TowerEta=temp;
              temp= arr[i].TowerPhi;
               arr[i].TowerPhi= arr[i+1].TowerPhi;
               arr[i+1].TowerPhi=temp;
              }
  }
  
   bitonic_8(arr);

}


void TowerPeaks(uint16_t towerET_uncal[16], uint16_t PeakPhi[16], uint16_t PeakEta[16],uint16_t TowerPhi[16], uint16_t TowerEta[16])  
{
#pragma HLS PIPELINE II=8
#pragma HLS ARRAY_PARTITION variable= towerET_uncal complete dim=0
#pragma HLS ARRAY_PARTITION variable= PeakEta complete dim=0
#pragma HLS ARRAY_PARTITION variable= PeakPhi complete dim=0
#pragma HLS ARRAY_PARTITION variable= TowerEta complete dim=0
#pragma HLS ARRAY_PARTITION variable= TowerPhi complete dim=0

 // ap_fixed<16,9>    ClusterDeposits2[16];
 //  uint16_t  ClusterPeakEta2[16];
 //  uint16_t  ClusterPeakPhi2[16];
 //  uint16_t  ClusterTowerEta2[16];
 //  uint16_t  ClusterTowerPhi2[16];
  struct Cluster arr[16];
  
  for(int i=0;i<16;i++)
{
   arr[i].Deposits=0;
   arr[i].PeakEta=0;
   arr[i].PeakPhi=0;
   arr[i].TowerEta=0;
   arr[i].TowerPhi=0;
}
// #pragma HLS ARRAY_PARTITION variable= ClusterDeposits2 complete dim=0
//  #pragma HLS ARRAY_PARTITION variable= ClusterPeakEta2 complete dim=0
//   #pragma HLS ARRAY_PARTITION variable= ClusterPeakPhi2 complete dim=0
// #pragma HLS ARRAY_PARTITION variable= ClusterTowerEta2 complete dim=0
//   #pragma HLS ARRAY_PARTITION variable= ClusterTowerPhi2 complete dim=0
#pragma HLS ARRAY_PARTITION variable= arr complete dim=0

for(int i=0;i<16;i++)
{
   arr[i].Deposits= towerET_uncal[i];
   arr[i].PeakEta= PeakEta[i];
   arr[i].PeakPhi= PeakPhi[i];
   arr[i].TowerEta= TowerEta[i];
   arr[i].TowerPhi= TowerPhi[i];
}


int temp=0;
//first level of binary comparators
for(int i=0;i<16;i=i+4)
{
#pragma HLS unroll
if( arr[i].Deposits> arr[i+1].Deposits)
{temp= arr[i+1].Deposits;
 arr[i+1].Deposits= arr[i].Deposits;
 arr[i].Deposits=temp;
temp= arr[i].PeakEta;
 arr[i].PeakEta= arr[i+1].PeakEta;
 arr[i+1].PeakEta=temp;
temp= arr[i].PeakPhi;
 arr[i].PeakPhi= arr[i+1].PeakPhi;
 arr[i+1].PeakPhi=temp;
 temp= arr[i].TowerEta;
 arr[i].TowerEta= arr[i+1].TowerEta;
 arr[i+1].TowerEta=temp;
temp= arr[i].TowerPhi;
 arr[i].TowerPhi= arr[i+1].TowerPhi;
 arr[i+1].TowerPhi=temp;
}

if( arr[i+2].Deposits< arr[i+3].Deposits)
{temp= arr[i+3].Deposits;
 arr[i+3].Deposits= arr[i+2].Deposits;
 arr[i+2].Deposits=temp;
temp= arr[i+2].PeakEta;
 arr[i+2].PeakEta= arr[i+3].PeakEta;
 arr[i+3].PeakEta=temp;
temp= arr[i+2].PeakPhi;
 arr[i+2].PeakPhi= arr[i+3].PeakPhi;
 arr[i+3].PeakPhi=temp;
 temp= arr[i+2].TowerEta;
 arr[i+2].TowerEta= arr[i+3].TowerEta;
 arr[i+3].TowerEta=temp;
temp= arr[i+2].TowerPhi;
 arr[i+2].TowerPhi= arr[i+3].TowerPhi;
 arr[i+3].TowerPhi=temp;

}
  }


    // passing control to second level of quaternary comparators
     bitonic_4(arr);

    for(int i=0;i<16;i++)
{
    towerET_uncal[i]=arr[i].Deposits;
   PeakEta[i]= arr[i].PeakEta;
   PeakPhi[i]= arr[i].PeakPhi;
   TowerEta[i]= arr[i].TowerEta;
   TowerPhi[i]= arr[i].TowerPhi;

}
}




