#pragma once

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
