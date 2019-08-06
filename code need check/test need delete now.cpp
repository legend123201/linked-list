#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

struct info{
	int data;
};

struct node {
	int soluongnhanvien = -1;
	info* nhanvien[500] = {NULL};
};

void InsertNV(node &x, int dataThem)
{
	x.nhanvien[++x.soluongnhanvien] = new info;
	x.nhanvien[x.soluongnhanvien]->data = dataThem; 
}

int vitri_endList(int vitri_first, int soluongnhanvien) {
	int run;
	int t = vitri_first + 9;
	for (run = vitri_first; run < t && run < soluongnhanvien; run++); //run -> next != NULL de ko bi chay lo them dong run = run -> next
	return run;
}

void traveseList(node x, int first, int last, int current) {
	for (int run = first; run <= last; run++) {
		if (run == current) {
			cout << x.nhanvien[run]->data << " <" << endl;
		}
		else
		{
			cout << x.nhanvien[run]->data << endl;
		}
	}
}

void travese(node &x) {
	int vitri_firstList, vitri_lastList, vitri_currentList;
	vitri_firstList = vitri_currentList = 0;
	vitri_lastList = vitri_endList(vitri_firstList, x.soluongnhanvien);
	int keyHit = 0;
	while (true)
	{
		system("cls");
		traveseList(x, vitri_firstList, vitri_lastList, vitri_currentList);
		keyHit = _getch();
		if (keyHit == 'w') {
			if (vitri_currentList != vitri_firstList) {
				vitri_currentList--;
			}
			else if (vitri_currentList == vitri_firstList) {
				vitri_currentList = vitri_lastList;
			}
		}
		else if (keyHit == 's') {
			if (vitri_currentList != vitri_lastList) {
				vitri_currentList++;
			}
			else if (vitri_currentList == vitri_lastList) {
					vitri_currentList = vitri_firstList;			
			}
		}
		else if (keyHit == 'd') {
			if (vitri_lastList != x.soluongnhanvien) {
				vitri_firstList = vitri_lastList + 1;
				vitri_lastList = vitri_endList(vitri_firstList, x.soluongnhanvien);
				vitri_currentList = vitri_firstList;
			}
		}
		else if (keyHit == 'a') {
			if (vitri_firstList > 0) {
				vitri_firstList -= 10; 
				vitri_lastList = vitri_endList(vitri_firstList, x.soluongnhanvien);
				vitri_currentList = vitri_firstList;
			}
		}
	}
}

int main() {
	node x;
	int a;
	for (int i = 1; i < 26; i++) {
		a = i;
		InsertNV(x, a);
	}
	travese(x);
	system("pause");
}
