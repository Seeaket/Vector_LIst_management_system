#include"SortFunction.h"
#include"ListNode.h"

const float EPS = 1e-6f;//����f�����ֵ����Ĭ��Ϊdouble����

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
	/*return (a.wages - b.wages) < EPS;*///��list��sort�����жԸ����ͽ���������Ҫ�Ӿ����жϣ������ᱼ��
	return a.wages < b.wages;
}
