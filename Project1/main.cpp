#include <iostream>
#include "LinkedList.h"
#include "Structure.h"

using namespace std;

int main()
{
	List list;
	CreateList(list);
	int a;
	do
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. InsertFirst.";
		cout << "\n2. InsertLast.";
		cout << "\n3. InsertOrder.";
		cout << "\n4. .";
		cout << "\n5. .";
		cout << "\n6. .";
		cout << "\n7. . ";
		cout << "\n0. .";
		cout << "\n\n\t\t =========== END ===========";
		cout << "\nChon chuc nang: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			InsertFirst(list, InputAddData());
			break;
		}
		case 2:
		{
			InsertLast(list, InputAddData());
			break;
		}
		case 3:
		{
			InsertOrder(list, InputAddData());
			break;
		}
		case 4:
		{

			break;
		}
		case 5:
		{

			break;
		}
		case 6:
		{

			break;
		}
		case 7:
		{

			break;
		}
		default:
			break;
		}
		system("pause");
	} while (a != 0);
	return 0;
}