// Copyright 2017.���|�|
// author�����|�|
// ѡ������Ϳ�������
#include <iostream>
using std::cout;
using std::endl;

// ѡ������
void SelectSort(int* arrary, int length);

// ��������
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
            //// �Ӵ�С����
            //if (arrary[j] > arrary[k])
            //{
            //    k = j;
            //}

            // ��С��������
            if (arrary[j] > arrary[k])
            {
                k = j;
            }
        }

        if (k != i)
        {
            // ��ʹ���м�����������ݽ���
            arrary[i] = arrary[i] + arrary[k];
            arrary[k] = arrary[i] - arrary[k];
            arrary[i] = arrary[i] - arrary[k];
        }
    }
}

void QuickSort(int* arrary, int left, int right)
{
    int temp = arrary[left];  // ��׼ֵ
    int i = left;
    int j = right;

    if (left > right)
    {
        return;
    }

    // ��i = jʱ�� ˵��
    // i����ߵ�ֵȫ���Ȼ�׼ֵС
    // i�ұߵ�ֵȫ���Ȼ�׼ֵ��
    while (i != j)
    {
        // ��С��������
        // ���ȴ��������ұȻ�׼ֵС��Ԫ��
        while ((arrary[j] >= temp) && (i < j))
        {
            --j;
        }

        // Ȼ����������ұȻ�׼ֵ���Ԫ��
        while ((arrary[i] <= temp) && (i < j))
        {
            ++i;
        }

        // �Ӵ�С����
        //// ���ȴ��������ұȻ�׼ֵ���Ԫ��
        //while ((arrary[j] <= temp) && (i < j))
        //{
        //    --j;
        //}

        //// Ȼ����������ұȻ�׼ֵС��Ԫ��
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

    // �����whileѭ���£�array[i]�϶�С�ڻ����array[left]
    // ����׼ֵ��λ
    arrary[left] = arrary[i];
    arrary[i] = temp;

    // �ݹ����
    // arrary[i]��ֵ����������м�ֵ
    // left-i - 1��ֵ������С
    // i + 1-right��ֵ��������
     QuickSort(arrary, left, i - 1);
     QuickSort(arrary, i + 1, right);

}

