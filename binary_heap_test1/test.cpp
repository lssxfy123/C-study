// Copyright 2016.刘珅珅
// author：刘珅珅
// STL中的优先队列
// 默认为最大堆
#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

template<typename PriorityQueue>
void DumpContents(const string& msg, PriorityQueue& pq)
{
    cout << msg << ": " << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(int argc, char* argv[])
{
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int> > min_pq;

    max_pq.push(4);
    max_pq.push(3);
    max_pq.push(5);

    min_pq.push(4);
    min_pq.push(3);
    min_pq.push(5);

    DumpContents("minPQ", min_pq);
    cout << endl;
    DumpContents("maxPQ", max_pq);
    cout << endl;
    return 0;
}

