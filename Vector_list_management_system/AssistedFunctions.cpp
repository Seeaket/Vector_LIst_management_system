#include <iostream>
#include<iomanip>
#include"FunctionalFunctions.h"
#include "AssistedFunctions.h"
#include"ListNode.h"
#include<chrono>
#include<thread>
#include<vector>

void Menu()
{
	std::cout << Blank(5) << ">---------------------------<" << std::endl;
	std::cout << Blank(5) << "     Vector-List-System" << std::endl;
	std::cout << Blank(6) << "1、浏览信息" << std::endl;
	std::cout << Blank(6) << "2、添加信息" << std::endl;
	std::cout << Blank(6) << "3、删除信息" << std::endl;
	std::cout << Blank(6) << "4、修改信息" << std::endl;
	std::cout << Blank(6) << "5、查找信息" << std::endl;
	std::cout << Blank(6) << "6、信息排序" << std::endl;
	std::cout << Blank(6) << "0、退出系统" << std::endl;
	std::cout << Blank(5) << ">---------------------------<" << std::endl << Blank(6) << "请选择:";
}

void AddMenu()
{
	system("cls");
	std::cout << Blank(5) << ">---------------------------<" << std::endl;
	std::cout << Blank(5) << "     Vector-List-System" << std::endl;
	std::cout << Blank(6) << "1、首部添加" << std::endl;
	std::cout << Blank(6) << "2、尾部添加" << std::endl;
	std::cout << Blank(6) << "3、返回菜单" << std::endl;
	std::cout << Blank(5) << ">---------------------------<" << std::endl << Blank(6) << "请选择:";
}

void FindMenu()
{
	system("cls");
	std::cout << Blank(5) << ">---------------------------<" << std::endl;
	std::cout << Blank(5) << "  Vector-List-System-Search" << std::endl;
	std::cout << Blank(6) << "1、姓名查找" << std::endl;
	std::cout << Blank(6) << "2、编号查找" << std::endl;
	std::cout << Blank(6) << "3、工资段查找" << std::endl;
	std::cout << Blank(6) << "4、模糊查找" << std::endl;
	std::cout << Blank(6) << "5、返回菜单" << std::endl;
	std::cout << Blank(5) << ">---------------------------<" << std::endl << Blank(6) << "请选择:";
}

void SortMenu()
{
	system("cls");
	std::cout << Blank(5) << ">---------------------------<" << std::endl;
	std::cout << Blank(5) << "   Vector-List-System-Sort" << std::endl;
	std::cout << Blank(6) << "1、姓名排序" << std::endl;
	std::cout << Blank(6) << "2、编号排序" << std::endl;
	std::cout << Blank(6) << "3、工资排序" << std::endl;
	std::cout << Blank(6) << "4、返回菜单" << std::endl;
	std::cout << Blank(5) << ">---------------------------<" << std::endl << Blank(6) << "请选择:";
}

std::string Blank(int num)
{
	std::string tabs(num,'\t');
	return tabs;
}

int Judge()
{
	char c;
	std::cin >> c;
	if (c == 'y' || c == 'Y')
		return 1;
	else if (c == 'n' || c == 'N')
		return 0;
	return -1;
}

int InputTranslation()
{
	char c[20];
	std::cin >> c;
	return atoi(c);
}

ListNode* AddMessage(std::vector<ListMessage*>memory)
{
	std::cout << Blank(4) << "   >-----------根据提示录入信息-----------<" << std::endl;
	ListNode* tist = new ListNode;
	tist->next = nullptr;
	std::cout << std::endl << Blank(6) << "姓名:";
	std::string name;
	std::cin >> name;
	std::cout << std::endl << Blank(6) << "编号:";
	int id, num = 1;
	std::cin >> id;
	while(num--)
	{
		for (auto& message : memory)
		{
			if (message->id == id)
			{
				num++;
				std::cout << Blank(6) << "    编号重复!";
				std::cout << std::endl << Blank(6) << "编号:";
				std::cin >> id;
			}
			break;
		}
	}
	std::cout << std::endl << Blank(6) << "工资:";
	float wage;
	std::cin >> wage;
	tist->data.name = name, tist->data.id = id, tist->data.wages = wage;
	return tist;
}

void Dealy(int num)
{
	std::cout << Blank(6) << "     ";
	while (num -= 200)
	{
		auto time_t = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(num);
		std::cout << ".";
		std::this_thread::sleep_until(time_t);
	}
	auto time_t = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(num);
	std::this_thread::sleep_until(time_t);
	std::cout << std::endl;
}

void SaveMessage(std::vector<ListMessage*> memory)
{
	Dealy(800);
	SaveFile(memory);
	std::cout << Blank(6) << "   操作成功!" << std::endl;
	Dealy(200);
}

int DeleteMessage()
{
	std::cout << Blank(4) << "   >--------------------------------------<" << std::endl;
	std::cout << Blank(5) << "请输入删除的编号:";
	int id;
	std::cin >> id;
	std::cout << Blank(3) << "       >----------------------------------------------<" << std::endl;
	std::cout << Blank(4) << std::setw(20) << std::left << "    姓名" << std::setw(18) << "编号" << "工资" << std::endl;
	return id;
}


