// Copyright 2019.���|�|
// author�����|�|
// ��С�Ӵ�����
#include <iostream>
#include <unordered_map>
#include "../../include/print.hpp"
using namespace std;

string minWindow(string &source, string &target) {
    // write your code here
    if (source.length() < target.length())
    {
        return "";
    }

    if (source.length() == 0)
    {
        return "";
    }

    // targetΪ���ַ���������source
    if (target.length() == 0)
    {
        return source;
    }

    unordered_map<char, int> refs;
    string result = "";
    for (int i = 0;i < target.length(); ++i)
    {
        if (refs.count(target[i]) == 0)
        {
            refs[target[i]] = 1;
        }
        else
        {
            refs[target[i]]++;
        }
    }

    int count = refs.size();
    int k = 0;
    int len = source.length() + 1;
    for (int j = 0; j < source.length(); ++j)
    {
        while (k < source.length() && count > 0)
        {
            --refs[source[k]];
            if (refs[source[k]] == 0)
            {
                --count;
            }
            ++k;

            if (count == 0)
            {
                break;
            }
        }

        if (count == 0 && k - j < len)
        {
            len = k - j;
            result = source.substr(j, k - j);
        }

        if (refs[source[j]] == 0)
        {
            ++count;
        }
        refs[source[j]]++;
    }


    return result;
}

string minWindow1(string &source, string &target) {
    // write your code here
    if (source.length() < target.length())
    {
        return "";
    }

    if (source.length() == 0)
    {
        return "";
    }

    // targetΪ���ַ���������source
    if (target.length() == 0)
    {
        return source;
    }

    unordered_map<char, int> refs;
    string result = "";
    for (int i = 0; i < target.length(); ++i)
    {
        if (refs.count(target[i]) == 0)
        {
            refs[target[i]] = 1;
        }
        else
        {
            refs[target[i]]++;
        }
    }

    int count = 0;
    int k = 0;
    int len = source.length() + 1;
    for (int j = 0; j < source.length(); ++j)
    {
        if (refs.count(source[j]) == 0)
        {
            continue;
        }

        // ��һ��whileѭ���ҵ���k
        while (k < source.length() && count != refs.size())
        {
            if (refs.find(source[k]) != refs.end())
            {
                --refs[source[k]];

                // refs[key]==0�������Ѿ����ҵ�����target��key�ĸ������ַ�key
                if (refs[source[k]] == 0)
                {
                    ++count;
                }
            }
            ++k;
        }

        if (count == refs.size() && k - j < len)
        {
            len = k - j;
            result = source.substr(j, k - j);
        }

        // refs[key]<0������֮ǰwhileѭ���õ���ǰk���ַ���
        // �ַ�key�ĸ�������target���ַ�key�ĸ�������ʱ���ı�count
        // ���count==refs.size()����һ��ѭ���ͻὫ֮ǰ��result��������
        // ���refs[key]==0������ǰk���ַ��е��ַ�key�ĸ�������target��
        // �ַ�key�ĸ�������ʱ�޸�count��ʹ�����whileѭ�����¿�ʼ����ѯ
        // �������ʹcount==refs.size()��j�����µ��Ӵ�����ʼλ�ã����k-jС��
        // ֮ǰ�Ӵ��ĳ��ȣ��͸���result
        // refs[key]>0������j����֮ǰ��kֵ
        if (refs[source[j]]++ >= 0)
        {
            --count;
        }
    }


    return result;
}


int main(int argc, char* argv[])
{
    string src = "BADOBECODEBANC";
    string target = "AABC";
    cout << minWindow1(src, target) << endl;
    return 0;
}
