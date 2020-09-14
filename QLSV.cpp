#include<iostream>
#include<windows.h>
#include<string.h>
#include<fstream>
#include <sstream>
#include <time.h>
#include"lib.h"
#define DOWN -80
#define UP -72
#define LEFT -75
#define RIGHT -77
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define SPACE 32
#define F1 -59
#define F2 -60
#define F3 -61
#define F5 -63
#define DELETE -83
#define F8 -66
using namespace std;
#define MAXMONHOC 300
#define MAXLOPTC 2000
#define MAXSV 100
//-------khai bao--------
//mon hoc--------mang con tro---------
typedef struct  MonHoc {
	char MAMH[10];
	char TENMH[35];
	float STCLT;
	float STCTH;
};
typedef struct DS_MonHoc {
	int n;
	MonHoc* monhoc[MAXMONHOC];
};
//sinh vien-------ds lien ket don--------
typedef struct SinhVien {
	char MASV[12];
	char HO[20];
	char TEN[10];
	char PHAI[10];
	char SDT[11];
	char MALOP[15];
	int NAMNHAPHOC;
};
typedef struct node_SV {
	SinhVien info;
	node_SV* next;
};
typedef struct node_SV *PTR_SV;
//sv dang ky--------ds lien ket don---------
struct SVDangKi {
	char MaSV[12];
	char DIEM[4]="0";
	int tinhtrangDK=1;
};
struct node_SVDK {
	SVDangKi info;
	node_SVDK* next;
};
typedef struct node_SVDK* PTRDK;
//lop tin chi-----------cay nhi phan tim kiem--------
typedef struct LopTinChi {
	int MALOPTC;
	char MAMH[10];
	char NIENKHOA[10];
	int HOCKI;
	int NHOM;
	int SoSVMAX;
	int SoSVMIN;
	PTRDK DSSVDK = NULL;
};
struct node_LOPTINCHI {
	LopTinChi info;
	node_LOPTINCHI* left;
	node_LOPTINCHI* right;
};
typedef struct node_LOPTINCHI* PTRLTC;
//----------------------------------------------------------
int GetKey()
{
	char key;
	key = _getch();
	if (key == -32 || key == 0)
		return -_getch();
	else return key;
}
char MENU[6][40] = {
	"  1.Quan Ly Lop Tin Chi ",
	"  2.Quan Ly Mon Hoc     ",
	"  3.Quan Ly Sinh Vien   ",
	"  4.Quan Ly Dang Ki     ",
	"  5.Xem Diem Trung Binh ",
	"  6.Thoat               " };

char MENUloptc[4][40] = {
	"  1. Nhap Danh Sach Lop Tin Chi ",
	"  2. Xem Danh Sach Lop Tin Chi  ",
	"  3. Xem Diem Lop Tin Chi       ",
	"  4. Nhap Diem                  "
};

char MENUsv[2][40] = {
	"  1. Nhap Danh Sach SV          ",
	"  2. Xem Danh Sach SV           "};

char MENUdangki[3][40] = {
	"  1. Dang Ki Lop Tin Chi        ",
	"  2. Xem Danh Sach Dang Ki      ",
	"  3. Huy Dang Ki                "};

void ToMauMenuChinh(int color, int vitri)
{
	TextColor(color);
	gotoXY(0, 5 + vitri * 4); cout << "                        ";
	gotoXY(0, 6 + vitri * 4); cout << MENU[vitri];
	gotoXY(0, 7 + vitri * 4); cout << "                        ";
}

void ToMauMenuCon(int color, char MENUCON[][40], int vitri)
{
	TextColor(color);
	gotoXY(28, 5 + (vitri + 1) * 4);	cout << "                                ";
	gotoXY(28, 6 + (vitri + 1) * 4);	cout << MENUCON[vitri];
	gotoXY(28, 7 + (vitri + 1) * 4);	cout << "                                ";
}

int MenuCon(int item, char MENUCON[][40])
{

	char key;
	int vitri = 0;	int color = 188; int color1 = 236;
	while (1)
	{
		ThongTinChung();
		key = GetKey();
		if (key == ENTER)
			return vitri + 1;
		if (key == ESC || key == LEFT)
			return 0;
		switch (key)
		{
		case DOWN:
		{
			if (vitri == (item - 1))
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri = 0;
				ToMauMenuCon(236, MENUCON, vitri);
			}
			else
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri++;
				ToMauMenuCon(236, MENUCON, vitri);
			}
		}break;
		case UP:
		{
			if (vitri == 0)
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri = item - 1;
				ToMauMenuCon(236, MENUCON, vitri);
			}
			else
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri--;
				ToMauMenuCon(236, MENUCON, vitri);
			}
		}break;
		}
	}
}

int MenuCha()
{

	int vitri = 0;
	while (1)
	{
		ThongTinChung();
		char key = GetKey();
		if (key == ENTER || (key == RIGHT && vitri != 6)) // vitri!= 6 la ngay tai o Thoát
		{
			return vitri + 1;
		}
		switch (key)
		{
		case DOWN:
		{
			if (vitri == 5)
			{
				ToMauMenuChinh(240, vitri);
				vitri = 0;
				ToMauMenuChinh(236, vitri);
			}
			else
			{
				ToMauMenuChinh(240, vitri);
				vitri++;
				ToMauMenuChinh(236, vitri);
			}
		}break;
		case UP:
		{
			if (vitri == 0)
			{
				ToMauMenuChinh(240, vitri);
				vitri = (5);
				ToMauMenuChinh(236, vitri);
			}
			else
			{
				ToMauMenuChinh(240, vitri);
				vitri--;
				ToMauMenuChinh(236, vitri);
			}
		}break;
		}
	}
}

void GhiChu(string c, int x, int y, int color, int sleep)
{

	gotoXY(x, y);
	TextColor(color);
	cout << c;
	Sleep(sleep);
	gotoXY(x, y);
	TextColor(14);
	for (int j = 0; j <= c.length(); j++)
	{
		cout << ' ';
	}

}
//----------------------------------------------------
void Insert_NodeDK(PTRDK& DSDK, SVDangKi svdk) {
	PTRDK p = new node_SVDK;
	p->info = svdk;
	p->next = NULL;
	if (DSDK == NULL) {
		DSDK = p;
		return;
	}
	else {
		for (PTRDK k = DSDK; k != NULL; k = k->next)
		{
			if (k->next == NULL)	//Tim ra Node Tail
			{
				k->next = p;
				k = p;
			}
		}
		return;
	}
}

void Init_LTC(PTRLTC &dsltc){
	dsltc = NULL;
}

int EmptyDSLTC(PTRLTC dsltc) {
	return(dsltc == NULL ? TRUE : FALSE);
}

void InsertNode_LTC(PTRLTC &dsltc, LopTinChi ltc) {
	if (EmptyDSLTC(dsltc)) {
		PTRLTC p = new node_LOPTINCHI;
		p->info = ltc;
		p->left = p->right = NULL;
		dsltc = p;
		return;
	}
	else {
		if (dsltc->info.MALOPTC > ltc.MALOPTC) {
			InsertNode_LTC(dsltc->left, ltc);
		}
		else {
			InsertNode_LTC(dsltc->right, ltc);
		}
	}
}
int  Search_malopTc(PTRLTC& dsltc, int malopTc)
{
	if (dsltc != NULL) {
		//so sanh bang ma lop tin chi
		if (dsltc->info.MALOPTC == malopTc)
		{
			return dsltc->info.MALOPTC; //neu phan trung thi tra ve vi tri key
		}
		else if (dsltc->info.MALOPTC > malopTc)
			Search_malopTc(dsltc->left, malopTc);
		else
			Search_malopTc(dsltc->right, malopTc);
	}
	else
		return -1; //khong tim thay trung
}

PTRLTC Search_LTC(PTRLTC& DSLTC, int mltc) {
	if (EmptyDSLTC(DSLTC)) { return NULL; }
	else {
		if (DSLTC->info.MALOPTC == mltc) {
			return DSLTC;
		}
		else if (DSLTC->info.MALOPTC > mltc) {
			Search_LTC(DSLTC->left, mltc);
		}
		else {
			Search_LTC(DSLTC->right, mltc);
		}
	}
}
MonHoc* TaoMH() {
	MonHoc* mh = new MonHoc;
	mh->MAMH[0] = NULL;
	mh->TENMH[0] = NULL;
	mh->STCLT = 0;
	mh->STCTH = 0;
	return mh;
}
//Full
int  FullMH(DS_MonHoc dsmh) {

	return(dsmh.n == MAXMONHOC ? TRUE : FALSE);
}
int	 InsertMH(DS_MonHoc& dsmh, MonHoc mh, int i) {
	//kiem tra xem danh sach full hay chua
	if (FullMH(dsmh))
		return 0;
	else
	{
		//them vao cuoi
		dsmh.monhoc[i] = TaoMH();
		strcpy(dsmh.monhoc[i]->MAMH, mh.MAMH);
		strcpy(dsmh.monhoc[i]->TENMH, mh.TENMH);
		dsmh.monhoc[i]->STCLT = mh.STCLT;
		dsmh.monhoc[i]->STCTH = mh.STCTH;
		
	}
	//them thanh cong, tang so luong phan tu len 1
	dsmh.n++;
}
void InitMH(DS_MonHoc& dsmh)
{
	dsmh.n = 0;
}
//Empty
int EmptyMH(DS_MonHoc dsmh)
{
	return(dsmh.n == 0 ? TRUE : FALSE);
}
//xoaLTC
void DeleteMH(DS_MonHoc& dsmh, int i)
{
	//cac truong hop chi so dua vao khong hop le
	if (i<0 || i>dsmh.n || EmptyMH(dsmh))
	{
		return;
	}
	if (i == dsmh.n)
	{
		delete dsmh.monhoc[dsmh.n];
		dsmh.n--;
		dsmh.monhoc[dsmh.n] = NULL;//tranh tinh trang con tro bi treo
		return;
	}
	else
	{
		delete dsmh.monhoc[i];
		for (int temp = i + 1; temp < dsmh.n; temp++)
		{
			dsmh.monhoc[temp - 1] = dsmh.monhoc[temp];
		}
		dsmh.n--;
		dsmh.monhoc[dsmh.n] = NULL; //tranh tinh trang con tro bi treo
	}
	return;
}
//------------------doc ghi file--------------------------------
void DocFileDSMH(DS_MonHoc& dsmh) {
	ifstream infile;
	infile.open("DSMH.txt", ios::in);
	if (!infile) {
		cout << "\n File danh sach mon hoc khong ton tai";
		return;
	}
	int i = 0;
	MonHoc mh;
	while (infile.good()) {
		infile.getline(mh.MAMH, 10);
		infile.getline(mh.TENMH, 35);
		infile >> mh.STCLT;
		infile >> mh.STCTH;
		infile.ignore();
		if (infile.eof()) break;
		if (i < MAXMONHOC)
		{
			InsertMH(dsmh, mh, dsmh.n);
			i++;
		}
	}
	infile.close();
}
void GhiFileDSMH(DS_MonHoc dsmh) {
	ofstream outfile;
	outfile.open("DSMH.txt");
	for (int i = 0; i < dsmh.n; i++)
	{
		outfile << dsmh.monhoc[i]->MAMH << endl;
		outfile << dsmh.monhoc[i]->TENMH << endl;
		outfile << dsmh.monhoc[i]->STCLT << endl;
		outfile << dsmh.monhoc[i]->STCTH << endl;
	}
	outfile.close();
}
void DocFileDSLTC(PTRLTC &dsltc) {
	ifstream infile;
	string data;
	infile.open("DSLTC.txt", ios::in);
	if (!infile) { 
		GhiChu("Khong tim thay file", 35, 27, 79, 2000); 
		return; 
	} //Khong tim thay file
	while (infile.good())
	{
		LopTinChi ltc;
		getline(infile, data);
		if (data.size() == 0) { break; } //Da co file nhung chua co du lieu
		ltc.MALOPTC = atoi(data.c_str());
		getline(infile, data);		strcpy(ltc.MAMH, data.c_str());
		getline(infile, data);		strcpy(ltc.NIENKHOA, data.c_str());
		getline(infile, data);		ltc.HOCKI = atoi(data.c_str());
		getline(infile, data);		ltc.NHOM = atoi(data.c_str());
		getline(infile, data);		ltc.SoSVMIN = atoi(data.c_str());
		getline(infile, data);		ltc.SoSVMAX = atoi(data.c_str());
		InsertNode_LTC(dsltc, ltc);
	}
	infile.close();
}
void GhiFile_LNR(ofstream &file, PTRLTC dsltc)
{
	if (dsltc != NULL) 
	{
		GhiFile_LNR(file, dsltc->left);
		file << dsltc->info.MALOPTC << endl
			<< dsltc->info.MAMH << endl
			<< dsltc->info.NIENKHOA << endl
			<< dsltc->info.HOCKI << endl
			<< dsltc->info.NHOM << endl
			<< dsltc->info.SoSVMIN << endl
			<< dsltc->info.SoSVMAX << endl;
		GhiFile_LNR(file, dsltc->right);
	}
}
void GhiFileLTC(PTRLTC dsltc) {
	ofstream outfile;
	outfile.open("DSLTC.txt", ios::out);
	GhiFile_LNR(outfile, dsltc);
	outfile.close();
}

void DocFileDSDK(PTRLTC dsltc){
	int temp, vitri;
	string data;
	char a[11];
	int malopTc;
	ifstream infile;
	infile.open("DSDK.txt", ios::in);
	if (!infile) { return; }
	while (infile.good())
	{
		SVDangKi svdk;
		getline(infile, data);
		if (data.size() == 0) { break; }
		strcpy(a, data.c_str());
		malopTc = atoi(a);
		temp = Search_malopTc(dsltc, malopTc);
		if(temp != -1){
			dsltc = Search_LTC(dsltc, malopTc);
		}
		else {
			strcpy(svdk.MaSV, data.c_str());
			getline(infile, data);		strcpy(svdk.DIEM,data.c_str());
			getline(infile, data);		svdk.tinhtrangDK=atoi(data.c_str());
			Insert_NodeDK(dsltc->info.DSSVDK, svdk);
		}
	}
	infile.close();
}
void GhiFileDK_LNR(ofstream& file, PTRLTC dsltc)
{
	if (dsltc != NULL)
	{
		GhiFileDK_LNR(file,dsltc->left);
		if (dsltc->info.DSSVDK != NULL) {
			file << dsltc->info.MALOPTC << endl;
			for (PTRDK dsdk = dsltc->info.DSSVDK; dsdk != NULL; dsdk = dsdk->next)
			{
				file << dsdk->info.MaSV << endl
					<< dsdk->info.DIEM << endl
					<<dsdk->info.tinhtrangDK<<endl;
			}
		}
		GhiFileDK_LNR(file,dsltc->right);
	}
}
void GhiFileDK(PTRLTC dsltc)
{
	ofstream outfile;
	outfile.open("DSDK.txt", ios::out);
	GhiFileDK_LNR(outfile, dsltc);
	outfile.close();
}

//------------------------------MONHOC------------------------
int Search_MH_LTC(PTRLTC& DSLTC, char mh[]) {
	if (DSLTC != NULL)
	{
		Search_MH_LTC(DSLTC->left, mh);
		if (strcmp(DSLTC->info.MAMH, mh) == 0)
		{
			return 1;
		}
		Search_MH_LTC(DSLTC->right, mh);
	}
}
void Sua_MMH_LTC(PTRLTC& DSLTC,char mmhsua[], char mmh[]) {
	if (DSLTC != NULL)
	{
		Sua_MMH_LTC(DSLTC->left, mmhsua, mmh);
			if (strcmp(DSLTC->info.MAMH, mmhsua) == 0) {
				strcpy(DSLTC->info.MAMH, mmh);
			}
		Sua_MMH_LTC(DSLTC->right, mmhsua, mmh);
	}
}
int KTMH(DS_MonHoc DSMH, char mh[], int n) {
	if (DSMH.n == 0)
		return 0;
	for (int i = 0; i <= n; i++)						// tra ve -1 : trung Ma lop
	{
		if (DSMH.n == i) { continue; }
		if (strcmp(DSMH.monhoc[i]->MAMH, mh)== 0)
			return -1;
	}
	return 0;
}
int  Search_MAMH(DS_MonHoc DSMH, char maMH[], int dem)
{
	for (int i = 0; i < dem; i++)
	{
		if (strcmp(DSMH.monhoc[i]->MAMH, maMH)==0)
		{
			return i; //neu phan trung thi tra ve vi tri i
		}
	}
	return -1; //khong tim thay trung
}
//-- them mon hoc
void ThemMonHoc(DS_MonHoc& DSMH, bool& check_change)
{
	int key, vitri = 0, x = 12, y = 14, check_trung;
	MonHoc mh;	mh.MAMH[0] = NULL;	mh.TENMH[0] = NULL;	mh.STCLT = 0;	mh.STCTH = 0;
	Khung_Them_MonHoc(); gotoXY(x, y);
MAMH:
	while (1)
	{
		TextColor(250);	gotoXY(10, 15);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10";
		TextColor(12); gotoXY(12 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout << mh.MAMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12 + vitri, y);
			cout << " ";
			gotoXY(12 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (FullMH(DSMH)) { continue; }
			mh.MAMH[vitri] = '\0';
			check_trung = KTMH(DSMH, mh.MAMH, DSMH.n);
			if (check_trung != 0) {
				TextColor(78);	gotoXY(10, 15);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			vitri = strlen(mh.TENMH);
			gotoXY(30 + vitri, y);
			goto TENMH;
		}
		if (key == RIGHT)
		{
			if (FullMH(DSMH)) { continue; }
			mh.MAMH[vitri] = '\0';
			check_trung = KTMH(DSMH, mh.MAMH,DSMH.n);
			if (check_trung != 0) {
				TextColor(78);	gotoXY(10, 15);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500); continue;
			}
			vitri = strlen(mh.TENMH);
			gotoXY(30 + vitri, y);
			goto TENMH;
		}
		if (key == ESC || key == F1) { return; }
	}
TENMH:
	while (1)
	{
		TextColor(250);	gotoXY(10, 15);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 35";
		TextColor(12); gotoXY(30 + vitri, y); //Ghi chú
		key = GetKey();
		if (mh.MAMH[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Mon Hoc!", 35, 27, 79, 700);
			gotoXY(12, y);
			goto MAMH;
		}
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			mh.TENMH[vitri] = char(key);
			mh.TENMH[vitri] = toupper(mh.TENMH[vitri]);
			cout << mh.TENMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(30 + vitri, y);
			cout << " ";
			gotoXY(30 + vitri, y);
		}
		if (key == SPACE && mh.TENMH[vitri - 1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(30 + vitri, y);
			cout << " ";
			mh.TENMH[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (mh.TENMH[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.TENMH[vitri] = '\0';
			vitri = 0;
			gotoXY(67 + vitri, y);
			goto STCLT;
		}
		if (key == LEFT)
		{
			mh.TENMH[vitri] = '\0';
			vitri = strlen(mh.MAMH);
			gotoXY(12 + vitri, y);
			goto MAMH;
		}
		if (key == RIGHT)
		{
			if (mh.TENMH[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.TENMH[vitri] = '\0';
			vitri = 0;
			gotoXY(67 + vitri, y);
			goto STCLT;
		}
		if (key == ESC || key == F1) { return; }
	}
STCLT:
	while (1)
	{
		char stclt[4];
		TextColor(250);	gotoXY(10, 15);
		cout << "Ki tu: (0-9 & .). Toi da: 3         ";
		TextColor(12); gotoXY(67 + vitri, y); // Ghi chú
		key = GetKey();
		if (mh.TENMH[0] == '\0')
		{
			GhiChu("Ban Chua Nhap TEN Mon Hoc!", 35, 27, 79, 700);
			gotoXY(30, y);
			goto TENMH;
		}
		if ((key <= '9' && key >= '0') && (vitri < 3) || (key == '.') && (vitri < 3))
		{
			stclt[vitri] = char(key);
			stclt[vitri] = toupper(stclt[vitri]);
			cout << stclt[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(67 + vitri, y);
			cout << " ";
			gotoXY(67 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			stclt[vitri] = '\0';
			mh.STCLT = atof(stclt);
			float a = mh.STCLT - int(mh.STCLT); int demcham =0;
			for (int i = 0; i < 3; i++) {
				if (stclt[i] == '.') demcham++;
			}
			if (((a == 0.5) || (a == 0))&&((stclt[0] != '.') && (demcham <=1)))
			{
				stclt[vitri] = '\0';
				vitri = 0;
				gotoXY(75 + vitri, y);
				goto STCTH;
			}
			else {
				GhiChu("Nhap sai so tin chi", 35, 27, 79, 700);
				continue;
			}
		}
		if (key == LEFT)
		{
			stclt[vitri] = '\0';
			mh.STCLT = atof(stclt);
			vitri = strlen(mh.TENMH);
			gotoXY(30 + vitri, y);
			goto TENMH;
		}
		if (key == RIGHT)
		{
			stclt[vitri] = '\0';
			mh.STCLT = atof(stclt);
			float a = mh.STCLT - int(mh.STCLT); int demcham = 0;
			for (int i = 0; i < 3; i++) {
				if (stclt[i] == '.') demcham++;
			}
			if (((a == 0.5) || (a == 0)) && ((stclt[0] != '.') && (demcham <= 1)))
			{
				stclt[vitri] = '\0';
				vitri = 0;
				gotoXY(75 + vitri, y);
				goto STCTH;
			}
			else {
				GhiChu("Nhap sai so tin chi", 35, 27, 79, 700);
				continue;
			}
		}
		if (key == ESC || key == F1) { return; }
	}
STCTH:
	while (1)
	{
		char stcth[4];
		TextColor(250);	gotoXY(10, 15);
		cout << "Ki tu: (0-9 & .). Toi da: 3         ";
		TextColor(12); gotoXY(75 + vitri, y); // Ghi chú
		key = GetKey();
		if (mh.STCLT == 0)
		{
			GhiChu("Ban Chua Nhap STCLT Mon Hoc!", 35, 27, 79, 700);
			gotoXY(67, y);
			goto STCLT;
		}
		if ((key <= '9' && key >= '0') && (vitri < 3)|| (key == '.') && (vitri < 3))
		{
			stcth[vitri] = char(key);
			stcth[vitri] = toupper(stcth[vitri]);
			cout << stcth[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(75 + vitri, y);
			cout << " ";
			gotoXY(75 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			stcth[vitri] = '\0';
			mh.STCTH = atof(stcth);
			float a = mh.STCTH - int(mh.STCTH); int demcham = 0;
			for (int i = 0; i < 3; i++) {
				if (stcth[i] == '.') demcham++;
			}
			if (((a == 0.5) || (a == 0)) && ((stcth[0] != '.') && (demcham <= 1)))
			{
				check_change = true;
				stcth[vitri] = '\0';
				InsertMH(DSMH, mh, DSMH.n);
				GhiChu("Them Thanh Cong", 35, 27, 79, 1000);
				return;
			}
			else {
				GhiChu("Nhap sai so tin chi", 35, 27, 79, 700);
				continue;
			}
		}
		if (key == LEFT)
		{
			stcth[vitri] = '\0';
			mh.STCTH = atof(stcth);
			mh.STCLT = 0;
			vitri = 0;
			gotoXY(67 + vitri, y);
			goto STCLT;
		}
		if (key == ESC || key == F1) { return; }
	}
}
//--sua mon hoc----
void SuaMonHoc(DS_MonHoc& DSMH,PTRLTC& DSLTC, bool& check_change)
{
	int key, vitri = 0, x = 33, y = 14, check_vt, check_trung;
	char tam[11]; //de luu ma mon nhap vao
	MonHoc mh;	mh.MAMH[0] = NULL;	mh.TENMH[0] = NULL;	mh.STCLT = 0;	mh.STCTH = 0;
	Khung_Sua_MonHoc(); gotoXY(x, y);
	//dau tien phai tim vi tri cua ma mon
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 15))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout << mh.MAMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.MAMH[vitri] = '\0';	//Ngat chuoi~
			strcpy(tam, mh.MAMH);
			check_vt = Search_MAMH(DSMH, tam, DSMH.n); //KT trung`. 1: trung, co ton tai 0: ko trung
			if (check_vt != -1) {
				vitri = 0;
				Khung_Them_MonHoc();
				x = 12, y = 14;
				gotoXY(x, y);
				TextColor(14);
				strcpy(mh.MAMH, DSMH.monhoc[check_vt]->MAMH);
				strcpy(mh.TENMH, DSMH.monhoc[check_vt]->TENMH);
				mh.STCLT = DSMH.monhoc[check_vt]->STCLT;
				mh.STCTH = DSMH.monhoc[check_vt]->STCTH;
				gotoXY(12, y); cout << mh.MAMH;
				gotoXY(30, y); cout << mh.TENMH;
				gotoXY(67, y); cout << mh.STCLT;
				gotoXY(75, y); cout << mh.STCTH;
				vitri = strlen(tam);
				goto MAMH;
				break;
				
			}
			else {
				GhiChu("Ma Mon Hoc Khong Ton Tai!", 35, 27, 79, 500);	TextColor(12);	gotoXY(33 + vitri, y);
			}
		}
		if (key == ESC || key == F3) { return; }
	}

MAMH:
	while (1)
	{
		TextColor(244);	gotoXY(10, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 10";
		TextColor(14); gotoXY(12 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout << mh.MAMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12 + vitri, y);
			cout << " ";
			gotoXY(12 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			mh.MAMH[vitri] = '\0';
			check_trung = Search_MAMH(DSMH, mh.MAMH,DSMH.n);
			if (check_trung != -1 || check_trung == check_vt) {
				TextColor(78);
				gotoXY(10, 15);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			else {
				vitri = strlen(mh.TENMH);
				gotoXY(30 + vitri, y);
				goto TENMH;
			}
		}
		if (key == RIGHT)
		{
			mh.MAMH[vitri] = '\0';
			check_trung = Search_MAMH(DSMH, mh.MAMH,DSMH.n);
			if (check_trung != -1 || check_trung == check_vt) {
				TextColor(78);
				gotoXY(10, 15);
				cout << "Trung Ma Mon Hoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			else {
				vitri = strlen(mh.TENMH);
				gotoXY(30 + vitri, y);
				goto TENMH;
			}
		}
		if (key == ESC || key == F3) { return; }
	}
TENMH:
	while (1)
	{
		TextColor(244);	gotoXY(10, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 35";
		TextColor(14); gotoXY(30 + vitri, y); //Ghi chú
		key = GetKey();
		if (mh.MAMH[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Mon Hoc!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(12 + vitri, y);
			goto MAMH;
		}
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 35))
		{
			mh.TENMH[vitri] = char(key);
			mh.TENMH[vitri] = toupper(mh.TENMH[vitri]);
			cout << mh.TENMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(30 + vitri, y);
			cout << " ";
			gotoXY(30 + vitri, y);
		}
		if (key == SPACE && mh.TENMH[vitri - 1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(30 + vitri, y);
			cout << " ";
			mh.TENMH[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (mh.TENMH[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.TENMH[vitri] = '\0';
			vitri = 0;
			gotoXY(67 + vitri, y);
			goto STCLT;
		}
		if (key == LEFT)
		{
			mh.TENMH[vitri] = '\0';
			vitri = strlen(mh.MAMH);
			gotoXY(12 + vitri, y);
			goto MAMH;
		}
		if (key == RIGHT)
		{
			if (mh.TENMH[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.TENMH[vitri] = '\0';
			if (mh.STCLT - int(mh.STCLT) == 0) {
				vitri = 1;
			}
			else vitri = 3;
			gotoXY(67 + vitri, y);
			goto STCLT;
		}
		if (key == ESC || key == F3) { return; }
	}
STCLT:
	while (1)
	{
		TextColor(244);	gotoXY(10, 15); cout << "Ki tu: (0-9 && .). Toi da: 3         ";
		TextColor(14); gotoXY(67 + vitri, y); // Ghi chú
		key = GetKey();
		char stclt[4];
		if (mh.TENMH[0] == '\0')
		{
			GhiChu("Ban Chua Nhap TEN Mon Hoc!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(30 + vitri, y);
			goto TENMH;
		}
		if ((key <= '9' && key >= '0') && (vitri < 3) || (key == '.') && (vitri < 3))
		{
			stclt[vitri] = char(key);
			stclt[vitri] = toupper(stclt[vitri]);
			cout << stclt[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(67 + vitri, y);
			cout << " ";
			gotoXY(67 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			stclt[vitri] = '\0';
			mh.STCLT = atof(stclt);
			float a = mh.STCLT - int(mh.STCLT); int demcham = 0;
			for (int i = 0; i < 3; i++) {
				if (stclt[i] == '.') demcham++;
			}
			if (((a == 0.5) || (a == 0)) && ((stclt[0] != '.') && (demcham <= 1)))
			{
				stclt[vitri] = '\0';
				vitri = 0;
				gotoXY(75 + vitri, y);
				goto STCTH;
			}
			else {
				GhiChu("Nhap sai so tin chi", 35, 27, 79, 700);
				continue;
			}
		}
		if (key == LEFT)
		{
			stclt[vitri] = '\0';
			vitri = strlen(mh.TENMH);
			gotoXY(30 + vitri, y);
			goto TENMH;
		}
		if (key == RIGHT)
		{
			stclt[vitri] = '\0';
			mh.STCLT = atof(stclt);
			float a = mh.STCLT - int(mh.STCLT); int demcham = 0;
			for (int i = 0; i < 3; i++) {
				if (stclt[i] == '.') demcham++;
			}
			if (((a == 0.5) || (a == 0)) && ((stclt[0] != '.') && (demcham <= 1)))
			{
				stclt[vitri] = '\0';
				vitri = 0;
				gotoXY(75 + vitri, y);
				goto STCTH;
			}
			else {
				GhiChu("Nhap sai so tin chi", 35, 27, 79, 700);
				continue;
			}
		}
		if (key == ESC || key == F3) { return; }
	}
STCTH:
	while (1)
	{
		TextColor(244);	gotoXY(10, 15); cout << "Ki tu: (0-9 && .). Toi da: 3         ";
		TextColor(14); gotoXY(75 + vitri, y); // Ghi chú
		key = GetKey();
		char stcth[4];
		if (mh.STCLT == 0)
		{
			GhiChu("Ban Chua Nhap STCLT Mon Hoc!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(67 + vitri, y);
			goto STCLT;
		}
		if ((key <= '9' && key >= '0') && (vitri < 3) || (key == '.') && (vitri < 3))
		{
			stcth[vitri] = char(key);
			stcth[vitri] = toupper(stcth[vitri]);
			cout << stcth[vitri];
			mh.STCTH = atof(stcth);
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{

			vitri--;
			gotoXY(75 + vitri, y);
			cout << " ";
			gotoXY(75 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			stcth[vitri] = '\0';
			mh.STCTH = atof(stcth);
			float a = mh.STCTH - int(mh.STCTH); int demcham = 0;
			for (int i = 0; i < 3; i++) {
				if (stcth[i] == '.') demcham++;
			}
			if (((a == 0.5) || (a == 0)) && ((stcth[0] != '.') && (demcham <= 1)))
			{
				check_change = true;
				stcth[vitri] = '\0';
				//sua trong danh sach mon hoc, phai sua luon trong DSLTC
				Sua_MMH_LTC(DSLTC,tam, mh.MAMH);
				strcpy(DSMH.monhoc[check_vt]->MAMH, mh.MAMH);
				strcpy(DSMH.monhoc[check_vt]->TENMH, mh.TENMH);
				DSMH.monhoc[check_vt]->STCLT = mh.STCLT;
				DSMH.monhoc[check_vt]->STCTH = mh.STCTH;
				GhiChu("Mon hoc da duoc cap nhat!", 35, 27, 79, 700);
				return;
			}
			else {
				GhiChu("Nhap sai so tin chi", 35, 27, 79, 700);
				continue;
			}
		}
		if (key == LEFT)
		{
			stcth[vitri] = '\0';
			mh.STCTH = atof(stcth);
			vitri = 0;
			gotoXY(67 + vitri, y);
			goto STCLT;
		}
		if (key == ESC || key == F3) { return; }
	}
}
//--xoa mon hoc
void XoaMonHoc(PTRLTC& DSLTC, DS_MonHoc& DSMH, bool& check_change) {
	int key;
	int x = 33, y = 14;
	int vitri = 0, vitri_MH;
	char MaMHXoa[11];
	Khung_Xoa_MonHoc();
	gotoXY(x, y);
Reset:
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			MaMHXoa[vitri] = char(key);
			MaMHXoa[vitri] = toupper(MaMHXoa[vitri]);
			cout << MaMHXoa[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			MaMHXoa[vitri] = '\0';			
			vitri_MH = Search_MAMH(DSMH, MaMHXoa, DSMH.n);
			if (-1 == vitri_MH) {
				GhiChu("MA MON HOC KHONG TON TAI!", 35, 27, 79, 700);
				gotoXY(33 + vitri, y);
				continue;
			}
			else {
				int temp = Search_MH_LTC(DSLTC, MaMHXoa);// kiem tra da mo lop tin chi chua
				if (temp != 1) { // chua mo -> xoa
					check_change = true;
					DeleteMH(DSMH, vitri_MH);
					GhiChu("XOA THANH CONG MON HOC!", 20, 27, 79, 500);
					return;
				}
                //===xoa trong DSLTC neu da mo lop
				else { //da mo
					GhiChu("Mon Hoc da duoc mo lop tin chi!Khong the xoa", 20, 27, 79, 500); TextColor(12);
					gotoXY(33 + vitri, y); goto Reset; break;
				}
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ESC || key == DELETE) {
			return;
		}
	}
}
//-- sap xep theo ten mon hoc
void SortDSMH(DS_MonHoc& DSMH, int n) { //Lop khong qua nhieu. Dung Selection Sort la Ok r
	MonHoc* min;
	int vitrimin;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		min = DSMH.monhoc[i];
		vitrimin = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(min->TENMH, DSMH.monhoc[j]->TENMH) > 0)
			{
				min = DSMH.monhoc[j];
				vitrimin = j;
			}
		}
		min = DSMH.monhoc[vitrimin];
		DSMH.monhoc[vitrimin] = DSMH.monhoc[i];
		DSMH.monhoc[i] = min;
	}
}
// --xem danh sach mon
void xemMonHoc(PTRLTC& DSLTC, DS_MonHoc& DSMH, int chedoxem) { // 1 xem,  != 1 xuli
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongmh, dem = 0, demdong = 0;
	bool check_change = false;
	while (1)
	{
		soluongmh = DSMH.n;
		if (soluongmh == 0)
		{
			GhiChu("Chua co du lieu Mon Hoc", 35, 27, 79, 500);
		}
		else {
			if (soluongmh < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluongmh - 1) / 15 + 1);
			}
		}
		SortDSMH(DSMH, DSMH.n);
		dem = 0; demdong = 0;
		TextColor(14);	system("cls");
		Khung_Xuat_MH();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongmh; i++)
		{
			TextColor(12); gotoXY(6, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(10, 8 + demdong); cout << DSMH.monhoc[i]->MAMH;
			gotoXY(31, 8 + demdong); cout << DSMH.monhoc[i]->TENMH;
			gotoXY(72, 8 + demdong); cout << DSMH.monhoc[i]->STCLT;
			gotoXY(80, 8 + demdong); cout << DSMH.monhoc[i]->STCTH;
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 73, 26);
		if (chedoxem == 1)//Dang o che do xem
		{
			TextColor(236); gotoXY(18, 24); cout << "                        DANG O CHE DO XEM!                      ";
			TextColor(236); gotoXY(33, 2); cout << " NHAN ESC DE THOAT CHE DO XEM";
		}	gotoXY(81, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == F1 && chedoxem != 1)
		{
			if (FullMH(DSMH)) { continue; }
			gotoXY(18, 24);  TextColor(251);	cout << "F1";	//Tô màu F1
			ThemMonHoc(DSMH, check_change);
		}
		if (key == F3 && chedoxem != 1)
		{
			gotoXY(33, 24);  TextColor(251);	cout << "F3";	
			SuaMonHoc(DSMH, DSLTC, check_change);
		}
		if (key == DELETE && chedoxem != 1)
		{
			gotoXY(56, 24);  TextColor(251);	cout << "DELETE";	
			XoaMonHoc(DSLTC, DSMH, check_change);
		}
		if (key == F2)
		{
			if (check_change == true)
			{
				putchar(7);	gotoXY(45, 24);  TextColor(251);	cout << "F2"; 
				int temp = ThongBao_ESC();
				if (temp == -1) { continue; }
				if (temp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					GhiFileDSMH(DSMH);  GhiFileLTC(DSLTC);
				}
				if (temp == 0) { GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000); }
			}
		}
		if (key == ESC) {
			if (chedoxem == 1) {
				gotoXY(15, 2); TextColor(14); cout << "                                                         ";
				return;
			};
			system("cls");
			return;
		}
		if (key == F5 && chedoxem == 1) {
			gotoXY(15, 2); TextColor(14); cout << "                                                         ";
			return;
		}
	}
}
// =======================LOP TIN CHI====================================================================

//--dem sl lop tin chi-----------
int DemLTC(PTRLTC DSLTC) {
	if (DSLTC != NULL)
	{
		return (DemLTC(DSLTC->left) + DemLTC(DSLTC->right) + 1);
	}
	else return 0;
}
//load tam tat ca mon hoc vao de xu li //
void MangTam_LTC(PTRLTC DSLTC, LopTinChi ltc[], int& dem) {
	//phep duyet LNR
	if (DSLTC != NULL)
	{
		MangTam_LTC(DSLTC->left, ltc, dem);
		ltc[dem++] = DSLTC->info;
		MangTam_LTC(DSLTC->right, ltc, dem);
	}
}
//--sinh ma lop tin chi ngau nhien
void Swap(int* number_1, int* number_2)
{
	int temp = *number_1;
	*number_1 = *number_2;
	*number_2 = temp;
}
void tronMang(int* mltc, int n) {
	srand((int)time(0));
	int min;
	int max= n-1;
	int swapVT;
	int i = 0;
	while (i < n-1) {
		min = i + 1;
		swapVT = rand() % (max - min + 1)+min;
		Swap(&mltc[i], &mltc[swapVT]);
		i++;
	}
	for (int j = 0; j < n; j++) {
		if (mltc[j] == MAXLOPTC/2)
		Swap(&mltc[n-1],&mltc[j]);
	}
}

void GhiFileMLTC(int* mltc, int& n) {
	ofstream outfile;
	outfile.open("MLTC.txt");
	for (int i = 0; i < n; i++)
	{
		outfile << mltc[i] << " ";
	}
	outfile.close();
}
void DocFileMLTC(int* mltc, int n) {
	ifstream infile;
	infile.open("MLTC.txt", ios::in);
	if (!infile) {
		for (int i = 0; i < n; i++) {
			mltc[i] = i+1;
		}
		tronMang(mltc, n);
		GhiFileMLTC(mltc, n);
		return;
	}
	int i = 0;
	while (infile.good()) {
		infile >> mltc[i];
		i++;
	}
	infile.close();
}

int KiemtraBo4K(PTRLTC& DSLTC, LopTinChi lopTc) {
	if (DSLTC != NULL)
	{
		KiemtraBo4K(DSLTC->left, lopTc);
		if ((strcmp(DSLTC->info.MAMH, lopTc.MAMH) == 0) &&
			(strcmp(DSLTC->info.NIENKHOA, lopTc.NIENKHOA) == 0) &&
			(DSLTC->info.HOCKI == lopTc.HOCKI) &&
			(DSLTC->info.NHOM == lopTc.NHOM)) {
			return 1;
		}
		KiemtraBo4K(DSLTC->right, lopTc);
	}
	else return 0;
		
}
void nhapDSLTC(PTRLTC& DSLTC, DS_MonHoc DSMH, int*& MALTC, int& n) {
	KhungLTC();
	int x = 38, y = 2;
	int key, HK;
	int vitri = 0;
	char hocki, nienkhoa[10];
NIENKHOANHAP:
	while (1) {
		TextColor(14);
		gotoXY(38 + vitri, y);
		key = GetKey();
		if (((key <= '9' && key >= '0') && (vitri < 9)) || ((key == '-') && (vitri < 9)))
		{
			nienkhoa[vitri] = char(key);
			nienkhoa[vitri] = toupper(nienkhoa[vitri]);
			cout << nienkhoa[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(38 + vitri, y);
			cout << " ";
			gotoXY(38 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (nienkhoa[0] - '0') * 1000 + (nienkhoa[1] - '0') * 100 + (nienkhoa[2] - '0') * 10 + (nienkhoa[3] - '0');
			int b = (nienkhoa[5] - '0') * 1000 + (nienkhoa[6] - '0') * 100 + (nienkhoa[7] - '0') * 10 + (nienkhoa[8] - '0');
			if (nienkhoa[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 30, 4, 79, 2000);
				continue;
			}
			else if (b - a != 1) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC     ", 30, 4, 79, 2000);
				continue;
			}
			else {
				nienkhoa[vitri] = '\0';
				vitri = 0;
				gotoXY(60 + vitri, y);
				goto HOCKINHAP;
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("       NIEN KHOA PHAI DAY DU 9 KI TU !VD: 2019-2020!      ", 30, 4, 79, 2000);
				gotoXY(38 + vitri, y);
				continue;
			}
		}
		if (key == ESC) {
			return;
		}
	}
HOCKINHAP:
	while (1) {
		gotoXY(60 + vitri, y);
		key = GetKey();
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			hocki = char(key);
			cout << hocki;
			HK = hocki - '0';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			hocki = '\0';
			GhiChu("             DANG NHAP THANH CONG            ", 30, 4, 79, 700);
			system("cls");
			break;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(60 + vitri, y);
			cout << " ";
			gotoXY(60 + vitri, y);
		}
		if (key == LEFT)
		{
			hocki = '\0';
			vitri = strlen(nienkhoa);
			gotoXY(38 + vitri, y);
			goto NIENKHOANHAP;
		}
	}
	if (key == ESC) {
		return;
	}
	int soluonglop = DemLTC(DSLTC);
	LopTinChi* lopTc = new LopTinChi[MAXLOPTC];
	for (int i = 0; i < MAXLOPTC - soluonglop; i++) {
		lopTc[i].MALOPTC = 0; lopTc[i].MAMH[0] = NULL; strcpy(lopTc[i].NIENKHOA, nienkhoa); lopTc[i].HOCKI = HK; lopTc[i].NHOM = 0; lopTc[i].SoSVMIN = 0; lopTc[i].SoSVMAX = 0;
	}
	int dem = 0, demkhongdoi = 0;
	int STT = 1; int vtmltc = n;
	x = 10; y = 8;
	int check_trung;
	int pochinki = 0;
	bool check_change = false;
	Khung_Nhap_LTC();
	TextColor(12);
	gotoXY(6, 8); cout << STT;
	char tam[11];
	memset(tam, 0, sizeof(tam));
	TextColor(14);
MALOPTC:
	while (1)
	{
		vitri = 0;
		TextColor(14);
		gotoXY(9 + vitri, y);
		cout << MALTC[vtmltc - 1];
		lopTc[dem].MALOPTC = MALTC[vtmltc - 1];
		vtmltc--;
		gotoXY(41 + vitri, y); // vi tri nhap tiep theo
		cout << lopTc[dem].NIENKHOA;
		gotoXY(56 + vitri, y); // vi tri nhap tiep theo
		cout << lopTc[dem].HOCKI;
		vitri = strlen(lopTc[dem].MAMH);
		gotoXY(24 + vitri, y);
		goto MAMH;
	}
MAMH:
	while (1)
	{
		TextColor(244);				//Chu thich
		gotoXY(16, 29); cout << "                                                            ";
		gotoXY(16, 30); cout << " MA MON HOC: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 10 KI TU  ";
		gotoXY(16, 31); cout << "       F5 DE XEM DANH SACH MON HOC                          ";
		TextColor(14);
		gotoXY(24 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			lopTc[dem].MAMH[vitri] = char(key);
			lopTc[dem].MAMH[vitri] = toupper(lopTc[dem].MAMH[vitri]);
			cout << lopTc[dem].MAMH[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc[dem].MAMH[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc[dem].MAMH, DSMH.n);
			if (temp == -1) {
				vitri = 0;
				gotoXY(64 + vitri, y);
				goto NHOM;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 35, 27, 79, 700);
				gotoXY(24 + vitri, y);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(24 + vitri, y);
			cout << " ";
			gotoXY(24 + vitri, y);
		}
		if (key == RIGHT)
		{
			lopTc[dem].MAMH[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc[dem].MAMH, DSMH.n);
			if (temp == -1) {
				vitri = 0;
				gotoXY(64 + vitri, y);
				goto NHOM;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 35, 27, 79, 700);
				gotoXY(24 + vitri, y);
				continue;
			}
		}
		if (key == F5)
		{
			lopTc[dem].MAMH[vitri] = '\0';
			xemMonHoc(DSLTC, DSMH, 1);
			system("cls");
			Khung_Nhap_LTC();
			int yt = 8;
			for (int i = 0; i < dem; i++) {
				gotoXY(6, yt); cout << i + 1;
				gotoXY(9, yt); cout << lopTc[i].MALOPTC;
				gotoXY(24, yt); cout << lopTc[i].MAMH;
				gotoXY(41, yt); cout << lopTc[i].NIENKHOA;
				gotoXY(56, yt); cout << lopTc[i].HOCKI;
				gotoXY(64, yt); cout << lopTc[i].NHOM;
				gotoXY(71, yt); cout << lopTc[i].SoSVMIN;
				gotoXY(81, yt); cout << lopTc[i].SoSVMAX;
				yt++;
			}
			gotoXY(6, yt); cout << dem + 1;
			gotoXY(9, yt); cout << lopTc[dem].MALOPTC;
			gotoXY(24, yt); cout << lopTc[dem].MAMH;
			gotoXY(41, yt); cout << lopTc[dem].NIENKHOA;
			gotoXY(56, yt); cout << lopTc[dem].HOCKI;
		}
		if (key == F2)
		{
			if (check_change == true) //Co su thay doi
			{
				lopTc[dem].MAMH[vitri] = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					continue;
				}
				if (temp == 1)
				{
					GhiChu("Luu file thanh cong", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) { InsertNode_LTC(DSLTC, lopTc[i]); n--; }
					GhiFileLTC(DSLTC); GhiFileMLTC(MALTC, n);
				}
				if (temp == 0) {
					GhiChu("Luu file khong thanh cong", 35, 27, 79, 2000);
				}
			}
		}
		if (key == ESC)
		{
			delete lopTc;
			system("cls");	return;
		}
	}
NHOM:
	while (1)
	{
		TextColor(244);				//Chu thich
		gotoXY(16, 29); cout << "                                                            ";
		gotoXY(16, 30); cout << "       NHOM : GOM CAC KI TU  (1-9), TOI DA: 1 KI TU         ";
		gotoXY(16, 31); cout << "                                                            ";
		TextColor(14);
		gotoXY(64 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc[dem].HOCKI == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap hoc ki", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(24, y);
			goto MAMH;
		}
		char nhom;
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			nhom = char(key);
			nhom = toupper(nhom);
			cout << nhom;
			lopTc[dem].NHOM = nhom - '0';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			nhom = '\0';
			pochinki = KiemtraBo4K(DSLTC, lopTc[dem]);
			for (int i = 0; i < dem; i++) {
				if ((strcmp(lopTc[i].MAMH, lopTc[dem].MAMH) == 0) && (strcmp(lopTc[i].NIENKHOA, lopTc[dem].NIENKHOA) == 0)
					&& (lopTc[i].HOCKI == lopTc[dem].HOCKI) && (lopTc[i].NHOM == lopTc[dem].NHOM))
					pochinki = 2;
			}
			if (0 != pochinki) {
				GhiChu("Thong tin 4 field Ma mon hoc, Nien Khoa, Hoc ki, Nhom khong duoc trung", 20, 27, 79, 2000);
				continue;
			}
			else {
				vitri = 0;
				gotoXY(71 + vitri, y);
				goto SOLUONGMIN;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(64 + vitri, y);
			cout << " ";
			gotoXY(64 + vitri, y);
		}
		if (key == LEFT)
		{
			nhom = '\0';
			vitri = 0;
			gotoXY(24 + vitri, y);
			goto MAMH;
		}
		if (key == RIGHT)
		{
			nhom = '\0';
			pochinki = KiemtraBo4K(DSLTC, lopTc[dem]);
			for (int i = 0; i < dem; i++) {
				if ((strcmp(lopTc[i].MAMH, lopTc[dem].MAMH) == 0) && (strcmp(lopTc[i].NIENKHOA, lopTc[dem].NIENKHOA) == 0)
					&& (lopTc[i].HOCKI == lopTc[dem].HOCKI) && (lopTc[i].NHOM == lopTc[dem].NHOM))
					pochinki = 2;
			}
			if (0 != pochinki) {
				GhiChu("Thong tin 4 field Ma mon hoc, Nien Khoa, Hoc ki, Nhom khong duoc trung", 20, 27, 79, 2000);
				continue;
			}
			else {
				vitri = 0;
				gotoXY(71 + vitri, y);
				goto SOLUONGMIN;
			}
		}
		if (key == F2)
		{
			if (check_change == true) //Co su thay doi
			{
				nhom = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					continue;
				}
				if (temp == 1)
				{
					GhiChu("Luu file thanh cong", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) { InsertNode_LTC(DSLTC, lopTc[i]); n--; }
					GhiFileLTC(DSLTC); GhiFileMLTC(MALTC, n);
				}
				if (temp == 0) {
					GhiChu("Luu file khong thanh cong", 35, 27, 79, 2000);
				}
			}
		}
		if (key == ESC)
		{
			delete lopTc;
			system("cls");	return;
		}
	}
SOLUONGMIN:
	while (1)
	{
		TextColor(244);				//Chu thich
		gotoXY(16, 29); cout << "                                                            ";
		gotoXY(16, 30); cout << "    SO LUONG : GOM CAC KI TU  (0-9), TOI DA: 3 KI TU        ";
		gotoXY(16, 31); cout << "                                                            ";
		TextColor(14);
		gotoXY(71 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc[dem].NHOM == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap nhom", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(64, y);
			goto NHOM;
		}
		char svmin[4];
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			svmin[vitri] = char(key);
			svmin[vitri] = toupper(svmin[vitri]);
			cout << svmin[vitri];
			lopTc[dem].SoSVMIN = atoi(svmin);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			svmin[vitri] = '\0';
			vitri = 0;
			gotoXY(81 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(71 + vitri, y);
			cout << " ";
			gotoXY(71 + vitri, y);
		}
		if (key == LEFT)
		{
			svmin[vitri] = '\0';
			vitri = 0;
			gotoXY(64 + vitri, y);
			goto NHOM;
		}
		if (key == RIGHT)
		{
			svmin[vitri] = '\0';
			vitri = 0;
			gotoXY(81 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == F2)
		{
			if (check_change == true) //Co su thay doi
			{
				svmin[vitri] = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					continue;
				}
				if (temp == 1)
				{
					GhiChu("Luu file thanh cong", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) { InsertNode_LTC(DSLTC, lopTc[i]); n--; }
					GhiFileMLTC(MALTC, n);
					GhiFileLTC(DSLTC);
				}
				if (temp == 0) {
					GhiChu("Luu file khong thanh cong", 35, 27, 79, 2000);
				}
			}
		}
		if (key == ESC)
		{
			delete lopTc;
			system("cls");	return;
		}
	}
SOLUONGMAX:
	while (1)
	{
		TextColor(244);				//Chu thich
		gotoXY(16, 29); cout << "                                                            ";
		gotoXY(16, 30); cout << "    SO LUONG : GOM CAC KI TU  (0-9), TOI DA: 3 KI TU        ";
		gotoXY(16, 31); cout << "        ENTER DE TIEP TUC HOAC ESC DE THOAT                 ";
		TextColor(14);
		gotoXY(81 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc[dem].SoSVMIN == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap SL sv min", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(71, y);
			goto SOLUONGMIN;
		}
		char svmax[5];
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			svmax[vitri] = char(key);
			svmax[vitri] = toupper(svmax[vitri]);
			cout << svmax[vitri];
			lopTc[dem].SoSVMAX = atoi(svmax);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (lopTc[dem].SoSVMAX <= lopTc[dem].SoSVMIN) {
				GhiChu("So luong SV max phai lon hon SV min", 35, 27, 79, 700);
				vitri = 0;
				continue;
			}
			else {
				svmax[vitri] = '\0'; // cai nay de ngat chuoi, chuyen sang ben phai hoac trai nhap tiep
				check_change = true;
				GhiChu("Da luu vao danh sach ltc", 40, 27, 228, 500);
				gotoXY(6, y + 1);
				if (lopTc[dem + 1].MALOPTC == 0 && dem == demkhongdoi)	//Khong cho bien dem tang len khi sua loi~ cac NK phia' trên
				{
					TextColor(12);
					cout << ++STT;
					demkhongdoi++;
					TextColor(14);
					gotoXY(27, 4); cout << "SO LOP TIN CHI HIEN TAI LA:" << demkhongdoi + soluonglop;
				}
				if ((STT - 1) % 15 == 0) //Khi svien day` khung. Reset lai khung
				{
					y = 7;
					system("cls");
					TextColor(14);
					Khung_Nhap_LTC();
					TextColor(12);
					gotoXY(6, 8);
					cout << STT;
				}
				dem++;
				gotoXY(10 + vitri, ++y);
				goto MALOPTC;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(81 + vitri, y);
			cout << " ";
			gotoXY(81 + vitri, y);
		}
		if (key == LEFT)
		{
			svmax[vitri] = '\0';
			vitri = 0;
			gotoXY(71 + vitri, y);
			goto SOLUONGMIN;
		}
		if (key == F2)
		{
			if (check_change == true) //Co su thay doi
			{
				svmax[vitri] = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					continue;
				}
				if (temp == 1)
				{
					GhiChu("Luu file thanh cong", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) { InsertNode_LTC(DSLTC, lopTc[i]); n--; }
					GhiFileMLTC(MALTC, n);
					GhiFileLTC(DSLTC);
				}
				if (temp == 0) {
					GhiChu("Luu file khong thanh cong", 35, 27, 79, 2000);
				}
				
			}
		}
		if (key == ESC)
		{
			delete lopTc;
			system("cls");	return;
		}
	}
}
//Them Lop Tin chi.
void ThemLTC(PTRLTC& DSLTC, DS_MonHoc& DSMH,int*& MALTC, int&n, bool& check_change) {
	int key;
	int STT = 1;
	int vitri = 0, x = 9, y = 11;
	int check_trung;
	int pochinki;
	LopTinChi lopTc;
	lopTc.MALOPTC = 0; lopTc.MAMH[0] = NULL; lopTc.NIENKHOA[0] = NULL; lopTc.HOCKI = 0; lopTc.NHOM = 0; lopTc.SoSVMIN = 0; lopTc.SoSVMAX = 0;
	Khung_Them_LTC();
	TextColor(12);
	char tam[11];
	memset(tam, 0, sizeof(tam));
	gotoXY(x, y);

MALOPTC:
	while (1)
	{
		TextColor(14);
		gotoXY(9 + vitri, y);
		cout << MALTC[n-1];
		lopTc.MALOPTC = MALTC[n-1];
		vitri = strlen(lopTc.MAMH);
		gotoXY(24 + vitri, y);
		goto MAMH;
	}
MAMH:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(19, 13); cout << "Ki tu so & chu: (A-Z) && (0-9). Toi da 10 ki tu! F5 xem mon hoc!!";
		TextColor(14);
		gotoXY(24 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			lopTc.MAMH[vitri] = char(key);
			lopTc.MAMH[vitri] = toupper(lopTc.MAMH[vitri]);
			cout << lopTc.MAMH[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.MAMH[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc.MAMH,DSMH.n);
			if (temp == -1) {
				vitri = strlen(lopTc.NIENKHOA);
				gotoXY(41 + vitri, y);
				goto NIENKHOA;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 35, 27, 79, 700);
				gotoXY(24 + vitri, y);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(24 + vitri, y);
			cout << " ";
			gotoXY(24 + vitri, y);
		}
		if (key == RIGHT)
		{
			lopTc.MAMH[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc.MAMH,DSMH.n);
			if (temp == -1) {
				vitri = strlen(lopTc.NIENKHOA);
				gotoXY(41 + vitri, y);
				goto NIENKHOA;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 35, 27, 79, 700);
				gotoXY(24 + vitri, y);
				continue;
			}
		}
		if (key == F5)
		{
			lopTc.MAMH[vitri] = '\0';
			xemMonHoc(DSLTC, DSMH, 1);
			Khung_Them_LTC();
			gotoXY(9, y); cout << lopTc.MALOPTC;
			gotoXY(24, y); cout << lopTc.MAMH;
			gotoXY(41, y); cout << lopTc.NIENKHOA;
			gotoXY(54, y); cout << lopTc.HOCKI;
			gotoXY(64, y); cout << lopTc.NHOM;
			gotoXY(71, y); cout << lopTc.SoSVMIN;
			gotoXY(81, y); cout << lopTc.SoSVMAX;
			TextColor(223); gotoXY(18, 24); cout << "           NHAN F5 DE BAT CHUC NANG DI CHUYEN        ";
			TextColor(14);	gotoXY(40, y); cout << lopTc.MAMH[vitri];
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
NIENKHOA:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(19, 13); cout << "Ki tu: (0-9 , -). NIEN KHOA DAY DU 9 KI TU!VD: 2019-2020!         ";
		TextColor(14);
		gotoXY(41 + vitri, y);
		key = GetKey();
		
		if (((key <= '9' && key >= '0') && (vitri < 9))||((key == '-') && (vitri < 9)))
		{
			lopTc.NIENKHOA[vitri] = char(key);
			lopTc.NIENKHOA[vitri] = toupper(lopTc.NIENKHOA[vitri]);
			cout << lopTc.NIENKHOA[vitri];
			vitri++;
		}
		if (key == ENTER && vitri == 9) {
			int a = (lopTc.NIENKHOA[0] - '0') * 1000 + (lopTc.NIENKHOA[1] - '0') * 100 + (lopTc.NIENKHOA[2] - '0') * 10 + (lopTc.NIENKHOA[3] - '0');
			int b = (lopTc.NIENKHOA[5] - '0') * 1000 + (lopTc.NIENKHOA[6] - '0') * 100 + (lopTc.NIENKHOA[7] - '0') * 10 + (lopTc.NIENKHOA[8] - '0');
			if (lopTc.NIENKHOA[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
				continue;
			}
			else if (b - a != 1 ) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC     ", 35, 27, 79, 1000);
				continue;
			}
			else {
				lopTc.NIENKHOA[vitri] = '\0';
				vitri = 0;
				gotoXY(54 + vitri, y);
				goto HOCKI;
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("NIEN KHOA PHAI DAY DU 9 KI TU!VD: 2019-2020", 35, 27, 79, 700);
				gotoXY(38 + vitri, y);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(41 + vitri, y);
			cout << " ";
			gotoXY(41 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.NIENKHOA[vitri] = '\0';
			vitri = strlen(lopTc.MAMH);
			gotoXY(24 + vitri, y);
			goto MAMH;
		}
		if (key == RIGHT && vitri == 9) {
			if (key == RIGHT && vitri == 9) {
				int a = (lopTc.NIENKHOA[0] - '0') * 1000 + (lopTc.NIENKHOA[1] - '0') * 100 + (lopTc.NIENKHOA[2] - '0') * 10 + (lopTc.NIENKHOA[3] - '0');
				int b = (lopTc.NIENKHOA[5] - '0') * 1000 + (lopTc.NIENKHOA[6] - '0') * 100 + (lopTc.NIENKHOA[7] - '0') * 10 + (lopTc.NIENKHOA[8] - '0');
				if (lopTc.NIENKHOA[4] != '-') {
					GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
					continue;
				}
				else if (b - a != 1 ) {
					GhiChu("         NAM SAU PHAI LON HON NAM TRUOC    ", 35, 27, 79, 1000);
					continue;
				}
				else {
					lopTc.NIENKHOA[vitri] = '\0';
					vitri = 0;
					gotoXY(54 + vitri, y);
					goto HOCKI;
				}
			}
		}
		else {
			if (key == RIGHT && vitri != 9) {
				GhiChu("NIEN KHOA PHAI DAY DU 9 KI TU!VD: 2019-2020", 35, 27, 79, 700);
				gotoXY(38 + vitri, y);
				continue;
			}
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
HOCKI:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(19, 13); cout << "Ki tu so: (0-9). Toi da 1 ki tu!                          ";
		TextColor(14);
		gotoXY(54 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.NIENKHOA[0] == '\0')
		{
			GhiChu("Ban chua nhap nien khoa", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(41, y);
			goto NIENKHOA;
		}
		char HK;
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			HK = char(key);
			HK = toupper(HK);
			cout << HK;
			lopTc.HOCKI= HK -'0';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			HK= '\0';
			vitri = 0;
			gotoXY(64 + vitri, y);
			goto NHOM;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(54 + vitri, y);
			cout << " ";
			gotoXY(54 + vitri, y);
		}
		if (key == LEFT)
		{
			HK = '\0';
			vitri = strlen(lopTc.NIENKHOA);
			gotoXY(41 + vitri, y);
			goto NIENKHOA;
		}
		if (key == RIGHT)
		{
			HK = '\0';
			vitri = 0;
			gotoXY(64 + vitri, y);
			goto NHOM;
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
NHOM:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(19, 13); cout << "Ki tu so: (0-9). Toi da 1 ki tu!                          ";
		TextColor(14);
		gotoXY(64 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.HOCKI == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap hoc ki", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(54, y);
			goto HOCKI;
		}
		char nhom;
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			nhom = char(key);
			nhom = toupper(nhom);
			cout << nhom;
			lopTc.NHOM = nhom - '0';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			nhom = '\0';
			pochinki = KiemtraBo4K(DSLTC, lopTc);
			if (0 == pochinki) {
				vitri = 0;
				gotoXY(71 + vitri, y);
				goto SOLUONGMIN;
			}
			if (1 == pochinki) {
				GhiChu("Thong tin 4 field Ma mon hoc, Nien Khoa, Hoc ki, Nhom khong duoc trung", 20, 27, 79, 2000);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(64 + vitri, y);
			cout << " ";
			gotoXY(64 + vitri, y);
		}
		if (key == LEFT)
		{
			nhom = '\0';
			vitri = 0;
			gotoXY(54 + vitri, y);
			goto HOCKI;
		}
		if (key == RIGHT)
		{
			nhom = '\0';
			int pochinki = KiemtraBo4K(DSLTC, lopTc);
			if (0 == pochinki) {
				vitri = strlen(_itoa(lopTc.SoSVMIN, tam, 10));
				gotoXY(71 + vitri, y);
				goto SOLUONGMIN;
			}
			if (1 == pochinki) {
				GhiChu("Thong tin 4 field Ma mon hoc, Nien Khoa, Hoc ki, Nhom khong duoc trung", 20, 27, 79, 2000);
				continue;
			}
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
SOLUONGMIN:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(19, 13); cout << "Ki tu so : (0-9). Toi da 999 sinh vien!";
		TextColor(14);
		gotoXY(71 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.NHOM == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap nhom", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(64, y);
			goto NHOM;
		}
		char svmin[4];
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			svmin[vitri] = char(key);
			svmin[vitri] = toupper(svmin[vitri]);
			cout << svmin[vitri];
			lopTc.SoSVMIN = atoi(svmin);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			svmin[vitri] = '\0';
			vitri = 0;
			gotoXY(81 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(71 + vitri, y);
			cout << " ";
			gotoXY(71 + vitri, y);
		}
		if (key == LEFT)
		{
			svmin[vitri] = '\0';
			vitri = 0;
			gotoXY(64 + vitri, y);
			goto NHOM;
		}
		if (key == RIGHT)
		{
			svmin[vitri] = '\0';
			vitri = 0;
			gotoXY(81 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
SOLUONGMAX:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(19, 13); cout << "Ki tu so : (0-9). Toi da 999 sinh vien!";
		TextColor(14);
		gotoXY(81 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.SoSVMIN == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap SL sv min", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(71, y);
			goto SOLUONGMIN;
		}
		char svmax[5];
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			svmax[vitri] = char(key);
			svmax[vitri] = toupper(svmax[vitri]);
			cout << svmax[vitri];
			lopTc.SoSVMAX = atoi(svmax);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (lopTc.SoSVMAX <= lopTc.SoSVMIN) {
				GhiChu("So luong SV max phai lon hon SV min", 35, 27, 79, 700);
				vitri = 0;
				continue;
			}
			else {
				check_change = true;
				svmax[vitri] = '\0'; // cai nay de ngat chuoi, chuyen sang ben phai hoac trai nhap tiep
				InsertNode_LTC(DSLTC, lopTc); n--;
				GhiChu("Da luu vao bo nho", 40, 27, 228, 500);
				return;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(81 + vitri, y);
			cout << " ";
			gotoXY(81 + vitri, y);
		}
		if (key == LEFT)
		{
			svmax[vitri] = '\0';
			vitri = 0;
			gotoXY(71 + vitri, y);
			goto SOLUONGMIN;
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
}
//Xoa Lop Tin chi
void remove_case_3(PTRLTC& rp, PTRLTC& r) {
	if (r->left != NULL)
	{
		remove_case_3(rp, r->left);
	}
	//den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
	else {
		rp->info = r->info;			//cap nhat du lieu vô cùng trái sang con tro can xóa-> free rp
		rp = r;						//cap nhat dia chi vô cùng trái sang con tro can xóa->
		r = r->right;				//ben phai cua vô cùng trai' dôn` lên
	}
}
void DeleteLTC(PTRLTC& p, int x) {
	if (p == NULL) { return; }//khong tim thay
	else
		//Truong hop root > hoac < x
		if (x < p->info.MALOPTC)
			DeleteLTC(p->left, x);
		else if (x > p->info.MALOPTC)
			DeleteLTC(p->right, x);
	    //Truong Hop root == x
		else {
			PTRLTC rp = p;		//Cho con tro tai vi tri muon xoa vao 1 con tro? tam. de lat' xoa
			if (rp->right == NULL)  p = rp->left;
			// p là nút lá hoac la nut chi co cay con ben trai
			else if (rp->left == NULL)
				p = rp->right;  // p là nut co cay con ben phai
			else remove_case_3(p, rp->right);
			delete rp;
		}
}
void XoaLTC(PTRLTC& DSLTC, bool& check_change) {
	int key;
	int x = 33, y = 14;
	int vitri = 0, kiemtra;
	char tam[11];
	Khung_Xoa_LTC();
	gotoXY(x, y);
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 5))
		{
			tam[vitri] = char(key);
			tam[vitri] = toupper(tam[vitri]);
			cout << tam[vitri];
			vitri++;
			int mltc = atoi(tam);
		}
		if (key == ENTER && vitri != 0)
		{
			tam[vitri] = '\0';
			int mltc = atoi(tam);
			kiemtra = Search_malopTc(DSLTC, mltc);
			if (-1 == kiemtra) {
				GhiChu("LOP TIN CHI KHONG TON TAI!", 35, 27, 79, 700);
				gotoXY(33 + vitri, y);
				continue;
			}
			else {
				if (DSLTC->info.DSSVDK != NULL) {
					GhiChu("LOP TIN CHI DA CO SINH VIEN. KHONG THE XOA!", 35, 27, 79, 700);
					continue;
				}
				check_change = true;
				DeleteLTC(DSLTC, mltc);
				GhiChu("XOA THANH CONG LOP TIN CHI", 35, 27, 79, 1000);
				return;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ESC || key == DELETE) {
			return;
		}
	}
}
//sua ltc
void SuaLTC(PTRLTC& DSLTC, DS_MonHoc DSMH, bool& check_change) {
	int key; int x = 33, y = 11; int vitri = 0, vitri_LTC;
	PTRLTC p;
	char tam[10];
	int check_trung;
	int maLtc_trung;
	int ktmaLtc_trung;
	LopTinChi lopTc; 	lopTc.MALOPTC = 0; lopTc.MAMH[0] = NULL; lopTc.NIENKHOA[0] = NULL; lopTc.HOCKI = 0; lopTc.NHOM = 0; lopTc.SoSVMIN = 0; lopTc.SoSVMAX = 0;
	Khung_Sua_LTC();
	gotoXY(x, y);
	while (1) {
		TextColor(14);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 10))
		{
			tam[vitri] = char(key);
			tam[vitri] = toupper(tam[vitri]);
			cout << tam[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			tam[vitri] = '\0';
			lopTc.MALOPTC = atoi(tam);
			vitri_LTC = Search_malopTc(DSLTC,lopTc.MALOPTC);
			if (-1 == vitri_LTC) {
				GhiChu("LOP TIN CHI KHONG TON TAI!", 35, 27, 79, 700);
				gotoXY(33 + vitri, y);
				TextColor(14);
				continue;
			}
			else {
				vitri = 0;
				gotoXY(9, y);
				Khung_Them_LTC();
				TextColor(14);
				p = Search_LTC(DSLTC, lopTc.MALOPTC);
				lopTc.MALOPTC = p->info.MALOPTC;
				strcpy(lopTc.MAMH, p->info.MAMH);
				strcpy(lopTc.NIENKHOA, p->info.NIENKHOA);
				lopTc.HOCKI = p->info.HOCKI;
				lopTc.NHOM = p->info.NHOM;
				lopTc.SoSVMIN = p->info.SoSVMIN;
				lopTc.SoSVMAX = p->info.SoSVMAX;
				gotoXY(9, y); cout << lopTc.MALOPTC;
				gotoXY(24, y); cout << lopTc.MAMH;
				gotoXY(41, y); cout << lopTc.NIENKHOA;
				gotoXY(54, y); cout << lopTc.HOCKI;
				gotoXY(64, y); cout << lopTc.NHOM;
				gotoXY(71, y); cout << lopTc.SoSVMIN;
				gotoXY(81, y); cout << lopTc.SoSVMAX;
				goto MALOPTC;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ESC || key == F2)
		{
			return;
		}
	}
MALOPTC:
	while (1)
	{
		TextColor(14);
		gotoXY(9 + vitri, y);
		cout <<lopTc.MALOPTC;
		vitri = strlen(lopTc.MAMH);
		gotoXY(24 + vitri, y);
		goto MAMH;
	}
MAMH:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(15, 13); cout << "Ki tu so & chu: (A-Z) && (0-9). Toi da 10 ki tu! F5 de xem mon hoc!";
		TextColor(14);
		gotoXY(24 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			lopTc.MAMH[vitri] = char(key);
			lopTc.MAMH[vitri] = toupper(lopTc.MAMH[vitri]);
			cout << lopTc.MAMH[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			lopTc.MAMH[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc.MAMH, DSMH.n);
			if (temp == -1) {
				vitri = strlen(lopTc.NIENKHOA);
				gotoXY(41 + vitri, y);
				goto NIENKHOA;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 35, 27, 79, 700);
				gotoXY(24 + vitri, y);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(24 + vitri, y);
			cout << " ";
			gotoXY(24 + vitri, y);
		}
		if (key == RIGHT)
		{
			lopTc.MAMH[vitri] = '\0';
			int temp;
			temp = KTMH(DSMH, lopTc.MAMH, DSMH.n);
			if (temp == -1) {
				vitri = strlen(lopTc.NIENKHOA);
				gotoXY(41 + vitri, y);
				goto NIENKHOA;
			}
			else {
				GhiChu("MON HOC KHONG TON TAI", 35, 27, 79, 700);
				gotoXY(24 + vitri, y);
				continue;
			}
		}
		if (key == F5)
		{
			lopTc.MAMH[vitri] = '\0';
			xemMonHoc(DSLTC,DSMH,1);
			Khung_Them_LTC();
			gotoXY(9, y); cout << lopTc.MALOPTC;
			gotoXY(24, y); cout << lopTc.MAMH;
			gotoXY(41, y); cout << lopTc.NIENKHOA;
			gotoXY(54, y); cout << lopTc.HOCKI;
			gotoXY(64, y); cout << lopTc.NHOM;
			gotoXY(71, y); cout << lopTc.SoSVMIN;
			gotoXY(81, y); cout << lopTc.SoSVMIN;
			TextColor(223); gotoXY(18, 24); cout << "           NHAN F5 DE BAT CHUC NANG DI CHUYEN        ";
			TextColor(14);	gotoXY(40, y); cout << lopTc.MAMH[vitri];
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
NIENKHOA:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(15, 13); cout << "Ki tu: (0-9 , -). NIEN KHOA DAY DU 9 KI TU! VD:2019-2020                ";
		TextColor(14);
		gotoXY(41 + vitri, y);
		key = GetKey();

		if (((key <= '9' && key >= '0') && (vitri < 9)) || ((key == '-') && (vitri < 9)))
		{
			lopTc.NIENKHOA[vitri] = char(key);
			lopTc.NIENKHOA[vitri] = toupper(lopTc.NIENKHOA[vitri]);
			cout << lopTc.NIENKHOA[vitri];
			vitri++;
		}
		if (key == ENTER && vitri == 9) {
			if (key == ENTER && vitri == 9) {
				int a = (lopTc.NIENKHOA[0] - '0') * 1000 + (lopTc.NIENKHOA[1] - '0') * 100 + (lopTc.NIENKHOA[2] - '0') * 10 + (lopTc.NIENKHOA[3] - '0');
				int b = (lopTc.NIENKHOA[5] - '0') * 1000 + (lopTc.NIENKHOA[6] - '0') * 100 + (lopTc.NIENKHOA[7] - '0') * 10 + (lopTc.NIENKHOA[8] - '0');
				if (lopTc.NIENKHOA[4] != '-') {
					GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
					continue;
				}
				else if (b - a != 1) {
					GhiChu("         NAM SAU PHAI LON HON NAM TRUOC     ", 35, 27, 79, 1000);
					continue;
				}
				else {
					lopTc.NIENKHOA[vitri] = '\0';
					vitri = 1;
					gotoXY(54 + vitri, y);
					goto HOCKI;
				}
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("NIEN KHOA PHAI DAY DU 9 KI TU!VD: 2019-2020", 35, 27, 79, 700);
				gotoXY(38 + vitri, y);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(41 + vitri, y);
			cout << " ";
			gotoXY(41 + vitri, y);
		}
		if (key == LEFT)
		{
			lopTc.NIENKHOA[vitri] = '\0';
			vitri = strlen(lopTc.MAMH);
			gotoXY(24 + vitri, y);
			goto MAMH;
		}
		if (key == RIGHT && vitri == 9) {
			if (key == RIGHT && vitri == 9) {
				int a = (lopTc.NIENKHOA[0] - '0') * 1000 + (lopTc.NIENKHOA[1] - '0') * 100 + (lopTc.NIENKHOA[2] - '0') * 10 + (lopTc.NIENKHOA[3] - '0');
				int b = (lopTc.NIENKHOA[5] - '0') * 1000 + (lopTc.NIENKHOA[6] - '0') * 100 + (lopTc.NIENKHOA[7] - '0') * 10 + (lopTc.NIENKHOA[8] - '0');
				if (lopTc.NIENKHOA[4] != '-') {
					GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
					continue;
				}
				else if (b - a != 1) {
					GhiChu("         NAM SAU PHAI LON HON NAM TRUOC    ", 35, 27, 79, 1000);
					continue;
				}
				else {
					lopTc.NIENKHOA[vitri] = '\0';
					vitri = 1;
					gotoXY(54 + vitri, y);
					goto HOCKI;
				}
			}
		}
		else {
			if (key == RIGHT && vitri != 9) {
				GhiChu("NIEN KHOA PHAI DAY DU 9 KI TU!VD: 2019-2020", 35, 27, 79, 700);
				gotoXY(38 + vitri, y);
				continue;
			}
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
HOCKI:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(15, 13); cout << "Ki tu so: (0-9). Toi da 1 ki tu!                          ";
		TextColor(14);
		gotoXY(54 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.NIENKHOA[0] == '\0')
		{
			GhiChu("Ban chua nhap nien khoa", 35, 27, 79, 700);
			vitri = strlen(lopTc.NIENKHOA);
			gotoXY(41, y);
			goto NIENKHOA;
		}
		char HK;
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			HK = char(key);
			HK = toupper(HK);
			cout << HK;
			lopTc.HOCKI = HK - '0';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			HK = '\0';
			vitri = 1;
			gotoXY(64 + vitri, y);
			goto NHOM;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(54 + vitri, y);
			cout << " ";
			gotoXY(54 + vitri, y);
		}
		if (key == LEFT)
		{
			HK = '\0';
			vitri = strlen(lopTc.NIENKHOA);
			gotoXY(41 + vitri, y);
			goto NIENKHOA;
		}
		if (key == RIGHT)
		{
			HK = '\0';
			vitri = 1;
			gotoXY(64 + vitri, y);
			goto NHOM;
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
NHOM:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(15, 13); cout << "Ki tu so: (0-9). Toi da 1 ki tu!                          ";
		TextColor(14);
		gotoXY(64 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.HOCKI == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap hoc ki", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(54, y);
			goto HOCKI;
		}
		char nhom;
		if ((key <= '9' && key >= '1') && (vitri < 1))
		{
			nhom = char(key);
			nhom = toupper(nhom);
			cout << nhom;
			lopTc.NHOM = nhom - '0';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			nhom = '\0';
			int pochinki = KiemtraBo4K(DSLTC, lopTc);
			if (0 == pochinki) {
				vitri = strlen(_itoa(lopTc.SoSVMIN, tam, 10));
				gotoXY(71 + vitri, y);
				goto SOLUONGMIN;
			}
			if (1 == pochinki) {
				GhiChu("Thong tin 4 field Ma mon hoc, Nien Khoa, Hoc ki, Nhom khong duoc trung", 20, 27, 79, 2000);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(64 + vitri, y);
			cout << " ";
			gotoXY(64 + vitri, y);
		}
		if (key == LEFT)
		{
			nhom = '\0';
			vitri = 1;
			gotoXY(54 + vitri, y);
			goto HOCKI;
		}
		if (key == RIGHT)
		{
			nhom = '\0';
			int pochinki = KiemtraBo4K(DSLTC, lopTc);
			if (0 == pochinki) {
				vitri = strlen(_itoa(lopTc.SoSVMIN, tam, 10));
				gotoXY(71 + vitri, y);
				goto SOLUONGMIN;
			}
			if (1 == pochinki) {
				GhiChu("Thong tin 4 field Ma mon hoc, Nien Khoa, Hoc ki, Nhom khong duoc trung", 20, 27, 79, 2000);
				continue;
			}
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
SOLUONGMIN:
	while (1)
	{
		TextColor(WHITE);
		gotoXY(15, 13); cout << "Ki tu so : (0-9). Toi da 999 sinh vien!";
		TextColor(14);
		gotoXY(71 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		if (lopTc.NHOM == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap nhom", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(64, y);
			goto NHOM;
		}
		char svmin[4];
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			svmin[vitri] = char(key);
			svmin[vitri] = toupper(svmin[vitri]);
			cout << svmin[vitri];
			lopTc.SoSVMIN = atoi(svmin);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			svmin[vitri] = '\0';
			vitri = strlen(_itoa(lopTc.SoSVMAX, tam, 10));
			gotoXY(81 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(71 + vitri, y);
			cout << " ";
			gotoXY(71 + vitri, y);
		}
		if (key == LEFT)
		{
			svmin[vitri] = '\0';
			vitri = 1;
			gotoXY(64 + vitri, y);
			goto NHOM;
		}
		if (key == RIGHT)
		{
			svmin[vitri] = '\0';
			vitri = strlen(_itoa(lopTc.SoSVMAX, tam, 10));
			gotoXY(81 + vitri, y);
			goto SOLUONGMAX;
		}
		if (key == ESC || key == F1)
		{
			return;
		}
	}
SOLUONGMAX:
	while (1)
	{
		TextColor(245);
		gotoXY(15, 13); cout << "Ki tu so : (0-9). Toi da 999 sinh vien!";
		TextColor(14);
		gotoXY(81 + vitri, y); // vi tri nhap tiep theo
		key = GetKey();
		char svmax[4];
		if (lopTc.SoSVMIN == 0)		//Kiem tra Ephú} truoc cEdu~ lieu chua
		{
			GhiChu("Ban chua nhap so SV min", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(71, y);
			goto SOLUONGMIN;
		}
		if ((key <= '9' && key >= '0') && (vitri < 3))
		{
			svmax[vitri] = char(key);
			svmax[vitri] = toupper(svmax[vitri]);
			cout << svmax[vitri];
			lopTc.SoSVMAX = atoi(svmax);
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (lopTc.SoSVMAX <= lopTc.SoSVMIN) {
				GhiChu("So luong SV max phai lon hon SV min", 35, 27, 79, 700);
				vitri = 0;
				continue;
			}
			else {
				check_change = true;
				svmax[vitri] = '\0'; // cai nay de ngat chuoi, chuyen sang ben phai hoac trai nhap tiep
				p->info = lopTc;
				GhiChu("Da luu vao bo nho", 40, 27, 228, 500);	TextColor(12);
				return;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(81 + vitri, y);
			cout << " ";
			gotoXY(81 + vitri, y);
		}
		if (key == LEFT)
		{
			svmax[vitri] = '\0';
			vitri = strlen(_itoa(lopTc.SoSVMIN, tam, 10));
			gotoXY(71 + vitri, y);
			goto SOLUONGMIN;
		}
		if (key == ESC || key == F2)
		{
			return;
		}
	}
}
void XemDSLTC(PTRLTC& DSLTC, DS_MonHoc& DSMH, int* MALTC, int& n, int chedoxem) { // che do 1: chi xem !=1 cho phep xuli
	int key;
	int dem = 0, demdong = 0, trang = 0, tongtrang = 0;
	bool check_change = false;
	int soluongLTC;
	while (1) {
		soluongLTC = DemLTC(DSLTC);
		if (0 == soluongLTC) {
			GhiChu("Chua co danh sach lop", 35, 27, 79, 1000);
		}
		else {
			if (soluongLTC < 15) {
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluongLTC - 1) / 15 + 1);
			}
		}
		LopTinChi* LTC = new LopTinChi[soluongLTC + 1];
		MangTam_LTC(DSLTC, LTC, dem); //Do Cay Nhi Phan ra Mang
		dem = 0; demdong = 0;
		TextColor(14);	system("cls");
		Khung_Xuat_LTC();

		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongLTC; i++) {

			TextColor(12); gotoXY(6, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(10, 8 + demdong); cout << LTC[i].MALOPTC;
			gotoXY(24, 8 + demdong); cout << LTC[i].MAMH;
			gotoXY(41, 8 + demdong); cout << LTC[i].NIENKHOA;
			gotoXY(56, 8 + demdong); cout << LTC[i].HOCKI;
			gotoXY(65, 8 + demdong); cout << LTC[i].NHOM;
			gotoXY(73, 8 + demdong); cout << LTC[i].SoSVMIN;
			gotoXY(81, 8 + demdong); cout << LTC[i].SoSVMAX;
			demdong++;
		}
		HienThiTrang(trang + 1, tongtrang, 65, 26);
		if (chedoxem == 1) { //Dang o che do xem
			TextColor(14); gotoXY(18, 24); cout << "               DANG O CHE DO XEM!            ";
			TextColor(236); gotoXY(15, 2); cout << "              NHAN ESC DE THOAT CHE DO XEM          ";
		}
		gotoXY(73, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == F1 && chedoxem != 1)
		{
			gotoXY(18, 24);  TextColor(246);	cout << "F1"; //To mau` F1
			ThemLTC(DSLTC, DSMH, MALTC, n, check_change);
		}
		if (key == F3 && chedoxem != 1)
		{
			gotoXY(45, 24);	TextColor(246);	cout << "F3"; //To mau` F2
			SuaLTC(DSLTC, DSMH, check_change);
		}
		if (key == DELETE && chedoxem != 1)
		{
			gotoXY(56, 24);	TextColor(246);	cout << "DELETE"; //To mau` delete 
			XoaLTC(DSLTC, check_change);
		}
		if (key == F2)
		{
			if (check_change == true)
			{
				putchar(7);	gotoXY(33, 24); TextColor(246); cout << "F2"; //To mau` f2
				int temp = ThongBao_ESC();
				if (temp == -1) { continue; }	//Tra ve -1 => Bat' duoc phim' ESC 1 lân` nua~
				if (temp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					GhiFileLTC(DSLTC); GhiFileMLTC(MALTC, n);
				}
				if (temp == 0) { GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000); }
			}
		}
		if (key == ESC)
		{
			if (chedoxem == 1) {
				delete LTC; return;
			};
			system("cls"); delete LTC;
			return;
		}
		if (key == F5 && chedoxem == 1) {
			delete LTC; return;
		}
	}
}
//===============================SINH VIEN=============================================================================================================
//insert sv
void Insert_First(PTR_SV &first,SinhVien sv){
	PTR_SV p;
	p=new node_SV;
	p->info=sv;
	p->next=first;
	first=p;
}
void Insert_Last(PTR_SV &first,SinhVien sv){
	if(first==NULL) {
		Insert_First(first,sv);
		return;
	}
	PTR_SV q;
	q=new node_SV;
	q->info=sv;
	q->next=NULL;
	PTR_SV p=first;
	while(p->next!=NULL) p=p->next;
	p->next=q;
}
//dung selecttion sort
void SortSV(PTR_SV &first){
	PTR_SV p,q,pmin;
	SinhVien min;
	for(p=first;p->next!=NULL;p=p->next){
		min=p->info;
		pmin=p;
		for(q=p->next;q!=NULL;q=q->next){
			if(strcmp(min.MALOP,q->info.MALOP)>0){
				min=q->info;
				pmin=q;
			}else if(strcmp(min.MALOP,q->info.MALOP)==0){
				if(strcmp(min.MASV,q->info.MASV)>0){
					min=q->info;
					pmin=q;
				}
			}
			pmin->info=p->info;
			p->info=min;
		}
	}
}
//Xoa Sinh Vien
void XoaDauSV(PTR_SV &DSSV) {
	PTR_SV p = DSSV;
	DSSV = DSSV->next;	
	delete p;
}
void XoaSV(PTR_SV &DSSV, char c[]) {
	PTR_SV temp = NULL;
	for (PTR_SV p = DSSV; p != NULL; p = p->next)
	{
		if(strcmp(p->info.MASV, c) == 0&&p==DSSV){
			XoaDauSV(DSSV);
			return;
		}
		else if (strcmp(p->info.MASV, c) == 0)
		{
			temp->next = p->next;	delete p;	return;
		}
		temp = p; // temp luon la con tro truoc ben trai' cua con tro dang duyet
	}
}
//----thao tac file SINh Vien-------
//----thao tac file SINh Vien-------
void DocFileSV(PTR_SV &listSV)
{
	string data;
	fstream infile; 
   	infile.open("DSSV.txt",ios::in);
   	if (!infile) { 
		GhiChu("Khong tim thay file", 35, 27, 79, 2000); 
		return; 
	} //Khong tim thay file
	while (infile.good())
	{
		SinhVien sv;
		getline(infile, data);
		if (data.size() == 0) { break; } //Da co file nhung chua co du lieu
		strcpy(sv.MALOP,data.c_str());
		getline(infile, data);		strcpy(sv.MASV, data.c_str());
		getline(infile, data);		strcpy(sv.HO, data.c_str());
		getline(infile, data);		strcpy(sv.TEN, data.c_str());
		getline(infile, data);		strcpy(sv.PHAI, data.c_str());
		getline(infile, data);		strcpy(sv.SDT, data.c_str());
		getline(infile, data);		sv.NAMNHAPHOC = atoi(data.c_str());
		Insert_Last(listSV,sv);
	}
	infile.close();
}
void GhiFileSV(PTR_SV listSV)
{
	ofstream outfile;
   	outfile.open("DSSV.txt",ios::out);
   	if(outfile.is_open()){
		for(PTR_SV p=listSV ;p!=NULL;p=p->next){
			outfile<<p->info.MALOP<<endl
			<<p->info.MASV<<endl
			<<p->info.HO<<endl
			<<p->info.TEN<<endl
			<<p->info.PHAI<<endl
			<<p->info.SDT<<endl
			<<p->info.NAMNHAPHOC<<endl;
		}
	}
	outfile.close();
}
//---------------------ham de xu li lop va dssv----------------
int DemSinhVien(PTR_SV DSSV)
{
	int dem = 0;
	for (PTR_SV p = DSSV; p != NULL; p = p->next)  dem++; 
	return dem;
}
int DemSinhVien(PTR_SV DSSV, char c[])
{
	int dem = 0;
	for (PTR_SV p = DSSV; p != NULL; p = p->next) {
		if (strcmp(p->info.MALOP, c) == 0)
		{
			dem++;
		}
	}
	return dem;
}
int KTSV(PTR_SV DSSV, char msv[])
{
	for (PTR_SV p = DSSV; p != NULL; p = p->next)
	{
		if (strcmp(p->info.MASV, msv) == 0)
		{
			return 1;
		}
	}	
	return 0;
}
PTR_SV Search_MSV(PTR_SV DSSV, char msv[]) {
	if (NULL == DSSV) {
		return NULL;
	}
	for (PTR_SV p = DSSV; p != NULL; p = p->next) {
		if (strcmp(p->info.MASV, msv) == 0) {
			return p;
		}
	}return NULL;
}
//Nhap hang loat sinh vien-------------------------
void NhapSinhVien(PTRLTC DSLTC,PTR_SV &listSV, DS_MonHoc DSMH)
{
	int key;
	int check_trung;
	int x = 40, y = 2, vitri = 0, vitriMang, temp;
	int STT = 1;
	bool check_change = false;
	Khung_Nhap_MaLop();
	char malop[12];
	gotoXY(x, y); //Khoi tao rong~
				  //cai nay de tim ma lop
	while (1)
	{
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			malop[vitri] = char(key);
			malop[vitri] = toupper(malop[vitri]);
			cout << malop[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			malop[vitri] = '\0';
			TextColor(14);	system("cls");	break;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40 + vitri, y);
			cout << " ";
			gotoXY(40 + vitri, y);
		}
		if (key == ESC) { TextColor(14);	return; }
	}
	//neu o tren ok thi bd nhap
	x = 10, y = 8, vitri = 0;
	int dem = 0; //dem vi tri dong cua con tro hien tai
	int demkhongdoi = 0; // dem tong so sinh vien dang nhap vao
	SinhVien demsv[MAXSV];
	string namNhapHoc[10];
	for (int i = 0; i < MAXSV; i++) // Khoi tao mang tam rong~
	{
		strcpy(demsv[i].MALOP,malop);
		demsv[i].MASV[0] = NULL;
		demsv[i].HO[0] = NULL;
		demsv[i].TEN[0] = NULL;
		demsv[i].PHAI[0] = NULL;
		demsv[i].SDT[0] = NULL;
	}
	gotoXY(10,0);
	cout<<malop;
	Khung_Nhap_SV();
	TextColor(12);		gotoXY(6, 8); 	 cout << STT;
	TextColor(14); //In STT dau tien
MASV:
	while (1)
	{
		TextColor(252);				//Chu thich
		gotoXY(20, 26); cout << "                                                              ";
		gotoXY(20, 27); cout << " MA SINH VIEN: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 10 KI TU  ";
		gotoXY(20, 28); cout << "                                                              ";
		TextColor(14);
		gotoXY(10 + vitri, y);
		key = GetKey();
		if (demsv[dem - 1].SDT[0] == '\0' && y > 8)		//Kiem tra ô phía truoc' có du~ lieu chua
		{
			GhiChu("Ban Chua Nhap SDT!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(69, --y);
			dem--;
			goto SDT;
		}
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			demsv[dem].MASV[vitri] = char(key);
			demsv[dem].MASV[vitri] = toupper(demsv[dem].MASV[vitri]);
			cout << demsv[dem].MASV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(10 + vitri, y);
			cout << " ";
			gotoXY(10 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			demsv[dem].MASV[vitri] = '\0';
			for (int i = 0; i <= demkhongdoi; i++)
			{
				if (i == dem) { continue; }	// khi user sua loi~ cac MASV o tren bo? qua duyet bô. dêm. chính nó
				if (strcmp(demsv[i].MASV, demsv[dem].MASV) == 0) //KT trung sinh vien o mang? tam va trong bo nho trong ko
				{
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 35, 27, 79, 500);
					goto MASV;
				}
			}
			for(PTR_SV p=listSV;p!=NULL;p=p->next){
				if(strcmp(p->info.MASV,demsv[dem].MASV)==0){
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 35, 27, 79, 500);
					goto MASV;
				}
			}
			vitri = strlen(demsv[dem].HO);
			gotoXY(26 + vitri, y);
			goto HO;
		}
		if(key==ESC){
			system("cls");	return;
		}
		if (key == F2)
		{
			if (check_change == true)
			{
				demsv[dem].MASV[vitri] = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4, 24);
					TextColor(252);
					cout << "ESC"; //Tô màu ESC
					TextColor(14);
					continue;
				}
				if (temp == 1) // 1 la YES 
				{
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);//cho nay se dung insert last
					}	//Do? mang? tam. vao DSLK (bo nho trong)
					SortSV(listSV);
					GhiFileSV(listSV);
				}
				if (temp == 0) // 0 la NO
				{
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}
					SortSV(listSV);	//Do? mang? tam. vao DSLK (bo nho trong)
				}
			}
		}
		if (key == RIGHT)
		{
			demsv[dem].MASV[vitri] = '\0';
			for (int i = 0; i <= demkhongdoi; i++)
			{
				if (i == dem) { continue; }	// khi user sua loi~ cac MASV o tren bo? qua duyet bô. dêm. chính nó
				if (strcmp(demsv[i].MASV, demsv[dem].MASV) == 0) //KT trung sinh vien o mang? tam.
				{
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 35, 27, 79, 500);
					goto MASV;
				}
			}
			for(PTR_SV p=listSV;p!=NULL;p=p->next){
				if(strcmp(p->info.MASV,demsv[dem].MASV)==0){
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 35, 27, 79, 500);
					goto MASV;
				}
			}
			vitri = strlen(demsv[dem].HO);
			gotoXY(26 + vitri, y);
			goto HO;
		}
		if (key == DOWN && y < 22 && demsv[dem + 1].MASV[0] != '\0')
		{
			demsv[dem].MASV[vitri] = '\0';
			for (int i = 0; i <= demkhongdoi; i++) {
				if (i == dem) { continue; }// khi user sua loi cac MASV o tren bo qua duyet bô. dêm. chính nó
				if (strcmp(demsv[i].MASV, demsv[dem].MASV) == 0) //KT trung sinh vien o mang? tam.
				{
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 35, 27, 79, 500);
					goto MASV;
				}
			}
			for(PTR_SV p=listSV;p!=NULL;p=p->next){
				if(strcmp(p->info.MASV,demsv[dem].MASV)==0){
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 35, 27, 79, 500);
					goto MASV;
				}
			}
			dem++;
			vitri = strlen(demsv[dem].MASV);
			gotoXY(10 + vitri, ++y);
		}
		if (key == UP &&	y > 8)
		{
			demsv[dem].MASV[vitri] = '\0';
			for (int i = 0; i <= demkhongdoi; i++) {
				if (i == dem) { continue; }	// khi user sua loi cac MASV o tren bo qua duyet bô. dêm. chính nó
				if (strcmp(demsv[i].MASV, demsv[dem].MASV) == 0) //KT trung sinh vien o mang? tam.
				{
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 35, 27, 79, 500);
					goto MASV;
				}
			}
			for(PTR_SV p=listSV;p!=NULL;p=p->next){
				if(strcmp(p->info.MASV,demsv[dem].MASV)==0){
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!", 35, 27, 79, 500);
					goto MASV;
				}
			}
			dem--;
			vitri = strlen(demsv[dem].MASV);
			gotoXY(10 + vitri, --y);
		}
	}
HO:
	while (1)
	{
		TextColor(252);			//Chu thich
		gotoXY(20, 26); cout << "                                                              ";
		gotoXY(20, 27); cout << "      HO: GOM CAC KI TU (A-Z), TOI DA: 20 KI TU       ";
		gotoXY(20, 28); cout << "                                                              ";
		TextColor(14);
		gotoXY(26 + vitri, y);
		key = GetKey();
		if (demsv[dem].MASV[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Sinh Vien!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(10, y);
			goto MASV;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 20))
		{
			demsv[dem].HO[vitri] = char(key);
			demsv[dem].HO[vitri] = toupper(demsv[dem].HO[vitri]);
			cout << demsv[dem].HO[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(26 + vitri, y);
			cout << " ";
			gotoXY(26 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (demsv[dem].HO[vitri - 1] == ' ') { vitri--; }//KT khi enter truoc do co phai khoang trang
			demsv[dem].HO[vitri] = '\0';
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47 + vitri, y);
			goto TEN;
		}
		if (key == SPACE && demsv[dem].HO[vitri - 1] != ' ' && vitri > 0 && vitri < 20)
		{
			gotoXY(26 + vitri, y);
			cout << " ";
			demsv[dem].HO[vitri] = ' ';
			vitri++;
		}
		if(key==ESC){
			system("cls");	return;
		}
		if (key == F2)
		{
			if (check_change == true)
			{
				demsv[dem].HO[vitri] = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4, 24);  TextColor(252);	cout << "ESC"; //Tô màu ESC
					TextColor(14); continue;
				}
				if (temp == 1)
				{
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}//Do? mang? tam. vao DSLK (bo nho trong)
					SortSV(listSV);
					GhiFileSV(listSV);
				}
				if (temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}//Do mang? tam. vao DSLK (bo nho trong)
					SortSV(listSV);
				}
			}
			system("cls");	return;
		}
		if (key == LEFT)
		{
			demsv[dem].HO[vitri] = '\0';
			vitri = strlen(demsv[dem].MALOP);
			gotoXY(10 + vitri, y);
			goto MASV;
		}
		if (key == RIGHT)
		{
			demsv[dem].HO[vitri] = '\0';
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47 + vitri, y);
			goto TEN;
		}
		if (key == UP && y > 8)
		{
			demsv[dem].HO[vitri] = '\0';
			dem--;
			vitri = strlen(demsv[dem].HO);
			gotoXY(26 + vitri, --y);
		}
		if (key == DOWN && y < 22 && demsv[1 + dem].HO[0] != '\0')
		{
			demsv[dem].HO[vitri] = '\0';
			dem++;
			vitri = strlen(demsv[dem].HO);
			gotoXY(26 + vitri, ++y);
		}
	}
TEN:
	while (1)
	{
		TextColor(252);			//Chu thich
		gotoXY(20, 26); cout << "                                                               ";
		gotoXY(20, 27); cout << "          TEN: GOM CAC KI TU (A-Z), TOI DA: 10 KI TU           ";
		gotoXY(20, 28); cout << "                                                               ";
		TextColor(14); gotoXY(47 + vitri, y);
		key = GetKey();
		if (demsv[dem].HO[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ho!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(26, y);
			goto HO;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			demsv[dem].TEN[vitri] = char(key);
			demsv[dem].TEN[vitri] = toupper(demsv[dem].TEN[vitri]);
			cout << demsv[dem].TEN[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(47 + vitri, y);
			cout << " ";
			gotoXY(47 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			demsv[dem].TEN[vitri] = '\0';
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58 + vitri, y);
			goto PHAI;
		}
		if(key==ESC){
			system("cls");	return;
		}
		if (key == F2)
		{
			if (check_change == true)
			{
				demsv[dem].TEN[vitri] = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4, 24);  TextColor(252);	cout << "ESC";
					TextColor(14); continue;//Tô màu ESC
				}
				if (temp == 1)
				{
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}//Do mang tam. vao DSLK (bo nho trong)
					SortSV(listSV);
					GhiFileSV(listSV); // luu file luon
				}
				if (temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}//Do? mang tam. vao DSLK (bo nho trong)
					SortSV(listSV);
				}
			}
			system("cls");	return;
		}
		if (key == LEFT)
		{
			demsv[dem].TEN[vitri] = '\0';
			vitri = strlen(demsv[dem].HO);
			gotoXY(26 + vitri, y);
			goto HO;
		}
		if (key == RIGHT)
		{
			demsv[dem].TEN[vitri] = '\0';
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58 + vitri, y);
			goto PHAI;
		}
		if (key == UP && y > 8)
		{
			demsv[dem].TEN[vitri] = '\0';
			dem--;
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47 + vitri, --y);
		}
		if (key == DOWN && y < 22 && demsv[1 + dem].TEN[0] != '\0')
		{
			demsv[dem].TEN[vitri] = '\0';
			dem++;
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47 + vitri, ++y);
		}
	}
PHAI:
	while (1)
	{
		TextColor(252);			//Chu thich
		gotoXY(20, 26); cout << "                                                                ";
		gotoXY(20, 27); cout << "      PHAI: GOM CAC KI TU (A-Z) - NAM/NU, TOI DA: 3 KI TU       ";
		gotoXY(20, 28); cout << "                                                                ";
		TextColor(14); gotoXY(58 + vitri, y);
		key = GetKey();
		if (demsv[dem].TEN[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ten!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(47, y);
			goto TEN;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 3))
		{
			demsv[dem].PHAI[vitri] = char(key);
			demsv[dem].PHAI[vitri] = toupper(demsv[dem].PHAI[vitri]);
			cout << demsv[dem].PHAI[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(58 + vitri, y);
			cout << " ";
			gotoXY(58 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			demsv[dem].PHAI[vitri] = '\0';
			if ((strcmp(demsv[dem].PHAI, "NAM") == 0) || (strcmp(demsv[dem].PHAI, "NU") == 0)) // So sanh
			{
				vitri = strlen(demsv[dem].SDT);
				gotoXY(69 + vitri, y);
				goto SDT;
			}
			GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 79, 500); continue;
		}
		if(key==ESC){
			system("cls");	return;
		}
		if (key == F2)
		{
			if (check_change == true)
			{
				demsv[dem].PHAI[vitri] = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4, 24);  TextColor(252);	cout << "ESC"; //Tô màu ESC
					TextColor(14); continue;
				}
				if (temp == 1)
				{
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}//Do? mang? tam. vao DSLK (bo nho trong)
					SortSV(listSV);
					GhiFileSV(listSV);
				}
				if (temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}//Do? mang? tam. vao DSLK (bo nho trong)
					SortSV(listSV);
				}
			}
			system("cls"); 	return;
		}
		if (key == LEFT)
		{
			demsv[dem].PHAI[vitri] = '\0';
			if ((strcmp(demsv[dem].PHAI, "NAM") != 0) && (strcmp(demsv[dem].PHAI, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 79, 500);
				continue;
			}
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47 + vitri, y);
			goto TEN;
		}
		if (key == RIGHT)
		{
			demsv[dem].PHAI[vitri] = '\0';
			if ((strcmp(demsv[dem].PHAI, "NAM") != 0) && (strcmp(demsv[dem].PHAI, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 79, 500);
				continue;
			}
			vitri = strlen(demsv[dem].SDT);
			gotoXY(69 + vitri, y);
			goto SDT;
		}
		if (key == UP && y > 8)
		{
			demsv[dem].PHAI[vitri] = '\0';
			if ((strcmp(demsv[dem].PHAI, "NAM") != 0) && (strcmp(demsv[dem].PHAI, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 79, 500);
				continue;
			}
			dem--;
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58 + vitri, --y);
		}
		if (key == DOWN && y < 22 && demsv[1 + dem].PHAI[0] != '\0')
		{
			demsv[dem].PHAI[vitri] = '\0';
			if ((strcmp(demsv[dem].PHAI, "NAM") != 0) && (strcmp(demsv[dem].PHAI, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 79, 500);
				continue;
			}
			dem++;
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58 + vitri, ++y);
		}
	}
SDT:
	while (1)
	{
		TextColor(252);
		gotoXY(20, 26); cout << "                                                                 ";
		gotoXY(20, 27); cout << "      SO DIEN THOAI: GOM CAC KI TU (0-9), TOI DA: 10 KI TU       ";
		gotoXY(20, 28); cout << "                                                                 ";
		TextColor(14); gotoXY(69 + vitri, y);
		key = GetKey();
		if (demsv[dem].PHAI[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Phai!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(58, y);
			goto PHAI;
		}
		if ((key <= '9' && key >= '0') && (vitri < 10))
		{
			demsv[dem].SDT[vitri] = char(key);
			demsv[dem].SDT[vitri] = toupper(demsv[dem].SDT[vitri]);
			cout << demsv[dem].SDT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(69 + vitri, y);
			cout << " ";
			gotoXY(69 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			check_change = true;
			TextColor(14);
			demsv[dem].SDT[vitri] = '\0';
			vitri = namNhapHoc[dem].length();
			gotoXY(85 + vitri, y);
			goto NAMNHAPHOC;
		}
		if(key==ESC){
			system("cls");	return;
		}
		if (key == F2)
		{
			if (check_change == true)
			{
				demsv[dem].SDT[vitri] = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4, 24);  TextColor(252);	cout << "ESC"; //Tô màu ESC
					TextColor(14);	continue;
				}
				if (temp == 1)
				{
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}//Do? mang? tam. vao DSLK (bo nho trong)
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					SortSV(listSV);
					GhiFileSV(listSV);
				}
				if (temp == 0)
				{
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}//Do? mang? tam. vao DSLK (bo nho trong)
					SortSV(listSV);
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				}
			}
			system("cls");	return;
		}
		if (key == LEFT)
		{
			demsv[dem].SDT[vitri] = '\0';
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58 + vitri, y);
			goto PHAI;
		}
		if(key==RIGHT){
			demsv[dem].SDT[vitri]='\0';
			vitri = namNhapHoc[dem].length();
			gotoXY(58 + vitri, y);
			goto NAMNHAPHOC;
		}
		if (key == UP && y > 8)
		{
			demsv[dem].SDT[vitri] = '\0';
			dem--;
			vitri = strlen(demsv[dem].SDT);
			gotoXY(69 + vitri, --y);
		}
		if (key == DOWN && y < 22 && demsv[dem + 1].SDT[0] != '\0')
		{
			demsv[dem].SDT[vitri] = '\0';
			dem++;
			vitri = strlen(demsv[dem].SDT);
			gotoXY(69 + vitri, ++y);
		}
	}
NAMNHAPHOC:
	while (1)
	{
		TextColor(252);
		gotoXY(20, 26); cout << "                                                                 ";
		gotoXY(20, 27); cout << "      NAM NHAP HOC: GOM CAC KI TU (0-9), TOI DA: 10 KI TU       ";
		gotoXY(20, 28); cout << "                                                                 ";
		TextColor(14); gotoXY(85 + vitri, y);
		key = GetKey();
		if (demsv[dem].SDT[0] == '\0')
		{
			GhiChu("Ban Chua Nhap So Dien Thoai!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(69, y);
			goto SDT;
		}
		if ((key <= '9' && key >= '0') && (vitri < 4))
		{
			namNhapHoc[dem][vitri] = char(key);
			namNhapHoc[dem][vitri] = toupper(namNhapHoc[dem][vitri]);
			cout <<namNhapHoc[dem][vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(85 + vitri, y);
			cout << " ";
			gotoXY(85 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			check_change = true;
			TextColor(14);
			namNhapHoc[dem][vitri] = '\0';
			GhiChu("Save Thanh Cong!", 40, 27, 79, 500);
			gotoXY(6, y + 1);
			if (demsv[dem + 1].MASV[0] == '\0' && dem == demkhongdoi) // khong cho bien demkhongdoi tang khi sua loi~ cac SDT o tren
			{
				TextColor(12);
				cout << ++STT; //Cho xuat hien STT
				demkhongdoi++;	// De cuoi cung ESC gan' cho dem
			}
			if ((STT - 1) % 15 == 0)
			{
				y = 7;
				system("cls");
				Khung_Nhap_SV();
				TextColor(12);	gotoXY(6, 8); cout << STT;
			}
			demsv[dem].NAMNHAPHOC=atoi(namNhapHoc[dem].c_str());
			TextColor(14);
			dem++;	//dem nay co the thay doi khi di chuyen => can bien demkhongdoi
			vitri = strlen(demsv[dem].MASV);
			gotoXY(10 + vitri, ++y);
			goto MASV;
		}
		if(key==ESC){
			system("cls");	return;
		}
		if (key == F2)
		{
			if (check_change == true)
			{
				demsv[dem].SDT[vitri] = '\0';
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4, 24);  TextColor(252);	cout << "ESC"; //Tô màu ESC
					TextColor(14);	continue;
				}
				if (temp == 1)
				{
					for (int i = 0; i < demkhongdoi; i++) {
						Insert_Last(listSV,demsv[i]);
					}//Do? mang? tam. vao DSLK (bo nho trong)
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					SortSV(listSV);
					GhiFileSV(listSV);
				}
				if (temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				}
			}
			system("cls");	return;
		}
		if (key == LEFT)
		{
			demsv[dem].SDT[vitri] = '\0';
			vitri = strlen(demsv[dem].SDT);
			gotoXY(69 + vitri, y);
			goto SDT;
		}
		if (key == UP && y > 8)
		{
			demsv[dem].SDT[vitri] = '\0';
			dem--;
			vitri = strlen(demsv[dem].SDT);
			gotoXY(69 + vitri, --y);
		}
		if (key == DOWN && y < 22 && demsv[dem + 1].SDT[0] != '\0')
		{
			demsv[dem].SDT[vitri] = '\0';
			dem++;
			vitri = strlen(demsv[dem].SDT);
			gotoXY(69 + vitri, ++y);
		}
	}
}


//Sua Sinh Vien
void SuaSinhVien(PTR_SV &DSSV, PTRLTC &DSLTC, bool &check_change) {
	int key;
	int check_trung;
	PTR_SV p; //vi tri cua sinh vien trong dssv, tra ve con tro
	int vitri = 0, x = 33, y = 14, temp = 0;
	SinhVien sv;
	char namNhapHoc[4];
	namNhapHoc[0]=NULL;
	sv.MALOP[0]=NULL;sv.MASV[0] = NULL; sv.HO[0] = NULL; sv.TEN[0] = NULL; sv.PHAI[0] = NULL; sv.SDT[0] = NULL;
	Khung_Sua_SV(); gotoXY(x, y);
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 15))
		{
			sv.MASV[vitri] = char(key);
			sv.MASV[vitri] = toupper(sv.MASV[vitri]);
			cout << sv.MASV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.MASV[vitri] = '\0';	//Ngat chuoi~
			check_trung = KTSV(DSSV, sv.MASV);//KT trung sinh vien trong List
			if (check_trung == 1)//return 1 =>co ton tai sinh vien
			{
				vitri = 0;
				p = Search_MSV(DSSV, sv.MASV);
				x = 12; y = 14;
				Khung_Them_SV();
				strcpy(sv.MALOP, p->info.MALOP);
				strcpy(sv.MASV, p->info.MASV);
				strcpy(sv.HO, p->info.HO);
				strcpy(sv.TEN, p->info.TEN);
				strcpy(sv.PHAI, p->info.PHAI);
				strcpy(sv.SDT, p->info.SDT);
				sv.NAMNHAPHOC =p->info.NAMNHAPHOC;
				_itoa(p->info.NAMNHAPHOC,namNhapHoc,10);
				TextColor(12);
				gotoXY(29, y); cout << sv.HO;
				gotoXY(51, y); cout << sv.TEN;
				gotoXY(63, y); cout << sv.PHAI;
				gotoXY(68, y); cout << sv.SDT;
				gotoXY(85, y); cout << namNhapHoc;
				vitri = strlen(sv.HO);
				TextColor(14);
				goto HO;
				break; //Tra ve con tro? sinh vien da tim` thay'
			}
			else {
				GhiChu("Ma Sinh Vien Khong Ton Tai!", 35, 27, 79, 500);
				TextColor(14);	gotoXY(33 + vitri, y);
			}
		}
		if (key == ESC || key == F1) { return; }
	}
HO:
	while (1)
	{
		TextColor(236);	gotoXY(30, 15); cout << "Ki tu: (A-Z). Toi da: 20";
		TextColor(14); gotoXY(29 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 20))
		{
			sv.HO[vitri] = char(key);
			sv.HO[vitri] = toupper(sv.HO[vitri]);
			cout << sv.HO[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(29 + vitri, y);
			cout << " ";
			gotoXY(29 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (sv.HO[vitri - 1] == ' ') { vitri--; }	//KT khi enter truoc do co phai khoang trang
			sv.HO[vitri] = '\0';
			vitri = strlen(sv.TEN);
			gotoXY(51 + vitri, y);
			goto TEN;
		}
		if (key == SPACE && sv.HO[vitri - 1] != ' ' && vitri > 0 && vitri < 20)
		{
			gotoXY(29 + vitri, y);
			cout << " ";
			sv.HO[vitri] = ' ';
			vitri++;
		}
		if (key == RIGHT)
		{
			if (sv.HO[vitri - 1] == ' ') { vitri--; }	//KT khi enter truoc do co phai khoang trang
			sv.HO[vitri] = '\0';
			vitri = strlen(sv.TEN);
			gotoXY(51 + vitri, y);
			goto TEN;
		}
		if (key == ESC || key == F1) { return; }
	}
TEN:
	while (1)
	{
		TextColor(236);	gotoXY(30, 15); cout << "Ki tu: (A-Z). Toi da: 10        ";
		TextColor(14);  gotoXY(51 + vitri, y);
		key = GetKey();
		if (sv.HO[0] == '\0')
		{
			GhiChu("Ban Chua Nhap HO Sinh Vien!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(29, y);
			goto HO;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			sv.TEN[vitri] = char(key);
			sv.TEN[vitri] = toupper(sv.TEN[vitri]);
			cout << sv.TEN[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(51 + vitri, y);
			cout << " ";
			gotoXY(51 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.TEN[vitri] = '\0';
			vitri = strlen(sv.PHAI);
			gotoXY(63 + vitri, y);
			goto PHAI;
		}
		if (key == LEFT)
		{
			sv.TEN[vitri] = '\0';
			vitri = strlen(sv.HO);
			gotoXY(29 + vitri, y);
			goto HO;
		}
		if (key == RIGHT)
		{
			sv.TEN[vitri] = '\0';
			vitri = strlen(sv.PHAI);
			gotoXY(63 + vitri, y);
			goto PHAI;
		}
		if (key == ESC || key == F1) { return; }
	}
PHAI:
	while (1)
	{
		TextColor(236);	gotoXY(30, 15); cout << "Gioi tinh Nam / Nu. Toi da: 3         ";
		TextColor(14); gotoXY(63 + vitri, y);
		key = GetKey();
		if (sv.TEN[0] == '\0')
		{
			GhiChu("Ban Chua Nhap TEN Sinh Vien!", 35, 27, 79, 700);
			vitri = 0;
			gotoXY(51, y);
			goto TEN;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 3))
		{
			sv.PHAI[vitri] = char(key);
			sv.PHAI[vitri] = toupper(sv.PHAI[vitri]);
			cout << sv.PHAI[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(63 + vitri, y);
			cout << " ";
			gotoXY(63 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.PHAI[vitri] = '\0';
			if ((strcmp(sv.PHAI, "NAM") == 0) || (strcmp(sv.PHAI, "NU") == 0)) // So sanh
			{
				vitri = strlen(sv.SDT);
				goto SDT;
			}
			GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 79, 500); continue;
		}
		if (key == LEFT)
		{
			sv.PHAI[vitri] = '\0';
			if ((strcmp(sv.PHAI, "NAM") != 0) && (strcmp(sv.PHAI, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500); continue;
			}
			vitri = strlen(sv.TEN);
			gotoXY(51 + vitri, y);
			goto TEN;
		}
		if (key == RIGHT)
		{
			sv.PHAI[vitri] = '\0';
			if ((strcmp(sv.PHAI, "NAM") != 0) && (strcmp(sv.PHAI, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam / Nu!", 35, 27, 79, 500);
				continue;
			}
			vitri = strlen(sv.SDT);
			gotoXY(68 + vitri, y);
			goto SDT;
		}
		if (key == ESC || key == F1) { return; }
	}
SDT:
	while (1)
	{
		TextColor(236);	gotoXY(30, 15); cout << "Ki tu: (0-9). Toi da: 11        ";
		TextColor(14);	gotoXY(68 + vitri, y);
		key = GetKey();
		if (sv.PHAI[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Gioi Tinh!", 35, 27, 79, 700);
			gotoXY(63, y);
			goto PHAI;
		}
		if ((key <= '9' && key >= '0') && (vitri < 10))
		{
			sv.SDT[vitri] = char(key);
			sv.SDT[vitri] = toupper(sv.SDT[vitri]);
			cout << sv.SDT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(68 + vitri, y);
			cout << " ";
			gotoXY(68 + vitri, y);
		}
		if (key == RIGHT)
		{
			sv.SDT[vitri] = '\0';
			vitri = strlen(namNhapHoc);
			gotoXY(85 + vitri, y);
			goto NAMNHAPHOC;
		}
		if (key == ENTER && vitri != 0)
		{
			sv.SDT[vitri] = '\0';
			vitri = strlen(namNhapHoc);
			gotoXY(85 + vitri, y);
			goto NAMNHAPHOC;
		}
		if (key == LEFT)
		{
			sv.SDT[vitri] = '\0';
			vitri = strlen(sv.PHAI);
			gotoXY(63 + vitri, y);
			goto PHAI;
		}
		if (key == ESC || key == F1) { return; }
	}
NAMNHAPHOC:
	while (1)
	{
		TextColor(236);	gotoXY(30, 15); cout << "Ki tu: (0-9). Toi da: 4 ki tu        ";
		TextColor(14);	gotoXY(85 + vitri, y);
		key = GetKey();
		if (sv.SDT[0] == '\0')
		{
			GhiChu("Ban Chua Nhap SDT!", 35, 27, 79, 700);
			gotoXY(68, y);
			goto SDT;
		}
		if ((key <= '9' && key >= '0') && (vitri < 4))
		{
			namNhapHoc[vitri] = char(key);
			namNhapHoc[vitri] = toupper(namNhapHoc[vitri]);
			cout << namNhapHoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(85 + vitri, y);
			cout << " ";
			gotoXY(85 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			check_change = true;
			namNhapHoc[vitri] = '\0';
			sv.NAMNHAPHOC=atoi(namNhapHoc);
			p->info = sv;
			GhiChu("Sua thanh cong", 35, 27, 79, 1000);
			return;
		}
		if (key == LEFT)
		{
			sv.SDT[vitri] = '\0';
			vitri = strlen(sv.SDT);
			gotoXY(68 + vitri, y);
			goto SDT;
		}
		if (key == ESC || key == F1) { return; }
	}
}
PTRDK SearchSV_LTC(PTRLTC DSLTC, char masv[]) {
	if (DSLTC == NULL)return NULL;
	SearchSV_LTC(DSLTC->left, masv);
	for (PTRDK p = DSLTC->info.DSSVDK; p != NULL; p = p->next) {
		if (strcmp(p->info.MaSV, masv) == 0)return p;
	}
	SearchSV_LTC(DSLTC->right, masv);
}
void XoaSinhVien(PTRLTC &DSLTC, PTR_SV &DSSV, bool &check_change)
{
	int key, x = 33, y = 14, vitri = 0, temp;
	SinhVien sv; 	sv.MASV[0] = NULL;
	PTRDK p;
	Khung_Xoa_SV();	gotoXY(x, y);
Reset:
	while (1)
	{
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			sv.MASV[vitri] = char(key);
			sv.MASV[vitri] = toupper(sv.MASV[vitri]);
			cout << sv.MASV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			sv.MASV[vitri] = '\0';	//Ngat chuoi~
			temp = KTSV(DSSV, sv.MASV);//KT trung sinh vien trong Listlop
			p = SearchSV_LTC(DSLTC, sv.MASV);
			if (temp == 1)
			{
				if (p != NULL) {
					GhiChu("Sinh Vien Da Dang Ki Mon. Khong Duoc Xoa!", 35, 27, 79, 700);
					TextColor(14);
					gotoXY(33 + vitri, y);
					goto Reset;
				}
				else {
					check_change = true;
					XoaSV(DSSV, sv.MASV);
					return;
				}
			}
			else {
				GhiChu("Ma Sinh Vien Khong Ton Tai!", 35, 27, 79, 500);
				TextColor(14);	gotoXY(33 + vitri, y);
			}
		}
		if (key == ESC || key == DELETE) { return; }
	}
}
//kiem tra ma lop co ton tai khong
PTR_SV KTMaLop(PTR_SV listSV, char c[])
{
	for (PTR_SV p = listSV; p != NULL; p = p->next)
	{
		if (strcmp(p->info.MALOP, c) == 0)
		{
			return p;	// neu trung tra ve vi tri
		}
	}
	return NULL;			// khong tim thay ptu tra ""
}
void XemSinhVien(PTR_SV& listSV, DS_MonHoc DSMH, PTRLTC& DSLTC)
{
	int key;
	int x = 40, y = 2;
	int vitri = 0, vitriMang;
	int STT = 1;
	bool check_change = false;
	char malop[12];
	Khung_Nhap_MaLop();
	gotoXY(x, y);
	PTR_SV temp=NULL;
	while (1)
	{
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			malop[vitri] = char(key);
			malop[vitri] = toupper(malop[vitri]);
			cout << malop[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			malop[vitri] = '\0';
			temp = KTMaLop(listSV, malop); //KT trung ma lop
			if (temp != NULL)
			{
				break;
			}
			else {
				GhiChu("     Ma Lop Khong Ton Tai!    ", 33, 5, 159, 500);
				gotoXY(40 + vitri, y);
				TextColor(14);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40 + vitri, y);
			cout << " ";
			gotoXY(40 + vitri, y);
		}
		if (key == ESC) { TextColor(14); return; }
	}
	int trang = 0, tongtrang = 0, soluongsv = 0;
	int dem1 = 0, dem = 0;	//dem la dem dong`.  dem1 la vitri phan tu sv
	while (1)
	{
		dem1 = 0;
		soluongsv = DemSinhVien(listSV, temp->info.MALOP);
		if (soluongsv == 0)
		{
			GhiChu("Chua co du lieu sinh vien", 35, 27, 79, 500);
		}
		else {
			if (soluongsv < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((soluongsv - 1) / 15 + 1);
			}
		}
		SinhVien* SV = new SinhVien[soluongsv + 1];
		for (PTR_SV p = listSV; p != NULL; p = p->next)
		{
			if (strcmp(p->info.MALOP, temp->info.MALOP) == 0) {
				SV[dem1] = p->info;
				dem1++;
			}
		} //DÃ´? DSSV vÃ o mang?
		TextColor(14);	system("cls");
		Khung_Xuat_SV();
		dem = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongsv; i++)
		{
			TextColor(12); gotoXY(6, 8 + dem); cout << i + 1;
			TextColor(14);
			gotoXY(10, 8 + dem); cout << SV[i].MALOP;
			gotoXY(28, 8 + dem); cout << SV[i].MASV;
			gotoXY(44, 8 + dem); cout << SV[i].HO;
			gotoXY(63, 8 + dem); cout << SV[i].TEN;
			gotoXY(74, 8 + dem); cout << SV[i].PHAI;
			gotoXY(85, 8 + dem); cout << SV[i].SDT;
			gotoXY(100, 8 + dem); cout << SV[i].NAMNHAPHOC;
			dem++;
		}
		HienThiTrang(trang + 1, tongtrang, 73, 26);
		gotoXY(81, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == F1)
		{
			SuaSinhVien(listSV, DSLTC, check_change);
		}
		if (key == DELETE)
		{
			XoaSinhVien(DSLTC, listSV, check_change);
		}
		if (key == F2)
		{
			if (check_change == true)
			{
				putchar(7);	gotoXY(4, 24);  TextColor(251);	cout << "ESC"; //TÃ´ mÃ u ESC
				int temp = ThongBao_ESC();
				if (temp == -1) { continue; } //Tra ve -1 => Bat' duoc phim' ESC 1 lÃ¢n` nua~
				if (temp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					GhiFileSV(listSV); //GhiFileDK(DSLTC);
				} //Them 1 SV moi cap nhat lai 
				  // can cap nhat file diem
				if (temp == 0) { GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000); }
			}
		}
		if(key==ESC) {
			system("cls");	delete(SV); return;
		}
	}
}

//=================================================DANG KI LOP TIN CHI===================================================================

void XoaMT_MLTC(LopTinChi*& a, int& n, int pos) {
	// Mang rong, khong the xoa.
	if (n < 0 || pos >= n) {
		return;
	}
	// Dich chuyen mang
	for (int i = pos; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	// Giam so luong phan tu sau khi xoa.
	--n;
}
void XoaPhanTuLTC(int*& a, int& n, int pos) {
	// Mang rong, khong the xoa.
	if (n < 0 || pos >= n) {
		return;
	}
	// Dich chuyen mang
	for (int i = pos; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	// Giam so luong phan tu sau khi xoa.
	--n;
}
void XoaLTCDK(int*& MALOPTC, int& demMaLopTC, LopTinChi*& mhltc, int& demtam) {
	int key;
	int x = 84, y = 21;
	int vitri = 0, kiemtra = -1, kiemtra2 = -1;
	char maloptctam[11];
	Khung_Xoa_LTCDK();
	gotoXY(x, y);
	while (1)
	{
		TextColor(14);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 5))
		{
			maloptctam[vitri] = char(key);
			maloptctam[vitri] = toupper(maloptctam[vitri]);
			cout << maloptctam[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			maloptctam[vitri] = '\0';
			int mltc = atoi(maloptctam);
			for (int i = 0; i < demMaLopTC; i++) {
				if (mltc == MALOPTC[i]) kiemtra = i;
			}
			for (int i = 0; i < demtam; i++) {
				if (mltc == mhltc[i].MALOPTC) kiemtra2 = i;
			}
			if (-1 == kiemtra || kiemtra2 == -1) {
				GhiChu("LOP TIN CHI KHONG TON TAI!", 35, 27, 79, 700);
				gotoXY(84 + vitri, y);
				continue;
			}
			else {
				//xoa
				XoaPhanTuLTC(MALOPTC, demMaLopTC, kiemtra);
				XoaMT_MLTC(mhltc, demtam, kiemtra2);
				GhiChu("XOA THANH CONG LOP TIN CHI", 35, 27, 79, 1000);
				return;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(84 + vitri, y);
			cout << " ";
			gotoXY(84 + vitri, y);
		}
		if (key == ESC || key == DELETE) {
			return;
		}
	}
}
int Search_LTC_HK_NK(PTRLTC& DSLTC, int hk, char nk[]) {
	if (DSLTC == NULL)return 0;
	Search_LTC_HK_NK(DSLTC->left, hk, nk);
	if (hk == DSLTC->info.HOCKI && strcmp(nk, DSLTC->info.NIENKHOA) == 0)return 1;
	Search_LTC_HK_NK(DSLTC->right, hk, nk);
}
int nhap_MSV_HK_NK(PTRLTC DSLTC, PTR_SV listSV, SVDangKi& svdk, LopTinChi& lopTc) {
	Khung_Nhap_MSV_HK_NK();
	int x = 34, y = 2;
	int key;
	int vitri = 0;
	int temp1; //kiem tra sinh vien
	int temp2; //kiem tra nien khoa
	int temp_mh, temp_ltc; //kiem tra ma mon
	svdk.MaSV[0] = NULL;;
	PTR_SV vitrisv;
MSV:
	while (1) {
		TextColor(228); gotoXY(30, 3); cout << "                                      ";
		TextColor(14);
		gotoXY(34 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			svdk.MaSV[vitri] = char(key);
			svdk.MaSV[vitri] = toupper(svdk.MaSV[vitri]);
			cout << svdk.MaSV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(34 + vitri, y);
			cout << " ";
			gotoXY(34 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			svdk.MaSV[vitri] = '\0';	//Ngat chuoi~

			temp1 = KTSV(listSV, svdk.MaSV); // ok co ton tai hay k
			vitrisv = Search_MSV(listSV, svdk.MaSV); // lay vi tri
			if (temp1 == 1) {
				vitri = 0;
				gotoXY(49 + vitri, y);
				goto HK;
			}

			if (temp1 == 0) {
				GhiChu("           MA SINH VIEN KHONG TON TAI        ", 30, 4, 79, 500);
				/*gotoXY(34 + vitri, y);
				continue;*/
			}
		}
		if (key == RIGHT && vitri != 0)
		{
			svdk.MaSV[vitri] = '\0';	//Ngat chuoi~

			temp1 = KTSV(listSV, svdk.MaSV); // ok co ton tai hay k
			vitrisv = Search_MSV(listSV, svdk.MaSV); // lay vi tri
			if (temp1 == 1) {
				vitri = 0;
				gotoXY(49 + vitri, y);
				goto HK;
			}

			if (temp1 == 0) {
				GhiChu("           MA SINH VIEN KHONG TON TAI        ", 30, 4, 79, 500);
				/*gotoXY(34 + vitri, y);
				continue;*/
			}
		}
		if (key == ESC) { TextColor(14);	return 0; }
	}
HK:
	while (1) {
		TextColor(228); //gotoXY(30, 3); cout << "    Nhan F5 de xem Danh sach mon hoc     ";
		TextColor(14);
		gotoXY(49 + vitri, y);
		key = GetKey();
		char hocki;
		if ((key <= '9' && key >= '0') && (vitri < 1))
		{
			hocki = char(key);
			hocki = toupper(hocki);
			cout << hocki;
			lopTc.HOCKI = hocki - '0';
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(49 + vitri, y);
			cout << " ";
			gotoXY(49 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			hocki = '\0';	//Ngat chuoi~
			vitri = strlen(lopTc.NIENKHOA);
			gotoXY(60 + vitri, y);
			goto NIENKHOA;
		}
		if (key == RIGHT && vitri != 0)
		{
			hocki = '\0';	//Ngat chuoi~
		}
		if (key == LEFT) {
			hocki = '\0';
			vitri = strlen(svdk.MaSV);
			gotoXY(34 + vitri, y);
			goto MSV;
		}
		if (key == ESC) { TextColor(14);	return 0; }
	}
NIENKHOA:
	while (1) {
		TextColor(14);
		gotoXY(60 + vitri, y);
		key = GetKey();
		if ((key == '-' || (key <= '9' && key >= '0')) && (vitri < 9))
		{
			lopTc.NIENKHOA[vitri] = char(key);
			lopTc.NIENKHOA[vitri] = toupper(lopTc.NIENKHOA[vitri]);
			cout << lopTc.NIENKHOA[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(60 + vitri, y);
			cout << " ";
			gotoXY(60 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (lopTc.NIENKHOA[0] - '0') * 1000 + (lopTc.NIENKHOA[1] - '0') * 100 + (lopTc.NIENKHOA[2] - '0') * 10 + (lopTc.NIENKHOA[3] - '0');
			int b = (lopTc.NIENKHOA[5] - '0') * 1000 + (lopTc.NIENKHOA[6] - '0') * 100 + (lopTc.NIENKHOA[7] - '0') * 10 + (lopTc.NIENKHOA[8] - '0');
			if (lopTc.NIENKHOA[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
				continue;
			}
			else if (b - a != 1) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC    ", 35, 27, 79, 1000);
				continue;
			}
			else {
				lopTc.NIENKHOA[vitri] = '\0';
				temp2 = Search_LTC_HK_NK(DSLTC, lopTc.HOCKI, lopTc.NIENKHOA);
				if (temp2 == 1) {
					GhiChu("             DANG NHAP THANH CONG            ", 30, 4, 79, 700);
					system("cls");
					return 1;
				}
				else {
					GhiChu("             KHONG TON TAI LOP HOC           ", 30, 4, 79, 700);
					gotoXY(64 + vitri, y);
				}
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("         NIEN KHOA PHAI DAY DU 9 KI TU!      ", 30, 4, 79, 700);
				gotoXY(64 + vitri, y);
				continue;
			}
		}
		if (key == LEFT) {
			lopTc.NIENKHOA[vitri] = '\0';
			vitri = 1;
			gotoXY(49 + vitri, y);
			goto HK;
		}
		if (key == ESC) { TextColor(14);	return 0; }
	}
}
//====Dang ky LTC
int Search_SV_DSDK(PTRLTC& DSLTC, char masv[], int maLopTC) {
	if (EmptyDSLTC(DSLTC)) { return 0; }
	else {
		if (DSLTC->info.MALOPTC == maLopTC) {
			for (PTRDK p = DSLTC->info.DSSVDK; p != NULL; p = p->next) {
				if (strcmp(p->info.MaSV, masv) == 0&&p->info.tinhtrangDK==1)
					return 1;
			} //kiểm tra sv đa dk loptc
		}
		else if (DSLTC->info.MALOPTC > maLopTC) {
			Search_SV_DSDK(DSLTC->left, masv, maLopTC);
		}
		else {
			Search_SV_DSDK(DSLTC->right, masv, maLopTC);
		}
	}
}
void MangTam_MLTC(PTRLTC DSLTC, LopTinChi ltc[], int maLopTC, int& dem) {
	if (EmptyDSLTC(DSLTC)) { return; }

	if (DSLTC->info.MALOPTC == maLopTC) {
		ltc[dem++] = DSLTC->info;
	}
	else if (DSLTC->info.MALOPTC > maLopTC) {
		MangTam_MLTC(DSLTC->left, ltc, maLopTC, dem);
	}
	else {
		MangTam_MLTC(DSLTC->right, ltc, maLopTC, dem);
	}
}
void MangTam_SV_LTC(PTRLTC DSLTC, LopTinChi ltc[], char sv[], char nienkhoa[], int& dem) {
	if (DSLTC != NULL) {
		MangTam_SV_LTC(DSLTC->left, ltc, sv, nienkhoa, dem);
		if (strcmp(DSLTC->info.NIENKHOA, nienkhoa) == 0) {
			for (PTRDK p = DSLTC->info.DSSVDK; p != NULL; p = p->next) {
				if (strcmp(sv, p->info.MaSV) == 0&&p->info.tinhtrangDK==1) {
					ltc[dem++] = DSLTC->info;
				}
			}
		}
		MangTam_SV_LTC(DSLTC->right, ltc, sv, nienkhoa, dem);
	}
}
void MangTam_SV_LTC_HK(PTRLTC DSLTC, LopTinChi ltc[], char sv[], char nienkhoa[],int hk, int& dem) {
	if (DSLTC != NULL) {
		MangTam_SV_LTC_HK(DSLTC->left, ltc, sv, nienkhoa,hk, dem);
		if (strcmp(DSLTC->info.NIENKHOA, nienkhoa) == 0&&DSLTC->info.HOCKI==hk) {	
			for (PTRDK p = DSLTC->info.DSSVDK; p != NULL; p = p->next) {
				if (strcmp(sv, p->info.MaSV) == 0&&p->info.tinhtrangDK==1) {
					ltc[dem++] = DSLTC->info;
					break;
				}
			}
		}
		MangTam_SV_LTC_HK(DSLTC->right, ltc, sv, nienkhoa,hk, dem);
	}
}
void MangTam(PTRLTC dsLopTC, LopTinChi ltc[], int hk, char nk[], int& dem) {
	if (dsLopTC != NULL) {
		MangTam(dsLopTC->left, ltc, hk, nk, dem);
		if (hk == dsLopTC->info.HOCKI && strcmp(nk, dsLopTC->info.NIENKHOA) == 0) {
			ltc[dem++] = dsLopTC->info;
		}
		MangTam(dsLopTC->right, ltc, hk, nk, dem);
	}
}

int DemSVDK(PTRDK DSDK)
{
	int dem = 0;
	for (PTRDK p = DSDK; p != NULL; p = p->next) { dem++; }
	return dem;
}
void DANGKI_LTC(PTRLTC DSLTC, PTR_SV listSV, DS_MonHoc DSMH, bool check_change) {
	int key;
	int x = 34, y = 2;
	int dem, trang = 0, tongtrang = 0;
	int kiemtraESC;
	int solop; //dem so lop thoa man
	int vitrilop;
	SVDangKi svdk;
	LopTinChi lopTc;
	svdk.MaSV[0] = NULL; lopTc.HOCKI = 0; lopTc.NIENKHOA[0] = NULL;
	kiemtraESC = nhap_MSV_HK_NK(DSLTC, listSV, svdk, lopTc);
	if (0 == kiemtraESC) {
		return; // qua trinh dang nhap dung lai se tra ve 0l
	}
	TextColor(14);	system("cls");
	gotoXY(0, 2); cout << "MA SV    :"; gotoXY(10, 2); cout << svdk.MaSV;
	gotoXY(0, 0); cout << "HOC KI   :"; gotoXY(10, 0); cout << lopTc.HOCKI;
	gotoXY(0, 1); cout << "NIEN KHOA:"; gotoXY(10, 1); cout << lopTc.NIENKHOA;
	Khung_DKLTC();
	gotoXY(93, 4);
	char malop[11];
	int vitri = 0;
	int quyetdinh; int slconlai;
	PTRLTC nodeltc;
	LopTinChi* ltc = new LopTinChi[MAXLOPTC];
	//mang tam kiem tra trung mon hoc
	LopTinChi* mhltc = new LopTinChi[MAXLOPTC];
	//mang tam kiem tra trung mon hoc sv da dang ky
	LopTinChi* svltc = new LopTinChi[MAXLOPTC];
	int demtam = 0, demtam2 = 0;
	int demMaLopTC = 0;
	int* MALOPTC = new int[MAXLOPTC];
MALOPTC:
	while (1)
	{
		Khung_Xuat_LTCDK();
		TextColor(14);
		dem = 0;
		MangTam(DSLTC, ltc, lopTc.HOCKI, lopTc.NIENKHOA, dem);
		for (int i = 0; i < dem; i++) {
			TextColor(12); gotoXY(6, 8 + i); cout << (i + 1);
			TextColor(14);
			gotoXY(10, 8 + i); cout << ltc[i].MALOPTC;
			int vtMH = Search_MAMH(DSMH, ltc[i].MAMH, DSMH.n);
			gotoXY(18, 8 + i); cout << ltc[i].MAMH;
			gotoXY(31, 8 + i); cout << DSMH.monhoc[vtMH]->TENMH;
			gotoXY(65, 8 + i); cout << ltc[i].NHOM;
			gotoXY(73, 8 + i); cout << ltc[i].SoSVMAX - DemSVDK(ltc[i].DSSVDK);
			for (int j = 0; j < demMaLopTC; j++) {
				if (MALOPTC[j] == ltc[i].MALOPTC) {
					TextColor(225);
					gotoXY(10, 8 + i); cout << ltc[i].MALOPTC;
					int vtMH = Search_MAMH(DSMH, ltc[i].MAMH, DSMH.n);
					gotoXY(18, 8 + i); cout << ltc[i].MAMH;
					gotoXY(31, 8 + i); cout << DSMH.monhoc[vtMH]->TENMH;
					gotoXY(65, 8 + i); cout << ltc[i].NHOM;
					gotoXY(73, 8 + i); cout << ltc[i].SoSVMAX - DemSVDK(ltc[i].DSSVDK);
				}
			}
		}
		for (int i = 0; i < demMaLopTC; i++) {
			TextColor(14);
			gotoXY(82, 10 + i); cout << i + 1;
			gotoXY(98, 10 + i); cout << MALOPTC[i];
		}
		TextColor(14);
		gotoXY(93 + vitri, 3);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 10))
		{
			malop[vitri] = char(key);
			malop[vitri] = toupper(malop[vitri]);
			cout << malop[vitri];
			vitri++;
		}
		//kiem tra maloptc trong mang tam va trong dsdk
		if (key == ENTER && vitri != 0)
		{
			malop[vitri] = '\0';
			int trung = 0;
			int trungMH = 0;
			MangTam_SV_LTC(DSLTC, svltc, svdk.MaSV, lopTc.NIENKHOA, demtam2);
			trung = Search_SV_DSDK(DSLTC, svdk.MaSV, atoi(malop));
			vitrilop = -1;
			for (int i = 0; i < demMaLopTC; i++) {
				if (atoi(malop) == MALOPTC[i]) trung = 1;
			}
			for (int i = 0; i < dem; i++) {
				if (atoi(malop) == ltc[i].MALOPTC) vitrilop = 1;
			}

			if (vitrilop != -1) {
				nodeltc = Search_LTC(DSLTC, atoi(malop));
				slconlai = nodeltc->info.SoSVMAX - DemSVDK(nodeltc->info.DSSVDK);
				for (int i = 0; i < demtam; i++) {
					if (strcmp(nodeltc->info.MAMH, mhltc[i].MAMH) == 0) trungMH = 1;
				}
				for (int i = 0; i < demtam2; i++) {
					if (strcmp(nodeltc->info.MAMH, svltc[i].MAMH) == 0) trungMH = 1;
				}

			}
			if (vitrilop == -1) {
				GhiChu("MA LOP KHONG DUNG!", 93, 28, 79, 500);
				continue;
			}
			else if (trung == 1) {
				GhiChu("DA DANG KY LOP!", 93, 28, 79, 500);
				continue;
			}
			else if (slconlai <= 0) {
				GhiChu("LOP KHONG CON CHO TRONG!", 93, 28, 79, 1000);
				continue;
			}
			else if (trungMH == 1) {
				GhiChu("KHONG DUOC TRUNG MON HOC!", 93, 28, 79, 1000); continue;
			}
			else {
				quyetdinh = ThongBao_DK();
				if (-1 == quyetdinh) {
					TextColor(14);
					gotoXY(85, 22); cout << "                                 ";
					gotoXY(85, 23); cout << "                                 ";
					gotoXY(85, 24); cout << "                                 ";
					gotoXY(85, 25); cout << "                                 ";
					gotoXY(85, 26); cout << "                                 ";
					continue;
				}
				if (1 == quyetdinh) {
					TextColor(14);
					gotoXY(85, 22); cout << "                                 ";
					gotoXY(85, 23); cout << "                                 ";
					gotoXY(85, 24); cout << "                                 ";
					gotoXY(85, 25); cout << "                                 ";
					gotoXY(85, 26); cout << "                                 ";
					GhiChu("DANG KI THANH CONG", 93, 28, 79, 1000);
					MALOPTC[demMaLopTC] = atoi(malop);
					MangTam_MLTC(DSLTC, mhltc, MALOPTC[demMaLopTC], demtam);
					demMaLopTC++;
					check_change = true;
				}
				if (0 == quyetdinh) {
					TextColor(14);
					gotoXY(85, 22); cout << "                                 ";
					gotoXY(85, 23); cout << "                                 ";
					gotoXY(85, 24); cout << "                                 ";
					gotoXY(85, 25); cout << "                                 ";
					gotoXY(85, 26); cout << "                                 ";
					continue;
				}
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(93 + vitri, 3);
			cout << " ";
			gotoXY(93 + vitri, 3);
		}
		if (key == DELETE) {
			gotoXY(82, 24);	TextColor(246);	cout << "DELETE";
			XoaLTCDK(MALOPTC, demMaLopTC, mhltc, demtam);
		}
		if (key == RIGHT || key == LEFT || key == UP || key == DOWN) { continue; }
		if(key==ESC){
			delete ltc; delete mhltc; delete svltc;
			delete MALOPTC;
			system("cls");
			return;
		}
		if (key == F2)
		{
			if (check_change == true) {
				int temp = ThongBao_ESC();
				if (temp == -1) { continue; }	//Tra ve -1 => Bat' duoc phim' ESC 1 lân` nua~
				if (temp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					for (int i = 0; i < demMaLopTC; i++) {
						int kt=0;
						PTRLTC LTC = Search_LTC(DSLTC, MALOPTC[i]);
						for(PTRDK p=LTC->info.DSSVDK;p!=NULL;p=p->next){
							if(strcmp(p->info.MaSV,svdk.MaSV)==0){
								p->info.tinhtrangDK=1;
								kt=1;
							}
						}
						if(kt==0)Insert_NodeDK(LTC->info.DSSVDK, svdk);
					}
					GhiFileDK(DSLTC);
				}
				if (temp == 0) {
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				}
			}
		}
	}
}
//=====================================IN DSSVDK========================================================

PTRLTC KT_MMH_HK_NK_N(PTRLTC DSLTC, LopTinChi ltc) {
	if (DSLTC == NULL)return NULL;
	KT_MMH_HK_NK_N(DSLTC->left, ltc);
	if (strcmp(DSLTC->info.MAMH, ltc.MAMH) == 0 && DSLTC->info.HOCKI == ltc.HOCKI && strcmp(DSLTC->info.NIENKHOA, ltc.NIENKHOA) == 0 && DSLTC->info.NHOM == ltc.NHOM) {
		return DSLTC;
	}
	KT_MMH_HK_NK_N(DSLTC->right, ltc);
}

void Sort_MangSV(SinhVien a[], int n) { //Lop khong qua nhieu. Dung Selection Sort la Ok r
	SinhVien min;
	int vitrimin;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		min = a[i];
		vitrimin = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(min.MASV, a[j].MASV) > 0)
			{
				min = a[j];
				vitrimin = j;
			}
		}
		min = a[vitrimin];
		a[vitrimin] = a[i];
		a[i] = min;
	}
}
//xem ds sv dk
void XemDSDK(PTRLTC DSLTC, PTR_SV listSV, DS_MonHoc DSMH) {
	int key;
	int x = 40, y = 2;
	int vitri = 0, vitriMang, temp;
	int STT = 1;
	bool check_change = false;
	PTRLTC lopTC;
	LopTinChi ltc;
	ltc.MAMH[0] = NULL;
	ltc.NIENKHOA[0] = NULL;
	char hk[2], nhom[2];
	hk[0] = NULL, nhom[0] = NULL;
	Khung_Nhap_MMH_HK_NK_N();
	gotoXY(x, y);
MMH:
	while (1) {
		TextColor(228);
		gotoXY(30, 3); cout << "    Nhan F5 de xem Danh sach mon hoc     ";
		TextColor(14);
		gotoXY(34 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			ltc.MAMH[vitri] = char(key);
			ltc.MAMH[vitri] = toupper(ltc.MAMH[vitri]);
			cout << ltc.MAMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(34 + vitri, y);
			cout << " ";
			gotoXY(34 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ltc.MAMH[vitri] = '\0';	//Ngat chuoi~
			temp = Search_MH_LTC(DSLTC, ltc.MAMH);
			if (temp == 1) {
				vitri = strlen(hk);
				gotoXY(49 + vitri, y);
				goto HK;
			}
			else{
				GhiChu("           MA MON HOC KHONG TON TAI        ", 30, 4, 79, 500);
				/*gotoXY(34 + vitri, y);
				continue;*/
			}
		}
		if (key == RIGHT && vitri != 0)
		{
			ltc.MAMH[vitri] = '\0';	//Ngat chuoi~
			temp = Search_MH_LTC(DSLTC, ltc.MAMH); // ok co ton tai hay k
			if (temp == 1) {
				vitri = strlen(hk);
				gotoXY(49 + vitri, y);
				goto HK;
			}
			else{
				GhiChu("           MA MON HOC KHONG TON TAI        ", 30, 4, 79, 500);
				/*gotoXY(34 + vitri, y);
				continue;*/
			}
		}
		if (key == F5)
		{
			ltc.MAMH[vitri] = '\0';
			xemMonHoc(DSLTC, DSMH, 1);
			Khung_Nhap_MMH_HK_NK_N();
			TextColor(223); gotoXY(18, 24); cout << "           NHAN F5 DE BAT CHUC NANG DI CHUYEN        ";
			TextColor(14);	gotoXY(40, y); cout << ltc.MAMH[vitri];
		}
		if (key == ESC) { TextColor(14);	return; }
	}
HK:
	while (1) {
		TextColor(228); //gotoXY(30, 3); cout << "    Nhan F5 de xem Danh sach mon hoc     ";
		TextColor(14);
		gotoXY(49 + vitri, y);
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 1))
		{
			hk[vitri] = char(key);
			hk[vitri] = toupper(hk[vitri]);
			cout << hk[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(49 + vitri, y);
			cout << " ";
			gotoXY(49 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			hk[vitri] = '\0';	//Ngat chuoi~
			ltc.HOCKI = atoi(hk);
			vitri = strlen(ltc.NIENKHOA);
			gotoXY(60 + vitri, y);
			goto NIENKHOA;
		}
		if (key == RIGHT && vitri != 0)
		{
			hk[vitri] = '\0';	//Ngat chuoi~
			ltc.HOCKI = atoi(hk);
			vitri = strlen(ltc.NIENKHOA);
			gotoXY(60 + vitri, y);
			goto NIENKHOA;
		}
		if (key == LEFT) {
			hk[vitri] = '\0';
			ltc.HOCKI = atoi(hk);
			vitri = strlen(ltc.MAMH);
			gotoXY(34 + vitri, y);
			goto MMH;
		}
		if (key == ESC) { TextColor(14);	return; }
	}
NIENKHOA:
	while (1) {
		TextColor(14);
		gotoXY(60 + vitri, y);
		key = GetKey();
		if ((key == '-' || (key <= '9' && key >= '0')) && (vitri < 9))
		{
			ltc.NIENKHOA[vitri] = char(key);
			ltc.NIENKHOA[vitri] = toupper(ltc.NIENKHOA[vitri]);
			cout << ltc.NIENKHOA[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(60 + vitri, y);
			cout << " ";
			gotoXY(60 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (ltc.NIENKHOA[0] - '0') * 1000 + (ltc.NIENKHOA[1] - '0') * 100 + (ltc.NIENKHOA[2] - '0') * 10 + (ltc.NIENKHOA[3] - '0');
			int b = (ltc.NIENKHOA[5] - '0') * 1000 + (ltc.NIENKHOA[6] - '0') * 100 + (ltc.NIENKHOA[7] - '0') * 10 + (ltc.NIENKHOA[8] - '0');
			if (ltc.NIENKHOA[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
				continue;
			}
			else if (b - a != 1 ) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC     ", 35, 27, 79, 1000);
				continue;
			}
			else {
				ltc.NIENKHOA[vitri] = '\0';
				vitri = strlen(nhom);
				gotoXY(60 + vitri, y);
				goto NHOM;
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("         NIEN KHOA PHAI DAY DU 9 KI TU!      ", 30, 4, 79, 700);
				gotoXY(64 + vitri, y);
				continue;
			}
		}
		if (key == LEFT) {
			ltc.NIENKHOA[vitri] = '\0';
			vitri = strlen(hk);
			gotoXY(49 + vitri, y);
			goto HK;
		}
		if (key == RIGHT && vitri != 0)
		{
			hk[vitri] = '\0';	//Ngat chuoi~
			vitri = strlen(nhom);
			gotoXY(80 + vitri, y);
			goto NHOM;
		}
		if (key == ESC) { TextColor(14);	return; }
	}
NHOM:
	while (1) {
		TextColor(228); 
		TextColor(14);
		gotoXY(80 + vitri, y);
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 1))
		{
			nhom[vitri] = char(key);
			nhom[vitri] = toupper(nhom[vitri]);
			cout << nhom[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(80 + vitri, y);
			cout << " ";
			gotoXY(80 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			nhom[vitri] = '\0';	//Ngat chuoi~
			ltc.NHOM = atoi(nhom);
			lopTC = KT_MMH_HK_NK_N(DSLTC, ltc);
			if (lopTC == NULL) {
				GhiChu("         LOP TIN CHI NAY KHONG TON TAI     ", 35, 27, 79, 1000);
				vitri = strlen(ltc.MAMH);
				gotoXY(34 + vitri, y);
				goto MMH;
			}
			else {
				GhiChu("         DANG NHAP THANH CONG     ", 35, 27, 79, 1000);
				break;
			}
		}
		if (key == LEFT) {
			nhom[vitri] = '\0';
			ltc.NHOM = atoi(nhom);
			vitri = strlen(ltc.NIENKHOA);
			gotoXY(60 + vitri, y);
			goto NIENKHOA;
		}
		if (key == ESC) { TextColor(14);	return; }
	}
	int trang = 0, tongtrang = 0, soluongsv = 0;
	int dem1 = 0, dem = 0;	//dem la dem dong`.  dem1 la vitri phan tu sv
	dem1 = 0;
	soluongsv = DemSVDK(lopTC->info.DSSVDK);
	if (soluongsv == 0)
	{
		GhiChu("Chua co du lieu sinh vien", 35, 27, 79, 500);
	}
	else {
		if (soluongsv < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongsv - 1) / 15 + 1);
		}
	}
	int ktrasv;
	PTR_SV svdk;
	SinhVien* SV = new SinhVien[soluongsv + 1];
	for (PTRDK p = lopTC->info.DSSVDK; p != NULL; p = p->next) {
		svdk = Search_MSV(listSV, p->info.MaSV);
		SV[dem1] = svdk->info;
		dem1++;
	}
	Sort_MangSV(SV, dem1);
	while (1)
	{
		TextColor(14);	system("cls");
		Khung_Xuat_SV();
		dem = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongsv; i++)
		{
			TextColor(12); gotoXY(6, 8 + dem); cout << i + 1;
			TextColor(14);
			gotoXY(10, 8 + dem); cout << SV[i].MALOP;
			gotoXY(28, 8 + dem); cout << SV[i].MASV;
			gotoXY(44, 8 + dem); cout << SV[i].HO;
			gotoXY(63, 8 + dem); cout << SV[i].TEN;
			gotoXY(74, 8 + dem); cout << SV[i].PHAI;
			gotoXY(85, 8 + dem); cout << SV[i].SDT;
			gotoXY(100, 8 + dem); cout << SV[i].NAMNHAPHOC;
			dem++;
		}
		TextColor(7);
		gotoXY(1, 0); cout << "MA lOP:";
		gotoXY(1, 1); cout << "MON HOC:";
		gotoXY(1, 2); cout << "NIEN KHOA:";
		gotoXY(1, 3); cout << "HOC KI:";
		gotoXY(1, 4); cout << "NHOM:";
		TextColor(7);
		gotoXY(12, 0); cout << lopTC->info.MALOPTC;
		gotoXY(12, 1); cout << lopTC->info.MAMH;
		gotoXY(12, 2); cout << lopTC->info.NIENKHOA;
		gotoXY(12, 3); cout << lopTC->info.HOCKI;
		gotoXY(12, 4); cout << lopTC->info.NHOM;
		HienThiTrang(trang + 1, tongtrang, 73, 26);
		gotoXY(81, 26);
		key = GetKey();
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if (key == ESC)
		{
			system("cls");	delete(SV); return;
		}
	}
}
PTRDK KT_DIEM(PTRLTC DSLTC, SVDangKi svdk,int malop){
	if(DSLTC==NULL)return NULL;
	KT_DIEM(DSLTC->left,svdk,malop);
	if(DSLTC->info.MALOPTC==malop){
		for(PTRDK p=DSLTC->info.DSSVDK;p!=NULL;p=p->next){
			if(strcmp(p->info.MaSV,svdk.MaSV)==0&&strcmp(p->info.DIEM,"0")==0){
				return p;
			}
		}	
	}
	KT_DIEM(DSLTC->right,svdk,malop);
}
void HuyDSDK(PTRLTC DSLTC, PTR_SV listSV, DS_MonHoc DSMH) {
	int key;
	int x = 34, y = 2;
	int dem, trang = 0, tongtrang = 0;
	int kiemtraESC;
	bool check_change=false;
	int solop; //dem so lop thoa man
	int vitrilop;
	SVDangKi svdk;
	LopTinChi lopTc;
	svdk.MaSV[0] = NULL; lopTc.HOCKI = 0; lopTc.NIENKHOA[0] = NULL;
	kiemtraESC = nhap_MSV_HK_NK(DSLTC, listSV, svdk, lopTc);
	if (0 == kiemtraESC) {
		return; // qua trinh dang nhap dung lai se tra ve 0l
	}
	TextColor(14);	system("cls");
	gotoXY(0, 2); cout << "MA SV    :"; gotoXY(10, 2); cout << svdk.MaSV;
	gotoXY(0, 0); cout << "HOC KI   :"; gotoXY(10, 0); cout << lopTc.HOCKI;
	gotoXY(0, 1); cout << "NIEN KHOA:"; gotoXY(10, 1); cout << lopTc.NIENKHOA;
	Khung_HLTC();
	gotoXY(93, 4);
	char malop[11];
	int vitri = 0;
	int quyetdinh;
	PTRLTC nodeltc;
	LopTinChi* ltc = new LopTinChi[MAXLOPTC];
		for (int i = 0; i < MAXLOPTC; i++) {
		ltc[i].MALOPTC = 0; ltc[i].MAMH[0] = NULL; 
	}
	int demtam = 0, demtam2 = 0;
	int demMaLopTC = 0;
	dem = 0;
	MangTam_SV_LTC_HK(DSLTC,ltc,svdk.MaSV,lopTc.NIENKHOA,lopTc.HOCKI, dem);
	MALOPTC:
	while (1)
	{
		Khung_Huy_LTCDK();
		TextColor(14);
		for (int i = 0; i < dem; i++) {
			TextColor(12); gotoXY(6, 8 + i); cout << (i + 1);
			TextColor(14);
			gotoXY(10, 8 + i); cout << ltc[i].MALOPTC;
			int vtMH = Search_MAMH(DSMH, ltc[i].MAMH, DSMH.n);
			gotoXY(18, 8 + i); cout << ltc[i].MAMH;
			gotoXY(31, 8 + i); cout << DSMH.monhoc[vtMH]->TENMH;
			gotoXY(65, 8 + i); cout << ltc[i].NHOM;
		}
		TextColor(14);
		gotoXY(10, 8 + dem); cout <<"     ";
		gotoXY(18, 8 + dem); cout <<"       ";
		gotoXY(31, 8 + dem); cout <<"           ";
		TextColor(14);
		gotoXY(93 + vitri, 8);
		key = GetKey();
		if ((key >= '0' && key <= '9') && (vitri < 10))
		{
			malop[vitri] = char(key);
			malop[vitri] = toupper(malop[vitri]);
			cout << malop[vitri];
			vitri++;
		}
		//kiem tra maloptc trong mang tam va trong dsdk
		if (key == ENTER && vitri != 0)
		{
			malop[vitri] = '\0';
			int trung = 0;
			vitrilop = -1;
			PTRDK SV_CheckDiem=KT_DIEM(DSLTC,svdk,atoi(malop));
			for (int i = 0; i < dem; i++) {
				if (atoi(malop) == ltc[i].MALOPTC) vitrilop = 1;
			}
			if (vitrilop == -1) {
				GhiChu("MA LOP KHONG DUNG!", 93, 28, 79, 500);
				continue;
			}
			else if(SV_CheckDiem==NULL){
				GhiChu("SINH VIEN DA CO DIEM!", 93, 28, 79, 500);
				continue;
			}
			else {
				quyetdinh = ThongBao_DK();
				if (-1 == quyetdinh) {
					TextColor(14);
					gotoXY(85, 22); cout << "                                 ";
					gotoXY(85, 23); cout << "                                 ";
					gotoXY(85, 24); cout << "                                 ";
					gotoXY(85, 25); cout << "                                 ";
					gotoXY(85, 26); cout << "                                 ";
					continue;
				}
				if (1 == quyetdinh) {
					TextColor(14);
					gotoXY(85, 22); cout << "                                 ";
					gotoXY(85, 23); cout << "                                 ";
					gotoXY(85, 24); cout << "                                 ";
					gotoXY(85, 25); cout << "                                 ";
					gotoXY(85, 26); cout << "                                 ";
					GhiChu("XOA THANH CONG", 93, 28, 79, 1000);
					int index;
					for (int i = 0; i < dem; i++) {
						if (atoi(malop) == ltc[i].MALOPTC) index = i;
					}
					XoaMT_MLTC(ltc,dem,index);
					SV_CheckDiem->info.tinhtrangDK=0;
					check_change = true;
				}
				if (0 == quyetdinh) {
					TextColor(14);
					gotoXY(85, 22); cout << "                                 ";
					gotoXY(85, 23); cout << "                                 ";
					gotoXY(85, 24); cout << "                                 ";
					gotoXY(85, 25); cout << "                                 ";
					gotoXY(85, 26); cout << "                                 ";
					continue;
				}
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(93 + vitri, 8);
			cout << " ";
			gotoXY(93 + vitri, 8);
		}
		if (key == RIGHT || key == LEFT || key == UP || key == DOWN) { continue; }
		if(key==ESC){
			delete ltc;
			system("cls");
			return;
		}
		if (key == F2)
		{
			if (check_change == true) {
				int temp = ThongBao_ESC();
				if (temp == -1) { continue; }	//Tra ve -1 => Bat' duoc phim' ESC 1 lân` nua~
				if (temp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					GhiFileDK(DSLTC);
					delete ltc; 
					
				}
				if (temp == 0) {
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
					delete ltc; 
					
				}
			}
			system("cls");
			return;
		}
	}
}
//============================================NHAP XEM DIEM====================================
void nhap_xem_DIEM(PTRLTC& DSLTC, PTR_SV listSV, DS_MonHoc DSMH, int chedoxem)
{
	int key;
	int x = 40, y = 2;
	int vitri = 0, vitriMang, temp;
	int STT = 1;
	bool check_change = false;
	PTRLTC lopTC;
	LopTinChi ltc;
	ltc.MAMH[0] = NULL;
	ltc.NIENKHOA[0] = NULL;
	char hk[2], nhom[2];
	hk[0] = NULL, nhom[0] = NULL;
	Khung_Nhap_MMH_HK_NK_N();
	gotoXY(x, y);
MMH:
	while (1) {
		TextColor(228);
		gotoXY(30, 3); cout << "    Nhan F5 de xem Danh sach mon hoc     ";
		TextColor(14);
		gotoXY(34 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 10))
		{
			ltc.MAMH[vitri] = char(key);
			ltc.MAMH[vitri] = toupper(ltc.MAMH[vitri]);
			cout << ltc.MAMH[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(34 + vitri, y);
			cout << " ";
			gotoXY(34 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ltc.MAMH[vitri] = '\0';	//Ngat chuoi~
			temp = Search_MH_LTC(DSLTC, ltc.MAMH);
			if (temp == 1) {
				vitri = strlen(hk);
				gotoXY(49 + vitri, y);
				goto HK;
			}
			else {
				GhiChu("           MA MON HOC KHONG TON TAI        ", 30, 4, 79, 500);
				/*gotoXY(34 + vitri, y);
				continue;*/
			}
		}
		if (key == RIGHT && vitri != 0)
		{
			ltc.MAMH[vitri] = '\0';	//Ngat chuoi~
			temp = Search_MH_LTC(DSLTC, ltc.MAMH); // ok co ton tai hay k
			if (temp == 1) {
				vitri = strlen(hk);
				gotoXY(49 + vitri, y);
				goto HK;
			}
			else {
				GhiChu("           MA MON HOC KHONG TON TAI        ", 30, 4, 79, 500);
				/*gotoXY(34 + vitri, y);
				continue;*/
			}
		}
		if (key == F5)
		{
			ltc.MAMH[vitri] = '\0';
			xemMonHoc(DSLTC, DSMH, 1);
			Khung_Nhap_MMH_HK_NK_N();
			TextColor(223); gotoXY(18, 24); cout << "           NHAN F5 DE BAT CHUC NANG DI CHUYEN        ";
			TextColor(14);	gotoXY(40, y); cout << ltc.MAMH[vitri];
		}
		if (key == ESC) { TextColor(14);	return; }
	}
HK:
	while (1) {
		TextColor(228); //gotoXY(30, 3); cout << "    Nhan F5 de xem Danh sach mon hoc     ";
		TextColor(14);
		gotoXY(49 + vitri, y);
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 1))
		{
			hk[vitri] = char(key);
			hk[vitri] = toupper(hk[vitri]);
			cout << hk[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(49 + vitri, y);
			cout << " ";
			gotoXY(49 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			hk[vitri] = '\0';	//Ngat chuoi~
			ltc.HOCKI = atoi(hk);
			vitri = strlen(ltc.NIENKHOA);
			gotoXY(60 + vitri, y);
			goto NIENKHOA;
		}
		if (key == RIGHT && vitri != 0)
		{
			hk[vitri] = '\0';	//Ngat chuoi~
			ltc.HOCKI = atoi(hk);
			vitri = strlen(ltc.NIENKHOA);
			gotoXY(60 + vitri, y);
			goto NIENKHOA;
		}
		if (key == LEFT) {
			hk[vitri] = '\0';
			ltc.HOCKI = atoi(hk);
			vitri = strlen(ltc.MAMH);
			gotoXY(34 + vitri, y);
			goto MMH;
		}
		if (key == ESC) { TextColor(14);	return; }
	}
NIENKHOA:
	while (1) {
		TextColor(14);
		gotoXY(60 + vitri, y);
		key = GetKey();
		if ((key == '-' || (key <= '9' && key >= '0')) && (vitri < 9))
		{
			ltc.NIENKHOA[vitri] = char(key);
			ltc.NIENKHOA[vitri] = toupper(ltc.NIENKHOA[vitri]);
			cout << ltc.NIENKHOA[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(60 + vitri, y);
			cout << " ";
			gotoXY(60 + vitri, y);
		}
		if (key == ENTER && vitri == 9) {
			int a = (ltc.NIENKHOA[0] - '0') * 1000 + (ltc.NIENKHOA[1] - '0') * 100 + (ltc.NIENKHOA[2] - '0') * 10 + (ltc.NIENKHOA[3] - '0');
			int b = (ltc.NIENKHOA[5] - '0') * 1000 + (ltc.NIENKHOA[6] - '0') * 100 + (ltc.NIENKHOA[7] - '0') * 10 + (ltc.NIENKHOA[8] - '0');
			if (ltc.NIENKHOA[4] != '-') {
				GhiChu("         SAI DINH DANG !VD: 2019-2020!     ", 35, 27, 79, 1000);
				continue;
			}
			else if (b - a != 1) {
				GhiChu("         NAM SAU PHAI LON HON NAM TRUOC    ", 35, 27, 79, 1000);
				continue;
			}
			else {
				ltc.NIENKHOA[vitri] = '\0';
				vitri = strlen(nhom);
				gotoXY(60 + vitri, y);
				goto NHOM;
			}
		}
		else {
			if (key == ENTER && vitri != 9) {
				GhiChu("         NIEN KHOA PHAI DAY DU 9 KI TU!      ", 30, 4, 79, 700);
				gotoXY(64 + vitri, y);
				continue;
			}
		}
		if (key == LEFT) {
			ltc.NIENKHOA[vitri] = '\0';
			vitri = strlen(hk);
			gotoXY(49 + vitri, y);
			goto HK;
		}
		if (key == RIGHT && vitri != 0)
		{
			hk[vitri] = '\0';	//Ngat chuoi~
			vitri = strlen(nhom);
			gotoXY(80 + vitri, y);
			goto NHOM;
		}
		if (key == ESC) { TextColor(14);	return; }
	}
NHOM:
	while (1) {
		TextColor(228);
		TextColor(14);
		gotoXY(80 + vitri, y);
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 1))
		{
			nhom[vitri] = char(key);
			nhom[vitri] = toupper(nhom[vitri]);
			cout << nhom[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(80 + vitri, y);
			cout << " ";
			gotoXY(80 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			nhom[vitri] = '\0';	//Ngat chuoi~
			ltc.NHOM = atoi(nhom);
			lopTC = KT_MMH_HK_NK_N(DSLTC, ltc);
			if (lopTC == NULL) {
				GhiChu("         LOP TIN CHI NAY KHONG TON TAI     ", 35, 27, 79, 1000);
				vitri = strlen(ltc.MAMH);
				gotoXY(34 + vitri, y);
				goto MMH;
			}
			else {
				GhiChu("         DANG NHAP THANH CONG     ", 35, 27, 79, 1000);
				break;
			}
		}
		if (key == LEFT) {
			nhom[vitri] = '\0';
			ltc.NHOM = atoi(nhom);
			vitri = strlen(ltc.NIENKHOA);
			gotoXY(60 + vitri, y);
			goto NIENKHOA;
		}
		if (key == ESC) { TextColor(14);	return; }
	}
	int soluongsv;
	int dem1 = 0, dem2 = 0, dem = 0;	//dem la dem dong`.  dem1 la vitri phan tu sv
	dem1 = 0;
	soluongsv = DemSVDK(lopTC->info.DSSVDK);
	if (soluongsv == 0)
	{
		GhiChu("Chua co du lieu sinh vien", 35, 27, 79, 500);
	}
	int ktrasv;
	PTR_SV svdk;
	SinhVien* SV = new SinhVien[soluongsv + 1];
	SVDangKi* SVDK = new SVDangKi[soluongsv + 1];
	for (PTRDK p = lopTC->info.DSSVDK; p != NULL; p = p->next) {
		if(p->info.tinhtrangDK==1){
			svdk = Search_MSV(listSV, p->info.MaSV);
			SV[dem1] = svdk->info;
			dem1++;
		}
	}
	Sort_MangSV(SV, dem1);
	//dua du lieu diem vao danh sach sinh vien
	for (int i = 0; i < dem1; i++) {
		for (PTRDK p = lopTC->info.DSSVDK; p != NULL; p = p->next) {
			if (strcmp(p->info.MaSV, SV[i].MASV) == 0) {
				SVDK[i] = p->info;
			}
		}
	}
	vitri = strlen(SVDK[0].DIEM);
	y = 8;
Reset:
	TextColor(14);	system("cls");
	if (chedoxem != 1) {
		
		Khung_Nhap_Diem(dem1);
		dem = 0;
		for (int i = 0; i < dem1; i++)
		{
			TextColor(12); gotoXY(6, 8 + dem); cout << i + 1;
			TextColor(14);
			gotoXY(10, 8 + dem); cout << SV[i].MASV;
			gotoXY(26, 8 + dem); cout << SV[i].HO;
			gotoXY(57, 8 + dem); cout << SV[i].TEN;
			gotoXY(71, 8 + dem); cout << SVDK[i].DIEM;
			dem++;
		}
		TextColor(7);
		gotoXY(1, 0); cout << "MA lOP:";
		gotoXY(1, 1); cout << "MON HOC:";
		gotoXY(1, 2); cout << "NIEN KHOA:";
		gotoXY(1, 3); cout << "HOC KI:";
		gotoXY(1, 4); cout << "NHOM:";
		TextColor(7);
		gotoXY(12, 0); cout << lopTC->info.MALOPTC;
		gotoXY(12, 1); cout << lopTC->info.MAMH;
		gotoXY(12, 2); cout << lopTC->info.NIENKHOA;
		gotoXY(12, 3); cout << lopTC->info.HOCKI;
		gotoXY(12, 4); cout << lopTC->info.NHOM;
		while (1)
		{
			TextColor(252);				//Chu thich
			gotoXY(80, 30); cout << " DIEM SINH VIEN: Nhap tu 0 den 10. ";
			TextColor(14);
			gotoXY(71 + vitri, y);
			key = GetKey();
			if (((key <= '9' && key >= '0') || key == '.') && (vitri < 3))
			{
				SVDK[dem2].DIEM[vitri] = char(key);
				SVDK[dem2].DIEM[vitri] = toupper(SVDK[dem2].DIEM[vitri]);
				cout << SVDK[dem2].DIEM[vitri];
				vitri++;
			}
			if (key == ENTER && dem2 < dem1)
			{
				SVDK[dem2].DIEM[vitri] = '\0';
				
				if (atof(SVDK[dem2].DIEM) > 10 || SVDK[dem2].DIEM[0] == '.' || SVDK[dem2].DIEM[2] == '.')
				{
					GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""", 20, 27, 74, 500);	continue;
				}
				if (vitri > 0) { check_change = true; GhiChu("Save Thanh Cong!", 35, 27, 79, 300); TextColor(14); }
				dem2++;
				vitri = strlen(SVDK[dem2].DIEM);
				if (dem2 % 15 == 0)
				{
					y = 8;
					goto Reset;
				}
				if (dem2 == dem1) {
					continue;
				}
				gotoXY(71 + vitri, ++y);
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(71 + vitri, y);
				cout << " ";
				gotoXY(71 + vitri, y);
			}
			if (key == UP && y > 8)
			{
				SVDK[dem2].DIEM[vitri] = '\0';
				if ( atof(SVDK[dem2].DIEM) > 10 || SVDK[dem2].DIEM[0] == '.' || SVDK[dem2].DIEM[2] == '.')
				{
					GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""", 20, 27, 79, 500);	continue;
				}
				dem2--;
				vitri = strlen(SVDK[dem2].DIEM);
				gotoXY(71 + vitri, --y);
			}
			if (key == DOWN && y < 22 && dem2 < dem1 - 1)
			{
				SVDK[dem2].DIEM[vitri] = '\0';
				
				if (atof(SVDK[dem2].DIEM) > 10 || SVDK[dem2].DIEM[0] == '.' || SVDK[dem2].DIEM[2] == '.')
				{
					GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""", 20, 27, 79, 500);	continue;
				}
				dem2++;
				vitri = strlen(SVDK[dem2].DIEM);
				gotoXY(71 + vitri, ++y);
			}
			if (key == F2)
			{
				SVDK[dem2].DIEM[vitri] = '\0';
				int i = 0;
				int checkqd = 0;
				if (check_change == true) {
					checkqd = ThongBao_ESC();
				}
				if (checkqd == -1)	//TH bat duoc them 1 phim' ESC
				{
					gotoXY(4, 24);  TextColor(252);	cout << "ESC";
					TextColor(14); //TÃ´ mÃ u ESC
					goto Reset;
				}
				if (checkqd == 1)
				{
					//dua diem vao dssvdk cua ltc
					for (PTRDK p = lopTC->info.DSSVDK; p != NULL; p = p->next) {
						for (int i = 0; i < dem1; i++) {
							if (strcmp(p->info.MaSV, SVDK[i].MaSV) == 0) {
								strcpy(p->info.DIEM,SVDK[i].DIEM);
							}
						}
					}
					GhiChu("Luu Vao File Thanh Cong!", 30, 27, 79, 2000);
					GhiFileDK(DSLTC); GhiFileLTC(DSLTC);
					goto Reset;
				}
				if (checkqd == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!", 30, 27, 79, 2000);
					goto Reset;
				}
			}
			if (key == ESC)
			{
				system("cls");	delete(SV); delete(SVDK); return;
			}
		}
	}
	else {
		while (1) {
			TextColor(14);	system("cls");
			int vtmh= Search_MAMH(DSMH, lopTC->info.MAMH, DSMH.n);
			Khung_Xuat_Diem(dem1);
			TextColor(236);
			gotoXY(44, 2); cout << DSMH.monhoc[vtmh]->TENMH;
			dem = 0;
			for (int i = 0; i < dem1; i++)
			{
				TextColor(12); gotoXY(6, 8 + dem); cout << i + 1;
				TextColor(14);
				gotoXY(10, 8 + dem); cout << SV[i].MASV;
				gotoXY(26, 8 + dem); cout << SV[i].HO;
				gotoXY(57, 8 + dem); cout << SV[i].TEN;
				gotoXY(71, 8 + dem); cout << SVDK[i].DIEM;
				dem++;
			}
			TextColor(7);
			gotoXY(1, 0); cout << "MA lOP:";
			gotoXY(1, 1); cout << "MON HOC:";
			gotoXY(1, 2); cout << "NIEN KHOA:";
			gotoXY(1, 3); cout << "HOC KI:";
			gotoXY(1, 4); cout << "NHOM:";
			TextColor(7);
			gotoXY(12, 0); cout << lopTC->info.MALOPTC;
			gotoXY(12, 1); cout << lopTC->info.MAMH;
			gotoXY(12, 2); cout << lopTC->info.NIENKHOA;
			gotoXY(12, 3); cout << lopTC->info.HOCKI;
			gotoXY(12, 4); cout << lopTC->info.NHOM;
			key = GetKey();
			if (key == ESC)
			{
				system("cls");	delete(SV); delete(SVDK); return;
			}
		}
	}
}
//============================XEM DIEM TRUNG BINH=================================
//tinh so tc cua mon hoc theo ma mon hoc
float tinhSoTCMH(DS_MonHoc dsMH, char mmh[]) {
	float stc = 0;
	for (int i = 0; i < dsMH.n; i++) {
		if (strcmp(dsMH.monhoc[i]->MAMH, mmh) == 0) {
			stc += (dsMH.monhoc[i]->STCLT + dsMH.monhoc[i]->STCTH);
		}
	}
	return stc;
}

//tinh so tc cua 1 lop
void tinhSoTCLOP(PTRLTC DSLTC, SinhVien* SV,int soluongsv, DS_MonHoc dsMH, float& soTC) {
	if (DSLTC == NULL)return;
	tinhSoTCLOP(DSLTC->left, SV,soluongsv, dsMH, soTC);
	for(int i=0;i<soluongsv;i++){
		for (PTRDK p = DSLTC->info.DSSVDK; p != NULL; p = p->next) {
			if (strcmp(SV[i].MASV, p->info.MaSV) == 0) {
				soTC += tinhSoTCMH(dsMH, DSLTC->info.MAMH);
				goto END;
			}
		}
	}
END:
	tinhSoTCLOP(DSLTC->right, SV,soluongsv, dsMH, soTC);
}
//tinh tong diem tat ca cac mon cua sinh vien
void tinhDiemSV(PTRLTC DSLTC, SinhVien SV, DS_MonHoc dsMH, float& diem) {
	if (DSLTC == NULL)return;
	tinhDiemSV(DSLTC->left, SV, dsMH, diem);
	for (PTRDK p = DSLTC->info.DSSVDK; p != NULL; p = p->next) {
		if (strcmp(SV.MASV, p->info.MaSV) == 0) {
			float soTC = tinhSoTCMH(dsMH, DSLTC->info.MAMH);
			diem += (atof(p->info.DIEM)* soTC);
		}
	}
	tinhDiemSV(DSLTC->right, SV, dsMH, diem);
}
void xemDiemTB(PTRLTC DSLTC, PTR_SV listSV, DS_MonHoc dsMH) {
	int key;
	int x = 40, y = 2;
	int vitri = 0, vitriMang;
	int STT = 1;
	bool check_change = false;
	char malop[12];
	system("cls");
	Khung_Nhap_MaLop();
	gotoXY(x, y);
	PTR_SV temp=NULL;
	while (1)
	{
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z') || (key == '-')) && (vitri < 11))
		{
			malop[vitri] = char(key);
			malop[vitri] = toupper(malop[vitri]);
			cout << malop[vitri];
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			malop[vitri] = '\0';
			temp = KTMaLop(listSV, malop); //KT trung ma lop
			if (temp != NULL)
			{
				break;
			}
			else {
				GhiChu("     Ma Lop Khong Ton Tai!    ", 33, 5, 159, 500);
				gotoXY(40 + vitri, y);
				TextColor(14);
				continue;
			}
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40 + vitri, y);
			cout << " ";
			gotoXY(40 + vitri, y);
		}
		if (key == ESC) { TextColor(14); return; }
	}
	int soluongsv;
	int dem1 = 0, dem2 = 0, dem = 0;	//dem la dem dong`.  dem1 la vitri phan tu sv
	dem1 = 0;
	soluongsv = DemSinhVien(listSV, malop);
	if (soluongsv == 0)
	{
		GhiChu("Chua co du lieu sinh vien", 35, 27, 79, 500);
	}
	int ktrasv;
	SinhVien* SV = new SinhVien[soluongsv + 1];
	SVDangKi* SVDK = new SVDangKi[soluongsv + 1];
	char diem[4];
	diem[0] = NULL;
	for (PTR_SV p = listSV; p != NULL; p = p->next) {
		if (strcmp(p->info.MALOP, malop) == 0) {
			SV[dem1] = p->info;
			dem1++;
		}
	}
	Sort_MangSV(SV, dem1);
	float soTCLOP;
	tinhSoTCLOP(DSLTC,SV,soluongsv,dsMH,soTCLOP);
	if (soTCLOP == 0) soTCLOP = 1;
	//dua du lieu diem vao danh sach sinh vien
	y = 8;
Reset:
	while (1) {
		TextColor(14);	system("cls");
		Khung_Xuat_Diem(dem1);
		TextColor(236);	gotoXY(25, 1);	cout << "                                  ";
		gotoXY(25, 2);	cout << "  BANG THONG KE DIEM TB KHOA HOC  ";
		gotoXY(25, 3);	cout << "                                  ";
		dem = 0;
		for (int i = 0; i < dem1; i++)
		{
			TextColor(12); gotoXY(6, 8 + dem); cout << i + 1;
			TextColor(14);
			gotoXY(10, 8 + dem); cout << SV[i].MASV;
			gotoXY(26, 8 + dem); cout << SV[i].HO;
			gotoXY(57, 8 + dem); cout << SV[i].TEN;
			float diemsv = 0;
			tinhDiemSV(DSLTC, SV[i], dsMH, diemsv);
			gotoXY(71, 8 + dem);
			if(diemsv / soTCLOP!=0)printf("%0.1f",diemsv / soTCLOP);
			else cout<<diemsv / soTCLOP;
			dem++;
		}
		TextColor(7);
		gotoXY(1, 0); cout << "MA lOP:";
		gotoXY(1, 1); cout << "NAM NHAP HOC:";
		TextColor(7);
		gotoXY(15, 0); cout << malop;
		gotoXY(15, 1); cout << SV[0].NAMNHAPHOC;
		key = GetKey();
		if (key == ESC)
		{
			system("cls");	delete(SV); delete(SVDK); return;
		}
	}
}

//===========================GIAI PHONG BO NHO===========================
void GiaiPhong_LTC(PTRLTC& DSLTC)
{
	if (DSLTC != NULL)
	{
		GiaiPhong_LTC(DSLTC->left);
		GiaiPhong_LTC(DSLTC->right);
		delete DSLTC;
		DSLTC = NULL;
	}
}
void GiaiPhong(PTRLTC& DSLTC, DS_MonHoc& DSMH, PTR_SV listSV, int* MALTC)
{
	for (PTR_SV p = listSV; p != NULL; p->next) {
		delete p;
		p = NULL;
	}
	for (int i = 0; i < DSMH.n; i++)//Giai phong bo nho lop tin chi
	{
		delete DSMH.monhoc[i];
	}
	//giai phog mang LTC
	delete MALTC;
	GiaiPhong_LTC(DSLTC); //Giai phong bo nho Cay Nhi Phan
}
void MenuKT(PTRLTC& DSLTC,PTR_SV &listSV, DS_MonHoc& DSMH, int* MALTC,int & n)
{
	int chonMenuCon;
	while (1)
	{
		system("cls");
		for (int i = 0; i < 6; i++)
		{
			if (i == 0) { TextColor(228); }
			else { TextColor(240); }
			gotoXY(0, 5 + i * 4); cout << "                        ";
			gotoXY(0, 6 + i * 4); cout << MENU[i];
			gotoXY(0, 7 + i * 4); cout << "                        ";
		}
		gotoXY(24, 7);
		int chon = MenuCha();
		switch (chon)
		{
		case 1:
		{
			for (int i = 0; i < 4; i++)
			{
				if (i == 0) { TextColor(236); }
				else { TextColor(252); }
				gotoXY(28, 5 + (i + 1) * 4);	cout << "                                ";
				gotoXY(28, 6 + (i + 1) * 4);	cout << MENUloptc[i];
				gotoXY(28, 7 + (i + 1) * 4);	cout << "                                ";
			}
			chonMenuCon = MenuCon(4, MENUloptc);
			TextColor(14);
			system("cls");
			switch (chonMenuCon)
			{
				case 1: {	nhapDSLTC(DSLTC, DSMH, MALTC, n);		  break;		}
				case 2: {	XemDSLTC(DSLTC, DSMH,MALTC,n, 0); break;		}
				case 3: {nhap_xem_DIEM(DSLTC, listSV, DSMH, 1); break;  }
			    case 4: {nhap_xem_DIEM(DSLTC, listSV,DSMH, 0); break; }
			}break;
		}
		case 2:
		{
			xemMonHoc(DSLTC, DSMH, 0);
			break;	
		}
		case 3:
		{
			for (int i = 0; i < 2; i++)
			{
				if (i == 0) { TextColor(236); }
				else { TextColor(252); }
				gotoXY(28, 5 + (i + 1) * 4);	cout << "                                ";
				gotoXY(28, 6 + (i + 1) * 4);	cout << MENUsv[i];
				gotoXY(28, 7 + (i + 1) * 4);	cout << "                                ";
			}
			chonMenuCon = MenuCon(2, MENUsv);
			TextColor(14);
			system("cls");
			switch (chonMenuCon)
			{
				case 1: {	NhapSinhVien(DSLTC, listSV, DSMH); break;			}
				case 2: {	XemSinhVien(listSV, DSMH, DSLTC); break;			}
			}break;
		}
		case 4:
		{
			for (int i = 0; i < 3; i++)
			{
				if (i == 0) { TextColor(236); }
				else { TextColor(252); }
				gotoXY(28, 5 + (i + 1) * 4);	cout << "                                ";
				gotoXY(28, 6 + (i + 1) * 4);	cout << MENUdangki[i];
				gotoXY(28, 7 + (i + 1) * 4);	cout << "                                ";
			}
			chonMenuCon = MenuCon(3, MENUdangki);
			TextColor(14);
			system("cls");
			switch (chonMenuCon)
			{
				case 1: { bool check_change = false; DANGKI_LTC(DSLTC, listSV, DSMH, check_change); break; }
				case 2: {XemDSDK(DSLTC, listSV, DSMH); break; }
				case 3: {HuyDSDK(DSLTC, listSV, DSMH); break; }
				
			}break;
		}
		case 5: {
			xemDiemTB(DSLTC, listSV, DSMH); 
			break;
		}
		case 6:
		{
			putchar(7);
			int temp = ThongBao_Thoat();
			if (temp == 1) {
				GiaiPhong(DSLTC,DSMH, listSV, MALTC);
				TextColor(14);
				system("cls");
				exit(0);
			}
			TextColor(14);	break;
		}
		}
	}
}
int main() {
	system("color 0F");
	PTRLTC DSLTC;
	DS_MonHoc DSMH;
	PTR_SV DS_SINHVIEN =NULL;
	InitMH(DSMH);
	Init_LTC(DSLTC);
	DocFileDSLTC(DSLTC);
	DocFileDSDK(DSLTC);
	DocFileDSMH(DSMH);
	DocFileSV(DS_SINHVIEN);
	int n = MAXLOPTC - DemLTC(DSLTC);
	int* MALTC = new int[n];
	DocFileMLTC(MALTC, n);
	MenuKT(DSLTC,DS_SINHVIEN,DSMH,MALTC,n);
	system("pause");
	return 0;
}
