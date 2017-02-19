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
        // 多分配10个空间
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

    // 最小堆的索引为1的位置为根结点
    // 也是最小值
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

        // 插入元素时，首先在下一个空闲创建元素
        int hole = ++current_size_;

        // 执行上滤操作
        // 将待插入的元素x与位于hole/2的元素(可能的父亲)比较
        // 如果其小于该值，将该值移入到创建的空闲位置并将空闲
        // 上移，直到为x找到合适的插入点为止
        for (; hole > 1 && x < array_[hole / 2]; hole = hole / 2)
        {
            array_[hole] = array_[hole / 2];
        }

        array_[hole] = x;
    }

    // 删除最小值
    void DeleteMin()
    {
        if (IsEmpty())
        {
            return;
        }

        // 这里要注意使用后缀--
        // 不能使用前缀--，因为要把
        // 二叉堆的最后一个元素挪到根结点
        // 由于数组的0位置不存储结点，所以
        // current_size_位置存储的是最后一个结点
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
    // 由任意顺序的数组生成二叉堆
    // 从current_size_/2开始下滤的原因是
    // 最底层的元素不需要下滤,根据二叉堆的结构
    // 可以直接从current_size_/2开始下滤
    void BuildHeap()
    {
        for (int i = current_size_ / 2; i > 0; --i)
        {
            PercolateDown(i);
        }
    }

    // 下滤
    void PercolateDown(int hole)
    {
        int child;
        Comparable tmp = array_[hole];
        for (; hole * 2 <= current_size_; hole = child)
        {
            child = hole * 2;  // 左儿子

            // 如果child不等于current_size_，则表示右儿子肯定存在
            // 如果右儿子比左儿子小，则比较右儿子
            if (child != current_size_ && array_[child + 1] < array_[child])
            {
                ++child;
            }

            if (array_[child] < tmp)
            {
                array_[hole] = array_[child];
            } else
                break;
        }

        array_[hole] = tmp;
    }

private:
    int current_size_;

    // 二叉堆中通过数组来存储其结点
    // 第i个结点的左儿子在2i上，右儿子
    // 在2i+1上，父亲则在i/2上.
    // 数组的第0个位置不放元素，方便管理
    vector<Comparable> array_;
};

#endif
