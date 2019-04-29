// Copyright 2017.���|�|
// author�����|�|
// �����㷨-N�ʺ�����
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N = 0;
long sum = 0;
long upper_column = 1;

// �鿴���ֵĶ����Ʊ�ʾ
template<typename T> void BinaryRecursion(T n)
{
    T a = n % 2;
    n = n >> 1;
    if (n != 0)
        BinaryRecursion(n);
    cout << a;
}

template<typename T> void BinaryCount(T n, int count)
{
    for (int i = count - 1; i >= 0; --i)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

// λ����ĳ�����Ѱ�ҿ��ԷŻʺ�ĵط�
// row����ĳһ�������������²��ܷ��ûʺ����
// left_diagonal����ĳһ������Խ��������²��ܷ��ûʺ����
// right_diagonal����ĳһ�����ҶԽ��������²��ܷ��ûʺ����
// ��6x6������Ϊ����
// row=101010������ĳһ�еĵ�1,3,5�в��ܷ��ûʺ�
// left_diagonal=100100������ĳһ�еĵ�1,4�в��ܷ��ûʺ�
// right_diagonal=000111������ĳһ�еĵ�4,5,6�в��ܷ��ûʺ�
// �ο�http://www.matrix67.com/blog/archives/266
// �еĽ��⣬��һ����ͼ�����4�е������ǰ3�ж��ѷ����˻ʺ�
// rowΪ��ɫ������left_diagonalΪ��ɫ��������ͼ�п��Կ�������ɫ����
// ���4���ཻ�ڵ�1,4�У�����left_diagonal=100100��right_diagonalΪ��ɫ
// ���4���ཻ�ڵ�4,5,6�У�right_diagonal=000111
// ��pos = upper_column & ~(row | left_diagonal | right_diagonal)���Լ����
// pos=010000����ʾ��2�п��Է��ûʺ�ȡ�����ұ߿����У�p=010000
// �ӵڶ�����ͼ���Կ������ڵ�4�е�2�з��ûʺ�󣬵�5�е��������
// row=row+p, left_diagonal=(left_diagonal+p)<<1,right_diagonal=(right_diagonal+p)>>1
// row�ı仯������һ�е�p��1���в����Է��ûʺ���
// left_diagonal+p����1λ����Ϊleft_diagonal�����λΪ��4�е�1�е����ƣ���
// ����ǰ3�еĻʺ���þ����ģ��������õ���5�У�Ӧ���ɵ�4�еĻʺ����
// ��ȷ����5�е�1�еĻʺ����ƣ�����Ҫ����1λ��ͬ��right_diagonal+p����1λҲ�����
void Test(long row, long left_diagonal, long right_diagonal)
{
    if (row != upper_column)
    {
        // pos����ĳһ�����п��Է��ûʺ����
        long pos = upper_column & ~(row | left_diagonal | right_diagonal);

        while (pos)
        {
            // ȡ�����ұߵ�Ϊ1��bit
            long p = pos & (~pos + 1);

            // ��pos���޳������ҵĿ�����
            // Ϊ��һ�λ�ȡ���ҿ�������׼��
            pos -= p;

            Test(row + p, (left_diagonal + p) << 1, (right_diagonal + p)>> 1);
        }
    } else {
        // row������λ��Ϊ�����������ж��ɹ������˻ʺ�
        ++sum;
    }
}


int main(int argc, char* argv[])
{
    N = 6;

    // ������N��1��ɵĶ�������
    // N���ʺ�ֻ��NΪ�洢���лʺ���ж�Ӧ��λΪ1
    upper_column = (upper_column << N) - 1;
    BinaryRecursion(upper_column);
    cout << endl;
    Test(0, 0, 0);
    cout << N << " Queen answer is " << sum << endl;
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
