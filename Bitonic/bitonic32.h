#include<stdio.h>
#include<math.h>
#include <stdint.h>
#include <ap_fixed.h>


// void getTowerPeaks3x4(uint16_t towerETRegions[3][4],uint16_t cEta[5],
                        // uint16_t cPhi[5],uint16_t ClusterDeposits[32], uint16_t ClusterEta[32], uint16_t ClusterPhi[32]);
void TowerPeaks(uint16_t towerET[32], uint16_t PeakPhi[32], uint16_t PeakEta[32],uint16_t TowerPhi[32], uint16_t TowerEta[32]);	 