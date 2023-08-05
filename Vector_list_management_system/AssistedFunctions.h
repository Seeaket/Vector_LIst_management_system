#pragma once
#include"ListNode.h"
#include<list>


void Menu();

void AddMenu();

void FindMenu();

void SortMenu();

std::string Blank(int num);

int Judge();

int InputTranslation();

void AddMessage(std::list<ListMessage>& memory);

void Dealy(int num);

void SaveMessage(std::list<ListMessage>& memory);

int DeleteMessage();


