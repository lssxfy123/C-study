// Copyright 2017.���|�|
// author�����|�|
// ȫ�ֱ������ֲ���̬�������ֲ�����
#include <iostream>
using std::cout;
using std::endl;

int count = 3;

int main(void)
{
    int i, sum, count = 2;

    // forѭ���ж������е�countΪ�ֲ�����count
    for (i = 0, sum=0; i < count; i += 2, count++)
    {
        static int count = 4;
        count++;  // ��̬����count

        if((i%2) == 0)
        {
            extern int count;  // ȫ�ֱ���count
            cout << "count = " << count << endl;
            count++;
            sum += count;
        }
        sum += count;  // ��̬����count

        cout << "sum = " << sum << endl;
    }

    // count = 4�������countΪ�ֲ�����count����forѭ���ж�����������������
    // sum = 20
    cout << count << " " << sum << endl;

    return 0; 
}
