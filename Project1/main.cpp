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
	
	CreateList(list);
	ReadFile(list, "Dulieu.txt");
	List temp;
	temp = list;
	DeleteFirst(temp);
	//StaticMenu(list);
	//MainList(list);

	/*PTRTree root;
	CreateTree(root);
	ReadFile(root, "DulieuTree.txt");
	StaticMenu(root);*/
	return 0;
}