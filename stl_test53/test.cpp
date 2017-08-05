// Copyright 2017.刘珅珅
// author：刘珅珅
// shared ptr实现STL Reference语义
#include <algorithm>
#include <deque>
#include <iostream>
#include <memory>
#include <set>
#include "../include/print.hpp"
#include "../include/buckets.hpp"
using namespace std;

class Item {
public:
    Item(const string& name, float price = 0) : name_(name), price_(price)
    {}

    string name() const
    {
        return name_;
    }

    void set_name(const string& name)
    {
        name_ = name;
    }

    float price() const {
        return price_;
    }

    void set_price(float p)
    {
        price_ = p;
    }
private:
    string name_;
    float price_;
};

template<typename Coll>
void PrintItems(const string& msg, const Coll& coll)
{
    cout << msg << endl;
    for (const auto& elem : coll)
    {
        cout << ' ' << elem->name() << ":"
            << elem->price() << endl;
    }
}

int main(int argc, char* argv[])
{
    typedef shared_ptr<Item> ItemPtr;
    // 使用shared_ptr作为STL容器实现Reference语义
    set<ItemPtr> allItems;
    deque<ItemPtr> bestsellers;

    bestsellers = {ItemPtr(new Item("Kong Yize", 20.10f)), 
                         ItemPtr(new Item("A Midsummer Night's Dream", 14.99f)),
                         ItemPtr(new Item("The Maltese Falcon", 9.88f))};
    allItems = {ItemPtr(new Item("Water", 0.44f)), ItemPtr(new Item("Pizza", 2.22f))};
    allItems.insert(bestsellers.begin(), bestsellers.end());
    PrintItems("bestsellers:   ", bestsellers);
    PrintItems("all:   ", allItems);
    cout << endl;

    cout << "double price of bestsellers" << endl;
    for_each(bestsellers.begin(), bestsellers.end(), [](shared_ptr<Item>& elem) {
        elem->set_price(elem->price() * 2);
    });

    cout << "replace second bestseller by first item with name Pizza" << endl;
    bestsellers[1] = *(find_if(allItems.begin(), allItems.end(), [](shared_ptr<Item> elem) {
        return elem->name() == "Pizza";
    }));

    bestsellers[0]->set_price(44.77f);
    PrintItems("bestsellers:   ", bestsellers);
    PrintItems("all:   ", allItems);
    return 0;
}
