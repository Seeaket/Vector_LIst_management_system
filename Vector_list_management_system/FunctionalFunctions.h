#pragma once
#include<iostream>
#include<list>
#include"ListNode.h"


void SaveFile(std::list<ListMessage>& memory);
void  LoadFile(std::list<ListMessage>& memory);

void View(std::list<ListMessage>& memory);

void AddPerson(std::list<ListMessage>& memory);

void Deletely(std::list<ListMessage>& memory);

void Modify(std::list<ListMessage>& memory);

void FindFunction(std::list<ListMessage>& memory);

void Sort(std::list<ListMessage>& memory);
