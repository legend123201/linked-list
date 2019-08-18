#pragma once
#include"Structure.h"

void StaticMenu(PTRTree& p);
void ReadFile(PTRTree& root, const char namefile[]);
int InputAddKey();
void CreateTree(PTRTree& root);
bool Empty(PTRTree root);
void InsertTree(PTRTree& p, int addKey, int addData);
void DeleteTree(PTRTree& p, int delData);
void DeleteTreeCase3(PTRTree& p, PTRTree& temp);
void OutPutConsole_LNR(PTRTree p);
void OutPutConsole_NLR(PTRTree p);
void OutPutConsole_LRN(PTRTree p);
void OutputConsole_NodesLeftRight(PTRTree p);
int MainTree();