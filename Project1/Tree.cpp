#include "Tree.h"
#include <iostream>
#include <fstream>
using namespace std;

void StaticMenu(PTRTree& p)
{
	int a;
	do
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. InsertTree.";
		cout << "\n2. DeleteTre.";
		cout << "\n3. NLR.";
		cout << "\n4. LNR.";
		cout << "\n5. LRN.";
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
			InsertTree(p, InputAddKey(), 0);
			break;
		}
		case 2:
		{
			DeleteTree(p, InputAddKey());
			break;
		}
		case 3:
		{
			cout << "\n        ======= NLR ========";
			OutPutConsole_NLR(p);
			break;
		}
		case 4:
		{
			cout << "\n        ======= LNR ========";
			OutPutConsole_LNR(p);
			break;
		}
		case 5:
		{
			cout << "\n        ======= LRN ========";
			OutPutConsole_LRN(p);
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
}

void ReadFile(PTRTree& root, const char namefile[])
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
		InsertTree(root, tempData, 0);
	}
	f.close();
}

int InputAddKey()
{
	int key;
	cout << "\nNhap khoa muon them/xoa: ";
	cin >> key;
	return key;
}

void CreateTree(PTRTree& root)
{
	root = NULL;
}

bool Empty(PTRTree root)
{
	if (root == NULL)
		return true;
	return false;
}

void InsertTree(PTRTree& p, int addKey, int addData)
{
	if (p == NULL) //tim duoc vi tri de them, tao cho no vung nho va cho no gia tri
	{
		p = new NodesTree;
		p->data = addData;
		p->key = addKey;
		p->left = NULL;
		p->right = NULL;
	}
	else if (addKey < p->key) //khoa can them nho hon khoa nut hien tai thi qua trai
		InsertTree(p->left, addKey, addData);
	else //khoa can them lon hon khoa nut hien tai thi qua phai
		InsertTree(p->right, addKey, addData);
}

void DeleteTree(PTRTree& p, int delKey)
{
	if (p == NULL) //dieu kien dung de quy
		cout << "Phan tu can xoa khong ton tai!";	
	else //van con phan tu
	{
		if (delKey < p->key ) //khoa can them nho hon nut hien tai thi qua trai
			DeleteTree(p->left, delKey);
		else if (delKey > p->key) //khoa can them lon hon nut hien tai thi qua phai
			DeleteTree(p->right, delKey);
		else //tim duoc phan tu de xoa, delKey = p->key
		{
			PTRTree temp = p; //tao temp va tro vao vi tri cua phan tu can xoa
			if (p->left == NULL) //TH ko co cay con ben trai
				p = p->right; // vi la de quy nen dong nay co nghia la p->right = p->right->right(TH can xoa nut ben phai cua nut nao do), the nen no lien ket voi nhau duoc
			else if (p->right == NULL)//TH ko co cay con ben phai
				p = p->left;
			else
				DeleteTreeCase3(p->right, temp); //TH nut can xoa co 2 nut con, tim nut tan cung ben trai cua cay con ben phai
			delete temp;
		}
	}

}

void DeleteTreeCase3(PTRTree& p, PTRTree& temp)
{
	if (p->left != NULL) //de quy de tim ra phan tu trai tan cung 
		DeleteTreeCase3(p->left, temp);
	else //p luc nay la phan tu trai tan cung, temp van giu gia tri p dau tien
	{
		//copy data tu p qua temp
		temp->key = p->key;
		temp->data = p->data;
		temp = p; //temp giu vi tri can xoa
		p = p->right; //noi lai cay con ben phai cua p vao lai cay
	}
}

void OutPutConsole_LNR(PTRTree p)
{
	if (p != NULL)
	{
		OutPutConsole_LNR(p->left);
		OutputConsole_NodesLeftRight(p);
		OutPutConsole_LNR(p->right);
	}
}

void OutPutConsole_NLR(PTRTree p)
{
	if (p != NULL)
	{
		OutputConsole_NodesLeftRight(p);
		OutPutConsole_NLR(p->left);
		OutPutConsole_NLR(p->right);
	}
}

void OutPutConsole_LRN(PTRTree p)
{
	if (p != NULL)
	{
		OutPutConsole_LRN(p->left);
		OutPutConsole_LRN(p->right);
		OutputConsole_NodesLeftRight(p);
	}
}

void OutputConsole_NodesLeftRight(PTRTree p)
{
	if (p->left != NULL) //co nut trai 
		cout << "\n " << p->key << " " << p->left->key << " ";
	else
		cout << "\n " << p->key << " none ";
	if (p->right != NULL) //co nut phai
		cout << p->right->key;
	else
		cout << " none ";
}

int MainTree()
{
	return 0;
}

