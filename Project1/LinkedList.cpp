#include "LinkedList.h"
#include <iostream> // "NULL" duoc dinh nghia trong day
#include <fstream>
#include "Design.h"
#include <conio.h> //_getch() trong nay

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
		cout << "\n4. DeleteFirst.";
		cout << "\n5. DeleteLast.";
		cout << "\n6. DeleteInfo.";
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
			DeleteFirst(list);
			break;
		}
		case 5:
		{
			DeleteLast(list);
			break;
		}
		case 6:
		{
			DeleteInfo(list, InputAddData());
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
	int Data;
	cout << "\nNhap gia tri muon them/xoa: ";
	cin >> Data;
	return Data;
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
	//neu ma rong thi cho vao dau, hoac la thu tu ngay vi tri dau thi cho vao dau, dung de chan dau
	if (Empty(list) || list.first->data > addData)
	{
		InsertFirst(list, addData);
	}
	else if(list.last->data <= addData) //ko co if nay thi van them vao cuoi dc o else phia duoi nhung last no ko cap nhat va cai nay cung de chan cuoi
	{
		InsertLast(list, addData);
	}
	else //ko rong va ko phai thu tu dau
	{
		PTRList run;
		for (run = list.first; run->next != NULL && run->next->data < addData; run = run->next); //luon xu li tren run->next, de khi tim dc "run" thi xu li node dang sau run cho ez
		InsertAfter(run, addData);
	}
}

void DeleteFirst(List& list)
{
	if (Empty(list))
	{
		cout << "Khong co phan tu de xoa.";
		return;
	}
	//	if(l.First == l.Last)
	//	{
	//		l.First = l.Last = NULL;
	//	}
	//  Ko can vi truong hop 1 phan tu vs nhieu phan tu thi giai quyet giong nhau
	PTRList p = list.first;
	list.first = list.first->next;
	delete p;
}

void DeleteLast(List& list)
{
	if (Empty(list))
	{
		cout << "Khong co phan tu de xoa.";
		return;
	}
	if (list.first == list.last) //danh sach chi 1 phan tu
	{
		delete list.first;
		list.first = list.last = NULL;
	}
	for (PTRList p = list.first; p != NULL; p = p->next)
	{
		if (p->next == list.last) // tim dc cai truoc cai last
		{
			delete list.last;
			p->next = NULL;
			list.last = p;
		}
	}
}

void DeleteAfter(PTRList& p)
{
	PTRList q;
	q = p->next; //p -> next = q
	p->next = q->next; //noi cai next bac cau qua roi xoa
	delete q;
}

void DeleteInfo(List& list, int delData)
{
	if (Empty(list))
	{
		cout << "\nKhong the xoa vi danh sach rong.";
		return;
	}
	if (list.first->data == delData) //neu node can xoa la first
	{
		cout << "\nDa xoa xong" << endl;
		DeleteFirst(list);
		return;
	}
	if (list.last->data == delData) //neu node can xoa la last, ham duoi co xoa neu no la last luon nhung no ko cap nhat lai last
	{
		cout << "\nDa xoa xong" << endl;
		DeleteLast(list);
		return;
	}
	/*PTRList run;*/
	/*for (run = list.first; run->next != NULL && run->next->data != delData; run = run->next); */
	//luon xu li tren run->next, de khi tim dc "run" thi xu li node dang sau run cho ez
	//(luc truoc suy nghi the nay) dong nay khac voi dong o tren cho run != NULL, neu de la run->next != NULL thi neu ko co phan tu can tim thi no se dung o phan tu cuoi-> sai (run den cuoi cai ko co run-> next->data luon, chuong trinh ko chay duoc)
	for (PTRList run = list.first; run->next != NULL; run = run->next)
	{
		if (run->next->data == delData)
		{
			DeleteAfter(run);
			return;
		}
	}
	cout << "Phan tu can xoa ko ton tai!";
}

void Keyhit_Move(int keyhit)
{
	if (keyhit == KEY_UP) {
		if (currentList != firstList) {
			currentList = prevList(firstList, currentList);
		}
		else if (currentList == firstList) {
			currentList = lastList;
		}
	}
	else if (keyhit == KEY_DOWN) {
		if (currentList != lastList) {
			currentList = currentList->next;
		}
		else if (currentList == lastList) {
			currentList = firstList;
		}
	}
	else if (keyhit == KEY_RIGHT) {
		if (lastList->next != NULL) {
			x.hoaDonDauTrang[++x.trangHienTai] = lastList->next;
			firstList = lastList->next;
			lastList = endList(firstList);
			currentList = firstList;
		}
	}
	else if (keyhit == KEY_LEFT) {
		if (x.trangHienTai > 1) {
			//delete x.hoadondautrang[x.tranghientai];
			firstList = x.hoaDonDauTrang[--x.trangHienTai];
			lastList = endList(firstList);
			currentList = firstList;
		}
	}
}

void Output10Nodes()
{
	int j = 0;
	int i = 0;
	int t = (x.trangHienTai - 1) * 10;
	for (PTRHoaDon run = firstList; run != lastList->next, run != NULL; run = run->next) {
		if (run == currentList)
		{
			TextColor(4);
			textbk(15);
		}
		else
		{
			TextColor(0);
			textbk(15);
		}
		j = 0;
		t += 1;
		gotoXY(36 + j, 18 + i);
		cout << CenterTextInSpace(to_string(t), BOXHDWIDE - 1);
		j += 25;
		gotoXY(36 + j, 18 + i);
		cout << CenterTextInSpace(run->infoHoaDon.soHoaDon, BOXHDWIDE - 1);
		j += 25;
		gotoXY(36 + j, 18 + i);
		string temp_date;
		temp_date = IntToString(run->infoHoaDon.ngayNhapHoaDon.date) + " / " + IntToString(run->infoHoaDon.ngayNhapHoaDon.month) + " / " + IntToString(run->infoHoaDon.ngayNhapHoaDon.year);
		cout << CenterTextInSpace(temp_date, BOXHDWIDE - 1);
		j += 25;
		gotoXY(36 + j, 18 + i);
		cout << CenterTextInSpace(run->infoHoaDon.loai, BOXHDWIDE - 1);
		j += 25;
		gotoXY(36 + j, 18 + i);
		string temp_trigia = to_string(this->TriGiaHD(run));
		cout << CenterTextInSpace(DelFloatTrail(temp_trigia), BOXHDWIDE - 1);
		i += 2;
	}
	TextColor(0);
	textbk(15);
	if (t < (x.trangHienTai - 1) * 10 + 10) {
		for (int k = t; k <= (x.trangHienTai - 1) * 10 + 10; k++) {
			j = 0;
			gotoXY(36 + j, 18 + i);
			cout << CenterTextInSpace("", BOXHDWIDE - 1);
			j += 25;
			gotoXY(36 + j, 18 + i);
			cout << CenterTextInSpace("", BOXHDWIDE - 1);
			j += 25;
			gotoXY(36 + j, 18 + i);
			cout << CenterTextInSpace("", BOXHDWIDE - 1);
			j += 25;
			gotoXY(36 + j, 18 + i);
			cout << CenterTextInSpace("", BOXHDWIDE - 1);
			j += 25;
			gotoXY(36 + j, 18 + i);
			cout << CenterTextInSpace("", BOXHDWIDE - 1);
			i += 2;
		}
	}
}

void MainList()
{
	PTRList firstNode, lastNode, currentNode;
	NodeDauTrang x;
	int keyhit = 0;
	while (true)
	{
		if (keyhit == 224)
			keyhit = _getch();
	}
}
