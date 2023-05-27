// bai_1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Bài 1.1: Tạo một cây nhị phân tìm kiếm, trong đó trường Key tại mỗi nút là một số nguyên dương. Hãy viết hàm thực hiện các thao tác sau:
//a.Người dùng nhập vào các giá trị đến khi nhập - 1 thì dừng(giá trị - 1 không thuộc cây)
//b.In cây nhị phân tìm kiếm nói trên theo các thứ tự tăng dần, giảm dần.
//c.Tìm một nút có khoá bằng X trên cây.
//d.Xoá 1 nút có khoá bằng X trên cây, nếu không có thì thông báo không có.
//e.Đếm số nút trong cây
//f.Tính chiều cao của cây
//g.	(*) Xuất cây nhị phân theo tầng.

#include <iostream>
#include <queue>
using namespace std;

struct node {
	int data;
	node* pLeft;
	node* pRight;
};

typedef node* TREE;

void KhoiTaoTree(TREE& t)
{
	t = NULL;
}

void Them_1_PhanTuVaoCayNhiPhan(TREE& t, int x)
{
	if (t == NULL)
	{
		TREE tmp = new node();
		tmp->data = x;
		tmp->pLeft = NULL;
		tmp->pRight = NULL;
		t = tmp;
	}
	else
	{
		if (x > t->data) Them_1_PhanTuVaoCayNhiPhan(t->pRight, x);
		else if (x < t->data) Them_1_PhanTuVaoCayNhiPhan(t->pLeft, x);
	}
}

void DuyetCay_LNR(TREE& t) //tang dan
{
	if (t != NULL)
	{
		DuyetCay_LNR(t->pLeft);
		cout << t->data << " ";
		DuyetCay_LNR(t->pRight);
	}
}

void DuyetCay_RNL(TREE& t)// giam dan
{
	if (t != NULL)
	{
		DuyetCay_RNL(t->pRight);
		cout << t->data << " ";
		DuyetCay_RNL(t->pLeft);
	}
}

int TimKiem(TREE t, int x)
{
	if (t == NULL) return 0;
	else
	{
		if (x > t->data) TimKiem(t->pRight, x);
		else if (x < t->data) TimKiem(t->pLeft, x);
		else return 1;
	}
}

void ThayThe(TREE& a, TREE& b)  // node*b = t->pRight
{
	if (b->pLeft != NULL) ThayThe(a, b->pLeft);
	else
	{
		a->data = b->data;
		a = b;
		b = b->pRight;
	}
}
void Xoa(TREE& t, int x)
{
	if (t == NULL) return;
	else
	{
		if (x > t->data) Xoa(t->pRight, x);
		else if (x < t->data) Xoa(t->pLeft, x);
		else
		{
			node* tmp = t;
			if (t->pLeft == NULL) t = t->pRight;
			else if (t->pRight == NULL) t = t->pLeft;
			else
			{
				ThayThe(tmp, t->pRight);
			}
			delete tmp;
		}
	}
}


int DemNut(TREE t, int&cnt)
{
	
	if (t != NULL)
	{
		cnt++;
		DemNut(t->pLeft, cnt);
		DemNut(t->pRight, cnt);
	}
	return cnt;
}

int tinhChieuCao(TREE t)
{
	if (t==NULL) return -1;
	int a = tinhChieuCao(t->pLeft);
	int b = tinhChieuCao(t->pRight);
	return (a > b ? a : b) +1 ;
}


void XuatCayTheoTang(TREE t) // duyet cay theo chieu rong
{
	if (t == NULL) return;
	queue<node*> bf_queue;     
	bf_queue.push(t); // t: root
	while (!bf_queue.empty())
	{
		node* curr = bf_queue.front();
		bf_queue.pop();
		cout << curr->data << " ";
		
		if (curr->pLeft != NULL)
		{
			bf_queue.push(curr->pLeft);
		}
		if (curr->pRight != NULL)
		{
			bf_queue.push(curr->pRight);
		}
	}
	
		
}
void Menu(TREE& t)
{
	while (1)
	{
		cout << "\n\t\t***MENU***\n";
		cout << "\n1.Nhap gia tri.";
		cout << "\n2.In theo thu tu tang dan.";
		cout << "\n3.In theo thu tu giam dan.";
		cout << "\n4.Tim 1 nut.";
		cout << "\n5.Xoa 1 nut.";
		cout << "\n6.Dem so nut";
		cout << "\n7.Tinh chieu cao cua cay.";
		cout << "\n8.Xuat cay theo tang.";
		cout << "\n0.Thoat.";

		int lc; cout << "\n\n\tNhap lua chon: "; cin >> lc;

		if (lc == 1)
		{
			int x;
			do
			{
				cout << "\nNhap gia tri so nguyen duong: ";  cin >> x;
				if (x <= 0)
				{
					cout << "\n\tNhap lai !!!\n";
					continue;
				}
				else
				{
					Them_1_PhanTuVaoCayNhiPhan(t, x);
				}
			} while (x != -1);
		}

		else if (lc == 2)
		{
			cout << "\nCay nhi phan tim kiem theo thu tu tang dan: ";
			DuyetCay_LNR(t);
			cout << endl;
		}
		else if (lc == 3)
		{
			cout << "\nCay nhi phan tim kiem theo thu tu tang dan: ";
			DuyetCay_RNL(t);
			cout << endl;
		}
		else if (lc == 4)
		{
			cout << "\nNhap nut can tim kiem: "; int x; cin >> x;
			if (TimKiem(t, x) == 1) cout << "\nNut co gia tri " << x << " ton tai trong cay nhi phan tim kiem.";
			else cout << "\nNut co gia tri " << x << "  KHONG ton tai trong cay nhi phan tim kiem.\n";
		}
		else if (lc == 5)
		{
			cout << "\nNhap gia tri can xoa: "; int y; cin >> y;
			Xoa(t, y);
			cout << endl;
		}
		else if (lc == 6)
		{
			int cnt = 0;
			cout << "\nSo nut trong cay la: " << DemNut(t, cnt);
			cout << endl;
		}
		else if (lc == 7)
		{
			cout << "\nChieu cao cua cay la: " << tinhChieuCao(t);
			cout << endl;
		}
		else if (lc == 8)
		{
			cout << "\nGia tri cua cac tang tu tren xuong la: ";
			XuatCayTheoTang(t);
			cout << endl;// duyet cay theo chieu rong
		}
		else break;
	}
}

int main()
{
	TREE t;
	KhoiTaoTree(t);
	Menu(t);
	return 0;
}
