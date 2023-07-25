#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include"ListNode.h"
#include "FindFunction.h"
#include<string.h>
#include<string>
#include<sstream>


int NameFind(ListMessage* data,std::string names)
{
	return data->name.compare(names) == 0;
}


int IdFind(ListMessage* data,int ids)
{
	return data->id == ids;
}


int WagesFind(ListMessage* data, std::string wage)
{
	constexpr double EPS = 1e-5;
	std::istringstream iss(wage);//需要包含头文件sstram
	std::string str1, str2;
	std::getline(iss, str1, ',');
	std::getline(iss, str2);
	double wages1 = atof(str1.c_str());
	double wages2 = atof(str2.c_str());
	double temp;
	if (wages1 - wages2 > EPS)
	{
		temp = wages1;
		wages1 = wages2;
		wages2 = temp;
	}
	return (((data->wages + EPS) > wages1) && ((data->wages + EPS) < wages2));
}


int SimilarFind(ListMessage* data,std::string ccs)
{
	char const * name = data->name.c_str();
	std::string ids = std::to_string(data->id);
	char const* id = ids.c_str();
	char wage[20];
	sprintf(wage, "%f", data->wages);
	char const* cc = ccs.c_str();
	if (strstr(name, cc) != NULL || strstr(id,cc) != NULL || strstr(wage,cc))
		return 1;
	return 0;
}
