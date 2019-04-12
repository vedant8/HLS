#include<stdio.h>
#include<math.h>
#include <stdint.h>
#include <ap_fixed.h>
#include <ap_int.h>

// void getTowerPeaks3x4(uint16_t towerETRegions[3][4],uint16_t cEta[5],
                        // uint16_t cPhi[5],uint16_t ClusterDeposits[32], uint16_t ClusterEta[32], uint16_t ClusterPhi[32]);
// void TowerPeaks(uint16_t towerET[16], uint16_t PeakPhi[16], uint16_t PeakEta[16],uint16_t TowerPhi[16], uint16_t TowerEta[16]);	
void TowerPeaks(ap_uint<192> link_in[48], ap_uint<192> link_out[48])  ;