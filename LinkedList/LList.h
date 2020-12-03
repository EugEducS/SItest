#pragma once
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <vector>
#include "./third_party/json.hpp"

struct ListNode {
	ListNode* prev = NULL;
	ListNode* next = NULL;
	ListNode* rand = NULL; // ���� Null
	std::string data;
};

class List {
public:
	List();
	~List() {};
	void Add(std::string);
	void PrintAllData();
	void PrintAllData(void (*f) (std::string));
	void PrintRandom();
	void Serialize(FILE*); // ����������. fopen(path, "wb");
	void Deserialize(FILE*); //��������. fopen(path, "rb");
private:
	ListNode* head;
	ListNode* tail;
	int count;
};