#include "CppUnitTest.h"

#include"1672-richest-customer-wealth.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My1672Richestcustomerwealth
{
	TEST_CLASS(My1672Richestcustomerwealth) {

public:

	TEST_METHOD(TestMethod1) {

		const int accounts_num = 2;
		const int banks_num = 3;
		int accounts_arr[accounts_num][banks_num] = { {1, 2, 3}, {3, 2, 1} };
		const int ans = 6;

		int** accounts;
		accounts = (int**)malloc(accounts_num * sizeof(int*));

		for (int i = 0; i < accounts_num; i++) {
			accounts[i] = (int*)malloc(banks_num * sizeof(int));
		}

		for (int i = 0; i < accounts_num; i++) {
			for (int j = 0; j < banks_num; j++) {
				accounts[i][j] = accounts_arr[i][j];
			}
		}

		Assert::AreEqual(ans, maximumWealth(accounts, accounts_num, banks_num));

		for (int i = 0; i < accounts_num; i++) {
			free(accounts[i]);
		}
		free(accounts);
	} // namespace My1672Richestcustomerwealth
	};
}
