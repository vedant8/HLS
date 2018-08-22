#include "ClusterfinderCombined.hh"
#include "ECAL_Calib_LUT.h"
#include "HCAL_Calib_LUT.h"

#include <iostream>
using namespace std;


void ECAL_bitonic32(ap_fixed<16,9> ECAL_Cluster_1_Deposits[32], uint16_t ECAL_ClusterEta[32], uint16_t ECAL_ClusterPhi[32])
{// sorting blocks of size 32                                                                                                                                                        
  int temp;
  // #pragma HLS dataflow                                                                                                                                                              
  for(int i=0;i<16;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+16])
	{
	  temp=ECAL_Cluster_1_Deposits[i+16];
	  ECAL_Cluster_1_Deposits[i+16]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+16];
	  ECAL_ClusterEta[i+16]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+16];
	  ECAL_ClusterPhi[i+16]=temp;
	}
    }

  for(int i=0;i<8;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+8])
        {
          temp=ECAL_Cluster_1_Deposits[i+8];
          ECAL_Cluster_1_Deposits[i+8]=ECAL_Cluster_1_Deposits[i];
          ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+8];
	  ECAL_ClusterEta[i+8]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+8];
	  ECAL_ClusterPhi[i+8]=temp;
        }
    }

  for(int i=16;i<24;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+8])
	{
	  temp=ECAL_Cluster_1_Deposits[i+8];
	  ECAL_Cluster_1_Deposits[i+8]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+8];
	  ECAL_ClusterEta[i+8]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+8];
	  ECAL_ClusterPhi[i+8]=temp;
	}
    }

  for(int i=0;i<4;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
	}
    }
  for(int i=8;i<12;i++)
    {
      #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
        {
          temp=ECAL_Cluster_1_Deposits[i+4];
          ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
          ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
        }
    }


  for(int i=16;i<20;i++)
    {
      #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
        {
          temp=ECAL_Cluster_1_Deposits[i+4];
          ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
          ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
        }
    }

  for(int i=24;i<28;i++)
    {
      #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
        {
          temp=ECAL_Cluster_1_Deposits[i+4];
          ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
          ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
        }
    }

  for(int i=0;i<29;i=i+4)
    {
            #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=temp;
	}
      if(ECAL_Cluster_1_Deposits[i+1]<ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=ECAL_ClusterEta[i+3];
	  ECAL_ClusterEta[i+3]=temp;
	  temp=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=ECAL_ClusterPhi[i+3];
	  ECAL_ClusterPhi[i+3]=temp;
	}
    }




  for(int i=0;i<31;i=i+2)
    {
      #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
        {
          temp=ECAL_Cluster_1_Deposits[i+1];
          ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
          ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
        }
    }

}


void ECAL_bitonic16(ap_fixed<16,9> ECAL_Cluster_1_Deposits[32], uint16_t ECAL_ClusterEta[32], uint16_t ECAL_ClusterPhi[32])
{// sorting blocks of size 16                                                                                                                                                        
  int temp;
  // #pragma HLS dataflow                                                                                                                                                              
  for(int i=0;i<8;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+8])
	{
	  temp=ECAL_Cluster_1_Deposits[i+8];
	  ECAL_Cluster_1_Deposits[i+8]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+8];
	  ECAL_ClusterEta[i+8]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+8];
	  ECAL_ClusterPhi[i+8]=temp;
	}

    }

  for(int i=16;i<24;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+8])
	{
	  temp=ECAL_Cluster_1_Deposits[i+8];
	  ECAL_Cluster_1_Deposits[i+8]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+8];
	  ECAL_ClusterEta[i+8]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+8];
	  ECAL_ClusterPhi[i+8]=temp;
	}

    }

  for(int i=0;i<4;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
	}
    }
  for(int i=8;i<12;i++)
    {
 #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
	}
    }
  for(int i=16;i<20;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
	}
    }

  for(int i=24;i<28;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
	}
    }

  for(int i=0;i<13;i=i+4)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
          ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
          ECAL_ClusterEta[i+2]=temp;
          temp=ECAL_ClusterPhi[i];
          ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
          ECAL_ClusterPhi[i+2]=temp;
	}

      if(ECAL_Cluster_1_Deposits[i+1]<ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=ECAL_ClusterEta[i+3];
	  ECAL_ClusterEta[i+3]=temp;
	  temp=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=ECAL_ClusterPhi[i+3];
	  ECAL_ClusterPhi[i+3]=temp;
	}
    }

  for(int i=16;i<29;i=i+4)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
          ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
          ECAL_ClusterEta[i+2]=temp;
          temp=ECAL_ClusterPhi[i];
          ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
          ECAL_ClusterPhi[i+2]=temp;
	}


      if(ECAL_Cluster_1_Deposits[i+1]>ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=ECAL_ClusterEta[i+3];
	  ECAL_ClusterEta[i+3]=temp;
	  temp=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=ECAL_ClusterPhi[i+3];
	  ECAL_ClusterPhi[i+3]=temp;
	}
    }



  for(int i=0;i<15;i=i+2)
    {
#pragma HLS unroll//may be faster if split into two loops                                                                                                                          
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	{
	  temp=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
	}

    }

  for(int i=16;i<31;i=i+2)
    {
#pragma HLS unroll//may be faster if split into two loops                                                                                                                          
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{
	  temp=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
	}

    }


  ECAL_bitonic32(ECAL_Cluster_1_Deposits,ECAL_ClusterEta,ECAL_ClusterPhi);
}



void ECAL_bitonic8(ap_fixed<16,9> ECAL_Cluster_1_Deposits[32], uint16_t ECAL_ClusterEta[32], uint16_t ECAL_ClusterPhi[32])
{// sorting blocks of size 8                                                                                                                                                         
  int temp;
  // #pragma HLS dataflow                                                                                                                                                              
  for(int i=0;i<4;i++)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
	}
    } 

  for(int i=8;i<12;i++)
	{
    #pragma HLS unroll
	  if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+4])
	    {
	      temp=ECAL_Cluster_1_Deposits[i+4];
	      ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	      ECAL_Cluster_1_Deposits[i]=temp;
	      temp=ECAL_ClusterEta[i];
	      ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	      ECAL_ClusterEta[i+4]=temp;
	      temp=ECAL_ClusterPhi[i];
	      ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	      ECAL_ClusterPhi[i+4]=temp;
	    }
	}


  for(int i=16;i<20;i++)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
	}
    }
  for(int i=24;i<28;i++)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+4];
	  ECAL_ClusterEta[i+4]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+4];
	  ECAL_ClusterPhi[i+4]=temp;
	}
    }


  for(int i=0;i<5;i=i+4)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=temp;
	  temp=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=temp;
	}
      if(ECAL_Cluster_1_Deposits[i+1]<ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
          temp=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=ECAL_ClusterEta[i+3];
	  ECAL_ClusterEta[i+3]=temp;
	  temp=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=ECAL_ClusterPhi[i+3];
	  ECAL_ClusterPhi[i+3]=temp;
	}
    }

  for(int i=8;i<13;i=i+4)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=temp;
	  temp=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=temp;
	}

      if(ECAL_Cluster_1_Deposits[i+1]>ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=ECAL_ClusterEta[i+3];
	  ECAL_ClusterEta[i+3]=temp;
	  temp=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=ECAL_ClusterPhi[i+3];
	  ECAL_ClusterPhi[i+3]=temp;
	}
    }

  for(int i=16;i<21;i=i+4)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=temp;
	  temp=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=temp;
	}
      if(ECAL_Cluster_1_Deposits[i+1]<ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=ECAL_ClusterEta[i+3];
	  ECAL_ClusterEta[i+3]=temp;
	  temp=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=ECAL_ClusterPhi[i+3];
	  ECAL_ClusterPhi[i+3]=temp;
	}
    }

  for(int i=24;i<29;i=i+4)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=temp;
	  temp=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=temp;
	}

      if(ECAL_Cluster_1_Deposits[i+1]>ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=ECAL_ClusterEta[i+3];
	  ECAL_ClusterEta[i+3]=temp;
	  temp=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=ECAL_ClusterPhi[i+3];
	  ECAL_ClusterPhi[i+3]=temp;
	}

    }

  for(int i=0;i<7;i=i+2)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	{
	  temp=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_ClusterEta[i];
          ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
          ECAL_ClusterEta[i+1]=temp;
          temp=ECAL_ClusterPhi[i];
          ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
          ECAL_ClusterPhi[i+1]=temp;
	}
    }
  for(int i=8;i<15;i=i+2)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{
	  temp=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_ClusterEta[i];
          ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
          ECAL_ClusterEta[i+1]=temp;
          temp=ECAL_ClusterPhi[i];
          ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
          ECAL_ClusterPhi[i+1]=temp;
	}
    }

  for(int i=16;i<23;i=i+2)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	{
	  temp=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_ClusterEta[i];
          ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
          ECAL_ClusterEta[i+1]=temp;
          temp=ECAL_ClusterPhi[i];
          ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
          ECAL_ClusterPhi[i+1]=temp;
	}
    }
  for(int i=24;i<31;i=i+2)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{
	  temp=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_ClusterEta[i];
          ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
          ECAL_ClusterEta[i+1]=temp;
          temp=ECAL_ClusterPhi[i];
          ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
          ECAL_ClusterPhi[i+1]=temp;
	}
    }

  ECAL_bitonic16(ECAL_Cluster_1_Deposits,ECAL_ClusterEta,ECAL_ClusterPhi);
}
void ECAL_bitonic4(ap_fixed<16,9> ECAL_Cluster_1_Deposits[32], uint16_t ECAL_ClusterEta[32], uint16_t ECAL_ClusterPhi[32])
{
  int temp;
  // #pragma HLS dataflow                                                                                                                                                              
  // comparators in blocks of 4                                                                                                                                                        
  for(int i=0;i<2;i++)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=temp;
	}
    }
  for(int i=4;i<6;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=temp;
	}
    }
  for(int i=8;i<10;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=temp;
	}
    }
  for(int i=12;i<14;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=temp;
	}
    }
  for(int i=16;i<18;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=temp;
	}
    }

  for(int i=20;i<22;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=temp;
	}
    }
  for(int i=24;i<26;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=temp;
	}
    }
  for(int i=28;i<30;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+2];
	  ECAL_ClusterEta[i+2]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+2];
	  ECAL_ClusterPhi[i+2]=temp;
	}
    }

  for(int i=0;i<3;i=i+2)
	 {
  #pragma HLS unroll
	   if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	     {temp=ECAL_Cluster_1_Deposits[i];
	       ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	       ECAL_Cluster_1_Deposits[i+1]=temp;
	       temp=ECAL_ClusterEta[i];
	       ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	       ECAL_ClusterEta[i+1]=temp;
	       temp=ECAL_ClusterPhi[i];
	       ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	       ECAL_ClusterPhi[i+1]=temp;
	     }
	 }
  for(int i=4;i<7;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
	}
    }


  for(int i=8;i<11;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
	}
    }

  for(int i=12;i<15;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
	}
    }
  for(int i=16;i<19;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
	}
    }


  for(int i=20;i<23;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
	}
    }



  for(int i=24;i<27;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
	}
    }
  for(int i=28;i<31;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_ClusterEta[i];
	  ECAL_ClusterEta[i]=ECAL_ClusterEta[i+1];
	  ECAL_ClusterEta[i+1]=temp;
	  temp=ECAL_ClusterPhi[i];
	  ECAL_ClusterPhi[i]=ECAL_ClusterPhi[i+1];
	  ECAL_ClusterPhi[i+1]=temp;
	}
    }

  ECAL_bitonic8(ECAL_Cluster_1_Deposits,ECAL_ClusterEta,ECAL_ClusterPhi);

}

void ECAL_bitonic_1_16(ap_fixed<16,9> ECAL_Cluster_1_Deposits[16], uint16_t ECAL_Cluster_1_Eta[16], uint16_t ECAL_Cluster_1_Phi[16])
{// sorting blocks of size 16                                                                                                                                                        
  int temp;
  // #pragma HLS dataflow                                                                                                                                                              
  for(int i=0;i<8;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+8])
	{
	  temp=ECAL_Cluster_1_Deposits[i+8];
	  ECAL_Cluster_1_Deposits[i+8]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+8];
	  ECAL_Cluster_1_Eta[i+8]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+8];
	  ECAL_Cluster_1_Phi[i+8]=temp;
	}

    }


  for(int i=0;i<4;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+4];
	  ECAL_Cluster_1_Eta[i+4]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+4];
	  ECAL_Cluster_1_Phi[i+4]=temp;
	}
    }


  for(int i=8;i<12;i++)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+4];
	  ECAL_Cluster_1_Eta[i+4]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+4];
	  ECAL_Cluster_1_Phi[i+4]=temp;
	}
    }


  for(int i=0;i<13;i=i+4)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
          ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+2];
          ECAL_Cluster_1_Eta[i+2]=temp;
          temp=ECAL_Cluster_1_Phi[i];
          ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+2];
          ECAL_Cluster_1_Phi[i+2]=temp;
	}

      if(ECAL_Cluster_1_Deposits[i+1]<ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_Cluster_1_Eta[i+1];
	  ECAL_Cluster_1_Eta[i+1]=ECAL_Cluster_1_Eta[i+3];
	  ECAL_Cluster_1_Eta[i+3]=temp;
	  temp=ECAL_Cluster_1_Phi[i+1];
	  ECAL_Cluster_1_Phi[i+1]=ECAL_Cluster_1_Phi[i+3];
	  ECAL_Cluster_1_Phi[i+3]=temp;
	}
    }


  for(int i=0;i<15;i=i+2)
       {
#pragma HLS unroll//may be faster if split into two loops                                                                                                                          
	 if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	   {
	     temp=ECAL_Cluster_1_Deposits[i+1];
	     ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
	     ECAL_Cluster_1_Deposits[i]=temp;
	     temp=ECAL_Cluster_1_Eta[i];
	     ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+1];
	     ECAL_Cluster_1_Eta[i+1]=temp;
	     temp=ECAL_Cluster_1_Phi[i];
	     ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+1];
	     ECAL_Cluster_1_Phi[i+1]=temp;
	   }

       }


}



void ECAL_bitonic_1_8(ap_fixed<16,9> ECAL_Cluster_1_Deposits[16], uint16_t ECAL_Cluster_1_Eta[16], uint16_t ECAL_Cluster_1_Phi[16])
{// sorting blocks of size 8                                                                                                                                                         
  int temp;
  // #pragma HLS dataflow                                                                                                                                                              
  for(int i=0;i<4;i++)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+4];
	  ECAL_Cluster_1_Eta[i+4]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+4];
	  ECAL_Cluster_1_Phi[i+4]=temp;
	}
    }
  for(int i=8;i<12;i++)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+4])
	{
	  temp=ECAL_Cluster_1_Deposits[i+4];
	  ECAL_Cluster_1_Deposits[i+4]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+4];
	  ECAL_Cluster_1_Eta[i+4]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+4];
	  ECAL_Cluster_1_Phi[i+4]=temp;
	}
    }


  for(int i=0;i<5;i=i+4)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_Cluster_1_Eta[i+2];
	  ECAL_Cluster_1_Eta[i+2]=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=temp;
	  temp=ECAL_Cluster_1_Phi[i+2];
	  ECAL_Cluster_1_Phi[i+2]=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=temp;
	}
      if(ECAL_Cluster_1_Deposits[i+1]<ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
          temp=ECAL_Cluster_1_Eta[i+1];
	  ECAL_Cluster_1_Eta[i+1]=ECAL_Cluster_1_Eta[i+3];
	  ECAL_Cluster_1_Eta[i+3]=temp;
	  temp=ECAL_Cluster_1_Phi[i+1];
	  ECAL_Cluster_1_Phi[i+1]=ECAL_Cluster_1_Phi[i+3];
	  ECAL_Cluster_1_Phi[i+3]=temp;
	}
    }



  for(int i=8;i<13;i=i+4)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{
	  temp=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
	  temp=ECAL_Cluster_1_Eta[i+2];
	  ECAL_Cluster_1_Eta[i+2]=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=temp;
	  temp=ECAL_Cluster_1_Phi[i+2];
	  ECAL_Cluster_1_Phi[i+2]=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=temp;
	}
      if(ECAL_Cluster_1_Deposits[i+1]>ECAL_Cluster_1_Deposits[i+3])
	{
	  temp=ECAL_Cluster_1_Deposits[i+3];
	  ECAL_Cluster_1_Deposits[i+3]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_Cluster_1_Eta[i+1];
	  ECAL_Cluster_1_Eta[i+1]=ECAL_Cluster_1_Eta[i+3];
	  ECAL_Cluster_1_Eta[i+3]=temp;
	  temp=ECAL_Cluster_1_Phi[i+1];
	  ECAL_Cluster_1_Phi[i+1]=ECAL_Cluster_1_Phi[i+3];
	  ECAL_Cluster_1_Phi[i+3]=temp;
	}
    }


  for(int i=0;i<7;i=i+2)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	{
	  temp=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_Cluster_1_Eta[i];
          ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+1];
          ECAL_Cluster_1_Eta[i+1]=temp;
          temp=ECAL_Cluster_1_Phi[i];
          ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+1];
          ECAL_Cluster_1_Phi[i+1]=temp;
	}
    }
  for(int i=8;i<15;i=i+2)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{
	  temp=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=temp;
          temp=ECAL_Cluster_1_Eta[i];
          ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+1];
          ECAL_Cluster_1_Eta[i+1]=temp;
          temp=ECAL_Cluster_1_Phi[i];
          ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+1];
          ECAL_Cluster_1_Phi[i+1]=temp;
	}
    }
  ECAL_bitonic_1_16(ECAL_Cluster_1_Deposits,ECAL_Cluster_1_Eta,ECAL_Cluster_1_Phi);
}




void ECAL_bitonic_1_4(ap_fixed<16,9> ECAL_Cluster_1_Deposits[16], uint16_t ECAL_Cluster_1_Eta[16], uint16_t ECAL_Cluster_1_Phi[16])
{
  int temp;
  // #pragma HLS dataflow                                                                                                                                                              
  // comparators in blocks of 4                                                                                                                                                        
  for(int i=0;i<2;i++)
    {
    #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+2];
	  ECAL_Cluster_1_Eta[i+2]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+2];
	  ECAL_Cluster_1_Phi[i+2]=temp;
	}
    }
  for(int i=4;i<6;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+2];
	  ECAL_Cluster_1_Eta[i+2]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+2];
	  ECAL_Cluster_1_Phi[i+2]=temp;
	}
    }
  for(int i=8;i<10;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+2];
	  ECAL_Cluster_1_Eta[i+2]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+2];
	  ECAL_Cluster_1_Phi[i+2]=temp;
	}
    }


  for(int i=12;i<14;i++)
    {
#pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+2])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+2];
	  ECAL_Cluster_1_Deposits[i+2]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+2];
	  ECAL_Cluster_1_Eta[i+2]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+2];
	  ECAL_Cluster_1_Phi[i+2]=temp;
	}
    }

  for(int i=0;i<3;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+1];
	  ECAL_Cluster_1_Eta[i+1]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+1];
	  ECAL_Cluster_1_Phi[i+1]=temp;
	}
    }


  for(int i=4;i<7;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+1];
	  ECAL_Cluster_1_Eta[i+1]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+1];
	  ECAL_Cluster_1_Phi[i+1]=temp;
	}
    }

  for(int i=8;i<11;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]<ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+1];
	  ECAL_Cluster_1_Eta[i+1]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+1];
	  ECAL_Cluster_1_Phi[i+1]=temp;
	}
    }
  for(int i=12;i<15;i=i+2)
    {
  #pragma HLS unroll
      if(ECAL_Cluster_1_Deposits[i]>ECAL_Cluster_1_Deposits[i+1])
	{temp=ECAL_Cluster_1_Deposits[i];
	  ECAL_Cluster_1_Deposits[i]=ECAL_Cluster_1_Deposits[i+1];
	  ECAL_Cluster_1_Deposits[i+1]=temp;
	  temp=ECAL_Cluster_1_Eta[i];
	  ECAL_Cluster_1_Eta[i]=ECAL_Cluster_1_Eta[i+1];
	  ECAL_Cluster_1_Eta[i+1]=temp;
	  temp=ECAL_Cluster_1_Phi[i];
	  ECAL_Cluster_1_Phi[i]=ECAL_Cluster_1_Phi[i+1];
	  ECAL_Cluster_1_Phi[i+1]=temp;
	}
    }

  ECAL_bitonic_1_8(ECAL_Cluster_1_Deposits,ECAL_Cluster_1_Eta,ECAL_Cluster_1_Phi);

}



uint16_t getPeakBinOf5(ap_fixed<16,9> et[5], ap_fixed<16,9> etSum) {
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=et complete dim=0
  ap_fixed<16,9> iEtSum = 
    (et[0] >> 1)                +  // 0.5xet[0]
    (et[1] >> 1) + et[1]        +  // 1.5xet[1]
    (et[2] >> 1) + (et[2] << 1) +  // 2.5xet[2]
    (et[3] << 2) - (et[3] >> 1) +  // 3.5xet[3]
    (et[4] << 2) + (et[4] >> 1) ;  // 4.5xet[4]
  uint16_t iAve = 0xBEEF;
  if(     iEtSum <= etSum) iAve = 0;
  else if(iEtSum <= (etSum << 1)) iAve = 1;
  else if(iEtSum <= (etSum + (etSum << 1))) iAve = 2;
  else if(iEtSum <= (etSum << 2)) iAve = 3;
  else iAve = 4;
  return iAve;
}



bool getECAL_Clustersin3x4Region(ap_fixed<16,9> crystals_tower[3][4][5][5],
			    uint16_t peakEta1[3][4],
			    uint16_t peakPhi1[3][4],
				ap_fixed<16,9> towerET1[3][4],
				ap_fixed<16,9> ECAL_ClusterET1[3][4],
				ap_fixed<16,9> SortedECAL_ClusterET[5],
			    uint16_t SortedPeakEta[5],
			    uint16_t SortedPeakPhi[5]) {
  

#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=crystals_tower complete dim=0
#pragma HLS ARRAY_PARTITION variable=peakEta1 complete dim=0
#pragma HLS ARRAY_PARTITION variable=peakPhi1 complete dim=0
#pragma HLS ARRAY_PARTITION variable=towerET1 complete dim=0
#pragma HLS ARRAY_PARTITION variable=ECAL_ClusterET1 complete dim=0
#pragma HLS ARRAY_PARTITION variable=SortedECAL_ClusterET complete dim=0
#pragma HLS ARRAY_PARTITION variable=SortedPeakEta complete dim=0
#pragma HLS ARRAY_PARTITION variable=SortedPeakPhi complete dim=0

  uint16_t peakEta2[16];
  uint16_t peakPhi2[16];
  ap_fixed<16,9> ECAL_ClusterET2[16];

#pragma HLS ARRAY_PARTITION variable=peakEta2 complete dim=0
#pragma HLS ARRAY_PARTITION variable=peakPhi2 complete dim=0
#pragma HLS ARRAY_PARTITION variable=ECAL_ClusterET2 complete dim=0

// for (int i=0;i<17;i++)
// {
//   for (int j=0;j<4;j++)
//   {
//     towerET_cal[i][j]=0;
//   }
// }
  for(int i=0;i<16;i++)
    {
#pragma HLS UNROLL      
      peakEta2[i]=0;
      peakPhi2[i]=0;
      ECAL_ClusterET2[i]=0;

    }

  int i=0;
  for(int tPhi = 0; tPhi < 4; tPhi++) {
#pragma HLS UNROLL
    for(int tEta = 0; tEta < 3; tEta++) {
#pragma HLS UNROLL
      getECAL_ClustersInTower(crystals_tower[tEta][tPhi], 
			 &peakEta1[tEta][tPhi],
			 &peakPhi1[tEta][tPhi],
			 &towerET1[tEta][tPhi],
			 &ECAL_ClusterET1[tEta][tPhi]);
			 
      std::cout<<"tower eta: " << tEta<<" tower phi: "<<tPhi<<" peakEta1: "<<peakEta1[tEta][tPhi]<<" peakPhi1: "<<peakPhi1[tEta][tPhi]<<" ECAL_ClusterET: "<<ECAL_ClusterET1[tEta][tPhi]<<std::endl;
      peakEta2[i]= peakEta1[tEta][tPhi];
      peakPhi2[i]= peakPhi1[tEta][tPhi];

      //peakEta2[i]= tEta;                                                                                                                                     
      //peakPhi2[i]= tPhi;  
      ECAL_ClusterET2[i] = ECAL_ClusterET1[tEta][tPhi];
      
      i++;
    }
  }


  
  for(int i=13;i<16;i++)
    {
#pragma HLS UNROLL
      peakEta2[i]=0;
      peakPhi2[i]=0;
      ECAL_ClusterET2[i]=0;

    }

  
  uint16_t xx;
  
  for(int i=0;i<16;i=i+4)
    {
#pragma HLS unroll
      if(ECAL_ClusterET2[i]<ECAL_ClusterET2[i+1])
	{xx=ECAL_ClusterET2[i+1];
	  ECAL_ClusterET2[i+1]=ECAL_ClusterET2[i];
	  ECAL_ClusterET2[i]=xx;
	  xx=peakEta2[i];
	  peakEta2[i]=peakEta2[i+1];
	  peakEta2[i+1]=xx;
	  xx=peakPhi2[i];
	  peakPhi2[i]=peakPhi2[i+1];
	  peakPhi2[i+1]=xx;
	}

      if(ECAL_ClusterET2[i+2]>ECAL_ClusterET2[i+3])
	{xx=ECAL_ClusterET2[i+3];
	  ECAL_ClusterET2[i+3]=ECAL_ClusterET2[i+2];
	  ECAL_ClusterET2[i+2]=xx;
	  xx=peakEta2[i+2];
	  peakEta2[i+2]=peakEta2[i+3];
	  peakEta2[i+3]=xx;
	  xx=peakPhi2[i+2];
	  peakPhi2[i+2]=peakPhi2[i+3];
	  peakPhi2[i+3]=xx;

	}
    }


  // passing control to second level of quaternary comparators                                                                                                                     
  ECAL_bitonic_1_4(ECAL_ClusterET2,peakEta2,peakPhi2);

  for(int i=0;i<5;i++)
    {
      SortedECAL_ClusterET[i] = ECAL_ClusterET2[i];
      SortedPeakEta[i]= peakEta2[i];
      SortedPeakPhi[i]= peakPhi2[i];
    }
  

  

}

bool getECAL_ClustersInTower(ap_fixed<16,9> crystals[NCrystalsPerEtaPhi][NCrystalsPerEtaPhi],
                        uint16_t *peakEta,
                        uint16_t *peakPhi,
                        ap_fixed<16,9> *towerET,
                        ap_fixed<16,9> *ECAL_ClusterET) {
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=crystals complete dim=0
  ap_fixed<16,9> phiStripSum[NCrystalsPerEtaPhi];
#pragma HLS ARRAY_PARTITION variable=phiStripSum complete dim=0
  for(int phi = 0; phi < NCrystalsPerEtaPhi; phi++) {
#pragma HLS UNROLL
    phiStripSum[phi] = 0;
    for(int eta = 0; eta < NCrystalsPerEtaPhi; eta++) {
#pragma HLS UNROLL
      phiStripSum[phi] += crystals[eta][phi];
    }
  }
  ap_fixed<16,9> etaStripSum[NCrystalsPerEtaPhi];
#pragma HLS ARRAY_PARTITION variable=etaStripSum complete dim=0
  for(int eta = 0; eta < NCrystalsPerEtaPhi; eta++) {
#pragma HLS UNROLL
    etaStripSum[eta] = 0;
    for(int phi = 0; phi < NCrystalsPerEtaPhi; phi++) {
#pragma HLS UNROLL
      etaStripSum[eta] += crystals[eta][phi];
    }
  }
  // Large ECAL_Cluster ET is the ET of the full tower
  *towerET = 0;
  for(int phi = 0; phi < NCrystalsPerEtaPhi; phi++) {
#pragma HLS UNROLL
    *towerET += phiStripSum[phi];
  }
  *peakEta = getPeakBinOf5(etaStripSum, *towerET);
  *peakPhi = getPeakBinOf5(phiStripSum, *towerET);
  // Small ECAL_Cluster ET is just the 3x5 around the peak
  *ECAL_ClusterET = 0;
  for(int dEta = -1; dEta <= 1; dEta++) {
#pragma HLS UNROLL
      int eta = *peakEta + dEta;
        if(eta >= 0 && eta < NCrystalsPerEtaPhi) {
        	 *ECAL_ClusterET += etaStripSum[eta];
      }
  }
////subECAL_Cluster 2X5L
//  uint16_t ECAL_ClusterETL ;
//  ECAL_ClusterETL =0;
//	for(int dEtaL = -1; dEtaL <= 0; dEtaL++) {
//#pragma HLS UNROLL
//	  int eta = *peakEta + dEtaL;
//	  if(eta >= 0 && eta < NCrystalsPerEtaPhi){
//	    ECAL_ClusterETL += etaStripSum[eta];
//	  }
//	}
//	//subECAL_Cluster 2X5R
//	uint16_t ECAL_ClusterETR ;
//	ECAL_ClusterETR =0;
//	for(int dEtaR = 0; dEtaR <= 1; dEtaR++) {
//#pragma HLS UNROLL
//	  int eta = *peakEta + dEtaR;
//	  if(eta >= 0 && eta < NCrystalsPerEtaPhi){
//	    ECAL_ClusterETR += etaStripSum[eta];
//	  }
//	}
//	//ECAL_Cluster2X5 is equal to max of 2X5L or 2X5R
//	*ECAL_Clusteret2x5 = biggerLR(ECAL_ClusterETL, ECAL_ClusterETR);
//	
	return true;
}

uint16_t biggerLR(ap_fixed<16,9> ECAL_ClusterETL, ap_fixed<16,9> ECAL_ClusterETR){


//
#pragma HLS PIPELINE II=6

  uint16_t ECAL_Clusterf = 0;
  
  if(ECAL_ClusterETL>ECAL_ClusterETR)
    ECAL_Clusterf = ECAL_ClusterETL;
  
  else
    ECAL_Clusterf = ECAL_ClusterETR;
  
  return ECAL_Clusterf;
}




bool mergeECAL_Clusters(uint16_t ieta1, uint16_t iphi1, ap_fixed<16,9> itet1, ap_fixed<16,9> icet1,
                   uint16_t ieta2, uint16_t iphi2, ap_fixed<16,9> itet2, ap_fixed<16,9> icet2,
                   uint16_t *eta1, uint16_t *phi1, ap_fixed<16,9> *tet1, ap_fixed<16,9> *cet1,
                   uint16_t *eta2, uint16_t *phi2, ap_fixed<16,9> *tet2, ap_fixed<16,9> *cet2) {
  // Check that the ECAL_Clusters are neighbors in eta or phi
  if((ieta1 == ieta2) || (iphi1 == iphi2)) {
    if(icet1 > icet2) {
      // Merge 2 in to 1, and set 2 to remnant energy centered in tower
      *eta1 = ieta1;
      *phi1 = iphi1;
      *cet1 = icet1 + icet2;
      *tet1 = itet1 + icet2;
      *eta2 = 2;
      *phi2 = 2;
      *cet2 = 0;
      *tet2 = itet2 - icet2;
    }
    else {
      // Merge 1 in to 2, and set 1 to remnant energy centered in tower
      *eta2 = ieta2;
      *phi2 = iphi2;
      *cet2 = icet2 + icet1;
      *tet2 = itet2 + icet1;
      *eta1 = 2;
      *phi1 = 2;
      *cet1 = 0;
      *tet1 = itet1 - icet1;
    }
  }
  else {
    *eta1 = ieta1;
    *phi1 = iphi1;
    *cet1 = icet1;
    *tet1 = itet1;
    *eta2 = ieta2;
    *phi2 = iphi2;
    *cet2 = icet2;
    *tet2 = itet2;
  }
  return true;
}

bool getECAL_ClustersInCard(ap_fixed<16,9> uncal_crystals[NCaloLayer1Eta][NCaloLayer1Phi][NCrystalsPerEtaPhi][NCrystalsPerEtaPhi],
                       uint16_t peakEta[NCaloLayer1Eta][NCaloLayer1Phi],
                       uint16_t peakPhi[NCaloLayer1Eta][NCaloLayer1Phi],
                       ap_fixed<16,9> towerET[NCaloLayer1Eta][NCaloLayer1Phi],
                       ap_fixed<16,9> ECAL_ClusterET[NCaloLayer1Eta][NCaloLayer1Phi],
		       ap_fixed<16,9> SortedECAL_Cluster_ET[30],
		       uint16_t SortedPeak_Eta[30],
		       ap_fixed<16,9> HCAL_towerET_uncal[17][4],
		       uint16_t SortedPeak_Phi[30]) {
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=uncal_crystals complete dim=0
#pragma HLS ARRAY_PARTITION variable=peakEta complete dim=0
#pragma HLS ARRAY_PARTITION variable=peakPhi complete dim=0
#pragma HLS ARRAY_PARTITION variable=towerET complete dim=0
#pragma HLS ARRAY_PARTITION variable=ECAL_ClusterET complete dim=0
#pragma HLS ARRAY_PARTITION variable=SortedECAL_Cluster_ET complete dim=0
#pragma HLS ARRAY_PARTITION variable=SortedPeak_Eta complete dim=0
#pragma HLS ARRAY_PARTITION variable=SortedPeak_Phi complete dim=0

ap_fixed<16,9> crystals[NCaloLayer1Eta][NCaloLayer1Phi][NCrystalsPerEtaPhi][NCrystalsPerEtaPhi];
#pragma HLS ARRAY_PARTITION variable=crystals complete dim=0
for (int i=0;i<17;i++)
{
  for (int j=0;j<4;j++)
  {
  	for (int k=0;k<5;k++)
  	{
  		for(int l=0;l<5;l++)
  		{
  			crystals[i][j][k][l]=0;
  		}
  	}
    
  }
}
//ECAL_Calibration
ap_fixed<16,9>   towerET_cal [17][4];

#pragma HLS ARRAY_PARTITION variable=towerET complete dim=0
for (int i=0;i<17;i++)
{
  #pragma HLS UNROLL
  for (int j=0;j<4;j++)
  {
    #pragma HLS UNROLL
    towerET_cal[i][j]=0;
  }
}
for (int i=0;i<17;i++)
{
  #pragma HLS UNROLL
  for (int j=0;j<4;j++)
  {
    #pragma HLS UNROLL
    for (int k=0;k<5;k++)
    {
      #pragma HLS UNROLL
      for(int l=0;l<5;l++)
      {
        #pragma HLS UNROLL
        towerET_cal[i][j]=towerET_cal[i][j]+uncal_crystals[i][j][k][l];
      }
    }
    towerET_cal[i][j]=towerET_cal[i][j]+HCAL_towerET_uncal[i][j];
  }
}
 for (int j=0;j<17;j++)
  {
  #pragma HLS UNROLL
      for (int k=0;k<4;k++)
      {
      #pragma HLS UNROLL
        if(towerET_cal[j][k]<ECAL_Calib_ET_Bins[0])
         {
          towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[0][j];
          
         }
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[0])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[1]))
         {
              towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[1][j];

         } 
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[1])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[2]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[2][j];
         }
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[2])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[3]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[3][j];
         } 
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[3])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[4]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[4][j];
         }
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[4])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[5]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[5][j];
         } 
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[5])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[6]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[6][j];
         }
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[6])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[7]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[7][j];
         } 
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[7])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[8]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[8][j];
         }
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[8])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[9]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[9][j];
         } 
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[9])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[10]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[10][j];
         }
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[10])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[11]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[11][j];
         } 
        else if ((towerET_cal[j][k]>ECAL_Calib_ET_Bins[11])&&(towerET_cal[j][k]<ECAL_Calib_ET_Bins[12]))
         {
        	towerET_cal[j][k]=towerET_cal[j][k]*ECAL_Calib_LUT[12][j];
         }

      }
  }

  uint16_t preMergePeakEta[NCaloLayer1Eta][NCaloLayer1Phi];
  uint16_t preMergePeakPhi[NCaloLayer1Eta][NCaloLayer1Phi];
  ap_fixed<16,9> preMergeTowerET[NCaloLayer1Eta][NCaloLayer1Phi];
  ap_fixed<16,9> preMergeECAL_ClusterET[NCaloLayer1Eta][NCaloLayer1Phi];
  ap_fixed<16,9> crystals_tower[3][4][5][5];
#pragma HLS ARRAY_PARTITION variable=crystals_tower complete dim=0
  ap_fixed<16,9> sortedECAL_Clusteret[5];

#pragma HLS ARRAY_PARTITION variable=sortedECAL_Clusteret complete dim=0
  uint16_t sortedpeaketa[5];
#pragma HLS ARRAY_PARTITION variable=sortedpeaketa complete dim=0
  uint16_t sortedpeakphi[5];
#pragma HLS ARRAY_PARTITION variable=sortedpeakphi complete dim=0
  ap_fixed<16,9> SortedECAL_Cluster_ET1[30];
  uint16_t SortedPeak_Eta1[30];
  uint16_t SortedPeak_Phi1[30];


#pragma HLS ARRAY_PARTITION variable=preMergePeakEta complete dim=0
#pragma HLS ARRAY_PARTITION variable=preMergePeakPhi complete dim=0
#pragma HLS ARRAY_PARTITION variable=preMergeTowerET complete dim=0
#pragma HLS ARRAY_PARTITION variable=preMergeECAL_ClusterET complete dim=0




#pragma HLS ARRAY_PARTITION variable=SortedECAL_Cluster_ET1 complete dim=0
#pragma HLS ARRAY_PARTITION variable=SortedPeak_Eta1 complete dim=0
#pragma HLS ARRAY_PARTITION variable=SortedPeak_Phi1 complete dim=0

  for(int i=0; i<5; i++)
    {
      sortedECAL_Clusteret[i]=0;
      sortedpeaketa[i]=0;
      sortedpeakphi[i]=0;
      
    }


  for(int i=0; i<30; i++)
    {
      SortedECAL_Cluster_ET1[i]=0;
      SortedPeak_Eta1[i]=0;
      SortedPeak_Phi1[i]=0;
      
    }


  for(int i=0; i<30; i++)
    {
      SortedECAL_Cluster_ET[i]=0;
      SortedPeak_Eta[i]=0;
      SortedPeak_Phi[i]=0;
      
    }
  

  int a=0;
  for(int i =0; i<15; i+=3) {
#pragma HLS UNROLL
    for(int tEta = 0; tEta < 3; tEta++) {
#pragma HLS UNROLL
      for(int tPhi = 0; tPhi < NCaloLayer1Phi; tPhi++) {
#pragma HLS UNROLL
	preMergePeakEta[tEta][tPhi] = 999;
	preMergePeakPhi[tEta][tPhi] = 999;
	preMergeTowerET[tEta][tPhi] = 0;
	preMergeECAL_ClusterET[tEta][tPhi] = 0;
	for( int ceta =0; ceta<5; ceta++) {
#pragma HLS UNROLL
	  for( int cphi =0; cphi<5; cphi++) {
#pragma HLS UNROLL
	crystals_tower[tEta][tPhi][ceta][cphi] = crystals[i+tEta][tPhi][ceta][cphi];
	  }
	  
	}
      }
    }
    getECAL_Clustersin3x4Region(crystals_tower, preMergePeakEta,
			   preMergePeakPhi,
			   preMergeTowerET,
			   preMergeECAL_ClusterET,
			   sortedECAL_Clusteret,
			   sortedpeaketa,
			   sortedpeakphi);
    

    SortedECAL_Cluster_ET1[a+0] = sortedECAL_Clusteret[0];
    SortedECAL_Cluster_ET1[a+1] = sortedECAL_Clusteret[1];
    SortedECAL_Cluster_ET1[a+2] = sortedECAL_Clusteret[2];
    SortedECAL_Cluster_ET1[a+3] = sortedECAL_Clusteret[3];
    SortedECAL_Cluster_ET1[a+4] = sortedECAL_Clusteret[4];

    
    SortedPeak_Eta1[a+0] = sortedpeaketa[0];
    SortedPeak_Eta1[a+1] = sortedpeaketa[1];
    SortedPeak_Eta1[a+2] = sortedpeaketa[2];
    SortedPeak_Eta1[a+3] = sortedpeaketa[3];
    SortedPeak_Eta1[a+4] = sortedpeaketa[4];
    
    
    SortedPeak_Phi1[a+0] = sortedpeakphi[0];
    SortedPeak_Phi1[a+1] = sortedpeakphi[1];
    SortedPeak_Phi1[a+2] = sortedpeakphi[2];
    SortedPeak_Phi1[a+3] = sortedpeakphi[3];
    SortedPeak_Phi1[a+4] = sortedpeakphi[4];

    //    for(int i=0;i<5; i++)
    //{std::cout<<"a: "<<a<<"i: "<<i<<"SortedPeak_Eta[a+0]: "<<SortedPeak_Eta[a+i]<<"SortedPeak_Phi[a+0]: "<<SortedPeak_Phi[a+i]<<"peak eta: "<<preMergePeakEta[SortedPeak_Eta[a+i]][SortedPeak_Phi[a+i]]<<"Sorted_et: "<<SortedECAL_Cluster_ET[a+i]<<"Using clsuter et: "<<preMergeECAL_ClusterET[SortedPeak_Eta[a+i]][SortedPeak_Phi[a+i]]<<std::endl;}


    a= a+5;

          
  }
  
  for(int tEta = 0; tEta < 2; tEta++) {
#pragma HLS UNROLL
    for(int tPhi = 0; tPhi < NCaloLayer1Phi; tPhi++) {
#pragma HLS UNROLL
      for( int ceta =0; ceta<5; ceta++) {
#pragma HLS UNROLL
	for( int cphi =0; cphi<5; cphi++) {
#pragma HLS UNROLL
	  crystals_tower[tEta][tPhi][ceta][cphi] = crystals[tEta+15][tPhi][ceta][cphi];
	}

      }
    }
  }
  getECAL_Clustersin3x4Region(crystals_tower, preMergePeakEta,
			 preMergePeakPhi,
			 preMergeTowerET,
			 preMergeECAL_ClusterET,
			 sortedECAL_Clusteret,
			 sortedpeaketa,
			 sortedpeakphi);


  SortedECAL_Cluster_ET1[25+0] = sortedECAL_Clusteret[0];
  SortedECAL_Cluster_ET1[25+1] = sortedECAL_Clusteret[1];
  SortedECAL_Cluster_ET1[25+2] = sortedECAL_Clusteret[2];
  SortedECAL_Cluster_ET1[25+3] = sortedECAL_Clusteret[3];
  SortedECAL_Cluster_ET1[25+4] = sortedECAL_Clusteret[4];


  SortedPeak_Eta1[25+0] = sortedpeaketa[0];
  SortedPeak_Eta1[25+1] = sortedpeaketa[1];
  SortedPeak_Eta1[25+2] = sortedpeaketa[2];
  SortedPeak_Eta1[25+3] = sortedpeaketa[3];
  SortedPeak_Eta1[25+4] = sortedpeaketa[4];


  SortedPeak_Phi1[25+0] = sortedpeakphi[0];
  SortedPeak_Phi1[25+1] = sortedpeakphi[1];
  SortedPeak_Phi1[25+2] = sortedpeakphi[2];
  SortedPeak_Phi1[25+3] = sortedpeakphi[3];
  SortedPeak_Phi1[25+4] = sortedpeakphi[4];


  uint16_t peakEta3[32];
  uint16_t peakPhi3[32];
  ap_fixed<16,9> ECAL_ClusterET3[32];

#pragma HLS ARRAY_PARTITION variable=peakEta3 complete dim=0
#pragma HLS ARRAY_PARTITION variable=peakPhi3 complete dim=0
#pragma HLS ARRAY_PARTITION variable=ECAL_ClusterET3 complete dim=0
  
  for(int i=0;i<32;i++)
    {
#pragma HLS UNROLL
      peakEta3[i]=0;
      peakPhi3[i]=0;
      ECAL_ClusterET3[i]=0;

    }


  for(int i=0;i<30;i++)
    {
      ECAL_ClusterET3[i]= SortedECAL_Cluster_ET1[i];
      peakEta3[i]= SortedPeak_Eta1[i];
      peakPhi3[i]= SortedPeak_Phi1[i];
    }


  int xx=0;
  //first level of binary comparators                                                                                                                                                  
  for(int i=0;i<32;i=i+4)
    {
#pragma HLS unroll
      if(ECAL_ClusterET3[i]>ECAL_ClusterET3[i+1])
	{xx=ECAL_ClusterET3[i+1];
	  ECAL_ClusterET3[i+1]=ECAL_ClusterET3[i];
	  ECAL_ClusterET3[i]=xx;
	  xx=peakEta3[i];
	  peakEta3[i]=peakEta3[i+1];
	  peakEta3[i+1]=xx;
	  xx=peakPhi3[i];
	  peakPhi3[i]=peakPhi3[i+1];
	  peakPhi3[i+1]=xx;
	}


      if(ECAL_ClusterET3[i+2]<ECAL_ClusterET3[i+3])
	{xx=ECAL_ClusterET3[i+3];
	  ECAL_ClusterET3[i+3]=ECAL_ClusterET3[i+2];
	  ECAL_ClusterET3[i+2]=xx;
	  xx=peakEta3[i+2];
	  peakEta3[i+2]=peakEta3[i+3];
	  peakEta3[i+3]=xx;
	  xx=peakPhi3[i+2];
	  peakPhi3[i+2]=peakPhi3[i+3];
	  peakPhi3[i+3]=xx;

	}
    }


  ECAL_bitonic4(ECAL_ClusterET3,peakEta3,peakPhi3);


  for(int i=0;i<30;i++)
    {
      SortedECAL_Cluster_ET[i] = ECAL_ClusterET3[i];
      SortedPeak_Eta[i]= peakEta3[i];
      SortedPeak_Phi[i]= peakPhi3[i];

      std::cout<<"i: "<<i<<" SortedPeak_Eta[i] "<<SortedPeak_Eta[i]<<" SortedPeak_Phi[i]"<<SortedPeak_Phi[i]<<"  SortedECAL_Cluster_ET[i]"<< SortedECAL_Cluster_ET[i]<<std::endl;
    }

  
  // Merge neighboring split-ECAL_Clusters here
  for(int tEta = 0; tEta < NCaloLayer1Eta; tEta++) {
#pragma HLS UNROLL
    for(int tPhi = 0; tPhi < NCaloLayer1Phi; tPhi++) {
#pragma HLS UNROLL
      peakEta[tEta][tPhi] = preMergePeakEta[tEta][tPhi];
      peakPhi[tEta][tPhi] = preMergePeakPhi[tEta][tPhi];
      towerET[tEta][tPhi] = preMergeTowerET[tEta][tPhi];
      ECAL_ClusterET[tEta][tPhi] = preMergeECAL_ClusterET[tEta][tPhi];
      int nEta = -1;
      int nPhi = -1;
      if(preMergePeakEta[tEta][tPhi] == 0 && tEta != 0) nEta = tEta - 1;
      if(preMergePeakEta[tEta][tPhi] == NCaloLayer1Phi && tEta != 16) nEta = tEta + 1;
      if(preMergePeakPhi[tEta][tPhi] == 0 && tPhi != 0) nPhi = tPhi - 1;
      if(preMergePeakPhi[tEta][tPhi] == NCaloLayer1Phi && tPhi != 3) nPhi = tPhi + 1;
      //std::cout<<"Before merging tEta/tPhi/peakEta/peakPhi/"<<tEta<<"/"<<tPhi<<"/"<<peakEta[tEta][tPhi]<<"/"<<peakPhi[tEta][tPhi]<<endl;
      if(nEta >= 0 && nEta < NCaloLayer1Eta && nPhi >= 0 && nPhi < NCaloLayer1Phi) {
	if(!mergeECAL_Clusters(preMergePeakEta[tEta][tPhi],
			  preMergePeakPhi[tEta][tPhi],
			  preMergeTowerET[tEta][tPhi],
			  preMergeECAL_ClusterET[tEta][tPhi],
			  preMergePeakEta[nEta][nPhi],
			  preMergePeakPhi[nEta][nPhi],
			  preMergeTowerET[nEta][nPhi],
			  preMergeECAL_ClusterET[nEta][nPhi],
			  &peakEta[tEta][tPhi],
			  &peakPhi[tEta][tPhi],
			  &towerET[tEta][tPhi],
			  &ECAL_ClusterET[tEta][tPhi],
			  &peakEta[nEta][nPhi],
			  &peakPhi[nEta][nPhi],
			  &towerET[nEta][nPhi],
			  &ECAL_ClusterET[nEta][nPhi]))
			  return false;
	
      }
      
            
	
    }
  }
  
  
  return true;
}
void HCAL_bitonic_1_16( ap_fixed<16,9>   HCAL_Cluster_1_Deposits[16], uint16_t HCAL_Cluster_1_Eta[16], uint16_t HCAL_Cluster_1_Phi[16])
{// sorting blocks of size 16
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<8;i++)
  {
  #pragma HLS unroll
  if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+8])
    {
      temp=HCAL_Cluster_1_Deposits[i+8];
      HCAL_Cluster_1_Deposits[i+8]=HCAL_Cluster_1_Deposits[i];
      HCAL_Cluster_1_Deposits[i]=temp;
      temp=HCAL_Cluster_1_Eta[i];
        HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+8];
        HCAL_Cluster_1_Eta[i+8]=temp;
        temp=HCAL_Cluster_1_Phi[i];
        HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+8];
        HCAL_Cluster_1_Phi[i+8]=temp;
    }

    }

  
   for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+4])
    {
      temp=HCAL_Cluster_1_Deposits[i+4];
      HCAL_Cluster_1_Deposits[i+4]=HCAL_Cluster_1_Deposits[i];
      HCAL_Cluster_1_Deposits[i]=temp;
      temp=HCAL_Cluster_1_Eta[i];
        HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+4];
        HCAL_Cluster_1_Eta[i+4]=temp;
        temp=HCAL_Cluster_1_Phi[i];
        HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+4];
        HCAL_Cluster_1_Phi[i+4]=temp;
    }
    }
   for(int i=8;i<12;i++)
  {
  #pragma HLS unroll
  if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+4])
    {
      temp=HCAL_Cluster_1_Deposits[i+4];
      HCAL_Cluster_1_Deposits[i+4]=HCAL_Cluster_1_Deposits[i];
      HCAL_Cluster_1_Deposits[i]=temp;
      temp=HCAL_Cluster_1_Eta[i];
        HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+4];
        HCAL_Cluster_1_Eta[i+4]=temp;
        temp=HCAL_Cluster_1_Phi[i];
        HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+4];
        HCAL_Cluster_1_Phi[i+4]=temp;
    }
    }
  

  for(int i=0;i<13;i=i+4)
  {
  #pragma HLS unroll
  if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+2])
    {
      temp=HCAL_Cluster_1_Deposits[i+2];
      HCAL_Cluster_1_Deposits[i+2]=HCAL_Cluster_1_Deposits[i];
      HCAL_Cluster_1_Deposits[i]=temp;
      temp=HCAL_Cluster_1_Eta[i];
          HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+2];
          HCAL_Cluster_1_Eta[i+2]=temp;
          temp=HCAL_Cluster_1_Phi[i];
          HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+2];
          HCAL_Cluster_1_Phi[i+2]=temp;
    }

    if(HCAL_Cluster_1_Deposits[i+1]<HCAL_Cluster_1_Deposits[i+3])
    {
      temp=HCAL_Cluster_1_Deposits[i+3];
      HCAL_Cluster_1_Deposits[i+3]=HCAL_Cluster_1_Deposits[i+1];
      HCAL_Cluster_1_Deposits[i+1]=temp;
       temp=HCAL_Cluster_1_Eta[i+1];
              HCAL_Cluster_1_Eta[i+1]=HCAL_Cluster_1_Eta[i+3];
              HCAL_Cluster_1_Eta[i+3]=temp;
              temp=HCAL_Cluster_1_Phi[i+1];
              HCAL_Cluster_1_Phi[i+1]=HCAL_Cluster_1_Phi[i+3];
              HCAL_Cluster_1_Phi[i+3]=temp;
    }
    }
  
 
   

  for(int i=0;i<15;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+1])
    {
      temp=HCAL_Cluster_1_Deposits[i+1];
      HCAL_Cluster_1_Deposits[i+1]=HCAL_Cluster_1_Deposits[i];
      HCAL_Cluster_1_Deposits[i]=temp;
       temp=HCAL_Cluster_1_Eta[i];
              HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+1];
              HCAL_Cluster_1_Eta[i+1]=temp;
              temp=HCAL_Cluster_1_Phi[i];
              HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+1];
              HCAL_Cluster_1_Phi[i+1]=temp;
    }

    }
 


  }

void HCAL_bitonic_1_8( ap_fixed<16,9>   HCAL_Cluster_1_Deposits[16], uint16_t HCAL_Cluster_1_Eta[16], uint16_t HCAL_Cluster_1_Phi[16])
{// sorting blocks of size 8
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<4;i++)
  {
    #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+4])
      {
        temp=HCAL_Cluster_1_Deposits[i+4];
        HCAL_Cluster_1_Deposits[i+4]=HCAL_Cluster_1_Deposits[i];
        HCAL_Cluster_1_Deposits[i]=temp;
        temp=HCAL_Cluster_1_Eta[i];
        HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+4];
        HCAL_Cluster_1_Eta[i+4]=temp;
        temp=HCAL_Cluster_1_Phi[i];
        HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+4];
        HCAL_Cluster_1_Phi[i+4]=temp;
      }
  }
  for(int i=8;i<12;i++)
  {
    #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]>HCAL_Cluster_1_Deposits[i+4])
      {
        temp=HCAL_Cluster_1_Deposits[i+4];
        HCAL_Cluster_1_Deposits[i+4]=HCAL_Cluster_1_Deposits[i];
        HCAL_Cluster_1_Deposits[i]=temp;
        temp=HCAL_Cluster_1_Eta[i];
        HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+4];
        HCAL_Cluster_1_Eta[i+4]=temp;
        temp=HCAL_Cluster_1_Phi[i];
        HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+4];
        HCAL_Cluster_1_Phi[i+4]=temp;
      }
  }
 

  for(int i=0;i<5;i=i+4)
  {
    #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+2])
      {
        temp=HCAL_Cluster_1_Deposits[i+2];
        HCAL_Cluster_1_Deposits[i+2]=HCAL_Cluster_1_Deposits[i];
        HCAL_Cluster_1_Deposits[i]=temp;
        temp=HCAL_Cluster_1_Eta[i+2];
        HCAL_Cluster_1_Eta[i+2]=HCAL_Cluster_1_Eta[i];
        HCAL_Cluster_1_Eta[i]=temp;
        temp=HCAL_Cluster_1_Phi[i+2];
        HCAL_Cluster_1_Phi[i+2]=HCAL_Cluster_1_Phi[i];
        HCAL_Cluster_1_Phi[i]=temp;
      }
    if(HCAL_Cluster_1_Deposits[i+1]<HCAL_Cluster_1_Deposits[i+3])
      {
        temp=HCAL_Cluster_1_Deposits[i+3];
        HCAL_Cluster_1_Deposits[i+3]=HCAL_Cluster_1_Deposits[i+1];
        HCAL_Cluster_1_Deposits[i+1]=temp;
          temp=HCAL_Cluster_1_Eta[i+1];
        HCAL_Cluster_1_Eta[i+1]=HCAL_Cluster_1_Eta[i+3];
        HCAL_Cluster_1_Eta[i+3]=temp;
        temp=HCAL_Cluster_1_Phi[i+1];
        HCAL_Cluster_1_Phi[i+1]=HCAL_Cluster_1_Phi[i+3];
        HCAL_Cluster_1_Phi[i+3]=temp;
      }
  }
  for(int i=8;i<13;i=i+4)
  {
    #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]>HCAL_Cluster_1_Deposits[i+2])
      {
        temp=HCAL_Cluster_1_Deposits[i+2];
        HCAL_Cluster_1_Deposits[i+2]=HCAL_Cluster_1_Deposits[i];
        HCAL_Cluster_1_Deposits[i]=temp;
        temp=HCAL_Cluster_1_Eta[i+2];
        HCAL_Cluster_1_Eta[i+2]=HCAL_Cluster_1_Eta[i];
        HCAL_Cluster_1_Eta[i]=temp;
        temp=HCAL_Cluster_1_Phi[i+2];
        HCAL_Cluster_1_Phi[i+2]=HCAL_Cluster_1_Phi[i];
        HCAL_Cluster_1_Phi[i]=temp;
      }
    if(HCAL_Cluster_1_Deposits[i+1]>HCAL_Cluster_1_Deposits[i+3])
      {
        temp=HCAL_Cluster_1_Deposits[i+3];
        HCAL_Cluster_1_Deposits[i+3]=HCAL_Cluster_1_Deposits[i+1];
        HCAL_Cluster_1_Deposits[i+1]=temp;
         temp=HCAL_Cluster_1_Eta[i+1];
        HCAL_Cluster_1_Eta[i+1]=HCAL_Cluster_1_Eta[i+3];
        HCAL_Cluster_1_Eta[i+3]=temp;
        temp=HCAL_Cluster_1_Phi[i+1];
        HCAL_Cluster_1_Phi[i+1]=HCAL_Cluster_1_Phi[i+3];
        HCAL_Cluster_1_Phi[i+3]=temp;
      }
  }
  
  for(int i=0;i<7;i=i+2)
  {
    #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+1])
      {
        temp=HCAL_Cluster_1_Deposits[i+1];
        HCAL_Cluster_1_Deposits[i+1]=HCAL_Cluster_1_Deposits[i];
        HCAL_Cluster_1_Deposits[i]=temp;
          temp=HCAL_Cluster_1_Eta[i];
          HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+1];
          HCAL_Cluster_1_Eta[i+1]=temp;
          temp=HCAL_Cluster_1_Phi[i];
          HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+1];
          HCAL_Cluster_1_Phi[i+1]=temp;
      }
  }
  for(int i=8;i<15;i=i+2)
  {
    #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]>HCAL_Cluster_1_Deposits[i+1])
      {
        temp=HCAL_Cluster_1_Deposits[i+1];
        HCAL_Cluster_1_Deposits[i+1]=HCAL_Cluster_1_Deposits[i];
        HCAL_Cluster_1_Deposits[i]=temp;
          temp=HCAL_Cluster_1_Eta[i];
          HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+1];
          HCAL_Cluster_1_Eta[i+1]=temp;
          temp=HCAL_Cluster_1_Phi[i];
          HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+1];
          HCAL_Cluster_1_Phi[i+1]=temp;
      }
  }
 HCAL_bitonic_1_16(HCAL_Cluster_1_Deposits,HCAL_Cluster_1_Eta,HCAL_Cluster_1_Phi);
}
void HCAL_bitonic_1_4( ap_fixed<16,9>   HCAL_Cluster_1_Deposits[16], uint16_t HCAL_Cluster_1_Eta[16], uint16_t HCAL_Cluster_1_Phi[16])
{
  int temp;
// #pragma HLS dataflow
// comparators in blocks of 4
  for(int i=0;i<2;i++)
  {
    #pragma HLS unroll
      if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+2])
              {temp=HCAL_Cluster_1_Deposits[i];
              HCAL_Cluster_1_Deposits[i]=HCAL_Cluster_1_Deposits[i+2];
              HCAL_Cluster_1_Deposits[i+2]=temp;
               temp=HCAL_Cluster_1_Eta[i];
              HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+2];
              HCAL_Cluster_1_Eta[i+2]=temp;
              temp=HCAL_Cluster_1_Phi[i];
              HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+2];
              HCAL_Cluster_1_Phi[i+2]=temp;
              }
  }
  for(int i=4;i<6;i++)
  {
#pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]>HCAL_Cluster_1_Deposits[i+2])
              {temp=HCAL_Cluster_1_Deposits[i];
              HCAL_Cluster_1_Deposits[i]=HCAL_Cluster_1_Deposits[i+2];
              HCAL_Cluster_1_Deposits[i+2]=temp;
               temp=HCAL_Cluster_1_Eta[i];
              HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+2];
              HCAL_Cluster_1_Eta[i+2]=temp;
              temp=HCAL_Cluster_1_Phi[i];
              HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+2];
              HCAL_Cluster_1_Phi[i+2]=temp;
              }
  }
  for(int i=8;i<10;i++)
  {
#pragma HLS unroll
      if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+2])
              {temp=HCAL_Cluster_1_Deposits[i];
              HCAL_Cluster_1_Deposits[i]=HCAL_Cluster_1_Deposits[i+2];
              HCAL_Cluster_1_Deposits[i+2]=temp;
               temp=HCAL_Cluster_1_Eta[i];
              HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+2];
              HCAL_Cluster_1_Eta[i+2]=temp;
              temp=HCAL_Cluster_1_Phi[i];
              HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+2];
              HCAL_Cluster_1_Phi[i+2]=temp;
              }
  }
  for(int i=12;i<14;i++)
  {
#pragma HLS unroll
      if(HCAL_Cluster_1_Deposits[i]>HCAL_Cluster_1_Deposits[i+2])
              {temp=HCAL_Cluster_1_Deposits[i];
              HCAL_Cluster_1_Deposits[i]=HCAL_Cluster_1_Deposits[i+2];
              HCAL_Cluster_1_Deposits[i+2]=temp;
               temp=HCAL_Cluster_1_Eta[i];
              HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+2];
              HCAL_Cluster_1_Eta[i+2]=temp;
              temp=HCAL_Cluster_1_Phi[i];
              HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+2];
              HCAL_Cluster_1_Phi[i+2]=temp;
              }
  }
  
  for(int i=0;i<3;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+1])
              {temp=HCAL_Cluster_1_Deposits[i];
              HCAL_Cluster_1_Deposits[i]=HCAL_Cluster_1_Deposits[i+1];
              HCAL_Cluster_1_Deposits[i+1]=temp;
                temp=HCAL_Cluster_1_Eta[i];
              HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+1];
              HCAL_Cluster_1_Eta[i+1]=temp;
              temp=HCAL_Cluster_1_Phi[i];
              HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+1];
              HCAL_Cluster_1_Phi[i+1]=temp;
              }
  }
  for(int i=4;i<7;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]>HCAL_Cluster_1_Deposits[i+1])
              {temp=HCAL_Cluster_1_Deposits[i];
              HCAL_Cluster_1_Deposits[i]=HCAL_Cluster_1_Deposits[i+1];
              HCAL_Cluster_1_Deposits[i+1]=temp;
                temp=HCAL_Cluster_1_Eta[i];
              HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+1];
              HCAL_Cluster_1_Eta[i+1]=temp;
              temp=HCAL_Cluster_1_Phi[i];
              HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+1];
              HCAL_Cluster_1_Phi[i+1]=temp;
              }
  }
  for(int i=8;i<11;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+1])
              {temp=HCAL_Cluster_1_Deposits[i];
              HCAL_Cluster_1_Deposits[i]=HCAL_Cluster_1_Deposits[i+1];
              HCAL_Cluster_1_Deposits[i+1]=temp;
                temp=HCAL_Cluster_1_Eta[i];
              HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+1];
              HCAL_Cluster_1_Eta[i+1]=temp;
              temp=HCAL_Cluster_1_Phi[i];
              HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+1];
              HCAL_Cluster_1_Phi[i+1]=temp;
              }
  }
  for(int i=12;i<15;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_Cluster_1_Deposits[i]>HCAL_Cluster_1_Deposits[i+1])
              {temp=HCAL_Cluster_1_Deposits[i];
              HCAL_Cluster_1_Deposits[i]=HCAL_Cluster_1_Deposits[i+1];
              HCAL_Cluster_1_Deposits[i+1]=temp;
                temp=HCAL_Cluster_1_Eta[i];
              HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+1];
              HCAL_Cluster_1_Eta[i+1]=temp;
              temp=HCAL_Cluster_1_Phi[i];
              HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+1];
              HCAL_Cluster_1_Phi[i+1]=temp;
              }
  }
  
  HCAL_bitonic_1_8(HCAL_Cluster_1_Deposits,HCAL_Cluster_1_Eta,HCAL_Cluster_1_Phi);

}
void HCAL_bitonic_2_32( ap_fixed<16,9>   HCAL_ClusterDeposits[32], uint16_t HCAL_ClusterEta[32], uint16_t HCAL_ClusterPhi[32])
{// sorting blocks of size 32
  int temp;
// #pragma HLS dataflow
for(int i=0;i<16;i++)
{
#pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+16])
    {
      temp=HCAL_ClusterDeposits[i+16];
      HCAL_ClusterDeposits[i+16]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+16];
        HCAL_ClusterEta[i+16]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+16];
        HCAL_ClusterPhi[i+16]=temp;
    }
  }

  for(int i=0;i<8;i++)
  {
#pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+8])
        {
          temp=HCAL_ClusterDeposits[i+8];
          HCAL_ClusterDeposits[i+8]=HCAL_ClusterDeposits[i];
          HCAL_ClusterDeposits[i]=temp;
          temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+8];
        HCAL_ClusterEta[i+8]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+8];
        HCAL_ClusterPhi[i+8]=temp;
        }
  }
  for(int i=16;i<24;i++)
    {
  #pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+8])
          {
            temp=HCAL_ClusterDeposits[i+8];
            HCAL_ClusterDeposits[i+8]=HCAL_ClusterDeposits[i];
            HCAL_ClusterDeposits[i]=temp;
            temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+8];
        HCAL_ClusterEta[i+8]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+8];
        HCAL_ClusterPhi[i+8]=temp;
          }
    }



 for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+4])
    {
      temp=HCAL_ClusterDeposits[i+4];
      HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
    }
    }
 for(int i=8;i<12;i++)
      {
      #pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+4])
        {
          temp=HCAL_ClusterDeposits[i+4];
          HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
          HCAL_ClusterDeposits[i]=temp;
          temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
        }
        }
 for(int i=16;i<20;i++)
      {
      #pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+4])
        {
          temp=HCAL_ClusterDeposits[i+4];
          HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
          HCAL_ClusterDeposits[i]=temp;
          temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
        }
        }
 for(int i=24;i<28;i++)
      {
      #pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+4])
        {
          temp=HCAL_ClusterDeposits[i+4];
          HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
          HCAL_ClusterDeposits[i]=temp;
          temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
        }
        }


 for(int i=0;i<29;i=i+4)
            {
            #pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+2])
          {
              temp=HCAL_ClusterDeposits[i+2];
              HCAL_ClusterDeposits[i+2]=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=temp;
               temp=HCAL_ClusterEta[i];
                HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
                HCAL_ClusterEta[i+2]=temp;
                temp=HCAL_ClusterPhi[i];
                HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
                HCAL_ClusterPhi[i+2]=temp;
          }
          if(HCAL_ClusterDeposits[i+1]<HCAL_ClusterDeposits[i+3])
          {
              temp=HCAL_ClusterDeposits[i+3];
              HCAL_ClusterDeposits[i+3]=HCAL_ClusterDeposits[i+1];
              HCAL_ClusterDeposits[i+1]=temp;
              temp=HCAL_ClusterEta[i+1];
               HCAL_ClusterEta[i+1]=HCAL_ClusterEta[i+3];
               HCAL_ClusterEta[i+3]=temp;
               temp=HCAL_ClusterPhi[i+1];
               HCAL_ClusterPhi[i+1]=HCAL_ClusterPhi[i+3];
               HCAL_ClusterPhi[i+3]=temp;
          }
          }


     for(int i=0;i<31;i=i+2)
      {
      #pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+1])
        {
          temp=HCAL_ClusterDeposits[i+1];
          HCAL_ClusterDeposits[i+1]=HCAL_ClusterDeposits[i];
          HCAL_ClusterDeposits[i]=temp;
          temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
        }
      }

  }  
void HCAL_bitonic_2_16( ap_fixed<16,9>   HCAL_ClusterDeposits[32], uint16_t HCAL_ClusterEta[32], uint16_t HCAL_ClusterPhi[32])
{// sorting blocks of size 16
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<8;i++)
  {
  #pragma HLS unroll
  if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+8])
    {
      temp=HCAL_ClusterDeposits[i+8];
      HCAL_ClusterDeposits[i+8]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+8];
        HCAL_ClusterEta[i+8]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+8];
        HCAL_ClusterPhi[i+8]=temp;
    }

    }

  for(int i=16;i<24;i++)
  {
  #pragma HLS unroll
  if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+8])
    {
      temp=HCAL_ClusterDeposits[i+8];
      HCAL_ClusterDeposits[i+8]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+8];
        HCAL_ClusterEta[i+8]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+8];
        HCAL_ClusterPhi[i+8]=temp;
    }

    }
   for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+4])
    {
      temp=HCAL_ClusterDeposits[i+4];
      HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
    }
    }
   for(int i=8;i<12;i++)
  {
  #pragma HLS unroll
  if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+4])
    {
      temp=HCAL_ClusterDeposits[i+4];
      HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
    }
    }
   for(int i=16;i<20;i++)
  {
  #pragma HLS unroll
  if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+4])
    {
      temp=HCAL_ClusterDeposits[i+4];
      HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
    }
    }
  for(int i=24;i<28;i++)
  {
  #pragma HLS unroll
  if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+4])
    {
      temp=HCAL_ClusterDeposits[i+4];
      HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
    }
    }

  for(int i=0;i<13;i=i+4)
  {
  #pragma HLS unroll
  if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+2])
    {
      temp=HCAL_ClusterDeposits[i+2];
      HCAL_ClusterDeposits[i+2]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
          HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
          HCAL_ClusterEta[i+2]=temp;
          temp=HCAL_ClusterPhi[i];
          HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
          HCAL_ClusterPhi[i+2]=temp;
    }

    if(HCAL_ClusterDeposits[i+1]<HCAL_ClusterDeposits[i+3])
    {
      temp=HCAL_ClusterDeposits[i+3];
      HCAL_ClusterDeposits[i+3]=HCAL_ClusterDeposits[i+1];
      HCAL_ClusterDeposits[i+1]=temp;
       temp=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=HCAL_ClusterEta[i+3];
              HCAL_ClusterEta[i+3]=temp;
              temp=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=HCAL_ClusterPhi[i+3];
              HCAL_ClusterPhi[i+3]=temp;
    }
    }
  for(int i=16;i<29;i=i+4)
  {
  #pragma HLS unroll
  if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+2])
    {
      temp=HCAL_ClusterDeposits[i+2];
      HCAL_ClusterDeposits[i+2]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
      temp=HCAL_ClusterEta[i];
          HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
          HCAL_ClusterEta[i+2]=temp;
          temp=HCAL_ClusterPhi[i];
          HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
          HCAL_ClusterPhi[i+2]=temp;
    }

    if(HCAL_ClusterDeposits[i+1]>HCAL_ClusterDeposits[i+3])
    {
      temp=HCAL_ClusterDeposits[i+3];
      HCAL_ClusterDeposits[i+3]=HCAL_ClusterDeposits[i+1];
      HCAL_ClusterDeposits[i+1]=temp;
       temp=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=HCAL_ClusterEta[i+3];
              HCAL_ClusterEta[i+3]=temp;
              temp=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=HCAL_ClusterPhi[i+3];
              HCAL_ClusterPhi[i+3]=temp;
    }
    }
 
   

  for(int i=0;i<15;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+1])
    {
      temp=HCAL_ClusterDeposits[i+1];
      HCAL_ClusterDeposits[i+1]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
       temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
    }

    }
  for(int i=16;i<31;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+1])
    {
      temp=HCAL_ClusterDeposits[i+1];
      HCAL_ClusterDeposits[i+1]=HCAL_ClusterDeposits[i];
      HCAL_ClusterDeposits[i]=temp;
       temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
    }

    }


HCAL_bitonic_2_32(HCAL_ClusterDeposits,HCAL_ClusterEta,HCAL_ClusterPhi);
  }

void HCAL_bitonic_2_8( ap_fixed<16,9>   HCAL_ClusterDeposits[32], uint16_t HCAL_ClusterEta[32], uint16_t HCAL_ClusterPhi[32])
{// sorting blocks of size 8
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<4;i++)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+4])
      {
        temp=HCAL_ClusterDeposits[i+4];
        HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
        temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
      }
  }
  for(int i=8;i<12;i++)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+4])
      {
        temp=HCAL_ClusterDeposits[i+4];
        HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
        temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
      }
  }
  for(int i=16;i<20;i++)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+4])
      {
        temp=HCAL_ClusterDeposits[i+4];
        HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
        temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
      }
  }
  for(int i=24;i<28;i++)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+4])
      {
        temp=HCAL_ClusterDeposits[i+4];
        HCAL_ClusterDeposits[i+4]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
        temp=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=HCAL_ClusterEta[i+4];
        HCAL_ClusterEta[i+4]=temp;
        temp=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+4];
        HCAL_ClusterPhi[i+4]=temp;
      }
  }


  for(int i=0;i<5;i=i+4)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+2])
      {
        temp=HCAL_ClusterDeposits[i+2];
        HCAL_ClusterDeposits[i+2]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
        temp=HCAL_ClusterEta[i+2];
        HCAL_ClusterEta[i+2]=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=temp;
        temp=HCAL_ClusterPhi[i+2];
        HCAL_ClusterPhi[i+2]=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=temp;
      }
    if(HCAL_ClusterDeposits[i+1]<HCAL_ClusterDeposits[i+3])
      {
        temp=HCAL_ClusterDeposits[i+3];
        HCAL_ClusterDeposits[i+3]=HCAL_ClusterDeposits[i+1];
        HCAL_ClusterDeposits[i+1]=temp;
          temp=HCAL_ClusterEta[i+1];
        HCAL_ClusterEta[i+1]=HCAL_ClusterEta[i+3];
        HCAL_ClusterEta[i+3]=temp;
        temp=HCAL_ClusterPhi[i+1];
        HCAL_ClusterPhi[i+1]=HCAL_ClusterPhi[i+3];
        HCAL_ClusterPhi[i+3]=temp;
      }
  }
  for(int i=8;i<13;i=i+4)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+2])
      {
        temp=HCAL_ClusterDeposits[i+2];
        HCAL_ClusterDeposits[i+2]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
        temp=HCAL_ClusterEta[i+2];
        HCAL_ClusterEta[i+2]=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=temp;
        temp=HCAL_ClusterPhi[i+2];
        HCAL_ClusterPhi[i+2]=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=temp;
      }
    if(HCAL_ClusterDeposits[i+1]>HCAL_ClusterDeposits[i+3])
      {
        temp=HCAL_ClusterDeposits[i+3];
        HCAL_ClusterDeposits[i+3]=HCAL_ClusterDeposits[i+1];
        HCAL_ClusterDeposits[i+1]=temp;
         temp=HCAL_ClusterEta[i+1];
        HCAL_ClusterEta[i+1]=HCAL_ClusterEta[i+3];
        HCAL_ClusterEta[i+3]=temp;
        temp=HCAL_ClusterPhi[i+1];
        HCAL_ClusterPhi[i+1]=HCAL_ClusterPhi[i+3];
        HCAL_ClusterPhi[i+3]=temp;
      }
  }
  for(int i=16;i<21;i=i+4)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+2])
      {
        temp=HCAL_ClusterDeposits[i+2];
        HCAL_ClusterDeposits[i+2]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
        temp=HCAL_ClusterEta[i+2];
        HCAL_ClusterEta[i+2]=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=temp;
        temp=HCAL_ClusterPhi[i+2];
        HCAL_ClusterPhi[i+2]=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=temp;
      }
    if(HCAL_ClusterDeposits[i+1]<HCAL_ClusterDeposits[i+3])
      {
        temp=HCAL_ClusterDeposits[i+3];
        HCAL_ClusterDeposits[i+3]=HCAL_ClusterDeposits[i+1];
        HCAL_ClusterDeposits[i+1]=temp;
         temp=HCAL_ClusterEta[i+1];
        HCAL_ClusterEta[i+1]=HCAL_ClusterEta[i+3];
        HCAL_ClusterEta[i+3]=temp;
        temp=HCAL_ClusterPhi[i+1];
        HCAL_ClusterPhi[i+1]=HCAL_ClusterPhi[i+3];
        HCAL_ClusterPhi[i+3]=temp;
      }
  }
  for(int i=24;i<29;i=i+4)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+2])
      {
        temp=HCAL_ClusterDeposits[i+2];
        HCAL_ClusterDeposits[i+2]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
        temp=HCAL_ClusterEta[i+2];
        HCAL_ClusterEta[i+2]=HCAL_ClusterEta[i];
        HCAL_ClusterEta[i]=temp;
        temp=HCAL_ClusterPhi[i+2];
        HCAL_ClusterPhi[i+2]=HCAL_ClusterPhi[i];
        HCAL_ClusterPhi[i]=temp;
      }
      
    if(HCAL_ClusterDeposits[i+1]>HCAL_ClusterDeposits[i+3])
      {
        temp=HCAL_ClusterDeposits[i+3];
        HCAL_ClusterDeposits[i+3]=HCAL_ClusterDeposits[i+1];
        HCAL_ClusterDeposits[i+1]=temp;
        temp=HCAL_ClusterEta[i+1];
        HCAL_ClusterEta[i+1]=HCAL_ClusterEta[i+3];
        HCAL_ClusterEta[i+3]=temp;
        temp=HCAL_ClusterPhi[i+1];
        HCAL_ClusterPhi[i+1]=HCAL_ClusterPhi[i+3];
        HCAL_ClusterPhi[i+3]=temp;
      }
      
  }


  for(int i=0;i<7;i=i+2)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+1])
      {
        temp=HCAL_ClusterDeposits[i+1];
        HCAL_ClusterDeposits[i+1]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
          temp=HCAL_ClusterEta[i];
          HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
          HCAL_ClusterEta[i+1]=temp;
          temp=HCAL_ClusterPhi[i];
          HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
          HCAL_ClusterPhi[i+1]=temp;
      }
  }
  for(int i=8;i<15;i=i+2)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+1])
      {
        temp=HCAL_ClusterDeposits[i+1];
        HCAL_ClusterDeposits[i+1]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
          temp=HCAL_ClusterEta[i];
          HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
          HCAL_ClusterEta[i+1]=temp;
          temp=HCAL_ClusterPhi[i];
          HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
          HCAL_ClusterPhi[i+1]=temp;
      }
  }
  for(int i=16;i<23;i=i+2)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+1])
      {
        temp=HCAL_ClusterDeposits[i+1];
        HCAL_ClusterDeposits[i+1]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
          temp=HCAL_ClusterEta[i];
          HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
          HCAL_ClusterEta[i+1]=temp;
          temp=HCAL_ClusterPhi[i];
          HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
          HCAL_ClusterPhi[i+1]=temp;
      }
  }
  for(int i=24;i<31;i=i+2)
  {
    #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+1])
      {
        temp=HCAL_ClusterDeposits[i+1];
        HCAL_ClusterDeposits[i+1]=HCAL_ClusterDeposits[i];
        HCAL_ClusterDeposits[i]=temp;
         temp=HCAL_ClusterEta[i];
          HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
          HCAL_ClusterEta[i+1]=temp;
          temp=HCAL_ClusterPhi[i];
          HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
          HCAL_ClusterPhi[i+1]=temp;
      }
  }
 
HCAL_bitonic_2_16(HCAL_ClusterDeposits,HCAL_ClusterEta,HCAL_ClusterPhi);
}
void HCAL_bitonic_2_4( ap_fixed<16,9>   HCAL_ClusterDeposits[32], uint16_t HCAL_ClusterEta[32], uint16_t HCAL_ClusterPhi[32])
{
  int temp;
// #pragma HLS dataflow
// comparators in blocks of 4
  for(int i=0;i<2;i++)
  {
    #pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+2])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+2];
              HCAL_ClusterDeposits[i+2]=temp;
               temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
              HCAL_ClusterEta[i+2]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
              HCAL_ClusterPhi[i+2]=temp;
              }
  }
  for(int i=4;i<6;i++)
  {
#pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+2])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+2];
              HCAL_ClusterDeposits[i+2]=temp;
               temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
              HCAL_ClusterEta[i+2]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
              HCAL_ClusterPhi[i+2]=temp;
              }
  }
  for(int i=8;i<10;i++)
  {
#pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+2])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+2];
              HCAL_ClusterDeposits[i+2]=temp;
               temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
              HCAL_ClusterEta[i+2]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
              HCAL_ClusterPhi[i+2]=temp;
              }
  }
  for(int i=12;i<14;i++)
  {
#pragma HLS unroll
      if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+2])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+2];
              HCAL_ClusterDeposits[i+2]=temp;
               temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
              HCAL_ClusterEta[i+2]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
              HCAL_ClusterPhi[i+2]=temp;
              }
  }
  for(int i=16;i<18;i++)
  {
#pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+2])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+2];
              HCAL_ClusterDeposits[i+2]=temp;
               temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
              HCAL_ClusterEta[i+2]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
              HCAL_ClusterPhi[i+2]=temp;
              }
  }
  for(int i=20;i<22;i++)
  {
#pragma HLS unroll
      if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+2])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+2];
              HCAL_ClusterDeposits[i+2]=temp;
               temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
              HCAL_ClusterEta[i+2]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
              HCAL_ClusterPhi[i+2]=temp;
              }
  }
  for(int i=24;i<26;i++)
  {
#pragma HLS unroll
      if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+2])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+2];
              HCAL_ClusterDeposits[i+2]=temp;
               temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
              HCAL_ClusterEta[i+2]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
              HCAL_ClusterPhi[i+2]=temp;
              }
  }
  for(int i=28;i<30;i++)
  {
#pragma HLS unroll
      if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+2])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+2];
              HCAL_ClusterDeposits[i+2]=temp;
               temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+2];
              HCAL_ClusterEta[i+2]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+2];
              HCAL_ClusterPhi[i+2]=temp;
              }
  }
 
  for(int i=0;i<3;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+1])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+1];
              HCAL_ClusterDeposits[i+1]=temp;
                temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
              }
  }
  for(int i=4;i<7;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+1])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+1];
              HCAL_ClusterDeposits[i+1]=temp;
                temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
              }
  }
  for(int i=8;i<11;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+1])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+1];
              HCAL_ClusterDeposits[i+1]=temp;
                temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
              }
  }
  for(int i=12;i<15;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+1])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+1];
              HCAL_ClusterDeposits[i+1]=temp;
                temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
              }
  }
  for(int i=16;i<19;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+1])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+1];
              HCAL_ClusterDeposits[i+1]=temp;
                temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
              }
  }
  for(int i=20;i<23;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+1])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+1];
              HCAL_ClusterDeposits[i+1]=temp;
                temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
              }
  }
  for(int i=24;i<27;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]<HCAL_ClusterDeposits[i+1])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+1];
              HCAL_ClusterDeposits[i+1]=temp;
                temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
              }
  }
  for(int i=28;i<31;i=i+2)
  {
  #pragma HLS unroll
    if(HCAL_ClusterDeposits[i]>HCAL_ClusterDeposits[i+1])
              {temp=HCAL_ClusterDeposits[i];
              HCAL_ClusterDeposits[i]=HCAL_ClusterDeposits[i+1];
              HCAL_ClusterDeposits[i+1]=temp;
                temp=HCAL_ClusterEta[i];
              HCAL_ClusterEta[i]=HCAL_ClusterEta[i+1];
              HCAL_ClusterEta[i+1]=temp;
              temp=HCAL_ClusterPhi[i];
              HCAL_ClusterPhi[i]=HCAL_ClusterPhi[i+1];
              HCAL_ClusterPhi[i+1]=temp;
              }
  }
  
  HCAL_bitonic_2_8(HCAL_ClusterDeposits,HCAL_ClusterEta,HCAL_ClusterPhi);

}
void getHCAL_TowerPeaks3x4( ap_fixed<16,9>   HCAL_towerET_calRegions[3][4],uint16_t cEta[5],
                        uint16_t cPhi[5])
{
  int temp;// temporary copying variable
#pragma HLS PIPELINE II=8
  ap_fixed<16,9>   HCAL_Cluster_1_Deposits[16];
  uint16_t HCAL_Cluster_1_Eta[16];
  uint16_t HCAL_Cluster_1_Phi[16];
#pragma HLS ARRAY_PARTITION variable=HCAL_Cluster_1_Deposits complete dim=0
 #pragma HLS ARRAY_PARTITION variable=HCAL_Cluster_1_Eta complete dim=0
  #pragma HLS ARRAY_PARTITION variable=HCAL_Cluster_1_Phi complete dim=0
#pragma HLS ARRAY_PARTITION variable=cEta complete dim=0
 #pragma HLS ARRAY_PARTITION variable=cPhi complete dim=0
#pragma HLS ARRAY_PARTITION variable=HCAL_towerET_calRegions complete dim=0
  
 for(int i=0;i<16;i++)
  {
    HCAL_Cluster_1_Deposits[i]=0;
    HCAL_Cluster_1_Phi[i]=0;
    HCAL_Cluster_1_Eta[i]=0;

  }
  int i=0;
 for(int tPhi = 0; tPhi < 4; tPhi++) {
#pragma HLS UNROLL
    for(int tEta = 0; tEta < 3; tEta++) {
#pragma HLS UNROLL
      HCAL_Cluster_1_Deposits[i] = HCAL_towerET_calRegions[tEta][tPhi];
       HCAL_Cluster_1_Phi[i]=tPhi;
      HCAL_Cluster_1_Eta[i]=tEta;
     i++;
    }
  }
for (int i=13;i<16;i++)
{
#pragma HLS UNROLL
 HCAL_Cluster_1_Deposits[i]=0;
 HCAL_Cluster_1_Phi[i]=0;
  HCAL_Cluster_1_Eta[i]=0;
}
//first level of binary comparators
for(int i=0;i<16;i=i+4)
{
#pragma HLS unroll
if(HCAL_Cluster_1_Deposits[i]<HCAL_Cluster_1_Deposits[i+1])
{temp=HCAL_Cluster_1_Deposits[i+1];
HCAL_Cluster_1_Deposits[i+1]=HCAL_Cluster_1_Deposits[i];
HCAL_Cluster_1_Deposits[i]=temp;
temp=HCAL_Cluster_1_Eta[i];
HCAL_Cluster_1_Eta[i]=HCAL_Cluster_1_Eta[i+1];
HCAL_Cluster_1_Eta[i+1]=temp;
temp=HCAL_Cluster_1_Phi[i];
HCAL_Cluster_1_Phi[i]=HCAL_Cluster_1_Phi[i+1];
HCAL_Cluster_1_Phi[i+1]=temp;
}

if(HCAL_Cluster_1_Deposits[i+2]>HCAL_Cluster_1_Deposits[i+3])
{temp=HCAL_Cluster_1_Deposits[i+3];
HCAL_Cluster_1_Deposits[i+3]=HCAL_Cluster_1_Deposits[i+2];
HCAL_Cluster_1_Deposits[i+2]=temp;
temp=HCAL_Cluster_1_Eta[i+2];
HCAL_Cluster_1_Eta[i+2]=HCAL_Cluster_1_Eta[i+3];
HCAL_Cluster_1_Eta[i+3]=temp;
temp=HCAL_Cluster_1_Phi[i+2];
HCAL_Cluster_1_Phi[i+2]=HCAL_Cluster_1_Phi[i+3];
HCAL_Cluster_1_Phi[i+3]=temp;

}
  }


    // passing control to second level of quaternary comparators
    HCAL_bitonic_1_4(HCAL_Cluster_1_Deposits,HCAL_Cluster_1_Eta,HCAL_Cluster_1_Phi);
    //copying sorted array back into output variable
for(int i=0;i<5;i++)
{
  cEta[i]=HCAL_Cluster_1_Eta[i];
  cPhi[i]=HCAL_Cluster_1_Phi[i];
}
  

}
void HCAL_TowerPeaks( ap_fixed<16,9> HCAL_towerET_uncal[17][4],  uint16_t HCAL_TowerPhi[30], uint16_t HCAL_TowerEta[30])
{
#pragma HLS PIPELINE II=8
#pragma HLS ARRAY_PARTITION variable=HCAL_towerET_uncal complete dim=0

 ap_fixed<16,9>   HCAL_towerET_cal [17][4];

#pragma HLS ARRAY_PARTITION variable=HCAL_towerET_cal complete dim=0
for (int i=0;i<17;i++)
{
  for (int j=0;j<4;j++)
  {
    HCAL_towerET_cal[i][j]=0;
  }
}
#pragma HLS ARRAY_PARTITION variable=HCAL_TowerEta complete dim=0
#pragma HLS ARRAY_PARTITION variable=HCAL_TowerPhi complete dim=0

//HCAL_Calibration
 for (int j=0;j<17;j++)
  {
  #pragma HLS UNROLL
      for (int k=0;k<4;k++)
      {
      #pragma HLS UNROLL
        if(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[0])
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[0][j];
         }
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[0])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[1]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[1][j];
         } 
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[1])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[2]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[2][j];
         }
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[2])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[3]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[3][j];
         } 
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[3])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[4]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[4][j];
         }
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[4])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[5]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[5][j];
         } 
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[5])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[6]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[6][j];
         }
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[6])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[7]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[7][j];
         } 
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[7])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[8]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[8][j];
         }
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[8])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[9]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[9][j];
         } 
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[9])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[10]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[10][j];
         }
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[10])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[11]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[11][j];
         } 
        else if ((HCAL_towerET_uncal[j][k]>HCAL_Calib_ET_Bins[11])&&(HCAL_towerET_uncal[j][k]<HCAL_Calib_ET_Bins[12]))
         {
          HCAL_towerET_cal[j][k]=HCAL_towerET_uncal[j][k]*HCAL_Calib_LUT[12][j];
         }

      }
  }
 ap_fixed<16,9>   HCAL_regions[3][4];
#pragma HLS ARRAY_PARTITION variable=HCAL_regions complete dim=0
uint16_t HCAL_regionEta[5];
#pragma HLS ARRAY_PARTITION variable=HCAL_regionEta complete dim=0
uint16_t HCAL_regionPhi[5];
#pragma HLS ARRAY_PARTITION variable=HCAL_regionPhi complete dim=0
uint16_t HCAL_Tower_1_Eta[30];
#pragma HLS ARRAY_PARTITION variable=HCAL_Tower_1_Eta complete dim=0
uint16_t HCAL_Tower_1_Phi[30];
#pragma HLS ARRAY_PARTITION variable=HCAL_Tower_1_Phi complete dim=0

#pragma HLS UNROLL
 for (int j=0;j<3;j++)
  {
  #pragma HLS UNROLL
      for (int k=0;k<4;k++)
      {
      #pragma HLS UNROLL
        HCAL_regions[j][k]=0;
      }
  }
  for (int i=0;i<5;i++)
  {
    HCAL_regionEta[i]=0;
    HCAL_regionPhi[i]=0;
  }
  for(int i=0;i<30;i++)
  {
    HCAL_Tower_1_Eta[i]=0;
    HCAL_Tower_1_Phi[i]=0;
  }

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
        HCAL_regions[j][k]=HCAL_towerET_cal[i+j][k];
      }
  }

getHCAL_TowerPeaks3x4(HCAL_regions,HCAL_regionEta,HCAL_regionPhi);
HCAL_Tower_1_Eta[x+0]=HCAL_regionEta[0]+i;
HCAL_Tower_1_Eta[x+1]=HCAL_regionEta[1]+i;
HCAL_Tower_1_Eta[x+2]=HCAL_regionEta[2]+i;
HCAL_Tower_1_Eta[x+3]=HCAL_regionEta[3]+i;
HCAL_Tower_1_Eta[x+4]=HCAL_regionEta[4]+i;
HCAL_Tower_1_Phi[x+0]=HCAL_regionPhi[0];
HCAL_Tower_1_Phi[x+1]=HCAL_regionPhi[1];
HCAL_Tower_1_Phi[x+2]=HCAL_regionPhi[2];
HCAL_Tower_1_Phi[x+3]=HCAL_regionPhi[3];
HCAL_Tower_1_Phi[x+4]=HCAL_regionPhi[4];
x=x+5;
}
for (int j=0;j<2;j++)
  {
  #pragma HLS UNROLL
      for (int k=0;k<4;k++)
      {
      #pragma HLS UNROLL
        HCAL_regions[j][k]=HCAL_towerET_cal[j+15][k];
      }
  }
  HCAL_regions[2][0]=0;
  HCAL_regions[2][1]=0;
  HCAL_regions[2][2]=0;
  HCAL_regions[2][3]=0;
  getHCAL_TowerPeaks3x4(HCAL_regions,HCAL_regionEta,HCAL_regionPhi);
HCAL_Tower_1_Eta[25+0]=HCAL_regionEta[0]+15;
HCAL_Tower_1_Eta[25+1]=HCAL_regionEta[1]+15;
HCAL_Tower_1_Eta[25+2]=HCAL_regionEta[2]+15;
HCAL_Tower_1_Eta[25+3]=HCAL_regionEta[3]+15;
HCAL_Tower_1_Eta[25+4]=HCAL_regionEta[4]+15;
HCAL_Tower_1_Phi[25+0]=HCAL_regionPhi[0];
HCAL_Tower_1_Phi[25+1]=HCAL_regionPhi[1];
HCAL_Tower_1_Phi[25+2]=HCAL_regionPhi[2];
HCAL_Tower_1_Phi[25+3]=HCAL_regionPhi[3];
HCAL_Tower_1_Phi[25+4]=HCAL_regionPhi[4];
 ap_fixed<16,9>   HCAL_ClusterDeposits2[32];
  uint16_t HCAL_ClusterEta2[32];
  uint16_t HCAL_ClusterPhi2[32];
  for(int i=0;i<32;i++)
{
  HCAL_ClusterDeposits2[i]=0;
  HCAL_ClusterEta2[i]=0;
  HCAL_ClusterPhi2[i]=0;
}
#pragma HLS ARRAY_PARTITION variable=HCAL_ClusterDeposits2 complete dim=0
 #pragma HLS ARRAY_PARTITION variable=HCAL_ClusterEta2 complete dim=0
  #pragma HLS ARRAY_PARTITION variable=HCAL_ClusterPhi2 complete dim=0
for(int i=0;i<30;i++)
{
  HCAL_ClusterDeposits2[i]=HCAL_towerET_cal[HCAL_Tower_1_Eta[i]][HCAL_Tower_1_Phi[i]];
  HCAL_ClusterEta2[i]=HCAL_Tower_1_Eta[i];
  HCAL_ClusterPhi2[i]=HCAL_Tower_1_Phi[i];
}


int temp=0;
//first level of binary comparators
for(int i=0;i<32;i=i+4)
{
#pragma HLS unroll
if(HCAL_ClusterDeposits2[i]>HCAL_ClusterDeposits2[i+1])
{temp=HCAL_ClusterDeposits2[i+1];
HCAL_ClusterDeposits2[i+1]=HCAL_ClusterDeposits2[i];
HCAL_ClusterDeposits2[i]=temp;
temp=HCAL_ClusterEta2[i];
HCAL_ClusterEta2[i]=HCAL_ClusterEta2[i+1];
HCAL_ClusterEta2[i+1]=temp;
temp=HCAL_ClusterPhi2[i];
HCAL_ClusterPhi2[i]=HCAL_ClusterPhi2[i+1];
HCAL_ClusterPhi2[i+1]=temp;
}

if(HCAL_ClusterDeposits2[i+2]<HCAL_ClusterDeposits2[i+3])
{temp=HCAL_ClusterDeposits2[i+3];
HCAL_ClusterDeposits2[i+3]=HCAL_ClusterDeposits2[i+2];
HCAL_ClusterDeposits2[i+2]=temp;
temp=HCAL_ClusterEta2[i+2];
HCAL_ClusterEta2[i+2]=HCAL_ClusterEta2[i+3];
HCAL_ClusterEta2[i+3]=temp;
temp=HCAL_ClusterPhi2[i+2];
HCAL_ClusterPhi2[i+2]=HCAL_ClusterPhi2[i+3];
HCAL_ClusterPhi2[i+3]=temp;

}
  }


    // passing control to second level of quaternary comparators
    HCAL_bitonic_2_4(HCAL_ClusterDeposits2,HCAL_ClusterEta2,HCAL_ClusterPhi2);

    for(int i=0;i<30;i++)
{

  HCAL_TowerEta[i]=HCAL_ClusterEta2[i];
  HCAL_TowerPhi[i]=HCAL_ClusterPhi2[i];

}
}








