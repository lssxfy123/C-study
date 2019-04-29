// Copyright 2019.���|�|
// author�����|�|
// ͳ��0-n�У�k��0-9�����ֵĴ���
// ��ע��ֻ�������һ��
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
			//	result += 1;  // ��λ��>k
			//}

			if (digit > k)
			{
				if (digits.size() > 0)
				{
					result += pow(10, digits.size());
				}
				else
				{
					result += 1;  // ��λ��>k
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
				result += 1;  // ��λ��>=k
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

// ���²ο���
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
		// ����һ������ABCD��
		// digitΪÿ��λ�ϵ����֣��ֱ�Ϊ��D, C, B, A
		int digit = tmp % 10;

		// numberΪÿ��λ��������֣��ֱ�Ϊ��D, CD, BCD(�����λ����0)
		int number = n % m;

		// ����Ƕ�λ���֣�����ָ��k�ļ������
		// ��ʮλ��ʼ������ָ��k�ĸ���ΪC * 1 * 10^0
		// ��λ��B * 2 * 10^1
		// ǧλ��A * 3 * 10^2
		// ԭ����ÿ10�����ֿ϶�����k����λ���ֻ�������k��ͷ��10������
		// ǧλ���֣�������k��ͷ��100�����֣�����kΪʮλ��100������
		// ��������
		if (digits.size() > 0)
		{
			// ����m����100������Ϊ���digits.size() > 0
			// m��СҲ��100��ddigits.size()=1,m=100����ʾʮλ
			result += digit * digits.size() * m / 100;
		}
		else
		{
			// ��λ��>=k
			if (digit >= k)
			{
				result += 1; 
			}
		}

		// ���λ������k��k��Ϊ0
		// digits.size()����λ��
		// ��Ҫ��������10^digits.size()
		// ʮλ������10^1
		// ��λ������10^2
		// ԭ���ǻ�����k��ͷ��ʮ����ٸ�����
		// �����������ƣ��ų�0�����ڣ�û����0��ʼ����
		if (digit > k && k > 0)
		{
			if (digits.size() > 0)
			{
				result += m / 10;
			}
		}
		else if (digit == k)
		{
			// ���digit == k����Ҳ���������һ��������
			// ����Ϊ����������+1
			// ����152�а���1�����֣�����Ҫ+53
			if (digits.size() > 0)
			{
				result += digits.back() + 1;

				// ���digit��k��Ϊ0������Ҫ��ȥ10^digits.size()
				// ԭ�����ڼ�����һ��λ��ʱ��������10^digits.size()
				// ��Ϊû�����λ��0��ͷ�����֣������������ȼ�ȥ
				// ���digit��Ϊ0������Ҫ��ȥ����Ϊ����0��Ϊ��λ������
				// ��:k = 0, n = 105�������λ1ʱ��result+=20����û����0��ͷ��ʮλ��
				// k - 0, n = 115�������λ1ʱ��result+=20������0Ϊʮλ���İ�λ��
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
