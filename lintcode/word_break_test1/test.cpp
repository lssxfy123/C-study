// Copyright 2019.���|�|
// author�����|�|
// ���ʲ�� I
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

		// dp[i]��ʾǰi���ַ����Ƿ�ɷ�
		// ֻҪ�ַ������Բ�֣���ʹ��ֳ�n��
		// ���ǿ��Կ�����ǰn-1�ζ�Ӧ���ַ��ɲ��
		// Ȼ���ǵ�n�ζ�Ӧ���ַ��ɲ��
		// ����s="abcdefg"����dict�п��Բ��Ϊab,cd,efg��3��
		// ��dp[2]=true����ǰ2���ַ��ɲ��
		// dp[3]=false��ǰ3���ַ����ɲ��
		// dp[4]=true��dp[7]=true
		// �ܹ�7���ַ����Կ���ǰ4���ַ��ɲ�֣���3���ַ��ɲ��
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		int max_length = getMaxLength(dict);
		for (int i = 1; i <= s.length(); ++i)
		{
			// ֮���Լ���max_length��Ϊ�˼����ж�
			// ���ڲ�forѭ��Ҫ�жϳ���Ϊj���ַ����Ƿ������dict
			// ���j����max_length����û�б�Ҫ�ж���
			for (int j = 1; j <= i && j <= max_length; ++j)
			{
				// dp[i-j]��ʾǰi���ַ���ǰi-j���ַ��Ƿ�ɲ��
				// ���ǰi-j���ַ����ɲ�֣���û�б�Ҫ�ж�
				// ǰi���ַ��ĺ�j���ַ��Ƿ�ɲ����
				if (!dp[i - j])
				{
					continue;
				}

				// ǰi���ַ��ĺ�j���ַ�
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
