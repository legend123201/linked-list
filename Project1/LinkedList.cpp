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
	{
		cout << "Nhap file khong thanh cong" << endl;
		return;
	}
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
		int count = 1;
		for (PTRList run = list.first; run != NULL; run = run->next, count++)
		{			
			if (count == 11)
			{
				count = 1;
				cout << endl;
			}
			cout << run->data << "\t";
		}
	}
}

void OutputFirstOfPages(NodeDauTrang x)
{
	cout << endl;
	for (int i = 1; i < 20; i++)
	{
		if (x.hoaDonDauTrang[i] == NULL)
			break;	
		cout << x.hoaDonDauTrang[i]->data << " ";
	}
}

void CreateList(List& list)
{
	list.first = NULL;
	list.last = NULL;
}

bool Empty(List list)
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

int InsertOrder(List& list, int addData) //sap xep tang dan, tra ve so thu tu them phan tu //tra ve 0 co nghia la them vao cuoi
{
	int soLuongNut = 1;
	//neu ma rong thi cho vao dau, hoac la thu tu ngay vi tri dau thi cho vao dau, dung de chan dau
	if (Empty(list) || list.first->data > addData) //them vao dau tien
	{
		InsertFirst(list, addData);
		return 1; 
	}
	else if(list.last->data <= addData) //ko co if nay thi van them vao cuoi dc o else phia duoi nhung last no ko cap nhat va cai nay cung de chan cuoi
	{
		InsertLast(list, addData);
		return 0;
	}
	else //ko rong va ko phai thu tu dau
	{
		PTRList run;
		for (run = list.first; (run->next != NULL) && (run->next->data < addData); run = run->next, soLuongNut++); //luon xu li tren run->next, de khi tim dc "run" thi xu li node dang sau run cho ez
		InsertAfter(run, addData);
		return ++soLuongNut; //tra ve thu tu hien tai
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

PTRList endNode(PTRList firstNode)
{
	if (firstNode == NULL)
		return NULL;
	PTRList run = firstNode;
	for (int i = 0; i < 9 && run->next != NULL; i++, run = run->next); //run -> next != NULL de ko bi chay lo them dong run = run -> next, no se tra ve phan tu truoc NULL neu ma ko du 10 phan tu
	return run;
}

PTRList prevNode(PTRList firstNode, PTRList currentNode)
{
	if (firstNode == NULL)
		return NULL;
	PTRList run;
	for (run = firstNode; run->next != currentNode; run = run->next);
	return run;
}

void Keyhit_Move(PTRList& firstNode, PTRList& lastNode, PTRList& currentNode, NodeDauTrang& x, int keyhit)
{
	if (firstNode == NULL)
		return;
	if (keyhit == KEY_UP) {
		if (currentNode != firstNode) //khong phai nut dau 
		{
			currentNode = prevNode(firstNode, currentNode);
		}
		else if (currentNode == firstNode) //la nut dau thi cho thanh nut cuoi
		{
			currentNode = lastNode;
		}
	}
	else if (keyhit == KEY_DOWN) {
		if (currentNode != lastNode) //khong phai nut cuoi
		{
			currentNode = currentNode->next;
		}
		else if (currentNode == lastNode) //la nut cuoi thi cho thanh nut dau
		{
			currentNode = firstNode;
		}
	}
	else if (keyhit == KEY_RIGHT) {
		if (lastNode->next != NULL) // van con phan tu cho page sau
		{
			//x.hoaDonDauTrang[++x.trangHienTai] = lastNode->next; //ghi lai phan tu dau tien cua page tiep theo //luc truoc ko cap nhat tat ca cac node dau trang ngay tu luc mo chuong trinh nen can dong nay
			x.trangHienTai++;
			firstNode = lastNode->next;
			lastNode = endNode(firstNode);
			currentNode = firstNode;
		}
	}
	else if (keyhit == KEY_LEFT) {
		if (x.trangHienTai > 1) //ko phai page dau tien
		{
			//delete x.hoadondautrang[x.tranghientai]; //hoi xua lam dong nay de toi uu nhung bi sai, no chi la con tro nen ko can xoa
			firstNode = x.hoaDonDauTrang[--x.trangHienTai];
			lastNode = endNode(firstNode);
			currentNode = firstNode;
		}
	}
}

void Keyhit_Insert(List& list, PTRList& firstNode, PTRList& lastNode, PTRList& currentNode, NodeDauTrang& x, int keyhit)
{
	if (keyhit == INS)
	{
		system("cls");
		int addData;
		cout << "\nNhap so muon them: ";
		cin >> addData;
		int posNumber = InsertOrder(list, addData); //so thu tu cua phan tu them
		if (posNumber == 0) //TH them vao cuoi cung
		{
			int i; //i se la page max
			for (i = x.trangHienTai; i < 20; i++)
			{
				if (x.hoaDonDauTrang[i] == NULL)
					break;
			}
			x.trangHienTai = --i;
			//ktra xem co them trang moi hay ko
			PTRList temp = endNode(x.hoaDonDauTrang[i])->next;
			if (temp != NULL)
			{
				x.hoaDonDauTrang[i + 1] = temp;
				x.trangHienTai = i + 1;
			}
			firstNode = x.hoaDonDauTrang[x.trangHienTai];
		}
		else //cac TH khac da dung so thu tu
		{
			x.trangHienTai = (posNumber-1) / 10 + 1; //POS - 1 boi vi TH them vao 20, thi phai tru 1 moi la trang 2
			if (posNumber == 1) //them vao list.first
			{
				x.hoaDonDauTrang[1] = firstNode = list.first; //cap nhat lai node dau trang 1 va first node
			}
			else if (posNumber % 10 == 1) //TH la firstNode cua trang 2 tro len
			{
				x.hoaDonDauTrang[x.trangHienTai] = firstNode = endNode(x.hoaDonDauTrang[x.trangHienTai - 1])->next; //cap nhat lai node dau trang va firstNode hien tai la phan tu next cua lastNode trang truoc
			}//tat ca cac truong hop khac thi cung chi can cap nhat lai last node va first
			else
			{
				firstNode = x.hoaDonDauTrang[x.trangHienTai];
			}
			// xem xem sau khi them co them trang moi hay ko 
			int pageMax = CapnhatNodesdautrang_InsertCase(x); //vua cap nhat cac node dau trang vua giu lai page cuoi cung de ktra
			PTRList temp = endNode(x.hoaDonDauTrang[pageMax])->next; //temp giu vi tri lastnode.next cua page cuoi cung
			if (temp != NULL)
			{
				x.hoaDonDauTrang[pageMax + 1] = temp;
			}			
		}
		//cap nhat lai lastNode
		lastNode = endNode(firstNode);
		//cap nhat lai currentNode
		PTRList p;
		for (p = firstNode;p->data != addData; p = p->next);
		currentNode = p;
		system("cls");
	}	
}

void Keyhit_Delete(List& list, PTRList& firstNode, PTRList& lastNode, PTRList& currentNode, NodeDauTrang& x, int keyhit)
{
	if (list.first == NULL)
		return;
	if (keyhit == DEL)
	{
		if (currentNode == x.hoaDonDauTrang[x.trangHienTai]) //cur la dau trang
		{
			if (currentNode != list.first) //cur ko phai la fisrt toan bo danh sach
			{
				lastNode = endNode(x.hoaDonDauTrang[--x.trangHienTai]); //cho lastnode thanh last cua page truoc 
				firstNode = x.hoaDonDauTrang[x.trangHienTai]; //firstnode cung thanh first cua page truoc
				CapnhatNodesdautrang_DeleteCase(x);
				DeleteInfo(list, currentNode->data);
				currentNode = lastNode; //cho cur chi vao cuoi page
			}
			else //cur la first toan bo danh sach
			{
				if (list.first->next == NULL) // truong hop toan bo danh sach co 1 phan tu
				{
					DeleteInfo(list, currentNode->data);
					currentNode = firstNode = lastNode = NULL;
				}
				else // con nhieu phan tu
				{
					x.hoaDonDauTrang[x.trangHienTai] = x.hoaDonDauTrang[x.trangHienTai]->next; //cap nhat rieng cai first trang hien tai
					firstNode = firstNode->next; // first page tro next
					lastNode = endNode(firstNode);//cap nhat lai last
					CapnhatNodesdautrang_DeleteCase(x);// cap nhat cac page sau
					DeleteInfo(list, currentNode->data);
					currentNode = firstNode;//cap nhat lai current
				}
			}
		}
		else if (currentNode == lastNode) // truong hop cur la lastNode (last toan bo ds cung la 1 lastNode)
		{
			CapnhatNodesdautrang_DeleteCase(x); //cap nhat cac page sau
			DeleteInfo(list, currentNode->data);
			lastNode = currentNode = endNode(firstNode); //cap nhat lai current va last
		}
		else // truong hop cur binh thuong
		{
			CapnhatNodesdautrang_DeleteCase(x); //cap nhat cac page sau
			PTRList temp = currentNode->next;//giu vi tri cur->next
			DeleteInfo(list, currentNode->data);
			currentNode = temp;//cur = vi tri tro next hoi nay
			lastNode = endNode(firstNode); //cap nhat lai last
		}
		system("cls"); //xoa man hinh, no se viet lai danh sach o nhung hang phia duoi trong while true
	}
}

void Output10Nodes(PTRList firstNode, PTRList lastNode, PTRList currentNode, NodeDauTrang x)
{
	if (firstNode == NULL)
		return;
	int t = (x.trangHienTai - 1) * 10; //t la so thu tu
	for (PTRList run = firstNode; run != lastNode->next; run = run->next) {
		if (run == currentNode)
		{
			cout << "\n" << run->data << "  <--- ";
		}
		else
		{
			cout << "\n" << run->data;
		}	
	}
	if (t < (x.trangHienTai - 1) * 10 + 10) //neu page nay ko du 10 phan tu thi se de trang nhung vi tri con lai
	{
		for (int k = t; k <= (x.trangHienTai - 1) * 10 + 10; k++) {
			cout << " ";
		}
	}
}

void CapnhatNodesdautrang_DeleteCase(NodeDauTrang& x)
{
	for (int i = x.trangHienTai + 1; i < 20; i++)
	{
		if (x.hoaDonDauTrang[i] == NULL)
			break;
		x.hoaDonDauTrang[i] = x.hoaDonDauTrang[i]->next;
	}
}

int CapnhatNodesdautrang_InsertCase(NodeDauTrang& x) //tra ve trang max
{
	int i;
	for (i = x.trangHienTai + 1; i < 20; i++)
	{
		if (x.hoaDonDauTrang[i] == NULL)
			break;
		x.hoaDonDauTrang[i] = endNode(x.hoaDonDauTrang[i-1]->next);
	}
	return --i;
}

void MainList(List& list)
{
	PTRList firstNode, lastNode, currentNode;
	NodeDauTrang x;
	int keyhit = 0;
	//cap nhat cac node dau trang
	x.hoaDonDauTrang[x.trangHienTai++] = list.first;
	int i = 1;
	for (PTRList p = list.first; p != NULL; p = p->next, i++)
	{
		if (i == 11)
		{
			i = 1;
			x.hoaDonDauTrang[x.trangHienTai++] = p;
		}
	}
	//khoi tao cac gia tri dau tien
	x.trangHienTai = 1;
	firstNode = currentNode = x.hoaDonDauTrang[x.trangHienTai] = list.first;
	lastNode = endNode(firstNode);
	//chuong trinh chay chinh
	while (true)
	{
		system("cls");
		if (keyhit == 224)
			keyhit = _getch();
		Keyhit_Move(firstNode, lastNode, currentNode, x, keyhit); //chuyen node
		Keyhit_Insert(list, firstNode, lastNode, currentNode, x, keyhit);
		Keyhit_Delete(list, firstNode, lastNode, currentNode, x, keyhit);
		OutputConsolList(list);
		OutputFirstOfPages(x);
		Output10Nodes(firstNode, lastNode, currentNode, x); // in 10 node lai
		if (keyhit == ESC)
			return;
		keyhit = _getch();
	}
}
