// Copyright 2017.刘珅珅
// author：刘珅珅
// 01背包-动态规划
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int* goods_weight = NULL;
int* goods_value = NULL;
int* goods_select = NULL;
int** max_value_array = NULL;
int calculate_count = 0;

int GetMaxValue(int weight, int count)
{
    int max_value = 0;

    // 如果这个问题计算过，取备忘录
    if (max_value_array[weight][count] != -1)
    {
        max_value = max_value_array[weight][count];
    } else if (count == 0)  // 动态规划的边界
    {
        // 背包剩余的容量大于物品的体积
        if (weight >= goods_weight[count])
        {
            max_value = goods_value[count];
        } else {  // 背包剩余的容量小于物品的体积
            max_value = 0;
        }
    } else if (weight >= goods_weight[count])  // 最优子结构
    {
        ++calculate_count;
        // 放入第count个物品所能获取的最大价值
        int max_value1 = GetMaxValue(weight - goods_weight[count], count - 1) + goods_value[count];

        // 不放入count个物品所能获取的最大价值
        int max_value2 = GetMaxValue(weight, count - 1);
        max_value = max(max_value1, max_value2);
    } else {
        ++calculate_count;
        // 背包的剩余容量小于第count个物品的体积
        // 肯定无法放入第count个物品
        max_value = GetMaxValue(weight, count - 1);
    }

    // 做备忘录
    max_value_array[weight][count] = max_value;
    return max_value;
}

void SmartBag()
{
    // 读取输入测试数据
    ifstream read;
    read.open("input.txt");
    if (!read)
    {
        return;
    }

    string buffer;
    getline(read, buffer);
    string::size_type const idx = buffer.find(',');
    if (idx == string::npos)
    {
        read.close();
        return;
    }

    int max_weight = atoi(buffer.substr(0, idx).c_str()) + 1;
    int max_count = atoi(buffer.substr(idx + 1).c_str());
    goods_weight = new int[max_count];
    goods_value = new int[max_count];
    goods_select = new int[max_count];
    for (int k = 0; k < max_count; ++k)
    {
        goods_select[k] = 0;
    }

    int index = 0;
    while (getline(read, buffer))
    {
        if (buffer.length() > 0)
        {
            string::size_type const idx = buffer.find(',');
            if (idx != string::npos)
            {
                goods_weight[index] = atoi(buffer.substr(0, idx).c_str());
                goods_value[index] = atoi(buffer.substr(idx + 1).c_str());
                ++index;
            }
        }

        if (index == max_count)
        {
            break;
        }
    }

    read.close();

    max_value_array = new int* [max_weight];
    for (int i = 0; i < max_weight; ++i)
    {
        max_value_array[i] = new int[max_count];
    }

    for (int i = 0; i < max_weight; ++i)
    {
        for (int j = 0; j < max_count; ++j)
        {
            max_value_array[i][j] = -1;
        }
    }

    int max_value = GetMaxValue(max_weight - 1, max_count - 1);

    cout << "max value is " << max_value << endl;
    cout << "calculate count " << calculate_count << endl;
    cout << "goods select " << endl;

    int weight = max_weight - 1;
    for (int k = max_count - 1; k >= 1; --k)
    {
        // 代表第k个值在最优解中被放入背包
        if (max_value_array[weight][k] > max_value_array[weight][k - 1])
        {
            goods_select[k] = 1;
            weight = weight - goods_weight[k];
        } else {
            goods_select[k] = 0;
        }
    }

    int sum = 0;
    for (int k = 0; k < max_count; ++k)
    {
        cout << goods_select[k] << endl;
        if (goods_select[k] == 1)
        {
            sum += goods_value[k];
        }
    }
    cout << "sum = " << sum << endl;
    cout << endl;
}

int main(int argc, char* argv[])
{
    SmartBag();
    delete [] goods_value;
    delete [] goods_weight;
    delete [] goods_select;
    delete[] max_value_array;
    return 0;
}
