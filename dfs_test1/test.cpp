// Copyright 2018.���|�|
// author�����|�|
// �����������-ȫ����
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void DFS(vector<int> array, vector<int> book, int step)
{
    if (step == array.size())
    {
        // ���һ������
        for (int i = 0; i < array.size(); ++i)
        {
            cout << array[i] << "";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= array.size(); ++i)
    {
        if (book[i - 1] == 0)  // ��ʾi��û��ʹ��
        {
            array[step] = i;
            book[i - 1] = 1;  // ������i���Ϊ��ʹ��
            DFS(array, book, step + 1);
            book[i - 1] = 0;  // ������i�ָ�Ϊδʹ�ã��Ա����������
        }
    }
}

// �ǵݹ������������
void DFSNoRecursion()
{
    
}

int main(int argc, char* argv[])
{
    int n = 3;  // n��ȫ����
    vector<int> array(n, 0);
    vector<int> book(n, 0);
    DFS(array, book, 0);
    return 0;
}
