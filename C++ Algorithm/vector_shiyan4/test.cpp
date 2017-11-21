// Copyright 2017.刘珅珅
// author：刘珅珅
// 测试vecto
#include <iostream>
#include <vector>
using namespace std;

char *year;
vector<float> vec1;
vector<float> vec2;

int main(int argc, char *argv[])
{
	if (year == NULL)
	{
		cout << "字符串为空" << endl;
	}
	else
	{
		cout << "字符串不为空" << endl;
	}

	for (size_t i = 0; i != 10; ++i)
	{
		vec1.push_back(i);
	}

	vector<float> :: iterator vecIter1;
	vecIter1 = vec1.begin();

	if (vecIter1 == vec1.end())
	{
		cout << "链表为空" << endl;
	}
	else
	{
		cout << "链表不为空" << endl;
	}

	for (;vecIter1 != vec1.end(); ++vecIter1)
	{
		vec2.push_back(*vecIter1);
	}

	return 0;
}

/*
bool Get12Month(char *nian, char *yue, std :: vector<float> &yongDianL, 
				std :: vector<float> &dianF)
{
	// 如果待传递的数据位空
	if (year == NULL || month == NULL)
	{
		printf("\n year or month is Null! \n");
		return false;
	}

	yongDianL.clear();
	dianF.clear();

	std :: vector<float> :: iterator elecConIter;
	std :: vector<float> :: iterator elecChargeIter;

	elecConIter = elecConsumption.begin();
	elecChargeIter = elecCharge.begin();

	if (elecConIter == elecConsumption.end() || elecChargeIter == elecCharge.end())
	{
		printf("\n elecConsumption or elecCharge is Null! \n");
		return false;
	}

	// 传递数据到界面

	nian = year;
	yue = month;

	for (; elecConIter != elecConsumption.end(); ++elecConIter)
	{
		yongDianL.push_back(*elecConIter);
	}

	for (; elecChargeIter != elecCharge.end(); ++elecChargeIter)
	{
		dianF.push_back(*elecChargeIter);
	}

	return true;

}


bool GetAirControl(std :: vector<char*> &startTime, std :: vector<char*> &endTime,
				   std :: vector<int> &moShi, std :: vector<int> &wenDu, 
				   std :: vector<int> &fengShu)
{
	std :: vector<char*> :: iterator startTimeIter;
	std :: vector<char*> :: iterator endTimeIter;
	std :: vector<int> :: iterator modelIter;
	std :: vector<int> :: iterator temperatureIter;
	std :: vector<int> :: iterator windSpeedIter;

	startTimeIter = startTimeInterval.begin();
	endTimeIter = endTimeInterval.begin();
	modelIter = model.begin();
	temperatureIter = temperature.begin();
	windSpeedIter = windSpeed.begin();

	// 如果待传递的数据为空
	if (startTimeIter == startTimeInterval.end() ||
		endTimeIter == endTimeInterval.end() ||
		modelIter == model.end() || 
		temperatureIter == temperature.end() ||
		windSpeedIter == windSpeed.end())
	{
		return false;
	}

	startTime.clear();
	endTime.clear();
	moShi.clear();
	wenDu.clear();
	fengShu.clear();

	// 将数据传给界面

	for (; startTimeIter != startTimeInterval.end(); ++startTimeIter)
	{
		startTime.push_back(*startTimeIter);
	}

	for (; endTimeIter != endTimeInterval.end(); ++endTimeIter)
	{
		endTime.push_back(*endTimeIter);
	}

	for (; modelIter != model.end(); ++modelIter)
	{
		moShi.push_back(*modelIter);
	}

	for (; temperatureIter != temperature.end(); ++temperatureIter)
	{
		wenDu.push_back(*temperatureIter);
	}

	for (; windSpeedIter != windSpeed.end(); ++windSpeedIter)
	{
		fengShu.push_back(*windSpeedIter);
	}

	return true;
}
*/