#include<iostream>
#include"AssistedFunctions.h"
#include"FunctionalFunctions.h"
#include"ListNode.h"
#include<vector>
#include<crtdbg.h>
using namespace std;

int main()
{
	typedef int (*Func)(vector<ListMessage*>& memory,ListNode*& head);
	std::vector<ListMessage*>memory;
	ListNode* head = new ListNode;
	head->data.name = "-1", head->data.id = -1, head->data.wages = -1.0f, head->next = nullptr;
	head = LoadFile(memory, head);
	Func function[] = { (Func)View,(Func)AddPerson,(Func)Deletely,(Func)Modify,(Func)FindFunction,(Func)Sort};
	while (1)
	{
		system("cls");
		Menu();
		int num = InputTranslation();
		if (num >= 1 && num <= 6)
			function[num - 1](memory,head);
		else if(num == 0)
		{
			cout << Blank(4) << "   >--------------------------------------<" << endl;
			cout << Blank(4) << "    是否退出系统？\t\ty[Y]/n[N]" << endl << Blank(6) << "请选择:";
			int num1 = Judge();
			if (num1 == 1)
			{
				ListNode* tempNext = head;
				while (head != nullptr)
				{
					tempNext = head->next;
					delete head;
					if(tempNext == nullptr)
						return 0;
					head = tempNext;
				}
			}
			cout << endl << Blank(5) << (num1 == 0 ? "      已取消退出系统!" : "    无效操作已取消退出!") << endl;
		}
		else
		{
			cout << Blank(6) << "    无效输入!" << endl;
		}
		cout << endl << Blank(5) << "     ";
		system("pause");
	}
	return 0;
}



