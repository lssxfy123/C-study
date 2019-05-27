#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
class BinaryHeap
{
public:
    explicit BinaryHeap(int capactiy = 100):current_size_(0)
    {
        array_.resize(capactiy);
    }

    explicit BinaryHeap(const vector<Comparable>& items)
    {
        // �����10���ռ�
        array_.resize(items.size() + 10);
        current_size_ = items.size();
        for (int i = 0; i < items.size(); ++i)
        {
            array_[i + 1] = items[i];
        }
        BuildHeap();
    }

    void MakeEmpty()
    {
        current_size_ = 0;
        array_.clear();
    }

    bool IsEmpty() const
    {
        return 0 == current_size_;
    }

    // ��С�ѵ�����Ϊ1��λ��Ϊ�����
    // Ҳ����Сֵ
    const Comparable& FindMin() const
    {
        return array_[1];
    }

    void Insert(const Comparable& x)
    {
        if (current_size_ == array_.size() - 1)
        {
            array_.resize(array_.size() * 2);
        }

        // ����Ԫ��ʱ����������һ�����д���Ԫ��
        int hole = ++current_size_;

        // ִ�����˲���
        // ���������Ԫ��x��λ��hole/2��Ԫ��(���ܵĸ���)�Ƚ�
        // �����С�ڸ�ֵ������ֵ���뵽�����Ŀ���λ�ò�������
        // ���ƣ�ֱ��Ϊx�ҵ����ʵĲ����Ϊֹ
        for (; hole > 1 && x < array_[hole / 2]; hole = hole / 2)
        {
            array_[hole] = array_[hole / 2];
        }

        array_[hole] = x;
    }

    // ɾ����Сֵ
    void DeleteMin()
    {
        if (IsEmpty())
        {
            return;
        }

        // ����Ҫע��ʹ�ú�׺--
        // ����ʹ��ǰ׺--����ΪҪ��
        // ����ѵ����һ��Ԫ��Ų�������
        // ���������0λ�ò��洢��㣬����
        // current_size_λ�ô洢�������һ�����
        array_[1] = array_[current_size_--];
        PercolateDown(1);
    }

    void DeleteMin(Comparable& min_item)
    {
        if (IsEmpty())
        {
            return;
        }
        min_item = array_[1];
        array_[1] = array_[current_size_--];
        PercolateDown(1);
    }

    void Print()
    {
        for (int i = 1; i <= current_size_;++i)
        {
            cout << array_[i] << " ";
        }
        cout << endl;
    }

private:
    // ������˳����������ɶ����
    // ��current_size_/2��ʼ���˵�ԭ����
    // ��ײ��Ԫ�ز���Ҫ���ˣ����ݶ����(��ȫ������)�Ľṹ
	// ��current_size_/2��Ԫ����Ҷ��㣬Ҷ��㲻��Ҫ���ˣ���û��
	// �����ӽ�㣬����ֱ�Ӵ�current_size_/2��ʼ����
    void BuildHeap()
    {
        for (int i = current_size_ / 2; i > 0; --i)
        {
            PercolateDown(i);
        }
    }

    // ����
	// ��ν���˾��ǰѵ�ǰ��Ҫ�����Ľ�����������ӽ��Ƚ�
    void PercolateDown(int hole)
    {
        int child;
        Comparable tmp = array_[hole];
        for (; hole * 2 <= current_size_; hole = child)
        {
            child = hole * 2;  // �����

            // ���child������current_size_�����ʾ�Ҷ��ӿ϶�����
            // ����Ҷ��ӱ������С����Ƚ��Ҷ���
			// �Ӷ���ѵ����ʿ��Կ����������ӽ���໥�Ĵ�С����ȷ��
			// ��С���ǽ��������ӽ�㶼С�������ǽ��������ӽ�㶼��
            if (child != current_size_ && array_[child + 1] < array_[child])
            {
                ++child;
            }

			// ����ӽ��С�ڵ�ǰ�ڵ㣬���ӽ���ֵ������ǰ���
			// ��forѭ������ ��ִ��hole=child�������������ˣ�����
			// ��Ϊ�˽���ʼ��array_[hole]���˵���ʼ��㵽Ҷ�ӽ��
			// ·��������ʵ�λ��
            if (array_[child] < tmp)  // ��С��
            {
                array_[hole] = array_[child];
            } else
                break;
        }

        array_[hole] = tmp;
    }

private:
    int current_size_;

    // �������ͨ���������洢����
    // ��i�������������2i�ϣ��Ҷ���
    // ��2i+1�ϣ���������i/2��.
    // ����ĵ�0��λ�ò���Ԫ�أ��������
    vector<Comparable> array_;
};

#endif
