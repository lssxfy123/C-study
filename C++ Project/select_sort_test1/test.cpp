// Copyright 2017.刘珅珅
// author：刘珅珅
// 选择排序和快速排序
#include <iostream>
using std::cout;
using std::endl;

// 选择排序
void SelectSort(int* arrary, int length);

// 快速排序
void QuickSort(int* arrary, int left, int right);

int main(int argc, char* argv[])
{
    int a[10] = {3, 5, 9, 2, 13, 4, 6, 21, 3, 15};
    // SelectSort(a, 10);
    QuickSort(a, 0, 9);

    for (int i = 0; i != 10; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

void SelectSort(int* arrary, int length)
{
    int k = 0;
    for (int i = 0; i != (length - 1); ++i)
    {
        k = i;
        for (int j = i + 1; j != length; ++j)
        {
            //// 从大到小排列
            //if (arrary[j] > arrary[k])
            //{
            //    k = j;
            //}

            // 从小都大排列
            if (arrary[j] > arrary[k])
            {
                k = j;
            }
        }

        if (k != i)
        {
            // 不使用中间变量进行数据交换
            arrary[i] = arrary[i] + arrary[k];
            arrary[k] = arrary[i] - arrary[k];
            arrary[i] = arrary[i] - arrary[k];
        }
    }
}

void QuickSort(int* arrary, int left, int right)
{
    int temp = arrary[left];  // 基准值
    int i = left;
    int j = right;

    if (left > right)
    {
        return;
    }

    // 当i = j时， 说明
    // i的左边的值全部比基准值小
    // i右边的值全部比基准值大
    while (i != j)
    {
        // 从小到大排列
        // 首先从右向左找比基准值小的元素
        while ((arrary[j] >= temp) && (i < j))
        {
            --j;
        }

        // 然后从左向右找比基准值大的元素
        while ((arrary[i] <= temp) && (i < j))
        {
            ++i;
        }

        // 从大到小排列
        //// 首先从右向左找比基准值大的元素
        //while ((arrary[j] <= temp) && (i < j))
        //{
        //    --j;
        //}

        //// 然后从左向右找比基准值小的元素
        //while ((arrary[i] >= temp) && (i < j))
        //{
        //    ++i;
        //}


        if (i < j)
        {
            int t = arrary[i];
            arrary[i] = arrary[j];
            arrary[j] = t;
        }
    }

    // 上面的while循环下，array[i]肯定小于或等于array[left]
    // 将基准值归位
    arrary[left] = arrary[i];
    arrary[i] = temp;

    // 递归调用
    // arrary[i]的值整个数组的中间值
    // left-i - 1的值都比它小
    // i + 1-right的值都比它大
     QuickSort(arrary, left, i - 1);
     QuickSort(arrary, i + 1, right);

}

