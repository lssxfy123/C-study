// Copyright 2019.刘珅珅
// author：刘珅珅
// 单词拆分 I
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
	/*
	 * @param s: A string
	 * @param dict: A dictionary of words dict
	 * @return: A boolean
	 */
	int getMaxLength(unordered_set<string> &dict)
	{
		int max_length = 0;
		for (auto itor = dict.begin(); itor != dict.end(); ++itor)
		{
			max_length = max_length > (*itor).length() ? max_length : (*itor).length();
		}
		return max_length;
	}

	bool wordBreak(string &s, unordered_set<string> &dict) {
		// write your code here
		if (s == "" && dict.empty())
		{
			return true;
		}

		if (s == "" || dict.empty())
		{
			return false;
		}

		// dp[i]表示前i个字符串是否可分
		// 只要字符串可以拆分，即使拆分成n段
		// 总是可以看成是前n-1段对应的字符可拆分
		// 然后是第n段对应的字符可拆分
		// 例：s="abcdefg"，在dict中可以拆分为ab,cd,efg共3段
		// 则dp[2]=true，即前2个字符可拆分
		// dp[3]=false，前3个字符不可拆分
		// dp[4]=true，dp[7]=true
		// 总共7个字符可以看成前4个字符可拆分，后3个字符可拆分
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		int max_length = getMaxLength(dict);
		for (int i = 1; i <= s.length(); ++i)
		{
			// 之所以计算max_length是为了减少判断
			// 在内层for循环要判断长度为j的字符串是否存在于dict
			// 如果j大于max_length，就没有必要判断了
			for (int j = 1; j <= i && j <= max_length; ++j)
			{
				// dp[i-j]表示前i个字符中前i-j个字符是否可拆分
				// 如果前i-j个字符不可拆分，就没有必要判断
				// 前i个字符的后j个字符是否可拆分了
				if (!dp[i - j])
				{
					continue;
				}

				// 前i个字符的后j个字符
				string tmp = s.substr(i - j, j);
				if (dict.find(tmp) != dict.end())
				{
					dp[i] = true;
					break;
				}
			}
		}

		return dp[s.length()];
	}
};

int main(int argc, char* argv[])
{
	return 0;
}
