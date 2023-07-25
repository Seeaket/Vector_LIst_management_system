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
	std::cout << Blank(6) << "1�������Ϣ" << std::endl;
	std::cout << Blank(6) << "2�������Ϣ" << std::endl;
	std::cout << Blank(6) << "3��ɾ����Ϣ" << std::endl;
	std::cout << Blank(6) << "4���޸���Ϣ" << std::endl;
	std::cout << Blank(6) << "5��������Ϣ" << std::endl;
	std::cout << Blank(6) << "6����Ϣ����" << std::endl;
	std::cout << Blank(6) << "0���˳�ϵͳ" << std::endl;
	std::cout << Blank(5) << ">---------------------------<" << std::endl << Blank(6) << "��ѡ��:";
}

void AddMenu()
{
	system("cls");
	std::cout << Blank(5) << ">---------------------------<" << std::endl;
	std::cout << Blank(5) << "     Vector-List-System" << std::endl;
	std::cout << Blank(6) << "1���ײ����" << std::endl;
	std::cout << Blank(6) << "2��β�����" << std::endl;
	std::cout << Blank(6) << "3�����ز˵�" << std::endl;
	std::cout << Blank(5) << ">---------------------------<" << std::endl << Blank(6) << "��ѡ��:";
}

void FindMenu()
{
	system("cls");
	std::cout << Blank(5) << ">---------------------------<" << std::endl;
	std::cout << Blank(5) << "  Vector-List-System-Search" << std::endl;
	std::cout << Blank(6) << "1����������" << std::endl;
	std::cout << Blank(6) << "2����Ų���" << std::endl;
	std::cout << Blank(6) << "3�����ʶβ���" << std::endl;
	std::cout << Blank(6) << "4��ģ������" << std::endl;
	std::cout << Blank(6) << "5�����ز˵�" << std::endl;
	std::cout << Blank(5) << ">---------------------------<" << std::endl << Blank(6) << "��ѡ��:";
}

void SortMenu()
{
	system("cls");
	std::cout << Blank(5) << ">---------------------------<" << std::endl;
	std::cout << Blank(5) << "   Vector-List-System-Sort" << std::endl;
	std::cout << Blank(6) << "1����������" << std::endl;
	std::cout << Blank(6) << "2���������" << std::endl;
	std::cout << Blank(6) << "3����������" << std::endl;
	std::cout << Blank(6) << "4�����ز˵�" << std::endl;
	std::cout << Blank(5) << ">---------------------------<" << std::endl << Blank(6) << "��ѡ��:";
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
	std::cout << Blank(4) << "   >-----------������ʾ¼����Ϣ-----------<" << std::endl;
	ListNode* tist = new ListNode;
	tist->next = nullptr;
	std::cout << std::endl << Blank(6) << "����:";
	std::string name;
	std::cin >> name;
	std::cout << std::endl << Blank(6) << "���:";
	int id, num = 1;
	std::cin >> id;
	while(num--)
	{
		for (auto& message : memory)
		{
			if (message->id == id)
			{
				num++;
				std::cout << Blank(6) << "    ����ظ�!";
				std::cout << std::endl << Blank(6) << "���:";
				std::cin >> id;
			}
			break;
		}
	}
	std::cout << std::endl << Blank(6) << "����:";
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
	std::cout << Blank(6) << "   �����ɹ�!" << std::endl;
	Dealy(200);
}

int DeleteMessage()
{
	std::cout << Blank(4) << "   >--------------------------------------<" << std::endl;
	std::cout << Blank(5) << "������ɾ���ı��:";
	int id;
	std::cin >> id;
	std::cout << Blank(3) << "       >----------------------------------------------<" << std::endl;
	std::cout << Blank(4) << std::setw(20) << std::left << "    ����" << std::setw(18) << "���" << "����" << std::endl;
	return id;
}


