#pragma once

#include<iostream>
#include<conio.h>
#include<windows.h>
#define LEFT -75	
#define RIGHT -77	
#define ENTER 13 
#define ESC 27
#define F2 -60
#define DELETE -83
#define WHITE 245
#define YELLOW 225
using namespace std;

void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int  GetKey1() {
	char key; key = _getch();
	if (key == -32 || key == 0)
		return -(_getch());
	else return key;
}
void HienThiTrang(int trang, int tongtrang, int x, int y) {
	TextColor(174);	gotoXY(x, y); cout << " Trang:        ";
	gotoXY(x + 8, y); cout << trang << "/" << tongtrang;
	TextColor(14);
}
//--------------LTC----------------
void Khung_Nhap_LTC() {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n";
	cout << "   +------------------------------------------------------------------------------------+";
	cout << "\n   |    |             |  	      | 	    |        |        |        |        |";
	cout << "\n   |----+-------------+---------------+-------------+--------+--------+--------+--------+";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      |             |        |        |        |        |";
	cout << "\n   |    | 	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |------------------------------------------------------------------------------------|";
	cout << "\n   |                                                                                    |";
	cout << "\n   +------------------------------------------------------------------------------------+";
	gotoXY(26, 2);
	TextColor(236);
	cout << "     DANH SACH LOP TIN CHI      ";
	TextColor(14);
	gotoXY(5, 6);    	cout << "STT";
	gotoXY(11, 6);    	cout << "MA LOP";
	gotoXY(25, 6);		cout << "MA MON HOC";
	gotoXY(41, 6);		cout << "NIEN KHOA";
	gotoXY(54, 6);		cout << "HOC KI";
	gotoXY(64, 6);		cout << "NHOM";
	gotoXY(72, 6);		cout << "SL MIN";
	gotoXY(81, 6);		cout << "SL MAX";
	gotoXY(4, 24);		TextColor(252);		cout << "ESC";
	TextColor(14);		cout << ": Exit";
	gotoXY(35, 24);		TextColor(252);		cout << "F2";
	TextColor(14);		cout << ": Save";
	gotoXY(50, 24);		TextColor(252);		cout << "F5";
	TextColor(14);		cout << ": DSMH";
	gotoXY(20, 24);		TextColor(252);		cout << "ENTER";
	TextColor(14);		cout << ": OK";
	gotoXY(95, 9); cout << "^";
	gotoXY(91, 11); cout << "<";
	gotoXY(99, 11); cout << ">";
	gotoXY(95, 13); cout << "v";
	gotoXY(90, 15); cout << "UP";
	gotoXY(90, 17); cout << "DOWN";
	gotoXY(90, 19); cout << "LEFT";
	gotoXY(90, 21); cout << "RIGHT";
	gotoXY(95, 15); cout << ": LEN";
	gotoXY(95, 17); cout << ": XUONG";
	gotoXY(95, 19); cout << ": TRAI";
	gotoXY(95, 21); cout << ": PHAI";
	gotoXY(0, 27);
}
void Khung_Xuat_LTC() {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n";
	cout << "   +------------------------------------------------------------------------------------+";
	cout << "\n   |    |             |  	      | 	    |        |        |        |        |";
	cout << "\n   |----+-------------+---------------+-------------+--------+--------+--------+--------+";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      |             |        |        |        |        |";
	cout << "\n   |    | 	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |    |	      |		      | 	    |        |        |        |        |";
	cout << "\n   |------------------------------------------------------------------------------------|";
	cout << "\n   |                                                                                    |";
	cout << "\n   +------------------------------------------------------------------------------------+";
	gotoXY(26, 2);
	TextColor(236);
	cout << "     DANH SACH LOP TIN CHI      ";
	TextColor(14);
	gotoXY(5, 6);    	cout << "STT";
	gotoXY(11, 6);    	cout << "MA LOP";
	gotoXY(25, 6);		cout << "MA MON HOC";
	gotoXY(41, 6);		cout << "NIEN KHOA";
	gotoXY(54, 6);		cout << "HOC KI";
	gotoXY(64, 6);		cout << "NHOM";
	gotoXY(72, 6);		cout << "SL MIN";
	gotoXY(81, 6);		cout << "SL MAX";
	gotoXY(4, 24);		TextColor(252);		cout << "ESC";
	TextColor(14);		cout << ": Exit";
	gotoXY(18, 24);		TextColor(252);		cout << "F1";
	TextColor(14);		cout << ": Insert";
	gotoXY(33, 24);		TextColor(252);		cout << "F2";
	TextColor(14);		cout << ": Save";
	gotoXY(45, 24);		TextColor(252);		cout << "F3";
	TextColor(14);		cout << ": Edit";
	gotoXY(56, 24);		TextColor(252);		cout << "DELETE";
	TextColor(14);		cout << ": Delete";
	gotoXY(95, 9); cout << "^";
	gotoXY(91, 11); cout << "<";
	gotoXY(99, 11); cout << ">";
	gotoXY(95, 13); cout << "v";
	gotoXY(90, 15); cout << "UP";
	gotoXY(90, 17); cout << "DOWN";
	gotoXY(90, 19); cout << "LEFT";
	gotoXY(90, 21); cout << "RIGHT";
	gotoXY(95, 15); cout << ": LEN";
	gotoXY(95, 17); cout << ": XUONG";
	gotoXY(95, 19); cout << ": TRAI";
	gotoXY(95, 21); cout << ": PHAI";
	gotoXY(0, 27);
}

void Khung_Them_LTC() {
	TextColor(225);
	gotoXY(7, 8);		cout << "                     NHAP THONG TIN LOP TIN CHI CAN THEM                          ";
	TextColor(228);
	gotoXY(7, 9);		cout << "                                                                                  ";
	gotoXY(7, 10);    	cout << "                                                                                  ";
	gotoXY(12, 10);    	cout << "MA LOP";
	gotoXY(25, 10);		cout << "MA MON HOC";
	gotoXY(41, 10);		cout << "NIEN KHOA";
	gotoXY(54, 10);		cout << "HOC KI";
	gotoXY(64, 10);		cout << "NHOM";
	gotoXY(71, 10);		cout << "SL MIN";
	gotoXY(81, 10);     cout << "SL MAX";
	gotoXY(7, 11);    	cout << "                                                                                  ";
	gotoXY(7, 12);    	cout << "                                                                                  ";
	gotoXY(7, 13);    	cout << "                                                                                  ";
	TextColor(WHITE);
	gotoXY(9, 13);    	cout << "                                                                              ";
	TextColor(12);
	gotoXY(9, 11);    	cout << "            ";
	gotoXY(24, 11);    	cout << "            ";
	gotoXY(41, 11);    	cout << "         ";
	gotoXY(54, 11);    	cout << "      ";
	gotoXY(64, 11);		cout << "    ";
	gotoXY(71, 11);		cout << "       ";
	gotoXY(81, 11);		cout << "       ";
}
void Khung_Xoa_LTC() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Lop Can Xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(12);	gotoXY(33, 14); cout << "                           ";
}
void Khung_Sua_LTC() {
	TextColor(228);
	gotoXY(30, 10); cout << "                                 ";
	gotoXY(30, 11); cout << "                                 ";
	gotoXY(30, 12); cout << "                                 ";
	gotoXY(33, 10); cout << "Nhap Ma Lop Tin Chi Can Sua";
	TextColor(228); gotoXY(33, 12); cout << "Enter:";
	gotoXY(51, 12); cout << "ESC:";
	TextColor(225); gotoXY(40, 12); cout << "OK";
	gotoXY(56, 12); cout << "Exit";
	TextColor(12);	gotoXY(33, 11); cout << "                           ";
}
void Khung_Diem_LTC() {
	TextColor(228);
	gotoXY(30, 10); cout << "                                 ";
	gotoXY(30, 11); cout << "                                 ";
	gotoXY(30, 12); cout << "                                 ";
	gotoXY(33, 10); cout << "   Nhap Ma Lop Tin Chi    ";
	TextColor(228); gotoXY(33, 12); cout << "Enter:";
	gotoXY(51, 12); cout << "ESC:";
	TextColor(225); gotoXY(40, 12); cout << "OK";
	gotoXY(56, 12); cout << "Exit";
	TextColor(12);	gotoXY(33, 11); cout << "                           ";
}
void KhungLTC() {
	TextColor(WHITE);
	gotoXY(30, 0);		cout << "     NHAP THONG TIN DE TIEN HANH MO LOP      ";
	TextColor(228);
	gotoXY(30, 1);    	cout << "                                             ";
	gotoXY(40, 1);		cout << "NIEN KHOA";
	gotoXY(60, 1);		cout << "HOC KI";
	gotoXY(30, 2);    	cout << "                                             ";
	gotoXY(30, 3);    	cout << "                                             ";
	TextColor(12);
	gotoXY(38, 2);    	cout << "             ";
	gotoXY(60, 2);    	cout << "      ";

}
//------------DSDK-----------------
void Khung_Nhap_MSV_HK_NK() {
	TextColor(WHITE);
	gotoXY(30, 0);		cout << "     NHAP THONG TIN DE TIEN HANH DANG KI     ";
	TextColor(228);
	gotoXY(30, 1);    	cout << "                                             ";
	gotoXY(34, 1);		cout << "MA SINH VIEN";
	gotoXY(50, 1);		cout << "HOC KI ";
	gotoXY(63, 1);		cout << "NIEN KHOA";
	gotoXY(30, 2);    	cout << "                                             ";
	gotoXY(30, 3);    	cout << "                                             ";
	TextColor(12);
	gotoXY(34, 2);    	cout << "            ";
	gotoXY(49, 2);    	cout << "       ";
	gotoXY(60, 2);    	cout << "              ";
}
void Khung_Xuat_LTCDK() {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n";
	cout << "   +---------------------------------------------------------------------------+----------------------------------+";
	cout << "\n   |    |       |  	    | 	                             |        |        ||                                 |";
	cout << "\n   |----+-------+-----------+--------------------------------+--------+--------++---------------------------------+";
	cout << "\n   |    |	|	    | 	                             |        |        ||  STT |     MA LOP TIN CHI       |";
	cout << "\n   |    |	|	    |                                |        |        ||------+--------------------------|";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |    | 	|	    | 	                             |        |        ||      |                          |";
	cout << "\n   |---------------------------------------------------------------------------||---------------------------------+";
	cout << "\n   |                                                                           ||                                 |";
	cout << "\n   +--------------------------------------------------------------------------------------------------------------+";
	gotoXY(26, 2);
	TextColor(236);
	cout << "     DANH SACH LOP TIN CHI DANG KI     ";
	TextColor(14);
	gotoXY(5, 6);    	cout << "STT";
	gotoXY(9, 6);    	cout << "MA LOP";
	gotoXY(17, 6);		cout << "MA MON HOC";
	gotoXY(35, 6);		cout << "TEN MON HOC";
	gotoXY(64, 6);		cout << "NHOM";
	gotoXY(71, 6);		cout << "SL TRONG";
	TextColor(12);
	gotoXY(90, 6);		cout << "LOP DA DANG KI";
	gotoXY(4, 24);		TextColor(252);		cout << "ESC";
	TextColor(14);		cout << ": Exit";
	gotoXY(20, 24);		TextColor(252);		cout << "F2";
	TextColor(14);		cout << ": Save";
	gotoXY(82, 24);		TextColor(252);		cout << "DELETE";
	TextColor(14);		cout << ": DELETE";
	gotoXY(0, 27);
}
void Khung_Huy_LTCDK() {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n";
	cout << "   +---------------------------------------------------------------------------+";
	cout << "\n   |    |       |  	    | 	                             |        |        |";
	cout << "\n   |----+-------+-----------+--------------------------------+--------+--------+";
	cout << "\n   |    |	|	    | 	                             |        |        |";
	cout << "\n   |    |	|	    |                                |        |        |";
	cout << "\n   |    |	|	    | 	                             |        |        |";
	cout << "\n   |    |	|	    |                                |        |        |";
	cout << "\n   |    |	|	    | 	                             |        |        |";
	cout << "\n   |    |	|	    |                                |        |        |";
	cout << "\n   |    |	|	    | 	                             |        |        |";
	cout << "\n   |    |	|	    |                                |        |        |";
	cout << "\n   |    |	|	    | 	                             |        |        |";
	cout << "\n   |    |	|	    |                                |        |        |";
	cout << "\n   |    |	|	    | 	                             |        |        |";
	cout << "\n   |    |	|	    |                                |        |        |";
	cout << "\n   |    |	|	    |                                |        |        |";
	cout << "\n   |    |	|	    | 	                             |        |        |";
	cout << "\n   |    |	|	    |                                |        |        |";
	cout << "\n   |---------------------------------------------------------------------------|";
	cout << "\n   |                                                                           |";
	cout << "\n   +---------------------------------------------------------------------------+";
	gotoXY(26, 2);
	TextColor(236);
	cout << "     DANH SACH LOP TIN CHI DANG KI     ";
	TextColor(14);
	gotoXY(5, 6);    	cout << "STT";
	gotoXY(9, 6);    	cout << "MA LOP";
	gotoXY(17, 6);		cout << "MA MON HOC";
	gotoXY(35, 6);		cout << "TEN MON HOC";
	gotoXY(64, 6);		cout << "NHOM";
	gotoXY(71, 6);		cout << "SL TRONG";
	TextColor(12);
	gotoXY(4, 24);		TextColor(252);		cout << "ESC";
	TextColor(14);		cout << ": Exit";
	gotoXY(20, 24);		TextColor(252);		cout << "F2";
	TextColor(14);		cout << ": Save";
	gotoXY(30, 24);		TextColor(252);		cout << "F1";
	TextColor(14);		cout << ": DELETE";
	gotoXY(0, 27);
}
void Khung_Xoa_LTCDK() {
	TextColor(228);
	gotoXY(81, 20); cout << "                                 ";
	gotoXY(81, 21); cout << "                                 ";
	gotoXY(81, 22); cout << "                                 ";
	gotoXY(81, 20); cout << "    Nhap Ma Lop Can Bo Chon   ";
	TextColor(228); gotoXY(84, 22); cout << "Enter:";
	gotoXY(102, 22); cout << "ESC:";
	TextColor(225); gotoXY(91, 22); cout << "OK";
	gotoXY(107, 22); cout << "Exit";
	TextColor(12);	gotoXY(84, 21); cout << "                           ";
}
void Khung_DKLTC() {
	TextColor(244);
	gotoXY(80, 1); cout << "   NHAP LOP TIN CHI MUON DANG KI   ";
	TextColor(228);
	gotoXY(80, 2); cout << "                                   ";
	gotoXY(80, 3); cout << "   MA LTC                          ";
	gotoXY(80, 4); cout << "                                   ";
	TextColor(14);
	gotoXY(93, 3); cout << "             ";

}
void Khung_HLTC() {
	TextColor(244);
	gotoXY(80, 6); cout << "   NHAP LOP TIN CHI MUON HUY       ";
	TextColor(228);
	gotoXY(80, 7); cout << "                                   ";
	gotoXY(80, 8); cout << "   MA LTC                          ";
	gotoXY(80, 9); cout << "                                   ";
	TextColor(14);
	gotoXY(93, 8); cout << "             ";

}
void Khung_Nhap_bo4Diem() {
	TextColor(244);
	gotoXY(11, 9);		cout << "                    NHAP THONG TIN                     ";
	TextColor(228);
	gotoXY(11, 10);    	cout << "                                                       ";
	gotoXY(16, 10);    	cout << "MA MON HOC";
	gotoXY(31, 10);		cout << "NIEN KHOA";
	gotoXY(44, 10);		cout << "HOC KI";
	gotoXY(58, 10);		cout << "NHOM";
	gotoXY(11, 11);    	cout << "                                                       ";
	gotoXY(11, 12);    	cout << "                                                       ";
	TextColor(12);
	gotoXY(13, 11);    	cout << "            ";
	gotoXY(28, 11);    	cout << "            ";
	gotoXY(45, 11);    	cout << "         ";
	gotoXY(58, 11);    	cout << "      ";
}
int	 ThongBao_DK() {
	int key, count = 0;
	TextColor(206);
	gotoXY(85, 23); cout << "    Ban chac chan muon dang ki   ";
	gotoXY(85, 24); cout << "                                 ";
	gotoXY(85, 25); cout << "                                 ";
	TextColor(238);
	gotoXY(88, 24); cout << "                           ";
	TextColor(252);	gotoXY(93, 24);	cout << " YES ";
	TextColor(233);	gotoXY(105, 24);	cout << " NO ";
	gotoXY(94, 24);
	while (1) {
		key = GetKey1();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(93, 24); cout << " YES ";
				TextColor(252);		gotoXY(105, 24); cout << " NO ";
				gotoXY(106, 24);
			}
			else {
				TextColor(252);		gotoXY(93, 24); cout << " YES ";
				TextColor(233);		gotoXY(105, 24); cout << " NO ";
				gotoXY(94, 24);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				return 1;
			}
			else {
				if (count % 2 == 1) {
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (key == ESC) {
			return -1;
		}
	}
}
void Khung_Xuat_Diem(int dem) {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n   +-----------------------------------------------------------------------+";
	cout << "\n   |     |		 |		             |     	    |      |";
	cout << "\n   |-----+---------------+---------------------------+--------------+------|";
	for(int i=0;i<dem;i++){
		cout << "\n   |	 |               |       	             |              |      |";
	}
	cout << "\n   +-----------------------------------------------------------------------+";
	TextColor(236);
	gotoXY(25, 2);	cout << " BANG DIEM MON HOC ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(12, 6);	cout << "MA SINH VIEN";
	gotoXY(40, 6);	cout << "HO";
	gotoXY(60, 6);	cout << "TEN";
	gotoXY(70, 6);	cout << "DIEM";
	gotoXY(85, 8);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(0, 27);
}
void Khung_Nhap_MMH_HK_NK_N() {
	TextColor(WHITE);
	gotoXY(30, 0);		cout << "       NHAP THONG TIN DE XEM DANH SACH DANG KI             ";
	TextColor(228);
	gotoXY(30, 1);    	cout << "                                                           ";
	gotoXY(34, 1);		cout << "MA MON HOC";
	gotoXY(50, 1);		cout << "HOC KI ";
	gotoXY(63, 1);		cout << "NIEN KHOA";
	gotoXY(80, 1);		cout << "NHOM";
	gotoXY(30, 2);    	cout << "                                                           ";
	gotoXY(30, 3);    	cout << "                                                           ";
	TextColor(12);
	gotoXY(34, 2);    	cout << "            ";
	gotoXY(49, 2);    	cout << "       ";
	gotoXY(60, 2);    	cout << "              ";
	gotoXY(78, 2);    	cout << "       ";
}
void Khung_Nhap_Diem(int dem) {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n   +-----------------------------------------------------------------------+";
	cout << "\n   |     |		 |		             |     	    |      |";
	cout << "\n   |-----+---------------+---------------------------+--------------+------|";
	for(int i=0;i<dem;i++){
		cout << "\n   |	 |               |       	             |              |      |";
	}
	cout << "\n   +-----------------------------------------------------------------------+";
	TextColor(236);	gotoXY(25, 1);	cout << "                              ";
	gotoXY(25, 2);	cout << "      NHAP DANH SACH DIEM     ";
	gotoXY(25, 3);	cout << "                              ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(12, 6);	cout << "MA SINH VIEN";
	gotoXY(40, 6);	cout << "HO";
	gotoXY(60, 6);	cout << "TEN";
	gotoXY(70, 6);	cout << "DIEM";
	gotoXY(85, 8);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(85, 10);	TextColor(252);	cout << "ENTER";
	TextColor(14);	cout << ": OK";
	gotoXY(85, 12);	TextColor(252);	cout << "F2";
	TextColor(14);		cout << ": Save";
	gotoXY(95, 14); cout << "^";
	gotoXY(91, 16); cout << "<";
	gotoXY(99, 16); cout << ">";
	gotoXY(95, 18); cout << "v";
	gotoXY(90, 20); cout << "UP";
	gotoXY(90, 22); cout << "DOWN";
	gotoXY(90, 24); cout << "LEFT";
	gotoXY(90, 26); cout << "RIGHT";
	gotoXY(95, 20); cout << ": LEN";
	gotoXY(95, 22); cout << ": XUONG";
	gotoXY(95, 24); cout << ": TRAI";
	gotoXY(95, 26); cout << ": PHAI";
	gotoXY(0, 27);
}


//-------------DSMH--------------
void Khung_Them_MonHoc() {
	TextColor(228);
	gotoXY(10, 13); cout << "     MA MON HOC                    TEN MON HOC          STCLT   STCTH ";
	gotoXY(10, 14); cout << "                                                                      ";
	gotoXY(10, 15); cout << "                                                                      ";
	TextColor(228);	gotoXY(58, 15); cout << "Enter:";
	gotoXY(70, 15); cout << "ESC:";
	TextColor(225);	gotoXY(65, 15); cout << "OK";
	gotoXY(75, 15); cout << "Exit";
	TextColor(12);
	gotoXY(12, 14); cout << "                ";
	gotoXY(30, 14); cout << "                                   ";
	gotoXY(67, 14); cout << "   ";
	gotoXY(75, 14); cout << "   ";
}
void Khung_Sua_MonHoc() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Mon Hoc Can Sua";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);
	gotoXY(33, 14); cout << "                           ";
}
void Khung_Xoa_MonHoc() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Mon Hoc Can Xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);	gotoXY(33, 14); cout << "                           ";
}
void Khung_Xuat_MH() {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n   +-----------------------------------------------------------------------------------+";
	cout << "\n   |     |		      |					       |       |       |";
	cout << "\n   |-----+--------------------+----------------------------------------+---------------|";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |-----------------------------------------------------------------------------------|";
	cout << "\n   |                                            	                       	       |";
	cout << "\n   +-----------------------------------------------------------------------------------+";
	TextColor(236);
	gotoXY(33, 2);	cout << "    XUAT DANH SACH MON HOC    ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(15, 6);	cout << "MA MON HOC";
	gotoXY(46, 6);	cout << "TEN MON HOC";
	gotoXY(73, 6);	cout << "STCLT";
	gotoXY(81, 6);	cout << "STCTH";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(18, 24);	TextColor(252);	cout << "F1";
	TextColor(14);	cout << ": Insert";
	gotoXY(33, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": Save";
	gotoXY(45, 24);	TextColor(252);	cout << "F3";
	TextColor(14);	cout << ": Edit";
	gotoXY(56, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(95, 9); cout << "^";
	gotoXY(91, 11); cout << "<";
	gotoXY(99, 11); cout << ">";
	gotoXY(95, 13); cout << "v";
	gotoXY(90, 15); cout << "UP";
	gotoXY(90, 17); cout << "DOWN";
	gotoXY(90, 19); cout << "LEFT";
	gotoXY(90, 21); cout << "RIGHT";
	TextColor(14); gotoXY(95, 15); cout << ": LEN";
	gotoXY(95, 17); cout << ": XUONG";
	gotoXY(95, 19); cout << ": TRAI";
	gotoXY(95, 21); cout << ": PHAI";
	gotoXY(0, 27);
}
void Khung_Xuat_SV() {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n   +-------------------------------------------------------------------------------------------------------------+";
	cout << "\n   |     |                |              |                   |         |          |             |                |";
	cout << "\n   |-----+----------------+--------------+-------------------+---------+----------+-------------+----------------|";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |	 |                |              |     	             |         |          |             |                |";
	cout << "\n   |-------------------------------------------------------------------------------------------------------------|";
	cout << "\n   |                                                                                                             |";
	cout << "\n   +-------------------------------------------------------------------------------------------------------------+";
	TextColor(236);	gotoXY(33, 1);	cout << "                              ";
	gotoXY(33, 2);	cout << "   XUAT DANH SACH SINH VIEN   ";
	gotoXY(33, 3);	cout << "                              ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(10, 6);	cout << "MA LOP";
	gotoXY(28, 6);	cout << "MA SINH VIEN";
	gotoXY(44, 6);	cout << "HO";
	gotoXY(63, 6);	cout << "TEN";
	gotoXY(74, 6);	cout << "PHAI";
	gotoXY(85, 6);	cout << "SDT";
	gotoXY(100, 6);	cout << "NAM NHAP HOC";
	gotoXY(4, 24);		TextColor(252);		cout << "ESC";
	TextColor(14);		cout << ": Exit";
	gotoXY(20, 24);		TextColor(252);		cout << "F1";
	TextColor(14);		cout << ": Edit";
	gotoXY(36, 24);		TextColor(252);		cout << "F2";
	TextColor(14);		cout << ": Save";
	gotoXY(52,24); 		TextColor(252);		cout << "DELETE";
	TextColor(14);		cout << ": Delete";
//	gotoXY(110, 9); cout << "^";
//	gotoXY(106, 11); cout << "<";
//	gotoXY(114, 11); cout << ">";
//	gotoXY(110, 13); cout << "v";
//	gotoXY(105, 15); cout << "UP";
//	gotoXY(105, 17); cout << "DOWN";
//	gotoXY(105, 19); cout << "LEFT";
//	gotoXY(105, 21); cout << "RIGHT";
//	gotoXY(110, 15); cout << ": LEN";
//	gotoXY(110, 17); cout << ": XUONG";
//	gotoXY(110, 19); cout << ": TRAI";
//	gotoXY(110, 21); cout << ": PHAI";
	gotoXY(0, 27);
}
void Khung_Nhap_MH() {
	gotoXY(0, 0);
	cout << "\n\n\n\n\n   +-----------------------------------------------------------------------------------+";
	cout << "\n   |     |		      |					       |       |       |";
	cout << "\n   |-----+--------------------+----------------------------------------+---------------|";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   |	 |		      |					       |       |       |";
	cout << "\n   | 	 |		      |					       |       |       |";
	cout << "\n   |-----------------------------------------------------------------------------------|";
	cout << "\n   |                                            	                       	       |";
	cout << "\n   +-----------------------------------------------------------------------------------+";
	TextColor(236);	gotoXY(33, 1);	cout << "                              ";
	gotoXY(33, 2);	cout << "    NHAP DANH SACH MON HOC    ";
	gotoXY(33, 3);	cout << "                              ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(15, 6);	cout << "MA MON HOC";
	gotoXY(46, 6);	cout << "TEN MON HOC";
	gotoXY(73, 6);	cout << "STCLT";
	gotoXY(81, 6);	cout << "STCTH";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(20, 24);	TextColor(252);	cout << "ENTER";
	TextColor(14);	cout << ": OK";
	gotoXY(36, 24);	TextColor(252);	cout << "CONTROL";
	TextColor(14);	cout << ": LEFT - RIGHT - UP - DOWN";
	gotoXY(95, 9); cout << "^";
	gotoXY(91, 11); cout << "<";
	gotoXY(99, 11); cout << ">";
	gotoXY(95, 13); cout << "v";
	gotoXY(90, 15); cout << "UP";
	gotoXY(90, 17); cout << "DOWN";
	gotoXY(90, 19); cout << "LEFT";
	gotoXY(90, 21); cout << "RIGHT";
	gotoXY(95, 15); cout << ": LEN";
	gotoXY(95, 17); cout << ": XUONG";
	gotoXY(95, 19); cout << ": TRAI";
	gotoXY(95, 21); cout << ": PHAI";
	gotoXY(0, 27);
}
//=============DSSV===========
void Khung_Nhap_MaLop() {
	TextColor(228); gotoXY(33, 2); cout << "                              ";
	gotoXY(33, 3); cout << "                              ";
	gotoXY(33, 4); cout << "                              ";
	gotoXY(33, 1); cout << "                              ";
	TextColor(192);	TextColor(116); gotoXY(33, 1); cout << "          NHAP MA LOP         ";
	TextColor(233); gotoXY(36, 3); cout << "Enter:";
	gotoXY(50, 3); cout << "ESC:";
	gotoXY(38, 4); cout << "F5:";
	TextColor(228); gotoXY(43, 3); cout << "OK";
	gotoXY(55, 3); cout << "Exit";
	gotoXY(42, 4); cout << "XEM DANH SACH LOP";
	TextColor(14);	gotoXY(40, 2); cout << "               ";
}
void Khung_Nhap_SV() {
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n\n   +-------------------------------------------------------------------------------------------------+";
	cout << "\n   |     |		 |		      |          |	    |              |                 |";
	cout << "\n   |-----+---------------+--------------------+----------+----------+--------------+-----------------|";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |	 |               |       	      |          |          |              |                 |";
	cout << "\n   |-------------------------------------------------------------------------------------------------|";
	cout << "\n   |                                                                                                 |";
	cout << "\n   +-------------------------------------------------------------------------------------------------+";
	TextColor(236);	gotoXY(33, 1);	cout << "                              ";
	gotoXY(0,0); cout<<"MA LOP: ";
	gotoXY(33, 2);	cout << "   NHAP DANH SACH SINH VIEN   ";
	gotoXY(33, 3);	cout << "                              ";
	TextColor(12);	gotoXY(5, 6);    cout << "STT";
	TextColor(14);
	gotoXY(12, 6);	cout << "MA SINH VIEN";
	gotoXY(28, 6);	cout << "HO";
	gotoXY(49, 6);	cout << "TEN";
	gotoXY(60, 6);	cout << "PHAI";
	gotoXY(71, 6);	cout << "SDT";
	gotoXY(86, 6);	cout << "NAM NHAP HOC";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(20, 24);	TextColor(252);	cout << "ENTER";
	TextColor(14);	cout << ": OK";
	gotoXY(36, 24); TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": Save";
	gotoXY(110, 9); cout << "^";
	gotoXY(106, 11); cout << "<";
	gotoXY(114, 11); cout << ">";
	gotoXY(110, 13); cout << "v";
	gotoXY(106, 15); cout << "UP";
	gotoXY(106, 17); cout << "DOWN";
	gotoXY(106, 19); cout << "LEFT";
	gotoXY(106, 21); cout << "RIGHT";
	gotoXY(111, 15); cout << ": LEN";
	gotoXY(111, 17); cout << ": XUONG";
	gotoXY(111, 19); cout << ": TRAI";
	gotoXY(111, 21); cout << ": PHAI";
	gotoXY(0, 27);
}
void Khung_Xoa_SV() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Sinh Vien Can Xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(12);	gotoXY(33, 14); cout << "                           ";
}
void Khung_Them_SV() {
	TextColor(228); gotoXY(27, 13); cout << "            HO              TEN     PHAI     SDT     NAM NHAP HOC     ";
	//gotoXY(10, 14); cout << "  ";
	gotoXY(27, 14); cout << "  ";
	gotoXY(49, 14); cout << "  ";
	gotoXY(61, 14); cout << "  ";
	gotoXY(66, 14); cout << "  ";
	gotoXY(79, 14); cout << "  ";
	gotoXY(92, 14); cout << "     ";
	gotoXY(27, 15); cout << "                                                                      ";
	TextColor(228);
	gotoXY(70, 15); cout << "Enter:";
	gotoXY(86, 15); cout << "ESC:";
	TextColor(225);	gotoXY(77, 15); cout << "OK";
	gotoXY(91, 15); cout << "Exit";
	TextColor(14);	
	//gotoXY(12, 14); cout << "               ";
	gotoXY(29, 14); cout << "                    ";
	gotoXY(51, 14); cout << "          ";
	gotoXY(63, 14); cout << "   ";
	gotoXY(68, 14); cout << "           ";
	gotoXY(82, 14); cout << "          ";
}
void Khung_Sua_SV() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Sinh Vien Can Sua";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(12);	gotoXY(33, 14); cout << "                           ";
}
void Khung_Nhap_MaSV() {
	TextColor(228);
	gotoXY(30, 8);	cout << "                                      ";
	gotoXY(30, 9);	cout << "   NHAP VAO MA SINH VIEN DE THAO TAC  ";
	gotoXY(30, 10); cout << "                                      ";
	TextColor(246);
	gotoXY(36, 13); cout << "                         ";
	gotoXY(36, 14); cout << "                         ";
	gotoXY(36, 15); cout << "                         ";
	TextColor(246); gotoXY(37, 13); cout << "    Nhap Ma Sinh Vien  ";
	TextColor(244); gotoXY(38, 15); cout << "Enter:";
	gotoXY(50, 15); cout << "ESC:";
	TextColor(249); gotoXY(44, 15); cout << "OK";
	gotoXY(55, 15); cout << "Exit";
	TextColor(12);	gotoXY(40, 14); cout << "                 ";
}
//===========================
int	 ThongBao_ESC() {
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 12); cout << "     Ban Co Muon Luu Vao File!   ";
	gotoXY(25, 13);	cout << "   ";
	gotoXY(55, 13);	cout << "   ";
	gotoXY(25, 14);	cout << "   ";
	gotoXY(55, 14);	cout << "   ";
	gotoXY(25, 15);	cout << "   ";
	gotoXY(55, 15);	cout << "   ";
	gotoXY(25, 16);	cout << "                                 ";
	TextColor(238);
	gotoXY(28, 13); cout << "                           ";
	gotoXY(28, 14); cout << "                           ";
	gotoXY(28, 15); cout << "                           ";
	TextColor(252);	gotoXY(33, 14);	cout << " YES ";
	TextColor(233);	gotoXY(45, 14);	cout << " NO ";
	gotoXY(34, 14);
	while (1) {
		key = GetKey1();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(33, 14); cout << " YES ";
				TextColor(252);		gotoXY(45, 14); cout << " NO ";
				gotoXY(46, 14);
			}
			else {
				TextColor(252);		gotoXY(33, 14); cout << " YES ";
				TextColor(233);		gotoXY(45, 14); cout << " NO ";
				gotoXY(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				TextColor(14);
				gotoXY(25, 12); cout << "                                 ";
				gotoXY(25, 13);	cout << "   ";
				gotoXY(55, 13);	cout << "   ";
				gotoXY(25, 14);	cout << "   ";
				gotoXY(55, 14);	cout << "   ";
				gotoXY(25, 15);	cout << "   ";
				gotoXY(55, 15);	cout << "   ";
				gotoXY(25, 16);	cout << "                                 ";
				gotoXY(28, 13); cout << "                           ";
				gotoXY(28, 14); cout << "                           ";
				gotoXY(28, 15); cout << "                           ";
				gotoXY(33, 14);	cout << "     ";
				gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else {
				if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 12); cout << "                                 ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                 ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 0;
				}
				else {
					TextColor(14);
					gotoXY(25, 12); cout << "                                 ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                 ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 1;
				}
			}
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "   ";
			gotoXY(55, 13);	cout << "   ";
			gotoXY(25, 14);	cout << "   ";
			gotoXY(55, 14);	cout << "   ";
			gotoXY(25, 15);	cout << "   ";
			gotoXY(55, 15);	cout << "   ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}
int	 ThongBao_Thoat() {
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 12);
	cout << "        BAN CO MUON THOAT?       ";
	gotoXY(25, 13);	cout << "   ";
	gotoXY(55, 13);	cout << "   ";
	gotoXY(25, 14);	cout << "   ";
	gotoXY(55, 14);	cout << "   ";
	gotoXY(25, 15);	cout << "   ";
	gotoXY(55, 15);	cout << "   ";
	gotoXY(25, 16);	cout << "                                 ";
	TextColor(238);
	gotoXY(28, 13); cout << "                           ";
	gotoXY(28, 14); cout << "                           ";
	gotoXY(28, 15); cout << "                           ";
	TextColor(252);	gotoXY(33, 14);	cout << " YES ";
	TextColor(233);	gotoXY(45, 14);	cout << " NO ";
	gotoXY(34, 14);
	while (1) {
		key = GetKey1();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(33, 14); cout << " YES ";
				TextColor(252);		gotoXY(45, 14); cout << " NO ";
				gotoXY(46, 14);
			}
			else {
				TextColor(252);		gotoXY(33, 14); cout << " YES ";
				TextColor(233);		gotoXY(45, 14); cout << " NO ";
				gotoXY(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				return 1;
			}
			else {
				if (count % 2 == 1) {
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (key == ESC) {
			return -1;
		}
	}
}
int  ThongBao_Xoa() {
	int key, count = 0; TextColor(206);
	gotoXY(25, 12);	cout << "   Ban Co Chac Chan Muon Xoa!    ";
	gotoXY(25, 13);	cout << "   ";	gotoXY(55, 13);	cout << "   ";
	gotoXY(25, 14);	cout << "   ";	gotoXY(55, 14);	cout << "   ";
	gotoXY(25, 15);	cout << "   ";	gotoXY(55, 15);	cout << "   ";
	gotoXY(25, 16);	cout << "                                 ";
	TextColor(238);	gotoXY(28, 13); cout << "                           ";
	gotoXY(28, 14); cout << "                           ";
	gotoXY(28, 15); cout << "                           ";
	TextColor(252);	gotoXY(33, 14);	cout << " YES ";
	TextColor(233);	gotoXY(45, 14);	cout << " NO ";
	gotoXY(34, 14);
	while (1) {
		key = GetKey1();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);				gotoXY(33, 14); cout << " YES ";
				TextColor(252);				gotoXY(45, 14); cout << " NO ";
				gotoXY(46, 14);
			}
			else {
				TextColor(252);				gotoXY(33, 14); cout << " YES ";
				TextColor(233);				gotoXY(45, 14); cout << " NO ";
				gotoXY(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				return 1;
			}
			else {
				if (count % 2 == 1) {
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (key == ESC || key == DELETE) {
			return -1;
		}
	}
}
int  ThongBao_ESC_Nhap() {
	int key, count = 0;	TextColor(206);
	gotoXY(25, 26);	cout << "     Ban Co Muon Luu Vao File!   ";
	gotoXY(25, 27);	cout << "   ";	gotoXY(55, 27);	cout << "   ";
	gotoXY(25, 28);	cout << "   ";	gotoXY(55, 28);	cout << "   ";
	gotoXY(25, 29);	cout << "   ";	gotoXY(55, 29);	cout << "   ";
	gotoXY(25, 30);	cout << "                                 ";
	TextColor(238);	gotoXY(28, 27); cout << "                           ";
	gotoXY(28, 28); cout << "                           ";
	gotoXY(28, 29); cout << "                           ";
	TextColor(252);	gotoXY(33, 28);	cout << " YES ";
	TextColor(233);	gotoXY(45, 28);	cout << " NO ";
	gotoXY(34, 28);
	while (1) {
		key = GetKey1();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);				gotoXY(33, 28); cout << " YES ";
				TextColor(252);				gotoXY(45, 28); cout << " NO ";
				gotoXY(46, 28);
			}
			else {
				TextColor(252);				gotoXY(33, 28); cout << " YES ";
				TextColor(233);				gotoXY(45, 28); cout << " NO ";
				gotoXY(34, 28);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				TextColor(14);
				gotoXY(24, 26);	cout << "                                   ";
			gotoXY(24, 27);	cout << "                                   ";
			gotoXY(24, 28);	cout << "                                   ";
			gotoXY(24, 29);	cout << "                                   ";
			gotoXY(24, 30);	cout << "                                   ";
				return 1;
			}
			else {
				if (count % 2 == 1) {
					TextColor(14);
					gotoXY(24, 26);	cout << "                                   ";
					gotoXY(24, 27);	cout << "                                   ";
					gotoXY(24, 28);	cout << "                                   ";
					gotoXY(24, 29);	cout << "                                   ";
					gotoXY(24, 30);	cout << "                                   ";
					return 0;
				}
				else {
					TextColor(14);
					gotoXY(24, 26);	cout << "                                   ";
					gotoXY(24, 27);	cout << "                                   ";
					gotoXY(24, 28);	cout << "                                   ";
					gotoXY(24, 29);	cout << "                                   ";
					gotoXY(24, 30);	cout << "                                   ";
					return 1;
				}
			}
		}
		if (key == ESC||key==F2) {
			TextColor(14);			
			gotoXY(24, 26);	cout << "                                   ";
			gotoXY(24, 27);	cout << "                                   ";
			gotoXY(24, 28);	cout << "                                   ";
			gotoXY(24, 29);	cout << "                                   ";
			gotoXY(24, 30);	cout << "                                   ";
			return -1;
		}
	}
}
void Khung_NK_HK_MMH() {
	TextColor(228);
	gotoXY(10, 6);	cout << "              NHAP VAO CAC THONG TIN DUOI DAY DE THAO TAC             ";
	gotoXY(10, 8);	cout << "                                                                      ";
	gotoXY(10, 9);  cout << "  MA MON HOC                                                          ";
	gotoXY(10, 10);	cout << "                                                                      ";
	gotoXY(10, 11); cout << "  NIEN KHOA                                                           ";
	gotoXY(10, 12);	cout << "                                                                      ";
	gotoXY(10, 13); cout << "  HOC KI                                                              ";
	gotoXY(10, 14);	cout << "                                                                      ";
	gotoXY(10, 15); cout << "  NHOM                                                                ";
	gotoXY(10, 16);	cout << "                                                                      ";
	TextColor(12);
	gotoXY(25, 9);	cout << "                                                     ";
	gotoXY(25, 11);	cout << "                                                     ";
	gotoXY(25, 13);	cout << "                                                     ";
	gotoXY(25, 15);	cout << "                                                     ";
}
void Khung_Xuat_NK() {
	TextColor(14);	gotoXY(23, 8); cout << "                                     ";
	gotoXY(23, 9); cout << "  XUAT DANH SACH LOP THEO NIEN KHOA  ";
	gotoXY(23, 10); cout << "                                     ";
	TextColor(111); gotoXY(30, 13); cout << "                         ";
	gotoXY(30, 14); cout << "                         ";
	gotoXY(30, 15); cout << "                         ";
	TextColor(107); gotoXY(36, 13); cout << "Nhap Nien Khoa";
	TextColor(108); gotoXY(31, 15); cout << "Enter:";
	gotoXY(45, 15); cout << "ESC:";
	TextColor(105); gotoXY(38, 15); cout << "OK";
	gotoXY(50, 15); cout << "Exit";
	TextColor(12);	gotoXY(41, 14); cout << "    ";
}


void ThongTinChung() {
	TextColor(244); gotoXY(35, 1); cout << "                                                  ";
	gotoXY(35, 2); cout << "    CHUONG TRINH QUAN LY DANG KI MON HOC          ";
	gotoXY(35, 3); cout << "                                                  ";
	TextColor(228);
	gotoXY(35, 0); cout << "               NGOC HUY - MINH HOANG              ";
	gotoXY(35, 4); cout << "                                                  ";
	gotoXY(35, 1); cout << "  "; gotoXY(83, 1); cout << "  ";
	gotoXY(35, 2); cout << "  "; gotoXY(83, 2); cout << "  ";
	gotoXY(35, 3); cout << "  "; gotoXY(83, 3); cout << "  ";
	TextColor(14);
	int y = 5;

	char s[] = { "    CHUONG TRINH QUAN LY DANG KI MON HOC     " };
	int m = strlen(s) - 1;	TextColor(240);
	while (!_kbhit()) {
		for (int i = m; i > 0; i--) {
			s[i] = s[i - 1];
			s[0] = s[m - 1];
		}
		gotoXY(38, 2);       cout << s;
		gotoXY(38, 2); cout << " ";	   Sleep(100);
	}
	TextColor(14);
}
