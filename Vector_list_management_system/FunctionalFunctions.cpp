#include<iostream>
#include "FunctionalFunctions.h"
#include"AssistedFunctions.h"
#include"ListNode.h"
#include<fstream>
#include<vector>
#include<iomanip>
#include "SortFunction.h"
#include "FindFunction.h"



void SaveFile(std::vector<ListMessage*>memory)
{
	std::ofstream openfile("DataList.csh");
	if (openfile.is_open())
	{
		for (auto& message : memory)
		{
			openfile << message->name << std::endl << message->id << std::endl << message->wages << std::endl;
		}
	}
	openfile.close();
}


ListNode* LoadFile(std::vector<ListMessage*>&memory,ListNode*& list)
{
	std::ifstream openfile("DataList.csh");
	ListNode* temp = new ListNode;
	list->next = temp;
	ListNode* theLastTemp = temp;
	if (openfile.is_open())
	{
		while (openfile >> temp->data.name >> temp->data.id >> temp->data.wages)
		{
			memory.push_back(&temp->data);
			temp->next = new ListNode;
			theLastTemp = temp;
			temp = temp->next;
		}
	}
	theLastTemp->next = nullptr;
	delete temp;
	temp = nullptr;
	if (memory.size() == 0)
		list->next = nullptr;
	openfile.close();
	return list;
}


void View(std::vector<ListMessage*>&memory,ListNode* list)
{
	std::cout << Blank(4) << "   >--------------------------------------<" << std::endl;
	std::cout << Blank(4) << std::setw(20) << std::left << "    姓名" << std::setw(18) << "编号" << "工资" << std::endl;
	for (auto& message : memory)
	{
		if (memory.size() < 20)
			std::cout << std::endl;
		std::cout << Blank(4) << "    "  << std::setw(16) << std::left << message->name << std::setw(18)
			<< message->id << message->wages << std::endl;
	}
}

void AddPerson(std::vector<ListMessage*>&memory,ListNode*& list)
{
	while (1)
	{
		AddMenu();
		int num = InputTranslation();
		if (num >= 1 && num <= 2)
		{
			ListNode* sist = AddMessage(memory);
			if (memory.size() == 0)
			{
				memory.push_back(&sist->data);
				list->next = sist;
				SaveMessage(memory);
				return;
			}
			if (num == 1)
			{
				memory.insert(memory.begin(),&sist->data);
				sist->next = list->next;
				list->next = sist;
				SaveMessage(memory);
				system("pause");
			}
			else
			{
				memory.push_back(&sist->data);
				ListNode* temp = list;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->next = sist;
				SaveMessage(memory);
				system("pause");
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
			std::cout << std::endl << Blank(5) << "     ";
			system("pause");
		}
	}
}

void Deletely(std::vector<ListMessage*>& memory, ListNode*& list)
{
	int id = DeleteMessage(),i = 0;
	if (memory.size() == 0)
	{
		std::cout << std::endl << Blank(6) << "暂无匹配数据!";
		return;
	}
	ListNode* temp = list;
	ListNode* sist = temp;
	for (auto& message : memory)
	{
		sist = temp;
		temp = temp->next;
		if (message->id == id)
		{
			std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << message->name << std::setw(18)
				<< message->id << message->wages << std::endl;
			std::cout << std::endl << Blank(4) << "    是否删除匹配数据?\t\ty[Y]/n[N]" << std::endl << Blank(6) << "请选择:";
			int num = Judge();
			if (num == 1)
			{
				memory.erase(memory.begin() + i);
				sist->next = temp->next;
				delete temp;
				SaveMessage(memory);
				return;
			}
			std::cout << std::endl << Blank(6) << (num == 0 ? "    已取消删除！" : "无效操作已取消删除！") << std::endl;
			return;
		}
		i++;
	}
	std::cout << std::endl << Blank(6) << "暂无匹配数据!";
}

void Modify(std::vector<ListMessage*>& memory, ListNode*& list)
{
	int id = DeleteMessage(), i = 0;
	if (memory.size() == 0)
	{
		std::cout << std::endl << Blank(6) << "暂无匹配数据!";
		return;
	}
	ListNode* temp = list;
	for (auto& message : memory)
	{
		temp = temp->next;
		if (message->id == id)
		{
			std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << message->name << std::setw(18)
				<< message->id << message->wages << std::endl;
			std::cout << std::endl << Blank(4) << "    是否修改匹配数据?\t\ty[Y]/n[N]" << std::endl << Blank(6) << "请选择:";
			int num = Judge();
			if (num == 1)
			{
				ListNode* sist = AddMessage(memory);
				temp->data = sist->data;
				memory.at(i) = &temp->data;
				SaveMessage(memory);
				return;
			}
			std::cout << std::endl << Blank(6) << (num == 0 ? "    已取消修改！" : "无效操作已取消修改！") << std::endl;
			return;
		}
		i++;
	}
	std::cout << std::endl << Blank(6) << "暂无匹配数据!";
}


void FindFunction(std::vector<ListMessage*>& memory, ListNode*& list)
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
			typedef int (*Find)(ListMessage* data,std::string s);
			Find IsFind[] = {(Find)NameFind,(Find)IdFind,(Find)WagesFind,(Find)SimilarFind};
			std::cout << Blank(3) << "       >----------------------------------------------<" << std::endl;
			std::cout << Blank(4) << std::setw(20) << std::left << "    姓名" << std::setw(18) << "编号" << "工资" << std::endl;
			if (num == 2)
			{
				for (auto message : memory)
				{
					if (IdFind(message,i))
					{
						std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << message->name << std::setw(18)
							<< message->id << message->wages << std::endl;
					}
				}
			}
			if (num == 3)
			{
				for (auto message : memory)
				{
					if (WagesFind(message, w))
					{
						std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << message->name << std::setw(18)
							<< message->id << message->wages << std::endl;
					}
				}
			}
			if(num == 1 || num == 4)
			{
				for (auto message : memory)
				{
					if (IsFind[num - 1](message, s))
					{
						std::cout << std::endl << Blank(4) << "    " << std::setw(16) << std::left << message->name << std::setw(18)
							<< message->id << message->wages << std::endl;
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

void Sort(std::vector<ListMessage*>& memory, ListNode*& list)
{
	typedef int(*Funcs)(std::vector<ListMessage*>memory, int i, int j);
	Funcs funcs[] = {(Funcs)NameSearch,(Funcs)IdSearch,(Funcs)wagesSearch};
	while (1)
	{
		SortMenu();
		int num = InputTranslation();
		if (num >= 1 && num <= 3)
		{
			ListMessage* data = memory.at(0);
			for (int i = 0; i < memory.size() - 1; i++)
			{
				for (int j = i + 1; j < memory.size(); j++)
				{
					if (funcs[num - 1](memory, i, j))
					{
						data = memory.at(i);
						memory.at(i) = memory.at(j);
						memory.at(j) = data;
					}
				}
			}
			View(memory,list);
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





