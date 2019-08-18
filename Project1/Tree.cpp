#include "Tree.h"
#include <iostream>
using namespace std;

void InsertTree(PTRTree& p, int addKey, int addData)
{
	if (p == NULL) //tim duoc vi tri de them, tao cho no vung nho va cho no gia tri
	{
		p = new NodesTree;
		p->data = addData;
		p->key = addKey;
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
	if (temp->left != NULL) //de quy de tim ra phan tu trai tan cung 
		DeleteTreeCase3(p, temp->left);
	else //temp luc nay la phan tu trai tan cung
	{
		//copy data tu temp qua cho can xoa
		p->data = temp->data;
		temp = temp->right; //noi lai cay con ben phai cua temp vao lai cay
	}
}

