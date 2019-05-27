#include <iostream>
#include <vector>
using namespace std;

// ��������
// ����С��Χ����
void InsertSort(vector<int>& array, int left, int right)
{
    int j;
    for (int i = left + 1; i <= right; ++i)
    {
        int tmp = array[i];
        for (j = i; j > 0 && tmp < array[j - 1]; --j)
        {
            array[j] = array[j - 1];
        }
        array[j] = tmp;
    }
}

// Ѱ�ҿ���������м���Ŧֵ
int Median3(vector<int>& array, int left, int right)
{
    int center = (left + right) / 2;
    if (array[center] < array[left])
    {
        swap(array[center], array[left]);
    }

    if (array[right] < array[left])
    {
        swap(array[right], array[left]);
    }

    if (array[right] < array[center])
    {
        swap(array[right], array[center]);
    }
    swap(array[center], array[right - 1]);
    return array[right - 1];
}


// ��������
void QuickSort(vector<int>& array, int left, int right)
{
    if (left + 10 <= right)
    {
        int pivot = Median3(array, left, right);
        int i = left;
        int j = right - 1;
        for (;;)
        {
            while (array[++i] < pivot)
            {
            }

            while (array[--j] > pivot)
            {
            }

            if (i < j)
            {
                swap(array[i], array[j]);
            }
            else
            {
                break;
            }
        }
        swap(array[i], array[right - 1]);
        QuickSort(array, left, i - 1);
        QuickSort(array, i + 1, right);
    }
    else
    {
        InsertSort(array, left, right);
    }
}

int main(int argc, char* argv[])
{
    vector<int> array {1, 6, 7, 8, 2, 9, 10, 12, 23, 5, 89, 24, 25, 26, 27, 34, 56};
    cout << "ԭʼ���飺" << endl;
    for (int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << ",";
    }
    cout << endl;
    QuickSort(array, 0, array.size() - 1);
    cout << "���������飺" << endl;
    for (int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << ",";
    }
    cout << endl;

    return 0;
}
