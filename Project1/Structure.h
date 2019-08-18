#pragma once
#include <iostream>

//khai bao cho ds lien ket don
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

//khai bao cho cay nhi phan

struct NodesTree
{
	int key;
	int data;	
	struct NodesTree* left;
	struct NodesTree* right;
};
typedef struct NodesTree* PTRTree;