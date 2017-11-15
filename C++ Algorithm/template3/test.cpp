/************************************************************************/
/*    �ļ���       ��test.cpp
/*    ����         �����|�|
/*    ����         ��2011/11/8
/*    ��������     ��ģ��ʵ�ε�ƥ��                                                                     */
/************************************************************************/

// ע��д����ģ�����ģ��ĸ�ʽ
template <typename T>
int compare(const T &v1, const T &v2);

int main(int argc, char *argv[])
{
	short s1 = 10;
//	int s2 = 20;
	short s3 = 20;

//	compare(s1, s2); // error:ʵ�ε��������ββ���ȫƥ�䣬����ʵ����compare(short, int)��������compare(short, short)��compare(int, int)
	compare(s1, s3);

	return 0;

}

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2)
	{
		return -1;
	}

	if(v2 < v1)
	{
		return 1;
	}

	return 0;
}
