// Copyright 2017.���|�|
// author�����|�|
// �����㷨-N�ʺ�����
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N = 0;
vector<vector<int> > trace;
vector<vector<string> > result;

bool Check(int row, int column)
{
    // ��1�е�����λ�ö����԰ڷŻʺ�
    if (row == 1) return true;
    int i, j;

    // �ж�ͬһ���Ƿ��лʺ�
    // row - 2��ԭ����row, column��Ϊʵ�ʵ��У���
    // ����¼�����켣��trace��0��ʼ
    // ֻ��Ҫ�ж�֮ǰ��ͬһ�У���Ϊ�����аڷŻʺ�
    // ����row = 2ʱ������ֻ��Ҫ�ж�trace�ĵ�0�е�ͬһ���Ƿ��лʺ�
    for (i = 0; i <= row - 2; ++i)
    {
        if (trace[i][column - 1] == 1)
        {
            return false;
        }
    }

    // �ж�(row, column)���Խ����Ƿ��лʺ�
    i = row - 2;
    j = i - (row - column);  // j = column - 2
    while (i >= 0 && j >= 0)
    {
        if (trace[i][j] == 1)
        {
            return false;
        }
        --i;
        --j;
    }

    // �ж�(row, column)���Խ����Ƿ��лʺ�
    i = row - 2;
    j = row + column - i - 2;  // j = column
    while (i >= 0 && j <= N - 1)
    {
        if (trace[i][j] == 1)
        {
            return false;
        }
        --i;
        ++j;
    }

    return true;
}

void Output()
{
    vector<string> temp;
    for (int i = 0; i < N; ++i)
    {
        string s;
        for (int j = 0; j < N; ++j)
        {
            // ���԰ڷŻʺ�
            if (trace[i][j] == 1)
            {
                s.push_back('Q');
            } else {
                s.push_back('.');
            }
        }
        temp.push_back(s);
    }
    result.push_back(temp);
}

void DFS(int level)
{
    if (level == N)
    {
        // �����Ϊ�ʺ�İڷŷ���
        Output();
    } else {
        // level�����У�i������
        for (int i = 0; i < N; ++i)
        {
            // level = 0,i = 0��ʾ�ڵ�1�е�1�аڷŻʺ�
            // Ȼ��ݹ����DFS���ж��ڵ�2��ĳ�п��԰ڷŻʺ�
            // ����������ʣ�µ�7�ж��ڷŻʺ�
            // �����ж�level = 0,i =1ʱ�����ֱ��level = 0, i = 7����
            // �ӽ��result.txt���Կ�����ÿ������»ʺ�İڷ�����ͬ
            // level = 0, i = 2ʱ�ܹ���16�аڷŷ�������2-7�еĻʺ�İڷ�
            // ���в�ͬ��ѡ��level = 0,i = 2�ڷŻʺ�Ȼ����ж�
            // level = 1, i = 0��level = 1, i = 7���������������ж�
            // level = 2, i = 0��level = 2, i = 7����������Ի��в�ͬ�İڷŷ���
            if (Check(level + 1, i + 1))
            {
                // level + 1��i + 1�п��԰ڷŻʺ�
                trace[level][i] = 1;

                // �ݹ���ð����к����ĵ��ö�ѹ��ջ��
                // ����ʱ���δ�ջ�е���
                DFS(level + 1);
                trace[level][i] = 0;  // ��level + 1��i + 1�в��ڷŻʺ�
            }
        }
    }
}

vector<vector<string> > SolveNQueens(int n)
{
    N = n;
    for (int i = 0; i < n; ++i)
    {
        vector<int> array(n, 0);
        trace.push_back(array);
    }
    DFS(0);
    return result;
}

int main(int argc, char* argv[])
{
    SolveNQueens(12);

    cout << "total solution: " << result.size() << endl;

    //ofstream write;
    //write.open("result.txt", ios::out);
    //for (int i = 0; i < result.size(); ++i)
    //{
    //    write << "solution " << i + 1 << endl;
    //    for (int j = 0; j < result[i].size(); ++j)
    //    {
    //        write << result[i][j].c_str() << endl;
    //    }
    //    write << endl;
    //}

    return 0;
}
