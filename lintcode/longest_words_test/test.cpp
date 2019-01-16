// Copyright 2019.刘珅珅
// author：刘珅珅
// 最长单词或单词集合
// 备注：只允许遍历一次
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<string> longestWords(vector<string> &dictionary) {
	// write your code here
	vector<string> result;
	if (dictionary.size() == 0)
	{
		return result;
	}
	result.push_back(dictionary[0]);
	for (int i = 1; i < dictionary.size(); ++i)
	{
		if (dictionary[i].length() > result.back().length())
		{
			result.clear();
			result.push_back(dictionary[i]);
		}
		else if (dictionary[i].length() == result.back().length())
		{
			result.push_back(dictionary[i]);
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	vector<string> vec{ "dog","google","facebook","internationalization","blabla"};
	vector<string> vec1 {"dogweq","google","facebo","blabla" };

	vector<string> result = longestWords(vec);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}

	vector<string> result1 = longestWords(vec1);

	for (int i = 0; i < result1.size(); ++i)
	{
		cout << result1[i] << endl;
	}

	return 0;
}
