#include <iostream>
#include "LinkedList.h"
#include "Structure.h"
#include <fstream>
#include <windows.h> //system "cls" "pause" trong nay
using namespace std;

int main()
{
	List list;
	CreateList(list);
	ReadFile(list, "Dulieu.txt");
	//StaticMenu(list);
	MainList(list);
	return 0;
}