#include "1672-richest-customer-wealth.h"

int maximumWealth(int** accounts, const int accountsSize, const int banksSize) {
	short maxWealth = 0;
	for (char i = 0; i < accountsSize; i++) {
		short currWealth = 0;
		for (char j = 0; j < banksSize; j++) {
			currWealth += accounts[i][j];
		}
		maxWealth = (currWealth > maxWealth) ? currWealth : maxWealth;
	}
	return maxWealth;
}