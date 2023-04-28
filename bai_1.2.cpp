
#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
	string ten;
	string MASV;
	double DTB;
};

struct Student {
	SinhVien a;
	Student* next;
};


struct list
{
	Student* pHead;
	Student* pTail;
};

void KhoiTao(list& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

Student* makeSinhVien(SinhVien x)
{
	Student* tmp = new Student();
	tmp->a = x;
	tmp->next = NULL;
	return tmp;
}

void InsertLast(list& l, Student* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->next = p;
		l.pTail = p;
	}
}

void InsertFirst(list& l, Student* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->next = l.pHead;
		l.pHead = p;
	}
}



void In(SinhVien x)
{
	cout << "Ho va ten: " << x.ten << endl;
	cout << "Ma so sinh vien: " << x.MASV << endl;
	cout << "Diem trung binh: " << x.DTB << endl;
}

void InDSSV(list l)
{
	for (Student* k = l.pHead; k != NULL; k = k->next)
	{
		In(k->a);
	}
}


bool TimKiemSV(list l, string id)
{
	for (Student* k = l.pHead; k != NULL; k = k->next)
	{
		if (k->a.MASV == id) return 1;
	}
	return 0;
}

void DeleteFirst(list& l)
{
	if (l.pHead == NULL) return;
	else
	{
		Student* p = l.pHead;
		l.pHead = l.pHead->next;
		delete p;
	}
}

void DeleteLast(list& l)
{
	if (l.pHead == NULL) return;
	for (Student* k = l.pHead; k != NULL; k = k->next)
	{
		if (k->next == l.pTail)
		{
			delete l.pTail;
			k->next = NULL;
			l.pTail = k;
		}
	}
}


void DeleteMid(list& l, string id)
{
	Student* truoc = NULL;
	Student* sau = l.pHead;
	Student* k;
	for (k = l.pHead; k->a.MASV != id; k = k->next)
	{
		truoc = sau;
		sau = sau->next;
	}

	truoc->next = sau->next;
	delete sau;

}
void Delete(list& l, string id)
{
	if (id == l.pHead->a.MASV) DeleteFirst(l);
	else if (id == l.pTail->a.MASV) DeleteLast(l);
	else DeleteMid(l, id);

}

void ListSV(list l)
{
	for (Student* k = l.pHead; k != NULL; k = k->next)
	{
		if (k->a.DTB >= 5) In(k->a);
	}
}

void XepLoai(list l)
{
	for (Student* k = l.pHead; k != NULL; k = k->next)
	{
		if (k->a.DTB <= 3.6)
		{
			In(k->a);
			cout << "Xep loai: YEU." << endl;
		}
		else if (k->a.DTB >= 5 && k->a.DTB < 6.5)
		{
			In(k->a);
			cout << "Xep loai: TRUNG BINH." << endl;
		}
		else if (k->a.DTB >= 6.5 && k->a.DTB < 7)
		{
			In(k->a);
			cout << "Xep loai: TRUNG BINH KHA." << endl;
		}
		else if (k->a.DTB >= 7 && k->a.DTB < 8)
		{
			In(k->a);
			cout << "Xep loai: KHA." << endl;
		}
		else if (k->a.DTB >= 8 && k->a.DTB < 9)
		{
			In(k->a);
			cout << "Xep loai: GIOI." << endl;
		}
		else
		{
			In(k->a);
			cout << "Xep loai: XUAT SAC." << endl;
		}
	}
}


void Sort(list l)
{
	for (Student* i = l.pHead; i != NULL; i = i->next)
	{
		for (Student* j = i; j != NULL; j = j->next)
		{
			if (i->a.DTB > j->a.DTB) swap(i->a, j->a);
		}
	}
}

int main()
{
	list l;
	KhoiTao(l);


	while (1)
	{
		cout << "\n--------MENU--------" << endl;
		cout << "1. Nhap danh sach cac sinh vien." << endl;
		cout << "2. Chen sinh vien vao dau danh sach." << endl;
		cout << "3. Tim kiem sinh vien co trong lop hay khong bang MSSV." << endl;
		cout << "4. Xoa sinh vien co MSSV la x." << endl;
		cout << "5. Liet ke thong tin cua sinh vien co DTB lon hon hoac bang 5." << endl;
		cout << "6. Xep loai cua tung sinh vien." << endl;
		cout << "7. Sap xep sinh vien tang theo DTB." << endl;
		cout << "8. Chen 1 sinh vien vao danh sach sinh vien tang theo DTB" << endl;
		cout << "9. In ra danh sach sinh vien hien tai." << endl;
		cout << "0. Thoat khoi chuong trinh." << endl;
		cout << "Nhap lua chon." << endl;
		int lc; cin >> lc;

		if (lc == 1) {
			int i = 0;
			while (1)
			{
				SinhVien x;
				cin.ignore();
				cout << "Nhap ho va ten: "; getline(cin, x.ten);
				if (x.ten == "") break;
				cout << "Nhap MSSV: "; cin >> x.MASV;
				cout << "Nhap diem trung binh: "; cin >> x.DTB;
				//cin.ignore();
				Student* p = makeSinhVien(x);
				InsertLast(l, p);
				i++;
			}
		}


		else if (lc == 2)
		{
			int i = 0;
			while (1)
			{
				SinhVien x;
				cin.ignore();
				cout << "Nhap ho va ten: "; getline(cin, x.ten);
				if (x.ten == "") break;
				cout << "Nhap MSSV: "; cin >> x.MASV;
				cout << "Nhap diem trung binh: "; cin >> x.DTB;
				//cin.ignore();
				Student* p = makeSinhVien(x);
				InsertFirst(l, p);
				i++;
			}
		}




		else if (lc == 3) {
			cout << "Nhap MASSV cua sinh vien can tim: "; string id; cin >> id;
			if (TimKiemSV(l, id) == 1) cout << "Sinh vien co trong danh sach.";
			else cout << "Sinh vien nay khong co trong danh sach :(" << endl;
		}


		else if (lc == 4)
		{
			cout << "Nhap MSSV cua sinh vien can xoa khoi danh sach: ";
			string ms; cin >> ms;
			Delete(l, ms);
		}

		else if (lc == 5)
		{
			cout << "----DANH SACH SINH VIEN CO DTB>=5---- " << endl;
			ListSV(l);
		}

		else if (lc == 6)
		{
			cout << "----XEP LOAI SINH VIEN---- " << endl;
			XepLoai(l);
		}

		else if (lc == 7)
		{
			cout << "----SAP XEP SINH VIEN TANG DAN THEO DTB---- " << endl;
			Sort(l);
			InDSSV(l);
		}

		else if (lc == 8)
		{
			SinhVien y;
			cin.ignore();
			cout << "Nhap ho va ten: "; getline(cin, y.ten);
			if (y.ten == "") break;
			cout << "Nhap MSSV: "; cin >> y.MASV;
			cout << "Nhap diem trung binh: "; cin >> y.DTB;
			//cin.ignore();
			Student* q = makeSinhVien(y);
			InsertLast(l, q);
			Sort(l);
			cout << "----DANH SACH SINH VIEN SAU KHI CHEN.----" << endl;
			InDSSV(l);

		}
		else if (lc == 9)
		{
			cout << "\n----DANH SACH SINH VIEN HIEN TAI----" << endl;
			InDSSV(l);

		}

		else if (lc == 0) break;

	}
}
