#include <stdio.h>
#include "1672-richest-customer-wealth.h"

#define ACCOUNTS 2
#define BANKS 3

void main() {
	char accounts_num = ACCOUNTS;
	char banks_num[] = {BANKS, BANKS};
	char accounts_arr[ACCOUNTS][BANKS] = {{1, 2, 3}, {3, 2, 1}};

	char **accounts;
	accounts = malloc(accounts_num * sizeof(char));

	for (int i = 0; i < accounts_num; i++) {
		accounts[i] = malloc(banks_num[i] * sizeof(char));
	}

	for (int i = 0; i < accounts_num; i++) {
		for (int j = 0; j < banks_num[i]; j++) {
			accounts[i][j] = accounts_arr[i][j];
		}
	}

	printf("Max Wealth = %d", maximumWealth(accounts, accounts_num, banks_num));
}