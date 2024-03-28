#include "CppUnitTest.h"

#include "1337. The K Weakest Rows in a Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My1337TheKWeakestRowsinaMatrix
{
	TEST_CLASS(My1337TheKWeakestRowsinaMatrix) {
public:

	TEST_METHOD(TestMethod1) {
		//Input: mat =
		// [[1, 1, 0, 0, 0],
		//	[1, 1, 1, 1, 0],
		//	[1, 0, 0, 0, 0],
		//	[1, 1, 0, 0, 0],
		//	[1, 1, 1, 1, 1]],
		//	k = 3
		//	Output: [2, 0, 3]
		//	Explanation :
		//	The number of soldiers in each row is :
		//-Row 0 : 2
		//	- Row 1 : 4
		//	- Row 2 : 1
		//	- Row 3 : 2
		//	- Row 4 : 5
		//	The rows ordered from weakest to strongest are[2, 0, 3, 1, 4].

		const int rows = 5, cols = 5;

		int mat_t[rows][cols] = { {1, 1, 0, 0, 0},
			{1, 1, 1, 1, 0},
			{1, 0, 0, 0, 0},
			{1, 1, 0, 0, 0},
			{1, 1, 1, 1, 1} };

		int** mat = (int**)malloc(rows * sizeof(int*));
		for (int i = 0; i < rows; i++) {
			mat[i] = (int*)malloc(cols * sizeof(int));
			for (int j = 0; j < cols; j++) {
				mat[i][j] = mat_t[i][j];
			}
		}

		const int k = 3;
		int ans[k] = { 2,0,3 };
		int tempCols = cols;
		int returnSize;
		int* res = kWeakestRows(mat, rows, &tempCols, k, &returnSize);

		for (int i = 0; i < k; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}
		free(res);
	}

	TEST_METHOD(TestMethod2) {
		//Input: mat =
		// [[1, 0, 0, 0],
		//	[1, 1, 1, 1],
		//	[1, 0, 0, 0],
		//	[1, 0, 0, 0]],
		//	k = 2
		//	Output : [0, 2]
		//	Explanation :
		//	The number of soldiers in each row is :
		//-Row 0 : 1
		//	- Row 1 : 4
		//	- Row 2 : 1
		//	- Row 3 : 1
		//	The rows ordered from weakest to strongest are[0, 2, 3, 1].

		const int rows = 4, cols = 4;

		int mat_t[rows][cols] = { {1, 0, 0, 0},
			{1, 1, 1, 1},
			{1, 0, 0, 0},
			{1, 0, 0, 0} };

		int** mat = (int**)malloc(rows * sizeof(int*));
		for (int i = 0; i < rows; i++) {
			mat[i] = (int*)malloc(cols * sizeof(int));
			for (int j = 0; j < cols; j++) {
				mat[i][j] = mat_t[i][j];
			}
		}

		const int k = 2;
		int ans[k] = { 0, 2 };
		int tempCols = cols;
		int returnSize;
		int* res = kWeakestRows(mat, rows, &tempCols, k, &returnSize);

		for (int i = 0; i < k; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}
		free(res);
	}

	TEST_METHOD(TestMethod3) {
		//Input: mat =
		// [[1, 1, 1, 1, 1, 1],
		//  [1, 1, 1, 1, 1, 1],
		//	[1, 1, 1, 1, 1, 1]]
		//	k = 1
		//	Output : [0]

		const int rows = 3, cols = 6;

		int mat_t[rows][cols] = { {1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1} };

		int** mat = (int**)malloc(rows * sizeof(int*));
		for (int i = 0; i < rows; i++) {
			mat[i] = (int*)malloc(cols * sizeof(int));
			for (int j = 0; j < cols; j++) {
				mat[i][j] = mat_t[i][j];
			}
		}

		const int k = 1;
		int ans[k] = { 0 };
		int tempCols = cols;
		int returnSize;
		int* res = kWeakestRows(mat, rows, &tempCols, k, &returnSize);

		for (int i = 0; i < k; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}
		free(res);
	}

	TEST_METHOD(TestMethod4) {
		//Input: mat =
		// [[1, 0],
		//	[1, 0],
		//	[1, 0],
		//	[1, 1]]
		//	k = 4
		//	Output : [0,1,2,3]

		const int rows = 4, cols = 2;

		int mat_t[rows][cols] = { {1, 0},
			{1, 0},
			{1, 0},
			{1, 1} };

		int** mat = (int**)malloc(rows * sizeof(int*));
		for (int i = 0; i < rows; i++) {
			mat[i] = (int*)malloc(cols * sizeof(int));
			for (int j = 0; j < cols; j++) {
				mat[i][j] = mat_t[i][j];
			}
		}

		const int k = 4;
		int ans[4] = { 0,1,2,3 };
		int tempCols = cols;
		int returnSize;
		int* res = kWeakestRows(mat, rows, &tempCols, k, &returnSize);

		for (int i = 0; i < k; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}
		free(res);
	}

	TEST_METHOD(TestMethod5) {
		//Input: mat =
		// [[0, 0],
		//	[0, 0],
		//	[0, 0],
		//	[0, 0]]
		//	k = 4
		//	Output : [0,1,2,3]

		const int rows = 4, cols = 2;

		int mat_t[rows][cols] = { {0, 0},
			{0, 0},
			{0, 0},
			{0, 0} };

		int** mat = (int**)malloc(rows * sizeof(int*));
		for (int i = 0; i < rows; i++) {
			mat[i] = (int*)malloc(cols * sizeof(int));
			for (int j = 0; j < cols; j++) {
				mat[i][j] = mat_t[i][j];
			}
		}

		const int k = 4;
		int ans[4] = { 0,1,2,3 };
		int tempCols = cols;
		int returnSize;
		int* res = kWeakestRows(mat, rows, &tempCols, k, &returnSize);

		for (int i = 0; i < k; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}
		free(res);
	}

	TEST_METHOD(TestMethod6) {
		//Input: mat =
		// [[1, 1],
		//	[1, 1],
		//	[1, 1],
		//	[1, 1]]
		//	k = 4
		//	Output : [0,1,2,3]

		const int rows = 4, cols = 2;

		int mat_t[rows][cols] = { {1, 1},
			{1, 1},
			{1, 1},
			{1, 1} };

		int** mat = (int**)malloc(rows * sizeof(int*));
		for (int i = 0; i < rows; i++) {
			mat[i] = (int*)malloc(cols * sizeof(int));
			for (int j = 0; j < cols; j++) {
				mat[i][j] = mat_t[i][j];
			}
		}

		const int k = 4;
		int ans[4] = { 0,1,2,3 };
		int tempCols = cols;
		int returnSize;
		int* res = kWeakestRows(mat, rows, &tempCols, k, &returnSize);

		for (int i = 0; i < k; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}
		free(res);
	}

	TEST_METHOD(TestMethod7) {
		//Input: mat =
		//[[1, 1, 1, 0, 0, 0, 0],
		// [1, 1, 1, 1, 1, 1, 0],
		// [0, 0, 0, 0, 0, 0, 0],
		// [1, 1, 1, 0, 0, 0, 0],
		// [1, 1, 1, 1, 1, 1, 1]]
		//	k = 4
		//	Output : [2,0,3,1]

		const int rows = 5, cols = 7;

		int mat_t[rows][cols] = { {1, 1, 1, 0, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{1, 1, 1, 0, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 1} };

		int** mat = (int**)malloc(rows * sizeof(int*));
		for (int i = 0; i < rows; i++) {
			mat[i] = (int*)malloc(cols * sizeof(int));
			for (int j = 0; j < cols; j++) {
				mat[i][j] = mat_t[i][j];
			}
		}

		const int k = 4;
		int ans[4] = { 2,0,3,1 };
		int tempCols = cols;
		int returnSize;
		int* res = kWeakestRows(mat, rows, &tempCols, k, &returnSize);

		for (int i = 0; i < k; i++) {
			Assert::AreEqual(ans[i], res[i]);
		}
		free(res);
	}
	};
}
