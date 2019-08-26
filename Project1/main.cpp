#include <iostream>
#include "LinkedList.h"
#include "Tree.h"
#include "Structure.h"
#include <fstream>
#include <windows.h> //system "cls" "pause" trong nay
using namespace std;

int main()
{
	List list;
	//PTRTree root;
	CreateList(list);
	ReadFile(list, "Dulieu.txt");
	//StaticMenu(list);
	MainList(list);
	//CreateTree(root);
	//ReadFile(root, "DulieuTree.txt");
	//StaticMenu(root);
	return 0;
}