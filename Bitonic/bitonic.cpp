#include "bitonic.h"


#include <iostream>
using namespace std;

void  bitonic_16( ap_fixed<16,9>    Cluster_Deposits[16], uint16_t  Cluster_Peak_Eta[16], uint16_t  Cluster_Peak_Phi[16],uint16_t  Cluster_Tower_Eta[16], uint16_t  Cluster_Tower_Phi[16])
{// sorting blocks of size 16
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<8;i++)
  {
  #pragma HLS unroll
  if( Cluster_Deposits[i]< Cluster_Deposits[i+8])
    {
      temp= Cluster_Deposits[i+8];
       Cluster_Deposits[i+8]= Cluster_Deposits[i];
       Cluster_Deposits[i]=temp;
      temp= Cluster_Peak_Eta[i];
         Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+8];
         Cluster_Peak_Eta[i+8]=temp;
        temp= Cluster_Peak_Phi[i];
         Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+8];
         Cluster_Peak_Phi[i+8]=temp;
         temp= Cluster_Tower_Eta[i];
         Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+8];
         Cluster_Tower_Eta[i+8]=temp;
        temp= Cluster_Tower_Phi[i];
         Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+8];
         Cluster_Tower_Phi[i+8]=temp;
    }

    }

  
   for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if( Cluster_Deposits[i]< Cluster_Deposits[i+4])
    {
      temp= Cluster_Deposits[i+4];
       Cluster_Deposits[i+4]= Cluster_Deposits[i];
       Cluster_Deposits[i]=temp;
      temp= Cluster_Peak_Eta[i];
         Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+4];
         Cluster_Peak_Eta[i+4]=temp;
        temp= Cluster_Peak_Phi[i];
         Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+4];
         Cluster_Peak_Phi[i+4]=temp;
          temp= Cluster_Tower_Eta[i];
         Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+4];
         Cluster_Tower_Eta[i+4]=temp;
        temp= Cluster_Tower_Phi[i];
         Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+4];
         Cluster_Tower_Phi[i+4]=temp;
    }
    }
   for(int i=8;i<12;i++)
  {
  #pragma HLS unroll
  if( Cluster_Deposits[i]< Cluster_Deposits[i+4])
    {
      temp= Cluster_Deposits[i+4];
       Cluster_Deposits[i+4]= Cluster_Deposits[i];
       Cluster_Deposits[i]=temp;
      temp= Cluster_Peak_Eta[i];
         Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+4];
         Cluster_Peak_Eta[i+4]=temp;
        temp= Cluster_Peak_Phi[i];
         Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+4];
         Cluster_Peak_Phi[i+4]=temp;
         temp= Cluster_Tower_Eta[i];
         Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+4];
         Cluster_Tower_Eta[i+4]=temp;
        temp= Cluster_Tower_Phi[i];
         Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+4];
         Cluster_Tower_Phi[i+4]=temp;
    }
    }
  

  for(int i=0;i<13;i=i+4)
  {
  #pragma HLS unroll
  if( Cluster_Deposits[i]< Cluster_Deposits[i+2])
    {
      temp= Cluster_Deposits[i+2];
       Cluster_Deposits[i+2]= Cluster_Deposits[i];
       Cluster_Deposits[i]=temp;
      temp= Cluster_Peak_Eta[i];
           Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+2];
           Cluster_Peak_Eta[i+2]=temp;
          temp= Cluster_Peak_Phi[i];
           Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+2];
           Cluster_Peak_Phi[i+2]=temp;
            temp= Cluster_Tower_Eta[i];
           Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+2];
           Cluster_Tower_Eta[i+2]=temp;
          temp= Cluster_Tower_Phi[i];
           Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+2];
           Cluster_Tower_Phi[i+2]=temp;
    }

    if( Cluster_Deposits[i+1]< Cluster_Deposits[i+3])
    {
      temp= Cluster_Deposits[i+3];
       Cluster_Deposits[i+3]= Cluster_Deposits[i+1];
       Cluster_Deposits[i+1]=temp;
       temp= Cluster_Peak_Eta[i+1];
               Cluster_Peak_Eta[i+1]= Cluster_Peak_Eta[i+3];
               Cluster_Peak_Eta[i+3]=temp;
              temp= Cluster_Peak_Phi[i+1];
               Cluster_Peak_Phi[i+1]= Cluster_Peak_Phi[i+3];
               Cluster_Peak_Phi[i+3]=temp;
               temp= Cluster_Tower_Eta[i+1];
               Cluster_Tower_Eta[i+1]= Cluster_Tower_Eta[i+3];
               Cluster_Tower_Eta[i+3]=temp;
              temp= Cluster_Tower_Phi[i+1];
               Cluster_Tower_Phi[i+1]= Cluster_Tower_Phi[i+3];
               Cluster_Tower_Phi[i+3]=temp;
    }
    }
  
 
   

  for(int i=0;i<15;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if( Cluster_Deposits[i]< Cluster_Deposits[i+1])
    {
      temp= Cluster_Deposits[i+1];
       Cluster_Deposits[i+1]= Cluster_Deposits[i];
       Cluster_Deposits[i]=temp;
       temp= Cluster_Peak_Eta[i];
               Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+1];
               Cluster_Peak_Eta[i+1]=temp;
              temp= Cluster_Peak_Phi[i];
               Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+1];
               Cluster_Peak_Phi[i+1]=temp;
               temp= Cluster_Tower_Eta[i];
               Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+1];
               Cluster_Tower_Eta[i+1]=temp;
              temp= Cluster_Tower_Phi[i];
               Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+1];
               Cluster_Tower_Phi[i+1]=temp;
    }

    }
 


  }

void  bitonic_8( ap_fixed<16,9>    Cluster_Deposits[16], uint16_t  Cluster_Peak_Eta[16], uint16_t  Cluster_Peak_Phi[16],uint16_t  Cluster_Tower_Eta[16], uint16_t  Cluster_Tower_Phi[16])
{// sorting blocks of size 8
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<4;i++)
  {
    #pragma HLS unroll
    if( Cluster_Deposits[i]< Cluster_Deposits[i+4])
      {
        temp= Cluster_Deposits[i+4];
         Cluster_Deposits[i+4]= Cluster_Deposits[i];
         Cluster_Deposits[i]=temp;
        temp= Cluster_Peak_Eta[i];
         Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+4];
         Cluster_Peak_Eta[i+4]=temp;
        temp= Cluster_Peak_Phi[i];
         Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+4];
         Cluster_Peak_Phi[i+4]=temp;
         temp= Cluster_Tower_Eta[i];
         Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+4];
         Cluster_Tower_Eta[i+4]=temp;
        temp= Cluster_Tower_Phi[i];
         Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+4];
         Cluster_Tower_Phi[i+4]=temp;
      }
  }
  for(int i=8;i<12;i++)
  {
    #pragma HLS unroll
    if( Cluster_Deposits[i]> Cluster_Deposits[i+4])
      {
        temp= Cluster_Deposits[i+4];
         Cluster_Deposits[i+4]= Cluster_Deposits[i];
         Cluster_Deposits[i]=temp;
        temp= Cluster_Peak_Eta[i];
         Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+4];
         Cluster_Peak_Eta[i+4]=temp;
        temp= Cluster_Peak_Phi[i];
         Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+4];
         Cluster_Peak_Phi[i+4]=temp;
         temp= Cluster_Tower_Eta[i];
         Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+4];
         Cluster_Tower_Eta[i+4]=temp;
        temp= Cluster_Tower_Phi[i];
         Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+4];
         Cluster_Tower_Phi[i+4]=temp;
      }
  }
 

  for(int i=0;i<5;i=i+4)
  {
    #pragma HLS unroll
    if( Cluster_Deposits[i]< Cluster_Deposits[i+2])
      {
        temp= Cluster_Deposits[i+2];
         Cluster_Deposits[i+2]= Cluster_Deposits[i];
         Cluster_Deposits[i]=temp;
        temp= Cluster_Peak_Eta[i+2];
         Cluster_Peak_Eta[i+2]= Cluster_Peak_Eta[i];
         Cluster_Peak_Eta[i]=temp;
        temp= Cluster_Peak_Phi[i+2];
         Cluster_Peak_Phi[i+2]= Cluster_Peak_Phi[i];
         Cluster_Peak_Phi[i]=temp;
          temp= Cluster_Tower_Eta[i+2];
         Cluster_Tower_Eta[i+2]= Cluster_Tower_Eta[i];
         Cluster_Tower_Eta[i]=temp;
        temp= Cluster_Tower_Phi[i+2];
         Cluster_Tower_Phi[i+2]= Cluster_Tower_Phi[i];
         Cluster_Tower_Phi[i]=temp;
      }
    if( Cluster_Deposits[i+1]< Cluster_Deposits[i+3])
      {
        temp= Cluster_Deposits[i+3];
         Cluster_Deposits[i+3]= Cluster_Deposits[i+1];
         Cluster_Deposits[i+1]=temp;
          temp= Cluster_Peak_Eta[i+1];
         Cluster_Peak_Eta[i+1]= Cluster_Peak_Eta[i+3];
         Cluster_Peak_Eta[i+3]=temp;
        temp= Cluster_Peak_Phi[i+1];
         Cluster_Peak_Phi[i+1]= Cluster_Peak_Phi[i+3];
         Cluster_Peak_Phi[i+3]=temp;
          temp= Cluster_Tower_Eta[i+1];
         Cluster_Tower_Eta[i+1]= Cluster_Tower_Eta[i+3];
         Cluster_Tower_Eta[i+3]=temp;
        temp= Cluster_Tower_Phi[i+1];
         Cluster_Tower_Phi[i+1]= Cluster_Tower_Phi[i+3];
         Cluster_Tower_Phi[i+3]=temp;
      }
  }
  for(int i=8;i<13;i=i+4)
  {
    #pragma HLS unroll
    if( Cluster_Deposits[i]> Cluster_Deposits[i+2])
      {
        temp= Cluster_Deposits[i+2];
         Cluster_Deposits[i+2]= Cluster_Deposits[i];
         Cluster_Deposits[i]=temp;
        temp= Cluster_Peak_Eta[i+2];
         Cluster_Peak_Eta[i+2]= Cluster_Peak_Eta[i];
         Cluster_Peak_Eta[i]=temp;
        temp= Cluster_Peak_Phi[i+2];
         Cluster_Peak_Phi[i+2]= Cluster_Peak_Phi[i];
         Cluster_Peak_Phi[i]=temp;
         temp= Cluster_Tower_Eta[i+2];
         Cluster_Tower_Eta[i+2]= Cluster_Tower_Eta[i];
         Cluster_Tower_Eta[i]=temp;
        temp= Cluster_Tower_Phi[i+2];
         Cluster_Tower_Phi[i+2]= Cluster_Tower_Phi[i];
         Cluster_Tower_Phi[i]=temp;
      }
    if( Cluster_Deposits[i+1]> Cluster_Deposits[i+3])
      {
        temp= Cluster_Deposits[i+3];
         Cluster_Deposits[i+3]= Cluster_Deposits[i+1];
         Cluster_Deposits[i+1]=temp;
         temp= Cluster_Peak_Eta[i+1];
         Cluster_Peak_Eta[i+1]= Cluster_Peak_Eta[i+3];
         Cluster_Peak_Eta[i+3]=temp;
        temp= Cluster_Peak_Phi[i+1];
         Cluster_Peak_Phi[i+1]= Cluster_Peak_Phi[i+3];
         Cluster_Peak_Phi[i+3]=temp;
         temp= Cluster_Tower_Eta[i+1];
         Cluster_Tower_Eta[i+1]= Cluster_Tower_Eta[i+3];
         Cluster_Tower_Eta[i+3]=temp;
        temp= Cluster_Tower_Phi[i+1];
         Cluster_Tower_Phi[i+1]= Cluster_Tower_Phi[i+3];
         Cluster_Tower_Phi[i+3]=temp;
      }
  }
  
  for(int i=0;i<7;i=i+2)
  {
    #pragma HLS unroll
    if( Cluster_Deposits[i]< Cluster_Deposits[i+1])
      {
        temp= Cluster_Deposits[i+1];
         Cluster_Deposits[i+1]= Cluster_Deposits[i];
         Cluster_Deposits[i]=temp;
          temp= Cluster_Peak_Eta[i];
           Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+1];
           Cluster_Peak_Eta[i+1]=temp;
          temp= Cluster_Peak_Phi[i];
           Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+1];
           Cluster_Peak_Phi[i+1]=temp;
           temp= Cluster_Tower_Eta[i];
           Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+1];
           Cluster_Tower_Eta[i+1]=temp;
          temp= Cluster_Tower_Phi[i];
           Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+1];
           Cluster_Tower_Phi[i+1]=temp;
      }
  }
  for(int i=8;i<15;i=i+2)
  {
    #pragma HLS unroll
    if( Cluster_Deposits[i]> Cluster_Deposits[i+1])
      {
        temp= Cluster_Deposits[i+1];
         Cluster_Deposits[i+1]= Cluster_Deposits[i];
         Cluster_Deposits[i]=temp;
          temp= Cluster_Peak_Eta[i];
           Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+1];
           Cluster_Peak_Eta[i+1]=temp;
          temp= Cluster_Peak_Phi[i];
           Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+1];
           Cluster_Peak_Phi[i+1]=temp;
           temp= Cluster_Tower_Eta[i];
           Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+1];
           Cluster_Tower_Eta[i+1]=temp;
          temp= Cluster_Tower_Phi[i];
           Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+1];
           Cluster_Tower_Phi[i+1]=temp;
      }
  }
  bitonic_16( Cluster_Deposits, Cluster_Peak_Eta, Cluster_Peak_Phi,Cluster_Tower_Eta, Cluster_Tower_Phi);
}
void  bitonic_4( ap_fixed<16,9>    Cluster_Deposits[16], uint16_t  Cluster_Peak_Eta[16], uint16_t  Cluster_Peak_Phi[16],uint16_t  Cluster_Tower_Eta[16], uint16_t  Cluster_Tower_Phi[16])
{
  int temp;
// #pragma HLS dataflow
// comparators in blocks of 4
  for(int i=0;i<2;i++)
  {
    #pragma HLS unroll
      if( Cluster_Deposits[i]< Cluster_Deposits[i+2])
              {temp= Cluster_Deposits[i];
               Cluster_Deposits[i]= Cluster_Deposits[i+2];
               Cluster_Deposits[i+2]=temp;
               temp= Cluster_Peak_Eta[i];
               Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+2];
               Cluster_Peak_Eta[i+2]=temp;
              temp= Cluster_Peak_Phi[i];
               Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+2];
               Cluster_Peak_Phi[i+2]=temp;
               temp= Cluster_Tower_Eta[i];
               Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+2];
               Cluster_Tower_Eta[i+2]=temp;
              temp= Cluster_Tower_Phi[i];
               Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+2];
               Cluster_Tower_Phi[i+2]=temp;
              }
  }
  for(int i=4;i<6;i++)
  {
#pragma HLS unroll
    if( Cluster_Deposits[i]> Cluster_Deposits[i+2])
              {temp= Cluster_Deposits[i];
               Cluster_Deposits[i]= Cluster_Deposits[i+2];
               Cluster_Deposits[i+2]=temp;
               temp= Cluster_Peak_Eta[i];
               Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+2];
               Cluster_Peak_Eta[i+2]=temp;
              temp= Cluster_Peak_Phi[i];
               Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+2];
               Cluster_Peak_Phi[i+2]=temp;
               temp= Cluster_Tower_Eta[i];
               Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+2];
               Cluster_Tower_Eta[i+2]=temp;
              temp= Cluster_Tower_Phi[i];
               Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+2];
               Cluster_Tower_Phi[i+2]=temp;
              }
  }
  for(int i=8;i<10;i++)
  {
#pragma HLS unroll
      if( Cluster_Deposits[i]< Cluster_Deposits[i+2])
              {temp= Cluster_Deposits[i];
               Cluster_Deposits[i]= Cluster_Deposits[i+2];
               Cluster_Deposits[i+2]=temp;
               temp= Cluster_Peak_Eta[i];
               Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+2];
               Cluster_Peak_Eta[i+2]=temp;
              temp= Cluster_Peak_Phi[i];
               Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+2];
               Cluster_Peak_Phi[i+2]=temp;
               temp= Cluster_Tower_Eta[i];
               Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+2];
               Cluster_Tower_Eta[i+2]=temp;
              temp= Cluster_Tower_Phi[i];
               Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+2];
               Cluster_Tower_Phi[i+2]=temp;
              }
  }
  for(int i=12;i<14;i++)
  {
#pragma HLS unroll
      if( Cluster_Deposits[i]> Cluster_Deposits[i+2])
              {temp= Cluster_Deposits[i];
               Cluster_Deposits[i]= Cluster_Deposits[i+2];
               Cluster_Deposits[i+2]=temp;
               temp= Cluster_Peak_Eta[i];
               Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+2];
               Cluster_Peak_Eta[i+2]=temp;
              temp= Cluster_Peak_Phi[i];
               Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+2];
               Cluster_Peak_Phi[i+2]=temp;
               temp= Cluster_Tower_Eta[i];
               Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+2];
               Cluster_Tower_Eta[i+2]=temp;
              temp= Cluster_Tower_Phi[i];
               Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+2];
               Cluster_Tower_Phi[i+2]=temp;
              }
  }
  
  for(int i=0;i<3;i=i+2)
  {
  #pragma HLS unroll
    if( Cluster_Deposits[i]< Cluster_Deposits[i+1])
              {temp= Cluster_Deposits[i];
               Cluster_Deposits[i]= Cluster_Deposits[i+1];
               Cluster_Deposits[i+1]=temp;
                temp= Cluster_Peak_Eta[i];
               Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+1];
               Cluster_Peak_Eta[i+1]=temp;
              temp= Cluster_Peak_Phi[i];
               Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+1];
               Cluster_Peak_Phi[i+1]=temp;
                 temp= Cluster_Tower_Eta[i];
               Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+1];
               Cluster_Tower_Eta[i+1]=temp;
              temp= Cluster_Tower_Phi[i];
               Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+1];
               Cluster_Tower_Phi[i+1]=temp;
              }
  }
  for(int i=4;i<7;i=i+2)
  {
  #pragma HLS unroll
    if( Cluster_Deposits[i]> Cluster_Deposits[i+1])
              {temp= Cluster_Deposits[i];
               Cluster_Deposits[i]= Cluster_Deposits[i+1];
               Cluster_Deposits[i+1]=temp;
                temp= Cluster_Peak_Eta[i];
               Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+1];
               Cluster_Peak_Eta[i+1]=temp;
              temp= Cluster_Peak_Phi[i];
               Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+1];
               Cluster_Peak_Phi[i+1]=temp;
                 temp= Cluster_Tower_Eta[i];
               Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+1];
               Cluster_Tower_Eta[i+1]=temp;
              temp= Cluster_Tower_Phi[i];
               Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+1];
               Cluster_Tower_Phi[i+1]=temp;
              }
  }
  for(int i=8;i<11;i=i+2)
  {
  #pragma HLS unroll
    if( Cluster_Deposits[i]< Cluster_Deposits[i+1])
              {temp= Cluster_Deposits[i];
               Cluster_Deposits[i]= Cluster_Deposits[i+1];
               Cluster_Deposits[i+1]=temp;
                temp= Cluster_Peak_Eta[i];
               Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+1];
               Cluster_Peak_Eta[i+1]=temp;
              temp= Cluster_Peak_Phi[i];
               Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+1];
               Cluster_Peak_Phi[i+1]=temp;
                 temp= Cluster_Tower_Eta[i];
               Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+1];
               Cluster_Tower_Eta[i+1]=temp;
              temp= Cluster_Tower_Phi[i];
               Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+1];
               Cluster_Tower_Phi[i+1]=temp;
              }
  }
  for(int i=12;i<15;i=i+2)
  {
  #pragma HLS unroll
    if( Cluster_Deposits[i]> Cluster_Deposits[i+1])
              {temp= Cluster_Deposits[i];
               Cluster_Deposits[i]= Cluster_Deposits[i+1];
               Cluster_Deposits[i+1]=temp;
                temp= Cluster_Peak_Eta[i];
               Cluster_Peak_Eta[i]= Cluster_Peak_Eta[i+1];
               Cluster_Peak_Eta[i+1]=temp;
              temp= Cluster_Peak_Phi[i];
               Cluster_Peak_Phi[i]= Cluster_Peak_Phi[i+1];
               Cluster_Peak_Phi[i+1]=temp;
                 temp= Cluster_Tower_Eta[i];
               Cluster_Tower_Eta[i]= Cluster_Tower_Eta[i+1];
               Cluster_Tower_Eta[i+1]=temp;
              temp= Cluster_Tower_Phi[i];
               Cluster_Tower_Phi[i]= Cluster_Tower_Phi[i+1];
               Cluster_Tower_Phi[i+1]=temp;
              }
  }
  
   bitonic_8( Cluster_Deposits, Cluster_Peak_Eta, Cluster_Peak_Phi,Cluster_Tower_Eta, Cluster_Tower_Phi);

}

struct Cluster{
 ap_fixed<16,9>    ClusterDeposits2[16];
  uint16_t  ClusterPeakEta2[16];
  uint16_t  ClusterPeakPhi2[16];
  uint16_t  ClusterTowerEta2[16];
  uint16_t  ClusterTowerPhi2[16];
};
void  TowerPeaks( uint16_t towerET_uncal[16],uint16_t  PeakPhi[16], uint16_t  PeakEta[16], uint16_t  TowerPhi[16], uint16_t  TowerEta[16])
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
  for(int i=0;i<16;i++)
{
   ClusterDeposits2[i]=0;
   ClusterPeakEta2[i]=0;
   ClusterPeakPhi2[i]=0;
   ClusterTowerEta2[i]=0;
   ClusterTowerPhi2[i]=0;
}
#pragma HLS ARRAY_PARTITION variable= ClusterDeposits2 complete dim=0
 #pragma HLS ARRAY_PARTITION variable= ClusterPeakEta2 complete dim=0
  #pragma HLS ARRAY_PARTITION variable= ClusterPeakPhi2 complete dim=0
#pragma HLS ARRAY_PARTITION variable= ClusterTowerEta2 complete dim=0
  #pragma HLS ARRAY_PARTITION variable= ClusterTowerPhi2 complete dim=0
for(int i=0;i<16;i++)
{
   ClusterDeposits2[i]= towerET_uncal[i];
   ClusterPeakEta2[i]= PeakEta[i];
   ClusterPeakPhi2[i]= PeakPhi[i];
   ClusterTowerEta2[i]= TowerEta[i];
   ClusterTowerPhi2[i]= TowerPhi[i];
}


int temp=0;
//first level of binary comparators
for(int i=0;i<16;i=i+4)
{
#pragma HLS unroll
if( ClusterDeposits2[i]> ClusterDeposits2[i+1])
{temp= ClusterDeposits2[i+1];
 ClusterDeposits2[i+1]= ClusterDeposits2[i];
 ClusterDeposits2[i]=temp;
temp= ClusterPeakEta2[i];
 ClusterPeakEta2[i]= ClusterPeakEta2[i+1];
 ClusterPeakEta2[i+1]=temp;
temp= ClusterPeakPhi2[i];
 ClusterPeakPhi2[i]= ClusterPeakPhi2[i+1];
 ClusterPeakPhi2[i+1]=temp;
 temp= ClusterTowerEta2[i];
 ClusterTowerEta2[i]= ClusterTowerEta2[i+1];
 ClusterTowerEta2[i+1]=temp;
temp= ClusterTowerPhi2[i];
 ClusterTowerPhi2[i]= ClusterTowerPhi2[i+1];
 ClusterTowerPhi2[i+1]=temp;
}

if( ClusterDeposits2[i+2]< ClusterDeposits2[i+3])
{temp= ClusterDeposits2[i+3];
 ClusterDeposits2[i+3]= ClusterDeposits2[i+2];
 ClusterDeposits2[i+2]=temp;
temp= ClusterPeakEta2[i+2];
 ClusterPeakEta2[i+2]= ClusterPeakEta2[i+3];
 ClusterPeakEta2[i+3]=temp;
temp= ClusterPeakPhi2[i+2];
 ClusterPeakPhi2[i+2]= ClusterPeakPhi2[i+3];
 ClusterPeakPhi2[i+3]=temp;
 temp= ClusterTowerEta2[i+2];
 ClusterTowerEta2[i+2]= ClusterTowerEta2[i+3];
 ClusterTowerEta2[i+3]=temp;
temp= ClusterTowerPhi2[i+2];
 ClusterTowerPhi2[i+2]= ClusterTowerPhi2[i+3];
 ClusterTowerPhi2[i+3]=temp;

}
  }


    // passing control to second level of quaternary comparators
     bitonic_4(ClusterDeposits2, ClusterPeakEta2, ClusterPeakPhi2,ClusterTowerEta2, ClusterTowerPhi2);

    for(int i=0;i<16;i++)
{
    towerET_uncal[i]=ClusterDeposits2[i];
   PeakEta[i]= ClusterPeakEta2[i];
   PeakPhi[i]= ClusterPeakPhi2[i];
   TowerEta[i]= ClusterTowerEta2[i];
   TowerPhi[i]= ClusterTowerPhi2[i];

}
}




