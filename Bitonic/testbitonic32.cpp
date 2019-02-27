#include"bitonic.h"

#include <iostream>
using namespace std;
int main ()
{
	 uint16_t a[32];
	 uint16_t cEta[32];
	 uint16_t cPhi[32];
	 uint16_t tEta[32];
	 uint16_t tPhi[32];
	 for (int i=0; i<32;i++)
	 {
	 	cEta[i]=0;
	 	cPhi[i]=0;
	 	tEta[i]=0;
	 	tPhi[i]=0;
	 }
		 a[0]=16;
		 a[1]=24;
		 a[2]=72;
		 a[3]=6;
		 a[4]=28;
		 a[5]=67;
		 a[6]=53;
		 a[7]=49;
		 a[0+8]=12;
		 a[1+8]=14;
		 a[2+8]=7;
		 a[3+8]=43;
		 a[4+8]=22;
		 a[5+8]=97;
		 a[6+8]=3;
		 a[7+8]=46;
		 a[16]=19;
		 a[16+1]=26;
		 a[16+2]=73;
		 a[16+3]=62;
		 a[16+4]=29;
		 a[16+5]=65;
		 a[16+6]=52;
		 a[16+7]=50;
		 a[16+0+8]=21;
		 a[16+1+8]=10;
		 a[16+2+8]=73;
		 a[16+3+8]=37;
		 a[16+4+8]=202;
		 a[16+5+8]=91;
		 a[16+6+8]=37;
		 a[16+7+8]=4;
		

		 TowerPeaks(a,cPhi,cEta,tPhi,tEta);
		 cout<<"Eta"
               << "\t" <<  "Phi" << "\t" <<  "ET" << endl;
		 			for(uint16_t i=0;i<32;i++)
				{
					cout << cEta[i]
               << "\t" <<  cPhi[i] <<"\t"<<  a[i] << endl;
				
				}
		



		
			return 0;
}
