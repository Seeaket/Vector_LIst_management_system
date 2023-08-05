#include<iostream>
#include<list>
#include "FunctionalFunctions.h"
#include"AssistedFunctions.h"
#include"ListNode.h"
#include<fstream>
#include<iomanip>
#include "FindFunction.h"
#include<algorithm>
#include"SortFunction.h"

ListMessage message;

void SaveFile(std::list<ListMessage>& memory)
{
	std::ofstream openfile("DataList.csh");
	if (openfile.is_open())
	{
		for (auto& messages : memory)
		{
			openfile << messages.name << std::endl << messages.id << std::endl << messages.wages << std::endl;
		}
	}
	openfile.close();
}


void LoadFile(std::list<ListMessage>&memory)
{
	std::ifstream openfile("DataList.csh");
	if (openfile.is_open())
	{
		while (openfile >> message.name >> message.id >> message.wages)
		{
			memory.push_back(message);
		}
	}
	openfile.close();
}


void View(std::list<ListMessage>&memory)
{
	std::cout << Blank(4) << "   >--------------------------------------<" << std::endl;
	std::cout << Blank(4) << std::setw(20) << std::left << "    姓名" << std::setw(18) << "编号" << "工资" << std::endl;
	for (auto& messages : memory)
	{
		if (memory.size() < 7)
			std::cout << std::endl;
		std::cout << Blank(4) << "    "  << std::setw(16) << std::left << messages.name << std::setw(18)
			<< messages.id << messages.wages << std::endl;
	}
}

void AddPerson(std::list<ListMessage>&memory)
{
	while (1)
	{
		AddMenu();
		int num = InputTranslation();
		if (num >= 1 && num <= 2)
		{
			AddMessage(memory);
			if (num == 1)
			{
				memory.push_front(message);
				SaveMessage(memory);
			}
			else
			{
				memory.push_back(message);
				SaveMessage(memory);
			}
		}
		else if (num == 3)
		{
			std::cout << Blank(6) << "即将返回主菜单!" << std::endl;
			break;
		}
		else
		{
			std::cout << Blank(6) << "   无效输入!" << std::endl;
		}
		std::cout << std::endl << Blank(5) << "     ";
		system("pause");
	}
}

void Deletely(std::list<ListMessage>& memory)
{
	int id = DeleteMessage(),i = 0;
	if (memory.size() == 0)
	{
		std::cout << std::endl << Blank(6) << "暂无匹配数据!";
		return;
	}
	auto it = memory.begin();
	for (auto& messages : memory)
	{
		if (messages.id == id)
		{
			std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << messages.name << std::setw(18)
				<< messages.id << messages.wages << std::endl;
			std::cout << std::endl << Blank(4) << "    是否删除匹配数据?\t\ty[Y]/n[N]" << std::endl << Blank(6) << "请选择:";
			int num = Judge();
			if (num == 1)
			{
				memory.erase(it);
				SaveMessage(memory);
				return;
			}
			std::cout << std::endl << Blank(6) << (num == 0 ? "    已取消删除！" : "无效操作已取消删除！") << std::endl;
			return;
		}
		it++;
	}
	std::cout << std::endl << Blank(6) << "暂无匹配数据!";
}

void Modify(std::list<ListMessage>& memory)
{
	int id = DeleteMessage(), i = 0;
	if (memory.size() == 0)
	{
		std::cout << std::endl << Blank(6) << "暂无匹配数据!";
		return;
	}
	auto it = memory.begin();
	for (auto& messages : memory)
	{
		if (messages.id == id)
		{
			std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << messages.name << std::setw(18)
				<< messages.id << messages.wages << std::endl;
			std::cout << std::endl << Blank(4) << "    是否修改匹配数据?\t\ty[Y]/n[N]" << std::endl << Blank(6) << "请选择:";
			int num = Judge();
			if (num == 1)
			{
				AddMessage(memory);
				*it = message;
				SaveMessage(memory);
				return;
			}
			std::cout << std::endl << Blank(6) << (num == 0 ? "    已取消修改！" : "无效操作已取消修改！") << std::endl;
			return;
		}
		it++;
	}
	std::cout << std::endl << Blank(6) << "暂无匹配数据!";
}


void FindFunction(std::list<ListMessage>& memory)
{
	while (1)
	{
		FindMenu();
		int num = InputTranslation(),counter = 1;
		if (num >= 1 && num <= 4)
		{
			std::cout << Blank(4) << "   >--------------------------------------<" << std::endl;
			std::cout << Blank(5) << "请输入查找信息:";
			std::string s,w,w1,w2;
			int i;
			if (num == 1)
				std::cin >> s;
			else if (num == 2)
				std::cin >> i;
			else if (num == 3)
			{
				std::cin >> w1;
				std::cout << Blank(5) << "请输入查找信息2:";
				std::cin >> w2;
				w = w1 + ',' + w2;
			}
			else
				std::cin >> s;
			typedef int (*Find)(ListMessage data,std::string s);
			Find IsFind[] = {(Find)NameFind,(Find)IdFind,(Find)WagesFind,(Find)SimilarFind};
			std::cout << Blank(3) << "       >----------------------------------------------<" << std::endl;
			std::cout << Blank(4) << std::setw(20) << std::left << "    姓名" << std::setw(18) << "编号" << "工资" << std::endl;
			if (num == 2)
			{
				for (auto messages : memory)
				{
					if (IdFind(messages,i))
					{
						std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << messages.name
							<< std::setw(18) << messages.id << messages.wages << std::endl;
					}
				}
			}
			if (num == 3)
			{
				for (auto messages : memory)
				{
					if (WagesFind(messages, w))
					{
						std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << messages.name << std::setw(18)
							<< messages.id << messages.wages << std::endl;
					}
				}
			}
			if(num == 1 || num == 4)
			{
				for (auto messages : memory)
				{
					if (IsFind[num - 1](messages, s))
					{
						std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << messages.name << std::setw(18)
							<< messages.id << messages.wages << std::endl;
					}
				}
			}
			std::cout << std::endl << Blank(5) << "     ";
			system("pause");
		}
		else if (num == 5)
		{
			std::cout << Blank(6) << "即将返回主菜单!" << std::endl;
			break;
		}
		else
		{
			std::cout << Blank(6) << "   无效输入!" << std::endl;
			std::cout << std::endl << Blank(5) << "     ";
			system("pause");
		}
	}
}

void Sort(std::list<ListMessage>& memory)
{
	typedef int(*Funcs)(std::list<ListMessage>&memory);
	while (1)
	{
		SortMenu();
		int num = InputTranslation();
		if (num >= 1 && num <= 3)
		{
			num == 1 ? memory.sort(NameSort) : (num == 2 ? memory.sort(IdSort) : memory.sort(WageSort));
			View(memory);
			std::cout << std::endl << Blank(5) << "     ";
			system("pause");
		}
		else if (num == 4)
		{
			std::cout << Blank(6) << "即将返回主菜单!" << std::endl;
			break;
		}
		else
		{
			std::cout << Blank(6) << "   无效输入!" << std::endl;
			std::cout << std::endl << Blank(5) << "     ";
			system("pause");
		}
	}
}





