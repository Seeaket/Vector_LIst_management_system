#pragma once
#include"ListNode.h"
#include<vector>


void Menu();

void AddMenu();

void FindMenu();

void SortMenu();

std::string Blank(int num);

int Judge();

int InputTranslation();

struct ListNode* AddMessage(std::vector<ListMessage*>memory);

void Dealy(int num);

void SaveMessage(std::vector<ListMessage*>memory);

int DeleteMessage();


