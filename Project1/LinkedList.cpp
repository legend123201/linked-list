#include "LinkedList.h"
#include <iostream> // "NULL" duoc dinh nghia trong day
#include <fstream>

using namespace std;

void StaticMenu(List &list)
{
	int a;
	do
	{
		system("cls");
		OutputConsolList(list);
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
	} while (a != 0);
}

void ReadFile(List &list, const char namefile[])
{
	int tempData;
	ifstream f(namefile);
	if (!f.fail())
	{
		cout << "Nhap file thanh cong" << endl;
	}
	else
		cout << "Nhap file khong thanh cong" << endl;

	while (!f.eof()) //neu file rong no van chay va cho 1 gia tri rac, nen phia tren phai co ham ktra file rong
	{
		f >> tempData;
		InsertLast(list, tempData);
	}
	f.close();
}

int InputAddData()
{
	int addData;
	cout << "\nNhap gia tri muon them: ";
	cin >> addData;
	return addData;
}

void OutputConsolList(List& list)
{
	if (list.first == NULL)
		cout << "Khong co phan tu nao!";
	else
	{
		for (PTRList run = list.first; run != NULL; run = run->next)
		{
			cout << run->data <<" ";
		}
	}
}

void CreateList(List& list)
{
	list.first = NULL;
	list.last = NULL;
}

bool Empty(List& list)
{
	if (list.first == NULL)
		return true;
	return false;
}

void InsertFirst(List& list, int addData)
{
	PTRList p = new NodesLinkedList;
	if (p == NULL)
	{
		cout << "Bo nho cua ban da het. Khong them duoc phan tu.";
		return;
	}
	p->data = addData;
	p->next = NULL;
	//TH rong va TH khong rong
	if (Empty(list))
	{
		list.first = list.last = p;
	}
	else
	{
		p->next = list.first;
		list.first = p;
	}
}

void InsertLast(List& list, int addData)
{
	PTRList p = new NodesLinkedList;
	if (p == NULL)
	{
		cout << "Bo nho cua ban da het. Khong them duoc phan tu.";
		return;
	}
	p->data = addData;
	p->next = NULL;
	//TH rong va TH khong rong
	if (Empty(list))
	{
		list.first = list.last = p;
	}
	else
	{
		list.last->next = p;
		list.last = p;
	}
}

void InsertAfter(PTRList& p, int addData)
{
	PTRList q = new NodesLinkedList;
	if (q == NULL)
	{
		cout << "Bo nho cua ban da het. Khong them duoc phan tu.";
		return;
	}
	q->data = addData;
	//q la phan tu can them sau p, lay q tro toi node ma p dang tro toi truoc vi lat nua mat, roi sau do cho p tro toi q
	q->next = p->next;
	p->next = q;
}

void InsertOrder(List& list, int addData) //sap xep tang dan
{
	//neu ma rong thi cho vao dau, hoac la thu tu ngay vi tri dau thi cho vao dau
	if (Empty(list) || list.first->data > addData)
	{
		InsertFirst(list, addData);
	}
	else //ko rong va ko phai thu tu dau
	{
		PTRList run;
		for (run = list.first; run->next != NULL && run->next->data < addData; run = run->next); //luon xu li tren run->next, de khi tim dc "run" thi xu li node dang sau run cho ez
		InsertAfter(run, addData);
	}
}
