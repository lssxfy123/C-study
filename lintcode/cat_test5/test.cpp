// Copyright 2019.Áõ«|«|
// author£ºÁõ«|«|
// 846. ¶à¹Ø¼ü×ÖÅÅÐò
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<vector<int>> multiSort(vector<vector<int>> &array) {
	// Write your code here
	vector<vector<int>> result;

	sort(array.begin(), array.end(), [](vector<int>& a, vector<int>& b) ->bool {
		if (a[1] > b[1])
		{
			return true;
		}

		if (a[1] == b[1])
		{
			return a[0] < b[0];
		}
	});
	return array;
}

int main(int argc, char* argv[])
{
	return 0;
}
