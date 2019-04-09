#ifndef C_H
#define C_H

class C
{
  public:
    C() ;
    ~C();

  public:
    int GetHeight() const;
    void PrintValue();
    C& SetHeight(int height);

  private:
    int height = 0;
    const int width;
    // const int width = 0;  // error：不能在这里进行初始化
};

// const int n = 0;  // ok，可以在头文件中初始化const变量

#endif  // C_H
