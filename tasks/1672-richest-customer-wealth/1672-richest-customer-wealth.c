#include "1672-richest-customer-wealth.h"

short maximumWealth(int **accounts, int accountsSize, int *accountsColSize) {
	short maxWealth = 0;
	for (char i = 0; i < accountsSize; i++) {
		short currWealth = 0;
		for (char j = 0; j < accountsColSize[i]; j++) {
			currWealth += accounts[i][j];
		}
		maxWealth = (currWealth > maxWealth) ? currWealth : maxWealth;
	}
    return maxWealth;
}