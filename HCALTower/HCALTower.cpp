#include "HCALTower.h"
uint16_t ClusterDeposits[32];// Global array variable used; doesn't waste clock cycles in copying the array between functions
//hardcoding the blocks of the recursive algorithm necessary to reduce clock cycles.

uint16_t ClusterEta[32];
uint16_t ClusterPhi[32];

void bitonic32()
{// sorting blocks of size 32
  int temp;
// #pragma HLS dataflow
for(int i=0;i<16;i++)
{
#pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+16])
    {
      temp=ClusterDeposits[i+16];
      ClusterDeposits[i+16]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+16];
        ClusterEta[i+16]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+16];
        ClusterPhi[i+16]=temp;
    }
  }

  for(int i=0;i<8;i++)
  {
#pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+8])
        {
          temp=ClusterDeposits[i+8];
          ClusterDeposits[i+8]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+8];
        ClusterEta[i+8]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+8];
        ClusterPhi[i+8]=temp;
        }
  }
  for(int i=16;i<24;i++)
    {
  #pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+8])
          {
            temp=ClusterDeposits[i+8];
            ClusterDeposits[i+8]=ClusterDeposits[i];
            ClusterDeposits[i]=temp;
            temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+8];
        ClusterEta[i+8]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+8];
        ClusterPhi[i+8]=temp;
          }
    }



 for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]>ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }
 for(int i=8;i<12;i++)
      {
      #pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+4])
        {
          temp=ClusterDeposits[i+4];
          ClusterDeposits[i+4]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
        }
        }
 for(int i=16;i<20;i++)
      {
      #pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+4])
        {
          temp=ClusterDeposits[i+4];
          ClusterDeposits[i+4]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
        }
        }
 for(int i=24;i<28;i++)
      {
      #pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+4])
        {
          temp=ClusterDeposits[i+4];
          ClusterDeposits[i+4]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
        }
        }


 for(int i=0;i<29;i=i+4)
            {
            #pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+2])
          {
              temp=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=ClusterDeposits[i];
              ClusterDeposits[i]=temp;
               temp=ClusterEta[i];
                ClusterEta[i]=ClusterEta[i+2];
                ClusterEta[i+2]=temp;
                temp=ClusterPhi[i];
                ClusterPhi[i]=ClusterPhi[i+2];
                ClusterPhi[i+2]=temp;
          }
          if(ClusterDeposits[i+1]>ClusterDeposits[i+3])
          {
              temp=ClusterDeposits[i+3];
              ClusterDeposits[i+3]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
              temp=ClusterEta[i+1];
               ClusterEta[i+1]=ClusterEta[i+3];
               ClusterEta[i+3]=temp;
               temp=ClusterPhi[i+1];
               ClusterPhi[i+1]=ClusterPhi[i+3];
               ClusterPhi[i+3]=temp;
          }
          }


     for(int i=0;i<31;i=i+2)
      {
      #pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+1])
        {
          temp=ClusterDeposits[i+1];
          ClusterDeposits[i+1]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
        }
      }

  }  
void bitonic16()
{// sorting blocks of size 16
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<8;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]>ClusterDeposits[i+8])
    {
      temp=ClusterDeposits[i+8];
      ClusterDeposits[i+8]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+8];
        ClusterEta[i+8]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+8];
        ClusterPhi[i+8]=temp;
    }

    }

  for(int i=16;i<24;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]<ClusterDeposits[i+8])
    {
      temp=ClusterDeposits[i+8];
      ClusterDeposits[i+8]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+8];
        ClusterEta[i+8]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+8];
        ClusterPhi[i+8]=temp;
    }

    }
   for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]>ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }
   for(int i=8;i<12;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]>ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }
   for(int i=16;i<20;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]<ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }
  for(int i=24;i<28;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]<ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }

  for(int i=0;i<13;i=i+4)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]>ClusterDeposits[i+2])
    {
      temp=ClusterDeposits[i+2];
      ClusterDeposits[i+2]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+2];
          ClusterEta[i+2]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+2];
          ClusterPhi[i+2]=temp;
    }

    if(ClusterDeposits[i+1]>ClusterDeposits[i+3])
    {
      temp=ClusterDeposits[i+3];
      ClusterDeposits[i+3]=ClusterDeposits[i+1];
      ClusterDeposits[i+1]=temp;
       temp=ClusterEta[i+1];
              ClusterEta[i+1]=ClusterEta[i+3];
              ClusterEta[i+3]=temp;
              temp=ClusterPhi[i+1];
              ClusterPhi[i+1]=ClusterPhi[i+3];
              ClusterPhi[i+3]=temp;
    }
    }
  for(int i=16;i<29;i=i+4)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]<ClusterDeposits[i+2])
    {
      temp=ClusterDeposits[i+2];
      ClusterDeposits[i+2]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+2];
          ClusterEta[i+2]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+2];
          ClusterPhi[i+2]=temp;
    }

    if(ClusterDeposits[i+1]<ClusterDeposits[i+3])
    {
      temp=ClusterDeposits[i+3];
      ClusterDeposits[i+3]=ClusterDeposits[i+1];
      ClusterDeposits[i+1]=temp;
       temp=ClusterEta[i+1];
              ClusterEta[i+1]=ClusterEta[i+3];
              ClusterEta[i+3]=temp;
              temp=ClusterPhi[i+1];
              ClusterPhi[i+1]=ClusterPhi[i+3];
              ClusterPhi[i+3]=temp;
    }
    }
 
   

  for(int i=0;i<15;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if(ClusterDeposits[i]>ClusterDeposits[i+1])
    {
      temp=ClusterDeposits[i+1];
      ClusterDeposits[i+1]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
       temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
    }

    }
  for(int i=16;i<31;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if(ClusterDeposits[i]<ClusterDeposits[i+1])
    {
      temp=ClusterDeposits[i+1];
      ClusterDeposits[i+1]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
       temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
    }

    }


bitonic32();
  }

void bitonic8()
{// sorting blocks of size 8
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<4;i++)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+4])
      {
        temp=ClusterDeposits[i+4];
        ClusterDeposits[i+4]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
      }
  }
  for(int i=8;i<12;i++)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+4])
      {
        temp=ClusterDeposits[i+4];
        ClusterDeposits[i+4]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
      }
  }
  for(int i=16;i<20;i++)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+4])
      {
        temp=ClusterDeposits[i+4];
        ClusterDeposits[i+4]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
      }
  }
  for(int i=24;i<28;i++)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+4])
      {
        temp=ClusterDeposits[i+4];
        ClusterDeposits[i+4]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
      }
  }


  for(int i=0;i<5;i=i+4)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+2])
      {
        temp=ClusterDeposits[i+2];
        ClusterDeposits[i+2]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i+2];
        ClusterEta[i+2]=ClusterEta[i];
        ClusterEta[i]=temp;
        temp=ClusterPhi[i+2];
        ClusterPhi[i+2]=ClusterPhi[i];
        ClusterPhi[i]=temp;
      }
    if(ClusterDeposits[i+1]>ClusterDeposits[i+3])
      {
        temp=ClusterDeposits[i+3];
        ClusterDeposits[i+3]=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=temp;
          temp=ClusterEta[i+1];
        ClusterEta[i+1]=ClusterEta[i+3];
        ClusterEta[i+3]=temp;
        temp=ClusterPhi[i+1];
        ClusterPhi[i+1]=ClusterPhi[i+3];
        ClusterPhi[i+3]=temp;
      }
  }
  for(int i=8;i<13;i=i+4)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+2])
      {
        temp=ClusterDeposits[i+2];
        ClusterDeposits[i+2]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i+2];
        ClusterEta[i+2]=ClusterEta[i];
        ClusterEta[i]=temp;
        temp=ClusterPhi[i+2];
        ClusterPhi[i+2]=ClusterPhi[i];
        ClusterPhi[i]=temp;
      }
    if(ClusterDeposits[i+1]<ClusterDeposits[i+3])
      {
        temp=ClusterDeposits[i+3];
        ClusterDeposits[i+3]=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=temp;
         temp=ClusterEta[i+1];
        ClusterEta[i+1]=ClusterEta[i+3];
        ClusterEta[i+3]=temp;
        temp=ClusterPhi[i+1];
        ClusterPhi[i+1]=ClusterPhi[i+3];
        ClusterPhi[i+3]=temp;
      }
  }
  for(int i=16;i<21;i=i+4)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+2])
      {
        temp=ClusterDeposits[i+2];
        ClusterDeposits[i+2]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i+2];
        ClusterEta[i+2]=ClusterEta[i];
        ClusterEta[i]=temp;
        temp=ClusterPhi[i+2];
        ClusterPhi[i+2]=ClusterPhi[i];
        ClusterPhi[i]=temp;
      }
    if(ClusterDeposits[i+1]>ClusterDeposits[i+3])
      {
        temp=ClusterDeposits[i+3];
        ClusterDeposits[i+3]=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=temp;
         temp=ClusterEta[i+1];
        ClusterEta[i+1]=ClusterEta[i+3];
        ClusterEta[i+3]=temp;
        temp=ClusterPhi[i+1];
        ClusterPhi[i+1]=ClusterPhi[i+3];
        ClusterPhi[i+3]=temp;
      }
  }
  for(int i=24;i<29;i=i+4)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+2])
      {
        temp=ClusterDeposits[i+2];
        ClusterDeposits[i+2]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i+2];
        ClusterEta[i+2]=ClusterEta[i];
        ClusterEta[i]=temp;
        temp=ClusterPhi[i+2];
        ClusterPhi[i+2]=ClusterPhi[i];
        ClusterPhi[i]=temp;
      }
      
    if(ClusterDeposits[i+1]<ClusterDeposits[i+3])
      {
        temp=ClusterDeposits[i+3];
        ClusterDeposits[i+3]=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=temp;
        temp=ClusterEta[i+1];
        ClusterEta[i+1]=ClusterEta[i+3];
        ClusterEta[i+3]=temp;
        temp=ClusterPhi[i+1];
        ClusterPhi[i+1]=ClusterPhi[i+3];
        ClusterPhi[i+3]=temp;
      }
      
  }


  for(int i=0;i<7;i=i+2)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
      {
        temp=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+1];
          ClusterEta[i+1]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+1];
          ClusterPhi[i+1]=temp;
      }
  }
  for(int i=8;i<15;i=i+2)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
      {
        temp=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+1];
          ClusterEta[i+1]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+1];
          ClusterPhi[i+1]=temp;
      }
  }
  for(int i=16;i<23;i=i+2)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
      {
        temp=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+1];
          ClusterEta[i+1]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+1];
          ClusterPhi[i+1]=temp;
      }
  }
  for(int i=24;i<31;i=i+2)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
      {
        temp=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
         temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+1];
          ClusterEta[i+1]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+1];
          ClusterPhi[i+1]=temp;
      }
  }
 
bitonic16();
}
void bitonic4()
{
  int temp;
// #pragma HLS dataflow
// comparators in blocks of 4
  for(int i=0;i<2;i++)
  {
    #pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=4;i<6;i++)
  {
#pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=8;i<10;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=12;i<14;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=16;i<18;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=20;i<22;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=24;i<26;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=28;i<30;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
 
  for(int i=0;i<3;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=4;i<7;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=8;i<11;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=12;i<15;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=16;i<19;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=20;i<23;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=24;i<27;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=28;i<31;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  
  bitonic8();

}
void getTowerPeaks3x4(uint16_t towerETRegions[3][4],uint16_t cEta[5],
                        uint16_t cPhi[5])
{
  int temp;// temporary copying variable
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=cEta complete dim=0
 #pragma HLS ARRAY_PARTITION variable=cPhi complete dim=0
#pragma HLS ARRAY_PARTITION variable=towerETRegions complete dim=0
  #pragma HLS ARRAY_PARTITION variable=ClusterDeposits complete dim=0
 #pragma HLS ARRAY_PARTITION variable=ClusterEta complete dim=0
  #pragma HLS ARRAY_PARTITION variable=ClusterPhi complete dim=0
// #pragma HLS dataflow
  //copying input array into global array
// for(int i=0;i<128;i++)
// {
// #pragma HLS unroll
//   ClusterDeposits[i]=b[i];
// }
  int i=0;
 for(int tPhi = 0; tPhi < 4; tPhi++) {
#pragma HLS UNROLL
    for(int tEta = 0; tEta < 3; tEta++) {
#pragma HLS UNROLL
      ClusterDeposits[i] = towerETRegions[tEta][tPhi];
       ClusterPhi[i]=tPhi;
      ClusterEta[i]=tEta;
     i++;
    }
  }
for (int i=13;i<32;i++)
{
#pragma HLS UNROLL
 ClusterDeposits[i]=0;
}
//first level of binary comparators
for(int i=0;i<32;i=i+4)
{
#pragma HLS unroll
if(ClusterDeposits[i]>ClusterDeposits[i+1])
{temp=ClusterDeposits[i+1];
ClusterDeposits[i+1]=ClusterDeposits[i];
ClusterDeposits[i]=temp;
temp=ClusterEta[i];
ClusterEta[i]=ClusterEta[i+1];
ClusterEta[i+1]=temp;
temp=ClusterPhi[i];
ClusterPhi[i]=ClusterPhi[i+1];
ClusterPhi[i+1]=temp;
}

if(ClusterDeposits[i+2]<ClusterDeposits[i+3])
{temp=ClusterDeposits[i+3];
ClusterDeposits[i+3]=ClusterDeposits[i+2];
ClusterDeposits[i+2]=temp;
temp=ClusterEta[i+2];
ClusterEta[i+2]=ClusterEta[i+3];
ClusterEta[i+3]=temp;
temp=ClusterPhi[i+2];
ClusterPhi[i+2]=ClusterPhi[i+3];
ClusterPhi[i+3]=temp;

}
  }


    // passing control to second level of quaternary comparators
    bitonic4();
    //copying sorted array back into output variable
for(int i=0;i<5;i++)
{
  cEta[i]=ClusterEta[31-i];
  cPhi[i]=ClusterPhi[31-i];
}
  


}
void TowerPeaks(uint16_t towerET[17][4],  uint16_t TowerPhi[30], uint16_t TowerEta[30])
{
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=towerET complete dim=0

#pragma HLS ARRAY_PARTITION variable=TowerEta complete dim=0
#pragma HLS ARRAY_PARTITION variable=TowerPhi complete dim=0

uint16_t regions[3][4];
#pragma HLS ARRAY_PARTITION variable=regions complete dim=0
uint16_t regionEta[5];
#pragma HLS ARRAY_PARTITION variable=regionEta complete dim=0
uint16_t regionPhi[5];
#pragma HLS ARRAY_PARTITION variable=regionPhi complete dim=0
int x=0;
for (int i=0;i<15;i=i+3)
{
#pragma HLS UNROLL
 for (int j=0;j<3;j++)
  {
  #pragma HLS UNROLL
      for (int k=0;k<4;k++)
      {
      #pragma HLS UNROLL
        regions[j][k]=towerET[i+j][k];
      }
  }

getTowerPeaks3x4(regions,regionEta,regionPhi);
TowerEta[x+0]=regionEta[0]+i;
TowerEta[x+1]=regionEta[1]+i;
TowerEta[x+2]=regionEta[2]+i;
TowerEta[x+3]=regionEta[3]+i;
TowerEta[x+4]=regionEta[4]+i;
TowerPhi[x+0]=regionPhi[0];
TowerPhi[x+1]=regionPhi[1];
TowerPhi[x+2]=regionPhi[2];
TowerPhi[x+3]=regionPhi[3];
TowerPhi[x+4]=regionPhi[4];
x=x+5;
}
for (int j=0;j<2;j++)
  {
  #pragma HLS UNROLL
      for (int k=0;k<4;k++)
      {
      #pragma HLS UNROLL
        regions[j][k]=towerET[j+15][k];
      }
  }
  regions[2][0]=0;
  regions[2][1]=0;
  regions[2][2]=0;
  regions[2][3]=0;
  getTowerPeaks3x4(regions,regionEta,regionPhi);
TowerEta[25+0]=regionEta[0]+15;
TowerEta[25+1]=regionEta[1]+15;
TowerEta[25+2]=regionEta[2]+15;
TowerEta[25+3]=regionEta[3]+15;
TowerEta[25+4]=regionEta[4]+15;
TowerPhi[25+0]=regionPhi[0];
TowerPhi[25+1]=regionPhi[1];
TowerPhi[25+2]=regionPhi[2];
TowerPhi[25+3]=regionPhi[3];
TowerPhi[25+4]=regionPhi[4];
for(int i=0;i<30;i++)
{
  ClusterDeposits[i]=towerET[TowerEta[i]][TowerPhi[i]];
  ClusterEta[i]=TowerEta[i];
  ClusterPhi[i]=TowerPhi[i];
}
ClusterDeposits[30]=0;
ClusterDeposits[31]=0;
ClusterEta[30]=0;
ClusterEta[31]=0;
ClusterPhi[30]=0;
ClusterPhi[31]=0;

int temp=0;
//first level of binary comparators
for(int i=0;i<32;i=i+4)
{
#pragma HLS unroll
if(ClusterDeposits[i]>ClusterDeposits[i+1])
{temp=ClusterDeposits[i+1];
ClusterDeposits[i+1]=ClusterDeposits[i];
ClusterDeposits[i]=temp;
temp=ClusterEta[i];
ClusterEta[i]=ClusterEta[i+1];
ClusterEta[i+1]=temp;
temp=ClusterPhi[i];
ClusterPhi[i]=ClusterPhi[i+1];
ClusterPhi[i+1]=temp;
}

if(ClusterDeposits[i+2]<ClusterDeposits[i+3])
{temp=ClusterDeposits[i+3];
ClusterDeposits[i+3]=ClusterDeposits[i+2];
ClusterDeposits[i+2]=temp;
temp=ClusterEta[i+2];
ClusterEta[i+2]=ClusterEta[i+3];
ClusterEta[i+3]=temp;
temp=ClusterPhi[i+2];
ClusterPhi[i+2]=ClusterPhi[i+3];
ClusterPhi[i+3]=temp;

}
  }


    // passing control to second level of quaternary comparators
    bitonic4();

    for(int i=0;i<30;i++)
{

  TowerEta[i]=ClusterEta[31-i];
  TowerPhi[i]=ClusterPhi[31-i];
}
}




