#include"SortFunction.h"
#include"ListNode.h"

const float EPS = 1e-6f;//不加f这个数值函数默认为double类型

bool NameSort(const ListMessage& a, const ListMessage& b)
{
	return a.name < b.name;
}

bool IdSort(const ListMessage& a, const ListMessage& b)
{
	return a.id < b.id;
}

bool WageSort(const ListMessage& a, const ListMessage& b)
{
	/*return (a.wages - b.wages) < EPS;*///在list的sort函数中对浮点型进行排序不需要加精度判断，函数会奔溃
	return a.wages < b.wages;
}
