#include "ClusterfinderCombined.hh"

#include <iostream>
using namespace std;


int main(int argc, char **argv) {
ap_fixed<16,9> crystals[17][4][5][5];
  for(int tEta = 0; tEta < 17; tEta++) {
    for(int tPhi = 0; tPhi < 4; tPhi++) {
      for(int cEta = 0; cEta < 5; cEta++) {
        for(int cPhi = 0; cPhi < 5; cPhi++) {
          crystals[tEta][tPhi][cEta][cPhi] = 0;
        }
      }
    }
  }
  double totalET = 0;
  double clusters[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 111};
  cout << "Generated clusters: " << endl;
  cout << "tEta\ttPhi\tcEta\tcPhi\tclusterET" << endl;
  for(int cluster = 0; cluster < 10; cluster++) {
    // Crude simulation of dispersal of cluster ET for fun around some location
    int clusterET = clusters[cluster];
    int tEta = clusterET % 17;
    int tPhi = clusterET % 4;
    int cEta = (tPhi * clusterET) % 5;
    int cPhi = (tEta * clusterET) % 5;
    cout << tEta
         << "\t" << tPhi
         << "\t" << cEta
         << "\t" << cPhi
         << "\t" << clusters[cluster] << endl;
    for(int dEta = -1; dEta <= 1; dEta++) {
      for(int dPhi = -1; dPhi <= 1; dPhi++) {
        int ncEta = cEta + dEta;
        int ncPhi = cPhi + dPhi;
        // Start within the tower boundary
        int ntEta = tEta;
        int ntPhi = tPhi;
        // Adjust neighbor trigger tower as needed
        if(ncEta < 0) {ncEta = 4; ntEta = tEta - 1;}
        else if(ncEta > 4) {ncEta = 0; ntEta = tEta + 1;}
        if(ncPhi < 0) {ncPhi = 4; ntPhi = tPhi - 1;}
        else if(ncPhi > 4) {ncPhi = 0; ntPhi = tPhi + 1;}
        // Ignore spill-overs outside the card, defering to next layer
        if(dEta == 0 && dPhi == 0) {
          crystals[tEta][tPhi][cEta][cPhi] = (clusters[cluster] * 0.9);
        }
        else {
          if(ntEta >= 0 && ntEta < 17 && ntPhi >= 0 && ntPhi < 4)
            crystals[ntEta][ntPhi][ncEta][ncPhi] = (clusters[cluster] * 0.1 / 8.);
        }
      }
    }

    totalET += clusters[cluster];
  }
  cout << "Total generated ET = " << totalET << endl;
  uint16_t totalDeposited = 0;
  for(int tEta = 0; tEta < 17; tEta++) {
    for(int tPhi = 0; tPhi < 4; tPhi++) {
      for(int cEta = 0; cEta < 5; cEta++) {
        for(int cPhi = 0; cPhi < 5; cPhi++) {
    //std::cout<<"tEta/tPhi/cEta/cPhi/crystalet/"<<tEta<<"/"<<tPhi<<"/"<<cEta<<"/"<<cPhi<<"/"<<crystals[tEta][tPhi][cEta][cPhi]<<endl;
      
          totalDeposited += (int)crystals[tEta][tPhi][cEta][cPhi];
      }
      }
    }
  }
  cout << "Total deposited ET = " << totalDeposited << endl;
  uint16_t peakEta[17][4];
  uint16_t peakPhi[17][4];
  ap_fixed<16,9> largeClusterET[17][4];
  ap_fixed<16,9> smallClusterET[17][4];
  ap_fixed<16,9> sortedCluster_ET[30];
   uint16_t TowerPeak_Eta[30];
  uint16_t TowerPeak_Phi[30];
  uint16_t sortedPeak_Eta[30];
  uint16_t sortedPeak_Phi[30];
  ap_fixed<16,9> totalCardET = 0;
  ap_fixed<16,9> a[17][4];
  a[0][0]=16;
  		 a[1][0]=24;
  		 a[2][0]=72;
  		 a[3][0]=6;
  		 a[4][0]=28;
  		 a[5][0]=67;
  		 a[6][0]=53;
  		 a[7][0]=49;
  		 a[0+8][0]=12;
  		 a[1+8][0]=14;
  		 a[2+8][0]=7;
  		 a[3+8][0]=43;
  		 a[4+8][0]=22;
  		 a[5+8][0]=97;
  		 a[6+8][0]=3;
  		 a[7+8][0]=46;
  		a[16+0][0]=6;

  		 a[1][1]=2;
  		 a[2][1]=52;
  		 a[3][1]=68;
  		 a[4][1]=80;
  		 a[5][1]=67;
  		 a[6][1]=5;
  		 a[7][1]=91;
  		 a[0+8][1]=21;
  		 a[1+8][1]=1;
  		 a[2+8][1]=17;
  		 a[3+8][1]=4;
  		 a[4+8][1]=20;
  		 a[5+8][1]=70;
  		 a[6+8][1]=30;
  		 a[7+8][1]=64;
  		 a[16][1]=28;
  		 a[0][1]=12;
  		 		 a[0][2]=2;
  				 a[1][2]=23;
  				 a[2][2]=73;
  				 a[3][2]=6;
  				 a[4][2]=22;
  				 a[5][2]=65;
  				 a[6][2]=105;
  				 a[7][2]=40;
  				 a[0+8][2]=1;
  				 a[1+8][2]=142;
  				 a[2+8][2]=70;
  				 a[3+8][2]=13;
  				 a[4+8][2]=2;
  				 a[5+8][2]=79;
  				 a[6+8][2]=31;
  				 a[7+8][2]=45;
  				a[16+0][2]=61;

  				 a[0][3]=12;
  				 a[1][3]=3;
  				 a[2][3]=51;
  				 a[3][3]=6;
  				 a[4][3]=82;
  				 a[5][3]=67;
  				 a[6][3]=5;
  				 a[7][3]=109;
  				 a[0+8][3]=201;
  				 a[1+8][3]=11;
  				 a[2+8][3]=107;
  				 a[3+8][3]=40;
  				 a[4+8][3]=24;
  				 a[5+8][3]=0;
  				 a[6+8][3]=33;
  				 a[7+8][3]=44;
  				 a[16][3]=1;
  if(getECAL_ClustersInCard(crystals, peakEta, peakPhi, largeClusterET, smallClusterET,sortedCluster_ET,sortedPeak_Eta,TowerPeak_Eta, TowerPeak_Phi,a,sortedPeak_Phi)) {
    cout << "From the simulation: " << endl;
    cout << "tEta\ttPhi\tpeakEta\tpeakPhi\tlargeClusterET\tsmallClusterET\t" << endl;
    for(int tEta = 0; tEta < 17; tEta++) {
      for(int tPhi = 0; tPhi < 4; tPhi++) {
        if(largeClusterET[tEta][tPhi] > 0) 
          cout << tEta
               << "\t" << tPhi
               << "\t" << peakEta[tEta][tPhi]
               << "\t" << peakPhi[tEta][tPhi]
               << "\t" << largeClusterET[tEta][tPhi]
               << "\t" << smallClusterET[tEta][tPhi]
         <<"\t"<<endl;
        totalCardET += largeClusterET[tEta][tPhi];
      }
    }
    cout << "Total card ET = " << totalCardET << endl;
  }
  else {
    cout << "ClusterFinder failed" << endl;
    //cout << "Hi dinho"
    return 1;
  }
  // uint16_t cEta[30];
  //  uint16_t cPhi[30];
  //  HCAL_TowerPeaks(a,cPhi,cEta);
  //    cout<<"Eta"
  //              << "\t" <<  "Phi" << "\t" <<  "ET" << endl;
  //         for(uint16_t i=0;i<30;i++)
  //       {
  //         cout << cEta[i]
  //              << "\t" <<  cPhi[i] <<"\t"<<  a[cEta[i]][cPhi[i]] << endl;
        
  //       }
    



    
     
  return 0;
}
