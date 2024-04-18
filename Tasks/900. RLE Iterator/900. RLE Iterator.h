#pragma once

#include <vector>

class RLEIterator {

	std::vector<int> arr_enc;

public:
	RLEIterator(std::vector<int>& encoding);
	int next(int n);
};


/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */