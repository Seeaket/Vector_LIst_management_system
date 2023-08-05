#include<iostream>
#include"AssistedFunctions.h"
#include"FunctionalFunctions.h"
#include"ListNode.h"
#include<list>
#include<crtdbg.h>

using namespace std;

int main()
{
	typedef int (*Func)(list<ListMessage>& memory);
	std::list<ListMessage>memory;
	LoadFile(memory);
	Func function[] = { (Func)View,(Func)AddPerson,(Func)Deletely,(Func)Modify,(Func)FindFunction,(Func)Sort};
	while (1)
	{
		system("cls");
		Menu();
		int num = InputTranslation();
		if (num >= 1 && num <= 6)
			function[num - 1](memory);
		else if(num == 0)
		{
			cout << Blank(4) << "   >--------------------------------------<" << endl;
			cout << Blank(4) << "    �Ƿ��˳�ϵͳ��\t\ty[Y]/n[N]" << endl << Blank(6) << "��ѡ��:";
			int num1 = Judge();
			if (num1 == 1)
				break;
			cout << endl << Blank(5) << (num1 == 0 ? "      ��ȡ���˳�ϵͳ!" : "    ��Ч������ȡ���˳�!") << endl;
		}
		else
		{
			cout << Blank(6) << "    ��Ч����!" << endl;
		}
		cout << endl << Blank(5) << "     ";
		system("pause");
	}
	return 0;
}



