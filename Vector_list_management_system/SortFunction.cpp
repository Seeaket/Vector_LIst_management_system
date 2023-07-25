#include<vector>
#include"ListNode.h"
#include "SortFunction.h"

constexpr double EPS = 1e-6;

int NameSearch(std::vector<ListMessage*>memory,int i ,int j)
{
	return memory.at(i)->name > memory.at(j)->name;
}

int IdSearch(std::vector<ListMessage*> memory, int i, int j)
{
	return memory.at(i)->id > memory.at(j)->id;
}

int wagesSearch(std::vector<ListMessage*> memory, int i, int j)
{
	return memory.at(i)->wages > (memory.at(j)->wages + EPS);
}


