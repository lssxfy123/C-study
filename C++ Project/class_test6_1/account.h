#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
  public:
    Account();
    ~Account();

  public:
    const static int number = 30;  // 可以在类定义体中初始化
    double array[number];
};

#endif  // ACCOUNT_H
