// Copyright 2017.刘珅珅
// author：刘珅珅
// 01背包-动态规划，一维数组
// 背部重量为分数的背包问题
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct MaxValueNode
{
    double weight_;
    double value_;
};

vector<double> goods_weight;
vector<double> goods_value;
vector<MaxValueNode> max_value_array;
double precison = 0.5;

double FindValueByWeight(double weight)
{
    double result = 0;
    for (int i = 0; i < max_value_array.size(); ++i)
    {
        if (fabs(weight - max_value_array[i].weight_) <= 0.001)
        {
            result = max_value_array[i].value_;
            break;
        }
    }
    return result;
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

    double max_weight = atof(buffer.substr(0, idx).c_str());
    int max_count = atoi(buffer.substr(idx + 1).c_str());

    int index = 0;
    while (getline(read, buffer))
    {
        if (buffer.length() > 0)
        {
            string::size_type const idx = buffer.find(',');
            if (idx != string::npos)
            {
                goods_weight.push_back(atof(buffer.substr(0, idx).c_str()));
                goods_value.push_back(atof(buffer.substr(idx + 1).c_str()));
                ++index;
            }
        }

        if (index == max_count)
        {
            break;
        }
    }

    read.close();

    for (double i = 0; i < max_weight; i = i + precison)
    {
        MaxValueNode node;
        node.value_ = 0;
        node.weight_ = i;
        max_value_array.push_back(node);
    }

    int max_value_size = max_value_array.size();
    for (int i = 0; i < max_count; ++i)
    {
        for (int j = max_value_size - 1; max_value_array[j].weight_ >= goods_weight[i]; --j)
        {
            if (FindValueByWeight(max_value_array[j].weight_ - goods_weight[i]) + goods_value[i] > max_value_array[j].value_)
            {
                max_value_array[j].value_ = FindValueByWeight(max_value_array[j].weight_ - goods_weight[i]) + goods_value[i];
            }
        }
    }

    cout << "max value is " << max_value_array[max_value_size - 1].value_ << endl;
    //for (int i = 0; i < max_value_size; ++i)
    //{
    //    cout << max_value_array[i].value_ << ",";
    //}
    //cout << endl;
}

int main(int argc, char* argv[])
{
    goods_value.clear();
    goods_weight.clear();
    max_value_array.clear();
    SmartBag();
    goods_value.clear();
    goods_weight.clear();
    max_value_array.clear();
    return 0;
}
