#pragma once
#include<iostream>


struct ListMessage
{
	std::string name;
	int id;
	float wages;
};

struct ListNode
{
	ListMessage data;
	ListNode* next;
};