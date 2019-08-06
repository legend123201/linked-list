#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
#define MaxNhanVien 500
#define MaxVatTu 20
using namespace std;

typedef struct
{
	int date;
	int month;
	int year;
} Ngay;

typedef struct
{
	string tenVT[30], donViTinh[15];  //DVT = don vi tinh
	int soLuongTon; // so luong ton
} VatTu;

struct NodesVatTu
{
	VatTu info;
	struct NodesVatTu* left;
	struct NodesVatTu* right;
	char maVT[11]; //key
};

typedef struct NodesVatTu* PTRVatTu;

typedef struct
{
	char maVT[10];
	float soLuong, donGia, VAT; //VAT se la duoi dang xxx%
} ChiTietVatTu;

typedef struct
{
	int soLuongVatTu;
	ChiTietVatTu nodesChiTiet[MaxVatTu];
}ChiTietHoaDon;

typedef struct
{
	char soHoaDon[21];
	Ngay ngayNhapHoaDon;
	char loai[2];  //'N' = chi nhap 'X' = chi xuat
} HoaDon;

struct NodesHoaDon
{
	HoaDon infoHoaDon;
	struct NodesHoaDon* next;
	ChiTietHoaDon* PTRChiTietHoaDon;
};

typedef struct NodesHoaDon* PTRHoaDon;

typedef struct
{
	PTRHoaDon first;
	PTRHoaDon last;
}ListHoaDon;

typedef struct
{
	std::string maNV;
	//char Ho[30],Ten[30];
	std::string ho, ten;
	int phai;
	ListHoaDon PTRHoaDonNhanVien;   //danh sach hoa don nhan vien lam, chi den dia chi cua hoa don
} NhanVien;

typedef struct
{
	int soLuongNhanVien;
	NhanVien* nodes[501];
} DanhSachNhanVien;

int TrongNhanVien(DanhSachNhanVien DSNhanVien) 
{
	return DSNhanVien.soLuongNhanVien==0;
}

//Nhan vien day
int DayNhanVien(DanhSachNhanVien DSNhanVien)
{
	return ( DSNhanVien.soLuongNhanVien==MaxNhanVien ? 1 : 0 ) ;
}

//Tim kiem nhan vien theo ma nhan vien, tra ve vi tri cua nhan vien trong danh sach
int TimNhanVien(DanhSachNhanVien DSNhanVien, string maNV)
{
	for(int i=0; i<DSNhanVien.soLuongNhanVien; i++)
	{
		if(DSNhanVien.nodes[i]->maNV == maNV)
			return i;
	}
	return -1;
}

//Tim vi tri thich hop x theo ten
int TimViTriThichHopX(DanhSachNhanVien DSNhanVien, string ho, string ten)
{
	string t1 = ten + ho;
	string t2;	
	for (int i = 0; i < DSNhanVien.soLuongNhanVien; i++)
	{
        t2 = DSNhanVien.nodes[i]->ten + DSNhanVien.nodes[i]->ho;
		if (t2 >= t1)
			return i;
    }
    return DSNhanVien.soLuongNhanVien;
}

//Them Nhan Vien vao vi tri X
int ThemNhanVienVaoX(DanhSachNhanVien &DSNhanVien, NhanVien nhanVien, int diaChi)
{
	if( diaChi < 0 || diaChi > DSNhanVien.soLuongNhanVien || DayNhanVien(DSNhanVien) )
		return 0;
	DSNhanVien.nodes[DSNhanVien.soLuongNhanVien] = new NhanVien;
	for( int i = DSNhanVien.soLuongNhanVien; i > diaChi; i--)
		*DSNhanVien.nodes[i] = *DSNhanVien.nodes[i-1];
	DSNhanVien.soLuongNhanVien++;
	*DSNhanVien.nodes[diaChi] = nhanVien;
	return 1;
}

//Them nhan vien sap xep theo ten
int ThemNhanVienTheoTen(DanhSachNhanVien &DSNhanVien, NhanVien nhanVien)
{
	int diaChi = TimViTriThichHopX(DSNhanVien, nhanVien.ho, nhanVien.ten);
	int kq = ThemNhanVienVaoX(DSNhanVien, nhanVien, diaChi);
	return kq;
}

//void importWord(HashTablePointer&dictionary, string line) {
//	int index = hashF(line);
//	WordPointer newWord = new WordNode;
//	lineToWord(line, newWord);
//	addLast(dictionary[index].First, dictionary[index].Last, newWord);
//}
//
//void readFile(HashTablePointer&dictionary, WordPointer &currentWord) {
//	ifstream fi("data.txt");
//	string line;
//	if (fi.is_open()) {
//		while (getline(fi, line)) importWord(dictionary, line);
//		fi.close();
//	}
//	if (!fi.fail()) {
//		findFirstWord(dictionary, currentWord);
//		return;
//	}
//	// else
//	currentWord == NULL;
//}
//"'''''''''''
//void XuatHoaDon(HoaDon hoaDon)
//{
//	cout << hoaDon.soHoaDon <<endl;
//	cout << hoaDon.ngayNhapHoaDon.date << "/" << hoaDon.ngayNhapHoaDon.month << "/" << hoaDon.ngayNhapHoaDon.year <<endl;
//	cout << hoaDon.loai <<endl;
//}

bool Empty(ListHoaDon l)
{
	if(l.first == NULL)
		return true;
	return false;
}

void OutputConsole(ListHoaDon &l)
{
	if(Empty(l)) cout << "\nRong";
	for(PTRHoaDon i = l.first; i != NULL; i = i -> next)
	{
		cout << i -> infoHoaDon.soHoaDon <<"\n";
		cout << i -> infoHoaDon.ngayNhapHoaDon.date <<"\n";
		cout << i -> infoHoaDon.ngayNhapHoaDon.month <<"\n";
		cout << i -> infoHoaDon.ngayNhapHoaDon.year <<"\n";
		cout << i -> infoHoaDon.loai <<"\n";
	}
}



//void XuatDayHoaDon(PTRHoaDon first)
//{
//	for (PTRHoaDon p = first; p != NULL; p = p->next)
//		XuatHoaDon(p->infoHoaDon);
//}

void XuatDayNhanVien(DanhSachNhanVien dsNhanVien)
{
	for(int i = 0; i < dsNhanVien.soLuongNhanVien; i++)
	{
		cout << dsNhanVien.nodes[i]->ho << endl;
		cout << dsNhanVien.nodes[i]->ten << endl;
		cout << dsNhanVien.nodes[i]->maNV << endl;
		cout << dsNhanVien.nodes[i]->phai << endl;
		OutputConsole(dsNhanVien.nodes[i]->PTRHoaDonNhanVien);
	}
}

void XuatNhanVien(NhanVien nhanVien)
{
	cout << nhanVien.ho << endl;
	cout << nhanVien.ten << endl;
	cout << nhanVien.maNV << endl;
	cout << nhanVien.phai << endl;
}

Ngay StringToDate(string temp)
{
	Ngay result;
	result.date = 0;
	result.month = 0;
	result.year = 0;
	result.date = (int)(temp[0] - '0') * 10 + (int)(temp[1] - '0');
	result.month = (int)(temp[2] - '0') * 10 + (int)(temp[3] - '0');
	result.year = (int)(temp[4] - '0') * 1000 + (int)(temp[5] - '0')*100 + (int)(temp[6] - '0') * 10 + (int)(temp[7] - '0');
	return result;
}

bool EmptyHoaDon(ListHoaDon listHoaDon)
{
	if (listHoaDon.first == NULL)
		return true;
	else return false;
}
void InsertFirst(HoaDon info, ListHoaDon &listHoaDon)
{
	PTRHoaDon p = new NodesHoaDon;
	if (p == NULL)
	{
		cout << "Bo nho cua ban da het. Khong them duoc phan tu.";
		return;
	}
	p->infoHoaDon = info;
	p->next = NULL;
	if (EmptyHoaDon(listHoaDon))
	{
		listHoaDon.first = listHoaDon.last = p;
	}
	else
	{
		p->next = listHoaDon.first;
		listHoaDon.first = p;
	}
}

void LineToNhanVien(string line, NhanVien &newNhanVien)
{
	string temp = "";
	int i = 0;
	while (line[i] != '+')
	{
		temp += line[i];
		i++;
	}
	newNhanVien.maNV = temp;
	i++;
	temp = "";
	
	while (line[i] != '+')
	{
		temp += line[i];
		i++;
	}
	newNhanVien.ho = temp;
	i++;
	temp = "";
	
	while (line[i] != '+')
	{
		temp += line[i];
		i++;
	}
	newNhanVien.ten = temp;
	i++;
	temp = "";
	
	while (line[i] != '+')
	{
		temp += line[i];
		i++;
	}
	newNhanVien.phai = (int)temp[0] - '0';
	i++;
	temp = "";
	while(line[i] != '@')
	{
		HoaDon hoaDon;
		while(line[i] != '*')
		{
			temp += line[i];
			i++;
		}
		strcpy(hoaDon.soHoaDon,temp.c_str());
		i++;
		temp = "";
		
		while(line[i] != '*')
		{
			temp += line[i];
			i++;
		}
		hoaDon.ngayNhapHoaDon = StringToDate(temp);
		temp = "";
		i++;
		
		while(line[i] != '*')
		{
			temp += line[i];
			i++;
		}
		strcpy(hoaDon.loai,temp.c_str());
		i++;
		temp = "";
//		while(line[])
//		XuatHoaDon(hoaDon);
		InsertFirst(hoaDon, newNhanVien.PTRHoaDonNhanVien);
//		XuatDayHoaDon(newNhanVien.PTRHoaDonNhanVien.first);
	}
}

void ImportNhanVien(DanhSachNhanVien &nhanVien, string line)
{
	NhanVien newNhanVien;
	LineToNhanVien(line, newNhanVien);
//	XuatNhanVien(newNhanVien);
//	XuatDayNhanVien(nhanVien);
	ThemNhanVienTheoTen(nhanVien, newNhanVien);
}

void ReadFile(DanhSachNhanVien &nhanVien)
{
	ifstream data("data.txt");
	string line; //TUNG DONG CUA FILE
	if (data.is_open()) {
		while (getline(data, line))
			ImportNhanVien(nhanVien, line);
		data.close();
	}
	else
		cout << "Loi doc file";
}


int main()
{
	DanhSachNhanVien DSNhanVien;
	DSNhanVien.soLuongNhanVien = 0;
	ReadFile(DSNhanVien);
	cout << DSNhanVien.soLuongNhanVien <<endl;
	XuatDayNhanVien(DSNhanVien);
	return 0;
}

