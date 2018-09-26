// Copyright 2018.���|�|
// author�����|�|
// ��Ԫ�ز��ң����ֵĴ����ϸ��������Ԫ�صĶ���֮1
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int majorityNumber(vector<int> &nums) {
    // write your code here
    int majorty_number = nums[0];
    int count = 1;

    // ���ҵ�ǰ��������Ԫ��
    // Ĭ��nums�д�����Ԫ�أ�����
    // �������ľ�����Ԫ��
    for (int i = 1; i < nums.size(); ++i)
    {
        count += nums[i] == majorty_number ? 1 : -1;
        if (count == 0)  // countΪ0��ʾ0-i��Χ�ڣ���Ԫ�ز�Ϊ��Ԫ��
        {
            majorty_number = nums[i];
            count = 1;
        }
    }
    return majorty_number;
}

int main(int argc, char* argv[])
{
    vector<int> nums{1, 3, 5, 6, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1 };
    cout << majorityNumber(nums) << endl;
    return 0;
}
