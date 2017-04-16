// Copyright 2017.���|�|
// author�����|�|
// ��������-̰���㷨
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Bag {
public:
    Bag(int id, double weight, double value)
        : id_(id), weight_(weight), value_(value)
    {
    }

    int GetID() const {return id_;}
    double GetWeight() const { return weight_;}
    double GetValue() const { return value_;}
    double GetRatio() const { return value_ / weight_;}
private:
    int id_;
    double weight_;
    double value_;
};

int ComparableBag(Bag a, Bag b)
{
    return a.GetRatio() < b.GetRatio();
}

vector<Bag> bag_array;
double precision = 0.5f;

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

    double max_weight = atof(buffer.substr(0, idx).c_str());
    int count = atoi(buffer.substr(idx + 1).c_str());

    int index = 0;
    while (getline(read, buffer))
    {
        if (buffer.length() > 0)
        {
            string::size_type const idx = buffer.find(',');
            if (idx != string::npos)
            {
                Bag bag(index + 1, atof(buffer.substr(0, idx).c_str()),
                    atof(buffer.substr(idx + 1).c_str()));
                bag_array.push_back(bag);
                ++index;
            }
        }

        if (index == count)
        {
            break;
        }
    }

    read.close();

    // ������Ʒ�ĵ�λ�����ļ�ֵ��������
    sort(bag_array.begin(), bag_array.end(), ComparableBag);

    double current_weight = 0.0;
    double current_value = 0.0;

    // ̰���㷨
    // ����λ������ֵ��ߵ�װ�����
    for (int i = count - 1; i >= 0; --i)
    {
        if (current_weight + bag_array[i].GetWeight() <= max_weight)
        {
            current_weight += bag_array[i].GetWeight();
            current_value += bag_array[i].GetValue();
            if (fabs(current_weight - max_weight) < precision)
            {
                break;
            }
        } else {
             // ����������㣬�ͽ�ȡ��һ����������Ʒװ��
            double propotion = (max_weight - current_weight) / bag_array[i].GetWeight();
            current_weight += (bag_array[i].GetWeight() * propotion);
            current_value += (bag_array[i].GetValue() * propotion);
            break;
        }
    }

    cout << "total value: " << current_value << endl;
}

int main(int argc, char* argv[])
{
    SmartBag();
    return 0;
}
