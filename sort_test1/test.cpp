// Copyright 2017.���|�|
// author�����|�|
// ��������
#include <iostream>
#include <vector>
using namespace std;

// ��������
template<typename Comparable>
void InsertionSort(vector<Comparable>& array)
{
    int j;
    for (int i = 1; i < array.size(); ++i)
    {
        Comparable temp = array[i];
        // ��i��Ԫ����֮ǰ��0-i - 1���бȽ�
        for (j = i; j > 0 && temp < array[j - 1]; --j)
        {
            // �ƶ�����
            // ���temp<array[j - 1]����array[j - 1]����ƶ�
            // �Ա����temp
            array[j] = array[j - 1];
        }
        array[j] = temp;
    }

    // ��ӡ
    for (int k = 0; k < array.size(); ++k)
    {
        cout << array[k] << " ";
    }
    cout << endl;
}

// ϣ������
template<typename Comparable>
void ShellSort(vector<Comparable>& array)
{
    // ��������
    vector<int> gap_array;
    gap_array.push_back(5);
    gap_array.push_back(3);
    gap_array.push_back(1);
    for (int k = 0; k < gap_array.size(); ++k)
    {
        // gapΪ����
        int gap = gap_array[k];
        for (int i = gap; i < array.size(); ++i)
        {
            Comparable temp = array[i];
            int j = i;

            // array[i]��array[i - gap]�Ƚ�
            for (; j >= gap && temp < array[j - gap]; j -= gap)
            {
                // �ƶ�����
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }

        cout << "gap = " << gap << endl;
        for (int i = 0; i < array.size(); ++i)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

// ������
// ����ӵ�����ֵ
// �����Ѳ�ͬ������0λ����Ԫ��
// ����ѵ�0λ��û��Ԫ��
inline int LefChild(int i)
{
    return 2 * i + 1;
}

// ����
template<typename Comparable>
void PercolateDown(vector<Comparable>& array, int i, int n)
{
    int child;
    Comparable temp = array[i];

    for (; LefChild(i) < n; i = child)
    {
        child = LefChild(i);

        // ���ѣ�Сֵ����
		// �鿴���Ӻ��Һ���˭����
        if (child != n - 1 && array[child] < array[child + 1])
        {
            ++child;
        }

        if (temp < array[child])
        {
            array[i] = array[child];
        } else
            break;
    }
    array[i] = temp;
}

template<typename Comparable>
void HeapSort(vector<Comparable>& array)
{
    // ��������
    for (int i = array.size() / 2; i >= 0; --i)
    {
        PercolateDown(array, i, array.size());
    }

    // ����
    for (int j = array.size() - 1; j > 0; --j)
    {
        // array[0]�϶�����������ֵ
        // ����ʼ����array[0]��array[array.size() - 1]����
        // �������ֵ�ͻ���������ĩ��Ȼ��ִ�����˲���
        // ע����ǰarray.size() - 1������ˣ����һ�����
        // ������ǰarray.size() - 1������ֵ�ƶ�����array[0]λ��
        swap(array[0], array[j]);
        PercolateDown(array, 0, j);
    }

    // ��ӡ
    for (int k = 0; k < array.size(); ++k)
    {
        cout << array[k] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<int> array_test;
    array_test.push_back(34);
    array_test.push_back(8);
    array_test.push_back(64);
    array_test.push_back(51);
    array_test.push_back(32);
    array_test.push_back(21);
    cout << "��������:" << endl;
    InsertionSort(array_test);

    vector<int> array_test1;
    array_test1.push_back(81);
    array_test1.push_back(94);
    array_test1.push_back(11);
    array_test1.push_back(96);
    array_test1.push_back(12);
    array_test1.push_back(35);
    array_test1.push_back(17);
    array_test1.push_back(95);
    array_test1.push_back(28);
    array_test1.push_back(58);
    array_test1.push_back(41);
    array_test1.push_back(75);
    array_test1.push_back(15);
    cout << "ϣ������:" << endl;
    ShellSort(array_test1);

    vector<int> array_test2;
    array_test2.push_back(34);
    array_test2.push_back(8);
    array_test2.push_back(64);
    array_test2.push_back(51);
    array_test2.push_back(32);
    array_test2.push_back(21);
    cout << "������:" << endl;
    HeapSort(array_test2);
    return 0;
}
