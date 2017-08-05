// Copyright 2017.���|�|
// author�����|�|
// reference wrapperʵ��STL Reference����
#include <iostream>
#include <memory>
#include <vector>
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

int main(int argc, char* argv[])
{
    // ʹ��reference_wrapper�⸲��ʵ������Reference����
    vector<reference_wrapper<Item>> books;
    Item f("Faust", 12.99f);
    books.push_back(f);
    cout << "original: " << endl;
    for (const auto& book : books)
    {
        cout << book.get().name() << ":" << book.get().price() << endl;
    }

    cout << endl;
    cout << "change price:  " << endl;
    f.set_price(9.99f);
    for (const Item& book : books)
    {
        cout << book.name() << ":" << book.price() << endl;
    }
    return 0;
}
