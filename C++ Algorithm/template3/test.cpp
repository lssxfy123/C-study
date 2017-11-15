/************************************************************************/
/*    文件名       ：test.cpp
/*    作者         ：刘珅珅
/*    日期         ：2011/11/8
/*    功能描述     ：模板实参的匹配                                                                     */
/************************************************************************/

// 注意写函数模板和类模板的格式
template <typename T>
int compare(const T &v1, const T &v2);

int main(int argc, char *argv[])
{
	short s1 = 10;
//	int s2 = 20;
	short s3 = 20;

//	compare(s1, s2); // error:实参的类型与形参不完全匹配，不能实例化compare(short, int)，必须是compare(short, short)或compare(int, int)
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
