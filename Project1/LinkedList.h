#pragma once
#include "Structure.h"

void StaticMenu(List &list);
void ReadFile(List& list, const char namefile[]);
int InputAddData();
void OutputConsolList(List& list);
void CreateList(List &list);
bool Empty(List& list);
void InsertFirst(List& list, int addData);
void InsertLast(List& list, int addData);
void InsertAfter(PTRList& p, int addData);
void InsertOrder(List& list, int addData);