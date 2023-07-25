#pragma once
#include<iostream>
#include<vector>
#include"ListNode.h"


void SaveFile(std::vector<ListMessage*>memory);
struct ListNode* LoadFile(std::vector<ListMessage*>& memory, ListNode*& list);

void View(std::vector<ListMessage*>&memory,ListNode* list);

void AddPerson(std::vector<ListMessage*>& memory, ListNode*& list);

void Deletely(std::vector<ListMessage*>& memory, ListNode*& list);

void Modify(std::vector<ListMessage*>& memory, ListNode*& list);

void FindFunction(std::vector<ListMessage*>& memory, ListNode*& list);

void Sort(std::vector<ListMessage*>& memory, ListNode*& list);
