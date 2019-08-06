#include <iostream>
#include <string>
#include <windows.h>

#define CHIEUNGANG 165
#define CHIEUDOC 40

#define TOADOX 5
#define TOADOY 2

using namespace std;

void RemoveScroll() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
	csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;
	SetConsoleScreenBufferSize(hstdout, csbi.dwSize);

	HWND x = GetConsoleWindow();
	ShowScrollBar(x, SB_BOTH, FALSE);
}

void fullScreen() {
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DrawBorder(int toaDoX, int toaDoY, int chieuNgang, int chieuDoc)
{
	gotoXY(toaDoX, toaDoY); //goc trai tren
	cout << char(218); 
	gotoXY(toaDoX, toaDoY + chieuDoc); 	//goc trai duoi
	cout << char(192);
	gotoXY(toaDoX + chieuNgang, toaDoY); //goc phai tren
	cout << char(191); 
	gotoXY(toaDoX + chieuNgang, toaDoY + chieuDoc); //goc phai duoi
	cout << char(217); 		
	
	//ve hang
	gotoXY(toaDoX + 1, toaDoY);
	for (int i = 0; i < chieuNgang - 1; i++) {
		cout << char(196);	
	}
	gotoXY(toaDoX + 1, toaDoY + chieuDoc);
	for (int i = 0; i < chieuNgang - 1; i++) {
		cout << char(196);
	}
	//ve cot
	for (int i = 0; i < chieuDoc - 1; i++) {
		gotoXY(toaDoX, toaDoY + i + 1);
		cout << char(179);
		gotoXY(toaDoX + chieuNgang, toaDoY + i + 1);
		cout << char(179);
	}
	cout << "\n";
}

void DrawBorderList(int toaDoX, int toaDoY, int soDong, int soCot, int chieuNgangO, int chieuDocO)
{
	for (int i = 0; i < soDong; i++) {
		int tempX = toaDoX;
		for (int j = 0; j < soCot; j++) {
			DrawBorder(tempX, toaDoY, chieuNgangO, chieuDocO + 1);
			
			if(i == 0 && j > 0){
				gotoXY(tempX, toaDoY);
				cout << char(194); //doi goc trai tren cua cac o hang tren cung			
			}
			if(i == soDong - 1 && j > 0){
				gotoXY(tempX, toaDoY + chieuDocO + 1); //doi goc trai duoi cua cac o hang cuoi cung
				cout << char(193);
			}
			if(j == 0 && i > 0){
				gotoXY(tempX, toaDoY);//doi goc trai tren cua nhung o cot dau tien
				cout << char(195);
			}
			if(j == soCot - 1 && i > 0){
				gotoXY(tempX + chieuNgangO, toaDoY); //doi goc phai duoi cua nhung o cot cuoi cung
				cout << char(180); 
			}
			if(j > 0 && j < soCot && i > 0 && i < soDong){
				gotoXY(tempX, toaDoY); //con cac goc phai tren cua cac o con lai cho thanh dau cong la xong
				cout << char(197);
			}
			
			tempX += chieuNgangO;
		}
		toaDoY += chieuDocO + 1;
	}
}

int main()
{
	system("color f0");
	fullScreen();
	RemoveScroll();
	DrawBorder(TOADOX, TOADOY, CHIEUNGANG, CHIEUDOC);
	for(int i = 0; i < CHIEUDOC; i += ( CHIEUDOC / 5) ){
		DrawBorder(TOADOX, TOADOY + i, 20, CHIEUDOC/5);
	}
	for(int i = CHIEUDOC/5; i < CHIEUDOC; i+= CHIEUDOC / 5){
		gotoXY(TOADOX , TOADOY + i);
		cout << char(195);
		gotoXY(TOADOX + 20 ,TOADOY + i);
		cout << char(180);
	}
	gotoXY(TOADOX + 20, TOADOY);
	cout << char(194);
	gotoXY(TOADOX + 20, TOADOY + CHIEUDOC );
	cout<< char(193);
	DrawBorderList(40, 10, 5, 6, 10, 5);
	gotoXY(0, CHIEUDOC + 2 );
	return 0;
}
