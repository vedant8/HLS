#include"bitonic.h"

// #include <iostream>

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;



int main ()
{
// 	 uint16_t a[32];
// 	 uint16_t cEta[32];
// 	 uint16_t cPhi[32];
// 	 uint16_t tEta[32];
// 	 uint16_t tPhi[32];
// 	 for (int i=0; i<32;i++)
// 	 {
// 	 	cEta[i]=0;
// 	 	cPhi[i]=0;
// 	 	tEta[i]=0;
// 	 	tPhi[i]=0;
// 	 }
// 		 a[0]=16;
// 		 a[1]=24;
// 		 a[2]=72;
// 		 a[3]=6;
// 		 a[4]=28;
// 		 a[5]=67;
// 		 a[6]=53;
// 		 a[7]=49;
// 		 a[0+8]=12;
// 		 a[1+8]=14;
// 		 a[2+8]=7;
// 		 a[3+8]=43;
// 		 a[4+8]=22;
// 		 a[5+8]=97;
// 		 a[6+8]=3;
// 		 a[7+8]=46;
// 		 a[16]=19;
// 		 a[16+1]=26;
// 		 a[16+2]=73;
// 		 a[16+3]=62;
// 		 a[16+4]=29;
// 		 a[16+5]=65;
// 		 a[16+6]=52;
// 		 a[16+7]=50;
// 		 a[16+0+8]=21;
// 		 a[16+1+8]=10;
// 		 a[16+2+8]=73;
// 		 a[16+3+8]=37;
// 		 a[16+4+8]=202;
// 		 a[16+5+8]=91;
// 		 a[16+6+8]=37;
// 		 a[16+7+8]=4;
		

// 		 // TowerPeaks(a,cPhi,cEta,tPhi,tEta);
// 		 cout<<"Eta"
//                << "\t" <<  "Phi" << "\t" <<  "ET" << endl;
// 		 			for(uint16_t i=0;i<32;i++)
// 				{
// 					cout << cEta[i]
//                << "\t" <<  cPhi[i] <<"\t"<<  a[i] << endl;
				
// 				}
		



		
// 			return 0;
// }
	ap_uint<192> link_in[48];
ap_uint<192> link_out[48];
string ifname("G:/Physics/Particle_Physics/HLS/Projects/bitonic/bitonic_input.txt"); // input test vector
//	string ifname("input.txt"); // input test vector
	string ofname("G:/Physics/Particle_Physics/HLS/sorter_out.txt"); // output test vector
	string orfname("G:/Physics/Particle_Physics/HLS/sorter_out_ref.txt"); // reference output vector
// Open input stream...
	ifstream ifs(ifname.c_str());
	if (!ifs.is_open()) {
		cerr << "Error opening input file: " << ifname << endl;
		exit(1);
	}
// Open output stream and write a header
	ofstream ofs(ofname.c_str());
	if (!ofs.is_open()) {
		cerr << "Error opening output file: " << ofname << endl;
		exit(1);
	}
	// Open output reference stream...
	ifstream orfs(orfname.c_str());
	if (!orfs.is_open()) {
		cerr << "Error opening output reference file: " << orfname << endl;
		exit(1);
	}

	//...and position at the beginning of input test data
	string line;
	while (true) {
		ifs >> line;
		if (line.compare("#BeginData") == 0)
			break;
	}

	// /
	uint32_t wordCnt = 0;

	uint64_t data[48];

	ofs << "=====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================" << endl;
	ofs << "WordCnt             LINK_00               LINK_01               LINK_02               LINK_03               LINK_04               LINK_05               LINK_06               LINK_07               LINK_08               LINK_09               LINK_10               LINK_11               LINK_12               LINK_13               LINK_14               LINK_15               LINK_16               LINK_17               LINK_18               LINK_19               LINK_20               LINK_21               LINK_22               LINK_23               LINK_24               LINK_25               LINK_26               LINK_27               LINK_28               LINK_29               LINK_30               LINK_31               LINK_32               LINK_33               LINK_34               LINK_35               LINK_36               LINK_37               LINK_38               LINK_39               LINK_40               LINK_41               LINK_42               LINK_43               LINK_44               LINK_45               LINK_46               LINK_47" << endl;
	ofs << "#BeginData" << endl;
	// while (!ifs.eof()) {
		for (int cyc = 0; cyc < 3; cyc++) {
			ifs >> hex >> wordCnt;
			if  (ifs.eof())
				break;

			for (int link = 0; link < 48; link++)
			{
				uint64_t tmp;
				ifs >> hex >> tmp;
				if (cyc == 0) {
					link_in[link].range(63, 0) = tmp;
					// if (tmp!=0) cout<<"link:"<<link<<" "<<link_in[link].range(63, 48)<<" "<<link_in[link].range(47, 32)<<" "<<link_in[link].range(31, 16)<<" "<<link_in[link].range(15, 0)<<" "<<" cyc0 "<<endl;
				}
				else if (cyc == 1) {
					link_in[link].range(127, 64) = tmp;
					// if (tmp!=0) cout<<"link:"<<link<<" "<<link_in[link].range(127, 112)<<" "<<link_in[link].range(111, 96)<<" "<<link_in[link].range(95, 80)<<" "<<link_in[link].range(79, 64)<<" "<<" cyc1 "<<endl;
				}
				else {
					link_in[link].range(191, 128) = tmp;
					// if (tmp!=0) cout<<"link:"<<link<<" "<<link_in[link].range(191, 176)<<" "<<link_in[link].range(175, 160)<<" "<<link_in[link].range(159, 144)<<" "<<link_in[link].range(143, 128)<<" "<<" cyc2 "<<endl;
				}

			}
		}

		// if  (ifs.eof())
		// 	break;

	// }

	for (uint16_t i = 1; i <12; i++) {
cout<<link_in[0].range(16*i+15,16*i)<< " ";
}
cout<<endl;

	
	for (uint16_t i = 1; i <12; i++) {
cout<<link_in[1].range(16*i+15,16*i)<< " ";
}
cout<<endl;

	for (uint16_t i = 1; i <11; i++) {
cout<<link_in[2].range(16*i+15,16*i)<< " ";
}
cout<<endl;


	cout<<"data Collection"<<endl;
		TowerPeaks(link_in, link_out);

		wordCnt-=2;
for (int link = 0; link < 48; link++) {
		ofs << "0x" << setfill('0') << setw(16) << hex << link_out[link].range(15,0).to_int64() << "    ";
				// cout<<link_out[link].range(15,0)<<" "<<endl;
	
		}
	ofs<< std::endl;
	string output_diff("diff -c " + ofname + " " + orfname);

	if (system(output_diff.c_str())) {
		cout << "*** Output data verification. FAILED! ***" << endl;
		return 0;
	} else {
		cout << "*** Output data verification. PASSED ***" << endl;
		return 0;
	}
}
