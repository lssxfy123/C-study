// Copyright 2017.���|�|
// author�����|�|
// 01����-��̬�滮��һά����
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int* goods_weight = NULL;
int* goods_value = NULL;
int* goods_select = NULL;
int* max_value_array = NULL;
int calculate_count = 0;

void SmartBag()
{
    // ��ȡ�����������
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

    max_value_array = new int [max_weight];
    for (int i = 0; i < max_weight; ++i)
    {
        max_value_array[i] = 0;
    }

    for (int i = 0; i < max_count; ++i)
    {
        for (int j = max_weight - 1; j >= goods_weight[i]; --j)
        {
            if (max_value_array[j - goods_weight[i]] + goods_value[i] > max_value_array[j])
            {
                // max_value_arrayΪһά���飬��洢��������Ϊjʱ������ѡ������Ž�
                // �����Ͳ���Ҫ�ö�ά������
                // j��Ҫ�ӱ��������������ʼ�ݼ�����Ϊmax_value_arry[j]��Ҫ����
                // max_value_array[j - goods_weight[i]]���Ƶ�
                // Ŀǰû���������ŵ�ѡ�񣬼��ĸ���Ʒѡ�У��ĸ�ûѡ��
                max_value_array[j] = max_value_array[j - goods_weight[i]] + goods_value[i];
            }
        }
    }

    cout << "max value is " << max_value_array[max_weight - 1] << endl;

    for (int i = 0; i < max_weight; ++i)
    {
        cout << max_value_array[i] << ",";
    }
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
