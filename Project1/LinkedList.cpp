#include "LinkedList.h"
//#include <iostream> // "NULL" duoc dinh nghia trong day

using namespace std;

int InputAddData()
{
	int addData;
	cout << "/nNhap gia tri muon them: ";
	cin >> addData;
	return addData;
}

void OutputConsolList(List& list)
{
	if (list.first == NULL)
		cout << "Khong co phan tu nao!";
	else
	{
		for (PTRList run; run != NULL; run = run->next)
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
	if (Empty(list) || list.first->data < addData)
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
