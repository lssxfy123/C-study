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
    // const int width = 0;  // error��������������г�ʼ��
};

// const int n = 0;  // ok��������ͷ�ļ��г�ʼ��const����

#endif  // C_H
