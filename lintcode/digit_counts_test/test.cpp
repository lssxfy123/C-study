// Copyright 2019.刘珅珅
// author：刘珅珅
// 统计0-n中，k（0-9）出现的次数
// 备注：只允许遍历一次
#include <iostream>
#include <cmath>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int digitCounts1(int k, int n) {
	// write your code here
	int result = 0;
	if (n < 0 || k < 0 || k > n)
	{
		return result;
	}

	if (k == 0 && n == 0)
	{
		return 1;
	}

	vector<int> digits;
	int m = 10;
	int tmp = n;
	if (k > 0)
	{
		while (tmp != 0)
		{
			int digit = tmp % 10;
			int number = n % m;
			if (digits.size() > 0)
			{
				result += digit * digits.size() * pow(10, digits.size() - 1);
			}
			//else
			//{
			//	result += 1;  // 个位数>k
			//}

			if (digit > k)
			{
				if (digits.size() > 0)
				{
					result += pow(10, digits.size());
				}
				else
				{
					result += 1;  // 个位数>k
				}
			}
			else if (digit == k)
			{
				if (digits.size() > 0)
				{
					result += digits.back() + 1;
				}
				else
				{
					result += 1;
				}
			}

			tmp = tmp / 10;
			digits.push_back(number);
			m *= 10;
		}
	}
	else
	{
		while (tmp != 0)
		{
			int digit = tmp % 10;
			int number = n % m;
			if (digits.size() > 0)
			{
				result += digit * (digits.size()) * pow(10, digits.size() - 1);
			}
			else
			{
				result += 1;
			}

			if (digit > k)
			{
			}
			else if (digit == k)
			{
				if (digits.size() > 0)
				{
					result += digits.back() + 1;
				}
				
				if (digits.size() > 0)
				{
					if (digit == 0)
					{
						result -= pow(10, digits.size());
					}
				}
			}

			tmp = tmp / 10;
			digits.push_back(number);
			m *= 10;
		}
	}

	return result;
}

int digitCounts2(int k, int n) {
	// write your code here
	int result = 0;
	if (n < 0 || k < 0 || k > n)
	{
		return result;
	}

	if (k == 0 && n == 0)
	{
		return 1;
	}

	vector<int> digits;
	int m = 10;
	int tmp = n;
	while (tmp != 0)
	{
		int digit = tmp % 10;
		int number = n % m;
		if (digits.size() > 0)
		{
			result += digit * digits.size() * pow(10, digits.size() - 1);
		}
		else
		{
			if (digit >= k)
			{
				result += 1;  // 个位数>=k
			}
		}

		if (digit > k && k > 0)
		{
			if (digits.size() > 0)
			{
				result +=  pow(10, digits.size());
			}
		}
		else if (digit == k)
		{
			if (digits.size() > 0)
			{
				result += digits.back() + 1;
				if (digit == 0 && k == 0)
				{
					result -=  pow(10, digits.size());
				}
			}
		}

		tmp = tmp / 10;
		digits.push_back(number);
		m *= 10;
	}

	return result;
}

// 九章参考答案
int digitCounts3(int k, int n) {
	int count = 0;
	if (k == 0) {
		count = 1;
	}
	for (int i = 1; i <= n; i++) {
		int number = i;
		while (number > 0) {
			if (number % 10 == k) {
				count += 1;
			}
			number /= 10;
		}
	}

	return count;
}

int digitCounts(int k, int n) {
	// write your code here
	int result = 0;
	if (n < 0 || k < 0 || k > n)
	{
		return result;
	}

	if (k == 0 && n == 0)
	{
		return 1;
	}

	vector<int> digits;
	int m = 10;
	int tmp = n;
	while (tmp != 0)
	{
		// 对于一个数字ABCD，
		// digit为每个位上的数字，分别为：D, C, B, A
		int digit = tmp % 10;

		// number为每个位后面的数字，分别为：D, CD, BCD(如果高位不是0)
		int number = n % m;

		// 如果是多位数字，包含指定k的计算规则：
		// 从十位开始，包含指定k的个数为C * 1 * 10^0
		// 百位：B * 2 * 10^1
		// 千位：A * 3 * 10^2
		// 原因是每10个数字肯定包含k，百位数字还包含以k开头的10个数字
		// 千位数字，包含以k开头的100个数字，和以k为十位的100个数字
		// 依次类推
		if (digits.size() > 0)
		{
			// 这里m除以100，是因为如果digits.size() > 0
			// m最小也是100，ddigits.size()=1,m=100，表示十位
			result += digit * digits.size() * m / 100;
		}
		else
		{
			// 个位数>=k
			if (digit >= k)
			{
				result += 1; 
			}
		}

		// 如果位数大于k且k不为0
		// digits.size()代表位数
		// 需要额外增加10^digits.size()
		// 十位：增加10^1
		// 百位：增加10^2
		// 原因是会有以k开头的十个或百个数字
		// 其它依次类推，排除0是由于，没有以0开始的数
		if (digit > k && k > 0)
		{
			if (digits.size() > 0)
			{
				result += m / 10;
			}
		}
		else if (digit == k)
		{
			// 如果digit == k，则也会额外增加一部分数字
			// 个数为其后面的数字+1
			// 例如152中包含1的数字，这里要+53
			if (digits.size() > 0)
			{
				result += digits.back() + 1;

				// 如果digit和k都为0，则需要减去10^digits.size()
				// 原因是在计算下一个位数时，会多计算10^digits.size()
				// 因为没有最高位以0开头的数字，所以在这里先减去
				// 如果digit不为0，则不需要减去，因为有以0作为该位的数字
				// 例:k = 0, n = 105，计算百位1时，result+=20，但没有以0开头的十位数
				// k - 0, n = 115，计算百位1时，result+=20，有以0为十位数的百位数
				if ( k == 0 && digit == 0)
				{
					result -= m / 10;
				}
			}
		}

		tmp = tmp / 10;
		digits.push_back(number);
		m *= 10;
	}

	return result;
}

int main(int argc, char* argv[])
{
	cout << digitCounts(1, 1) << endl;  // 1
	cout << digitCounts(2, 10) << endl;  // 1
	cout << digitCounts(2, 100) << endl;  // 20
	cout << digitCounts(2, 10000) << endl;  // 4000
	cout << digitCounts(4, 483) << endl;  // 182

	cout << digitCounts3(1, 1) << endl;  // 1
	cout << digitCounts3(2, 10) << endl;  // 1
	cout << digitCounts3(2, 100) << endl;  // 20
	cout << digitCounts3(2, 10000) << endl;  // 4000
	cout << digitCounts3(4, 483) << endl;  // 182

	cout << digitCounts(0, 19) << endl;  // 2
	cout << digitCounts(0, 100) << endl;  // 12
	cout << digitCounts(0, 105) << endl;  // 17
	cout << digitCounts(0, 135) << endl; // 24
	cout << digitCounts(0, 190) << endl;  // 30
	cout << digitCounts(0, 205) << endl;  // 17
	cout << digitCounts(0, 345) << endl;  // 65
	cout << digitCounts(0, 1000) << endl;  // 193
	cout << digitCounts(0, 1005) << endl;  // 203
	cout << digitCounts(0, 1900) << endl;  // 472
	cout << digitCounts(0, 2345) << endl;  // 665
	cout << digitCounts(0, 10000) << endl;  // 2894
	cout << digitCounts(0, 11292) << endl;  // 4350
	return 0;
}
