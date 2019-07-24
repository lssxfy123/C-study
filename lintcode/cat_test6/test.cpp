// Copyright 2019.Áõ«|«|
// author£ºÁõ«|«|
// 
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

string depress(int m, int k, vector<int> &arr) {
	// Write your code here.
	if (arr.size() < k)
	{
		return "no";
	}

	sort(arr.begin(), arr.end());
	int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		sum += arr[i];
	}

	if (sum >= m)
	{
		return "no";
	}
	return "yes";
}

int main(int argc, char* argv[])
{
	return 0;
}
