#include "pch.h"

#include "900. RLE Iterator.h"

using namespace std;

RLEIterator::RLEIterator(vector<int>& encoding) {
	arr_enc = encoding;
}

int RLEIterator::next(int n) {
	while((arr_enc.size() > 0) && (*arr_enc.begin() < n)) {
		n -= *arr_enc.begin();
		arr_enc.erase(arr_enc.begin(), arr_enc.begin() + 2);
	}
	if (arr_enc.size() == 0) {
		return -1;
	};
	*arr_enc.begin() -= n;
	return *(arr_enc.begin() + 1);
}
