// 计数类


class U_Ptr
{
    friend class HasPtr;

    // 计数类的所有成员都为私有型，只允许HasPtr类访问
  private:
      U_Ptr(int* p) : ip(p), use(1) {}  // 初始化时，计数为1
      ~U_Ptr() {delete ip; ip = 0;}

  private:
    int* ip;
    size_t use;
};
