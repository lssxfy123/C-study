// ������


class U_Ptr
{
    friend class HasPtr;

    // ����������г�Ա��Ϊ˽���ͣ�ֻ����HasPtr�����
  private:
      U_Ptr(int* p) : ip(p), use(1) {}  // ��ʼ��ʱ������Ϊ1
      ~U_Ptr() {delete ip; ip = 0;}

  private:
    int* ip;
    size_t use;
};
