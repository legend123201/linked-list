#pragma once
#include <iostream>

struct NodesLinkedList
{
	int data;
	struct NodesLinkedList* next;
};
typedef struct NodesLinkedList* PTRList;

typedef struct
{
	PTRList first;
	PTRList last;
}List;

struct NodeDauTrang {
	int trangHienTai = 1;
	PTRList hoaDonDauTrang[20] = { NULL };
};