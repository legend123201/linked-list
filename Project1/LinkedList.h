#pragma once
#include "Structure.h"

void StaticMenu(List &list);
void ReadFile(List& list, const char namefile[]);
int InputAddData();
void OutputConsolList(List& list);
void CreateList(List &list);
bool Empty(List list);
void InsertFirst(List& list, int addData);
void InsertLast(List& list, int addData);
void InsertAfter(PTRList& p, int addData);
void InsertOrder(List& list, int addData);
void DeleteFirst(List& list);
void DeleteLast(List& list);
void DeleteAfter(PTRList& p);
void DeleteInfo(List &list, int delData);
PTRList endNode(PTRList firstNode);
PTRList prevNode(PTRList firstNode, PTRList currentNode);
void Keyhit_Move(PTRList& firstNode, PTRList& lastNode, PTRList& currentNode, NodeDauTrang& x, int keyhit);
void Keyhit_Delete(List& list, PTRList& firstNode, PTRList& lastNode, PTRList& currentNode, NodeDauTrang& x, int keyhit);
void Output10Nodes(PTRList firstNode, PTRList lastNode, PTRList currentNode, NodeDauTrang x);
void CapnhatNodesdautrang(NodeDauTrang& x);
void MainList(List& list);